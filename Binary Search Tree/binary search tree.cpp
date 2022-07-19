#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
node* R = NULL;
node* insertNode(node* root, int val){
    if(R == NULL){
        R = new node(val);
        root = new node(val);
        //cout<<root->data<<endl;
        return root;
    }
    if(root == NULL){
        root = new node(val);
        //cout<<root->data<<endl;
        return root;
    }
    if(val > root->data){
        root->right = insertNode(root->right, val);
        //root->right = n;
    }else{
        root->left = insertNode(root->left, val);
        //root->left = n;
    }
    return root;
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    //cout<<root->data<<" ";
}
int main(){
    cout<<"This is Binary Search Tree Program using Linked list"<<endl;

    insertNode(R, 55);
    insertNode(R, 10);
    insertNode(R, 7);
    insertNode(R, 15);
    insertNode(R, 87);
    insertNode(R, 5);
    insertNode(R, 4);
    insertNode(R, 70);
    inorder(R);
    return 0;
}
