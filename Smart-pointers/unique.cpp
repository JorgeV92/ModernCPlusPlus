#include <iostream>
#include <memory>

class Node {
public:
    int value;
    std::unique_ptr<Node> next;

    Node(int val) : value(val), next(nullptr) {
        std::cout << "Node created with value: " << value << std::endl;
    }

    ~Node() {
        std::cout << "Node with value " << value << " destroyed" << std::endl;
    }
};

void createUniqueLinkedList() {
    std::unique_ptr<Node> head = std::make_unique<Node>(1);
    head->next = std::make_unique<Node>(2);
    head->next->next = std::make_unique<Node>(3);

    std::cout << "Head node value: " << head->value << std::endl;
    std::cout << "Second node value: " << head->next->value << std::endl;
    std::cout << "Third node value: " << head->next->next->value << std::endl;

    // Transferring ownership
    std::unique_ptr<Node> newHead = std::move(head);
    if (!head) {
        std::cout << "head is now empty after move" << std::endl;
    }
    std::cout << "New head node value: " << newHead->value << std::endl;
}

int main() {
    createUniqueLinkedList();
    // All nodes will be destroyed automatically when unique pointers go out of scope
    return 0;
}