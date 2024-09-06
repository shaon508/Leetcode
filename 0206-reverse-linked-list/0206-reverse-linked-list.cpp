class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *temp = head, *front;
        while (temp) {
            front = temp->next;
            temp->next = pre;
            pre = temp;
            temp = front;
        }
        return pre;
    }
};