# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        def merge(l1, l2):
            if(l1 and l2):
                if(l1.val < l2.val):
                    n = ListNode(l1.val)
                    l1 = l1.next
                else:
                    n = ListNode(l2.val)
                    l2 = l2.next
            elif l1:
                    n = ListNode(l1.val)
                    l1 = l1.next
            elif l2:
                    n = ListNode(l2.val)
                    l2 = l2.next
            else:
                return None

            next_node = merge(l1, l2)

            if(next_node):
                 n.next = next_node

            return n
        return merge(l1, l2)
