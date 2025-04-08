#include "CalculatorFacade.h"
#include <sstream>

CalculatorFacade::CalculatorFacade() : core(std::make_unique<CalculatorCore>()) {}

std::string CalculatorFacade::calculate(const std::string& expression) {
    std::string result;
    try {
        double calculationResult = core->calculate(expression);
        std::ostringstream oss;
        oss << calculationResult;
        result = oss.str();
    } catch (const std::exception& e) {
        result = "Error: " + std::string(e.what());
    }
    return result;
}
