#include "LinkedList.h"
#include "stdio.h"

namespace utility
{
// ========== LinkedList ==========
	LinkedList::LinkedList() :
		m_pstHead(NULL),
		m_pstTail(NULL)
	{
	}

	LinkedList::~LinkedList()
	{
	}

	void LinkedList::Print()
	{
		Node* pstOpNode = m_pstHead;

		while (pstOpNode != NULL)
		{
			printf("%d ", pstOpNode->iData);
			pstOpNode = pstOpNode->pstNext;
		}
	}

	void LinkedList::Revert()
	{
		Node* pstOpNode = m_pstHead;
		Node* pstTailNode = NULL;
		Node* pstTempNode = NULL;

		while (pstOpNode != NULL)
		{
			pstTempNode = pstOpNode->pstNext;
			pstOpNode->pstNext = pstTailNode;
			pstTailNode = pstOpNode;
			pstOpNode = pstTempNode;
		}

		m_pstTail = m_pstHead;
		m_pstHead = pstTailNode;
	}

// ========== Queue ==========
	Queue::~Queue()
	{
	}

	void Queue::Push(int iData)
	{
		Node* pstNode = new Node;
		pstNode->iData = iData;

		if (m_pstHead == NULL)
		{
			m_pstHead = m_pstTail = pstNode;
		}
		else
		{
			m_pstTail->pstNext = pstNode;
			m_pstTail = pstNode;
		}
	}

	int Queue::Pop()
	{
		if (m_pstHead == NULL)
			return EMPTY;

		int iResult = m_pstHead->iData;
		Node* pstNode = m_pstHead;
		m_pstHead = m_pstHead->pstNext;

		// free the node
		pstNode->pstNext = NULL;
		delete pstNode;

		return iResult;
	}

// ========== Stack ==========
	Stack::~Stack()
	{
	}

	void Stack::Push(int iData)
	{
		Node* pstNode = new Node;
		pstNode->iData = iData;

		if (m_pstHead == NULL)
		{
			m_pstHead = pstNode;
		}
		else
		{
			pstNode->pstNext = m_pstHead;
			m_pstHead = pstNode;
		}
	}

	int Stack::Pop()
	{
		if (m_pstHead == NULL)
			return EMPTY;

		int iResult = m_pstHead->iData;
		Node* pstNode = m_pstHead;
		m_pstHead = m_pstHead->pstNext;

		// free the node
		pstNode->pstNext = NULL;
		delete pstNode;

		return iResult;
	}
};

