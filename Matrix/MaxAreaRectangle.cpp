// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    int maxHist(int row[], int C)
    {
        stack<int> st;
        int top;
        int max_area = 0;
        int area = 0;
        int i = 0;
        while (i < C)
        {
            if (st.empty() || row[st.top()] <= row[i])
            {
                st.push(i++);
            }
            else
            {
                top = row[st.top()];
                st.pop();
                area = top * i;
                if (!st.empty())
                {
                    area = top * (i - st.top() - 1);
                }
                max_area = max(area, max_area);
            }
        }

        while (!st.empty())
        {
            top = row[st.top()];
            st.pop();
            area = top * i;
            if (!st.empty())
            {
                area = top * (i - st.top() - 1);
            }
            max_area = max(area, max_area);
        }
        return max_area;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {

        int result = maxHist(M[0], m);

        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 1)
                {
                    M[i][j] += M[i - 1][j];
                }
            }
            result = max(result, maxHist(M[i], m));
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}