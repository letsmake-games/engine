#!/bin/bash

cmake -H. -DBT_TESTING=ON -B.build/linux_test -GNinja || exit
cmake --build .build/linux_test || exit
cd .build/linux_test
ctest -VV -j 8
