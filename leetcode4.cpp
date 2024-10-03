#include <iostream>
#include <unordered_map>

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

int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next; 
    head->next->random = head;       
    head->next->next->random = head->next; 
    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    Node* curr = copiedList;
    while (curr) {
        std::cout << "Node value: " << curr->val << "\n";
        if (curr->random)
            std::cout << "Random points to: " << curr->random->val << "\n";
        else
            std::cout << "Random points to: nullptr\n";
        curr = curr->next;
    }

    return 0;
}
