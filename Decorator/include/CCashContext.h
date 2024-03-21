#include <string>
#include "ISale.h"
#include "CCashModule.h"

class CCashContext
{
public:
	CCashContext(CashType type) {
		switch (type)
		{
			case CashType::Normal: {
				std::cout << " Cash Normal " << std::endl;
				cashmodule_ = new CCashNormal();
				break;
			}
			case CashType::Discount: {		
				std::cout << " Cash Discount " << std::endl;
				cashmodule_ = new CCashDiscount(0.5);
				break;
			}
			case CashType::Rebate: {	
				std::cout << " Cash Rebate " << std::endl;
				cashmodule_ = new CCashRebate(300, 100);
				break;
			}
			case CashType::DiscountAndRebate: {
				std::cout << " Discount -> Rebate " << std::endl;
				CCashNormal* cashnormal_ = new CCashNormal();
				CCashDiscount* cashdiscount_ = new CCashDiscount(0.5);
				CCashRebate* cashrebate_ = new CCashRebate(300, 50);

				cashrebate_->Decorate(cashnormal_);
				cashdiscount_->Decorate(cashrebate_);
				cashmodule_ = cashdiscount_;
				break;
			}
			case CashType::RebateAndDiscount: {
				std::cout << " Rebate -> Discount " << std::endl;
				CCashNormal* cashnormal_ = new CCashNormal();
				CCashRebate* cashrebate_ = new CCashRebate(300, 50);
				CCashDiscount* cashdiscount_ = new CCashDiscount(0.5);

				cashdiscount_->Decorate(cashnormal_);
				cashrebate_->Decorate(cashdiscount_);
				cashmodule_ = cashrebate_;
				break;
			}
			default:
				cashmodule_ = nullptr;
				break;			
		}				
	};

	double GetReturnCash(const double price, const double num) {	
		return cashmodule_->ReturnCash(price, num);
	}

private:
	ISale* cashmodule_;
};