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

plt.xlabel('n')
plt.ylabel('logaritmo en base 2 del tiempo (ns)')
plt.title('')
plt.plot(x, np.log2(matrix[0]))
plt.plot(x, np.log2(matrix[1]))
plt.plot(x, np.log2(matrix[2]))
plt.legend(['decreciente', 'creciente','unSort'],loc = 'upper left')
plt.savefig('todos'+sys.argv[1]+'.png', format='png')
plt.show()