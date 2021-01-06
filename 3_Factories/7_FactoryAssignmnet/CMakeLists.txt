cmake_minimum_required(VERSION 3.16)
project(BuilderTest)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}") #This line is to test that GTest is rightly setup


#################
#####Executable#####
#################
add_executable(mainApp main.cpp PersonFactory.cpp)

#################
#####Unit Test#####
#################
add_executable(testRunner testRunner.cpp PersonFactory.cpp)
target_link_libraries(testRunner ${GTEST_LIBRARIES} pthread)