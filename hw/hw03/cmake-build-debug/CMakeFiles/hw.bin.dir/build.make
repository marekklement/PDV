# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/marek/Dokumenty/instalers/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/marek/Dokumenty/instalers/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marek/Dokumenty/school/PDV/hw03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw.bin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw.bin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw.bin.dir/flags.make

CMakeFiles/hw.bin.dir/main.cpp.o: CMakeFiles/hw.bin.dir/flags.make
CMakeFiles/hw.bin.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hw.bin.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.bin.dir/main.cpp.o -c /home/marek/Dokumenty/school/PDV/hw03/main.cpp

CMakeFiles/hw.bin.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.bin.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Dokumenty/school/PDV/hw03/main.cpp > CMakeFiles/hw.bin.dir/main.cpp.i

CMakeFiles/hw.bin.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.bin.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Dokumenty/school/PDV/hw03/main.cpp -o CMakeFiles/hw.bin.dir/main.cpp.s

CMakeFiles/hw.bin.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/hw.bin.dir/main.cpp.o.requires

CMakeFiles/hw.bin.dir/main.cpp.o.provides: CMakeFiles/hw.bin.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw.bin.dir/build.make CMakeFiles/hw.bin.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/hw.bin.dir/main.cpp.o.provides

CMakeFiles/hw.bin.dir/main.cpp.o.provides.build: CMakeFiles/hw.bin.dir/main.cpp.o


CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o: CMakeFiles/hw.bin.dir/flags.make
CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o: ../_dataGenerator/DataGenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o -c /home/marek/Dokumenty/school/PDV/hw03/_dataGenerator/DataGenerator.cpp

CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Dokumenty/school/PDV/hw03/_dataGenerator/DataGenerator.cpp > CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.i

CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Dokumenty/school/PDV/hw03/_dataGenerator/DataGenerator.cpp -o CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.s

CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.requires:

.PHONY : CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.requires

CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.provides: CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw.bin.dir/build.make CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.provides.build
.PHONY : CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.provides

CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.provides.build: CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o


CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o: CMakeFiles/hw.bin.dir/flags.make
CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o: ../SumsOfVectors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o -c /home/marek/Dokumenty/school/PDV/hw03/SumsOfVectors.cpp

CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Dokumenty/school/PDV/hw03/SumsOfVectors.cpp > CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.i

CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Dokumenty/school/PDV/hw03/SumsOfVectors.cpp -o CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.s

CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.requires:

.PHONY : CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.requires

CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.provides: CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw.bin.dir/build.make CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.provides.build
.PHONY : CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.provides

CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.provides.build: CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o


CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o: CMakeFiles/hw.bin.dir/flags.make
CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o: ../_executor/Executor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o -c /home/marek/Dokumenty/school/PDV/hw03/_executor/Executor.cpp

CMakeFiles/hw.bin.dir/_executor/Executor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw.bin.dir/_executor/Executor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Dokumenty/school/PDV/hw03/_executor/Executor.cpp > CMakeFiles/hw.bin.dir/_executor/Executor.cpp.i

CMakeFiles/hw.bin.dir/_executor/Executor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw.bin.dir/_executor/Executor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Dokumenty/school/PDV/hw03/_executor/Executor.cpp -o CMakeFiles/hw.bin.dir/_executor/Executor.cpp.s

CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.requires:

.PHONY : CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.requires

CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.provides: CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw.bin.dir/build.make CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.provides.build
.PHONY : CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.provides

CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.provides.build: CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o


# Object files for target hw.bin
hw_bin_OBJECTS = \
"CMakeFiles/hw.bin.dir/main.cpp.o" \
"CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o" \
"CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o" \
"CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o"

# External object files for target hw.bin
hw_bin_EXTERNAL_OBJECTS =

hw.bin: CMakeFiles/hw.bin.dir/main.cpp.o
hw.bin: CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o
hw.bin: CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o
hw.bin: CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o
hw.bin: CMakeFiles/hw.bin.dir/build.make
hw.bin: CMakeFiles/hw.bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable hw.bin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw.bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw.bin.dir/build: hw.bin

.PHONY : CMakeFiles/hw.bin.dir/build

CMakeFiles/hw.bin.dir/requires: CMakeFiles/hw.bin.dir/main.cpp.o.requires
CMakeFiles/hw.bin.dir/requires: CMakeFiles/hw.bin.dir/_dataGenerator/DataGenerator.cpp.o.requires
CMakeFiles/hw.bin.dir/requires: CMakeFiles/hw.bin.dir/SumsOfVectors.cpp.o.requires
CMakeFiles/hw.bin.dir/requires: CMakeFiles/hw.bin.dir/_executor/Executor.cpp.o.requires

.PHONY : CMakeFiles/hw.bin.dir/requires

CMakeFiles/hw.bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw.bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw.bin.dir/clean

CMakeFiles/hw.bin.dir/depend:
	cd /home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Dokumenty/school/PDV/hw03 /home/marek/Dokumenty/school/PDV/hw03 /home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug /home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug /home/marek/Dokumenty/school/PDV/hw03/cmake-build-debug/CMakeFiles/hw.bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw.bin.dir/depend

