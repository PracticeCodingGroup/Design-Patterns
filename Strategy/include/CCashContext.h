#include <string>
#include "CCashModule.h"

class CCashContext
{
public:
	CCashContext(CashType type) {
		switch (type)
		{
		case CashType::Normal:
			cashmodule_ = new CCashNormal();
			break;
		case CashType::Discount:
			cashmodule_ = new CCashDiscount(0.8);
			break;
		case CashType::Rebate:
			cashmodule_ = new CCashRebate(300, 100);
			break;
		default:
			cashmodule_ = nullptr;
			break;
		}				
	};

	double GetReturn(double price, double num) {
		return cashmodule_->ReturnCash(price, num);
	}

private:
	ICashModule* cashmodule_;
};