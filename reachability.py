col=4
row=4
class queue:
    def __init__(self):
        self.top = 0
        self.tail = -1
        self.items = []
    def enqueue(self,item):
        self.items.insert(0,item)
        self.top+=1
    def dequeue(self):
        print(self.items.pop())
q = queue()
mark = [[0 for j in range(col)] for i in range(row)]
def check(i,j):
    mark[i][j] = 1
    if(mark[i-1][j]==0 and abs(A[i][j]-A[i-1][j])>=10):
        q.enqueue([i-1,j])
        check(i-1,j)
    elif(mark[i+1][j]==0 and abs(A[i][j]-A[i+1][j])>=10):
        q.enqueue([i+1,j])
        check(i+1,j)
    elif(mark[i][j-1]==0 and abs(A[i][j]-A[i][j-1])>=10):
        q.enqueue([i,j-1])
        check(i,j-1)
    elif(mark[i][j+1]==0 and abs(A[i][j]-A[i][j+1])>=10):
        q.enqueue([i,j+1])
        check(i,j+1)
    q.pop()
A = [[] for i in range(col)]
for i in range(row):
    A[i] = [int(j) for j in input().split()]
check(3,3)
        
    
