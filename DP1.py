#1.Define the subproblem.
#2.Create recurrence relation to solve the subproblem.
#3.Solve the base cases.
#Q.No. of ways to write 'n' as a sum of 1,3,4.
n=int(input())
a = [0]*(n+1)
a[0]=1
a[1]=1
a[2]=1
a[3]=2
for i in range(4,n+1):
    a[i] = a[i-1]+a[i-3]+a[i-4]
print(a[n])
