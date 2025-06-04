class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        map=set()
        p=head
        while p:
            if p in map:
                return True
            map.add(p)
            p=p.next
        return False
    
