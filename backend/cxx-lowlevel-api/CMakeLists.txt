cmake_minimum_required(VERSION 3.10)

set(CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(C_STANDARD 23)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

project(cxx-lowlevel-api)

find_package(Drogon REQUIRED)
find_package(Jsoncpp REQUIRED)

if (Drogon_FOUND)
  message(STATUS "Drogon found")
else()
  message(FATAL_ERROR "Drogon not found")
endif()

if (Jsoncpp_FOUND)
  message(STATUS "Jsoncpp found")
else()
  message(FATAL_ERROR "Jsoncpp not found")
endif()

include_directories(
  ${Drogon_INCLUDE_DIRS}
  ${Jsoncpp_INCLUDE_DIRS}
)

add_executable(cxx-lowlevel-api
main.cpp
)

target_link_directories(cxx-lowlevel-api
PRIVATE
  ${Drogon_LIBRARY_DIRS}
  ${Jsoncpp_LIBRARY_DIRS}
)

target_link_libraries(cxx-lowlevel-api
PRIVATE
  # ${Drogon_LIBRARIES}
  ${Jsoncpp_LIBRARIES}
  Drogon::Drogon
)
