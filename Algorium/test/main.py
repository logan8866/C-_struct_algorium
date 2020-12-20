import numpy as np
import copy
import time
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

goin = [0,0,0]
goout = [3,3,3]
dimension = 4
color = np.zeros((dimension,dimension,dimension))
#go_can = [[0,0,0],[0,1,0],[0,1,1],[1,1,1],[1,1,2],[1,2,2],[1,3,2],[2,3,2],[3,3,2],[3,3,3]]#,[2,1,1],[0,3,2],[2,2,2]]
#go_can = np.array(go_can)
go_can = [[0, 0, 0], [0, 1, 0], [0, 1, 1], [1, 1, 1], [1, 1, 2], [1, 2, 2], [1, 3, 2], [2, 3, 2], [3, 3, 2], [3, 3, 3]]
for i in go_can:
    color[i[0],i[1],i[2]] = 1
real_color = copy.deepcopy(color)
route = None
route_all = []
now_position = copy.deepcopy(goin)
bevor_position = copy.deepcopy(goin)
middle_position = None
i = 0
has_diff = 0
next_position = []
not_go = []

while(True):
    route = []
    route.append(copy.deepcopy(goin))
    while(True):
        i = 0
        if (now_position==goout):
            now_position = copy.deepcopy(goin)
            not_go.clear()
            break
        while(i<3):
            if now_position[i]-1>=0 and now_position[i]-1<dimension and now_position[i]-1!=bevor_position[i]:
                middle_position = copy.deepcopy(now_position)
                now_position[i]  = now_position[i]-1
                if now_position in go_can and now_position not in route and now_position not in not_go:
                    if now_position not in next_position and color[now_position[0]][now_position[1]][now_position[2]]==color[middle_position[0]][middle_position[1]][middle_position[2]]:
                        next_position.append(copy.deepcopy(now_position))
                        now_position[i] = now_position[i]+1
                        #print(now_position)
                    if color[now_position[0]][now_position[1]][now_position[2]]!=color[middle_position[0]][middle_position[1]][middle_position[2]]:
                        route.append(copy.deepcopy(now_position))
                        bevor_position = copy.deepcopy(middle_position)
                        #print(route)
                        next_position.clear()
                        break
                else:
                    now_position[i] = now_position[i]+1

            if now_position[i]+1>=0 and now_position[i]+1<dimension and now_position[i]+1!=bevor_position[i]:
                middle_position = copy.deepcopy(now_position)
                now_position[i]  = now_position[i]+1
                #print(now_position)
                #print(go_can)
                #print(route)
                if now_position in go_can and now_position not in route and now_position not in not_go:
                    if now_position not in next_position and color[now_position[0]][now_position[1]][now_position[2]]==color[middle_position[0]][middle_position[1]][middle_position[2]]:
                        next_position.append(copy.deepcopy(now_position))
                        now_position[i] = now_position[i]-1
                        #print("----",next_position)
                    if color[now_position[0]][now_position[1]][now_position[2]]!=color[middle_position[0]][middle_position[1]][middle_position[2]]:
                        route.append(copy.deepcopy(now_position))
                        bevor_position = copy.deepcopy(middle_position)
                        #print(route)
                        next_position.clear()
                        break
                else:
                    now_position[i] = now_position[i]-1
            i+=1
            if i==3:
                if len(next_position)!=0:
                    bevor_position = copy.deepcopy(middle_position)
                    now_position = copy.deepcopy(next_position[0])
                    route.append(copy.deepcopy(now_position))
                    #print("---route-cf----",route)
                    next_position.clear()
                else:
                    #go_can.remove(now_position)
                    not_go.append(copy.deepcopy(now_position))
                    route.pop()
                    now_position = copy.deepcopy(bevor_position)
                    bevor_position = copy.deepcopy(route[-2])
            #print(route)
            #time.sleep(0.1)
    for i in route:
        color[i[0]][i[1]][i[2]]+=1
    #print("----color----",color)
    #print("---all----",route_all)
    #print("----go_can----",go_can)
    if route in route_all:
        break
    else:
        route_all.append(copy.deepcopy(route))
    #print("---all----",route_all)

fig = plt.figure()
ax1 = plt.axes(projection='3d')
route = np.array(route)
x = np.arange(0,dimension)
x_ok = np.ones((dimension,dimension,dimension))
z = x_ok*x
x_1 = x_ok*x.reshape((dimension,1))
y = x_ok*x.reshape((dimension,1,1))
ax1.scatter3D(y,x_1,z,c=real_color)
abgleich = 0.00
for route in route_all:
    route = np.array(route)
    ax1.plot3D(route[:,0]+abgleich,route[:,1]+abgleich,route[:,2]+abgleich)
    abgleich+=0.03
plt.show()



