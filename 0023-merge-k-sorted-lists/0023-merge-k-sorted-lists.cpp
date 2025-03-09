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
    ListNode* merge2Lists(ListNode *L1 , ListNode* L2){
        if(!L1) return L2;
        if(!L2) return L1;
        ListNode* result;
        if(L1->val < L2->val){
            result = L1;
            result->next = merge2Lists(L1->next,L2);
        }
        else{
            result = L2;
            result->next = merge2Lists(L1,L2->next);
        }
        return result;
    }
    ListNode* provide2Lists(int start , int end , vector<ListNode*> &lists){
        if(start > end){
            return NULL;
        }
        if(start == end){
            return lists[start];
        }
        int mid = start + (end - start) / 2;
        ListNode* L1 = provide2Lists(start , mid , lists);
        ListNode* L2 = provide2Lists(mid+1 , end , lists);
        return merge2Lists(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0){
            return NULL;
        }
        return provide2Lists(0 , n-1 , lists);
    }
};