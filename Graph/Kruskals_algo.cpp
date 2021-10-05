//Q373) https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int source;
    int destination;
    int weight;
};

bool compare(Edge e1,Edge e2)
{
    return (e1.weight<e2.weight);
}

int findParent(int *parent, int v)
{
    if(parent[v]==v)
    {
        return v;
    }

    return findParent(parent,parent[v]);
}

void kruskals(Edge *input, int v, int E)
{
    //Sort input array in  ascending order
    sort(input,input+E,compare);

    Edge *output = new Edge[v-1];
    int *parent = new int[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
    }

    int count=0,i=0;
    while(count<v-1)
    {
        // Check whether we can add input[i] in MST or not
        int sourceParent = findParent(parent,input[i].source);
        int destinationParent = findParent(parent,input[i].destination);

        if(sourceParent != destinationParent)
        {
            output[count++] = input[i];
            parent[sourceParent] = destinationParent;
        }
        i++;
    }

    for(int i=0;i<v-1;i++)
    {
        if(output[i].source<output[i].destination)
        {
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }

    delete []parent;
    delete []output;
}

int main()
{
    int v,E;
    cin>>v>>E;
    Edge *input = new Edge[E];
    for(int i=0;i<E;i++)
    {
        cin>>input[i].source>>input[i].destination>>input[i].weight;
    }

    kruskals(input,v,E);

    delete []input;

}
