# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def findmid(self,head:Optional[ListNode])->Optional[ListNode]:
        slow=fast=head
        while fast and fast.next:
            pre=slow
            slow=slow.next
            fast=fast.next.next
        pre.next=None
        return slow
    def merge(self,list1:Optional[ListNode],list2:Optional[ListNode])->Optional[ListNode]:
        cur=dummy=ListNode()
        while list1 and list2:
            if list1.val<list2.val:
                cur.next=list1
                list1=list1.next
            else:
                cur.next=list2
                list2=list2.next
            cur=cur.next
        cur.next=list1 if list1 else list2
        return dummy.next
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        head2=self.findmid(head)
        head=self.sortList(head)
        head2=self.sortList(head2)
        return self.merge(head,head2)