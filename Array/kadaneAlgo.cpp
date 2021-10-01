int maxSubarraySum(int arr[], int n)
{

    // Your code here
    int currSum = 0;
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}
