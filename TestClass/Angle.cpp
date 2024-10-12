#include <iostream>
#include "Angle.h"
#include "cmath"
Angle::Angle::Angle(int degr, int min, double sec)
{
	if (min<0 || sec < 0 || min > factor || sec > factor || std::abs(degr) > gradus_max)
	{
		throw std::invalid_argument("wrong angle!");
	}
	this->degrees = degr;
	this->minutes = min;
	this->seconds = sec;
}

Angle::Angle::Angle(double sec)
{
	int negative = 1;
	if (sec < 0)
	{
		sec *= -1;
		negative = -1;
	}
	int temp_min = sec / factor;
	this->degrees = (negative * (temp_min / factor) % gradus_max);
	this->minutes = temp_min % factor;
	this->seconds = fmod(sec, factor);
}



bool Angle::Angle::operator==(const Angle& angle) const
{
	return(this->degrees == angle.degrees && this->minutes == angle.minutes && std::abs(this->seconds - angle.seconds) <= std::numeric_limits<double>::epsilon());
}

bool Angle::Angle::operator!=(const Angle& angle) const
{
	return !(*this == angle);
}

double Angle::Angle::convert() const
{
	double temp = (double)this->degrees + (double)this->minutes / factor + this->seconds / pow(factor, 2);
	return temp;
}

std::ostream& Angle::operator<<(std::ostream& output, const Angle& angle)
{
	output << angle.degrees << " degrees " << angle.minutes << " minutes " << angle.seconds << " seconds ";
	return output;
}

std::istream& Angle::operator>>(std::istream& input, Angle& angle)
{
	int degrees = 0,
		minutes = 0;
	double seconds = 0;
	input >> degrees >> minutes >> seconds;
	Angle temp(degrees, minutes, seconds);
	temp.swap(angle);
	return input;
}

void Angle::Angle::swap(Angle& angle)
{
	std::swap(this->degrees, angle.degrees);
	std::swap(this->minutes, angle.minutes);
	std::swap(this->seconds, angle.seconds);
}