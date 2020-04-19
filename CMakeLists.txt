# cmake_minimum_required(VERSION <specify CMake version here>)

cmake_minimum_required(VERSION 3.00)

project(LeetCode-CPP11)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE APP_SRCS "src/*.cpp" "src/*.hpp" "src/*.h" "unitTest/*.hpp" "unitTest/*.cpp" "unitTest/*.h")

add_executable(LeetCode ${APP_SRCS})

target_link_libraries(LeetCode pthread)