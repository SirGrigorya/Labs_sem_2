#ifndef BASE_FILE_READER_H
#define BASE_FILE_READER_H

#include "Scene.h"
#include "Normalization/NormalizationParameters.h"
#include <string>


class BaseFileReader
{
    public:
       virtual Scene* readScene(std::string filename, NormalizationParameters params) = 0;
       virtual ~BaseFileReader() {}
};

#endif // BASE_FILE_READER_H
