# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hpy/ospf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hpy/ospf/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ospf.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ospf.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ospf.dir/flags.make

src/CMakeFiles/ospf.dir/Thread.cpp.o: src/CMakeFiles/ospf.dir/flags.make
src/CMakeFiles/ospf.dir/Thread.cpp.o: ../src/Thread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hpy/ospf/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/ospf.dir/Thread.cpp.o"
	cd /home/hpy/ospf/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ospf.dir/Thread.cpp.o -c /home/hpy/ospf/src/Thread.cpp

src/CMakeFiles/ospf.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ospf.dir/Thread.cpp.i"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hpy/ospf/src/Thread.cpp > CMakeFiles/ospf.dir/Thread.cpp.i

src/CMakeFiles/ospf.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ospf.dir/Thread.cpp.s"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hpy/ospf/src/Thread.cpp -o CMakeFiles/ospf.dir/Thread.cpp.s

src/CMakeFiles/ospf.dir/Thread.cpp.o.requires:
.PHONY : src/CMakeFiles/ospf.dir/Thread.cpp.o.requires

src/CMakeFiles/ospf.dir/Thread.cpp.o.provides: src/CMakeFiles/ospf.dir/Thread.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ospf.dir/build.make src/CMakeFiles/ospf.dir/Thread.cpp.o.provides.build
.PHONY : src/CMakeFiles/ospf.dir/Thread.cpp.o.provides

src/CMakeFiles/ospf.dir/Thread.cpp.o.provides.build: src/CMakeFiles/ospf.dir/Thread.cpp.o

src/CMakeFiles/ospf.dir/ThreadPool.cpp.o: src/CMakeFiles/ospf.dir/flags.make
src/CMakeFiles/ospf.dir/ThreadPool.cpp.o: ../src/ThreadPool.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hpy/ospf/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/ospf.dir/ThreadPool.cpp.o"
	cd /home/hpy/ospf/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ospf.dir/ThreadPool.cpp.o -c /home/hpy/ospf/src/ThreadPool.cpp

src/CMakeFiles/ospf.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ospf.dir/ThreadPool.cpp.i"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hpy/ospf/src/ThreadPool.cpp > CMakeFiles/ospf.dir/ThreadPool.cpp.i

src/CMakeFiles/ospf.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ospf.dir/ThreadPool.cpp.s"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hpy/ospf/src/ThreadPool.cpp -o CMakeFiles/ospf.dir/ThreadPool.cpp.s

src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.requires:
.PHONY : src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.requires

src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.provides: src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ospf.dir/build.make src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.provides.build
.PHONY : src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.provides

src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.provides.build: src/CMakeFiles/ospf.dir/ThreadPool.cpp.o

src/CMakeFiles/ospf.dir/Simulate.cpp.o: src/CMakeFiles/ospf.dir/flags.make
src/CMakeFiles/ospf.dir/Simulate.cpp.o: ../src/Simulate.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hpy/ospf/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/ospf.dir/Simulate.cpp.o"
	cd /home/hpy/ospf/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ospf.dir/Simulate.cpp.o -c /home/hpy/ospf/src/Simulate.cpp

src/CMakeFiles/ospf.dir/Simulate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ospf.dir/Simulate.cpp.i"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hpy/ospf/src/Simulate.cpp > CMakeFiles/ospf.dir/Simulate.cpp.i

src/CMakeFiles/ospf.dir/Simulate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ospf.dir/Simulate.cpp.s"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hpy/ospf/src/Simulate.cpp -o CMakeFiles/ospf.dir/Simulate.cpp.s

src/CMakeFiles/ospf.dir/Simulate.cpp.o.requires:
.PHONY : src/CMakeFiles/ospf.dir/Simulate.cpp.o.requires

src/CMakeFiles/ospf.dir/Simulate.cpp.o.provides: src/CMakeFiles/ospf.dir/Simulate.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ospf.dir/build.make src/CMakeFiles/ospf.dir/Simulate.cpp.o.provides.build
.PHONY : src/CMakeFiles/ospf.dir/Simulate.cpp.o.provides

src/CMakeFiles/ospf.dir/Simulate.cpp.o.provides.build: src/CMakeFiles/ospf.dir/Simulate.cpp.o

src/CMakeFiles/ospf.dir/Syscalls.cpp.o: src/CMakeFiles/ospf.dir/flags.make
src/CMakeFiles/ospf.dir/Syscalls.cpp.o: ../src/Syscalls.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hpy/ospf/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/ospf.dir/Syscalls.cpp.o"
	cd /home/hpy/ospf/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ospf.dir/Syscalls.cpp.o -c /home/hpy/ospf/src/Syscalls.cpp

