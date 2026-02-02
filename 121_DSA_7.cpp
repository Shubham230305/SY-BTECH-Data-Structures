#include <iostream>
using namespace std;
#define max 100
class Node {
public:
 int data;
 Node* left;
 Node* right;
 Node(int value) {
 data = value;
 left = NULL;
 right = NULL;
 }
};
class Queue{
 public:
 int front,rear,size;
 Node* arr[max];
 Queue(){
 front=0;
 rear=0;
 size=0;
 }
 bool isempty(){
 return size==0;
 }
 bool isfull(){
 return size==max;
 }
 void enqueue(Node *node){
 if(isfull()){
 cout<<"OVERFLOW";
 return ;
 }
 arr[rear]=node;
 rear=(rear+1)%max;
 size++;
 }
 Node* dequeue(){
 if(isempty()){
 return NULL;
 }
 
 Node* node =arr[front];
 front = (front+1)%max;
 size--;
 return node;
 }
};
 Node* insert(Node* root, int val) {
 if (root == NULL) {
 return new Node(val);
 }
 if (val < root->data) {
 root->left = insert(root->left, val);
 } else {
 root->right = insert(root->right, val);
 }
 return root;
 }
 void inorder(Node* root, int arr[], int &index) {
 if (root == NULL) return;
 inorder(root->left, arr, index);
 arr[index++] = root->data;
 inorder(root->right, arr, index);
 }
 void convertToMinHeap(Node* root, int arr[], int &index) {
 Queue q;
 q.enqueue(root);
 while(!q.isempty()){
 Node* current = q.dequeue();
 current->data=arr[index++];
 if(current->left!=nullptr){
 q.enqueue(current->left);
 }
 if(current->right!=nullptr){
 q.enqueue(current->right);
 }
 }
 }
 void preorder(Node* root) {
 if (root == NULL) return;
 cout << root->data << " ";
 preorder(root->left);
 preorder(root->right);
 }
int main() {
 
 Node* root = NULL;
 int n;
 cout << "Enter the number of elements: ";
 cin >> n;
 int arr[n];
 for (int i = 0; i < n; i++) {
 cout << "Enter element " << i + 1 << ": ";
 cin >> arr[i];
 }
 for (int i = 0; i < n; i++) {
 root =insert(root, arr[i]);
 }
 int inorderArray[n], index = 0;
 inorder(root, inorderArray, index);
 index = 0;
 convertToMinHeap(root, inorderArray, index);
 cout << "Pre-order traversal of the converted Min Heap: ";
 preorder(root);
 return 0;
}