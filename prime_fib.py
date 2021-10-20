a, b = [int(x) for x in input().split()]
p=[]
for i in range(a, b+1):
    count=0
    for j in range(1,(i//2)+1):
        if i%j==0:
            count+=1
    if count==1:
        p.append(i)
n=[int((str(x)+str(y))) for x in p for y in p if x!=y]
print(n)
d=[]
for i in n:
    count=0
    for j in range(1,(i//2)+1):
        if i%j==0:
            count+=1
    if count==1:
        d.append(i)
d = set(d)
d = list(d)
count = len(d)
print(count)
min_ = min(d)
max_ = max(d)
arr = [0]*count
arr[0]=min_
arr[1]=max_
i = 2
while(i<count):
    arr[i] = arr[i-1]+arr[i-2]
    i+=1
print(arr[count-1]%2**63,end="")
    
