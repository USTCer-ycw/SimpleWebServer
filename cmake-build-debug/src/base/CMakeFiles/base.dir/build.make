# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/yaochuanwang/CLionProjects/SimpleWebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug

# Include any dependencies generated for this target.
include src/base/CMakeFiles/base.dir/depend.make

# Include the progress variables for this target.
include src/base/CMakeFiles/base.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/CMakeFiles/base.dir/flags.make

src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o: ../src/base/CountDownLatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/CountDownLatch.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/CountDownLatch.cpp

src/base/CMakeFiles/base.dir/CountDownLatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/CountDownLatch.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/CountDownLatch.cpp > CMakeFiles/base.dir/CountDownLatch.cpp.i

src/base/CMakeFiles/base.dir/CountDownLatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/CountDownLatch.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/CountDownLatch.cpp -o CMakeFiles/base.dir/CountDownLatch.cpp.s

src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.requires

src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.provides: src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.provides

src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.provides.build: src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o


src/base/CMakeFiles/base.dir/FileUtil.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/FileUtil.cpp.o: ../src/base/FileUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/base/CMakeFiles/base.dir/FileUtil.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/FileUtil.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/FileUtil.cpp

src/base/CMakeFiles/base.dir/FileUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/FileUtil.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/FileUtil.cpp > CMakeFiles/base.dir/FileUtil.cpp.i

src/base/CMakeFiles/base.dir/FileUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/FileUtil.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/FileUtil.cpp -o CMakeFiles/base.dir/FileUtil.cpp.s

src/base/CMakeFiles/base.dir/FileUtil.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/FileUtil.cpp.o.requires

src/base/CMakeFiles/base.dir/FileUtil.cpp.o.provides: src/base/CMakeFiles/base.dir/FileUtil.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/FileUtil.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/FileUtil.cpp.o.provides

src/base/CMakeFiles/base.dir/FileUtil.cpp.o.provides.build: src/base/CMakeFiles/base.dir/FileUtil.cpp.o


src/base/CMakeFiles/base.dir/LogFile.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/LogFile.cpp.o: ../src/base/LogFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/base/CMakeFiles/base.dir/LogFile.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/LogFile.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogFile.cpp

src/base/CMakeFiles/base.dir/LogFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/LogFile.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogFile.cpp > CMakeFiles/base.dir/LogFile.cpp.i

src/base/CMakeFiles/base.dir/LogFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/LogFile.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogFile.cpp -o CMakeFiles/base.dir/LogFile.cpp.s

src/base/CMakeFiles/base.dir/LogFile.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/LogFile.cpp.o.requires

src/base/CMakeFiles/base.dir/LogFile.cpp.o.provides: src/base/CMakeFiles/base.dir/LogFile.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/LogFile.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/LogFile.cpp.o.provides

src/base/CMakeFiles/base.dir/LogFile.cpp.o.provides.build: src/base/CMakeFiles/base.dir/LogFile.cpp.o


src/base/CMakeFiles/base.dir/LogStream.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/LogStream.cpp.o: ../src/base/LogStream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/base/CMakeFiles/base.dir/LogStream.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/LogStream.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogStream.cpp

src/base/CMakeFiles/base.dir/LogStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/LogStream.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogStream.cpp > CMakeFiles/base.dir/LogStream.cpp.i

src/base/CMakeFiles/base.dir/LogStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/LogStream.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/LogStream.cpp -o CMakeFiles/base.dir/LogStream.cpp.s

src/base/CMakeFiles/base.dir/LogStream.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/LogStream.cpp.o.requires

src/base/CMakeFiles/base.dir/LogStream.cpp.o.provides: src/base/CMakeFiles/base.dir/LogStream.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/LogStream.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/LogStream.cpp.o.provides

src/base/CMakeFiles/base.dir/LogStream.cpp.o.provides.build: src/base/CMakeFiles/base.dir/LogStream.cpp.o


src/base/CMakeFiles/base.dir/Logging.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/Logging.cpp.o: ../src/base/Logging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/base/CMakeFiles/base.dir/Logging.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/Logging.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Logging.cpp

src/base/CMakeFiles/base.dir/Logging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/Logging.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Logging.cpp > CMakeFiles/base.dir/Logging.cpp.i

src/base/CMakeFiles/base.dir/Logging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/Logging.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Logging.cpp -o CMakeFiles/base.dir/Logging.cpp.s

src/base/CMakeFiles/base.dir/Logging.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/Logging.cpp.o.requires

src/base/CMakeFiles/base.dir/Logging.cpp.o.provides: src/base/CMakeFiles/base.dir/Logging.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/Logging.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/Logging.cpp.o.provides

src/base/CMakeFiles/base.dir/Logging.cpp.o.provides.build: src/base/CMakeFiles/base.dir/Logging.cpp.o


src/base/CMakeFiles/base.dir/TImerQueue.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/TImerQueue.cpp.o: ../src/base/TImerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/base/CMakeFiles/base.dir/TImerQueue.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/TImerQueue.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TImerQueue.cpp

src/base/CMakeFiles/base.dir/TImerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/TImerQueue.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TImerQueue.cpp > CMakeFiles/base.dir/TImerQueue.cpp.i

src/base/CMakeFiles/base.dir/TImerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/TImerQueue.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TImerQueue.cpp -o CMakeFiles/base.dir/TImerQueue.cpp.s

src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.requires

src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.provides: src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.provides

src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.provides.build: src/base/CMakeFiles/base.dir/TImerQueue.cpp.o


src/base/CMakeFiles/base.dir/Thread.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/Thread.cpp.o: ../src/base/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/base/CMakeFiles/base.dir/Thread.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/Thread.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Thread.cpp

