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

#Screenshots

![WhatsApp Image 2025-05-24 at 10 01 14_3d649744](https://github.com/user-attachments/assets/4555cb94-f837-4267-988c-af0c1f2d6374)

![WhatsApp Image 2025-05-24 at 10 01 14_18eaf542](https://github.com/user-attachments/assets/ade73fb2-87dd-4a51-8323-0191ef491832)

![WhatsApp Image 2025-05-24 at 10 01 14_8f3d876c](https://github.com/user-attachments/assets/4f995ff9-628f-4eed-8104-14cf20f22300)

![WhatsApp Image 2025-05-24 at 10 01 15_bac0ea51](https://github.com/user-attachments/assets/2d9fdfd6-dd91-45d2-a1d2-fee7b9a99cf9)

![WhatsApp Image 2025-05-24 at 10 01 15_9d3caf5e](https://github.com/user-attachments/assets/c9a39991-fa00-461b-8519-aed706e10bf7)







