#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data): data(data), next(nullptr) {}

    Node* mergesort(Node *head1, Node *head2) {
        Node *head = new Node(0); 
        Node *tail = head;

        while (head1 && head2) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
     
        if (head1) {
            tail->next = head1;
        } else {
            tail->next = head2;
        }

        return head->next; 
    }

   
    Node* mergeSLL(Node* arr[], int start, int end) {
        if (start == end) {
            return arr[start]; 
        }
        int mid = start + (end - start) / 2;
        Node* left = mergeSLL(arr, start, mid);
        Node* right = mergeSLL(arr, mid + 1, end);
        return mergesort(left, right); 
    }
 
    Node* mergeklists(Node *arr[], int k) {
        return mergeSLL(arr, 0, k - 1); 
    }
};

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int k = 3;   
    Node* arr[k];


    arr[0] = new Node(1);
    arr[0]->next = new Node(9);
    arr[0]->next->next = new Node(15);
    arr[0]->next->next->next = new Node(68);
    

    arr[1] = new Node(12);
    arr[1]->next = new Node(24);
      
    
    arr[2] = new Node(15);
    arr[2]->next = new Node(25);
    arr[2]->next->next = new Node(27);
    arr[2]->next->next->next = new Node(36);
    arr[2]->next->next->next->next = new Node(78);
   
    Node* mergedList = arr[0]->mergeklists(arr, k);
    printList(mergedList);
    return 0;
}

//*If you have k = 3 lists and each list has an average of n = 4 nodes, 
//*the total time complexity would be O(3 * 4 * log(3)), which simplifies to O(12 * log(3)).
