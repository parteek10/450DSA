// Problem link : https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1#

#include<bits/stdc++.h>

using namespace std;

//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    char* reverseString = (char*)malloc((len+1)*sizeof(char));
    stack<char> revStack;
    
    int index=0;
    
    while(index<len){
        revStack.push(S[index]);
        index++;
    }
    
    index=0;
    
    while(!revStack.empty()){
        reverseString[index]=revStack.top();
        revStack.pop();
        index++;
    }
    
    reverseString+='\0';

    return reverseString;
    
}

int main(){

    char* demoString = "GeeksForGeeks";
    int length = 13;

    char* reversedString = reverse(demoString, length);
    printf("%s", reversedString);

    return 0;
}