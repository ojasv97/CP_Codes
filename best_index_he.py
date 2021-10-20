a = [int(i) for i in range(1,450)]
for i in range(1,len(a)):
    a[i]=a[i-1]+a[i]
def ind(i,n):
    j=0
    while(i+a[j+1]<=n+1):
        j+=1
    return a[j]
N = int(input())
L = [0]+[int(i) for i in input().split()]
l = [0]
l.append(L[1])
val=[]
for i in range(2,N+1):
    l.append(L[i]+l[i-1])
t=0
for i in range(1,N+1):
    t = ind(i,N)
    val.append(l[i-1+t]-l[i]+L[i])
print(max(val))
    
         
    

