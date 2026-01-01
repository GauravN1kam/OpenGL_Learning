#!/bin/zsh
echo Hello World!
cd build
cmake ..
make
./hello_window
cd ..