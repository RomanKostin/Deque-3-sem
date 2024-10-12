#include <iostream>
#include "..\Solver\deque.h"

int main()
{
	rut::Deque<double> deq, list{ 1.1,2,3 };
	deq.push_front(7);
	deq.push_front(4);
	deq.push_front(44.32);
	rut::Deque<double> copy = list;
	rut::Deque<double> test(deq);
	std::cout << list;
	std::cout << test;
	rut::Deque<double> stest(std::move(deq));
	deq = list;
	std::cout << std::endl << deq;
	return 0;
}