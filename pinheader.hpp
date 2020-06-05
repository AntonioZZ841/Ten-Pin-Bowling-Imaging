#include <opencv2/opencv.hpp>
#define THRESHOLD 160

bool isWhite(cv::Mat& image, int row, int col)
{
    int red = 0;
    for (int i = 0; i < 5; ++i)                          //This loops through 5 rows
    {
        cv::Vec3b *p = image.ptr<cv::Vec3b>(i + row);    //sets a pointer to a specific row
        for (int j = 0; j < 5; ++j)                      //This loops through 5 columns
        {
            red += p[j+col][2];                          //searches for the red component of BGR pic
        }
    }
    if (red / 25 < THRESHOLD)                            //if the average is oven the threshold trturn true
        return false;
    else 
        return true;
}

void inline printStatus(const bool* pin_i)
{
    //creats an output file
    std::ofstream out("out.txt", std::ios::out|std::ios::trunc);
    for (int i = 0; i < 10; ++i)
    {
        if(pin_i[i])
            std::cout << "Pin " << i + 1 << " is standing. "<< std::endl;
        else 
            std::cout << "Pin "<< i + 1 << " is not standing. "<< std::endl;
        //this puts into the file an 1 if the pin is standing and a 0 if it has fallen
        out << pin_i[i];
    }
    out.close();
    std::cout << std::endl;
}
