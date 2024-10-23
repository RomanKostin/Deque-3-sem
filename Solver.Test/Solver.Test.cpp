#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Deque.h"
#include "..\TestClass\Angle.h"
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
			Assert::IsTrue(deq.front()== 1&&deq.back()==4);
		}
		TEST_METHOD(PopFrontInt_ValidData_Success)
		{
			rut::Deque deq{ 1,2,3 };
			deq.pop_front();
			Assert::IsTrue(deq.front() == 2 && deq.back() == 3);
		}
		TEST_METHOD(PopBackInt_ValidData_Success)
		{
			rut::Deque deq{ 1,2,3 };
			deq.pop_back();
			Assert::IsTrue(deq.front()== 1&& deq.back()== 2);
		}
		TEST_METHOD(EqualDequesConstructionInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2 }, deq2(deq1);
			Assert::IsTrue(deq1.front()== deq2.front()&&deq1.back()==deq2.back());
		}
		TEST_METHOD(EqualDequesByOperatorInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2}, deq2 = deq1;
			Assert::IsTrue(deq1.front() == deq2.front() && deq1.back() == deq2.back());
		}
		TEST_METHOD(MoveConstructorInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2}, deq2(std::move(deq1));
			Assert::IsTrue(deq2.front() == 1 && deq2.back() == 2);
		}
		TEST_METHOD(OperatorMoveInt_ValidData_Success)
		{
			rut::Deque deq1{ 1,2 }, deq2 = std::move(deq1);
			Assert::IsTrue(deq2.front() == 1 && deq2.back() == 2);
		}
		
		
		TEST_METHOD(EmptyAngleDeque_Success)
		{
			rut::Deque<Angle::Angle> deq;
			Assert::IsTrue(deq.IsEmpty());
		}
		TEST_METHOD(PushFrontOneTimeAngle_ValidData_Success)
		{
			rut::Deque<Angle::Angle> deq;
			Angle::Angle value(42,42,42);
			deq.push_front(value);
			Assert::IsTrue(deq.front()== value);
		}
		TEST_METHOD(PushFrontFewTimesAngle_ValidData_Success)
		{
			rut::Deque<Angle::Angle> deq;
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			deq.push_front(value1);
			deq.push_front(value2);
			Assert::IsTrue(deq.front() == value2);
		}
		TEST_METHOD(PushBackOneTimeAngle_ValidData_Success)
		{
			rut::Deque<Angle::Angle> deq;
			Angle::Angle value(42, 42, 42);
			deq.push_back(value);
			Assert::IsTrue(deq.back() == value);
		}
		TEST_METHOD(PushBackFewTimesAngle_ValidData_Success)
		{
			rut::Deque<Angle::Angle> deq;
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			deq.push_back(value1);
			deq.push_back(value2);
			Assert::IsTrue(deq.back() == value2);
		}
		TEST_METHOD(PushBackAndPushFrontAngle_ValidData_Success)
		{
			rut::Deque<Angle::Angle> deq;
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			deq.push_front(value1);
			deq.push_back(value2);
			Assert::IsTrue(deq.front()== value1&& deq.back()== value2);
		}
		TEST_METHOD(PopFrontAngle_ValidData_Success)
		{
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			Angle::Angle value3(12, 34, 56);
			rut::Deque deq{ value1,value2,value3 };
			deq.pop_front();
			Assert::IsTrue(deq.front()== value2&& deq.back() == value3);
		}
		TEST_METHOD(PopBackAngle_ValidData_Success)
		{
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			Angle::Angle value3(12, 34, 56);
			rut::Deque deq{ value1,value2,value3 };
			deq.pop_back();
			Assert::IsTrue(deq.front()== value1&& deq.back() == value2);
		}
		TEST_METHOD(EqualDequesConstructionAngle_ValidData_Success)
		{
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			rut::Deque deq1{ value1,value2}, deq2(deq1);
			Assert::IsTrue(deq1.front() == deq2.front()&& deq1.back()== deq2.back());
		}
		TEST_METHOD(EqualDequesByOperatorAngle_ValidData_Success)
		{
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			rut::Deque deq1{ value1,value2}, deq2 = deq1;
			Assert::IsTrue(deq1.front() == deq2.front() && deq1.back() == deq2.back());
		}
		TEST_METHOD(MoveConstructorAngle_ValidData_Success)
		{
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			rut::Deque deq1{ value1,value2}, deq2(std::move(deq1));
			Assert::IsTrue(deq2.front() == value1 && deq2.back() == value2);

		}
		TEST_METHOD(OperatorMoveAngle_ValidData_Success)
		{
			Angle::Angle value1(42, 42, 42);
			Angle::Angle value2(11, 22, 33);
			rut::Deque deq1{ value1,value2}, deq2 = std::move(deq1);
			Assert::IsTrue(deq2.front() == value1 && deq2.back() == value2);
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
			Assert::IsTrue(deq.front() == expected1&& deq.back()== expected2);
		}
		TEST_METHOD(PopFrontString_ValidData_Success)
		{
			rut::Deque <std::string> deq{ "test1","test2","test3" };
			deq.pop_front();
			std::string expected2 = "test2";
			std::string expected3 = "test3";
			Assert::IsTrue(deq.front() == expected2&& deq.back() == expected3);
		}
		TEST_METHOD(PopBackString_ValidData_Success)
		{
			rut::Deque<std::string> deq{ "test1","test2","test3"};
			deq.pop_back();
			std::string expected1 = "test1";
			std::string expected2 = "test2";
			Assert::IsTrue(deq.front() == expected1 && deq.back() == expected2);
		}
		TEST_METHOD(EqualDequesConstructionString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1","test2"}, deq2(deq1);
			Assert::IsTrue(deq1.front() == deq2.front()&& deq1.back()== deq2.back());
		}
		TEST_METHOD(EqualDequesByOperatorString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1","test2"}, deq2 = deq1;
			Assert::IsTrue(deq1.front() == deq2.front() && deq1.back() == deq2.back());
		}
		TEST_METHOD(MoveConstructorString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1", "test2"}, deq2(std::move(deq1));
			std::string expected1 = "test1";
			std::string expected2 = "test2";
			Assert::IsTrue(deq2.front() == expected1 && deq2.back() == expected2);
		}
		TEST_METHOD(OperatorMoveString_ValidData_Success)
		{
			rut::Deque<std::string> deq1{ "test1","test2"}, deq2 = std::move(deq1);
			std::string expected1 = "test1";
			std::string expected2 = "test2";
			Assert::IsTrue(deq2.front() == expected1 && deq2.back() == expected2);
		}
	};
}
