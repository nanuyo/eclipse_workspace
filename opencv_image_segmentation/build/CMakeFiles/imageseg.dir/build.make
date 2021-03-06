# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/hjpark/hjworkspace/opencv_image_segmentation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hjpark/hjworkspace/opencv_image_segmentation/build

# Include any dependencies generated for this target.
include CMakeFiles/imageseg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/imageseg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/imageseg.dir/flags.make

CMakeFiles/imageseg.dir/imageSegmentation.cpp.o: CMakeFiles/imageseg.dir/flags.make
CMakeFiles/imageseg.dir/imageSegmentation.cpp.o: ../imageSegmentation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hjpark/hjworkspace/opencv_image_segmentation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/imageseg.dir/imageSegmentation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/imageseg.dir/imageSegmentation.cpp.o -c /home/hjpark/hjworkspace/opencv_image_segmentation/imageSegmentation.cpp

CMakeFiles/imageseg.dir/imageSegmentation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imageseg.dir/imageSegmentation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hjpark/hjworkspace/opencv_image_segmentation/imageSegmentation.cpp > CMakeFiles/imageseg.dir/imageSegmentation.cpp.i

CMakeFiles/imageseg.dir/imageSegmentation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imageseg.dir/imageSegmentation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hjpark/hjworkspace/opencv_image_segmentation/imageSegmentation.cpp -o CMakeFiles/imageseg.dir/imageSegmentation.cpp.s

CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.requires:

.PHONY : CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.requires

CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.provides: CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.requires
	$(MAKE) -f CMakeFiles/imageseg.dir/build.make CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.provides.build
.PHONY : CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.provides

CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.provides.build: CMakeFiles/imageseg.dir/imageSegmentation.cpp.o


# Object files for target imageseg
imageseg_OBJECTS = \
"CMakeFiles/imageseg.dir/imageSegmentation.cpp.o"

# External object files for target imageseg
imageseg_EXTERNAL_OBJECTS =

imageseg: CMakeFiles/imageseg.dir/imageSegmentation.cpp.o
imageseg: CMakeFiles/imageseg.dir/build.make
imageseg: /usr/local/lib/libopencv_dnn.so.3.3.0
imageseg: /usr/local/lib/libopencv_ml.so.3.3.0
imageseg: /usr/local/lib/libopencv_objdetect.so.3.3.0
imageseg: /usr/local/lib/libopencv_shape.so.3.3.0
imageseg: /usr/local/lib/libopencv_stitching.so.3.3.0
imageseg: /usr/local/lib/libopencv_superres.so.3.3.0
imageseg: /usr/local/lib/libopencv_videostab.so.3.3.0
imageseg: /usr/local/lib/libopencv_viz.so.3.3.0
imageseg: /usr/local/lib/libopencv_calib3d.so.3.3.0
imageseg: /usr/local/lib/libopencv_features2d.so.3.3.0
imageseg: /usr/local/lib/libopencv_flann.so.3.3.0
imageseg: /usr/local/lib/libopencv_highgui.so.3.3.0
imageseg: /usr/local/lib/libopencv_photo.so.3.3.0
imageseg: /usr/local/lib/libopencv_video.so.3.3.0
imageseg: /usr/local/lib/libopencv_videoio.so.3.3.0
imageseg: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
imageseg: /usr/local/lib/libopencv_imgproc.so.3.3.0
imageseg: /usr/local/lib/libopencv_core.so.3.3.0
imageseg: CMakeFiles/imageseg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hjpark/hjworkspace/opencv_image_segmentation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable imageseg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imageseg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/imageseg.dir/build: imageseg

.PHONY : CMakeFiles/imageseg.dir/build

CMakeFiles/imageseg.dir/requires: CMakeFiles/imageseg.dir/imageSegmentation.cpp.o.requires

.PHONY : CMakeFiles/imageseg.dir/requires

CMakeFiles/imageseg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/imageseg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/imageseg.dir/clean

CMakeFiles/imageseg.dir/depend:
	cd /home/hjpark/hjworkspace/opencv_image_segmentation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hjpark/hjworkspace/opencv_image_segmentation /home/hjpark/hjworkspace/opencv_image_segmentation /home/hjpark/hjworkspace/opencv_image_segmentation/build /home/hjpark/hjworkspace/opencv_image_segmentation/build /home/hjpark/hjworkspace/opencv_image_segmentation/build/CMakeFiles/imageseg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/imageseg.dir/depend

