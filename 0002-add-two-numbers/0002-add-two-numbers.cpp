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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL || l2 == NULL) {
            if (l1 == NULL && l2 == NULL)
                return NULL;
            else if (l1 == NULL)
                return l2;
            else
                return l1;
        }
        ListNode *ans = new ListNode(-1), *listOne = l1, *listTwo = l2, *temp,
                 *mover;
        temp = ans;
        int sum = 0, carry = 0;
        while (listOne && listTwo) {
            sum = (listOne->val + listTwo->val + carry);
            mover = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = mover;
            temp = mover;
            listOne = listOne->next;
            listTwo = listTwo->next;
        }
        while (listOne) {
            sum = (listOne->val + carry);
            mover = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = mover;
            temp = mover;
            listOne = listOne->next;
        }
        while (listTwo) {
            sum = (listTwo->val + carry);
            mover = new ListNode(sum % 10);
            carry = sum / 10;
            temp->next = mover;
            temp = mover;
            listTwo = listTwo->next;
        }
        if (carry > 0) {
            temp->next = new ListNode(carry);
        } 
        return ans -> next;
    }
    // ListNode *kk = ans;
   // ans = ;
   // delete kk;
   
};