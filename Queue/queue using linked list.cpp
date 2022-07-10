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
node* last = NULL;

void push(int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        last = n;
        return;
    }
    last->next = n;
    last = n;
    return;
}
void pop()
{
    if(head == NULL){
        cout<<"The Queue is empty"<<endl;
        return;
    }
    head = head->next;
}

void display()
{
    if(head == NULL){
        cout<<"The Queue is empty"<<endl;
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
    cout<<"This is Queue program using linked list"<<endl;
    while(true)
    {
        int input;
        printf("Input:\n\t 1.For push data\n\t 2.For pop list\n\t 3.For show the queue\n\t"
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
