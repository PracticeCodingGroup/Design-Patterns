#include <string>
#include "ISale.h"
#include "IFactory.h"
#include "CCashAdvancedModule.h"

class CCashContext
{
public:
	CCashContext(CashType type) {
		IFactory* factory_ = nullptr;
		switch (type)
		{
		case CashType::Normal: {
			std::cout << " Cash Normal ";
			factory_ = new CCashDiscountAndRebate(1.0, 0.0, 0.0);
			break;
		}
		case CashType::Discount: {
			std::cout << " Cash Discount ";
			factory_ = new CCashDiscountAndRebate(0.8, 0.0, 0.0);
			break;
		}
		case CashType::Rebate: {
			std::cout << " Cash Rebate ";
			factory_ = new CCashDiscountAndRebate(1.0, 300, 50);
			break;
		}
		case CashType::DiscountAndRebate: {
			std::cout << " Discount -> Rebate ";
			factory_ = new CCashDiscountAndRebate(0.5, 300, 50);
			break;
		}
		case CashType::RebateAndDiscount: {
			std::cout << " Rebate -> Discount ";
			factory_ = new CCashRebateAndDiscount(0.5, 300, 50);
			break;
		}
		default:
			factory_ = nullptr;
			break;
		}
		cashmodule_ = factory_->CrateSalesModel();
	};

	double GetReturnCash(const double price, const double num) {	
		return cashmodule_->ReturnCash(price, num);
	}

private:
	ISale* cashmodule_;
};