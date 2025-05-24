cmake_minimum_required(VERSION 3.22.1)
project("androidopencvdemo")
set(CMAKE_CXX_STANDARD 17)
set(OPENCV_DIR C:/Users/kumaw/Downloads/opencv-4.11.0-android-sdk/OpenCV-android-sdk/sdk/native)
include_directories(${OPENCV_DIR}/jni/include)
set(OpenCV_LIBS_DIR1 ${OPENCV_DIR}/staticlibs/${ANDROID_ABI}/)
file(GLOB OpenCV_LIBS1 "${OpenCV_LIBS_DIR1}/*.a")
set(OpenCV_LIBS_DIR2 ${OPENCV_DIR}/3rdparty/libs/${ANDROID_ABI}/)
file(GLOB OpenCV_LIBS2 "${OpenCV_LIBS_DIR2}/*.a")
set(OpenCV_LIBS ${OpenCV_LIBS1} ${OpenCV_LIBS2} z)
message("OpenCV_LIBS=${OpenCV_LIBS}")
add_library(${CMAKE_PROJECT_NAME} SHARED
        androidopencvdemo.cpp
        ImageProcessor.cpp ImageProcessor.h
        #
        mills/Mill.h
        mills/MillCanny.h
        mills/MillNeg.cpp mills/MillNeg.h
        mills/MillOFLK.cpp mills/MillOFLK.h
        mills/MillORB.cpp mills/MillORB.h
        mills/MillContour.cpp mills/MillContour.h
        mills/MillEngine.cpp mills/MillEngine.h
        )
target_link_libraries(${CMAKE_PROJECT_NAME} android log jnigraphics ${OpenCV_LIBS})