#include "CCashAdvancedModule.h"

CCashDiscountAndRebate::CCashDiscountAndRebate(double discount, double condition, double rebate)
	: discount_(discount), condition_(condition), rebate_(rebate)
{
	std::cout << " [discount: " << discount_ << ", condition: " << condition_ << ", rebate: " << rebate_ << "]" << std::endl;
}

ISale* CCashDiscountAndRebate::CreateSalesModel()
{
	CCashNormal* cashnormal_ = new CCashNormal();
	CCashDiscount* cashdiscount_ = new CCashDiscount(discount_);
	CCashRebate* cashrebate_ = new CCashRebate(condition_, rebate_);

	cashrebate_->Decorate(cashnormal_);
	cashdiscount_->Decorate(cashrebate_);
	return cashdiscount_;
}

CashType CCashDiscountAndRebate::TypeName() const
{
	return typename_;
}

CCashRebateAndDiscount::CCashRebateAndDiscount(double discount, double condition, double rebate)
	: discount_(discount), condition_(condition), rebate_(rebate)
{
	std::cout << " [discount: " << discount_ << ", condition: " << condition_ << ", rebate: " << rebate_ << "]" << std::endl;
}

ISale* CCashRebateAndDiscount::CreateSalesModel()
{
	CCashNormal* cashnormal_ = new CCashNormal();
	CCashRebate* cashrebate_ = new CCashRebate(condition_, rebate_);
	CCashDiscount* cashdiscount_ = new CCashDiscount(discount_);

	cashdiscount_->Decorate(cashnormal_);
	cashrebate_->Decorate(cashdiscount_);
	return cashrebate_;
}

CashType CCashRebateAndDiscount::TypeName() const
{
	return typename_;
}
