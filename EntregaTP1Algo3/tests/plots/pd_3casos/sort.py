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
x = [100,500,1000,2500,3000,4000,8000,12000,16000,20000,24000,28000,32000,36000,40000,44000,48000,52000,56000,60000,64000,68000,72000,76000,80000]

with open(sys.argv[1]) as csvfile:
    reader = csv.reader(csvfile, quoting=csv.QUOTE_NONNUMERIC)
    for row in reader:
    	matrix.append(row)
y = []
z = []
i = 0
for elem in matrix[1]:
	matrix[0][i] = matrix[0][i]/x[i]
	matrix[1][i] = matrix[1][i]/x[i]
	matrix[2][i] = matrix[2][i]/x[i]
	i = i+1
plt.xlabel('V')
plt.ylabel('tiempo/V (ns)')
plt.title('')
plt.plot(x, matrix[0])
plt.plot(x, matrix[1])
plt.plot(x, matrix[2])
plt.legend(['decreciente', 'creciente','unSort'],loc = 'upper left')
plt.savefig('todos'+sys.argv[1]+'.png', format='png')
plt.show()