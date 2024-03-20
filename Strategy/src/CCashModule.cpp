#include "CCashModule.h"

CCashNormal::CCashNormal(){
	std::cout << " [Constructor] Cash Normal" << std::endl;
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
	std::cout << " [Constructor] Cash Discount: " << discount_ << std::endl;
}

double CCashDiscount::ReturnCash(double price, double num)
{
	return price * num * discount_;
}

CashType CCashDiscount::TypeName() const {
	return typename_;
}

CCashRebate::CCashRebate(double condition, double rebate)
	: condition_(condition), rebate_(rebate) {
	std::cout << " [Constructor] Cash Rebate: " << 
		condition_ << "(condition), " << rebate_ << "(rebate)" << std::endl;
}

double CCashRebate::ReturnCash(double price, double num)
{
	double normal = price * num;
	if (condition_ > 0 && normal >= condition_) {
		return normal - rebate_;
	}
	return normal;
}

CashType CCashRebate::TypeName() const {
	return typename_;
}
