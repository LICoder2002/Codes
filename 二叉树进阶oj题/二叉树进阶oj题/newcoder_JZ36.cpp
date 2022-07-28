//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

/*
����
����һ�ö��������������ö���������ת����һ�������˫����������ͼ��ʾ
���ݷ�Χ������������Ľڵ��� 0 \le n \le 10000��n��1000����������ÿ���ڵ��ֵ 0\le val \le 10000��val��1000
Ҫ�󣺿ռ临�Ӷ�O(1)O(1)������ԭ���ϲ�������ʱ�临�Ӷ� O(n)O(n)
ע��:
1.Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ�򡣵�ת������Ժ����нڵ����ָ����Ҫָ��ǰ�������нڵ����ָ����Ҫָ����
2.���������еĵ�һ���ڵ��ָ��
3.�������ص�TreeNode��������ָ�룬��ʵ���Կ���һ��˫����������ݽṹ
4.�㲻�����˫����������������ķ���ֵ�Զ���ӡ���
����������
�������ĸ��ڵ�
����ֵ������
˫�����������һ��ͷ�ڵ㡣
*/

#include<vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};
class Solution {
    std::vector<TreeNode* > ret;
public:

    void InOrder(TreeNode* root)
    {
        if (root == nullptr)
            return;

        InOrder(root->left);
        ret.push_back(root);
        InOrder(root->right);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr)
            return pRootOfTree;

        InOrder(pRootOfTree);

        for (int i = 0; i < ret.size() - 1; ++i)
        {
            ret[i]->right = ret[i + 1];
            ret[i + 1]->left = ret[i];
        }
        return ret[0];

    }
};