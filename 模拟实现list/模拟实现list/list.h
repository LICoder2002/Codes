#pragma once
#include<assert.h>
#include<iostream>
#include"Reverse_iterator.h"

namespace lhf
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		list_node(const T& val = T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(val)
		{}

	};


	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T, Ref, Ptr> self;
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{}

		// 析构函数  -- 节点不属于迭代器，不需要迭代器释放
		// 拷贝构造和赋值重载 -- 默认生成的浅拷贝就可以

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}


		//前置++
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//后置++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		//前置--
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//后置--
		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}


		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}
	};


	template<class T>

	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;


		const_iterator begin()const 
		{
			return const_iterator(_head->_next);
			//return _head->_next;
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return iterator(_head->_next);
			//return _head->_next;
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_reverse_iterator rbegin()const
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rend()const
		{
			return reverse_iterator(begin());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
		}

		void empty_init()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
		}


		list()
		{
			empty_init();
		}
		
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& lt)
		{
			empty_init();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_back(const T& x)
		{
			//Node* tail = _head->_prev;
			//Node* newnode = new Node(x);

			//tail->_next = newnode;
			//newnode->_next = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;

			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		//pos前插入x
		iterator insert(iterator pos, const T& x)
		{
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;

			prev->_next = next;
			next->_prev = prev;
			delete cur;

			return iterator(next);
		}

	private:
		Node* _head;
	};
}
