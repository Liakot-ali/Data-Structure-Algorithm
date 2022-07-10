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
node* index = NULL;

void push(int val)
{
    node* n = new node(val);
    if(head == NULL){  ///For the first value
        head = n;
        index = n;
        return;
    }
    index->next = n;
    index = n;
}
void pop()
{
    if(head == NULL){
        cout<<"The Stack is empty"<<endl;
        return;
    }
    if(head == index){
        head = NULL;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        node* tmp = temp->next;
        if(tmp->next == NULL){
            index = temp;
            temp->next = NULL;
            return;
        }
        temp = temp->next;
    }
    index = head;
    return;
}

void display()
{
    if(head == NULL){
        cout<<"The stack is empty"<<endl;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

int main()
{
    cout<<"This is Stack program using linked list"<<endl;
     while(true)
    {
        int input;
        printf("Input:\n\t 1.For push data\n\t 2.For pop list\n\t 3.For show the stack\n\t"
                " 0.For exit\n");
        cin>>input;
        if(input == 1)
        {
            int value;
            cout<<"Enter the value:";
            cin>>value;
            push(value);

        }
        else if(input == 2)
        {
            pop();
        }
        else if(input == 3)
        {
            display();
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
    return 0;
}
