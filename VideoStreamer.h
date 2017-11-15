//
// Created by Alexandre Chaintreuil on 15/11/2017.
//

#ifndef DISPLAYIMAGE_VIDEOSTREAMER_H
#define DISPLAYIMAGE_VIDEOSTREAMER_H


#include <opencv2/opencv.hpp>

class VideoStreamer
{
private:
    cv::VideoCapture videoL, videoR;
    cv::Mat imageL, imageR;
    int height, width;
public:
    VideoStreamer(int height, int width, std::string addressVideoL, std::string addressVideoR);
    cv::Mat grab();
};



#endif //DISPLAYIMAGE_VIDEOSTREAMER_H
