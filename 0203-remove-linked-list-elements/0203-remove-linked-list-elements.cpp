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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp = new ListNode(-1), *h, *kk;
        h = temp;
        temp->next = head;
        temp = h;
        while (temp->next) {
            if (temp->next->val == val) {
                kk = temp->next;
                temp->next = temp->next->next;
                delete kk;
            }
            else
            {
                temp = temp->next;
            }
        }
        return h->next;
    }
};