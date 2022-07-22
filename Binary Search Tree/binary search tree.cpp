#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node   ///Node of the BST which has 2 pointer
{
public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node* R = NULL; ///----Main root, which point the root node
node* insertNode(node* root, int val)
{
    if(R == NULL)
    {
        R = new node(val);
        root = new node(val);
        return root;
    }
    if(root == NULL)
    {
        root = new node(val);
        return root;
    }
    if(val > root->data)
    {
        root->right = insertNode(root->right, val);
    }
    else
    {
        root->left = insertNode(root->left, val);
    }
    return root;
}
void displayInorder(node* root)  ///-------Traversing the BST in InOrder----
{

    if(R == NULL)
    {
        cout<<"The BST is empty"<<endl;
        return;
    }
    if(root == NULL)
    {
        return;
    }
    displayInorder(root->left);
    cout<<root->data<<" ";
    displayInorder(root->right);
}

node* inorderSucc(node* root){
    node* current = root;
    while(current != NULL && current->left != NULL){
        current = current->left;
    }
    return current;
}

node* deleteNode(node* root, int key)
{
    if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else{
        //-CASE 1---
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        } //-CASE 2---
        else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        //---CASE 3-----
        node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
bool Search(node* root, int val)
{
    if(R == NULL)
    {
        cout<<"The BST is empty"<<endl;
        return false;
    }
    if(root == NULL)
    {
        cout<<"The value is not in the BST"<<endl;
        return false;
    }
    if(val == root->data)
    {
        cout<<"The value is in the list"<<endl;
        return true;
    }
    else if(val > root->data)
    {
        Search(root->right, val);
    }
    else
    {
        Search(root->left, val);
    }
}
int main()
{
    cout<<"This is Binary Search Tree Program using Linked list"<<endl;

    while(true)
    {
        int input;
        printf("Input:\n\t 1.For insert data\n\t 2.For Show the BST in InOrder\n\t 3.For search a value\n\t"
               " 4.For delete a node\n\t 0.For exit\n");
        cin>>input;
        if(input == 1)
        {
            int value;
            cout<<"Enter the value:";
            cin>>value;
            insertNode(R, value);
        }
        else if(input == 2)
        {
            displayInorder(R);
            cout<<endl;
        }
        else if(input == 3)
        {
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            if(Search(R, value))
            {
                cout<<"Got it"<<endl;
            }
            else
            {
                cout<<"Sorry"<<endl;
            }
        }
        else if(input == 4){
            int val;
            cout<<"Input the value:";
            cin>>val;
            deleteNode(R,val);
        }
        else if(input == 0)
        {
            return 0;
        }
        else
        {
            cout<<"Invalid input"<<endl;
        }
    }

/*
    insertNode(R, 55);
    insertNode(R, 10);
    insertNode(R, 7);
    insertNode(R, 15);
    insertNode(R, 87);
    insertNode(R, 5);
    insertNode(R, 4);
    insertNode(R, 70);
    displayInorder(R);
    deleteNode(R, 15);
    displayInorder(R);
    deleteNode(R, 55);
    displayInorder(R);
*/
    return 0;
}
