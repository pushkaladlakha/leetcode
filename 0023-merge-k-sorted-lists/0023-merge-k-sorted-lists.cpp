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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare> pq;
        for(auto i : lists){
            if(i) pq.push(i);
        }
        ListNode* st = new ListNode(-1);
        ListNode* ans = st;
        while(!pq.empty()){
            if(pq.top()->next){pq.push(pq.top()->next);}
            st->next=pq.top();
            st=st->next;
            pq.pop();
        }
        return ans->next;
    }

};