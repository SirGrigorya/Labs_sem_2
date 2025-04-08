// CalculatorFacade.h
#ifndef CALCULATORFACADE_H
#define CALCULATORFACADE_H

#include <string>
#include <memory>
#include "CalculatorCore.h"

class CalculatorFacade {
public:
    CalculatorFacade();
    std::string calculate(const std::string& expression);

private:
    std::unique_ptr<CalculatorCore> core;
};

#endif // CALCULATORFACADE_H
