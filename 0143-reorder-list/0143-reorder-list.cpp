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
    ListNode *reverse(ListNode *head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev; 
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* last = reverse(slow);
        slow->next = NULL;
        ListNode* curr = head;
        while(last->next){
            ListNode* currNext = curr->next;
            curr->next = last;
            ListNode* lastNext = last->next;
            last->next = currNext;
            curr = currNext;
            last = lastNext;
        }
    }
};