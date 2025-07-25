#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0 && j == 0) dp[i][j] = true;
                if (i == 0) dp[i][j] = false;
                if (j == 0) dp[i][j] = true;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (j >= arr[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};
int main()
{
}