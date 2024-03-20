#include <iostream>
#include <string>
#include "ICashModule.h"
#include "CashType.h"

class CCashNormal : public ICashModule
{
public:
	CCashNormal();
	~CCashNormal() {};
	double ReturnCash(double price, double num) override;
	CashType TypeName() const final;

private:
	CashType typename_ = CashType::Normal;
};

class CCashDiscount : public ICashModule
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

class CCashRebate : public ICashModule
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