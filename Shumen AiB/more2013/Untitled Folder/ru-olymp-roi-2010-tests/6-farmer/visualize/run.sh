#!/bin/bash

make in2mp || exit 1

cat head.tex > vis.tex

pushd ../tests
for f in ?? ; do
  ../visualize/in2mp $f $f.a > ../visualize/$f.mp
done
popd

for f in ??.mp ; do
  mpost $f
done

for f in ??.1 ; do
  echo "\\includegraphics[width=17cm]{$f}" >> vis.tex
  echo "\\newpage" >> vis.tex
done

cat tail.tex >> vis.tex
latex vis.tex && latex vis.tex && dvipdfmx -p a4 vis.dvi
