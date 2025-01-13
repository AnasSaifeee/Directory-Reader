#ifndef DIRECTORYREADER_H
#define DIRECTORYREADER_H

#include <filesystem>

namespace fs = std::filesystem;

extern "C"{
void read_directory(const char* path);

}

#endif // DIRECTORYREADER_H
