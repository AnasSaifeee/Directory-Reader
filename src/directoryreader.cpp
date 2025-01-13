#include "directoryreader.h"
#include <iostream>
#include "dbhelpers.h"

extern "C" {
    void read_directory(const char* path) {
        try {
            fs::path dirPath(path);
            for (const auto& entry : fs::directory_iterator(dirPath)) {
                if (fs::is_directory(entry)) {
                    std::cout << "Directory: " << entry.path() << std::endl;
                    insert_path(nullptr, entry.path().string().c_str());
                    read_directory(entry.path().string().c_str());
                } else if (fs::is_regular_file(entry)) {
                    std::cout << "File is: " << entry.path() << std::endl;
                    insert_path(nullptr, entry.path().string().c_str());
                }
            }
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Error reading directory: " << e.what() << std::endl;
        }
    }
}
