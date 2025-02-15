#include "file_processor.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <thread>
#include <vector>
#include <mutex>

std::mutex db_mutex;

void process_line(const std::string &line, sqlite3 *db)
{
    std::regex log_pattern(R"(\[(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})\] (ERROR|INFO|DEBUG): (.*))");
    std::smatch match;

    if (std::regex_search(line, match, log_pattern))
    {
        std::string timestamp = match[1];
        std::string log_level = match[2];
        std::string message = match[3];

        std::lock_guard<std::mutex> lock(db_mutex);
        std::string sql = "INSERT INTO logs (timestamp, log_level, message) VALUES ('" + timestamp + "', '" + log_level + "', '" + message + "');";
        char *err_msg = nullptr;
        sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg);
        if (err_msg)
        {
            std::cerr << "SQL Error: " << err_msg << std::endl;
            sqlite3_free(err_msg);
        }
    }
}

void process_file(const std::string &filename, sqlite3 *db)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::vector<std::thread> workers;
    std::string line;
    while (std::getline(file, line))
    {
        workers.emplace_back(process_line, line, db);
    }

    for (auto &worker : workers)
    {
        worker.join();
    }
}