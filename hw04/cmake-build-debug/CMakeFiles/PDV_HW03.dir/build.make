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
CMAKE_SOURCE_DIR = /home/marek/Dokumenty/school/PDV/hw04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PDV_HW03.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PDV_HW03.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PDV_HW03.dir/flags.make

CMakeFiles/PDV_HW03.dir/main.cpp.o: CMakeFiles/PDV_HW03.dir/flags.make
CMakeFiles/PDV_HW03.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PDV_HW03.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PDV_HW03.dir/main.cpp.o -c /home/marek/Dokumenty/school/PDV/hw04/main.cpp

CMakeFiles/PDV_HW03.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PDV_HW03.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Dokumenty/school/PDV/hw04/main.cpp > CMakeFiles/PDV_HW03.dir/main.cpp.i

CMakeFiles/PDV_HW03.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PDV_HW03.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Dokumenty/school/PDV/hw04/main.cpp -o CMakeFiles/PDV_HW03.dir/main.cpp.s

CMakeFiles/PDV_HW03.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PDV_HW03.dir/main.cpp.o.requires

CMakeFiles/PDV_HW03.dir/main.cpp.o.provides: CMakeFiles/PDV_HW03.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PDV_HW03.dir/build.make CMakeFiles/PDV_HW03.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PDV_HW03.dir/main.cpp.o.provides

CMakeFiles/PDV_HW03.dir/main.cpp.o.provides.build: CMakeFiles/PDV_HW03.dir/main.cpp.o


CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o: CMakeFiles/PDV_HW03.dir/flags.make
CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o: ../bst_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o -c /home/marek/Dokumenty/school/PDV/hw04/bst_tree.cpp

CMakeFiles/PDV_HW03.dir/bst_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PDV_HW03.dir/bst_tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marek/Dokumenty/school/PDV/hw04/bst_tree.cpp > CMakeFiles/PDV_HW03.dir/bst_tree.cpp.i

CMakeFiles/PDV_HW03.dir/bst_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PDV_HW03.dir/bst_tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marek/Dokumenty/school/PDV/hw04/bst_tree.cpp -o CMakeFiles/PDV_HW03.dir/bst_tree.cpp.s

CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.requires:

.PHONY : CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.requires

CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.provides: CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.requires
	$(MAKE) -f CMakeFiles/PDV_HW03.dir/build.make CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.provides.build
.PHONY : CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.provides

CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.provides.build: CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o


# Object files for target PDV_HW03
PDV_HW03_OBJECTS = \
"CMakeFiles/PDV_HW03.dir/main.cpp.o" \
"CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o"

# External object files for target PDV_HW03
PDV_HW03_EXTERNAL_OBJECTS =

PDV_HW03: CMakeFiles/PDV_HW03.dir/main.cpp.o
PDV_HW03: CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o
PDV_HW03: CMakeFiles/PDV_HW03.dir/build.make
PDV_HW03: CMakeFiles/PDV_HW03.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PDV_HW03"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PDV_HW03.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PDV_HW03.dir/build: PDV_HW03

.PHONY : CMakeFiles/PDV_HW03.dir/build

CMakeFiles/PDV_HW03.dir/requires: CMakeFiles/PDV_HW03.dir/main.cpp.o.requires
CMakeFiles/PDV_HW03.dir/requires: CMakeFiles/PDV_HW03.dir/bst_tree.cpp.o.requires

.PHONY : CMakeFiles/PDV_HW03.dir/requires

CMakeFiles/PDV_HW03.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PDV_HW03.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PDV_HW03.dir/clean

CMakeFiles/PDV_HW03.dir/depend:
	cd /home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marek/Dokumenty/school/PDV/hw04 /home/marek/Dokumenty/school/PDV/hw04 /home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug /home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug /home/marek/Dokumenty/school/PDV/hw04/cmake-build-debug/CMakeFiles/PDV_HW03.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PDV_HW03.dir/depend

