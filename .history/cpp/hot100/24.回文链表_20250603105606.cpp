/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head) {
        ListNode *pre=nullptr;
        ListNode *p=head;
        while(p){
            ListNode *next=p->next;
            p->next=pre;
            pre=p;
            p=next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode *mid=middle(head);
        ListNode *head2=reverse(mid);
        while(head2){
            if(head2->val!=head->val) return false;
            else{
                head2=head2->next;
                head=head->next;
            }
        }
        return true;
    }
};