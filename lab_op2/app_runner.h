#pragma once

#include "entry.h"
#include <stdbool.h>

typedef enum {
    APP_RUN_LOAD,
    APP_RUN_CALCULATE
} AppRunMode;

bool run_app(AppContext* ctx, AppRunMode mode, const char* filepath_or_region, int column);

int get_total_lines(const AppContext* ctx);
int get_error_lines(const AppContext* ctx);
int get_valid_lines(const AppContext* ctx);
const char* get_last_error(const AppContext* ctx);
const DataArray* get_data_array(const AppContext* ctx);
double get_min_value(const AppContext* ctx);
double get_max_value(const AppContext* ctx);
double get_median_value(const AppContext* ctx);
