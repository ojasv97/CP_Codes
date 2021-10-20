class node:
    def __init__(self,data):
        self.data = data
        self.next = None
    def setD(self,new):
        self.data = new
    def setN(self,new):
        self.next = new
class List:
    def __init__(self):
        self.head = None
    def add(self,data):
        temp = Node(data)
        if(self.head==None):
            self.head = temp
        else:
            val = self.he
