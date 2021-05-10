#include "EAN.h"
Bottle::Bottle(std::string ean, std::string a, std::string p) throw(std::invalid_argument, std::length_error)
{
	if (ean.length() !=13)
		throw std::length_error("EAN has incorrect length");
	ean_code = ean;
	article = a;
	price=std::stod(p); /*if p is incorrect float-point value stod will throw std::invalid_argument exception*/
	count = 0;
}
void Bottle::AnotherBottle()
{
	count++;
}
std::string const Bottle::get_code()
{
	return this->ean_code;
}
int const Bottle::get_count()
{
	return this->count;
}
std::string const Bottle::get_article()
{
	return this->article;
}
double const Bottle::get_price()
{
	return this->price;
}
bool operator==(Bottle arg1,Bottle arg2)
{
	if (arg1.get_code() == arg2.get_code())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(Bottle l, std::string r) 
{
	if (l.get_code() == r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& operator<< (std::ostream& ostr, Bottle& f)
{
	ostr << f.get_count()<<"X "<<f.get_article()<<"("<<f.get_price()<<")\n";
	return ostr;
}