#include <iostream>
#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

// Solution class containing the function to copy the list.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        std::unordered_map<Node*, Node*> old_to_new;

        Node* curr = head;
        while (curr) {
            old_to_new[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head; 
        while(curr) {
            old_to_new[curr]->next = old_to_new[curr->next];
            old_to_new[curr]->random = old_to_new[curr->random];
            curr = curr->next; 
        }
        return old_to_new[head];
    }
};

// Test function to create a sample linked list and run the solution.
int main() {
    // Create a simple linked list for testing: 1 -> 2 -> 3 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Set random pointers for testing.
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head;       // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    // Instantiate the Solution and copy the list.
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    // Print the values and random pointers of the copied list for verification.
    Node* curr = copiedList;
    while (curr) {
        std::cout << "Node value: " << curr->val << "\n";
        if (curr->random)
            std::cout << "Random points to: " << curr->random->val << "\n";
        else
            std::cout << "Random points to: nullptr\n";
        curr = curr->next;
    }

    // Cleanup: You should ideally delete the created nodes to avoid memory leaks.
    // For brevity, cleanup code is not added here.

    return 0;
}
