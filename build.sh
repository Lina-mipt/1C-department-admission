#!/bin/bash

mkdir build
cd build
cmake ..
make
cd ..
cd tests
python3 run_tests.py
cd ..
