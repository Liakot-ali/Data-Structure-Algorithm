#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
node* head = NULL;
void Insert(int val, int pos)
{
    node* n = new node(val);

    if(head == NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;

}

void display()
{

    node* n = head;
    while(n->next != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<n->data<<endl;
}
int main()
{
    printf("This is linked list program");

    Insert(5,5);
    Insert(10,5);
    Insert(7,5);
    display();


    return 0;

}
