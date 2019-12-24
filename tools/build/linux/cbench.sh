#!/bin/bash

START_DIR=`pwd`
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_BENCHMARKS=On -H. -B.build/linux_bench -GNinja || exit
cmake --build .build/linux_bench || exit
cd .build/linux_bench

echo "Running benchmarks..."
ctest -VV || exit
cd $START_DIR
