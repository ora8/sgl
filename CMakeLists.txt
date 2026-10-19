cmake_minimum_required(VERSION 3.26s)
project(MessageQueueProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Option für Debug/Release Builds
option(BUILD_DEBUG "Build in debug mode" ON)

# Include-Verzeichnis für Header-Dateien
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Executable erstellen
add_executable(sgltest
    src/main.cpp
)

# Ziel-Dateien in einem separaten Verzeichnis speichern
set_target_properties(sgltest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Compiler-Flags für Debug/Release
if (BUILD_DEBUG)
    target_compile_options(sgltest PRIVATE -g -Wall -Wextra)
else()
    target_compile_options(sgltest PRIVATE -O2 -DNDEBUG)
endif()

# Installationsziel definieren (optional)
install(TARGETS sgltest
    RUNTIME DESTINATION bin
)
