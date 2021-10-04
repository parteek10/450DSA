//Problem link:https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
   vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int> v;
	    for(int i=0;i<n;i++){//iterating over the array
	        if(arr[i]==i+1) //indexing starts from 1 according to the problem
	        v.push_back(i+1); //all those elements will be added that have same value as their index
	    }
	    return v; //the vector is returned at the end of function
	}
};
//The following code is the driver code from the problem(see link) itself
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.valueEqualToIndex(arr, n);
        if (ans.empty()) {
            cout << "Not Found";
        } else {
            for (int x: ans) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
