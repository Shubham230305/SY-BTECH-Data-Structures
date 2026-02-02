#include <iostream> 
using namespace std; 
 
class BST { public:     int data; 
    BST *left, *right; 
 
    BST(int value) 
    {         data = value;         left = NULL;         right = NULL; 
    } 
 
public: 
    BST* insertion(BST* root, int target) 
    {         if (!root) 
        { 
            BST *temp = new BST(target);             return temp; 
        } 
 
        if (target < root->data) 
        {             root->left = insertion(root->left, target); 
        }         else 
        { 
            root->right = insertion(root->right, target); 
        } 
 
        return root; 
    } 
 
    BST* lastVisited = nullptr; 
 
    void postorder(BST* root, int key) 
    {         
        if (!root)             
        return; 
 
        postorder(root->left, key);         
        postorder(root->right, key); 
 
        if (root->data == key) 
        {             if (lastVisited) 
            { 
                cout << "Postorder Predecessor of " << key << " is: " << lastVisited->data << endl; 
            }             else             { 
                cout << "No postorder predecessor found for " << key << endl; 
            }             return; 
        } 
 
        lastVisited = root; 
    } 
 
    void postorderTraversal(BST* root) 
    {         if (!root)             return; 
 
        postorderTraversal(root->left);         postorderTraversal(root->right);         cout << root->data << " "; 
    } 
}; 
 
int main() { 
     BST ob(0); 
     BST *root = nullptr;  
     int n; 
    cout << "Enter the number of Elements: ";     
    cin >> n; 
 
    int *arr = new int[n];  
 
    for (int i = 0; i < n; i++) 
    {         
        cout << "Enter element " << i + 1 << ": ";         
        cin >> arr[i]; 
    } 
 
     for (int i = 0; i < n; i++) 
    {         root = ob.insertion(root, arr[i]); 
    } 
 
    cout << "Postorder Traversal: ";     
    ob.postorderTraversal(root);
    cout << endl; 
     
    ob.lastVisited = nullptr;     int key = 60;     ob.postorder(root, key); 
 
 
    return 0; 
} 