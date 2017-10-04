@echo off
copy  domino.in%1 domino.inp
delete domino.out
domino <domino.inp  >domino.out
domchck
