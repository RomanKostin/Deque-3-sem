#pragma once
#include <limits>
#include <iostream>
namespace Angle
{
	class Angle
	{
	private:
		/*
		*@brief �������� ��� �������� ������ � ����� � �������
		*/
		static const int factor = 60;

		/*
		*@brief ������������ �������� �������
		*/
		static const int gradus_max = 360;

		/*
		*@brief �������� � ��������
		*/
		int degrees{ 0 };

		/*
		*@brief �������� � �������
		*/
		int minutes{ 0 };

		/*
		*@brief �������� � ��������
		*/
		double seconds{ 0 };

		/*
		*@brief ������� swap ��� ������ Angle
		*/
		void swap(Angle& angle);

	public:
		/*
		*@brief ����������� ��� ������, ����� ������� ��� �������� �� ����
		*/
		Angle(int degr, int min, double sec);

		/*
		*@brief ����������� ��� ������, ����� ������� ������ �������� � ��������, ������� ����������� � ������, � ����� � �������
		*/
		Angle(double sec);

		/*
		*@brief ����������� �����������
		*/
		Angle(Angle& A) = default;

		/*
		*@brief �������� "=" ��� ������ Angle
		*/
		Angle& operator = (const Angle& angle) = default;

		/*
		*@brief ���������� ������ Angle
		*/
		~Angle() = default;

		/*
		*@brief �������� "==" ��� ������ Angle
		*/
		bool operator == (const Angle& angle) const;

		/*
		*@brief �������� "!=" ��� ������ Angle
		*/
		bool operator != (const Angle& angle) const;

		/*
		*@brief �������� "<<" ��� ������ Angle
		*/
		friend std::ostream& operator<<(std::ostream& output, const Angle& angle);

		/*
		*@brief �������� ">>" ��� ������ Angle
		*/
		friend std::istream& operator>>(std::istream& input, Angle& angle);

		/*
	*@brief ������� ��� �������� ��������� ���� � ������������ ��������, ����������� ��� ��������� �������, ��������� � �.�.
	*/
		double convert() const;

	};
}