//
// Created by Alexandre Chaintreuil on 15/11/2017.
//

#include "VideoStreamer.h"

VideoStreamer::VideoStreamer(int height, int width, std::string addressVideoL, std::string addressVideoR)
        : height(height), width(width) {
    if(!videoL.open(addressVideoL)) {
        std::cout << "Error opening video stream or file for the left camera" << std::endl;
        exit;
    }
    if(!videoR.open(addressVideoR)) {
        std::cout << "Error opening video stream or file for the right camera" << std::endl;
        exit;
    }
}

cv::Mat VideoStreamer::grab()
{
    cv::Mat frame(height, 2 * width, CV_8UC1);

    if(!videoL.read(imageL)) {
        std::cout << "No frame Left" << std::endl;
    }
    if(!videoR.read(imageR)) {
        std::cout << "No frame Right" << std::endl;
    }

    cvtColor(imageL, imageL, cv::COLOR_RGB2GRAY);
    cvtColor(imageR, imageR, cv::COLOR_RGB2GRAY);

    imageL.copyTo(frame(cv::Rect(0, 0, width, height)));
    imageR.copyTo(frame(cv::Rect(width, 0, width, height)));

    return frame;
}

cv::Mat VideoStreamer::grabLeft() {
    cv::Mat frame(height, width, CV_8UC3);

    if (!videoL.read(imageL)) {
        std::cout << "No frame Left" << std::endl;
    }

    imageL.copyTo(frame(cv::Rect(0, 0, width, height)));

    return frame;
}

cv::Mat VideoStreamer::grabRight() {
    cv::Mat frame(height, width, CV_8UC3);

    if (!videoL.read(imageR)) {
        std::cout << "No frame Right" << std::endl;
    }

    imageR.copyTo(frame(cv::Rect(0, 0, width, height)));

    return frame;
}
