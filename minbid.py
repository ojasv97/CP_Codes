import string
L = [i for i in input().split()]
dic = dict(zip([str(i) for i in range(0,10)],[int(i) for i in range(0,10)]))
dic.update(dict(zip(string.ascii_uppercase, range(10,36))))
L = [list(i) for i in L]
max_val = []
val = []
value=0
m=0
for i in L:
    m=0
    for j in i:
        if(dic[j]>m):
            m=dic[j]
    max_val.append(m+1)
p = 0
for i in range(len(L)):
    value=0
    p = len(L[i])-1
    for j in range(len(L[i])):
        value =value + (max_val[i]**p)*int(dic[(L[i][j])])
        p=p-1
    val.append(value)
print(min(val),end = "")
