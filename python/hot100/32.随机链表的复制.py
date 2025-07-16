class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return None
        nodedict={}
        cur=head
        while cur:
            nodedict[cur]=Node(cur.val)
            cur=cur.next
        cur=head
        while cur:
            clone=nodedict[cur]
            clone.next=nodedict.get(cur.next)
            clone.random=nodedict.get(cur.random)
            cur=cur.next
        return nodedict[head]
class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        cur=head
        while cur:
            cur.next=Node(cur.val,cur.next)
            cur=cur.next.next
        cur=head
        while cur:
            if cur.random:
                cur.next.random=cur.random.next
            cur=cur.next.next
        cur=head.next
        while cur.next:
            cur.next=cur.next.next
            cur=cur.next
        return head.next