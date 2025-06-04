#include "FacadeOperationResult.h"

using namespace std;

FacadeOperationResult::FacadeOperationResult() : _errorMsg(""), _isError(false)
{

}

FacadeOperationResult::FacadeOperationResult(string errorMsg) : _errorMsg(errorMsg), _isError(true)
{

}

bool FacadeOperationResult::isSuccess()
{
    return !_isError;
}

std::string FacadeOperationResult::getErrorMessage()
{
    return _errorMsg;
}

void FacadeOperationResult::set(string errorMsg)
{
    _errorMsg = errorMsg;
    _isError = true;
}

void FacadeOperationResult::clear()
{
    _errorMsg = "";
    _isError = false;
}

