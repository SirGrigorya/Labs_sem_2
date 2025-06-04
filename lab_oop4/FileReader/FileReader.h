#include "BaseFileReader.h"

#include <string>

class FileReader : public BaseFileReader
{
    private:
       std::vector<std::vector<std::string>> getData(std::string filename);
       std::vector<std::vector<double>> convertToDouble(std::vector<std::vector<std::string>> &data);
       std::vector<Vertex>* makeVerices(std::vector<std::vector<double>>& values);
       std::vector<Edge>* makeEdges(std::vector<Vertex> *verices);
    public:
       Scene* readScene(std::string filename, NormalizationParameters params) override;
};
