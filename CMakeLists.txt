cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME_STR fiuba_taller2_tallerify_app_server)
project(${PROJECT_NAME_STR} C CXX)
set(CMAKE_CXX_STANDARD 11)

# Options. Turn on with 'cmake -Dmyvarname=ON'.
option(test "Build all tests." OFF) # Makes boolean 'test' available.

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

#-------------------
# set common include folder for module
#-------------------
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

#-------------------
# Test
#-------------------
if (test)
    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

    include(cmake/CodeCoverage.cmake)
    enable_testing()
    set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
    include_directories(${GTEST_INCLUDE_DIRS})

    file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
    add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
    add_dependencies(${PROJECT_TEST_NAME} googletest)


    target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )

    target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

    add_test(test1 ${PROJECT_TEST_NAME})
    setup_target_for_coverage(${PROJECT_NAME_STR}_coverage ${PROJECT_TEST_NAME} coverage)
else()
    set(SOURCE_FILES
            README.md src/api/main.cpp)

    add_executable(fiuba_taller2_tallerify_app_server ${SOURCE_FILES})
endif()
