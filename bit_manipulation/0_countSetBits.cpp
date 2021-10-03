#include<bits/stdc++.h>
using namespace std;

//this function will count the set bits in the given number
int count_set_bits(int n){
	int count=0;
	while(n>0){
		if(n%2==1)		// there is 1 in its binary representaion
			count++;
		n=n/2;
	}
	return count;
}
int main(){
	int n=6;
	cout<<count_set_bits(n)<<"\n";
}
