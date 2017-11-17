cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/SimonRussia/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "ef53eaa092c18d1ae26299daa4ea84d0f1d979ef"
)

project(curl)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

add_executable(curl ${CMAKE_CURRENT_SOURCE_DIR}/curl.cpp)
target_link_libraries(curl CURL::libcurl)
