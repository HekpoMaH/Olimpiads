#!/usr/bin/python
# coding: cp1251

import os
import re

def get_stats(file):
  f = open(file, 'r')
  f.readline()
  f.readline()
  n = []
  for i in xrange(5):
    k = int(f.readline())
    for j in xrange(k):
      f.readline()     
    n.append(k)
  print ('Количество друзей: %d. N1 = %d, N2 = %d, N3 = %d, N4 = %d, N5 = %d. ' % (
      sum(n), n[0], n[1], n[2], n[3], n[4])) 

def main():
  for file in os.listdir('.'):
    if re.match('^[0-9]{2}$', file):
      get_stats(file)

main()