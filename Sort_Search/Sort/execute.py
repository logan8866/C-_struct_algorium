import matplotlib.pyplot as plt
import numpy as np

def draw_O(filename):
    list_0 = [[],[],[],[],[]]
    i = 0
    with open(filename,"r") as f:
        while True:
            if i==5:
                break
            str_1 = f.readline()
            if len(str_1)<2:
                break
            list_1 = str_1.split(",")
            for m in list_1:
                list_0[i].append(eval(m))
            i+=1
    #print(list_0)
    y = np.array(list_0)
    compare_time = y[:,0]
    execute_time = y[:,1]
    move_time = y[:,2]
    return [compare_time,execute_time,move_time]


is_list = draw_O("is.txt")
ss_list = draw_O("ss.txt")
ms_list = draw_O("ms.txt")
cs_list = draw_O("cs.txt")
rs_list = draw_O("rs.txt")
x = np.array([100,200,300,1000,2000])

p1 = plt.subplot(2,2,1)
p1.plot(x,is_list[0],x,ss_list[0],x,ms_list[0],x,cs_list[0],x,rs_list[0])
p2 = plt.subplot(2,2,2)
p2.plot(x,is_list[1],x,ss_list[1],x,ms_list[1],x,cs_list[1],x,rs_list[1])
p3 = plt.subplot(2,2,3)
p3.plot(x,is_list[2],x,ss_list[2],x,ms_list[2],x,cs_list[2],x,rs_list[2])
plt.show()



