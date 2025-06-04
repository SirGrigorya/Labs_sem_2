#ifndef EXCEPTION_FILE_READER_H
#define EXCEPTION_FILE_READER_H

#include <string>
#include <exception>


class ExceptionFileReader : public std::exception
{
    private:
        std::string _errorMsg;

    public:
        ExceptionFileReader(std::string errorMsg);
        const char * what() const noexcept override;
};

#endif // EXCEPTION_FILE_READER_H
