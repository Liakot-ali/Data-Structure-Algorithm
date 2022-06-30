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
node* tail = NULL;

void InsertTail(int value){
    node* n = new node(value);
    if(head == NULL){   //when add value for first time
        head = n;
        tail = n;
        return;
    }
    n->pre = tail;
    tail->next = n;
    tail = n;

    /*node* temp = head;
    while(temp->next != NULL){
        temp = temp->next; //using head pointer
    }
    temp->next = n;
    n->pre = temp;*/
}
void InsertHead(int value){
    node* n = new node(value);
    if(head == NULL)
    {
        head = n;
        tail = n;
        return;
    }
    n->next = head;
    head->pre = n;
    head = n;
}

void displayForward(){
    node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
void displayBackward(){
    node* tmp = tail;
    while(tmp->pre != NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->pre;
    }
    cout<<tmp->data<<endl;
}

int main(){
    cout<<"This is doubly linked list program"<<endl;
    InsertTail(5);
    displayForward();
    InsertTail(55);
    InsertHead(15);
    InsertTail(25);
    displayBackward();

    return 0;
}
