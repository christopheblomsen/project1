import numpy as np
import matplotlib.pyplot as plt
import sys
from tabulate import tabulate

#give general_thomas_N as your command line arguments

filename1 = sys.argv[1]
filename2 = sys.argv[2]
filename3 = sys.argv[3]
# files with values, first two rows header

data1 = np.loadtxt(filename1, skiprows=2)
data2 = np.loadtxt(filename2, skiprows=2)
data3 = np.loadtxt(filename3, skiprows=2)

# removes the end points that are zero
x1 = data1[1:-1, 0]
u1 = data1[1:-1, 1]
v1 = data1[1:-1, 2]
n1 = len(x1)+2

x2 = data2[1:-1, 0]
u2 = data2[1:-1, 1]
v2 = data2[1:-1, 2]
n2 = len(x2)+2

x3 = data3[1:-1, 0]
u3 = data3[1:-1, 1]
v3 = data3[1:-1, 2]
n3 = len(x3)+2

# 8a
delta1 = np.log10(np.abs(u1 - v1))
delta2 = np.log10(np.abs(u2 - v2))
delta3 = np.log10(np.abs(u3 - v3))

plt.plot(x1, delta1, '.', color = 'r', label = f'n={n1}')
plt.plot(x2, delta2, '.', color = 'k', label = f'n={n2}')
plt.plot(x3, delta3, '.', color = 'b', label = f'n={n3}')
plt.xlabel('x')
plt.ylabel('log_10(Abs error)')
plt.legend()
plt.savefig('plot_8a.pdf')
plt.close()

# 8b
eps1 = np.log10(np.abs((u1 - v1)/u1))
eps2 = np.log10(np.abs((u2 - v2)/u2))
eps3 = np.log10(np.abs((u3 - v3)/u3))

plt.plot(x1, eps1, '.', color = 'r', label = f'n={n1}')
plt.plot(x2, eps2, '.', color = 'k', label = f'n={n2}')
plt.plot(x3, eps3, '.', color = 'b', label = f'n={n3}')
plt.legend()
plt.xlabel('x')
plt.ylabel('log_10(Rel error)')
plt.savefig('plot_8b.pdf')
plt.close()

# 8c
eps = [np.max(eps1), np.max(eps2), np.max(eps3)]
n = [n1, n2, n3]
table = zip(n, eps)
print(tabulate(table, headers=["n", "Max relative error"], floatfmt=(".2e", ".3f")))
