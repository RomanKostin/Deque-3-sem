#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Deque.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SolverTest
{
	TEST_CLASS(SolverTest)
	{
	public:
		
		TEST_METHOD(EmptyIntDeque_Success)
		{
			rut::Deque<int> deq;
			Assert::IsTrue(deq.IsEmpty());
		}
		TEST_METHOD(PushFrontOneTimeInt_ValidData_Success)
		{
			rut::Deque<int> deq;
			deq.push_front(1);
			Assert::AreEqual(deq.front(), 1);
		}
		TEST_METHOD(PushFrontFewTimesInt_ValidData_Success)
		{
			rut::Deque<int> deq;
			deq.push_front(1);
			deq.push_front(2);
			Assert::AreEqual(deq.front(), 2);
		}
		TEST_METHOD(PushBackOneTimeInt_ValidData_Success)
		{
			rut::Deque<int> deq;
			deq.push_back(1);
			Assert::AreEqual(deq.back(), 1);
		}
		TEST_METHOD(PushBackFewTimesInt_ValidData_Success)
		{
			rut::Deque<int> deq;
			deq.push_back(1);
			deq.push_back(2);
			Assert::AreEqual(deq.back(), 2);
		}
		TEST_METHOD(PushBackAndPushFrontInt_ValidData_Success)
		{
			rut::Deque<int> deq;
			deq.push_front(1);
			deq.push_back(4);
			Assert::AreEqual(deq.front(), 1);
			Assert::AreEqual(deq.back(), 4);
		}
		TEST_METHOD(PopFrontInt_ValidData_Success)
		{
			rut::Deque deq{ 1,2,3 };
			deq.pop_front();
			Assert::AreEqual(deq.front(), 2);
			Assert::AreEqual(deq.back(), 3);
		}
		TEST_METHOD(PopBackInt_ValidData_Success)
		{
			rut::Deque deq{ 1,2,3 };
			deq.pop_back();
			Assert::AreEqual(deq.front(), 1);
			Assert::AreEqual(deq.back(), 2);
		}
		TEST_METHOD(EqualDequesConstructionInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2(deq1);
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(), deq2.front());
		}
		TEST_METHOD(EqualDequesByOperatorInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2 = deq1;
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(), deq2.front());
		}
		TEST_METHOD(MoveConstructorInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2(std::move(deq1));
			Assert::AreEqual(deq2.front(), 1);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), 2);
			Assert::AreEqual(deq2.back(), 3);
		}
		TEST_METHOD(OperatorMoveInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2,3 }, deq2 = std::move(deq1);
			Assert::AreEqual(deq2.front(), 1);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), 2);
			Assert::AreEqual(deq2.back(), 3);
		}
		
		
		TEST_METHOD(EmptyDoubleDeque_Success)
		{
			rut::Deque<double> deq;
			Assert::IsTrue(deq.IsEmpty());
		}
		TEST_METHOD(PushFrontOneTimeDouble_ValidData_Success)
		{
			rut::Deque<double> deq;
			deq.push_front(1.23);
			Assert::AreEqual(deq.front(), 1.23);
		}
		TEST_METHOD(PushFrontFewTimesDouble_ValidData_Success)
		{
			rut::Deque<double> deq;
			deq.push_front(1.23);
			deq.push_front(2.43);
			Assert::AreEqual(deq.front(), 2.43);
		}
		TEST_METHOD(PushBackOneTimeDouble_ValidData_Success)
		{
			rut::Deque<double> deq;
			deq.push_back(1.23);
			Assert::AreEqual(deq.back(), 1.23);
		}
		TEST_METHOD(PushBackFewTimesDouble_ValidData_Success)
		{
			rut::Deque<double> deq;
			deq.push_back(1.23);
			deq.push_back(2.43);
			Assert::AreEqual(deq.back(), 2.43);
		}
		TEST_METHOD(PushBackAndPushFrontDouble_ValidData_Success)
		{
			rut::Deque<double> deq;
			deq.push_front(1.23);
			deq.push_back(4.56);
			Assert::AreEqual(deq.front(), 1.23);
			Assert::AreEqual(deq.back(), 4.56);
		}
		TEST_METHOD(PopFrontDouble_ValidData_Success)
		{
			rut::Deque deq{ 1.23,2.43,3.33 };
			deq.pop_front();
			Assert::AreEqual(deq.front(), 2.43);
			Assert::AreEqual(deq.back(), 3.33);
		}
		TEST_METHOD(PopBackDouble_ValidData_Success)
		{
			rut::Deque deq{ 1.23,2.43,3.33 };
			deq.pop_back();
			Assert::AreEqual(deq.front(), 1.23);
			Assert::AreEqual(deq.back(), 2.43);
		}
		TEST_METHOD(EqualDequesConstructionDouble_ValidData_Success)
		{
			rut::Deque deq1{ 1.23,2.43,3.33 }, deq2(deq1);
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(), deq2.front());
		}
		TEST_METHOD(EqualDequesByOperatorDouble_ValidData_Success)
		{
			rut::Deque deq1{ 1.23,2.43,3.33 }, deq2 = deq1;
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(), deq2.front());
		}
		TEST_METHOD(MoveConstructorDouble_ValidData_Success)
		{
			rut::Deque deq1{ 1.23,2.43,3.33 }, deq2(std::move(deq1));
			Assert::AreEqual(deq2.front(), 1.23);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), 2.43);
			Assert::AreEqual(deq2.back(), 3.33);
		}
		TEST_METHOD(OperatorMoveDouble_ValidData_Success)
		{
			rut::Deque deq1{ 1.23,2.43,3.33 }, deq2 = std::move(deq1);
			Assert::AreEqual(deq2.front(), 1.23);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), 2.43);
			Assert::AreEqual(deq2.back(), 3.33);
		}

		TEST_METHOD(EmptyStringDeque_Success)
		{
			rut::Deque <std::string> deq;
			Assert::IsTrue(deq.IsEmpty());
		}
		TEST_METHOD(PushFrontOneTimeString_ValidData_Success)
		{
			rut::Deque<std::string> deq;
			deq.push_front("test");
			std::string expected = "test";
			Assert::AreEqual(deq.front(), expected);
		}
		TEST_METHOD(PushFrontFewTimesString_ValidData_Success)
		{
			rut::Deque<std::string> deq;
			deq.push_front("test1");
			deq.push_front("test2");
			std::string expected = "test2";
			Assert::AreEqual(deq.front(), expected);
		}
		TEST_METHOD(PushBackOneTimeString_ValidData_Success)
		{
			rut::Deque <std::string> deq;
			deq.push_back("test");
			std::string expected = "test";
			Assert::AreEqual(deq.back(), expected);
		}
		TEST_METHOD(PushBackFewTimesString_ValidData_Success)
		{
			rut::Deque<std::string> deq;
			deq.push_back("test1");
			deq.push_back("test2");
			std::string expected = "test2";
			Assert::AreEqual(deq.back(), expected);
		}
		TEST_METHOD(PushBackAndPushFrontString_ValidData_Success)
		{
			rut::Deque <std::string> deq;
			deq.push_front("test1");
			deq.push_back("test2");
			std::string expected1 = "test1";
			std::string expected2 = "test2";
			Assert::AreEqual(deq.front(), expected1);
			Assert::AreEqual(deq.back(), expected2);
		}
		TEST_METHOD(PopFrontString_ValidData_Success)
		{
			rut::Deque <std::string> deq{ "test1","test2","test3" };
			deq.pop_front();
			std::string expected2 = "test2";
			std::string expected3 = "test3";
			Assert::AreEqual(deq.front(), expected2);
			Assert::AreEqual(deq.back(), expected3);
		}
		TEST_METHOD(PopBackString_ValidData_Success)
		{
			rut::Deque<std::string> deq{ "test1","test2","test3"};
			deq.pop_back();
			std::string expected1 = "test1";
			std::string expected2 = "test2";
			Assert::AreEqual(deq.front(), expected1);
			Assert::AreEqual(deq.back(), expected2);
		}
		TEST_METHOD(EqualDequesConstructionString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1","test2","test3"}, deq2(deq1);
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(), deq2.front());
		}
		TEST_METHOD(EqualDequesByOperatorString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1","test2","test3"}, deq2 = deq1;
			Assert::AreEqual(deq1.front(), deq2.front());
			Assert::AreEqual(deq1.back(), deq2.back());
			deq1.pop_front();
			deq2.pop_front();
			Assert::AreEqual(deq1.front(), deq2.front());
		}
		TEST_METHOD(MoveConstructorString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1", "test2", "test3" }, deq2(std::move(deq1));
			std::string expected1 = "test1";
			std::string expected2 = "test2";
			std::string expected3 = "test3";
			Assert::AreEqual(deq2.front(), expected1);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), expected2);
			Assert::AreEqual(deq2.back(), expected3);
		}
		TEST_METHOD(OperatorMoveString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1","test2" ,"test3"}, deq2 = std::move(deq1);
			std::string expected1 = "test1";
			std::string expected2 = "test2";
			std::string expected3 = "test3";
			Assert::AreEqual(deq2.front(), expected1);
			deq2.pop_front();
			Assert::AreEqual(deq2.front(), expected2);
			Assert::AreEqual(deq2.back(), expected3);
		}
	};
}
