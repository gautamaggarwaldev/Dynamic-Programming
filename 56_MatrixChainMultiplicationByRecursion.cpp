#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int mcm(vector<int> &arr, int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        int mn = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int tempAns = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);

            if (tempAns < mn)
            {
                mn = tempAns;
            }
        }
        return mn;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        int ans = mcm(arr, 1, n - 1);
        return ans;
    }
};
int main()
{
}