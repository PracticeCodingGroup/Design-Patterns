//
// Created by NUZEROVI on 2024/03/21.
//
#include "EnumClassCast.h"
#include <iostream>
#include <string>
using namespace std;

#include "CCashContext.h"
#include "CashTypeEnum.h"

int main(){
    cout << "==================== Decorator ====================" << endl;
    double discount_ = 0.5;
    double condition_ = 300;
    double rebate_ = 50;
    cout << " DISCOUNT: " << discount_ << endl;
    cout << " CONDITION: " << condition_ << ", REBATE: " << rebate_ << endl;
    cout << "================================================" << endl;

    for (size_t i = 0; i < Enum_v(CashType::count); i++) {
        CCashContext* cash_context_ = new CCashContext(static_cast<CashType>(i));
        cout << " => Total: " << cash_context_->GetReturnCash(100, 5) << endl;
        cout << "================================================" << endl;
        delete cash_context_;
    }    

    return 0;
}
