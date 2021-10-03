// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
#include <iostream>
#include <vector>
using namespace std;
// using a global vector to store strings
vector<string> ans;
void get_prm(string ques, string str)
{
    // if ques.length()==0 -- whole str is traversed
    if (ques.length() == 0)
    {
        ans.push_back(str);
        return;
    }

    for (int i = 0; i < ques.length(); i++)
    {   //selecting a new character
        char ch = ques[i];
        // substr-- to get left and right part side of character
        string ros = ques.substr(0, i) + ques.substr(i + 1);
        //calling the function for rest of string
        get_prm(ros, str + ch);
    }
}
int main()
{
    string s;
    cout << "enter the string:";
    cin >> s;
    get_prm(s, " ");
    // after the function is executed the ans vector will contain all possible permutations
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}