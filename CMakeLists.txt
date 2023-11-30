cmake_minimum_required(VERSION 2.6)

project(sysmonitor)

include_directories(${CURSES_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.cpp")

include_directories(include)

find_package(Curses REQUIRED)

add_executable(sysmonitor ${SOURCES})

set_property(TARGET sysmonitor PROPERTY CXX_STANDARD 17)

target_link_libraries(sysmonitor ${CURSES_LIBRARIES})

target_compile_options(sysmonitor PRIVATE -Wall -Wextra)