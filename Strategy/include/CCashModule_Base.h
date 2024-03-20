//
// Created by NUZEROVI on 2024/03/19.
//

#ifndef DESIGN_PATTERNS_CCASHMODULE_H
#define DESIGN_PATTERNS_CCASHMODULE_H

#include <string>
#include "CashTypeEnum.h"

class CCashModule
{
public:
    virtual ~CCashModule() = default;
    virtual double ReturnCash(double price, double num) = 0;
    virtual CashType TypeName() const = 0;
};


#endif //DESIGN_PATTERNS_CCASHMODULE_H
