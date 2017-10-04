#!/bin/bash

rm -rf ./png
mkdir ./png

pushd ../tests
for f in ?? ; do
perl  ../visualize/in2png.pl $f $f.a > ../visualize/png/$f.png
done
popd
