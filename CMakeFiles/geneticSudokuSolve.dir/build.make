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
CMAKE_BINARY_DIR = /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms

# Include any dependencies generated for this target.
include CMakeFiles/geneticSudokuSolve.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/geneticSudokuSolve.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/geneticSudokuSolve.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/geneticSudokuSolve.dir/flags.make

CMakeFiles/geneticSudokuSolve.dir/main.cpp.o: CMakeFiles/geneticSudokuSolve.dir/flags.make
CMakeFiles/geneticSudokuSolve.dir/main.cpp.o: main.cpp
CMakeFiles/geneticSudokuSolve.dir/main.cpp.o: CMakeFiles/geneticSudokuSolve.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/geneticSudokuSolve.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/geneticSudokuSolve.dir/main.cpp.o -MF CMakeFiles/geneticSudokuSolve.dir/main.cpp.o.d -o CMakeFiles/geneticSudokuSolve.dir/main.cpp.o -c /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/main.cpp

CMakeFiles/geneticSudokuSolve.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geneticSudokuSolve.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/main.cpp > CMakeFiles/geneticSudokuSolve.dir/main.cpp.i

CMakeFiles/geneticSudokuSolve.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geneticSudokuSolve.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/main.cpp -o CMakeFiles/geneticSudokuSolve.dir/main.cpp.s

# Object files for target geneticSudokuSolve
geneticSudokuSolve_OBJECTS = \
"CMakeFiles/geneticSudokuSolve.dir/main.cpp.o"

# External object files for target geneticSudokuSolve
geneticSudokuSolve_EXTERNAL_OBJECTS =

geneticSudokuSolve: CMakeFiles/geneticSudokuSolve.dir/main.cpp.o
geneticSudokuSolve: CMakeFiles/geneticSudokuSolve.dir/build.make
geneticSudokuSolve: src/libgenSudoSolver.a
geneticSudokuSolve: CMakeFiles/geneticSudokuSolve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable geneticSudokuSolve"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geneticSudokuSolve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/geneticSudokuSolve.dir/build: geneticSudokuSolve
.PHONY : CMakeFiles/geneticSudokuSolve.dir/build

CMakeFiles/geneticSudokuSolve.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/geneticSudokuSolve.dir/cmake_clean.cmake
.PHONY : CMakeFiles/geneticSudokuSolve.dir/clean

CMakeFiles/geneticSudokuSolve.dir/depend:
	cd /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms /Users/danielgergov/Documents/C++/Sudoku-Solver-w-Genetic-Algorithms/CMakeFiles/geneticSudokuSolve.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/geneticSudokuSolve.dir/depend

