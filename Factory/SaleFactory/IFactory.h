//
// Created by NUZEROVI on 2024/03/22.
//

#ifndef DESIGN_PATTERNS_IFACTORY_H
#define DESIGN_PATTERNS_IFACTORY_H

#include <string>
#include "CashTypeEnum.h"
#include "ISale.h"

class IFactory
{
public:
    virtual ~IFactory() = default;
    virtual ISale* CrateSalesModel() = 0;
    virtual CashType TypeName() const = 0;
};


#endif //DESIGN_PATTERNS_IFACTORY_H
