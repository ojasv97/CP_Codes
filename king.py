import numpy as np
def get(x,y,N):
  if(x<0 or y<0 or x>N-1 or y>N-1):
    return
  if(L[x][y]==2):
    return
  L[x][y]=0
N = int(input())
L = np.array([[1]*N]*N)
K = int(input())
k =[]
for i in range(K):
  k.append([int(i) for i in input().split()])
R = int(input())
r = []
for i in range(R):
  r.append([int(i) for i in input().split()])
for i in range(R):
  L[r[i][0]][r[i][1]]=2
B = int(input())
b = []
for i in range(B):
  b.append([int(i) for i in input().split()])
for i in range(B):
  L[b[i][0]][b[i][1]]=2
Q = int(input())
q=[]
for i in range(Q):
  q.append([int(i) for i in input().split()])
for i in range(Q):
  L[q[i][0]][q[i][1]]=2
for i in range(K):
  L[k[i][0]][k[i][1]]=2
  get(k[i][0]+1,k[i][1]+2,N)
  get(k[i][0]+2,k[i][1]+1,N)
  get(k[i][0]+2,k[i][1]-1,N)
  get(k[i][0]+1,k[i][1]-2,N)
  get(k[i][0]-1,k[i][1]-2,N)
  get(k[i][0]-2,k[i][1]-1,N)
  get(k[i][0]-2,k[i][1]+1,N)
  get(k[i][0]-1,k[i][1]+2,N)
for i in range(R):
  row = r[i][0]
  col = r[i][1]
  for j in range(col-1,-1,-1):
    if(L[row][j]==2):
      break
    get(row,j,N)
  for j in range(col+1,N):
    if(L[row][j]==2):
      break
    get(row,j,N)
  for j in range(row+1,N):
    if(L[j][col]==2):
      break
    get(j,col,N)
  for j in range(row-1,-1,-1):
    if(L[j][col]==2):
      break
    get(j,col,N)
for i in range(B):
  row = b[i][0]
  col = b[i][1]
  p = min(row,N-col-1)
  z = min(N-row-1,N-col-1)
  x = min(N-row-1,col)
  s = min(row,col)
  for j in range(1,p+1):
    if(L[row-j][col+j]==2):
      break
    get(row-j,col+j,N)
  for j in range(1,z+1):
    if(L[row+j][col+j]==2):
      break
    get(row+j,col+j,N)
  for j in range(1,x+1):
    if(L[row+j][col-j]==2):
      break
    get(row+j,col-j,N)
  for j in range(1,s+1):
    if(L[row-j][col-j]==2):
      break
    get(row-j,col-j,N)
for i in range(Q):
  row = q[i][0]
  col = q[i][1]
  m = min(row,N-col-1)
  n = min(N-row-1,N-col-1)
  o = min(N-row-1,col)
  t = min(row,col)
  for j in range(1,m+1):
    if(L[row-j][col+j]==2):
      break
    get(row-j,col+j,N)
  for j in range(1,n+1):
    if(L[row+j][col+j]==2):
      break
    get(row+j,col+j,N)
  for j in range(1,o+1):
    if(L[row+j][col-j]==2):
      break
    get(row+j,col-j,N)
  for j in range(1,t+1):
    if(L[row-j][col-j]==2):
      break
    get(row-j,col-j,N)
  for j in range(col-1,-1,-1):
    if(L[row][j]==2):
      break
    get(row,j,N)
  for j in range(col+1,N):
    if(L[row][j]==2):
      break
    get(row,j,N)
  for j in range(row+1,N):
    if(L[j][col]==2):
      break
    get(j,col,N)
  for j in range(row-1,-1,-1):
    if(L[j][col]==2):
      break
    get(j,col,N)
count = np.count_nonzero(L)-(K+R+B+Q)
print(count,end="")
print(L)
