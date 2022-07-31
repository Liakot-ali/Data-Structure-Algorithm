#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout<<"Enter number of node and edge:"<<endl;
    cin>>n>>m;
    int adjm[n+1][n+1];
    memset(adjm, 0, sizeof(adjm));
    cout<<"Source and destination edges"<<endl;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin>>x>>y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout<<"Representation in adjacency matrix:"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<adjm[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
