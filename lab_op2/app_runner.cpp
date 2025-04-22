#include "entry.h"
#include "app_runner.h"
#include <cstdio>

bool run_app(AppContext* context, const char* filepath, const char* region, int column) {
    bool result = false;

    if (load_csv_file(context, filepath)) {
        if (calculate_metrics(context, region, column)) {
            result = true;
        }
    }

    return result;
}
