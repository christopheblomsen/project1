import numpy as np
import matplotlib.pyplot as plt
import sys

gen_10 = np.loadtxt('general_thomas_10.txt', skiprows = 2)
gen_100 = np.loadtxt('general_thomas_100.txt', skiprows = 2)
gen_1000 = np.loadtxt('general_thomas_1000.txt', skiprows = 2)

fig = plt.figure()
ax = plt.axes()
ax.plot(gen_1000[:, 0], gen_1000[:, 1], 'k')
ax.plot(gen_1000[::25, 0], gen_1000[::25, 2], 's', color = 'm', label = 'v_1000')
ax.plot(gen_100[::5, 0], gen_100[::5, 2], 'v', color = 'c', label = 'v_100')
ax.plot(gen_10[:, 0], gen_10[:, 2], 'o', color = 'r', label = 'v_10')
ax.set_xlabel('x [-]')
ax.set_ylabel('u(x), and v(x)')
fig.savefig('plot_7.pdf')
plt.legend()
plt.show()
