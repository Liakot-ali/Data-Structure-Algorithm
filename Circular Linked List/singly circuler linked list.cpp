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
void deleteTail(){
    if(head == NULL){
        cout<<"No item to delete"<<endl;
        return;
    }
    node* temp = head;
    if(temp->next == head){ //if there are only one element
        head = NULL;
        return;
    }
    while(temp->next != head){
        node* nextNode = temp->next;
        if(nextNode->next == head){
            nextNode->next = NULL;  //break the chain
            temp->next = head;
            break;
        }
        temp = temp->next;
    }
    return;
}
void deleteHead(){
    if(head == NULL){
        cout<<"No item to delete"<<endl;
        return;
    }
    node* tmp = head;

    if(tmp->next == head){
        head = NULL;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        if(temp->next == head){
            break;
        }
        temp = temp->next;
    }
    head = tmp->next;
    temp->next = head;
    tmp->next = NULL;
    return;

}
bool display(){
    if(head == NULL){
        cout<<"The list is empty"<<endl;
        return false;
    }
    node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    return true;
}
int main(){
    cout<<"This is circular singly linked list program"<<endl;
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
                insertHead(value);
            }else if(ch == 't' || ch == 'T'){
                insertTail(value);
            }else{
                cout<<"Input H or T:";
                cin>>ch;
                goto take;
            }
        }
        else if(input == 2)
        {
            display();
        }
        else if(input == 3)
        {
            if(display()){
                char ch;
                cout<<"Delete from HEAD(h) or TAIL(t)?:";
                cin>>ch;
                takeAgain:
                if(ch == 'h'|| ch == 'H'){
                    deleteHead();
                    display();
                }else if(ch == 't' || ch == 'T'){
                    deleteTail();
                    display();
                }else{
                    cout<<"Input H or T:";
                    cin>>ch;
                    goto takeAgain;
                }
            }
        }
        else if(input == 4){
            cout<<"Under construction"<<endl;
            /*int val;
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
