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
    ListNode* reverseLL(ListNode* head) {
        ListNode *pre = NULL, *curr = head, *front, *newHead;
        while (curr) {
            front = curr->next;
            curr->next = pre;
            pre = curr;
            curr = front;
        }
        newHead = pre;
        return newHead;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode *newHead, *curr, *tempHead, *mover;
        newHead = reverseLL(head);
        int maxx = newHead->val;
        ListNode* newNode = new ListNode(-1);
        tempHead = newNode;
        curr = newHead;
        while (curr) {
            if (curr->val >= maxx) {
                mover = new ListNode(curr->val);
                maxx = curr->val;
                tempHead->next = mover;
                tempHead = mover;
            }
            curr = curr->next;
        }
        return reverseLL(newNode->next);
    }
};