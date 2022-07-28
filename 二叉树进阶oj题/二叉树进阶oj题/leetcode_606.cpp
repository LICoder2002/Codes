//https://leetcode.cn/problems/construct-string-from-binary-tree/

/*
����������ĸ��ڵ� root ���������ǰ������ķ�ʽ����������ת��Ϊһ�������ź�������ɵ��ַ��������ع�������ַ�����
�սڵ�ʹ��һ�Կ����Ŷ� "()" ��ʾ��ת������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
*/

#include<string>
using std::string;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

class Solution {
public:
    void _tree2str(TreeNode* root, string& str) {
        if (root == nullptr)
            return;
        str += std::to_string(root->val);
        if (root->left) {
            str += '(';
            _tree2str(root->left, str);
            str += ')';
        }
        else if (root->right) {
            str += "()";
        }
        if (root->right) {
            str += '(';
            _tree2str(root->right, str);
            str += ')';
        }
    }
    string tree2str(TreeNode* root) {
        string str;
        _tree2str(root, str);
        return str;
    }

};