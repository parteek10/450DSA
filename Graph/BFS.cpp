//Q357)  Implementation of BFS

#include<bits/stdc++.h>
using namespace std;

void print_BFS(int **edges,int n,int sv)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(currentVertex == i)
            {
                continue;
            }
            if(edges[currentVertex][i]==true && !visited[i])
            {
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
    delete []visited;
}

int main()
{
    int n,e;
    cin>>n>>e;

    int **edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }

    //will now take input for edges
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    print_BFS(edges,n,0);

    for(int i=0;i<n;i++)
    {
        delete []edges[i];
    }
    delete []edges;
}
