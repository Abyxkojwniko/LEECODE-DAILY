class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Map<Node,Node> map=new HashMap<>();
        Node curr=head;
        while(curr){
            map.put(curr,new Node(curr.val));
            curr=curr->next;
        }
        curr=head;
        while(curr){
            Node clone=map.get(curr);
            clone->next=map.get(curr->next);
            clone->random=map.get(curr->random);
            curr=curr->next;
        }
        return map.get(head);
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        for(Node* cur=head;cur;cur=cur->next->next){
            cur->next=new Node(cur->val,cur->next,nullptr);
        }
        for(Node *cur=head;cur;cur=cur->next->next){
            if(cur->random) cur->next->random=cur->random->next;
        }
        Node *new_head=head->next;
        Node *cur=head;
        for(;cur->next->next;cur=cur->next){
            Node *copy=cur->next;
            cur->next=copy->next;
            copy->next=copy->next->next;
        }
        cur->next=nullptr;
        return new_head;
    }
};