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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minHeap;
        for(ListNode* head : lists){
            if(head) minHeap.push({head->val,head});
        }

        ListNode dummy(0);
        ListNode* head = &dummy;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top().second;
            head->next = temp;
            head = head->next;
            minHeap.pop();
            if(temp->next) minHeap.push({temp->next->val,temp->next});
        }

        head->next = nullptr;
        return dummy.next;
    }
};
