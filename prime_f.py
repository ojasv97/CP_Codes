a, b= [int(x) for x in input().split()]
p=[]
for i in range(a, b+1):
    count=0
    for j in range(1,(i//2)+1):
        if i%j==0:
            count+=1
    if count==1:
        p.append(i)
n=[int((str(x)+str(y))) for x in p for y in p]
q=[]
for i in n:
    count=0
    for j in range(1,(i//2)+1):
        if i%j==0:
            count+=1
    if count==1:
        q.append(i)
q.sort()
min_=min(q)
max_=max(q)
q = list(set(q))
count=len(q)
fib=[]
i = 0
f = min_
s = max_
for i in range(count):
    if i<=1:
        n=i
    else:
        n=f+s
        f=s
        s= n
    fib.append(n)
print(fib[-1],end="")
