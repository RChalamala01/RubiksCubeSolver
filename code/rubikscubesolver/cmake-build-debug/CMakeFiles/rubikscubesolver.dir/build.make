# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = "/Users/rohit/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/rohit/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.6682.181/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rubikscubesolver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rubikscubesolver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rubikscubesolver.dir/flags.make

CMakeFiles/rubikscubesolver.dir/main.cpp.o: CMakeFiles/rubikscubesolver.dir/flags.make
CMakeFiles/rubikscubesolver.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rubikscubesolver.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rubikscubesolver.dir/main.cpp.o -c /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/main.cpp

CMakeFiles/rubikscubesolver.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rubikscubesolver.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/main.cpp > CMakeFiles/rubikscubesolver.dir/main.cpp.i

CMakeFiles/rubikscubesolver.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rubikscubesolver.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/main.cpp -o CMakeFiles/rubikscubesolver.dir/main.cpp.s

CMakeFiles/rubikscubesolver.dir/createcube.cpp.o: CMakeFiles/rubikscubesolver.dir/flags.make
CMakeFiles/rubikscubesolver.dir/createcube.cpp.o: ../createcube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rubikscubesolver.dir/createcube.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rubikscubesolver.dir/createcube.cpp.o -c /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/createcube.cpp

CMakeFiles/rubikscubesolver.dir/createcube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rubikscubesolver.dir/createcube.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/createcube.cpp > CMakeFiles/rubikscubesolver.dir/createcube.cpp.i

CMakeFiles/rubikscubesolver.dir/createcube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rubikscubesolver.dir/createcube.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/createcube.cpp -o CMakeFiles/rubikscubesolver.dir/createcube.cpp.s

# Object files for target rubikscubesolver
rubikscubesolver_OBJECTS = \
"CMakeFiles/rubikscubesolver.dir/main.cpp.o" \
"CMakeFiles/rubikscubesolver.dir/createcube.cpp.o"

# External object files for target rubikscubesolver
rubikscubesolver_EXTERNAL_OBJECTS =

rubikscubesolver: CMakeFiles/rubikscubesolver.dir/main.cpp.o
rubikscubesolver: CMakeFiles/rubikscubesolver.dir/createcube.cpp.o
rubikscubesolver: CMakeFiles/rubikscubesolver.dir/build.make
rubikscubesolver: CMakeFiles/rubikscubesolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable rubikscubesolver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rubikscubesolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rubikscubesolver.dir/build: rubikscubesolver

.PHONY : CMakeFiles/rubikscubesolver.dir/build

CMakeFiles/rubikscubesolver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rubikscubesolver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rubikscubesolver.dir/clean

CMakeFiles/rubikscubesolver.dir/depend:
	cd /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug /Users/rohit/Documents/GitHub/RubiksCubeSolver/code/rubikscubesolver/cmake-build-debug/CMakeFiles/rubikscubesolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rubikscubesolver.dir/depend

