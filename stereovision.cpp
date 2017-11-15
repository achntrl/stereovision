#include <opencv2/opencv.hpp>

#include <iostream>
#include "VideoStreamer.h"

using namespace cv;

int main(int argc, char** argv)
{
    VideoStreamer videoStream = VideoStreamer(
            480,
            720,
            "http://192.168.0.100:8081/",
            "http://192.168.0.101:8081/"
    );

    for(;;) {
        cv::Mat displayImage;
        cv::Size size(720, 240);
        cv::resize(videoStream.grab(), displayImage, size);

        cv::imshow("Stereo Vision", displayImage);
        if(cv::waitKey(1) >= 0) break;
    }
}
