class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *tail=head;
        int flag=0;
        while(l1||l2||flag){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            int total=val1+val2+flag;
            flag=total/10;
            total=total%10;
            tail->next=new ListNode(total);
            tail=tail->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return head->next;
    }
};