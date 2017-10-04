# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/FYP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/FYP

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pi/FYP/CMakeFiles /home/pi/FYP/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pi/FYP/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named openALPR_test

# Build rule for target.
openALPR_test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 openALPR_test
.PHONY : openALPR_test

# fast build rule for target.
openALPR_test/fast:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/build
.PHONY : openALPR_test/fast

Sources/alpr_jpeg.o: Sources/alpr_jpeg.cpp.o

.PHONY : Sources/alpr_jpeg.o

# target to build an object file
Sources/alpr_jpeg.cpp.o:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o
.PHONY : Sources/alpr_jpeg.cpp.o

Sources/alpr_jpeg.i: Sources/alpr_jpeg.cpp.i

.PHONY : Sources/alpr_jpeg.i

# target to preprocess a source file
Sources/alpr_jpeg.cpp.i:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.i
.PHONY : Sources/alpr_jpeg.cpp.i

Sources/alpr_jpeg.s: Sources/alpr_jpeg.cpp.s

.PHONY : Sources/alpr_jpeg.s

# target to generate assembly for a file
Sources/alpr_jpeg.cpp.s:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.s
.PHONY : Sources/alpr_jpeg.cpp.s

Sources/launcher.o: Sources/launcher.cpp.o

.PHONY : Sources/launcher.o

# target to build an object file
Sources/launcher.cpp.o:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o
.PHONY : Sources/launcher.cpp.o

Sources/launcher.i: Sources/launcher.cpp.i

.PHONY : Sources/launcher.i

# target to preprocess a source file
Sources/launcher.cpp.i:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.i
.PHONY : Sources/launcher.cpp.i

Sources/launcher.s: Sources/launcher.cpp.s

.PHONY : Sources/launcher.s

# target to generate assembly for a file
Sources/launcher.cpp.s:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.s
.PHONY : Sources/launcher.cpp.s

Sources/v4l2_factory.o: Sources/v4l2_factory.cpp.o

.PHONY : Sources/v4l2_factory.o

# target to build an object file
Sources/v4l2_factory.cpp.o:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/v4l2_factory.cpp.o
.PHONY : Sources/v4l2_factory.cpp.o

Sources/v4l2_factory.i: Sources/v4l2_factory.cpp.i

.PHONY : Sources/v4l2_factory.i

# target to preprocess a source file
Sources/v4l2_factory.cpp.i:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/v4l2_factory.cpp.i
.PHONY : Sources/v4l2_factory.cpp.i

Sources/v4l2_factory.s: Sources/v4l2_factory.cpp.s

.PHONY : Sources/v4l2_factory.s

# target to generate assembly for a file
Sources/v4l2_factory.cpp.s:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/v4l2_factory.cpp.s
.PHONY : Sources/v4l2_factory.cpp.s

Sources/v4l2_jpeg.o: Sources/v4l2_jpeg.cpp.o

.PHONY : Sources/v4l2_jpeg.o

# target to build an object file
Sources/v4l2_jpeg.cpp.o:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/v4l2_jpeg.cpp.o
.PHONY : Sources/v4l2_jpeg.cpp.o

Sources/v4l2_jpeg.i: Sources/v4l2_jpeg.cpp.i

.PHONY : Sources/v4l2_jpeg.i

# target to preprocess a source file
Sources/v4l2_jpeg.cpp.i:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/v4l2_jpeg.cpp.i
.PHONY : Sources/v4l2_jpeg.cpp.i

Sources/v4l2_jpeg.s: Sources/v4l2_jpeg.cpp.s

.PHONY : Sources/v4l2_jpeg.s

# target to generate assembly for a file
Sources/v4l2_jpeg.cpp.s:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/v4l2_jpeg.cpp.s
.PHONY : Sources/v4l2_jpeg.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... openALPR_test"
	@echo "... Sources/alpr_jpeg.o"
	@echo "... Sources/alpr_jpeg.i"
	@echo "... Sources/alpr_jpeg.s"
	@echo "... Sources/launcher.o"
	@echo "... Sources/launcher.i"
	@echo "... Sources/launcher.s"
	@echo "... Sources/v4l2_factory.o"
	@echo "... Sources/v4l2_factory.i"
	@echo "... Sources/v4l2_factory.s"
	@echo "... Sources/v4l2_jpeg.o"
	@echo "... Sources/v4l2_jpeg.i"
	@echo "... Sources/v4l2_jpeg.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

