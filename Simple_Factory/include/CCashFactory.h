#include <string>
#include "CCashModule.h"

class CCashFactory
{
public:
	CCashModule* CreateCashType(CashType type) {
		switch (type)
		{
		case CashType::Normal:
			return new CCashNormal();
			break;
		case CashType::Discount:
			return new CCashDiscount(0.8);
			break;
		case CashType::Rebate:
			return new CCashRebate(300, 100);
			break;
		default:
			return nullptr;
			break;
		}		
	};
};