class Solution {

public:

ListNode* reverseList(ListNode* head) {

if(head == nullptr || head->next == nullptr) return head;

ListNode* node = head->next;

ListNode* prev = head;
prev->next = nullptr;

ListNode* NEXT = node->next;



while(node && NEXT){

node->next = prev;

prev = node;

node = NEXT;

NEXT = node->next;

}

node->next = prev;

return node;

}

};