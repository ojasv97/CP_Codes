def build(arr,tree,start,end,node):
    if(start==end):
        tree[node]=arr[start]
        return tree[node]
    mid = (start+end)//2
    tree[node]=build(arr,tree,start,mid,2*node)+ build(arr,tree,mid+1,end,(2*node)+1)
    return tree[node]
arr = [1,2,3,4,5,6,7]
tree = [0]*(2*(len(arr))+2)
build(arr,tree,0,6,1)
print(tree)
