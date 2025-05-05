#include "entry.h"
#include "csv_parser.h"
#include "filters.h"
#include "statistics.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 512
#define ERROR_MESSAGE_SIZE 256
#define MIN_COLUMN_INDEX 1
#define MAX_COLUMN_INDEX 5

void init_context(AppContext* ctx) {
    if (ctx) {
        ctx->data = (DataArray*)malloc(sizeof(DataArray));
        if (ctx->data) {
            init_data_array(ctx->data);
        }

        ctx->last_error = (char*)malloc(ERROR_MESSAGE_SIZE);
        if (ctx->last_error) {
            ctx->last_error[0] = '\0';
        }

        ctx->total_lines = 0;
        ctx->error_lines = 0;
        ctx->valid_lines = 0;
    }
}

void free_context(AppContext* ctx) {
    if (ctx) {
        if (ctx->data) {
            free_data_array(ctx->data);
            free(ctx->data);
            ctx->data = NULL;
        }

        if (ctx->last_error) {
            free(ctx->last_error);
            ctx->last_error = NULL;
        }
    }
}

bool load_csv_file(AppContext* ctx, const char* filepath) {
    bool success = false;

    if (ctx && ctx->data && ctx->last_error && filepath) {
        FILE* file = fopen(filepath, "r");
        if (file) {
            char* line = (char*)malloc(MAX_LINE_LENGTH);
            if (line) {
                if (fgets(line, MAX_LINE_LENGTH, file)) {
                    while (fgets(line, MAX_LINE_LENGTH, file)) {
                        ctx->total_lines++;
                        line[strcspn(line, "\r\n")] = '\0';

                        DataEntry entry;
                        if (parse_csv_line(line, &entry) && is_valid_entry(&entry)) {
                            if (!add_data_entry(ctx->data, entry)) {
                                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Memory allocation failed.");
                                break;
                            }
                            ctx->valid_lines++;
                        } else {
                            ctx->error_lines++;
                        }
                    }
                    success = true;
                } else {
                    snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Empty file.");
                }
                free(line);
            } else {
                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Memory allocation failed.");
            }
            fclose(file);
        } else {
            snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Can't open file.");
        }
    }

    return success;
}

bool calculate_metrics(AppContext* ctx, const char* region, int column_index, StatisticsResult* result) {
    bool success = false;

    if (ctx && ctx->data && ctx->last_error && result) {
        if (column_index >= MIN_COLUMN_INDEX && column_index <= MAX_COLUMN_INDEX) {
            success = calculate_statistics(ctx->data, region, column_index, result);
            if (!success) {
                snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Not enough valid data for statistics.");
            }
        } else {
            snprintf(ctx->last_error, ERROR_MESSAGE_SIZE, "Invalid column index.");
        }
    }

    return success;
}
