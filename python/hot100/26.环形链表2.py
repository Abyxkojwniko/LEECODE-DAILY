class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow=fast=head
        while fast and fast.next:
            fast=fast.next.next
            slow=slow.next
            if fast is slow:
                while head is not fast:
                    head=head.next
                    fast=fast.next
                return fast
        return None