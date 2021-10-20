import numpy as np
A = input()
B = input()
D = [[0 for i in range(len(B)+1)]for j in  range(len(A)+1)]
for i in range(1,len(A)+1):
    for j in range(1,len(B)+1):
        if(A[i-1]==B[j-1]):
            D[i][j]=1+D[i-1][j-1]
        else:
            D[i][j] = max(D[i-1][j],D[i][j-1])
i = len(A)
j = len(B)
E=[]
while(j!=0):
    if(D[i][j]==D[i][j-1]):
        j=j-1
    elif(D[i][j]==D[i-1][j-1]+1):
        E.append(A[i-1])
        i = i-1
        j = j-1
print(np.array(D))
print(''.join(reversed(E)))
