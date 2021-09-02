cmake_minimum_required(VERSION 3.5)

# should only be under cmake_minimum_required
# should be set as g++-7, otherwise will report error
set (CMAKE_CXX_COMPILER "/usr/bin/g++-5")

project(Compiler LANGUAGES CXX)



set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(dependencies/antlr4-runtime/src)
include_directories(grammar)
include_directories(src)

link_directories("dependencies/antlr4-runtime/lib")
link_libraries(antlr4-runtime)

FILE(GLOB SOURCE_FILES "src/*.cpp" "grammar/*.cpp")

add_definitions(-w -g)

add_executable(compiler ${SOURCE_FILES})
