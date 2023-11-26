#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;

int read_display_convert()
{
    std::string image_path = samples::findFile("C:\\repos\\GrowingGas\\GrowingGas\\data\\pattern2.bmp");
    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if (k == 's')
    {
        imwrite("converted.png", img);
    }
    return 0;
}