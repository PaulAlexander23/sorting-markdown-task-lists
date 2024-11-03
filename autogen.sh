#!/usr/bin/sh

# Remove previous build
rm -rf build

# Create and enter new build directory
mkdir build 
cd build

# Call cmake to create Makefiles
cmake ..

# Call make to build project
make

./cmake_demo.out ../data/test_sorter.md > actual_sorter.md

diff actual_sorter.md ../data/expected_sorter.md
