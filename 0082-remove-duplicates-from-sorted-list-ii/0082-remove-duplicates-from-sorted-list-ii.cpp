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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *pre = NULL;
        int temp;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                temp = curr->val;
                while (curr && curr->val == temp) {
                    curr = curr->next;
                }
                if (pre == NULL) {
                    head = curr;
                } else {
                    pre->next = curr;
                }
            } else {
                pre = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};