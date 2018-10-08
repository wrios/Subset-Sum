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
x = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]

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

plt.xlabel('i')
plt.ylabel('logaritmo en base 2 del tiempo (ns)')
plt.title('')
plt.plot(x, np.log2(matrix[0]))
plt.plot(x, np.log2(matrix[1]))
plt.plot(x, np.log2(matrix[2]))
plt.plot(x, np.log2(matrix[3]))
plt.legend(['Fuerza Bruta','Factibilidad', 'Optimalidad','PD'],loc = 'lower right')
plt.savefig('todos'+sys.argv[1]+'.png', format='png')
plt.show()