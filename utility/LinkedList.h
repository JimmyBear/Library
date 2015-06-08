#ifndef __UTILITY_LINKEDLIST_H
#define __UTILITY_LINKEDLIST_H

#include "stddef.h"

namespace utility
{
	class LinkedList
	{
	public:
		static const int EMPTY = -1;

		struct Node
		{
			Node() : iData(0), pstNext(NULL) {};
			int		iData;
			Node*	pstNext;
		};

		LinkedList();
		virtual ~LinkedList();

		// insert a node
		virtual void Push(int iData) = 0;

		// remove a node
		virtual int Pop() = 0;

		void Print();
		void Revert();

	protected:
		Node*	m_pstHead;
		Node*	m_pstTail;
	};

	class Queue : public LinkedList
	{
	public:
		~Queue();
		void Push(int iData);
		int Pop();
	};

	class Stack : public LinkedList
	{
	public:
		~Stack();
		void Push(int iData);
		int Pop();
	};
};

#endif // __UTILITY_LINKEDLIST_H