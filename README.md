# Ten-Pin-Bowling-Imaging
This project aims to provide binary tools for detection of bowling pins after a strke. The executives can be built via **CMake** and **make** by the following commands:

First, create a sub-directory "release" inside the root directory of the project and change to it:

`% mkdir release && cd relase`

Then, configure and generate the necessary files for building and build:
```
cmake ..             #generate files to the current directory while reading input files from the upper directory
make  -j$(nproc)     #build the executives with all the processor threads working in parallel.
```
