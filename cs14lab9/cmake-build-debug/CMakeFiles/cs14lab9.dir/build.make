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
CMAKE_SOURCE_DIR = /Users/lesliedejesus/CLionProjects/cs14lab9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lesliedejesus/CLionProjects/cs14lab9/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cs14lab9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cs14lab9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cs14lab9.dir/flags.make

CMakeFiles/cs14lab9.dir/main.cpp.o: CMakeFiles/cs14lab9.dir/flags.make
CMakeFiles/cs14lab9.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lesliedejesus/CLionProjects/cs14lab9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cs14lab9.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cs14lab9.dir/main.cpp.o -c /Users/lesliedejesus/CLionProjects/cs14lab9/main.cpp

CMakeFiles/cs14lab9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cs14lab9.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lesliedejesus/CLionProjects/cs14lab9/main.cpp > CMakeFiles/cs14lab9.dir/main.cpp.i

CMakeFiles/cs14lab9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cs14lab9.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lesliedejesus/CLionProjects/cs14lab9/main.cpp -o CMakeFiles/cs14lab9.dir/main.cpp.s

# Object files for target cs14lab9
cs14lab9_OBJECTS = \
"CMakeFiles/cs14lab9.dir/main.cpp.o"

# External object files for target cs14lab9
cs14lab9_EXTERNAL_OBJECTS =

cs14lab9: CMakeFiles/cs14lab9.dir/main.cpp.o
cs14lab9: CMakeFiles/cs14lab9.dir/build.make
cs14lab9: CMakeFiles/cs14lab9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lesliedejesus/CLionProjects/cs14lab9/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cs14lab9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cs14lab9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cs14lab9.dir/build: cs14lab9

.PHONY : CMakeFiles/cs14lab9.dir/build

CMakeFiles/cs14lab9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cs14lab9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cs14lab9.dir/clean

CMakeFiles/cs14lab9.dir/depend:
	cd /Users/lesliedejesus/CLionProjects/cs14lab9/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lesliedejesus/CLionProjects/cs14lab9 /Users/lesliedejesus/CLionProjects/cs14lab9 /Users/lesliedejesus/CLionProjects/cs14lab9/cmake-build-debug /Users/lesliedejesus/CLionProjects/cs14lab9/cmake-build-debug /Users/lesliedejesus/CLionProjects/cs14lab9/cmake-build-debug/CMakeFiles/cs14lab9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cs14lab9.dir/depend

