КАК СОБРАТЬ ЭТО

cmake -S . -B build-debug   -DCMAKE_BUILD_TYPE=Debug   && cmake --build build-debug   -j
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release && cmake --build build-release -j

КАК ЗАПУСТИТЬ ЭТО 

./build-debug/apps/demo_fraction
./build-debug/apps/demo_expression