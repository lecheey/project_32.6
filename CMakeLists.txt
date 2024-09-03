cmake_minimum_required(VERSION 3.14) # version can be different
set(CMAKE_CXX_STANDARD 14)

project(DBaccessAPI LANGUAGES CXX) #name of your project

#include()

enable_testing() #to  discover tests in test explorer 

add_subdirectory(googletest) # add googletest subdirectory

include_directories("include" "googletest/include" "googlemock/include") # this is so we can #include <gtest/gtest.h>

add_executable(${PROJECT_NAME} main.cpp ${HEADER}) # add this executable

#target_link_libraries(mytests PRIVATE gtest) # link google test to this executable
target_link_libraries(${PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest.a
	${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest_main.a
	${CMAKE_SOURCE_DIR}/googletest/build/lib/libgmock.a
	${CMAKE_SOURCE_DIR}/googletest/build/lib/libgmock_main.a)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(HEADER dbc.h dbc_mock.h dbc_if.h ctu_db.h)

include(CTest)
#gtest_discover_tests(mytests) # discovers tests by asking the compiled test executable to enumerate its tests
