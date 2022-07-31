#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int capacity = 5;

class minHeap
{
public:
    int currSize;
    int *arr;
    int capacity;
    minHeap(int cap)
    {
        capacity = cap;
        currSize = 0;
        arr = new int[cap];
    }

    void InsertKey(int val)
    {
        if(currSize == 0)
        {
            arr[currSize] = val;
            currSize++;
            return;
        }
        if(currSize >= capacity)
        {
            cout<<"The heap is overflow"<<endl;
            return;
        }
        else
        {
            arr[currSize] = val;
            int i = currSize;
            while(arr[i] < arr[parent(i)] && i >= 0)
            {
                int temp = arr[i];
                arr[i] = arr[parent(i)];
                arr[parent(i)] = temp;
                i = parent(i);
            }
            currSize++;
        }
    }

    void display()
    {
        cout<<"Current Size: "<<currSize<<endl;
        for(int i=0; i< currSize; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int parent(int x)
    {
        return (x-1)/2;
    }
};

int main()
{
    minHeap heap(capacity);
    cout<<"This is the Binary Heaps program using array"<<endl;
    while(true)
    {
        int input;
        printf("Input:\n\t 1.For insert data\n\t 2.For display the array\n\t 3.For search a value\n\t"
               " 4.For delete a value/key\n\t 0.For exit\n");
        cin>>input;
        if(input == 1)
        {
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            heap.InsertKey(value);
        }
        else if(input == 2)
        {
            heap.display();
        }
        else if(input == 3)
        {
            cout<<"Under construction"<<endl;
            /*
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            if(Search(R, value))
            {
                cout<<"Got it"<<endl;
            }
            else
            {
                cout<<"Sorry"<<endl;
            }
            */
        }
        else if(input == 4){

            cout<<"Under construction"<<endl;
                /*
            int val;
            cout<<"Input the value:";
            cin>>val;
            R = deleteNode(R,val);
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

    /*
    heap.InsertKey(3);
    heap.display();
    heap.InsertKey(2);
    heap.display();
    heap.InsertKey(5);
    heap.display();
    heap.InsertKey(7);
    heap.display();
    heap.InsertKey(4);
    heap.display();
    heap.InsertKey(4);
    heap.display();
    heap.InsertKey(3);
    heap.display();
    heap.InsertKey(2);
    heap.display();
    heap.InsertKey(5);
    heap.display();
    heap.InsertKey(7);
    heap.display();
    heap.InsertKey(4);
    heap.display();
    heap.InsertKey(4);
    heap.display();
    */

    return 0;
}
