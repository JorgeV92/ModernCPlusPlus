#include <iostream>
#include <memory>

class Node {
public:
    int value;
    std::shared_ptr<Node> next;

    Node(int val) : value(val), next(nullptr) {
        std::cout << "Node created with value: " << value << std::endl;
    }

    ~Node() {
        std::cout << "Node with value " << value << " destroyed" << std::endl;
    }
};

void createLinkedList() {
    std::shared_ptr<Node> head = std::make_shared<Node>(1);
    std::shared_ptr<Node> second = std::make_shared<Node>(2);
    std::shared_ptr<Node> third = std::make_shared<Node>(3);

    head->next = second;
    second->next = third;

    // Use count to show reference count
    std::cout << "Head reference count: " << head.use_count() << std::endl;
    std::cout << "Second reference count: " << second.use_count() << std::endl;

    // Creating another shared pointer to the second node
    std::shared_ptr<Node> another = second;
    std::cout << "Second reference count after creating another: " << second.use_count() << std::endl;
}

int main() {
    createLinkedList();
    // All nodes will be destroyed automatically when shared pointers go out of scope
    return 0;
}