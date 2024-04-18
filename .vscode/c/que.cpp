#include <iostream>

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue an element
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << val << " enqueued to the queue." << std::endl;
    }

    // Function to dequeue an element
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        std::cout << temp->data << " dequeued from the queue." << std::endl;
        delete temp;
    }

    // Function to get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1; // Assuming -1 as a default invalid value
        }
        return front->data;
    }

    // Function to get the rear element of the queue
    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No rear element." << std::endl;
            return -1; // Assuming -1 as a default invalid value
        }
        return rear->data;
    }
};

int main() {
    Queue queue;
    
    // Enqueue elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display front and rear elements
    std::cout << "Front element: " << queue.getFront() << std::endl;
    std::cout << "Rear element: " << queue.getRear() << std::endl;

    // Dequeue elements
    queue.dequeue();
    queue.dequeue();

    // Display front and rear elements after dequeue
    std::cout << "Front element after dequeue: " << queue.getFront() << std::endl;
    std::cout << "Rear element after dequeue: " << queue.getRear() << std::endl;

    return 0;
}
