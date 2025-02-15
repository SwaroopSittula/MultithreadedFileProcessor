#include "file_processor.h"
#include "database.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc < 3) {
        std::cerr << "Usage: ./file_processor <log_file> <db_file>" << std::endl;
        return 1;
    }

    Database db(argv[2]);
    process_file(argv[1], db.get_db());

    std::cout << "Log file processed successfully." << std::endl;
    return 0;
}
