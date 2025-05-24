#ifndef ANDROIDOPENCVDEMO_IMAGEPROCESSOR_H
#define ANDROIDOPENCVDEMO_IMAGEPROCESSOR_H


#include <opencv2/core.hpp>

#include "mills/MillEngine.h"

struct ImageProcessor {
    cv::Mat frameIn, frameOut, frameRot;
    mills::MillEngine engine;
    void process(int rotation);
    void setMode(int mode) {
        engine.setMode(mode);
    }
};


#endif