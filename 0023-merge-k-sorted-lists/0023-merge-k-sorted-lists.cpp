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
    ListNode* mergeTwoLL(ListNode* L1 , ListNode* L2){
        if(!L1) return L2;
        if(!L2) return L1;
        ListNode* result;
        if(L1->val <= L2->val){
            result = L1;
            result->next = mergeTwoLL(L1->next,L2);
        }else{
            result = L2;
            result->next = mergeTwoLL(L1,L2->next);
        }
        return result;
    }
    ListNode* provideTwoLL(int start , int end , vector<ListNode*> &lists){
        if(start > end) return NULL;
        if(start == end) return lists[start];
        int mid =  start+(end-start)/2;
        ListNode* L1 = provideTwoLL(start,mid,lists);
        ListNode* L2 = provideTwoLL(mid+1,end,lists);
        return mergeTwoLL(L1,L2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        return provideTwoLL(0,n-1,lists);
    }
};