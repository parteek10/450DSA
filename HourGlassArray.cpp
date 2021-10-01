#include <iostream>
using namespace std;

int main()
{
    int i, j, arr[6][6], max = 0, sum = 0, f = 1;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i < 5; i++)
    {
        for (j = 1; j < 5; j++)
        {
            sum = arr[i][j] + arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j + 1] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
            if (f == 1)
            {
                max = sum;
                f = 0;
            }

            if (max < sum)
            {
                max = sum;
            }
        }
    }
    cout << max;
}
