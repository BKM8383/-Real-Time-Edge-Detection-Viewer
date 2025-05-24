
#include <jni.h>
#include <android/log.h>
#include <android/bitmap.h>

#include <opencv2/imgproc.hpp>

#include "ImageProcessor.h"

const char * TAG = "BRIANNA";

extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidopencvdemo_ImageProcessorWrapper_ctorCPP(JNIEnv *env, jobject thisObj) {
    ImageProcessor * pImageProcessor = new ImageProcessor();
    jclass thisClass = env->GetObjectClass(thisObj);
    jfieldID fieldHandle = env->GetFieldID(thisClass, "handle", "J");  // "J" means long !
    env->SetLongField(thisObj, fieldHandle, (jlong)pImageProcessor);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidopencvdemo_ImageProcessorWrapper_close(JNIEnv *env, jobject thisObj) {
    jclass thisClass = env->GetObjectClass(thisObj);
    jfieldID fieldHandle = env->GetFieldID(thisClass, "handle", "J");  // "J" means long !
    jlong handle = env->GetLongField(thisObj, fieldHandle);
    ImageProcessor * pImageProcessor = (ImageProcessor *)handle;
    if (pImageProcessor != nullptr)
        delete pImageProcessor;
    env->SetLongField(thisObj, fieldHandle, jlong(0));
}

void bitmap2mat(JNIEnv *env, jobject bm, cv::Mat &img) {
    using namespace std;
    using namespace cv;
    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, bm, &info);
    int imW = info.width, imH = info.height;
    void *p;
    if (AndroidBitmap_lockPixels(env, bm, &p)) {
        __android_log_print(ANDROID_LOG_ERROR, TAG, "bitmap2mat: AndroidBitmap_lockPixels failure !");
        return;
    }

    Mat imgOrig(imH, imW, CV_8UC4, p);
    cvtColor(imgOrig, img, COLOR_RGBA2BGR);
    AndroidBitmap_unlockPixels(env, bm);
}

void mat2bitmap(JNIEnv *env, cv::Mat &img, jobject bm) {
    using namespace std;
    using namespace cv;

    AndroidBitmapInfo info;
    AndroidBitmap_getInfo(env, bm, &info);
    int imW = info.width, imH = info.height;
    void *p;
    if (AndroidBitmap_lockPixels(env, bm, &p)) {
        __android_log_print(ANDROID_LOG_ERROR, TAG, "mat2bitmap: AndroidBitmap_lockPixels failure !");
        return;
    }

    if (imW != img.cols || imH != img.rows) {
        __android_log_print(ANDROID_LOG_ERROR, TAG, "mat2bitmap: size mismatch !");
        return;
    }

    Mat imgBM(imH, imW, CV_8UC4, p);

    cvtColor(img, imgBM, COLOR_BGR2RGBA);

    AndroidBitmap_unlockPixels(env, bm);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidopencvdemo_ImageProcessorWrapper_process(JNIEnv *env, jobject thisObj,
                                                                 jint rotation, jobject bmIn,
                                                                 jobject bmOut) {
    // Get pointer pImageProcessor from handle
    jclass thisClass = env->GetObjectClass(thisObj);
    jfieldID fieldHandle = env->GetFieldID(thisClass, "handle", "J");  // "J" means long !
    jlong handle = env->GetLongField(thisObj, fieldHandle);
    ImageProcessor * pImageProcessor = (ImageProcessor *)handle;

    // Convert bitmap to cv::Mat
    bitmap2mat(env, bmIn, pImageProcessor->frameIn);

    // Process it with opencv
    pImageProcessor->process(rotation);

    // Convert back to bitmap
    mat2bitmap(env, pImageProcessor->frameOut, bmOut);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidopencvdemo_ImageProcessorWrapper_setMode(JNIEnv *env, jobject thisObj,
                                                                 jint mode) {
    // Get pointer pImageProcessor from handle
    jclass thisClass = env->GetObjectClass(thisObj);
    jfieldID fieldHandle = env->GetFieldID(thisClass, "handle", "J");  // "J" means long !
    jlong handle = env->GetLongField(thisObj, fieldHandle);
    ImageProcessor * pImageProcessor = (ImageProcessor *)handle;

    pImageProcessor->setMode(mode);
}