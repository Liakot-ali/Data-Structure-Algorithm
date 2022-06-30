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

///----insert value in the last--------
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

///-------insert value at first-------
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

void DeleteTail(){
    if(tail == NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    if(tail->pre == NULL){
        tail = NULL;
        head = NULL;
        return;
    }
    node* temp = tail->pre;
    temp->next = tail->next;
    tail = temp;
}
void DeleteHead(){
    if(head == NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    if(head->next == NULL){
        head = NULL;
        tail = NULL;
        return;
    }
    node* temp = head->next;
    temp->pre = head->pre;
    head = temp;
}

void displayForward(){
    if(head == NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    cout<<"This is forward list:"<<endl;
    node* temp = head;
    while(temp->next != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}
void displayBackward(){
    if(tail == NULL){
        cout<<"The list is empty"<<endl;
        return;
    }
    cout<<"This is backward list:"<<endl;
    node* tmp = tail;
    while(tmp->pre != NULL){
        cout<<tmp->data<<" ";
        tmp = tmp->pre;
    }
    cout<<tmp->data<<endl;
}

int main(){
    cout<<"This is doubly linked list program"<<endl;
    while(true)
    {
        int input;
        printf("Input:\n\t 1.For adding data\n\t 2.For Display list\n\t 3.For delete a element\n\t"
                " 4.For search a value\n\t 0.For exit\n");
        cin>>input;
        if(input == 1)
        {
            int value;
            char ch;
            cout<<"Enter the value:";
            cin>>value;
            cout<<"Insert at HEAD(h) or TAIL(t)?:";
            cin>>ch;
            take:
            if(ch == 'h'|| ch == 'H'){
                InsertHead(value);
            }else if(ch == 't' || ch == 'T'){
                InsertTail(value);
            }else{
                cout<<"Input H or T:";
                cin>>ch;
                goto take;
            }
        }
        else if(input == 2)
        {
            displayForward();
            displayBackward();
        }
        else if(input == 3)
        {
            displayForward();
            char ch;
            cout<<"Delete from HEAD(h) or TAIL(t)?:";
            cin>>ch;
            takeAgain:
            if(ch == 'h'|| ch == 'H'){
                DeleteHead();
                displayForward();
            }else if(ch == 't' || ch == 'T'){
                DeleteTail();
                displayForward();
            }else{
                cout<<"Input H or T:";
                cin>>ch;
                goto takeAgain;
            }
        }
        else if(input == 4){
            cout<<"Under construction"<<endl;
            /*
            int val;
            cout<<"Which value you want to search? ";
            cin>>val;
            Search(val);
            */
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
