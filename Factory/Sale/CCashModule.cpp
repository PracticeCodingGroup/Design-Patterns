#include "CCashModule.h"

CCashNormal::CCashNormal(){
}

CashType CCashNormal::TypeName() const {
	return typename_;
}

double CCashNormal::ReturnCash(double price, double num)
{
	return price * num;
}

CCashDiscount::CCashDiscount(double discount) 
	: discount_(discount) {
}

double CCashDiscount::ReturnCash(double price, double num)
{
	double total = price * num * discount_;	
	return super::ReturnCash(total, 1);
}

CashType CCashDiscount::TypeName() const {
	return typename_;
}

CCashRebate::CCashRebate(double condition, double rebate)
	: condition_(condition), rebate_(rebate) {	
}

double CCashRebate::ReturnCash(double price, double num)
{
	double normal = price * num;
	if (condition_ > 0 && normal >= condition_) {
		double total =  normal - rebate_;	
		return super::ReturnCash(total, 1);
	}
	return normal;
}

CashType CCashRebate::TypeName() const {
	return typename_;
}
