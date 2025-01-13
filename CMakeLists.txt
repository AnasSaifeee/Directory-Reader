cmake_minimum_required(VERSION 3.10)

project(MyProject)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/linux_toolchain.cmake" CACHE STRING "Toolchain file")

set(SOURCES
    src/directoryreader.cpp
    src/dbhelpers.cpp
)

# Define the shared library
add_library(my_shared_lib SHARED ${SOURCES})

# Specify the location of header files
target_include_directories(my_shared_lib PRIVATE src)

# Find and link SQLite3 (if you're using SQLite in your project)
find_package(SQLite3 REQUIRED)
target_link_libraries(my_shared_lib PRIVATE SQLite::SQLite3)

# Install shared library
install(TARGETS my_shared_lib DESTINATION lib)

# Optionally, set additional properties for the shared library
set_target_properties(my_shared_lib PROPERTIES
    VERSION 1.0
    SOVERSION 1
)
