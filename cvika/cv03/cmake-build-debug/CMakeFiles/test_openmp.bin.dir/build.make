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
CMAKE_SOURCE_DIR = /home/marek/Dokumenty/school/PDV/cvika/cv03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marek/Dokumenty/school/PDV/cvika/cv03/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_openmp.bin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_openmp.bin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_openmp.bin.dir/flags.make

CMakeFiles/test_openmp.bin.dir/test.cpp.o: CMakeFiles/test_openmp.bin.dir/flags.make
CMakeFiles/test_openmp.bin.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Dokumenty/school/PDV/cvika/cv03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_openmp.bin.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_openmp.bin.dir/test.cpp.o -c /home/marek/Dokumenty/school/PDV/cvika/cv03/test.cpp

CMakeFiles/test_openmp.bin.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_openmp.bin.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Dokumenty/school/PDV/cvika/cv03/test.cpp > CMakeFiles/test_openmp.bin.dir/test.cpp.i

CMakeFiles/test_openmp.bin.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_openmp.bin.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Dokumenty/school/PDV/cvika/cv03/test.cpp -o CMakeFiles/test_openmp.bin.dir/test.cpp.s

CMakeFiles/test_openmp.bin.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/test_openmp.bin.dir/test.cpp.o.requires

CMakeFiles/test_openmp.bin.dir/test.cpp.o.provides: CMakeFiles/test_openmp.bin.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_openmp.bin.dir/build.make CMakeFiles/test_openmp.bin.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/test_openmp.bin.dir/test.cpp.o.provides

CMakeFiles/test_openmp.bin.dir/test.cpp.o.provides.build: CMakeFiles/test_openmp.bin.dir/test.cpp.o


# Object files for target test_openmp.bin
test_openmp_bin_OBJECTS = \
"CMakeFiles/test_openmp.bin.dir/test.cpp.o"

# External object files for target test_openmp.bin
test_openmp_bin_EXTERNAL_OBJECTS =

test_openmp.bin: CMakeFiles/test_openmp.bin.dir/test.cpp.o
test_openmp.bin: CMakeFiles/test_openmp.bin.dir/build.make
test_openmp.bin: CMakeFiles/test_openmp.bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Dokumenty/school/PDV/cvika/cv03/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_openmp.bin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_openmp.bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_openmp.bin.dir/build: test_openmp.bin

.PHONY : CMakeFiles/test_openmp.bin.dir/build

CMakeFiles/test_openmp.bin.dir/requires: CMakeFiles/test_openmp.bin.dir/test.cpp.o.requires

.PHONY : CMakeFiles/test_openmp.bin.dir/requires

CMakeFiles/test_openmp.bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_openmp.bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_openmp.bin.dir/clean

CMakeFiles/test_openmp.bin.dir/depend:
	cd /home/marek/Dokumenty/school/PDV/cvika/cv03/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Dokumenty/school/PDV/cvika/cv03 /home/marek/Dokumenty/school/PDV/cvika/cv03 /home/marek/Dokumenty/school/PDV/cvika/cv03/cmake-build-debug /home/marek/Dokumenty/school/PDV/cvika/cv03/cmake-build-debug /home/marek/Dokumenty/school/PDV/cvika/cv03/cmake-build-debug/CMakeFiles/test_openmp.bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_openmp.bin.dir/depend

