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
		Deque();

		/*
		*@brief конструктор для списка
		*@param list - список
		*/
		Deque(std::initializer_list<T> list);

		/*
		*@brief конструктор копирования
		*@param other - другой дэк
		*/
		Deque(const Deque& other);

		/*
		*@brief конструктор перемещения
		*@param other - другой дэк
		*/
		Deque(Deque&& other) noexcept;

		/*
		*@brief деструктор дэка
		*/
		~Deque();

		/*
		*@brief оператор присваивания для дэка
		*@param other - другой дэк
		*@return возвращает дэк, равный other
		*/
		Deque& operator=(const Deque& other);

		/*
		*@brief оператор присваивания перемещением для дэка
		*@param other - другой дэк
		*@return возвращает дэк, равный other
		*/
		Deque& operator = (Deque&& other) noexcept;

		/*
		*@brief функция удаления переднего узла дэка
		*/
		void pop_front();

		/*
		*@brief функция удаления последнего узла дэка
		*/
		void pop_back();
		
		/*
		*@brief функция добавления узла спереди дэка
		*@param value - значение, которое будет принимать новый узел
		*/
		void push_front(const T value);

		/*
		*@brief функция добавления узла в конце дэка
		*@param value - значение, которое будет принимать новый узел
		*/
		void push_back(const T value);

		/*
		*@brief функция для получения значения переднего узла дэка
		*@return значение переднего узла
		*/
		T front();

		/*
		*@brief функция для получения значения последнего узла дэка
		*@return значение последнего узла
		*/
		T back();
		
		/*
		*@brief функция проверки на пустоту дэка
		*@return true если дэк пустой, иначе false
		*/
		bool IsEmpty();
	};

	template <typename T>
	Deque<T>::Deque() : head { nullptr }, tail{ nullptr }, size{ 0 } {}

	template <typename T>
	Deque<T>::Deque(std::initializer_list<T> list)
	{
		for (auto& x : list)
		{
			push_back(x);
		}
	}

	template <typename T>
	Deque<T>::Deque(const Deque& other)
	{
		Node* temp = other.head;
		while (temp != nullptr)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}

	template <typename T>
	Deque<T>::Deque(Deque&& other) noexcept : head{ other.head }, tail{ other.tail }, size{ other.size }
	{
		other.head = other.tail = nullptr;
		other.size = 0;
	}

	template <typename T>
	Deque<T>::~Deque()
	{
		while (!(IsEmpty()))
		{
			pop_front();
		}
	}

	template <typename T>
	Deque<T>& Deque<T>::operator=(const Deque& other)
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

	template <typename T>
	Deque<T>& Deque<T>::operator = (Deque&& other) noexcept
	{

		if (this == &other)
		{
			return *this;
		}
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = other.tail = nullptr;
		other.size = 0;
		return *this;
	}

	template <typename T>
	void Deque<T>::pop_front()
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

	template <typename T>
	void Deque<T>::pop_back()
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
	
	template <typename T>
	void Deque<T>::push_front(const T value)
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
	
	template <typename T>
	void Deque<T>::push_back(const T value)
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

	template <typename T>
	T Deque<T>::front()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("выход за границы дэка");
		}
		return this->head->data;
	}

	template <typename T>
	T Deque<T>::back()
	{
		if (IsEmpty())
		{
			throw std::out_of_range("выход за границы дэка");
		}
		return this->tail->data;
	}

	template <typename T>
	bool Deque<T>::IsEmpty()
	{
		return this->size == 0;
	}

	template <typename T>
	std::ostream& operator << (std::ostream& output, const Deque<T>& deque)
	{
		Deque temp = deque;
		while (!(temp.IsEmpty()))
		{
			output << temp.front() << std::endl;
			temp.pop_front();
		}
		return output;
	}
}