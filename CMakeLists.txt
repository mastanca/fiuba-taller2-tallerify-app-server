cmake_minimum_required(VERSION 3.6)
set(PROJECT_NAME fiuba_taller2_tallerify_app_server)
project(${PROJECT_NAME} C CXX)
set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

if (CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif ()

#-------------------
# set common include folder for module
#-------------------
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

#-------------------
# Test
#-------------------
option(COVERALLS "Turn on coveralls support" OFF)
option(COVERALLS_UPLOAD "Upload the generated coveralls json" ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
        ${PROJECT_SOURCE_DIR}/cmake)

if (COVERALLS)
    include(Coveralls)
    coveralls_turn_on_coverage()
endif()

file(GLOB_RECURSE COVERAGE_SRCS ${PROJECT_SOURCE_DIR}/src/api/*.cpp)

if (COVERALLS)
    coveralls_setup(
            "${COVERAGE_SRCS}"
            ${COVERALLS_UPLOAD}
            "${PROJECT_SOURCE_DIR}/cmake")
endif()

enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
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

find_package(libbsoncxx)
find_package(libmongocxx)

link_directories(
        ${LIBMONGOCXX_LIBRARY_DIRS}
        ${LIBBSONCXX_LIBRARY_DIRS}
)

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/api/*.cpp ${PROJECT_SOURCE_DIR}/src/mongoose/*.c)

set(SPDLOG_DIR "${PROJECT_SOURCE_DIR}/include")
include_directories(${SPDLOG_DIR})
link_directories(${SPDLOG_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
        PRIVATE ${LIBMONGOCXX_INCLUDE_DIRS}
        PRIVATE ${LIBBSONCXX_INCLUDE_DIRS}
        )

target_link_libraries(${PROJECT_NAME}
        PRIVATE ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES} Threads::Threads
        )
