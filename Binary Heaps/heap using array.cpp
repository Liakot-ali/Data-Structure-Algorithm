#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int capacity = 10000;

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

    void extractMin(){
        if(currSize == 0){
            return;
        }
        if(currSize == 1){
            currSize--;
            return;
        }
        currSize--;
        arr[0] = arr[currSize];
        minHeapify(0);

    }

    void minHeapify(int root){
        int left = leftChild(root);
        int right = rightChild(root);
        int small = root;
        if(left < currSize && arr[root] > arr[left]){
            small = left;
        }
        if(right < currSize && arr[right] < arr[small]){
            small = right;
        }
        if(small != root){
            swap(arr[root], arr[small]);
            minHeapify(small);
        }
        return;
    }

    int leftChild(int i){
        return 2*i + 1;
    }
    int rightChild(int i){
        return 2*i + 2;
    }
    void linearSearch(int val)
    {

        for(int i=0; i<currSize; i++)
        {
            if(arr[i] == val)
            {
                cout<<"Found"<<endl;
                return;
            }
        }
        cout<<"Not found"<<endl;
        return;
    }
    void displayTree(){
        int index = 0;
        for(int i=0; i<treeHeight();i++){
            for(int j=i;j<treeHeight()-1;j++){
                cout<<"\t";
            }
            cout<<" ";
            for(int k=0;k<=i;k++){
                cout<<arr[index++]<<"\t";
            }
            cout<<endl;
            if(i+1 != treeHeight()){
                for(int j=i;j<treeHeight()-1;j++){
                    cout<<"\t";
                }
                cout<<"/ \\"<<endl;
            }
        }

    }
    int treeHeight(){
        return log2(currSize) + 1;
    }

    void display()
    {
        if(currSize == 0){
            cout<<"The array is empty"<<endl;
            return;
        }
        //cout<<"Current Size: "<<currSize<<endl;
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
               " 4.For delete a value/key\n\t 5.For extract minimum value\n\t 0.For exit\n");
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
            if(heap.currSize == 0)
            {
                cout<<"The array is empty"<<endl;
            }else{
                int value;
                cout<<"Enter the value: ";
                cin>>value;
                heap.linearSearch(value);
            }
        }
        else if(input == 4)
        {
            cout<<"Under construction"<<endl;
            /*
            int val;
            cout<<"Input the value:";
            cin>>val;
            R = deleteNode(R,val);
            */
        }
        else if(input == 5)
        {
            heap.display();
            heap.extractMin();
            heap.display();
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


            10
           /  \
          15  20
         /  \   \
        21  26  35
    */

    return 0;
}
