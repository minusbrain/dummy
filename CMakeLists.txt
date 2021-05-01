cmake_minimum_required(VERSION 3.11)
project(test_popen LANGUAGES CXX C)

SET(CMAKE_CXX_FLAGS "-g -rdynamic -Wall -Werror -Wextra -Wpedantic")

SET (DUMMY_SRC
        dummy.cpp
    )

add_executable(dummy ${DUMMY_SRC})
set_property(TARGET dummy PROPERTY CXX_STANDARD 11)

install(TARGETS dummy DESTINATION bin)
