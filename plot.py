import numpy as np
import pylab as plt

name="neville.txt"
data=np.loadtxt(name)

x=data[:,0]
y=data[:,1]

name_datapoints="temperatura.txt"
data_points=np.loadtxt(name)

x_points=data_points[:,0]
y_points=data_points[:,1]

plt.plot(x,y)
plt.plot(x_points,y_points,'go')

plt.show()
