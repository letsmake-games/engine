cmake -H. -DBT_TESTING=ON -B.build/win_test -G"Visual Studio 16 2019"
cmake --build .build/win_test
cd .build/win_test
ctest -VV -j 8
