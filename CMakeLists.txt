cmake_minimum_required(VERSION 3.10)
project(MultithreadedFileProcessor)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)

add_executable(file_processor 
    src/main.cpp 
    src/file_processor.cpp 
    src/database.cpp)

target_include_directories(file_processor PRIVATE src)

target_link_libraries(file_processor SQLite::SQLite3)
