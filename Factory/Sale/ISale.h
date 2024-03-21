//
// Created by NUZEROVI on 2024/03/21.
//

#ifndef DESIGN_PATTERNS_ISALE_H
#define DESIGN_PATTERNS_ISALE_H

#include <string>
#include "CashTypeEnum.h"

class ISale
{
public:
    virtual ~ISale() = default;
    virtual double ReturnCash(double price, double num) = 0;
    virtual CashType TypeName() const = 0;
};


#endif //DESIGN_PATTERNS_ISALE_H
