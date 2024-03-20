//
// Created by NUZEROVI on 2024/03/20.
//
#include "EnumClassCast.h"
#include <iostream>
#include <string>
using namespace std;

#include "CCashContext.h"
#include "CashTypeEnum.h"

int main(){
    cout << "==================== Strategy ====================" << endl;
    for (size_t i = 0; i < Enum_v(CashType::count); i++) {
        CCashContext* cash_context_ = new CCashContext(static_cast<CashType>(i));
        cout << " => Total: " << cash_context_->GetReturn(100, 5) << endl;
        delete cash_context_;
    }    

    return 0;
}
