# Multithreaded File Processor

This C++ project is a multithreaded system for efficiently processing large log files. It extracts structured log data using regex and stores the results in an SQLite database.

## 📁 Project Structure

```
MultithreadedFileProcessor/
│── CMakeLists.txt         # CMake build configuration
│── README.md              # Project documentation
│── src/
│   │── main.cpp           # Main program logic
│   │── file_processor.cpp # File processing implementation
│   │── file_processor.h   # File processing header
│   │── database.cpp       # SQLite interaction
│   │── database.h         # Database header
│── logs/
│   │── sample.log         # Sample log file for testing
│── build/                 # Build directory (generated)
│── data/
│   │── logs.db            # SQLite database file (generated)
```

## Features

- **Multithreading:** Processes multiple log lines in parallel for improved performance.
- **Regex Extraction:** Extracts timestamp, log level, and message from logs.
- **SQLite Integration:** Stores extracted log data in a structured database.
- **File I/O Optimization:** Reads large log files efficiently.

## Requirements

- C++17 or later
- SQLite3 library
- CMake (for building the project)

## Installation and Usage

1. Clone the repository:
   ```sh
   git clone <repository-url>
   cd MultithreadedFileProcessor
   ```
2. Install the Requirements:
    - Linux (Ubuntu/Debian)
   ```sh
   sudo apt install cmake sqlite3 libsqlite3-dev
   ```
3. Build the project:
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
4. Run the application:
   ```sh
   ./file_processor <log_file> <db_file>
   ```
    - log_file: ../logs/sample.log
    - db_file: ../data/logs.db

## Validate Log Insertion

- Linux (Ubuntu/Debian)
- Validate the records in logs table of the `db` file using SQLite CLI

   ```sh
   ~/MultithreadedFileProcessor/build $ ./file_processor ../logs/sample.log ../data/logs.db
   Log file processed successfully.


   ~/MultithreadedFileProcessor/build $ sqlite3 ../data/logs.db 
   SQLite version 3.37.2 2022-01-06 13:25:41
   Enter ".help" for usage hints.

   sqlite> .tables
   logs

   sqlite> .schema logs
   CREATE TABLE logs (id INTEGER PRIMARY KEY AUTOINCREMENT, timestamp TEXT, log_level TEXT, message TEXT);

   sqlite> SELECT * FROM logs;
   1|2024-02-09 12:33:05|INFO|Request received for endpoint /api/data.
   2|2024-02-09 12:31:22|DEBUG|User logged in with ID 12345.
   3|2024-02-09 12:32:10|ERROR|Failed to connect to database.
   4|2024-02-09 12:30:15|INFO|Application started successfully.
   5|2024-02-09 12:34:45|DEBUG|Processing request parameters.
   6|2024-02-09 12:36:50|INFO|User logged out successfully.
   7|2024-02-09 12:35:30|ERROR|Timeout while connecting to external service.


   sqlite> .exit
   ```

## License

This project is open-source and available under the MIT License.

