class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* last = head;
        int totalNodes = 1;
        while (last->next != nullptr) {
            totalNodes++;
            last = last->next;
        }
        k %= totalNodes;
        if (k == 0) return head;
        int totalNodesMinusK = totalNodes - k;
        ListNode* curr = head;
        while (totalNodesMinusK > 1) {
            curr = curr->next;
            totalNodesMinusK--;
        }
        ListNode* newHead = curr->next;
        curr->next = nullptr;
        last->next = head;
        return newHead;
    }
};
