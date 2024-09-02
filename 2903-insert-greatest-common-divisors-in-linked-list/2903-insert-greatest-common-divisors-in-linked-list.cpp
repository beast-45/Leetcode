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
    int gcd(int a , int b)
    {
        if(a==0) return b;
        if(b==0) return a;
        if(a==b) return a;
        if(a>b) return gcd(a-b , b);
        return gcd(a , b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev =  head;
        ListNode* temp = head->next;

        while(temp != NULL)
        {
            ListNode* gcdNode =  new ListNode(gcd(prev->val,temp->val));
            ListNode* nxtNode = temp->next;
            prev->next = gcdNode;
            gcdNode->next =  temp;
            prev = temp;
            temp = nxtNode;
        }
        return head;
        
    }
};