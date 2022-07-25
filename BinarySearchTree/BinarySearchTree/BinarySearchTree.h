#pragma once

#include<algorithm>
#include<iostream>
using namespace std;

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;

	K _key;

	BSTreeNode(const K& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
	{}
};


template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;



public:
	BSTree() = default;//C++11、强制编译器自己生成构造函数

	BSTree(const BSTree<K>& t)
	{
		_root = CopyTree(t._root);
	}

	BSTree<K>& operator=(BSTree<K> t)
	{
		std::swap(_root, t._root);

		return *this;
	}

	~BSTree()
	{
		DestoryTree(_root);
		_root = nullptr;
	}

	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;//存在重复元素
			}
		}

		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}


	//bool Erase(const K& key)
	//{
	//	Node* parent = nullptr;
	//	Node* cur = _root;
	//	while (cur)
	//	{
	//		if (cur->_key < key)
	//		{
	//			parent = cur;
	//			cur = cur->_right;
	//		}
	//		else if (cur->_key > key)
	//		{
	//			parent = cur;
	//			cur = cur->_left;
	//		}
	//		else
	//		{
	//			// 一个孩子--左为空 or 右为空
	//			// 两个孩子 -- 替换法
	//			if (cur->_left == nullptr)
	//			{
	//				//if (parent == nullptr)
	//				if (cur == _root)
	//				{
	//					_root = cur->_right;
	//				}
	//				else
	//				{
	//					if (cur == parent->_left)
	//					{
	//						parent->_left = cur->_right;
	//					}
	//					else
	//					{
	//						parent->_right = cur->_right;
	//					}
	//				}
	//				delete cur;
	//			}
	//			else if (cur->_right == nullptr)
	//			{
	//				//if (parent == nullptr)
	//				if (cur == _root)
	//				{
	//					_root = cur->_left;
	//				}
	//				else
	//				{
	//					if (cur == parent->_left)
	//					{
	//						parent->_left = cur->_left;
	//					}
	//					else
	//					{
	//						parent->_right = cur->_left;
	//					}
	//				}

	//				delete cur;
	//			}
	//			else // 两个孩子都不为空
	//			{
	//				// 右子树的最小节点替代
	//				Node* minParent = cur;
	//				Node* minRight = cur->_right;
	//				while (minRight->_left)
	//				{
	//					minParent = minRight;
	//					minRight = minRight->_left;
	//				}

	//				swap(minRight->_key, cur->_key);
	//				//cur->_key = minRight->_key;
	//				if (minParent->_left == minRight)
	//				{
	//					minParent->_left = minRight->_right;
	//				}
	//				else
	//				{
	//					minParent->_right = minRight->_right;
	//				}

	//				delete minRight;
	//			}

	//			return true;
	//		}
	//	}

	//	return false;
	//}


	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{

				//一个孩子   左空/右空
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
				}
				//两个孩子
				else
				{
					Node* minRight = cur->_right;
					Node* minParent = cur;
					while (minRight->_left)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}
					//cur->_key = minRight->_key;
					swap(minRight->_key, cur->_key);
					if (minParent->_left == minRight)
					{
						minParent->_left = minRight->_right;
					}
					else
					{
						minParent->_right = minRight->_right;
					}
					delete minRight;
				}
				return true;
			}

		}
		return false;

	}

	bool FindR(const K& key)
	{
		return _FindR(_root, key);
	}


	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}

	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}

private:

	bool _EraseR(Node*& root, const K& key)
	{
		if (root == nullptr)
			return false;

		if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else
		{
			Node* del = root;

			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* minRight = root->_right;
				while (minRight->_left)
				{
					minRight = minRight->_left;
				}

				swap(root->_key, minRight->_key);

				return _EraseR(root->_right, key);
			}
			delete del;
			return true;
		}
	}

	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}

		if (root->_key > key)
		{
			return _InsertR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _InsertR(root->_right, key);
		}
		else
		{
			return false;
		}
	}

	void DestoryTree(Node* root)
	{
		if (root == nullptr)
			return;
		DestoryTree(root->_left);
		DestoryTree(root->_right);
		delete root;
	}

	Node* CopyTree(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* copyNode = new Node(root->_key);
		copyNode->_left = CopyTree(root->_left);
		copyNode->_right = CopyTree(root->_right);

		return copyNode;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	bool _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
			return false;
		if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _FindR(root->_left, key);
		}
		else
		{
			return true;
		}
	}


private:
	Node* _root = nullptr;
};


