class Node:
    def __init__(self, data, child=None):
        self.data = data
        self.child = child
    def __str__(self):
        return str(self.child)
    
tree = Node(1,[Node(2,[Node(3,[]),Node(4,[])]),Node(5,[Node(6,[]),Node(7,[])])])

def fun(tr):
    if (tr.child == []):
        print(tr.data)
    for i in tr.child:
        print(str(tr.data)+"-->",end = " ")
        fun(i)
fun(tree)
