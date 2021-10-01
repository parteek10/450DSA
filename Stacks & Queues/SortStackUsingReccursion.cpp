// Problem link : https://practice.geeksforgeeks.org/problems/sort-a-stack/1

void insertAtCorrectPos (stack<int> &s, int a) {
    if (s.empty() || s.top()<=a) {
        s.push(a);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtCorrectPos (s, a);
    s.push(num);
}

void SortedStack :: sort()
{
    if (s.empty()) return;
    
    int a = s.top();
    s.pop();
    sort ();
    insertAtCorrectPos (s, a);
}
