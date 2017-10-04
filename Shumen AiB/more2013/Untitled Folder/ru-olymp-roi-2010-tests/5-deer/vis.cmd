pushd visualizator
echo off
call run.cmd ../images/%1 <../tests/%1
echo on
popd
rem images\%1.png
