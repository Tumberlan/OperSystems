# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Igor\ProgProjects\OperSystems\lab8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Igor\ProgProjects\OperSystems\lab8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab8.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab8.dir/flags.make

CMakeFiles/lab8.dir/main.c.obj: CMakeFiles/lab8.dir/flags.make
CMakeFiles/lab8.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Igor\ProgProjects\OperSystems\lab8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab8.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab8.dir\main.c.obj -c C:\Users\Igor\ProgProjects\OperSystems\lab8\main.c

CMakeFiles/lab8.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab8.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Igor\ProgProjects\OperSystems\lab8\main.c > CMakeFiles\lab8.dir\main.c.i

CMakeFiles/lab8.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab8.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Igor\ProgProjects\OperSystems\lab8\main.c -o CMakeFiles\lab8.dir\main.c.s

CMakeFiles/lab8.dir/1.c.obj: CMakeFiles/lab8.dir/flags.make
CMakeFiles/lab8.dir/1.c.obj: ../1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Igor\ProgProjects\OperSystems\lab8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab8.dir/1.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\lab8.dir\1.c.obj -c C:\Users\Igor\ProgProjects\OperSystems\lab8\1.c

CMakeFiles/lab8.dir/1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab8.dir/1.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Igor\ProgProjects\OperSystems\lab8\1.c > CMakeFiles\lab8.dir\1.c.i

CMakeFiles/lab8.dir/1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab8.dir/1.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Igor\ProgProjects\OperSystems\lab8\1.c -o CMakeFiles\lab8.dir\1.c.s

# Object files for target lab8
lab8_OBJECTS = \
"CMakeFiles/lab8.dir/main.c.obj" \
"CMakeFiles/lab8.dir/1.c.obj"

# External object files for target lab8
lab8_EXTERNAL_OBJECTS =

lab8.exe: CMakeFiles/lab8.dir/main.c.obj
lab8.exe: CMakeFiles/lab8.dir/1.c.obj
lab8.exe: CMakeFiles/lab8.dir/build.make
lab8.exe: CMakeFiles/lab8.dir/linklibs.rsp
lab8.exe: CMakeFiles/lab8.dir/objects1.rsp
lab8.exe: CMakeFiles/lab8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Igor\ProgProjects\OperSystems\lab8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable lab8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab8.dir/build: lab8.exe
.PHONY : CMakeFiles/lab8.dir/build

CMakeFiles/lab8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab8.dir/clean

CMakeFiles/lab8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Igor\ProgProjects\OperSystems\lab8 C:\Users\Igor\ProgProjects\OperSystems\lab8 C:\Users\Igor\ProgProjects\OperSystems\lab8\cmake-build-debug C:\Users\Igor\ProgProjects\OperSystems\lab8\cmake-build-debug C:\Users\Igor\ProgProjects\OperSystems\lab8\cmake-build-debug\CMakeFiles\lab8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab8.dir/depend

