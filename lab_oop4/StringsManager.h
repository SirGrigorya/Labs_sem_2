#ifndef STRINGMANAGER_H
#define STRINGMANAGER_H


#include <string>
#include <vector>

class StringManager
{
    public:
        static std::vector<std::string> separateString(std::string str, char c);
};

#endif // STRINGMANAGER_H
