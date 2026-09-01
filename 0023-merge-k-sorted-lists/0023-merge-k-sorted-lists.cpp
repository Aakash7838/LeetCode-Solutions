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

        // Min Heap: {value, node}
        priority_queue<pair<int, ListNode*>,
                       vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>> minPQ;

        // Step 1: Har list ka pehla node
        for(int i = 0; i < (int)lists.size(); i++){
            if(lists[i] != nullptr){
                minPQ.push({lists[i]->val, lists[i]});
            }
        }

        // Dummy node
        ListNode dummy(0);
        ListNode* curr = &dummy;

        // Step 2: Merge
        while(!minPQ.empty()){
            auto [val, node] = minPQ.top();
            minPQ.pop();

            // Result mein add karo
            curr->next = node;
            curr = curr->next;

            // Step 3: Agla node us list se
            if(node->next != nullptr){
                minPQ.push({node->next->val, node->next});
            }
        }

        return dummy.next;
    }
};