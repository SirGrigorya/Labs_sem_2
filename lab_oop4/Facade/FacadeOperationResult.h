#ifndef FACADEOPERATIONRESULT_H
#define FACADEOPERATIONRESULT_H

#include <string>

class FacadeOperationResult
{
    private:
        std::string _errorMsg;
        bool _isError;
    public:
        FacadeOperationResult();
        FacadeOperationResult(std::string errorMsg);
        std::string getErrorMessage();
        void set(std::string errorMsg);
        void clear();
        bool isSuccess();
};

#endif // FACADEOPERATIONRESULT_H
