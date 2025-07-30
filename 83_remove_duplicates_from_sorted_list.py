from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Fixed: Return new head
def prepend(head, data):
    new_node = ListNode(data)
    new_node.next = head
    return new_node  # return the new head

def display(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

# Reassign head each time
head = ListNode(5)
head = prepend(head, 3)
head = prepend(head, 3)
head = prepend(head, 2)
head = prepend(head, 1)
head = prepend(head, 1)

display(head)

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head

        while curr and curr.next:
            if curr.val == curr.next.val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return head

s = Solution()
head1 = s.deleteDuplicates(head)

display(head1)