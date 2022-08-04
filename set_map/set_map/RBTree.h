#pragma once
#include<iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK,
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;

	Colour _col;

	RBTreeNode(const T& data)
		:_data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{}
};

template<class T, class Ref, class Ptr>
struct __RBTreeIterator
{
	typedef RBTreeNode<T> Node;

	typedef __RBTreeIterator<T, Ref, Ptr> self;
	Node* _node;

	__RBTreeIterator(Node* node)
		:_node(node)
	{}

	Ref operator*()
	{
		return _node->_data;
	}

	Ptr operator->()
	{
		return &_node->_data;
	}

	self& operator++()
	{
		if (_node->_right == nullptr)
		{
			//找祖先里面，孩子是父亲左的那个
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = cur->_parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		else
		{
			//右子树的最左节点
			Node* subL = _node->_right;
			while (subL->_left)
			{
				subL = subL->_left;
			}
			_node = subL;
		}

		return *this;
	}

	self operator++(int)
	{
		self tmp(*this);
		++(*this);
		return tmp;
	}

	self& operator--()
	{
		if (_node->_left == nullptr)
		{
			//找祖先里面，找祖先里面，孩子是父亲右的那个
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_left)
			{
				cur = cur->_parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		else
		{
			//左子树的最右节点
			Node* subR = _node->_left;
			while (subR->_right)
			{
				subR = subR->_left;
			}
			_node = subR;
		}
		return *this;
	}

	self operator--(int)
	{
		self tmp(*this);
		--(*this);
		return tmp;
	}

	bool operator!=(const self& s)
	{
		return _node != s._node;
	}

	bool operator==(const self& s)
	{
		return _node == s._node;
	}

};

// T决定红黑树存什么数据
// set  RBTree<K, K>
// map  RBTree<K, pair<K, V>>
// KeyOfT -> 支持取出T对象中key的仿函数
template<class K, class T, class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:

	typedef __RBTreeIterator<T, T&, T*> iterator;
	typedef __RBTreeIterator<T, const T&, const T*> const_iterator;

	iterator Begin()
	{
		Node* subL = _root;
		while (subL && subL->_left)
		{
			subL = subL->_left;
		}
		return subL;
	}

	iterator End()
	{
		return iterator(nullptr);
	}

	const_iterator Begin() const
	{
		Node* subL = _root;
		while (subL && subL->_left)
		{
			subL = subL->_left;
		}
		return subL;
	}

	const_iterator End() const
	{
		return const_iterator(nullptr);
	}

	pair<iterator,bool> Insert(const T& data)
	{
		// 1、搜索树的插入规则
		// 2、看是否违反平衡规则
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
		    return make_pair(iterator(_root), true);

		}

		KeyOfT kot;

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), true);
			}
		}

		//找到了插入位置
		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED; //插入结点为红色
		if (kot(parent->_data) < kot(data))
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
			//assert(grandfather);

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
		return make_pair(iterator(newnode), true);
	}

	iterator Find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;

		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return iterator(cur);
			}
		}
		return End();
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


private:
	Node* _root = nullptr;
};

