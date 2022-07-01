#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
node* head = NULL;

void insertTail(int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        n->next = head;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void insertHead(int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        n->next = head;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    n->next = head;
    head = n;
    temp->next = head;
}
void display(){
    if(head == NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
int main(){
    cout<<"This is circular singly linked list program"<<endl;
    display();
    insertTail(15);
    display();
    insertTail(5);
    display();
    insertTail(154);
    display();
    insertHead(12);
    display();
    insertTail(145);
    insertTail(165);
    insertTail(115);
    display();
    insertHead(89);
    display();
    return 0;
}
