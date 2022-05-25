# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/drago/Tetris_APS_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/drago/Tetris_APS_Project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/drago/Tetris_APS_Project/CMakeFiles /home/drago/Tetris_APS_Project//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/drago/Tetris_APS_Project/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named tetris

# Build rule for target.
tetris: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 tetris
.PHONY : tetris

# fast build rule for target.
tetris/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/build
.PHONY : tetris/fast

Source/GetTetromino.o: Source/GetTetromino.cpp.o
.PHONY : Source/GetTetromino.o

# target to build an object file
Source/GetTetromino.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/GetTetromino.cpp.o
.PHONY : Source/GetTetromino.cpp.o

Source/GetTetromino.i: Source/GetTetromino.cpp.i
.PHONY : Source/GetTetromino.i

# target to preprocess a source file
Source/GetTetromino.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/GetTetromino.cpp.i
.PHONY : Source/GetTetromino.cpp.i

Source/GetTetromino.s: Source/GetTetromino.cpp.s
.PHONY : Source/GetTetromino.s

# target to generate assembly for a file
Source/GetTetromino.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/GetTetromino.cpp.s
.PHONY : Source/GetTetromino.cpp.s

Source/GetWallKickData.o: Source/GetWallKickData.cpp.o
.PHONY : Source/GetWallKickData.o

# target to build an object file
Source/GetWallKickData.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/GetWallKickData.cpp.o
.PHONY : Source/GetWallKickData.cpp.o

Source/GetWallKickData.i: Source/GetWallKickData.cpp.i
.PHONY : Source/GetWallKickData.i

# target to preprocess a source file
Source/GetWallKickData.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/GetWallKickData.cpp.i
.PHONY : Source/GetWallKickData.cpp.i

Source/GetWallKickData.s: Source/GetWallKickData.cpp.s
.PHONY : Source/GetWallKickData.s

# target to generate assembly for a file
Source/GetWallKickData.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/GetWallKickData.cpp.s
.PHONY : Source/GetWallKickData.cpp.s

Source/Main.o: Source/Main.cpp.o
.PHONY : Source/Main.o

# target to build an object file
Source/Main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/Main.cpp.o
.PHONY : Source/Main.cpp.o

Source/Main.i: Source/Main.cpp.i
.PHONY : Source/Main.i

# target to preprocess a source file
Source/Main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/Main.cpp.i
.PHONY : Source/Main.cpp.i

Source/Main.s: Source/Main.cpp.s
.PHONY : Source/Main.s

# target to generate assembly for a file
Source/Main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/Main.cpp.s
.PHONY : Source/Main.cpp.s

Source/Tetromino.o: Source/Tetromino.cpp.o
.PHONY : Source/Tetromino.o

# target to build an object file
Source/Tetromino.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/Tetromino.cpp.o
.PHONY : Source/Tetromino.cpp.o

Source/Tetromino.i: Source/Tetromino.cpp.i
.PHONY : Source/Tetromino.i

# target to preprocess a source file
Source/Tetromino.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/Tetromino.cpp.i
.PHONY : Source/Tetromino.cpp.i

Source/Tetromino.s: Source/Tetromino.cpp.s
.PHONY : Source/Tetromino.s

# target to generate assembly for a file
Source/Tetromino.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/tetris.dir/build.make CMakeFiles/tetris.dir/Source/Tetromino.cpp.s
.PHONY : Source/Tetromino.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... tetris"
	@echo "... Source/GetTetromino.o"
	@echo "... Source/GetTetromino.i"
	@echo "... Source/GetTetromino.s"
	@echo "... Source/GetWallKickData.o"
	@echo "... Source/GetWallKickData.i"
	@echo "... Source/GetWallKickData.s"
	@echo "... Source/Main.o"
	@echo "... Source/Main.i"
	@echo "... Source/Main.s"
	@echo "... Source/Tetromino.o"
	@echo "... Source/Tetromino.i"
	@echo "... Source/Tetromino.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

