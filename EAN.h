#ifndef __EAN_H__
#define __EAN_H__
#include <iostream>
#include <string>
#include <stdexcept>
class Bottle /*every entity of this class preserve one type of bottles with specific EAN*/
{
private:
	std::string ean_code;
	std::string article;
	double price;
	int count; /*number of recycled bottles with this EAN*/
public:
	Bottle(std::string ean,std::string article,std::string price) throw(std::invalid_argument, std::length_error);
	void AnotherBottle();
	std::string const get_code();
	std::string const get_article();
	double const get_price();
	int const get_count();
};
bool operator==(Bottle, Bottle);
bool operator==(Bottle, std::string);
std::ostream& operator<<(std::ostream&, Bottle&);
#endif