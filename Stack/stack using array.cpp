#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n = 100;
class Stack{
    int* arr;
    int pointer;
    public:
    Stack(){
        arr = new int[n];
        pointer = -1;
    }
    void push(int val){
        if(pointer == n-1){
            cout<<"The Stack is overflow"<<endl;
            return;
        }
        pointer++;
        arr[pointer] = val;
    }

    void pop()
    {
        if(pointer == -1){
            cout<<"The stack is empty"<<endl;
            return;
        }
        pointer--;
    }
    void display()
    {
        if(pointer == -1){
            cout<<"The Stack is empty"<<endl;
            return;
        }
        for(int i=0;i<=pointer;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    cout<<"This is Stack program using array"<<endl;
    Stack stk;
    while(true)
    {
        int input;
        printf("Input:\n\t 1.For push data\n\t 2.For pop list\n\t 3.For show the Stack\n\t"
                " 0.For exit\n");
        cin>>input;
        if(input == 1)
        {
            int value;
            cout<<"Enter the value:";
            cin>>value;
            stk.push(value);

        }
        else if(input == 2)
        {
            stk.pop();
        }
        else if(input == 3)
        {
            stk.display();
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

    /*
    stk.display();
    stk.push(45);
    stk.display();
    stk.push(10);
    stk.display();
    stk.push(16);
    stk.display();
    stk.pop();
    stk.display();
    stk.push(65);
    stk.display();
    stk.pop();
    stk.display();
    */
    return 0;
}
