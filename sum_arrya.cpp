// Build a linked list from a vector  {2, 4, 3} → 2→4→3
ListNode* build(std::vector<int> digits) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int d : digits) {
        cur->next = new ListNode(d);
        cur = cur->next;
    }
    return dummy.next;
}

// Print linked list
void print(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << "\n";
}

// Free memory
void freeList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 342 + 465 = 807
    ListNode* l1 = build({2, 4, 3});
    ListNode* l2 = build({5, 6, 4});

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    print(result);   // Output: 7 -> 0 -> 8

    freeList(l1);
    freeList(l2);
    freeList(result);
    return 0;
}