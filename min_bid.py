import string
L=list(map(str, input().split()))
def bases(L):
    dic = dict(zip([str(i) for i in range(0,10)],[int(i) for i in range(1,11)]))
    dic.update(dict(zip(string.ascii_uppercase, range(11,37))))
    base=[]
    for i in L:
        b=[]
        for j in i:
            b.append(dic[j])
        base.append(max(b))
    return base
p=bases(L)
def bid(L):
    dic = dict(zip([str(i) for i in range(0,10)],[int(i) for i in range(0,10)]))
    dic.update(dict(zip(string.ascii_uppercase, range(10,36))))
    bid=[]
    for i in range(len(L)):
        x=L[i]
        a=x[::-1]
        b=0
        for j in range(len(a)):
            b+=(dic[a[j]])*(p[i]**j)
        bid.append(b)
    return min(bid)
result=bid(L)
print(result)
