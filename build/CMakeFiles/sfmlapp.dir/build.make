# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/anna/Документы/kur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anna/Документы/kur/build

# Include any dependencies generated for this target.
include CMakeFiles/sfmlapp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sfmlapp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sfmlapp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfmlapp.dir/flags.make

CMakeFiles/sfmlapp.dir/main.cpp.o: CMakeFiles/sfmlapp.dir/flags.make
CMakeFiles/sfmlapp.dir/main.cpp.o: ../main.cpp
CMakeFiles/sfmlapp.dir/main.cpp.o: CMakeFiles/sfmlapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/Документы/kur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sfmlapp.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfmlapp.dir/main.cpp.o -MF CMakeFiles/sfmlapp.dir/main.cpp.o.d -o CMakeFiles/sfmlapp.dir/main.cpp.o -c /home/anna/Документы/kur/main.cpp

CMakeFiles/sfmlapp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfmlapp.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/Документы/kur/main.cpp > CMakeFiles/sfmlapp.dir/main.cpp.i

CMakeFiles/sfmlapp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfmlapp.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/Документы/kur/main.cpp -o CMakeFiles/sfmlapp.dir/main.cpp.s

CMakeFiles/sfmlapp.dir/GameMenu.cpp.o: CMakeFiles/sfmlapp.dir/flags.make
CMakeFiles/sfmlapp.dir/GameMenu.cpp.o: ../GameMenu.cpp
CMakeFiles/sfmlapp.dir/GameMenu.cpp.o: CMakeFiles/sfmlapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/Документы/kur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sfmlapp.dir/GameMenu.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfmlapp.dir/GameMenu.cpp.o -MF CMakeFiles/sfmlapp.dir/GameMenu.cpp.o.d -o CMakeFiles/sfmlapp.dir/GameMenu.cpp.o -c /home/anna/Документы/kur/GameMenu.cpp

CMakeFiles/sfmlapp.dir/GameMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfmlapp.dir/GameMenu.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/Документы/kur/GameMenu.cpp > CMakeFiles/sfmlapp.dir/GameMenu.cpp.i

CMakeFiles/sfmlapp.dir/GameMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfmlapp.dir/GameMenu.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/Документы/kur/GameMenu.cpp -o CMakeFiles/sfmlapp.dir/GameMenu.cpp.s

CMakeFiles/sfmlapp.dir/Players.cpp.o: CMakeFiles/sfmlapp.dir/flags.make
CMakeFiles/sfmlapp.dir/Players.cpp.o: ../Players.cpp
CMakeFiles/sfmlapp.dir/Players.cpp.o: CMakeFiles/sfmlapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/Документы/kur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sfmlapp.dir/Players.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfmlapp.dir/Players.cpp.o -MF CMakeFiles/sfmlapp.dir/Players.cpp.o.d -o CMakeFiles/sfmlapp.dir/Players.cpp.o -c /home/anna/Документы/kur/Players.cpp

CMakeFiles/sfmlapp.dir/Players.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfmlapp.dir/Players.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/Документы/kur/Players.cpp > CMakeFiles/sfmlapp.dir/Players.cpp.i

CMakeFiles/sfmlapp.dir/Players.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfmlapp.dir/Players.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/Документы/kur/Players.cpp -o CMakeFiles/sfmlapp.dir/Players.cpp.s

CMakeFiles/sfmlapp.dir/Engine.cpp.o: CMakeFiles/sfmlapp.dir/flags.make
CMakeFiles/sfmlapp.dir/Engine.cpp.o: ../Engine.cpp
CMakeFiles/sfmlapp.dir/Engine.cpp.o: CMakeFiles/sfmlapp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anna/Документы/kur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sfmlapp.dir/Engine.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sfmlapp.dir/Engine.cpp.o -MF CMakeFiles/sfmlapp.dir/Engine.cpp.o.d -o CMakeFiles/sfmlapp.dir/Engine.cpp.o -c /home/anna/Документы/kur/Engine.cpp

CMakeFiles/sfmlapp.dir/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfmlapp.dir/Engine.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anna/Документы/kur/Engine.cpp > CMakeFiles/sfmlapp.dir/Engine.cpp.i

CMakeFiles/sfmlapp.dir/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfmlapp.dir/Engine.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anna/Документы/kur/Engine.cpp -o CMakeFiles/sfmlapp.dir/Engine.cpp.s

# Object files for target sfmlapp
sfmlapp_OBJECTS = \
"CMakeFiles/sfmlapp.dir/main.cpp.o" \
"CMakeFiles/sfmlapp.dir/GameMenu.cpp.o" \
"CMakeFiles/sfmlapp.dir/Players.cpp.o" \
"CMakeFiles/sfmlapp.dir/Engine.cpp.o"

# External object files for target sfmlapp
sfmlapp_EXTERNAL_OBJECTS =

sfmlapp: CMakeFiles/sfmlapp.dir/main.cpp.o
sfmlapp: CMakeFiles/sfmlapp.dir/GameMenu.cpp.o
sfmlapp: CMakeFiles/sfmlapp.dir/Players.cpp.o
sfmlapp: CMakeFiles/sfmlapp.dir/Engine.cpp.o
sfmlapp: CMakeFiles/sfmlapp.dir/build.make
sfmlapp: CMakeFiles/sfmlapp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anna/Документы/kur/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable sfmlapp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfmlapp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfmlapp.dir/build: sfmlapp
.PHONY : CMakeFiles/sfmlapp.dir/build

CMakeFiles/sfmlapp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfmlapp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfmlapp.dir/clean

CMakeFiles/sfmlapp.dir/depend:
	cd /home/anna/Документы/kur/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anna/Документы/kur /home/anna/Документы/kur /home/anna/Документы/kur/build /home/anna/Документы/kur/build /home/anna/Документы/kur/build/CMakeFiles/sfmlapp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfmlapp.dir/depend
