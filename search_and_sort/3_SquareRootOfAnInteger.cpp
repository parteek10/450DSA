//Link: https://practice.geeksforgeeks.org/problems/count-squares3649/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSquares(int N) {
      
        if(sqrt(N)-floor(sqrt(N))>0)
       //N is not necessarily a perfect square
        return floor(sqrt(N));
       //N is a perfect square
        else return floor(sqrt(N))-1;
    }
};
//driver code as given in problem(link above)
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
} 
