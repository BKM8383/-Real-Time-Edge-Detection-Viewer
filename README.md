The code takes a video stream from the camera, processes it with OpenCV (C++),
and displays the result on the screen. There are 5 example OpenCV algorithms you can switch on the fly:

1. Photo negative of the central 1/9  
2. Canny Edges  
3. Thresholding and contour detection  
4. ORB keypoints visualized  
5. Lucas-Kanade sparse optical flow  

Installation 

First, you'll need Android Studio with Android SDK, of course. 

Second, you'll have to open the "SDK Manager" and install the latest "NDK (Side by Side)" and CMake, in order to get C++ for Android. 

Third, go to the OpenCV website and download OpenCV for Android. I used version 4.9, file `opencv-4.9.0-android-sdk.zip`.
Unzip it somewhere on your computer. 

Finally, open the file `CMakeLists.txt` and **modify** it (change `OPENCV_DIR`) to hardcode the path to where you unzipped OpenCV on your computer.