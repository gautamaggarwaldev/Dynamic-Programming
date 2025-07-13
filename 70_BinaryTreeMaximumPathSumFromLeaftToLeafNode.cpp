#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int solve(Node *root, int &res)
    {
        if (root == NULL)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(l, r) + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            temp = max(temp, root->val);
        }
        int ans = max(temp, l + r + root->val);
        res = max(ans, res);
        return ans;
    }
    int maxPathSum(Node *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};
int main()
{
}