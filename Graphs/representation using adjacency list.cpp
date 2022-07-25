#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout<<"Enter number of node and edge:"<<endl;
    cin>>n>>m;
    vector<int> adjl[n+1];
    //memset(adjm, 0, sizeof(adjm));
    cout<<"Source and destination edges"<<endl;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    cout<<"The adjacency list is:"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<i<<"->";
        vector<int> :: iterator it;
        for(it = adjl[i].begin(); it != adjl[i].end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}
