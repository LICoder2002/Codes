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
	AVLTreeNode<K, V>* _left; //�ýڵ������
	AVLTreeNode<K, V>* _right;  //�ýڵ���Һ���
	AVLTreeNode<K, V>* _parent;  //�ýڵ��˫��

	int _bf; //ƽ������

	AVLTreeNode(const pair<K,V>& kv) //���캯��
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
		// 1���������Ĳ������
		// 2�����Ƿ�Υ��ƽ�������Υ������Ҫ����ת������
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

		//�ҵ��˲���λ��
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

		//����ƽ������

		while (parent) //��Զ���µ�parent
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			//�ж��Ƿ��������
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == -1 || parent->_bf == 1) // ��ʱ��������Ǳ߱����
			{
				//������������
				cur = cur->_parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2) // ������ʹ�ñ����ߵ�һ���ֱ���� -> ��ת
			{
				if (parent->_bf == 2 && cur->_bf == 1) // ����
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1) // �ҵ���
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1) // ����˫��
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1) // ����˫��
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
				assert(false);  // �������ʹ�������
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

	int Height()
	{
		return _Height(_root);
	}
private:

	bool _IsBalanceTree(Node* root)
	{
		// ����Ҳ��AVL��
		if (nullptr == root)
			return true;

		// ����root�ڵ��ƽ�����ӣ���root���������ĸ߶Ȳ�
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;

		// ����������ƽ��������root��ƽ�����Ӳ���ȣ�����
		// rootƽ�����ӵľ���ֵ����1����һ������AVL��
		if (abs(diff) >= 2) // ÿ���ڵ������߶Ȳ�ľ���ֵ������1
		{
			cout << root->_kv.first << "�ڵ�ƽ�������쳣" << endl;
			return false;
		}

		if (diff != root->_bf) // �ڵ��ƽ�������Ƿ������ȷ
		{
			cout << root->_kv.first << "�ڵ�ƽ�����Ӳ�����ʵ��" << endl;
			return false;
		}

		// root��������������AVL���������һ����AVL��
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
		subR->_bf = parent->_bf = 0; //����ƽ������
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


		//����ƽ������
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

		//����ƽ������
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