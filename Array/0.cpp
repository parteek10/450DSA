
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include <iostream>
using namespace std;

string reverseWord(string str)
{
    int i, n = str.size();
    for (i = 0; i < n / 2; i++)
        swap(str[i], str[n - 1 - i]);
    return str;
}

int main()
{
    string str;
    cin >> str;
    cout << reverseWord(str) << endl;
}