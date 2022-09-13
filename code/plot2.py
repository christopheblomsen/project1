import numpy as np
import matplotlib.pyplot as plt
import sys

# give two command line arguments, the first should be our numerical approx

filename1 = sys.argv[1]
filename2 = sys.argv[2]
# files with values, first two rows headers

data1 = np.loadtxt(filename1, skiprows=2)
data2 = np.loadtxt(filename2, skiprows=2)

x1 = data1[:, 0]
v = data1[:, 1]

x2 = data2[:, 0]
u = data2[:, 1]

plt.plot(x1, v, 'x', color = 'r')
plt.plot(x2, u, color = 'k')
plt.xlabel('x')
plt.ylabel('u(x) line, and v(x) cross')
plt.show()
