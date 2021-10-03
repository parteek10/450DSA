//LINK:https://leetcode.com/problems/reverse-string
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp; //for temporarily storing a character
        int end=s.size()-1,start=0; 
        /* using start and end variables to traverse from both sides
           which reduces time complexity
        */ 
        while(start<end){  //loop runs until it iterates over whole string
            //swapping starting chars. with ending chars.
            temp=s[start];
            s[start]=s[end];
            s[end]=temp; 
           //'start' and 'end' incremented and decremented until they are equal
            start++;
            end--;
        }
    }
};

int main(){
 vector<char> s;
  v.push_back('a');
  v.push_back('b');
  v.push_back('c');
  //s becomes abc
  Solution ob;
  ob.reverseString(s);
  //s becomes cba
}
