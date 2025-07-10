class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *pre=dummy;
        ListNode *lat=head;
        while(lat){
            ListNode *check=lat;
            for(int i=0;i<k;i++){
                if(!check) return dummy->next;
                check=check->next;
            }
            ListNode *tail=lat;
            for(int i=0;i<k-1;i++){
                ListNode *temp=lat->next;
                lat->next=temp->next;
                temp->next=pre->next;
                pre->next=temp;
            }
            pre=tail;  
            lat=pre->next;
        }
        return dummy->next;
    }
};