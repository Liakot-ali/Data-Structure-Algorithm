#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node* pre;
    node(int value){
        data = value;
        next = NULL;
        pre = NULL;
    }
};
node* head = NULL;

void InsertTail(int value){
    node* n = new node(value);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->pre = temp;
}
void InsertHead(int value){
    node* n = new node(value);
    if(head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head->pre = n;
    head = n;
}

void display(){
    node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main(){
    cout<<"This is doubly linked list program"<<endl;
    InsertTail(5);
    display();
    InsertTail(55);
    display();
    InsertHead(15);
    display();
    InsertTail(25);
    display();

    return 0;
}
