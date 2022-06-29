#include<iostream>
#include<bits/stdc++.h>
using namespace std;
///---------for a specific node-------
class node
{
public:
    int data;
    node* next; //this point the next node
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
node* head = NULL; //--at first the head pointer is null---
void Insert(int val, int pos)
{
    if(pos > 0)
    {
        int nodeCounter = 1;
        node* n = new node(val); //---create new node

        if(head == NULL)
        {
            if(pos>1)
            {
                cout<<"The length of the list is 0"<<endl;
            }
            else
            {
                head = n;  //if the head is null then the head is point the node
            }
            return;
        }
        if(pos == 1)  //for adding the node at first
        {
            node* temp = head;
            head = n;
            n->next = temp;
            return;
        }

        node* temp = head;
        while(temp->next != NULL)  //adding the node(n) at nth(pos) position
        {
            nodeCounter++;
            if(nodeCounter == pos)
            {
                n->next = temp->next;
                temp->next = n;
                break;
            }
            temp = temp->next;
        }
        if(nodeCounter+1 < pos) //if the length of the list is less than the position
        {
            cout<<"The length of the list is "<<nodeCounter<<endl;
        }
        else
        {
            temp->next = n;
        }
    }else{
        cout<<"Invalid position"<<endl;
    }
}

void Delete(int pos){
    if(pos>0){
        if(head == NULL){
            cout<<"There is no item to delete"<<endl;
            return;
        }
        int counter = 0;
        node* temp = head;
        while(temp->next != NULL){
            node* inc = temp->next;
            if(inc->next == NULL){
                temp ->next = NULL;
                return;
            }
            temp = temp->next;
        }
        head = NULL;
        return;
    }else{
        cout<<"Invalid position"<<endl;
    }
    return;
}

void display()
{

    node* n = head;
    if(head == NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    cout<<"Current list is: ";
    while(n->next != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<n->data<<endl;
}
int main()
{
    cout<<"This is linked list program"<<endl;
    while(true)
    {
        int input;
        printf("Input:\n\t 1.For adding data\n\t 2.For Display list\n\t 3.For delete a element\n\t 0.For exit\n");
        cin>>input;
        if(input == 1)
        {
            int value, position;
            cout<<"Enter the value and position:";
            cin>>value>>position;
            Insert(value, position);
        }
        else if(input == 2)
        {
            display();
        }
        else if(input == 3)
        {
            Delete(1);
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