src/base/CMakeFiles/base.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/Thread.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Thread.cpp > CMakeFiles/base.dir/Thread.cpp.i

src/base/CMakeFiles/base.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/Thread.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Thread.cpp -o CMakeFiles/base.dir/Thread.cpp.s

src/base/CMakeFiles/base.dir/Thread.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/Thread.cpp.o.requires

src/base/CMakeFiles/base.dir/Thread.cpp.o.provides: src/base/CMakeFiles/base.dir/Thread.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/Thread.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/Thread.cpp.o.provides

src/base/CMakeFiles/base.dir/Thread.cpp.o.provides.build: src/base/CMakeFiles/base.dir/Thread.cpp.o


src/base/CMakeFiles/base.dir/Timer.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/Timer.cpp.o: ../src/base/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/base/CMakeFiles/base.dir/Timer.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/Timer.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Timer.cpp

src/base/CMakeFiles/base.dir/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/Timer.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Timer.cpp > CMakeFiles/base.dir/Timer.cpp.i

src/base/CMakeFiles/base.dir/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/Timer.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/Timer.cpp -o CMakeFiles/base.dir/Timer.cpp.s

src/base/CMakeFiles/base.dir/Timer.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/Timer.cpp.o.requires

src/base/CMakeFiles/base.dir/Timer.cpp.o.provides: src/base/CMakeFiles/base.dir/Timer.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/Timer.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/Timer.cpp.o.provides

src/base/CMakeFiles/base.dir/Timer.cpp.o.provides.build: src/base/CMakeFiles/base.dir/Timer.cpp.o


src/base/CMakeFiles/base.dir/TimerId.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/TimerId.cpp.o: ../src/base/TimerId.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/base/CMakeFiles/base.dir/TimerId.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/TimerId.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TimerId.cpp

src/base/CMakeFiles/base.dir/TimerId.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/TimerId.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TimerId.cpp > CMakeFiles/base.dir/TimerId.cpp.i

src/base/CMakeFiles/base.dir/TimerId.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/TimerId.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TimerId.cpp -o CMakeFiles/base.dir/TimerId.cpp.s

src/base/CMakeFiles/base.dir/TimerId.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/TimerId.cpp.o.requires

src/base/CMakeFiles/base.dir/TimerId.cpp.o.provides: src/base/CMakeFiles/base.dir/TimerId.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/TimerId.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/TimerId.cpp.o.provides

src/base/CMakeFiles/base.dir/TimerId.cpp.o.provides.build: src/base/CMakeFiles/base.dir/TimerId.cpp.o


src/base/CMakeFiles/base.dir/TimerQueue.cpp.o: src/base/CMakeFiles/base.dir/flags.make
src/base/CMakeFiles/base.dir/TimerQueue.cpp.o: ../src/base/TimerQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/base/CMakeFiles/base.dir/TimerQueue.cpp.o"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/TimerQueue.cpp.o -c /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TimerQueue.cpp

src/base/CMakeFiles/base.dir/TimerQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/TimerQueue.cpp.i"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TimerQueue.cpp > CMakeFiles/base.dir/TimerQueue.cpp.i

src/base/CMakeFiles/base.dir/TimerQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/TimerQueue.cpp.s"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base/TimerQueue.cpp -o CMakeFiles/base.dir/TimerQueue.cpp.s

src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.requires:

.PHONY : src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.requires

src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.provides: src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.requires
	$(MAKE) -f src/base/CMakeFiles/base.dir/build.make src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.provides.build
.PHONY : src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.provides

src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.provides.build: src/base/CMakeFiles/base.dir/TimerQueue.cpp.o


# Object files for target base
base_OBJECTS = \
"CMakeFiles/base.dir/CountDownLatch.cpp.o" \
"CMakeFiles/base.dir/FileUtil.cpp.o" \
"CMakeFiles/base.dir/LogFile.cpp.o" \
"CMakeFiles/base.dir/LogStream.cpp.o" \
"CMakeFiles/base.dir/Logging.cpp.o" \
"CMakeFiles/base.dir/TImerQueue.cpp.o" \
"CMakeFiles/base.dir/Thread.cpp.o" \
"CMakeFiles/base.dir/Timer.cpp.o" \
"CMakeFiles/base.dir/TimerId.cpp.o" \
"CMakeFiles/base.dir/TimerQueue.cpp.o"

# External object files for target base
base_EXTERNAL_OBJECTS =

src/base/libbase.a: src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/FileUtil.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/LogFile.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/LogStream.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/Logging.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/TImerQueue.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/Thread.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/Timer.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/TimerId.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/TimerQueue.cpp.o
src/base/libbase.a: src/base/CMakeFiles/base.dir/build.make
src/base/libbase.a: src/base/CMakeFiles/base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX static library libbase.a"
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean_target.cmake
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/CMakeFiles/base.dir/build: src/base/libbase.a

.PHONY : src/base/CMakeFiles/base.dir/build

src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/CountDownLatch.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/FileUtil.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/LogFile.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/LogStream.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/Logging.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/TImerQueue.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/Thread.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/Timer.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/TimerId.cpp.o.requires
src/base/CMakeFiles/base.dir/requires: src/base/CMakeFiles/base.dir/TimerQueue.cpp.o.requires

.PHONY : src/base/CMakeFiles/base.dir/requires

src/base/CMakeFiles/base.dir/clean:
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean.cmake
.PHONY : src/base/CMakeFiles/base.dir/clean

src/base/CMakeFiles/base.dir/depend:
	cd /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yaochuanwang/CLionProjects/SimpleWebServer /home/yaochuanwang/CLionProjects/SimpleWebServer/src/base /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base /home/yaochuanwang/CLionProjects/SimpleWebServer/cmake-build-debug/src/base/CMakeFiles/base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/CMakeFiles/base.dir/depend

