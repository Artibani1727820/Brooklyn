# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/fra/geant4/workspace/brooklyn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fra/geant4/workspace/brooklyn/build

# Include any dependencies generated for this target.
include CMakeFiles/brook.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/brook.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/brook.dir/flags.make

CMakeFiles/brook.dir/brook.cc.o: CMakeFiles/brook.dir/flags.make
CMakeFiles/brook.dir/brook.cc.o: ../brook.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fra/geant4/workspace/brooklyn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/brook.dir/brook.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/brook.dir/brook.cc.o -c /home/fra/geant4/workspace/brooklyn/brook.cc

CMakeFiles/brook.dir/brook.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/brook.dir/brook.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fra/geant4/workspace/brooklyn/brook.cc > CMakeFiles/brook.dir/brook.cc.i

CMakeFiles/brook.dir/brook.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/brook.dir/brook.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fra/geant4/workspace/brooklyn/brook.cc -o CMakeFiles/brook.dir/brook.cc.s

# Object files for target brook
brook_OBJECTS = \
"CMakeFiles/brook.dir/brook.cc.o"

# External object files for target brook
brook_EXTERNAL_OBJECTS =

brook: CMakeFiles/brook.dir/brook.cc.o
brook: CMakeFiles/brook.dir/build.make
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4Tree.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4FR.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4GMocren.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4visHepRep.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4RayTracer.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4VRML.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4OpenGL.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4gl2ps.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4vis_management.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4modeling.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4interfaces.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4persistency.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4error_propagation.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4readout.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4physicslists.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4tasking.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4parmodels.so
brook: /usr/lib/x86_64-linux-gnu/libGL.so
brook: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
brook: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.12.8
brook: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
brook: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
brook: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
brook: /usr/lib/x86_64-linux-gnu/libXmu.so
brook: /usr/lib/x86_64-linux-gnu/libXext.so
brook: /usr/lib/x86_64-linux-gnu/libXt.so
brook: /usr/lib/x86_64-linux-gnu/libICE.so
brook: /usr/lib/x86_64-linux-gnu/libSM.so
brook: /usr/lib/x86_64-linux-gnu/libX11.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4run.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4event.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4tracking.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4processes.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4analysis.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4tools.so
brook: /usr/lib/x86_64-linux-gnu/libexpat.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4digits_hits.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4track.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4particles.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4geometry.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4materials.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4zlib.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4graphics_reps.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4intercoms.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4global.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4clhep.so
brook: /home/fra/geant4/install_path/geant4-v11.0.1-install/lib/libG4ptl.so.0.0.2
brook: CMakeFiles/brook.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fra/geant4/workspace/brooklyn/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable brook"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/brook.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/brook.dir/build: brook

.PHONY : CMakeFiles/brook.dir/build

CMakeFiles/brook.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/brook.dir/cmake_clean.cmake
.PHONY : CMakeFiles/brook.dir/clean

CMakeFiles/brook.dir/depend:
	cd /home/fra/geant4/workspace/brooklyn/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fra/geant4/workspace/brooklyn /home/fra/geant4/workspace/brooklyn /home/fra/geant4/workspace/brooklyn/build /home/fra/geant4/workspace/brooklyn/build /home/fra/geant4/workspace/brooklyn/build/CMakeFiles/brook.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/brook.dir/depend

