#!/bin/bash

mkdir -p ./build

cd build

echo 'Running conan.io...'
conan install -f ../conanfile.txt

echo 'Running cmake...'
cmake ../

echo 'Running make...'
make