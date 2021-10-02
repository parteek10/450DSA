
#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int cnt=0;
        for(auto x:m)
        {
            if(x.first<=k/2)
            {
                if(m.find(k-x.first)!=m.end())
                {
                    if(k-x.first==x.first&&m[x.first]<=1)
                    {continue;}
                    else if(k-x.first==x.first&&m[x.first]>1)
                    {
                        cnt+=m[x.first]*(m[x.first]-1)/2;
                        continue;
                    }
                    int pairs=max(m[x.first],m[k-x.first]);
                    cnt+=pairs*min(m[x.first],m[k-x.first]);
                }
            }
        }
        return cnt;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  
