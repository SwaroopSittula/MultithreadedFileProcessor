#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>
#include <sqlite3.h>

void process_file(const std::string &filename, sqlite3 *db);

#endif