src/CMakeFiles/ospf.dir/Syscalls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ospf.dir/Syscalls.cpp.i"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hpy/ospf/src/Syscalls.cpp > CMakeFiles/ospf.dir/Syscalls.cpp.i

src/CMakeFiles/ospf.dir/Syscalls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ospf.dir/Syscalls.cpp.s"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hpy/ospf/src/Syscalls.cpp -o CMakeFiles/ospf.dir/Syscalls.cpp.s

src/CMakeFiles/ospf.dir/Syscalls.cpp.o.requires:
.PHONY : src/CMakeFiles/ospf.dir/Syscalls.cpp.o.requires

src/CMakeFiles/ospf.dir/Syscalls.cpp.o.provides: src/CMakeFiles/ospf.dir/Syscalls.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ospf.dir/build.make src/CMakeFiles/ospf.dir/Syscalls.cpp.o.provides.build
.PHONY : src/CMakeFiles/ospf.dir/Syscalls.cpp.o.provides

src/CMakeFiles/ospf.dir/Syscalls.cpp.o.provides.build: src/CMakeFiles/ospf.dir/Syscalls.cpp.o

src/CMakeFiles/ospf.dir/main.cpp.o: src/CMakeFiles/ospf.dir/flags.make
src/CMakeFiles/ospf.dir/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/hpy/ospf/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/ospf.dir/main.cpp.o"
	cd /home/hpy/ospf/build/src && g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ospf.dir/main.cpp.o -c /home/hpy/ospf/src/main.cpp

src/CMakeFiles/ospf.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ospf.dir/main.cpp.i"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/hpy/ospf/src/main.cpp > CMakeFiles/ospf.dir/main.cpp.i

src/CMakeFiles/ospf.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ospf.dir/main.cpp.s"
	cd /home/hpy/ospf/build/src && g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/hpy/ospf/src/main.cpp -o CMakeFiles/ospf.dir/main.cpp.s

src/CMakeFiles/ospf.dir/main.cpp.o.requires:
.PHONY : src/CMakeFiles/ospf.dir/main.cpp.o.requires

src/CMakeFiles/ospf.dir/main.cpp.o.provides: src/CMakeFiles/ospf.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/ospf.dir/build.make src/CMakeFiles/ospf.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/ospf.dir/main.cpp.o.provides

src/CMakeFiles/ospf.dir/main.cpp.o.provides.build: src/CMakeFiles/ospf.dir/main.cpp.o

# Object files for target ospf
ospf_OBJECTS = \
"CMakeFiles/ospf.dir/Thread.cpp.o" \
"CMakeFiles/ospf.dir/ThreadPool.cpp.o" \
"CMakeFiles/ospf.dir/Simulate.cpp.o" \
"CMakeFiles/ospf.dir/Syscalls.cpp.o" \
"CMakeFiles/ospf.dir/main.cpp.o"

# External object files for target ospf
ospf_EXTERNAL_OBJECTS =

ospf: src/CMakeFiles/ospf.dir/Thread.cpp.o
ospf: src/CMakeFiles/ospf.dir/ThreadPool.cpp.o
ospf: src/CMakeFiles/ospf.dir/Simulate.cpp.o
ospf: src/CMakeFiles/ospf.dir/Syscalls.cpp.o
ospf: src/CMakeFiles/ospf.dir/main.cpp.o
ospf: src/CMakeFiles/ospf.dir/build.make
ospf: src/CMakeFiles/ospf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../ospf"
	cd /home/hpy/ospf/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ospf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ospf.dir/build: ospf
.PHONY : src/CMakeFiles/ospf.dir/build

src/CMakeFiles/ospf.dir/requires: src/CMakeFiles/ospf.dir/Thread.cpp.o.requires
src/CMakeFiles/ospf.dir/requires: src/CMakeFiles/ospf.dir/ThreadPool.cpp.o.requires
src/CMakeFiles/ospf.dir/requires: src/CMakeFiles/ospf.dir/Simulate.cpp.o.requires
src/CMakeFiles/ospf.dir/requires: src/CMakeFiles/ospf.dir/Syscalls.cpp.o.requires
src/CMakeFiles/ospf.dir/requires: src/CMakeFiles/ospf.dir/main.cpp.o.requires
.PHONY : src/CMakeFiles/ospf.dir/requires

src/CMakeFiles/ospf.dir/clean:
	cd /home/hpy/ospf/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ospf.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ospf.dir/clean

src/CMakeFiles/ospf.dir/depend:
	cd /home/hpy/ospf/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hpy/ospf /home/hpy/ospf/src /home/hpy/ospf/build /home/hpy/ospf/build/src /home/hpy/ospf/build/src/CMakeFiles/ospf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ospf.dir/depend
