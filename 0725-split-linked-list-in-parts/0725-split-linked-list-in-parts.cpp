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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int L = 0;
        while(curr)
        {
            L++;
            curr = curr->next;
        }
        int EachBucketNodes = L/k;
        int remNodes = L%k;

        vector<ListNode*> result(k , NULL);
        curr = head;
        ListNode* prev = NULL;

        for(int i=0 ; curr != NULL && i<k ; i++)
        {
            result[i] = curr;
            for(int count=0 ; count<EachBucketNodes + (remNodes>0 ? 1 : 0) ; count++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            remNodes--;
        }
        return result;

        
    }
};