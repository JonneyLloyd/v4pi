# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/FYP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/FYP

# Include any dependencies generated for this target.
include CMakeFiles/openALPR_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openALPR_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openALPR_test.dir/flags.make

CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o: CMakeFiles/openALPR_test.dir/flags.make
CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o: Sources/alpr_jpeg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/FYP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o -c /home/pi/FYP/Sources/alpr_jpeg.cpp

CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/FYP/Sources/alpr_jpeg.cpp > CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.i

CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/FYP/Sources/alpr_jpeg.cpp -o CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.s

CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.requires:

.PHONY : CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.requires

CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.provides: CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.requires
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.provides.build
.PHONY : CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.provides

CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.provides.build: CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o


CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o: CMakeFiles/openALPR_test.dir/flags.make
CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o: Sources/camera_grab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/FYP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o -c /home/pi/FYP/Sources/camera_grab.cpp

CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/FYP/Sources/camera_grab.cpp > CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.i

CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/FYP/Sources/camera_grab.cpp -o CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.s

CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.requires:

.PHONY : CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.requires

CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.provides: CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.requires
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.provides.build
.PHONY : CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.provides

CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.provides.build: CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o


CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o: CMakeFiles/openALPR_test.dir/flags.make
CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o: Sources/launcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/FYP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o -c /home/pi/FYP/Sources/launcher.cpp

CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/FYP/Sources/launcher.cpp > CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.i

CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/FYP/Sources/launcher.cpp -o CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.s

CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.requires:

.PHONY : CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.requires

CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.provides: CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.requires
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.provides.build
.PHONY : CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.provides

CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.provides.build: CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o


CMakeFiles/openALPR_test.dir/main.cpp.o: CMakeFiles/openALPR_test.dir/flags.make
CMakeFiles/openALPR_test.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/FYP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/openALPR_test.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/openALPR_test.dir/main.cpp.o -c /home/pi/FYP/main.cpp

CMakeFiles/openALPR_test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openALPR_test.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/FYP/main.cpp > CMakeFiles/openALPR_test.dir/main.cpp.i

CMakeFiles/openALPR_test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openALPR_test.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/FYP/main.cpp -o CMakeFiles/openALPR_test.dir/main.cpp.s

CMakeFiles/openALPR_test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/openALPR_test.dir/main.cpp.o.requires

CMakeFiles/openALPR_test.dir/main.cpp.o.provides: CMakeFiles/openALPR_test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/openALPR_test.dir/build.make CMakeFiles/openALPR_test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/openALPR_test.dir/main.cpp.o.provides

CMakeFiles/openALPR_test.dir/main.cpp.o.provides.build: CMakeFiles/openALPR_test.dir/main.cpp.o


# Object files for target openALPR_test
openALPR_test_OBJECTS = \
"CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o" \
"CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o" \
"CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o" \
"CMakeFiles/openALPR_test.dir/main.cpp.o"

# External object files for target openALPR_test
openALPR_test_EXTERNAL_OBJECTS =

openALPR_test: CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o
openALPR_test: CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o
openALPR_test: CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o
openALPR_test: CMakeFiles/openALPR_test.dir/main.cpp.o
openALPR_test: CMakeFiles/openALPR_test.dir/build.make
openALPR_test: /home/pi/openalpr/src/build/openalpr/libopenalpr.so
openALPR_test: CMakeFiles/openALPR_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/FYP/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable openALPR_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openALPR_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/openALPR_test.dir/build: openALPR_test

.PHONY : CMakeFiles/openALPR_test.dir/build

CMakeFiles/openALPR_test.dir/requires: CMakeFiles/openALPR_test.dir/Sources/alpr_jpeg.cpp.o.requires
CMakeFiles/openALPR_test.dir/requires: CMakeFiles/openALPR_test.dir/Sources/camera_grab.cpp.o.requires
CMakeFiles/openALPR_test.dir/requires: CMakeFiles/openALPR_test.dir/Sources/launcher.cpp.o.requires
CMakeFiles/openALPR_test.dir/requires: CMakeFiles/openALPR_test.dir/main.cpp.o.requires

.PHONY : CMakeFiles/openALPR_test.dir/requires

CMakeFiles/openALPR_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/openALPR_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/openALPR_test.dir/clean

CMakeFiles/openALPR_test.dir/depend:
	cd /home/pi/FYP && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/FYP /home/pi/FYP /home/pi/FYP /home/pi/FYP /home/pi/FYP/CMakeFiles/openALPR_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openALPR_test.dir/depend

