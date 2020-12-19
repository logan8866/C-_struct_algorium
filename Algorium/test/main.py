import numpy as np
import copy
import time

goin = [0,0,0]
goout = [3,3,3]
dimension = 4
color = np.zeros((dimension,dimension,dimension))
go_can = [[0,0,0],[0,1,0],[0,1,1],[1,1,1],[1,1,2],[1,2,2],[1,3,2],[2,3,2],[3,3,2],[3,3,3],[2,1,1],[0,3,2],[2,2,2]]
#go_can = np.array(go_can)
for i in go_can:
    color[i[0],i[1],i[2]] = 1
route = [goin]
route_all = []
now_position = copy.deepcopy(goin)
bevor_position = copy.deepcopy(goin)
middle_position = None
i = 0
while(True):
    i = 0
    if (now_position==goout):
        break
    while(i<3):
        print(i)
        if now_position[i]-1>=0 and now_position[i]-1<dimension and now_position[i]-1!=bevor_position[i]:
            middle_position = copy.deepcopy(now_position)
            now_position[i]  = now_position[i]-1
            #bevor_position[i] = bevor_position[i]-1
            if now_position in go_can and now_position not in route:
                route.append(copy.deepcopy(now_position))
                bevor_position = copy.deepcopy(middle_position)
                break
            else:
                now_position[i] = now_position[i]+1
                #bevor_position[i] = bevor_position[i]+1

        if now_position[i]+1>=0 and now_position[i]+1<dimension and now_position[i]+1!=bevor_position[i]:
            middle_position = copy.deepcopy(now_position)
            now_position[i]  = now_position[i]+1
            #bevor_position[i] = bevor_position[i]+1
            if now_position in go_can and now_position not in route:
                route.append(copy.deepcopy(now_position))
                bevor_position = copy.deepcopy(middle_position)
                break
            else:
                now_position[i] = now_position[i]-1
                #bevor_position[i] = bevor_position[i]-1
        i+=1
        if (i==3):
            print(now_position)
            go_can.remove(now_position)
            route.pop()
            now_position = copy.deepcopy(bevor_position)
            bevor_position = copy.deepcopy(route[-2])
        print(route)
        time.sleep(0.5)
        
print(route)


