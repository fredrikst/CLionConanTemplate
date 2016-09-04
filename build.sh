#!/bin/bash

rm -rf build

mkdir -p ./build

cd build

echo 'Running conan.io...'
conan install --build -f ../conanfile.txt -s compiler=gcc -s compiler.version=5.4 -s compiler.libcxx=libstdc++11

echo 'Running cmake...'
cmake ../

echo 'Running make...'
make