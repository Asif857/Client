# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /users/studs/bsc/2022/rolantas/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6461.75/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /users/studs/bsc/2022/rolantas/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/213.6461.75/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SPL3new.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SPL3new.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SPL3new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPL3new.dir/flags.make

CMakeFiles/SPL3new.dir/main.cpp.o: CMakeFiles/SPL3new.dir/flags.make
CMakeFiles/SPL3new.dir/main.cpp.o: ../main.cpp
CMakeFiles/SPL3new.dir/main.cpp.o: CMakeFiles/SPL3new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPL3new.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SPL3new.dir/main.cpp.o -MF CMakeFiles/SPL3new.dir/main.cpp.o.d -o CMakeFiles/SPL3new.dir/main.cpp.o -c /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/main.cpp

CMakeFiles/SPL3new.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3new.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/main.cpp > CMakeFiles/SPL3new.dir/main.cpp.i

CMakeFiles/SPL3new.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3new.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/main.cpp -o CMakeFiles/SPL3new.dir/main.cpp.s

CMakeFiles/SPL3new.dir/src/Task.cpp.o: CMakeFiles/SPL3new.dir/flags.make
CMakeFiles/SPL3new.dir/src/Task.cpp.o: ../src/Task.cpp
CMakeFiles/SPL3new.dir/src/Task.cpp.o: CMakeFiles/SPL3new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SPL3new.dir/src/Task.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SPL3new.dir/src/Task.cpp.o -MF CMakeFiles/SPL3new.dir/src/Task.cpp.o.d -o CMakeFiles/SPL3new.dir/src/Task.cpp.o -c /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/Task.cpp

CMakeFiles/SPL3new.dir/src/Task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3new.dir/src/Task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/Task.cpp > CMakeFiles/SPL3new.dir/src/Task.cpp.i

CMakeFiles/SPL3new.dir/src/Task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3new.dir/src/Task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/Task.cpp -o CMakeFiles/SPL3new.dir/src/Task.cpp.s

CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o: CMakeFiles/SPL3new.dir/flags.make
CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o: ../src/encoderDecoder.cpp
CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o: CMakeFiles/SPL3new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o -MF CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o.d -o CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o -c /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/encoderDecoder.cpp

CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/encoderDecoder.cpp > CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.i

CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/encoderDecoder.cpp -o CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.s

CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o: CMakeFiles/SPL3new.dir/flags.make
CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o: ../src/bidiProtocol.cpp
CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o: CMakeFiles/SPL3new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o -MF CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o.d -o CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o -c /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/bidiProtocol.cpp

CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/bidiProtocol.cpp > CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.i

CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/bidiProtocol.cpp -o CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.s

CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o: CMakeFiles/SPL3new.dir/flags.make
CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o: ../src/bidiClient.cpp
CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o: CMakeFiles/SPL3new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o -MF CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o.d -o CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o -c /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/bidiClient.cpp

CMakeFiles/SPL3new.dir/src/bidiClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3new.dir/src/bidiClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/bidiClient.cpp > CMakeFiles/SPL3new.dir/src/bidiClient.cpp.i

CMakeFiles/SPL3new.dir/src/bidiClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3new.dir/src/bidiClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/bidiClient.cpp -o CMakeFiles/SPL3new.dir/src/bidiClient.cpp.s

CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o: CMakeFiles/SPL3new.dir/flags.make
CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o: ../src/connectionHandler.cpp
CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o: CMakeFiles/SPL3new.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o -MF CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o.d -o CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o -c /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/connectionHandler.cpp

CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/connectionHandler.cpp > CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.i

CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/src/connectionHandler.cpp -o CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.s

# Object files for target SPL3new
SPL3new_OBJECTS = \
"CMakeFiles/SPL3new.dir/main.cpp.o" \
"CMakeFiles/SPL3new.dir/src/Task.cpp.o" \
"CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o" \
"CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o" \
"CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o" \
"CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o"

# External object files for target SPL3new
SPL3new_EXTERNAL_OBJECTS =

SPL3new: CMakeFiles/SPL3new.dir/main.cpp.o
SPL3new: CMakeFiles/SPL3new.dir/src/Task.cpp.o
SPL3new: CMakeFiles/SPL3new.dir/src/encoderDecoder.cpp.o
SPL3new: CMakeFiles/SPL3new.dir/src/bidiProtocol.cpp.o
SPL3new: CMakeFiles/SPL3new.dir/src/bidiClient.cpp.o
SPL3new: CMakeFiles/SPL3new.dir/src/connectionHandler.cpp.o
SPL3new: CMakeFiles/SPL3new.dir/build.make
SPL3new: CMakeFiles/SPL3new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SPL3new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SPL3new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPL3new.dir/build: SPL3new
.PHONY : CMakeFiles/SPL3new.dir/build

CMakeFiles/SPL3new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SPL3new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SPL3new.dir/clean

CMakeFiles/SPL3new.dir/depend:
	cd /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug /users/studs/bsc/2022/rolantas/CLionProjects/SPL3new/cmake-build-debug/CMakeFiles/SPL3new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPL3new.dir/depend

