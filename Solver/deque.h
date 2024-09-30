#pragma once
#include<iostream>
#include <initializer_list>

namespace rut
{
	template <typename T>
	class Deque
	{
	private:
		struct Node
		{
			T data;
			Node* next;
			Node* prev;
			Node(T value) :data(value), next(nullptr), prev(nullptr) {}
		};
		/*
		*@brief ���� ������ ����
		*/
		Node* head;

		/*
		*@brief ���� ������ ����
		*/
		Node* tail;

		/*
		*@brief ������ ����
		*/
		size_t size;

	public:
		/*
		*@brief ����������� �� ���������
		*/
		Deque() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

		/*
		*@brief ����������� ��� ������
		*@param list - ������
		*/
		Deque(std::initializer_list<T> list)
		{
			for (auto& x : list)
			{
				push_back(x);
			}
		}

		/*
		*@brief ����������� �����������
		*@param other - ������ ���
		*/
		Deque(const Deque& other)
		{
			Node* temp = other.head;
			while (temp != nullptr)
			{
				push_back(temp->data);
				temp = temp->next;
			}
		}

		/*
		*@brief ����������� �����������
		*@param other - ������ ���
		*/
		Deque(Deque&& other) noexcept : head{ other.head }, tail{ other.tail }, size{ other.size }
		{
			other.head = other.tail = nullptr;
			other.size = 0;
		}

		/*
		*@brief ���������� ����
		*/
		~Deque()
		{
			while (!(IsEmpty()))
			{
				pop_front();
			}
		}

		/*
		*@brief �������� ������������ ��� ����
		*@param other - ������ ���
		*@return ���������� ���, ������ other
		*/
		Deque& operator=(const Deque& other)
		{
			if (this != &other)
			{
				Deque temp(other);
				std::swap(this->head, temp.head);
				std::swap(this->tail, temp.tail);
				std::swap(this->size, temp.size);
			}
			return *this;
		}

		/*
		*@brief �������� ������������ ������������ ��� ����
		*@param other - ������ ���
		*@return ���������� ���, ������ other
		*/
		Deque& operator = (Deque&& other) noexcept
		{
			if (this != &other)
			{
				if (this == &other)
				{
					return *this;
				}
			}
			this->head = other.head;
			this->tail = other.tail;
			this->size = other.size;
			other.head = other.tail = nullptr;
			other.size = 0;
			return *this;
		}


		/*
		*@brief �������� "<<" ��� ������ ���
		*/
		friend std::ostream& operator << (std::ostream & output, const Deque & deque)
		{
			Deque temp = deque;
			while (!(temp.IsEmpty()))
			{
				output << temp.front() << std::endl;
				temp.pop_front();
			}
			return output;
		}

		/*
		*@brief ������� �������� ��������� ���� ����
		*/
		void pop_front()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("����� �� ������� ����");
			}
			if (this->head == this->tail)
			{
				this->head = this->tail = nullptr;
			}
			else
			{
				this->head = this->head->next;
				this->head->prev = nullptr;
			}
			--this->size;
		}

		/*
		*@brief ������� �������� ���������� ���� ����
		*/
		void pop_back()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("����� �� ������� ����");
			}
			if (this->head == this->tail)
			{
				this->head = this->tail = nullptr;
			}
			else
			{
				this->tail = this->tail->prev;
				this->tail->next = nullptr;
			}
			--this->size;
		}
		
		/*
		*@brief ������� ���������� ���� ������� ����
		*@param value - ��������, ������� ����� ��������� ����� ����
		*/
		void push_front(const T value)
		{
			Node* frontNode = new Node(value);
			if (IsEmpty())
			{
				this->head = this->tail = frontNode;
			}
			else
			{
				this->head->prev = frontNode;
				frontNode->next = this->head;
				this->head = frontNode;
			}
			++this->size;
		}

		/*
		*@brief ������� ���������� ���� � ����� ����
		*@param value - ��������, ������� ����� ��������� ����� ����
		*/
		void push_back(const T value)
		{
			Node* backNode = new Node(value);
			if (IsEmpty())
			{
				this->head = this->tail = backNode;
			}
			else
			{
				this->tail->next = backNode;
				backNode->prev = this->tail;
				this->tail = backNode;
			}
			++this->size;
		}

		/*
		*@brief ������� ��� ��������� �������� ��������� ���� ����
		*@return �������� ��������� ����
		*/
		int front()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("����� �� ������� ����");
			}
			return this->head->data;
		}

		/*
		*@brief ������� ��� ��������� �������� ���������� ���� ����
		*@return �������� ���������� ����
		*/
		int back()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("����� �� ������� ����");
			}
			return this->tail->data;
		}
		
		/*
		*@brief ������� �������� �� ������� ����
		*@return true ���� ��� ������, ����� false
		*/
		bool IsEmpty()
		{
			return this->size == 0;
		}
	};
}