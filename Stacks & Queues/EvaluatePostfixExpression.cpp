// Problem link : https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

bool isNum (char c) {
    return (c<='9' && c>='0');
}

int evaluate (int op1, int op2, char op) {
    switch (op) {
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
    }
}

int evaluatePostfix(string S) {
    stack<int> st;
    for (char c : S) {
        if (isNum(c)) {
            st.push(c-'0');
        } else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int val = evaluate (op1, op2, c);
            st.push(val);
        }
    }
    return st.top();
}
