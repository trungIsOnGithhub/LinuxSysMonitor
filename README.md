# System Monitor

> Development using C++11, Ubuntu 22.04 LTS, GNU Make and CMake >= 2.8.12 (lastest not deprecated)

## Description
This is a simple version of a system monitor program that is simillar to [htop](https://en.wikipedia.org/wiki/Htop. This small project capitalize on creating multiple classes and header files that parse, maniplate, and then display linux system information that can mostly be found in the `/proc` directory on the linux distributions.
## ncurses
[ncurses](https://www.gnu.org/software/ncurses/) is a library used in this project that facilitates text-based graphical output in the terminal.

Install ncurses within your own Linux environment: `sudo apt install libncurses5-dev libncursesw5-dev`

## Instructions for building and running

0. Clone the project from this repository

1. Run ```make clean``` before every time you run the project

2. Check if ```ncurses-dev``` is installed, if not, run ```sudo apt-get install libncurses-dev```

3. Build the project: ```make build```

4. Run the executable: `./build/sysmonitor`

5. Finally, implement the `System`, `Process`, and `Processor` classes, as well as functions within the `LinuxParser` namespace.

You should then see a program result as the one below:
![Executed Program](imgs/1.png)

## Running Status for Ubuntu 20.04

[x] Ok
