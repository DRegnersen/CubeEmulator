# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\deofr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\deofr\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\deofr\C++\CubeEmulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\deofr\C++\CubeEmulator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CubeEmulator.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CubeEmulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CubeEmulator.dir/flags.make

CMakeFiles/CubeEmulator.dir/main.cpp.obj: CMakeFiles/CubeEmulator.dir/flags.make
CMakeFiles/CubeEmulator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\deofr\C++\CubeEmulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CubeEmulator.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CubeEmulator.dir\main.cpp.obj -c C:\Users\deofr\C++\CubeEmulator\main.cpp

CMakeFiles/CubeEmulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CubeEmulator.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\deofr\C++\CubeEmulator\main.cpp > CMakeFiles\CubeEmulator.dir\main.cpp.i

CMakeFiles/CubeEmulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CubeEmulator.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\deofr\C++\CubeEmulator\main.cpp -o CMakeFiles\CubeEmulator.dir\main.cpp.s

CMakeFiles/CubeEmulator.dir/Cube.cpp.obj: CMakeFiles/CubeEmulator.dir/flags.make
CMakeFiles/CubeEmulator.dir/Cube.cpp.obj: ../Cube.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\deofr\C++\CubeEmulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CubeEmulator.dir/Cube.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CubeEmulator.dir\Cube.cpp.obj -c C:\Users\deofr\C++\CubeEmulator\Cube.cpp

CMakeFiles/CubeEmulator.dir/Cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CubeEmulator.dir/Cube.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\deofr\C++\CubeEmulator\Cube.cpp > CMakeFiles\CubeEmulator.dir\Cube.cpp.i

CMakeFiles/CubeEmulator.dir/Cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CubeEmulator.dir/Cube.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\deofr\C++\CubeEmulator\Cube.cpp -o CMakeFiles\CubeEmulator.dir\Cube.cpp.s

CMakeFiles/CubeEmulator.dir/Solver.cpp.obj: CMakeFiles/CubeEmulator.dir/flags.make
CMakeFiles/CubeEmulator.dir/Solver.cpp.obj: ../Solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\deofr\C++\CubeEmulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CubeEmulator.dir/Solver.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CubeEmulator.dir\Solver.cpp.obj -c C:\Users\deofr\C++\CubeEmulator\Solver.cpp

CMakeFiles/CubeEmulator.dir/Solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CubeEmulator.dir/Solver.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\deofr\C++\CubeEmulator\Solver.cpp > CMakeFiles\CubeEmulator.dir\Solver.cpp.i

CMakeFiles/CubeEmulator.dir/Solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CubeEmulator.dir/Solver.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\deofr\C++\CubeEmulator\Solver.cpp -o CMakeFiles\CubeEmulator.dir\Solver.cpp.s

# Object files for target CubeEmulator
CubeEmulator_OBJECTS = \
"CMakeFiles/CubeEmulator.dir/main.cpp.obj" \
"CMakeFiles/CubeEmulator.dir/Cube.cpp.obj" \
"CMakeFiles/CubeEmulator.dir/Solver.cpp.obj"

# External object files for target CubeEmulator
CubeEmulator_EXTERNAL_OBJECTS =

CubeEmulator.exe: CMakeFiles/CubeEmulator.dir/main.cpp.obj
CubeEmulator.exe: CMakeFiles/CubeEmulator.dir/Cube.cpp.obj
CubeEmulator.exe: CMakeFiles/CubeEmulator.dir/Solver.cpp.obj
CubeEmulator.exe: CMakeFiles/CubeEmulator.dir/build.make
CubeEmulator.exe: CMakeFiles/CubeEmulator.dir/linklibs.rsp
CubeEmulator.exe: CMakeFiles/CubeEmulator.dir/objects1.rsp
CubeEmulator.exe: CMakeFiles/CubeEmulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\deofr\C++\CubeEmulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable CubeEmulator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CubeEmulator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CubeEmulator.dir/build: CubeEmulator.exe
.PHONY : CMakeFiles/CubeEmulator.dir/build

CMakeFiles/CubeEmulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CubeEmulator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CubeEmulator.dir/clean

CMakeFiles/CubeEmulator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\deofr\C++\CubeEmulator C:\Users\deofr\C++\CubeEmulator C:\Users\deofr\C++\CubeEmulator\cmake-build-debug C:\Users\deofr\C++\CubeEmulator\cmake-build-debug C:\Users\deofr\C++\CubeEmulator\cmake-build-debug\CMakeFiles\CubeEmulator.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CubeEmulator.dir/depend

