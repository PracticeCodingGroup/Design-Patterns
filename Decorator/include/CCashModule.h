#include <iostream>
#include <string>
#include "ISale.h"
#include "CCashModule_Base.h"
#include "CashTypeEnum.h"

class CCashNormal : public ISale
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
protected:
	typedef CCashModule super;
public:
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
protected:
	typedef CCashModule super;
public:
	CCashRebate(double condition, double rebate);
	~CCashRebate() {};
	double ReturnCash(double price, double num) override;
	CashType TypeName() const final;

private:
	CashType typename_ = CashType::Rebate;
	double condition_;
	double rebate_;
};