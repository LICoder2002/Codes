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
			//���������棬�����Ǹ�������Ǹ�
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
			//������������ڵ�
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
			//���������棬���������棬�����Ǹ����ҵ��Ǹ�
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
			//�����������ҽڵ�
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

// T�����������ʲô����
// set  RBTree<K, K>
// map  RBTree<K, pair<K, V>>
// KeyOfT -> ֧��ȡ��T������key�ķº���
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
		// 1���������Ĳ������
		// 2�����Ƿ�Υ��ƽ�����
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

		//�ҵ��˲���λ��
		cur = new Node(data);
		Node* newnode = cur;
		cur->_col = RED; //������Ϊ��ɫ
		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;


		//���������ĺ���
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			//assert(grandfather);

			//parent����
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//���һ
				if (uncle && uncle->_col == RED) //���������Ϊ��ɫ
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���

					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���� ������ ���� ������Ϊ��
				{
					//�����
					if (cur == parent->_left) //�ҵ���
					{
						//    g
						//  p
						//c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;

					}
					//�����
					else //����˫��
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
			//parent����
			else  //(grandfather->_right == parent)
			{
				Node* uncle = grandfather->_left;
				//���һ
				if (uncle && uncle->_col == RED) //���������Ϊ��ɫ
				{
					//��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϴ���

					cur = grandfather;
					parent = cur->_parent;
				}
				else // ���� ������ ���� ������Ϊ��
				{
					//�����
					if (cur == parent->_right) //����
					{
						// g
						//   p
						//     c
						RotateL(grandfather);

						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					//�����
					else //(cur == parent->_left) ����˫��
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

