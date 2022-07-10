#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n = 100;
class Queue{
private:
    int * arr;  ///reference variable
    int first;
    int last;
public:
    Queue(){
        arr = new int[n];
        first = -1;
        last = -1;
    }
    void push(int x){
        if(last == n-1){
            cout<<"The queue is overflow"<<endl;
            return;
        }
        last++;
        arr[last] = x;
        if(first == -1){
            first++;
        }
    }
    void pop()
    {
        if(first == -1 || first > last){
            cout<<"The queue is empty"<<endl;
            return;
        }
        cout<<arr[first]<<endl;
        first++;
    }

    void display(){
        if(first == -1 || first > last){
            cout<<"The queue is empty"<<endl;
            return;
        }
        for(int i=first; i<=last; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    cout<<"This is Queue implementation using Array"<<endl;
    Queue q;
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
            q.push(value);

        }
        else if(input == 2)
        {
            q.pop();
        }
        else if(input == 3)
        {
            q.display();
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
    /*Queue q;
    q.push(5);
    q.push(10);
    q.display();
    q.pop();
    q.pop();
    q.push(15);
    q.pop();
    q.pop();*/
    return 0;
}
