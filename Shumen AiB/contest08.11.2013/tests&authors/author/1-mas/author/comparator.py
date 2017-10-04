#!/usr/bin/python2

import sys
import os
import tempfile
import filecmp
import subprocess
import time

def compare_single_test(sols, infile, outfiles):
  res = []
  times = []
  for sol, outfile in zip(sols, outfiles):
    outfile_handle = open(outfile, 'w+')

    infile_handle = open(infile)
    devnull = open(os.devnull, 'w')

    start = time.time()
    subprocess.call([ sol ], stdin=infile_handle, stdout=outfile_handle, stderr=devnull)
    times.append(time.time() - start)

    outfile_handle.seek(0)
    curr = outfile_handle.read().strip()
    res.append(int(curr))

  assert(len(res) == 2)
  if res[0] != res[1]:
    if res[0] < res[1]: print '!!!',
    else: print '   ',
    print 'Different results',
  else:
    print '    Equal results',

  print 'on "%s": %d vs %d (%.2lfs vs %.2lfs)' % (infile, res[0], res[1], times[0], times[1])
  return res[0] == res[1]

def compare_solutions(sol1, sol2, in_dir, out_dir):
  ans = True

  sol1_bn = os.path.basename(sol1);
  sol2_bn = os.path.basename(sol2);

  for fn in os.listdir(in_dir):
    first, ext = os.path.splitext(fn);

    outfile1 = os.path.join( out_dir, os.path.splitext(sol1_bn)[0] + '.' + first + ".out" )
    outfile2 = os.path.join( out_dir, os.path.splitext(sol2_bn)[0] + '.' + first + ".out" )

    if ext=='.in':
      if not compare_single_test([sol1, sol2], os.path.join(in_dir,fn), [outfile1, outfile2]):
        ans = False

  if ans==False:
    print "There is a problem, captain!"
  else:
    print "Everything's fine!"

if __name__ == "__main__":
  if len(sys.argv) != 5:
    print '<sol1 bin> <sol2 bin> <.in files dir> <results dir>'
  else:
    apply(compare_solutions, sys.argv[1:])

#    sol1 = sys.argv[1]
#    sol2 = sys.argv[2]
#    in_dir = sys.argv[3]
#    out_dir = sys.argv[4]

#    compare_solutions(sol1, sol2, in_dir, out_dir)
