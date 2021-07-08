# Your task is to complete this function

'''

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''


class Solution:
    
    #Function to rotate a linked list.
    def rotate(self, head, k):
        # code here
        if k == 0:
            return head
         
        # Let us understand the below code for example k = 4
        # and list = 10->20->30->40->50->60
        current = head
         
        # current will either point to kth or NULL after
        # this loop
        # current will point to node 40 in the above example
        count = 1
        while(count <k and current is not None):
            current = current.next
            count += 1
     
        # If current is None, k is greater than or equal
        # to count of nodes in linked list. Don't change
        # the list in this case
        if current is None:
            return head
 
        # current points to kth node. Store it in a variable
        # kth node points to node 40 in the above example
        kthNode = current
     
        # current will point to lsat node after this loop
        # current will point to node 60 in above example
        while(current.next is not None):
            current = current.next
 
        # Change next of last node to previous head
        # Next of 60 is now changed to node 10
        current.next = head
         
        # Change head to (k + 1)th node
        # head is not changed to node 50
        head = kthNode.next
 
        # change next of kth node to NULL
        # next of 40 is not NULL
        kthNode.next = None
        return head


#{ 
#  Driver Code Starts
# driver

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def insert(self,val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next

def printList(n):
    while n:
        print(n.data, end=' ')
        n = n.next
    print()

if __name__=="__main__":
    for _ in range(int(input())):
        n = int(input())
        arr = [int(x) for x in input().split()]
        k = int(input())
        
        lis = LinkedList()
        for i in arr:
            lis.insert(i)
        
        head = Solution().rotate(lis.head,k)
        printList(head)
# } Driver Code Ends