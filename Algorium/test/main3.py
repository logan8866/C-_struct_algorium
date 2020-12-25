import numpy as np
import copy
import time
from matplotlib import pyplot as plt
import matplotlib
from mpl_toolkits.mplot3d import Axes3D
import random
matplotlib.use('Agg')

goin = [0,0,0]
dimension = 4
goout = [dimension-1,dimension-1,dimension-1]
#create room
color = np.zeros((dimension,dimension,dimension))
#create random route
#go_can = [[0,0,0],[0,1,0],[0,1,1],[1,1,1],[1,1,2],[1,2,2],[1,3,2],[2,3,2],[3,3,2],[3,3,3],[2,1,1],[0,3,2],[2,2,2]]
go_can = []
go_can.append(copy.deepcopy(goin))
go_can.append(copy.deepcopy(goout))
now_position = copy.deepcopy(goin)
while(now_position!=goout):
    i = 0
    while i<3:
        go = random.randint(-1,1)
        now_position[i] = now_position[i]+go;
        if now_position[i]>=0 and now_position[i]<dimension:
            go_can.append(copy.deepcopy(now_position))
        else:
            now_position[i] = now_position[i]-go;
        i+=1
        #print(now_position)
go_can = list(set([tuple(t) for t in go_can]))
go_can = [list(t) for t in go_can]
#go_can = list(go_can)
#print(go_can)
#go_can = np.array(go_can)
#go_can = [[0,0,0],[0,1,0],[0,1,1],[1,1,1],[1,1,2],[1,2,2],[1,3,2],[2,3,2],[3,3,2],[3,3,3],[2,1,1],[0,3,2],[2,2,2]]
#go_can = [[0,0,0],[1,0,0],[1,1,0],[2,0,0],[2,1,0],[2,2,0],[2,3,0],[3,3,0],[3,3,0],[1,2,0],[1,3,0]]
#goout = [3,3,0]
#print(go_can)
for i in go_can:
    color[i[0]][i[1]][i[2]] = 1
real_color = copy.deepcopy(color)
route = []
route.append(copy.deepcopy(goin))
route_all = []
now_position = copy.deepcopy(goin)
route_stock = []
route_stock_num = []
next_num = []
num = 0
not_go = []

for i in go_can:
    i = list(i)
    x = 0
    num = 0
    while x<3:
        i[x] = i[x] + 1
        if i[x]>=0 and i[x]<dimension:
            if color[i[0]][i[1]][i[2]]!=0:
                num+=1
                i[x] = i[x]-1
            else:
                i[x] = i[x]-1
        else:
            i[x] = i[x]-1
        i[x] = i[x]-1
        if i[x]>=0 and i[x]<dimension:
            if color[i[0]][i[1]][i[2]]!=0:
                num+=1
                i[x] = i[x]+1
            else:
                i[x] = i[x]+1
        else:
            i[x] = i[x]+1
        x+=1
    next_num.append(copy.deepcopy(num))
#print(next_num)

bevor_position = None
now_position = copy.deepcopy(goin)
next_position = None
multi_stock = []
multi_stock_num = []
route_all = []
route = []

def now_status_def(now_position):
    global goin,goout,go_can,next_num,route
    if (now_position in route and now_position != multi_stock[-1]):
        return -3 #走过了
    elif (now_position == goin):
        return -2 #起点
    elif (now_position == goout):
        return -1 #到达终点
    elif(next_num[go_can.index(now_position)]==1):
        print("hello")
        return 1 #死胡同
    elif (next_num[go_can.index(now_position)]==2):
        return 2 #非起点，只有前进
    elif (next_num[go_can.index(now_position)]>2):
        return 0 #有多条路径

def go_next(now_position):
    go_count = 0
    i = 0
    now_position_copy = copy.deepcopy(now_position)
    next_position_def = None
    while(i<3):
        if (now_position_copy[i]-1>=0 and now_position_copy[i]-1<dimension):
            next_position_def = copy.deepcopy(now_position_copy)
            next_position_def[i]-=1
            if (next_position_def in go_can):
                if (now_position_copy in multi_stock):
                    if (go_count+multi_stock_num[multi_stock.index(now_position_copy)] == next_num[go_can.index(now_position)]):
                        return next_position_def
                    else:
                        go_count+=1
                else:
                    return next_position_def
            else:
                pass
        if (now_position_copy[i]+1>=0 and now_position_copy[i]+1<dimension):
            next_position_def = copy.deepcopy(now_position_copy)
            next_position_def[i]+=1
            if (next_position_def in go_can):
                if (now_position_copy in multi_stock):
                    if (go_count+multi_stock_num[multi_stock.index(now_position_copy)] == next_num[go_can.index(now_position)]):
                        return next_position_def
                    else:
                        go_count+=1
                else:
                    return next_position_def
            else:
                pass
        i+=1

