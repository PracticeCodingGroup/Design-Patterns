//
// Created by NUZEROVI on 2024/03/19.
//
#include "EnumClassCast.h"
#include <iostream>
#include <string>
using namespace std;

#include "CCashFactory.h"
#include "CashType.h"

int main(){
    cout << "==================== Simple Factory ====================" << endl;
    CCashFactory* simple_factory_ = new CCashFactory();

    for (size_t i = 0; i < Enum_v(CashType::count); i++) {
        ICashModule* cash_type_ = simple_factory_->CreateCashType(static_cast<CashType>(i));
        cout << " => Total: " << cash_type_->ReturnCash(100, 5) << endl;
        delete cash_type_;
    }   

    return 0;
}
