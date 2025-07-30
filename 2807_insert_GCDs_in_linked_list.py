from typing import Optional
import math

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def array_to_linked_list(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    current = head

    for value in arr[1:]:
        current.next = ListNode(value)
        current = current.next

    return head

def display(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

arr = [18,6,10,3]
head = array_to_linked_list(arr)
display(head)

class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head

        while curr and curr.next:
            gcd = math.gcd(curr.val, curr.next.val)
            new_node = ListNode(gcd)
            new_node.next = curr.next
            curr.next = new_node
            curr = new_node.next
        
        return head

s = Solution()
output = s.insertGreatestCommonDivisors(head)
display(output)