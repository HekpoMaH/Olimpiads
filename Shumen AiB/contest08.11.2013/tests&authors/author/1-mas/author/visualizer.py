#!/usr/bin/python

import sys
from Bio import Phylo

# unused
def print_newick(newick_fn):
  apaf = Phylo.read(newick_fn, 'newick')
  Phylo.draw_ascii(apaf)
  Phylo.draw(apaf)

"""
graph G {
  ordering=out
  label="..."

  node [shape=box];
  2 [label="2: MAN"];
  ...

  node [shape=ellipse];
  
  1 -- 2;
  ...
}
"""

def read_tree(fin):
  fin.readline().split()

def trees2dots(infile):
  fin = open(infile)

  is_last = False

  while is_last:
    tree, is_last = read_tree(fin)


if __name__ == "__main__":
  if len(sys.argv) != 2:
    print 'Give an input file name with at least one tree in it'
  else:
    dotfiles = trees2dots(sys.argv[1])
