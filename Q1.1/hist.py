import numpy as np
import matplotlib.pyplot as plt
f=open('Output.txt',"r")

barWidth = 0.25
fig = plt.subplots(figsize =(12, 8))

other=[]
rr=[]
fifo=[]
a=1
for i in f.readlines():
    if(a%2==0):
        rr.append(i)
    elif(a%3==0):
        fifo.append(i)
    else:
        other.append(i)
    a+=1

br1 = np.arange(len(other))
br2 = [x + barWidth for x in br1]
br3 = [x + barWidth for x in br2]

plt.bar(br1, other, color ='r', width = barWidth,
        edgecolor ='black', label ='SCHED_OTHER')
plt.bar(br2, rr, color ='g', width = barWidth,
        edgecolor ='black', label ='SCHED_RR')
plt.bar(br3, fifo, color ='b', width = barWidth,
        edgecolor ='black', label ='SCHED_FIFO')
 
plt.xlabel('Priorities', fontweight ='bold', fontsize = 15)
plt.ylabel('Time_taken', fontweight ='bold', fontsize = 15)
plt.xticks([r + barWidth for r in range(len(other))],
        ['def', 'p1', 'p2', 'p3', 'p4','p5','p6'])
 
plt.legend()
plt.show()