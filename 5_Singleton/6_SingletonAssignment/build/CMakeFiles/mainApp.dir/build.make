# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build

# Include any dependencies generated for this target.
include CMakeFiles/mainApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainApp.dir/flags.make

CMakeFiles/mainApp.dir/main.cpp.o: CMakeFiles/mainApp.dir/flags.make
CMakeFiles/mainApp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainApp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainApp.dir/main.cpp.o -c /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/main.cpp

CMakeFiles/mainApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainApp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/main.cpp > CMakeFiles/mainApp.dir/main.cpp.i

CMakeFiles/mainApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainApp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/main.cpp -o CMakeFiles/mainApp.dir/main.cpp.s

CMakeFiles/mainApp.dir/Singleton.cpp.o: CMakeFiles/mainApp.dir/flags.make
CMakeFiles/mainApp.dir/Singleton.cpp.o: ../Singleton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mainApp.dir/Singleton.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainApp.dir/Singleton.cpp.o -c /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/Singleton.cpp

CMakeFiles/mainApp.dir/Singleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainApp.dir/Singleton.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/Singleton.cpp > CMakeFiles/mainApp.dir/Singleton.cpp.i

CMakeFiles/mainApp.dir/Singleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainApp.dir/Singleton.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/Singleton.cpp -o CMakeFiles/mainApp.dir/Singleton.cpp.s

# Object files for target mainApp
mainApp_OBJECTS = \
"CMakeFiles/mainApp.dir/main.cpp.o" \
"CMakeFiles/mainApp.dir/Singleton.cpp.o"

# External object files for target mainApp
mainApp_EXTERNAL_OBJECTS =

mainApp: CMakeFiles/mainApp.dir/main.cpp.o
mainApp: CMakeFiles/mainApp.dir/Singleton.cpp.o
mainApp: CMakeFiles/mainApp.dir/build.make
mainApp: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
mainApp: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
mainApp: /usr/lib/x86_64-linux-gnu/libgtest.a
mainApp: CMakeFiles/mainApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable mainApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainApp.dir/build: mainApp

.PHONY : CMakeFiles/mainApp.dir/build

CMakeFiles/mainApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainApp.dir/clean

CMakeFiles/mainApp.dir/depend:
	cd /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build /home/shivsayali/Shivaram/onlineCourses/ModernCpp_DesignPatterns/5_Singleton/6_SingletonAssignment/build/CMakeFiles/mainApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainApp.dir/depend

