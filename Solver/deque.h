#pragma once
#include<iostream>
#include <initializer_list>

namespace rut
{
	template <typename T>
	class Deque
	{
	private:
		/*
		*@brief структура узла
		*/
		struct Node
		{
			T data;
			Node* next;
			Node* prev;
			Node(T value) :data(value), next(nullptr), prev(nullptr) {}
		};
		/*
		*@brief узел головы дэка
		*/
		Node* head;

		/*
		*@brief узел хвоста дэка
		*/
		Node* tail;

		/*
		*@brief размер дэка
		*/
		size_t size;

	public:
		/*
		*@brief конструктор по умолчанию
		*/
		Deque() : head{ nullptr }, tail{ nullptr }, size{ 0 } {}

		/*
		*@brief конструктор для списка
		*@param list - список
		*/
		Deque(std::initializer_list<T> list)
		{
			for (auto& x : list)
			{
				push_back(x);
			}
		}

		/*
		*@brief конструктор копирования
		*@param other - другой дэк
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
		*@brief конструктор перемещения
		*@param other - другой дэк
		*/
		Deque(Deque&& other) noexcept : head{ other.head }, tail{ other.tail }, size{ other.size }
		{
			other.head = other.tail = nullptr;
			other.size = 0;
		}

		/*
		*@brief деструктор дэка
		*/
		~Deque()
		{
			while (!(IsEmpty()))
			{
				pop_front();
			}
		}

		/*
		*@brief оператор присваивания для дэка
		*@param other - другой дэк
		*@return возвращает дэк, равный other
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
		*@brief оператор присваивания перемещением для дэка
		*@param other - другой дэк
		*@return возвращает дэк, равный other
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
		*@brief оператор "<<" для класса дэк
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
		*@brief функция удаления переднего узла дэка
		*/
		void pop_front()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("выход за пределы дэка");
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
		*@brief функция удаления последнего узла дэка
		*/
		void pop_back()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("выход за пределы дэка");
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
		*@brief функция добавления узла спереди дэка
		*@param value - значение, которое будет принимать новый узел
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
		*@brief функция добавления узла в конце дэка
		*@param value - значение, которое будет принимать новый узел
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
		*@brief функция для получения значения переднего узла дэка
		*@return значение переднего узла
		*/
		T front()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("выход за границы дэка");
			}
			return this->head->data;
		}

		/*
		*@brief функция для получения значения последнего узла дэка
		*@return значение последнего узла
		*/
		T back()
		{
			if (IsEmpty())
			{
				throw std::out_of_range("выход за границы дэка");
			}
			return this->tail->data;
		}
		
		/*
		*@brief функция проверки на пустоту дэка
		*@return true если дэк пустой, иначе false
		*/
		bool IsEmpty()
		{
			return this->size == 0;
		}
	};
}