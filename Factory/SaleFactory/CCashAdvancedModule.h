#include <iostream>
#include <string>
#include "IFactory.h"
#include "CashTypeEnum.h"
#include "CCashModule.h"

class CCashDiscountAndRebate : public IFactory
{
public:
	CCashDiscountAndRebate(double discount, double condition, double rebate);
	~CCashDiscountAndRebate() {};
	ISale* CrateSalesModel();
	CashType TypeName() const final;

private:
	CashType typename_ = CashType::DiscountAndRebate;
	double discount_;
	double condition_;
	double rebate_;
};

class CCashRebateAndDiscount : public IFactory
{
public:
	CCashRebateAndDiscount(double discount, double condition, double rebate);
	~CCashRebateAndDiscount() {};
	ISale* CrateSalesModel();
	CashType TypeName() const final;

private:
	CashType typename_ = CashType::RebateAndDiscount;
	double discount_;
	double condition_;
	double rebate_;
};