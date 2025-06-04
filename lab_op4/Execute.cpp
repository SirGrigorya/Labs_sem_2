#include "Execute.h"
#include "Files.h"
#include "Figure3DView.h"
#include "FigureConvertation.h"

static Figure3DView view;

result_t *executeOperation(operation_t *operation)
{
    result_t *result = new result_t;
    switch(operation->type)
    {
    case OP_LOAD_DATA_FROM_FILE:
    {
        vector<vector<string>> data;
        int error = loadDataFromFile(data, operation->fileName);
        if(!error)
            view = loadFigure3DView(data, operation->minRange, operation->maxRange);

        Figure3DView temp = view;
        result->error = error_type(error);
        break;
    }
    case OP_GET_FIGURE:
    {
        transformFigure3DView(view, operation->rotX, operation->rotY,
                              operation->rotZ, operation->scale);
        result->figure = convertFigure3DToFigure2D(view.modified);
        result->error = NO_ERROR;
        break;
    }
    }
    return result;
}
