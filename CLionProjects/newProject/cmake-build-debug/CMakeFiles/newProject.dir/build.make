# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = "/Users/Mac/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4129.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/Mac/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/182.4129.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Mac/CLionProjects/newProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Mac/CLionProjects/newProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/newProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/newProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/newProject.dir/flags.make

CMakeFiles/newProject.dir/main.cpp.o: CMakeFiles/newProject.dir/flags.make
CMakeFiles/newProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Mac/CLionProjects/newProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/newProject.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/newProject.dir/main.cpp.o -c /Users/Mac/CLionProjects/newProject/main.cpp

CMakeFiles/newProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/newProject.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Mac/CLionProjects/newProject/main.cpp > CMakeFiles/newProject.dir/main.cpp.i

CMakeFiles/newProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/newProject.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Mac/CLionProjects/newProject/main.cpp -o CMakeFiles/newProject.dir/main.cpp.s

# Object files for target newProject
newProject_OBJECTS = \
"CMakeFiles/newProject.dir/main.cpp.o"

# External object files for target newProject
newProject_EXTERNAL_OBJECTS =

newProject: CMakeFiles/newProject.dir/main.cpp.o
newProject: CMakeFiles/newProject.dir/build.make
newProject: CMakeFiles/newProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Mac/CLionProjects/newProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable newProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/newProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/newProject.dir/build: newProject

.PHONY : CMakeFiles/newProject.dir/build

CMakeFiles/newProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/newProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/newProject.dir/clean

CMakeFiles/newProject.dir/depend:
	cd /Users/Mac/CLionProjects/newProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Mac/CLionProjects/newProject /Users/Mac/CLionProjects/newProject /Users/Mac/CLionProjects/newProject/cmake-build-debug /Users/Mac/CLionProjects/newProject/cmake-build-debug /Users/Mac/CLionProjects/newProject/cmake-build-debug/CMakeFiles/newProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/newProject.dir/depend

