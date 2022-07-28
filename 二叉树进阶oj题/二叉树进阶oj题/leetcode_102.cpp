// https://leetcode.cn/problems/binary-tree-level-order-traversal/

#include<vector>
#include<queue>
using std::vector;
using std::queue;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    std::vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if (root == nullptr)
            return vv;
        queue<TreeNode*> q;

        int leveSize = 1;

        q.push(root);
        while (!q.empty())
        {
            vector<int> v;

            while (leveSize--)
            {
                TreeNode* front = q.front();
                q.pop();
                v.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            vv.push_back(v);

            leveSize = q.size();

        }
        return vv;

    }
};