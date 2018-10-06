from __future__ import division
import matplotlib.pyplot as plt
import pylab
from mpl_toolkits.mplot3d import Axes3D
import random
import platform
import itertools
from itertools import groupby as g
import csv
import sys
import getopt
import numpy as np
import ast
import scipy.io
from numpy import linalg as LA
import os.path
import matplotlib.pylab as plt

matrix = []
x = [5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35]

with open(sys.argv[1]) as csvfile:
    reader = csv.reader(csvfile, quoting=csv.QUOTE_NONNUMERIC)
    for row in reader:
    	matrix.append(row)
y = []
z = []
i = 0
for elem in matrix[0]:
	y.append(elem/(pow(2,x[i])))
	z.append(pow(2,x[i]))
	i = i+1

plt.figure(1)
plt.subplot(211)
plt.ylabel('tiempo del algoritmo(ns)')
plt.xlabel('cantidad de item')
plt.title('Backtracking con poda de factibilidad')
plt.plot(x, matrix[0])

plt.subplot(212)
plt.ylabel('tiempo del algoritmo(ns)')
plt.xlabel('cantidad de item')
plt.plot(x, y)
plt.savefig(sys.argv[1]+'.png', format='png')
plt.show()