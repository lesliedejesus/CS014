# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lesliedejesus/CLionProjects/CS14Lab10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CS14Lab10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CS14Lab10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CS14Lab10.dir/flags.make

CMakeFiles/CS14Lab10.dir/main.cpp.o: CMakeFiles/CS14Lab10.dir/flags.make
CMakeFiles/CS14Lab10.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CS14Lab10.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CS14Lab10.dir/main.cpp.o -c /Users/lesliedejesus/CLionProjects/CS14Lab10/main.cpp

CMakeFiles/CS14Lab10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS14Lab10.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lesliedejesus/CLionProjects/CS14Lab10/main.cpp > CMakeFiles/CS14Lab10.dir/main.cpp.i

CMakeFiles/CS14Lab10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS14Lab10.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lesliedejesus/CLionProjects/CS14Lab10/main.cpp -o CMakeFiles/CS14Lab10.dir/main.cpp.s

CMakeFiles/CS14Lab10.dir/Graph.cpp.o: CMakeFiles/CS14Lab10.dir/flags.make
CMakeFiles/CS14Lab10.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CS14Lab10.dir/Graph.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CS14Lab10.dir/Graph.cpp.o -c /Users/lesliedejesus/CLionProjects/CS14Lab10/Graph.cpp

CMakeFiles/CS14Lab10.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CS14Lab10.dir/Graph.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lesliedejesus/CLionProjects/CS14Lab10/Graph.cpp > CMakeFiles/CS14Lab10.dir/Graph.cpp.i

CMakeFiles/CS14Lab10.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CS14Lab10.dir/Graph.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lesliedejesus/CLionProjects/CS14Lab10/Graph.cpp -o CMakeFiles/CS14Lab10.dir/Graph.cpp.s

# Object files for target CS14Lab10
CS14Lab10_OBJECTS = \
"CMakeFiles/CS14Lab10.dir/main.cpp.o" \
"CMakeFiles/CS14Lab10.dir/Graph.cpp.o"

# External object files for target CS14Lab10
CS14Lab10_EXTERNAL_OBJECTS =

CS14Lab10: CMakeFiles/CS14Lab10.dir/main.cpp.o
CS14Lab10: CMakeFiles/CS14Lab10.dir/Graph.cpp.o
CS14Lab10: CMakeFiles/CS14Lab10.dir/build.make
CS14Lab10: CMakeFiles/CS14Lab10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CS14Lab10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CS14Lab10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CS14Lab10.dir/build: CS14Lab10

.PHONY : CMakeFiles/CS14Lab10.dir/build

CMakeFiles/CS14Lab10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CS14Lab10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CS14Lab10.dir/clean

CMakeFiles/CS14Lab10.dir/depend:
	cd /Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lesliedejesus/CLionProjects/CS14Lab10 /Users/lesliedejesus/CLionProjects/CS14Lab10 /Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug /Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug /Users/lesliedejesus/CLionProjects/CS14Lab10/cmake-build-debug/CMakeFiles/CS14Lab10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CS14Lab10.dir/depend