def go_just_next(now_position):
    i = 0
    now_position_copy = copy.deepcopy(now_position)
    next_position_def = None
    while(i<3):
        if (now_position_copy[i]-1>=0 and now_position_copy[i]-1<dimension):
            next_position_def = copy.deepcopy(now_position_copy)
            next_position_def[i]-=1
            if (next_position_def in go_can):
                if (next_position_def != route[-1]):
                    return next_position_def
                else:
                    pass
            else:
                pass
        if (now_position_copy[i]+1>=0 and now_position_copy[i]+1<dimension):
            next_position_def = copy.deepcopy(now_position_copy)
            next_position_def[i]+=1
            if (next_position_def in go_can):
                if (next_position_def != route[-1]):
                    return next_position_def
                else:
                    pass
            else:
                pass
        i+=1


while(True):
    now_status = now_status_def(now_position)
    #print(now_status)
    if now_status == -2:
        #print("hello")
        #如果是迷宫入口
        #如果迷宫入口出有一条路
        if (next_num[go_can.index(now_position)]==1):
            next_position = go_next(now_position)
            route.append(copy.deepcopy(now_position))
            bevor_position = copy.deepcopy(now_position)
            now_position = copy.deepcopy(next_position)
            #print(now_position)
            continue
        #如果迷宫有多条路
        elif (next_num[go_can.index(now_position)]>=2):
            if (now_position not in multi_stock):
                multi_stock.append(copy.deepcopy(now_position))
                multi_stock_num.append(copy.deepcopy(next_num[go_can.index(now_position)]))
                next_position = go_next(now_position)
                route.append(copy.deepcopy(now_position))
                bevor_position = copy.deepcopy(now_position)
                now_position = copy.deepcopy(next_position)
                continue
            elif (now_position in multi_stock):
                next_position = go_next(now_position)
                bevor_position = copy.deepcopy(now_position)
                now_position = copy.deepcopy(next_position)
                continue
    elif now_status == -3 or now_status == 1:
        #走过了 或 到死胡同
        #print(now_status)
        while(True):
            multi_stock_num[-1]-=1
            if multi_stock_num[-1]==0:
                del multi_stock_num[-1:]
                del multi_stock[-1:]
            elif multi_stock_num[-1]!=0:
                now_position = copy.deepcopy(multi_stock[-1])
                del route[route.index(now_position)+1:]
                if (now_position!=goin):
                    bevor_position = route[-2]
                elif (now_position == goin):
                    bevor_position = 0
                #print("--",now_position)
                time.sleep(0)
                break
            if len(multi_stock) == 0:
                break
        if len(multi_stock)==0:
            break

    elif now_status == -1:
        route.append(copy.deepcopy(now_position))
        print(route)
        route_all.append(copy.deepcopy(route))
        while(True):
            multi_stock_num[-1]-=1
            if multi_stock_num[-1]==0:
                del multi_stock_num[-1:]
                del multi_stock[-1:]
            elif multi_stock_num[-1]!=0:
                now_position = copy.deepcopy(multi_stock[-1])
                del route[route.index(now_position)+1:]
                if (now_position!=goin):
                    bevor_position = route[-2]
                elif (now_position == goin):
                    bevor_position = 0
                break
            if len(multi_stock) == 0:
                break
        if len(multi_stock)==0:
            break

    elif now_status == 2:
        next_position = go_just_next(now_position)
        bevor_position = copy.deepcopy(now_position)
        route.append(copy.deepcopy(now_position))
        now_position = copy.deepcopy(next_position)
        #print(now_position)

    elif now_status == 0:
        if (now_position not in multi_stock):
            multi_stock.append(copy.deepcopy(now_position))
            multi_stock_num.append(copy.deepcopy(next_num[go_can.index(now_position)]))
            next_position = go_next(now_position)
            route.append(copy.deepcopy(now_position))
            bevor_position = copy.deepcopy(now_position)
            now_position = copy.deepcopy(next_position)
            #print(now_position)
            time.sleep(0)

        elif (now_position in multi_stock):
            next_position = go_next(now_position)
            bevor_position = copy.deepcopy(now_position)
            now_position = copy.deepcopy(next_position)
            #print(now_position)
print(route_all)

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
name = 0
for route in route_all:
    route = np.array(route)
    lines = ax1.plot3D(route[:,0]+abgleich,route[:,1]+abgleich,route[:,2]+abgleich)
    plt.savefig("migong"+str(name)+".jpg")
    ax1.lines.remove(lines[0])
    #print(ax1.lines)
    abgleich+=0.00
    name += 1
#plt.savefig("migong"+str(abgleich)+".jpg")
#plt.show()


