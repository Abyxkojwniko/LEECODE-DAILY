# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergetwo(self,l1:Optional[ListNode],l2:Optional[ListNode])->Optional[ListNode]:
        cur=dummy=ListNode()
        while l1 and l2:
            if l1.val<l2.val:
                cur.next=l1
                l1=l1.next
            else:
                cur.next=l2
                l2=l2.next
            cur=cur.next
        cur.next=l1 if l1 else l2
        return dummy.next
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        length=len(lists)
        if length==0:
            return None
        if length==1:
            return lists[0]
        left=self.mergeKLists(lists[:length//2])
        right=self.mergeKLists(lists[length//2:])
        return self.mergetwo(left,right)