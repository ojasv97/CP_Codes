# cook your dish here
import math
i=1
while(i!=0):
    t = input()
    k=[]
    if(int(t)<=10):
        k.append(t)
        k.append(str(10-int(t)))
        print("".join(k))
        continue
    p = t[-1]
    l = [int(i) for i in t]
    count = sum(l)
    val = math.ceil(count/10)*10 - count
    l.append(val)
    l = [str(i) for i in l]
    print("".join(l))
    i=i+1
