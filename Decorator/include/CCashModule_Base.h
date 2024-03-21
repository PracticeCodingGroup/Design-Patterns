//
// Created by NUZEROVI on 2024/03/21.
//

#ifndef DESIGN_PATTERNS_CCASHMODULE_H
#define DESIGN_PATTERNS_CCASHMODULE_H

#include <string>
#include "CashTypeEnum.h"
#include "ISale.h"

class CCashModule : public ISale
{
public:
    ~CCashModule() {};    
    void Decorate(ISale* component) {
        component_ = component;
    };
    double ReturnCash(double price, double num) override{   
        if (component_ != nullptr) {
            return component_->ReturnCash(price, num);
        }
        else {
            return price * num;
        }         
    };
    CashType TypeName() { return typename_; }

protected:
    ISale* component_ = nullptr;
    CashType typename_;
};

#endif //DESIGN_PATTERNS_CCASHMODULE_H
