# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/daria/tda_video

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daria/tda_video

# Include any dependencies generated for this target.
include CMakeFiles/morphing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/morphing.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/morphing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/morphing.dir/flags.make

CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o: CMakeFiles/morphing.dir/flags.make
CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o: estudiante/src/morphing.cpp
CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o: CMakeFiles/morphing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/daria/tda_video/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o -MF CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o.d -o CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o -c /home/daria/tda_video/estudiante/src/morphing.cpp

CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daria/tda_video/estudiante/src/morphing.cpp > CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.i

CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daria/tda_video/estudiante/src/morphing.cpp -o CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.s

# Object files for target morphing
morphing_OBJECTS = \
"CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o"

# External object files for target morphing
morphing_EXTERNAL_OBJECTS =

morphing: CMakeFiles/morphing.dir/estudiante/src/morphing.cpp.o
morphing: CMakeFiles/morphing.dir/build.make
morphing: libvideo.a
morphing: CMakeFiles/morphing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/daria/tda_video/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable morphing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/morphing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/morphing.dir/build: morphing
.PHONY : CMakeFiles/morphing.dir/build

CMakeFiles/morphing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/morphing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/morphing.dir/clean

CMakeFiles/morphing.dir/depend:
	cd /home/daria/tda_video && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daria/tda_video /home/daria/tda_video /home/daria/tda_video /home/daria/tda_video /home/daria/tda_video/CMakeFiles/morphing.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/morphing.dir/depend

