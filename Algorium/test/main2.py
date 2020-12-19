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
route = [].append(copy.deep(goin))
route_all = []

def go_up(now_position):
    global go_can
    global color
    if now_position[i]-1>=0 and now_position[i]-1<dimension and now_position[i]-1!=bevor_position[i]:
        middle_position = copy.deepcopy(now_position)
        now_position[i]  = now_position[i]-1
        if now_position in go_can and now_position not in route:
            route.append(copy.deepcopy(now_position))
            bevor_position = copy.deepcopy(middle_position)
            #print(route)
            break
        else:
            now_position[i] = now_position[i]+1




