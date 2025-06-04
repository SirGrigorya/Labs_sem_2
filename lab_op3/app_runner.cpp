#include "app_runner.h"
#include <cstdio>
#include <string.h>

#define ERROR_MESSAGE_SIZE 256
#define MIN_COLUMN_INDEX 1
#define MAX_COLUMN_INDEX 5

bool run_app(AppContext* ctx, AppRunMode mode, const char* region, int column) {
    bool result = false;

    if (ctx && region) {
        if (mode == APP_RUN_LOAD) {
            free_context(ctx);
            init_context(ctx);
            result = load_csv_file(ctx, region);
        } else if (mode == APP_RUN_CALCULATE) {
            if (column >= MIN_COLUMN_INDEX && column <= MAX_COLUMN_INDEX) {
                result = calculate_metrics(ctx, region, column, &ctx->stats);
            } else {
                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Invalid column index.");
            }
        } else if (mode == APP_RUN_GET_SERIES) {
            result = extract_series(ctx, region, column, &ctx->series);
            if (!result) {
                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Failed to extract series.");
            }
        } else {
            snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Unknown mode.");
        }
    } else if (ctx && ctx->last_error) {
        snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Invalid arguments.");
    }

    return result;
}


int get_total_lines(const AppContext* ctx) {
    int value = 0;
    if (ctx) {
        value = ctx->total_lines;
    }
    return value;
}

int get_error_lines(const AppContext* ctx) {
    int value = 0;
    if (ctx) {
        value = ctx->error_lines;
    }
    return value;
}

int get_valid_lines(const AppContext* ctx) {
    int value = 0;
    if (ctx) {
        value = ctx->valid_lines;
    }
    return value;
}

const char* get_last_error(const AppContext* ctx) {
    const char* error = "";
    if (ctx && ctx->last_error) {
        error = ctx->last_error;
    }
    return error;
}

const DataArray* get_data_array(const AppContext* ctx) {
    const DataArray* data = NULL;
    if (ctx) {
        data = ctx->data;
    }
    return data;
}

double get_min_value(const AppContext* ctx) {
    double value = 0.0;
    if (ctx) {
        value = (double)ctx->stats.min;
    }
    return value;
}

double get_max_value(const AppContext* ctx) {
    double value = 0.0;
    if (ctx) {
        value = (double)ctx->stats.max;
    }
    return value;
}

double get_median_value(const AppContext* ctx) {
    double value = 0.0;
    if (ctx) {
        value = (double)ctx->stats.median;
    }
    return value;
}

