#pragma once
#include<assert.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left; //该节点的左孩子
	AVLTreeNode<K, V>* _right;  //该节点的右孩子
	AVLTreeNode<K, V>* _parent;  //该节点的双亲

	int _bf; //平衡因子

	AVLTreeNode(const pair<K,V>& kv) //构造函数
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		// 1、搜索树的插入规则
		// 2、看是否违反平衡规则，若违反则需要“旋转”处理
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		//找到了插入位置
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//更新平衡因子

		while (parent) //最远更新到parent
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			//判断是否继续更新
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == -1 || parent->_bf == 1) // 此时插入结点的那边变高了
			{
				//继续更新祖先
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2) // 插入结点使得本来高的一边又变高了 -> 旋转
			{
				if (parent->_bf == 2 && cur->_bf == 1) // 左单旋
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1) // 右单旋
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) // 左右双旋
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) // 右左双旋
				{
					RotateRL(parent);
				}
				else
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);  // 树本来就存在问题
			}
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

	vector<vector<int>> levelOrder() {
		vector<vector<int>> vv;
		if (_root == nullptr)
			return vv;

		queue<Node*> q;
		int levelSize = 1;
		q.push(_root);

		while (!q.empty())
		{
			// levelSize控制一层一层出
			vector<int> levelV;
			while (levelSize--)
			{
				Node* front = q.front();
				q.pop();
				levelV.push_back(front->_kv.first);
				if (front->_left)
					q.push(front->_left);

				if (front->_right)
					q.push(front->_right);
			}
			vv.push_back(levelV);
			for (auto e : levelV)
			{
				cout << e << " ";
			}
			cout << endl;

			// 上一层出完，下一层就都进队列
			levelSize = q.size();
		}

		return vv;
	}

	int Height()
	{
		return _Height(_root);
	}
private:

	bool _IsBalanceTree(Node* root)
	{
		// 空树也是AVL树
		if (nullptr == root)
			return true;

		// 计算root节点的平衡因子：即root左右子树的高度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;

		// 如果计算出的平衡因子与root的平衡因子不相等，或者
		// root平衡因子的绝对值超过1，则一定不是AVL树
		if (abs(diff) >= 2) // 每个节点子树高度差的绝对值不超过1
		{
			cout << root->_kv.first << "节点平衡因子异常" << endl;
			return false;
		}

		if (diff != root->_bf) // 节点的平衡因子是否计算正确
		{
			cout << root->_kv.first << "节点平衡因子不符合实际" << endl;
			return false;
		}

		// root的左和右如果都是AVL树，则该树一定是AVL树
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}


	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lh = _Height(root->_left);
		int rh = _Height(root->_right);

		return lh > rh ? lh + 1 : rh + 1;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if(subRL)
			subRL->_parent = parent;

		Node* grandParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == grandParent->_left)
			{
				grandParent->_left = subR;
			}
			else
			{
				grandParent->_right = subR;
			}
			subR->_parent = grandParent;
		}
		subR->_bf = parent->_bf = 0; //更新平衡因子
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* grandParent = parent->_parent;
		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == grandParent->_left)
			{
				grandParent->_left = subL;
			}
			else
			{
				grandParent->_right = subL;
			}
			subL->_parent = grandParent;
		}

		subL->_bf = parent->_bf = 0;

	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);


		//更新平衡因子
		if (1 == bf)
			subL->_bf = -1;
		else if (-1 == bf)
			parent->_bf = 1;
		else
		{
			assert(false);
		}
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		//更新平衡因子
		if (1 == bf)
		{
			parent->_bf = -1;
		}
		else if(-1 == bf)
		{
			subR->_bf = 1;
		}
		else
		{
			assert(false);
		}
	}

private:
	Node* _root = nullptr;
};