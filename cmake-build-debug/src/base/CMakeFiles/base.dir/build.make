# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/yaochuanwang/CLion-2020.2.1/clion-2020.2.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yaochuanwang/CLion-2020.2.1/clion-2020.2.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yaochuanwang/CLionProjects/SimpleWebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug

# Include any dependencies generated for this target.
include src/base/CMakeFiles/base.dir/depend.make

# Include the progress variables for this target.
include src/base/CMakeFiles/base.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/CMakeFiles/base.dir/flags.make

src/base/CMakeFiles/base.dir/FileUtil.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/FileUtil.cpp.o: ../src/base/FileUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/CMakeFiles/base.dir/FileUtil.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/FileUtil.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/FileUtil.cpp

src/base/CMakeFiles/base.dir/FileUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/FileUtil.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/FileUtil.cpp > CMakeFiles/base.dir/FileUtil.cpp.i

src/base/CMakeFiles/base.dir/FileUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/FileUtil.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/FileUtil.cpp -o CMakeFiles/base.dir/FileUtil.cpp.s

src/base/CMakeFiles/base.dir/LogFile.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/LogFile.cpp.o: ../src/base/LogFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/base/CMakeFiles/base.dir/LogFile.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/LogFile.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogFile.cpp

src/base/CMakeFiles/base.dir/LogFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/LogFile.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogFile.cpp > CMakeFiles/base.dir/LogFile.cpp.i

src/base/CMakeFiles/base.dir/LogFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/LogFile.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogFile.cpp -o CMakeFiles/base.dir/LogFile.cpp.s

# Object files for target base
base_OBJECTS = \
"CMakeFiles/base.dir/FileUtil.cpp.o" \
"CMakeFiles/base.dir/LogFile.cpp.o"

# External object files for target base
base_EXTERNAL_OBJECTS =

src/base/libbase.a: src/base/CMakeFiles/base.dir/FileUtil.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/LogFile.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/build.make
src/base/libbase.a: src/base/CMakeFiles/base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libbase.a"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean_target.cmake
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/CMakeFiles/base.dir/build: src/base/libbase.a

.PHONY : src/base/CMakeFiles/base.dir/build

src/base/CMakeFiles/base.dir/clean:
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean.cmake
.PHONY : src/base/CMakeFiles/base.dir/clean

src/base/CMakeFiles/base.dir/depend:
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yaochuanwang/CLionProjects/SimpleWebServer /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base/CMakeFiles/base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/CMakeFiles/base.dir/depend

