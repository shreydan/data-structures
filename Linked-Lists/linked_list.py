class LinkedList:
    class ListNode:
        def __init__(self, val=0, next=None) -> None:
            self.val = val
            self.next = next
    
    def __init__(self):
        self.head = None

    def add(self, val):
        node = self.ListNode(val)
        if self.head is None:
            self.head = node
            node.next = None
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = node
    
    def traverse(self):
        temp = self.head
        while temp is not None:
            print(f"{temp.val} ->", end=' ')
            temp = temp.next
        print("[X]")



l1 = LinkedList()
l1.add(2)
l1.add(4)
l1.add(3)

l2 = LinkedList()
l2.add(5)
l2.add(6)
l2.add(4)

l1.traverse()
l2.traverse()