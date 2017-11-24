cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

include(cmake/HunterGate.cmake)

HunterGate(
    URL "https://github.com/Kustov-Ilya/hunter/archive/v0.19.137.1.tar.gz"
    SHA1 "affff3092b27bdc5cbb96fca80c37c2673475886"
)

project(cget)

hunter_add_package(CURL)
find_package(CURL CONFIG REQUIRED)

add_executable(cget ${CMAKE_CURRENT_SOURCE_DIR}/cget.cpp)
target_link_libraries(cget CURL::libcurl)
