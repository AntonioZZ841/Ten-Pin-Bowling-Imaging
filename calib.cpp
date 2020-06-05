#include "pinheader.hpp" 

int main ()
{
    // matrix of the image/frames
    cv::Mat im;                                                 
    cv::VideoCapture cap(0);
    if(!cap.isOpened())
    {
        std::cerr << "Cannot open camera" << std::endl;
        return -1;
    }

    while(true)                                             // this is an infinite loop
    {
        cap >> im;                                          // this puts the frame into im (open CV syntax)
        bool pin_i[10] = {0};                               // this vector saves the pin status
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
        //imshow("Pic",im);

        bool check = 1;                                     // this sets check to true
        for( bool pin : pin_i)                              // this loops through the vector
        {
            check = check && pin;                           // if one pin is not true, the loop will continue but check
        }                                                   // will be false when we exit the loop
        if (check)
        {
            std::cout << "All pin positions are set" << std::endl;  //this can change as later an electronic output might be expected
            break;                                          // this will exit program if all pins are white
        }
    }
    return 0;
}

