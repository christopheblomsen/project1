import numpy as np
import matplotlib.pyplot as plt
import os

os.chdir(r'/home/rhuvy/Documents/FYS4150/fys4150/Projects/project1/code')

point_size = np.array([10, 100, 1000, 10000, 100000, 1000000])

for i in point_size:
    x, u, v, t = np.loadtxt('general_thomas_{}.txt'.format(i), skiprows=2, unpack=True)
    x_s, u_s, v_s, t_s = np.loadtxt('special_thomas_{}.txt'.format(i), skiprows=2, unpack=True)

    # print("The executed time for {} points with the special algorithm:".format(i), t_s[0])
    # print("The executed time for {} points with the general algorithm:".format(i), t[0], '\n')


var_10 = np.array([[4.287e-06, 4.765e-06, 5.028e-06, 5.456e-06, 4.436e-06], [6.554e-06, 5.26e-06, 8.591e-06, 5.836e-06, 5.739e-06]])
var_100 = np.array([[1.0543e-05, 1.0434e-05, 1.6824e-05, 1.8939e-05, 1.0656e-05], [3.3863e-05, 2.8276e-05, 5.8861e-05, 1.8876e-05, 1.7487e-05]])
var_1000 = np.array([[8.3227e-05, 8.3233e-05, 0.00011005, 0.00015238, 8.3553e-05], [0.00037528, 0.00021207, 0.00017538, 0.00013276, 0.000111]])
var_10000 = np.array([[0.0012768, 0.0010022, 0.0020294, 0.0011955, 0.0014736], [0.0022492, 0.0014198, 0.0013112, 0.0018732, 0.001297]])
var_100000 = np.array([[0.010953, 0.010482, 0.010759, 0.011245, 0.0099622], [0.01322, 0.012885, 0.0121, 0.017847, 0.011904]])
var_1000000 = np.array([[0.11737, 0.10661, 0.10987, 0.10755, 0.10477], [0.12559, 0.11892, 0.1307, 0.13171, 0.1295]])

print('the mean value is for 10 points is:', np.mean(var_10, axis=1), "and the standard deviation is:", np.std(var_10, axis=1))
print('the mean value is for 100 points is:', np.mean(var_100, axis=1), "and the standard deviation is:", np.std(var_100, axis=1))
print('the mean value is for 1000 points is:', np.mean(var_1000, axis=1), "and the standard deviation is:", np.std(var_1000, axis=1))
print('the mean value is for 10000 points is:', np.mean(var_10000, axis=1), "and the standard deviation is:", np.std(var_10000, axis=1))
print('the mean value is for 100000 points is:', np.mean(var_100000, axis=1), "and the standard deviation is:", np.std(var_100000, axis=1))
print('the mean value is for 1000000 points is:', np.mean(var_1000000, axis=1), "and the standard deviation is:", np.std(var_1000000, axis=1))
