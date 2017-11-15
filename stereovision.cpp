#include <opencv2/opencv.hpp>

#include <iostream>
#include "VideoStreamer.h"

using namespace cv;

void displayStereoImage(VideoStreamer videoStreamer)
{
    cv::Mat displayImage;
    cv::Size size(720, 240);

    for(;;) {
        cv::resize(videoStreamer.grab(), displayImage, size);

        cv::imshow("Stereo Vision", displayImage);
        if(cv::waitKey(1) >= 0) break;
    }
}

void saveLeftAndRightImages(VideoStreamer videoStreamer)
{
    int c;
    std::cout << "Press 'c' to capture a new image and 'q' to quit" << std::endl;
    for (;;) {
        c = getchar();
        if (c == 'c') {
            cv::Mat left = videoStreamer.grabLeft();
            cv::Mat right = videoStreamer.grabRight();

            std::time_t t = std::time(0);

            cv::imwrite("images/left" + std::to_string(t) + ".png", left);
            cv::imwrite("images/right" + std::to_string(t) + ".png", right);
        } else if (c == 'q') {
            break;
        }
    }
}

int main(int argc, char** argv)
{
    VideoStreamer videoStreamer = VideoStreamer(
            480,
            720,
            "http://192.168.0.100:8081/",
            "http://192.168.0.101:8081/"
    );

    // displayStereoImage(videoStreamer);
    saveLeftAndRightImages(videoStreamer);
}
