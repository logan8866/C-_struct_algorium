import numpy as np
import copy
import time
from matplotlib import pyplot as plt
import matplotlib
from mpl_toolkits.mplot3d import Axes3D
import random
matplotlib.use('Agg')

goin = [0,0,0]
dimension = 3
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
print(next_num)

can_go_count = 0

print("----------")

while(True):
    while(True):
        i = 0
        can_go_count = 0
        while(i<3):
            #cannot over layout
            if now_position not in route_stock:
                print("enter not stock if")
                #print(now_position)
                if now_position[i]-1>=0 and now_position[i]-1<dimension:
                    now_position[i] = now_position[i]-1
                    if now_position not in go_can :
                        now_position[i] = now_position[i]+1
                    elif now_position in go_can:
                        if now_position in route:
                            now_position[i] = now_position[i]+1
                        elif next_num[go_can.index(now_position)] == 1:
                            if now_position == goout:
                                route.append(copy.deepcopy(now_position))
                                print(route)
                                break
                            now_position[i] = now_position[i]+1
                        elif next_num[go_can.index(now_position)] == 2:
                            route.append(copy.deepcopy(now_position))
                            print(route)
                            break
                        elif next_num[go_can.index(now_position)]>2:
                            route_stock.append(copy.deepcopy(now_position))
                            route_stock_num.append(copy.deepcopy(next_num[go_can.index(now_position)]))
                            route.append(copy.deepcopy(now_position))
                            print(route)
                            break
                    else:
                        now_position[i] = now_position[i]+1
                if now_position[i]+1>=0 and now_position[i]+1<dimension:
                    now_position[i] = now_position[i]+1
                    if now_position not in go_can:
                        now_position[i] = now_position[i]-1
                    elif now_position in go_can:
                        if now_position in route:
                            now_position[i] = now_position[i]-1
                        elif next_num[go_can.index(now_position)] == 1:
                            if now_position == goout:
                                route.append(copy.deepcopy(now_position))
                                print(route)
                                break
                            now_position[i] = now_position[i]-1
                        elif next_num[go_can.index(now_position)] == 2:
                            route.append(copy.deepcopy(now_position))
                            print(route)
                            break
                        elif next_num[go_can.index(now_position)]>2:
                            route_stock.append(copy.deepcopy(now_position))
                            route_stock_num.append(copy.deepcopy(next_num[go_can.index(now_position)]))
                            route.append(copy.deepcopy(now_position))
                            """
                            print(route)
                            print("---now---",now_position)
                            print("88888",route_stock_num)
                            print("88888",route_stock)"""
                            print(route)
                            break
                    else:
                        now_position[i] = now_position[i]-1
                if i==2:
                    if len(route_stock)!=0: 
                        print("this")
                        now_position = copy.deepcopy(route_stock[-1])
                        del route[route.index(now_position)+1:]
                        print(route)
                        break
                    else:
                        now_position = copy.deepcopy(route[-1])
                        del route[-1:]
                        break
            elif now_position in route_stock:
                '''
                print("enter stock if")
                print(route_stock)
                print(route_stock_num)
                print(route)
                print(now_position)
                print("-----")
                '''
                print("enter stock if")
                bevor_position = copy.deepcopy(now_position)
                if now_position[i]-1>=0 and now_position[i]-1<dimension:
                    now_position[i] = now_position[i]-1
                    if now_position not in go_can:
                        now_position[i] = now_position[i]+1
                    elif now_position in go_can:
                        '''
                        print("--------")
                        print(now_position)
                        print(bevor_position)
                        print(route_stock)
                        print(route_stock_num)'''
                        if can_go_count+route_stock_num[route_stock.index(bevor_position)] == next_num[go_can.index(bevor_position)]:
                            route_stock_num[route_stock.index(bevor_position)]-=1
                            if route_stock_num[route_stock.index(bevor_position)]==0:
                                if next_num[go_can.index(now_position)]==1 or (now_position in route):
                                    now_position[i] = now_position[i]+1
                                    can_go_count += 1
                                    route_stock_num.pop(route_stock.index(bevor_position))
                                    route_stock.remove(bevor_position)
                                    print("heir---i------------")
                                    print(now_position)
                                    print(route)
                                    break
                                else:
                                    route_stock_num.pop(route_stock.index(bevor_position))
                                    route_stock.remove(bevor_position)
                                    route.append(copy.deepcopy(now_position))
                                    break
                                
                            elif next_num[go_can.index(now_position)]==1 or (now_position in route):
                                    #print("heir")
                                    now_position[i] = now_position[i]+1
                                    can_go_count += 1
                                    print("1",route)
                                    break
                            else:
                                route.append(copy.deepcopy(now_position))
                                print("2",route)
                                break
                        elif can_go_count+route_stock_num[route_stock.index(bevor_position)] != next_num[go_can.index(bevor_position)]:
                            can_go_count+=1
                            now_position[i] = now_position[i]+1
                if now_position[i]+1>=0 and now_position[i]+1<dimension:
                    print(0)
                    now_position[i] = now_position[i]+1
                    if now_position not in go_can:
                        now_position[i] = now_position[i]-1
                    elif now_position in go_can:
                        #print("----num----",route_stock_num)
                        if can_go_count+route_stock_num[route_stock.index(bevor_position)] == next_num[go_can.index(bevor_position)]:
                            route_stock_num[route_stock.index(bevor_position)]-=1
                            print("---pos----",now_position,"-----",route_stock_num[route_stock.index(bevor_position)])
                            if route_stock_num[route_stock.index(bevor_position)]==0:
                                if next_num[go_can.index(now_position)]==1 or (now_position in route):
                                    now_position[i] = now_position[i]-1
                                    can_go_count += 1
                                    route_stock_num.pop(route_stock.index(bevor_position))
                                    route_stock.remove(bevor_position)
                                    print("heir---")
                                    print(route)
                                    break
                                else:
                                    route_stock_num.pop(route_stock.index(bevor_position))
                                    route_stock.remove(bevor_position)
                                    route.append(copy.deepcopy(now_position))
                                    print(route)
                                    print("oooo")
                                    break
                            elif next_num[go_can.index(now_position)]==1 or (now_position in route):
                                print("hello",now_position)
                                now_position[i] = now_position[i]-1
                                can_go_count += 1
                                print(4)
                                break
                            else:
                                route.append(copy.deepcopy(now_position))
                                print("3",route)
                                break
                        elif can_go_count+route_stock_num[route_stock.index(bevor_position)] != next_num[go_can.index(bevor_position)]:
                            can_go_count+=1
                            now_position[i] = now_position[i]-1

                if i==2:
                    print("this")
                    now_position = copy.deepcopy(route_stock[-1])
                    del route[route.index(now_position)+1:]
                    break
            i+=1
            print(route)
            #print("-----")
           # print(route_stock)
            #time.sleep(0.05)
        #print("----all------",route_all)
        if now_position == goout:
            route_all.append(copy.deepcopy(route))
            print("---all----",route_all)
            #print(route_stock)
            if len(route_stock)!=0:
                now_position = copy.deepcopy(route_stock[-1])
                del route[route.index(now_position)+1:]
            elif len(route_stock) == 0:
                exit()
            break
    if len(route_stock)==1:
        print(route_stock)
        break




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
    lines = ax1.plot3D(route[:,0]+abgleich,route[:,1]+abgleich,route[:,2]+abgleich)
    plt.savefig("migong"+str(abgleich)+".jpg")
    ax1.lines.remove(lines[0])
    #print(ax1.lines)
    abgleich+=0.01
#plt.savefig("migong"+str(abgleich)+".jpg")
#plt.show()


