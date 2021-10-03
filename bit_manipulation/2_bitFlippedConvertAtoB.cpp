#include<bits/stdc++.h>
using namespace std;

//this function will count the bits to be flipped to convert a to b
int count_bits_to_be_flipped(int a, int b){
	int count=0;
	    while(a>0||b>0){
		    if((a%2==1&&b%2==0)||(b%2==1&&a%2==0))		// there is difference in the bits of a and b
			    count++;
		    a=a/2;
		    b=b/2;
	    }
	    return count;
}
int main(){
	int a=10,b=20;
	cout<<count_bits_to_be_flipped(a,b)<<"\n";
}
