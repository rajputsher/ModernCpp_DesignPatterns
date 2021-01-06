cmake_minimum_required(VERSION 3.16)
project(DesginPatterns)

set(CMAKE_CXX_STANDARD 17)

#################
#####Boost#####
#################
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.71.0 COMPONENTS filesystem regex) 

if(Boost_FOUND)
    add_executable(mainApp main.cpp) 
    target_link_libraries(mainApp Boost::filesystem Boost::regex)
endif()