#include <iostream>
#include <string>
#include "CCashModule_Base.h"
#include "CashTypeEnum.h"

class CCashNormal : public CCashModule
{
public:
	CCashNormal();
	~CCashNormal() {};
	double ReturnCash(double price, double num) override;
	CashType TypeName() const final;

private:
	CashType typename_ = CashType::Normal;
};

class CCashDiscount : public CCashModule
{
public:
	CCashDiscount() = delete;
	CCashDiscount(double discount);
	~CCashDiscount() {};
	double ReturnCash(double price, double num) override;
	CashType TypeName() const final;

private:
	CashType typename_ = CashType::Discount;
	double discount_;
};

class CCashRebate : public CCashModule
{
public:
	CCashRebate() = delete;
	CCashRebate(double condition, double rebate);
	~CCashRebate() {};
	double ReturnCash(double price, double num) override;
	CashType TypeName() const final;

private:
	CashType typename_ = CashType::Rebate;
	double condition_;
	double rebate_;
};