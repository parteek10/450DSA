//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

//first and last index of an element in a sorted array
#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n,x;
   cin>>n>>x;
   vector<int> numbers(n);
   
   for(int i=0;i<n;i++){
       cin>>numbers[i];
   }
   
   if(!binary_search(numbers.begin(),numbers.end(),x)){		//element is not there in the array
       cout<<"number not in the array\n";
   }
   else{
	int strt_ind=lower_bound(numbers.begin(),numbers.end(),x)-numbers.begin();	// starting index
   	int end_ind=upper_bound(numbers.begin(),numbers.end(),x)-numbers.begin();	// ending index
        cout<<strt_ind<<" "<<end_ind-1<<endl;
   }
}
