#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
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
        int left = solve(root->left, res);
        int right = solve(root->right, res);

        int temp = max(left, right) + 1;
        int ans = max(temp, left + right + 1);
        res = max(res, ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res - 1;
    }
};
int main()
{
}