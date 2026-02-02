#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

  
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

 
    void printList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        int count = 0; 
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        } while (temp != head && count < 20); 
        if (count >= 20) {
            cout << "... (circular, possibly disrupted)" << endl;
        } else {
            cout << temp->data << endl;
        }
    }
   
    void findAndFixDisruption() {
        if (head == nullptr) {
            return;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }


        if (slow != fast) {
            cout << "No cycle detected or list is not disturbed." << endl;
            return;
        }

        
        Node* entry = head;
        while (entry != slow) {
            entry = entry->next;
            slow = slow->next;
        }

        Node* last = entry;
        while (last->next != entry) {
            last = last->next;
        }

        last->next = head;
    }
};

int main() {
    CircularLinkedList cll;
    cll.append(1);
    cll.append(2);
    cll.append(3);
    cll.append(4);
 
    Node* node = cll.head;
    while (node->next != cll.head) {
        node = node->next;
    }
    node->next = cll.head->next->next; 
    cout << "Disrupted Circular Linked List:" << endl;
    cll.printList();
    cll.findAndFixDisruption();
    cout << "Corrected Circular Linked List:" << endl;
    cll.printList();

    return 0;
}
