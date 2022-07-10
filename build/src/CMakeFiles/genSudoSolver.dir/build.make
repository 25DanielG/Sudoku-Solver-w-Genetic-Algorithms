# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build

# Include any dependencies generated for this target.
include src/CMakeFiles/genSudoSolver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/genSudoSolver.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/genSudoSolver.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/genSudoSolver.dir/flags.make

src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o: src/CMakeFiles/genSudoSolver.dir/flags.make
src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o: ../src/libGenSudoSolver.cc
src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o: src/CMakeFiles/genSudoSolver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o"
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o -MF CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o.d -o CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o -c /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/src/libGenSudoSolver.cc

src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.i"
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/src/libGenSudoSolver.cc > CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.i

src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.s"
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/src/libGenSudoSolver.cc -o CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.s

# Object files for target genSudoSolver
genSudoSolver_OBJECTS = \
"CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o"

# External object files for target genSudoSolver
genSudoSolver_EXTERNAL_OBJECTS =

src/libgenSudoSolver.a: src/CMakeFiles/genSudoSolver.dir/libGenSudoSolver.cc.o
src/libgenSudoSolver.a: src/CMakeFiles/genSudoSolver.dir/build.make
src/libgenSudoSolver.a: src/CMakeFiles/genSudoSolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgenSudoSolver.a"
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src && $(CMAKE_COMMAND) -P CMakeFiles/genSudoSolver.dir/cmake_clean_target.cmake
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/genSudoSolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/genSudoSolver.dir/build: src/libgenSudoSolver.a
.PHONY : src/CMakeFiles/genSudoSolver.dir/build

src/CMakeFiles/genSudoSolver.dir/clean:
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src && $(CMAKE_COMMAND) -P CMakeFiles/genSudoSolver.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/genSudoSolver.dir/clean

src/CMakeFiles/genSudoSolver.dir/depend:
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/src /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/build/src/CMakeFiles/genSudoSolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/genSudoSolver.dir/depend

