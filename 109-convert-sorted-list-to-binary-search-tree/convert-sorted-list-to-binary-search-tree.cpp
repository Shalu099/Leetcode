class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle node (slow will be at mid)
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect left half
        if (prev) prev->next = nullptr;

        // slow is root
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST((slow == head) ? nullptr : head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
