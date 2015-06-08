
#include "gtest/gtest.h"
#include "LinkedList.h"

//------------------------------------------------------------------------------------------
// 
using namespace utility;

// The test case of Queue::Push and Queue::Pop
TEST(QueueTest, PushAndPop)
{
	Queue cQueue;
	cQueue.Push(1);
	cQueue.Push(2);
	cQueue.Push(3);
	cQueue.Push(4);
	cQueue.Push(5);
	//cQueue.Print(); // 1 2 3 4 5

	EXPECT_EQ(cQueue.Pop(), 1);
	EXPECT_EQ(cQueue.Pop(), 2);
	EXPECT_EQ(cQueue.Pop(), 3);
	EXPECT_EQ(cQueue.Pop(), 4);
	EXPECT_EQ(cQueue.Pop(), 5);
	//cQueue.Print(); //

	EXPECT_EQ(cQueue.Pop(), Queue::EMPTY);
}

// The test case of Queue::Reverse
TEST(QueueTest, Reverse)
{
	Queue cQueue;
	cQueue.Push(1);
	cQueue.Push(2);
	cQueue.Push(3);
	cQueue.Push(4);
	cQueue.Push(5);
	//cQueue.Print(); // 1 2 3 4 5

	cQueue.Revert();

	EXPECT_EQ(cQueue.Pop(), 5);
	EXPECT_EQ(cQueue.Pop(), 4);
	EXPECT_EQ(cQueue.Pop(), 3);
	EXPECT_EQ(cQueue.Pop(), 2);
	EXPECT_EQ(cQueue.Pop(), 1);
	//cQueue.Print(); //

	EXPECT_EQ(cQueue.Pop(), Queue::EMPTY);
}

// The test case of Stack::Push and Stack::Pop
TEST(StackTest, PushAndPop)
{
	Stack cStack;
	cStack.Push(1);
	cStack.Push(2);
	cStack.Push(3);
	cStack.Push(4);
	cStack.Push(5);
	//cStack.Print(); // 5 4 3 2 1

	EXPECT_EQ(cStack.Pop(), 5);
	EXPECT_EQ(cStack.Pop(), 4);
	EXPECT_EQ(cStack.Pop(), 3);
	EXPECT_EQ(cStack.Pop(), 2);
	EXPECT_EQ(cStack.Pop(), 1);
	//cStack.Print(); //

	EXPECT_EQ(cStack.Pop(), Queue::EMPTY);
}

// The test case of Stack::Reverse
TEST(StackTest, Reverse)
{
	Stack cStack;
	cStack.Push(1);
	cStack.Push(2);
	cStack.Push(3);
	cStack.Push(4);
	cStack.Push(5);
	//cStack.Print(); // 5 4 3 2 1

	cStack.Revert();

	EXPECT_EQ(cStack.Pop(), 1);
	EXPECT_EQ(cStack.Pop(), 2);
	EXPECT_EQ(cStack.Pop(), 3);
	EXPECT_EQ(cStack.Pop(), 4);
	EXPECT_EQ(cStack.Pop(), 5);
	//cStack.Print(); //

	EXPECT_EQ(cStack.Pop(), Stack::EMPTY);
}