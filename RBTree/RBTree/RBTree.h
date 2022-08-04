#pragma once
#include<assert.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum Colour
{
	RED,
	BLACK,
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		// 1、搜索树的插入规则
		// 2、看是否违反平衡规则
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
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
		cur->_col = RED; //插入结点为红色
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;


		//存在连续的红结点
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			assert(grandfather);

			//parent在左
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//情况一
				if (uncle && uncle->_col == RED) //叔叔存在且为红色
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理

					cur = grandfather;
					parent = cur->_parent;
				}
				else // 叔叔 不存在 或者 存在且为黑
				{
					//情况二
					if (cur == parent->_left) //右单旋
					{
						//    g
						//  p
						//c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;

					}
					//情况三
					else //左右双旋
					{
						//    g
						//  p
						//    c

						RotateL(parent);
						RotateR(grandfather);
						
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			//parent在右
			else  //(grandfather->_right == parent)
			{
				Node* uncle = grandfather->_left;
				//情况一
				if (uncle && uncle->_col == RED) //叔叔存在且为红色
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上处理

					cur = grandfather;
					parent = cur->_parent;
				}
				else // 叔叔 不存在 或者 存在且为黑
				{
					//情况二
					if (cur == parent->_right) //左单旋
					{
						// g
						//   p
						//     c
						RotateL(grandfather);

						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//情况三
					else //(cur == parent->_left) 右左双旋
					{
						// g
						//   p
						// c
						RotateR(parent);
						RotateL(grandfather);

						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void Height()
	{
		cout << "最长路径:" << _maxHeight(_root) << endl;
		cout << "最短路径:" << _minHeight(_root) << endl;
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

	//检查是否是红黑树
	bool IsBalanceRBTree()
	{
		if (_root == nullptr) //空树是红黑树
			return true;

		// 检查根节点是否是红黑树
		if (BLACK != _root->_col)
		{
			cout << "违反红黑树性质二：根节点必须是黑色" << endl;
			return false;
		}

		//获取任意一条路径中的黑色结点个数——比较基准值
		size_t blackCount = 0;
		Node* cur = _root;
		while (cur)
		{
			if (BLACK == cur->_col)
			{
				++blackCount;
			}
			cur = cur->_left;
		}

		//检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(_root, k, blackCount);	
	}

private:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
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
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	int _maxHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lh = _maxHeight(root->_left);
		int rh = _maxHeight(root->_right);

		return lh > rh ? lh + 1 : rh + 1;
	}

	int _minHeight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int lh = _minHeight(root->_left);
		int rh = _minHeight(root->_right);

		return lh < rh ? lh + 1 : rh + 1;
	}

	bool _IsValidRBTree(Node* root, size_t k, const size_t& blackCount)
	{
		//走到空, 判断 k 和 blackCount是否相等
		if (nullptr == root)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点个数必须相等" << endl;
				return false;
			}
			return true;
		}
		// 统计黑色节点的个数
		if (BLACK == root->_col)
			++k;

		//检查当前节点与其双亲节点是否都为红色
		if (RED == root->_col && root->_parent && RED == root->_parent->_col)
		{
			cout << "违反性质三：存在连在一起的红色节点" << endl;
			return false;
		}

		return _IsValidRBTree(root->_left, k, blackCount) && _IsValidRBTree(root->_right, k, blackCount);
	}

private:
	Node* _root = nullptr;
};

