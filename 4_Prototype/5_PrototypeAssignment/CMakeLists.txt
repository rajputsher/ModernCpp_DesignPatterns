cmake_minimum_required(VERSION 3.16)
project(BuilderTest)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
message("GTEST_INCLUDE_DIRS = ${GTEST_INCLUDE_DIRS}") #This line is to test that GTest is rightly setup


#################
#####Unit Test#####
#################
add_executable(testRunner main.cpp Prototype.cpp)
target_link_libraries(testRunner ${GTEST_LIBRARIES} pthread)