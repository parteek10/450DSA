#include <bits/stdc++.h>
using namespace std;

void Inorder(vector<int>&tree,vector<int>&inorder,int size,int index)
{
    if(index>=size)
    return;
    Inorder(tree,inorder,size,2*index+1);
    inorder.push_back(tree[index]);
    Inorder(tree,inorder,size,2*index+2);
    
}
int minSwaps(vector<int> inorder)
{
    vector<pair<int,int>> t;
    int ans=0;
    for(int i=0;i<inorder.size();i++)
    {
        t.push_back({inorder[i],i});
    }
    sort(t.begin(),t.end());
    for(int i=0;i<t.size();i++)
    {
        if(i==t[i].second)
        {
            continue;
        }
        else
        {
            swap(t[i].first,t[t[i].second].first);
            swap(t[i].second,t[t[i].second].second);
        }
        if(i!=t[i].second)
        {
            i--;
        }
        ans++;
        
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> tree(n);
    for(auto &x:tree)
    {
        cin>>x;
    }
    vector<int> inorder;
    Inorder(tree,inorder,n,0);
    cout<<minSwaps(inorder)<<endl;


    
}

int main()
{
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}