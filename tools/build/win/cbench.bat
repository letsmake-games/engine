cmake -H. -DCMAKE_BUILD_TYPE=Release -DBUILD_BENCHMARKS=On -B.build/win_bench -G"Visual Studio 16 2019"
cmake --build .build/win_bench
cd .build/win_bench
ctest -VV -j 8
