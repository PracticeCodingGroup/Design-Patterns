//
// Created by NUZEROVI on 2024/03/19.
//

#ifndef DESIGN_PATTERNS_ICASHMODULE_H
#define DESIGN_PATTERNS_ICASHMODULE_H

#include <string>
#include "CashType.h"

class ICashModule
{
public:
    virtual ~ICashModule() = default;
    virtual double ReturnCash(double price, double num) = 0;
    virtual CashType TypeName() const = 0;
};


#endif //DESIGN_PATTERNS_ICASHMODULE_H
