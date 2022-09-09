class LinkedList:

    class Node:
        def __init__(self, val=0, next=None):
            self.val = val
            self.next = next
    
    def __init__(self):
        self.length = 0
        self.head = None
        
    def traverse(self):
        temp = self.head
        while temp != None:
            print(temp.val)
            temp = temp.next
        

    def get(self, index: int) -> int:
        if index > self.length - 1 or index < 0:
            return -1
        
        temp = self.head
        while index != 0:
            temp = temp.next
            index -= 1
            
        if temp is not None:
            return temp.val
        else:
            return -1

            
    def reverse(self):
        current = self.head
        prev = None
        while current is not None:
            nextNode = current.next
            current.next = prev
            prev = current
            current = nextNode
        self.head = prev
        


    def addAtHead(self, val: int) -> None:
        node = self.Node(val)
        node.next = self.head
        self.head = node
        
        self.length += 1

    def addAtTail(self, val: int) -> None:
        if self.head is None:
            self.addAtHead(val)
        else:
            node = self.Node(val) 
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = node
            node.next = None
            
        self.length +=1
            

    def addAtIndex(self, index: int, val: int) -> None:
        if index == 0:
            self.addAtHead(val)
        elif index > self.length or index < 0:
            return
        elif index == self.length:
            self.addAtTail(val)
        else:
            temp = self.head
            while index != 1:
                temp = temp.next
                index -= 1
            node = self.Node(val)
            node.next = temp.next
            temp.next = node
            self.length += 1
            

    def deleteAtIndex(self, index: int) -> None:
        prev = None
        temp = self.head
        
        if index == 0:
            self.head = self.head.next
        elif index > self.length - 1 or index < 0:
            return
        else:
            while index != 0:
                prev = temp
                temp = temp.next
                index -= 1
            prev.next = temp.next
            
        self.length -= 1