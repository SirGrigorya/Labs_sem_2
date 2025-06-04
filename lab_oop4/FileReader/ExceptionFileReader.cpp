#include "ExceptionFileReader.h"

using namespace std;

ExceptionFileReader::ExceptionFileReader(string errorMsg) : _errorMsg(errorMsg)
{

}

const char* ExceptionFileReader::what() const noexcept
{
    return _errorMsg.c_str();
}
