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
		// 1���������Ĳ������
		// 2�����Ƿ�Υ��ƽ�����
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

		//�ҵ��˲���λ��
		cur = new Node(kv);
		cur->_col = RED; //������Ϊ��ɫ
		if (parent->_kv.first < kv.first)
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
			assert(grandfather);

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
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void Height()
	{
		cout << "�·��:" << _maxHeight(_root) << endl;
		cout << "���·��:" << _minHeight(_root) << endl;
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
			// levelSize����һ��һ���
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

			// ��һ����꣬��һ��Ͷ�������
			levelSize = q.size();
		}

		return vv;
	}

	//����Ƿ��Ǻ����
	bool IsBalanceRBTree()
	{
		if (_root == nullptr) //�����Ǻ����
			return true;

		// �����ڵ��Ƿ��Ǻ����
		if (BLACK != _root->_col)
		{
			cout << "Υ����������ʶ������ڵ�����Ǻ�ɫ" << endl;
			return false;
		}

		//��ȡ����һ��·���еĺ�ɫ�����������Ƚϻ�׼ֵ
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

		//����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
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
		//�ߵ���, �ж� k �� blackCount�Ƿ����
		if (nullptr == root)
		{
			if (k != blackCount)
			{
				cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�����������" << endl;
				return false;
			}
			return true;
		}
		// ͳ�ƺ�ɫ�ڵ�ĸ���
		if (BLACK == root->_col)
			++k;

		//��鵱ǰ�ڵ�����˫�׽ڵ��Ƿ�Ϊ��ɫ
		if (RED == root->_col && root->_parent && RED == root->_parent->_col)
		{
			cout << "Υ������������������һ��ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		return _IsValidRBTree(root->_left, k, blackCount) && _IsValidRBTree(root->_right, k, blackCount);
	}

private:
	Node* _root = nullptr;
};

