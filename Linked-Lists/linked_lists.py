"""
Linked Lists in Python
- gaddam shreyas daniel
"""


class Node:
    def __init__(self,value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        