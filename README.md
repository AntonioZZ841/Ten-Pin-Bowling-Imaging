# Ten-Pin-Bowling-Imaging
This project aims to provide binary tools for detection of bowling pins after a roll.  
The Core codes are realised based on **OpenCV 4.3.0** and **C++**.  
The executives can be built via **CMake** and **make** by the following commands:

First, create a sub-directory "release" inside the root directory of the project and change to it:  
`% mkdir release && cd relase`

Then, configure and generate the necessary files for building and build:
```
% cmake ..             #generate files to the current directory while reading input files from the upper directory
% make  -j$(nproc)     #build the executives with all the processor threads working in parallel.
```  
By this way, two binary executives, **calib** and **pinstats** are then generated. **calib** calibrates the camera, and quits when the ten pixel blocks that will be analysed are lying inside heads of the pins. **pinstats** analyses the status of the pins, whether standing of fallen, every 10s, and outputs the results as 10 binary numbers in a line to **out.txt**. The python file **SendReceive.py** sends the information in **out.txt** to an arduino that lies in the same frequency and channels as the Raspberry Pi 4B via the functions described in **lib_nrf24.py**.  

This repository includes an example of the project after building. If the programmes are not working as expected, you may delete the whole **release** directory, edit **CMakeLists.txt**, and rebuild the project yourself. Normally the two binary programs are expected to run without **OpenCV** framework as they were built with a static library so that they do not have any runtime dependancies.  
  
The Arduino code, **Receive.ino** depends on **SPI** and **RF24** libraries. Please ensure that you have them pre-installed in the arduino IDE prior to compiling. It receives the binary array from the Raspberry Pi and further actions may be made.
