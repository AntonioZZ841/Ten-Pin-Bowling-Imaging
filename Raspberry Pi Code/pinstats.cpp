#include "pinheader.hpp"
#include <unistd.h>
#define THRESHOLD 160                               // minimum pixel intensity to be classified as white

int main()
{
    while(true)
    {
        cv::Mat im;
        cv::VideoCapture cap(0);
        cap >> im;                                      // the picture will be saved in a matrix called im
    //    im = cv::imread("sample.png");                    //debug
     
           if (im.empty())                              // this checks if picture is taken properly
        {
            std::cerr << "Cannot open image" << std::endl;
            return -1;
        }

        bool pin_i[10] = {0};                         // this array saves the pin status
        
            pin_i[0] = isWhite(im, 131, 306);                   // this function has inputs image, row and col of top left pixel
            pin_i[1] = isWhite(im, 183, 262);
            pin_i[2] = isWhite(im, 192, 340);
            pin_i[3] = isWhite(im, 246, 208);
            pin_i[4] = isWhite(im, 261, 292);
            pin_i[5] = isWhite(im, 272, 377);
            pin_i[6] = isWhite(im, 308, 137);
            pin_i[7] = isWhite(im, 324, 234);
            pin_i[8] = isWhite(im, 347, 326);
            pin_i[9] = isWhite(im, 359, 421);
        printStatus(pin_i);
	system("python3 SendReceive.py");
        sleep(10);                                   //pauses for 5 secs
    }
    return 0;
}
