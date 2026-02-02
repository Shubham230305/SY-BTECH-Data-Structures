#include<iostream>
using namespace std;

class BST
{
    public:
    int data;
    
    BST *left, *right;
    BST(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
    
    public:
    BST *insertion(BST *root, int target)
    {
        if(root == NULL)
        {
            BST *temp = new BST(target);
            return temp;
        }
        
        if(target < root->data)
        {
            root->left = insertion(root->left, target);
        }
        else
        {
            root->right = insertion(root->right, target);
        }
        return root;
    }
    
    BST *LCA(BST*root, int x, int y)
    {
        if(root==NULL)
        {
            return NULL;
        }

        if(x < root->data && y < root->data)
        {
            return LCA(root->left, x, y);
        }
        else if(x > root->data && y > root->data)
        {
            return LCA(root->right, x, y);
        }
        else
        {
            return root;
        }
    }
};

int main()
{
    BST ob(0);
    BST *root = nullptr;
    
    int n;
    cout<<"Enter Number of Elements to be Inserted : ";
    cin>>n;
    
    int *arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter Element "<<i+1<<" : ";
        cin>>arr[i];
    }
    
    for(int i=0; i<n; i++)
    {
        root = ob.insertion(root, arr[i]);
    }
    
    int x, y;
    cout<<"Enter N1 : ";
    cin>>x;
    cout<<"Enter N2 : ";
    cin>>y;

    BST *lca = ob.LCA(root, x, y);

    if(lca!=nullptr)
    {
        cout<<"The LCA is : "<<lca->data;
    }
    else
    {
        cout<<"LCA Not Found";
    }
   
   return 0;
}