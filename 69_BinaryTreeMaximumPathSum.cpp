#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int solve(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;

        int l = max(0, solve(root->left, res));
        int r = max(0, solve(root->right, res));

        int temp = l + r + root->val;
        res = max(res, temp);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};

int main()
{
}