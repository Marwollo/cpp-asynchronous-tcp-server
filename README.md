# Basic C++ Asynchronous TCP server

## About
This project represents a boilerplate / example code for a basic asynchronous TCP server based on ASIO (standalone, without Boost).

## How to run
In order to compile and run the project, make sure you do the following:

### Unordered
* Make sure that CMake is installed on your device. You can check by trying out the command `cmake` in a terminal/command prompt window.
* Run `cmake ./build` in the root directory. This command will download the required dependencies and build the project in the `build` folder.
* Open the generated `build` folder in your terminal window. From there, you can execute `make`, which will compile the project and generate an executable file `AsyncTCPServer`.

## How to test
There are several ways to test the connectivity. One of them is to try creating a HTTP request to `localhost:15001` while the program is running. You should be able to see the HTTP request body in the console output.