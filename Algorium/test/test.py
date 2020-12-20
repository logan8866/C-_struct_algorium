import numpy as np
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure()
ax1 = plt.axes(projection='3d')

dimension = 4
#route = [[0, 0, 0], [0, 1, 0], [0, 1, 1], [1, 1, 1], [1, 1, 2], [1, 2, 2], [2, 2, 2], [2, 3, 2], [3, 3, 2], [3, 3, 3]]
route = [[0, 0, 0], [0, 1, 0], [0, 1, 1], [1, 1, 1], [1, 1, 2], [1, 2, 2], [2, 2, 2], [2, 3, 2], [3, 3, 3]]
route = np.array(route)
x = np.arange(0,dimension)
x_ok = np.ones((dimension,dimension,dimension))
z = x_ok*x
x_1 = x_ok*x.reshape((dimension,1))
y = x_ok*x.reshape((dimension,1,1))
color = np.ones((dimension,dimension,dimension))*0
for i in route:
    color[i[0],i[1],i[2]] = 1
ax1.scatter3D(y,x_1,z,c=color)
ax1.plot3D(route[:,0],route[:,1],route[:,2],'green')
ax1.plot3D(route[:,0]+0.03,route[:,1]+0.03,route[:,2]+0.03,'red')
plt.show()

