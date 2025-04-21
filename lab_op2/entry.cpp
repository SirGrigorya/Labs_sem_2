#include "entry.h"
#include "csv_parser.h"
#include "filters.h"
#include "statistics.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 512
#define MIN_COLUMN_INDEX 1
#define MAX_COLUMN_INDEX 5

void init_context(AppContext* ctx) {
    if (ctx) {
        init_data_array(&ctx->data);
        ctx->total_lines = 0;
        ctx->error_lines = 0;
        ctx->valid_lines = 0;
        ctx->min = 0;
        ctx->max = 0;
        ctx->median = 0;
        ctx->last_error[0] = '\0';
    }
}

void free_context(AppContext* ctx) {
    if (ctx) {
        free_data_array(&ctx->data);
    }
}

bool load_csv_file(AppContext* ctx, const char* filepath) {
    bool success = false;

    if (ctx && filepath) {
        FILE* file = fopen(filepath, "r");
        if (file) {
            char* line = (char*)malloc(MAX_LINE_LENGTH);
            if (line) {
                int line_num = 0;

                if (fgets(line, MAX_LINE_LENGTH, file)) { // Пропускаем заголовок
                    while (fgets(line, MAX_LINE_LENGTH, file)) {
                        ctx->total_lines++;
                        line[strcspn(line, "\r\n")] = '\0'; // Удаляем \n и \r

                        DataEntry entry;
                        if (parse_csv_line(line, &entry) && is_valid_entry(&entry)) {
                            if (!add_data_entry(&ctx->data, entry)) {
                                snprintf(ctx->last_error, sizeof(ctx->last_error), "Memory allocation failed.");
                                break;
                            }
                            ctx->valid_lines++;
                        } else {
                            ctx->error_lines++;
                        }
                    }
                    success = true;
                } else {
                    snprintf(ctx->last_error, sizeof(ctx->last_error), "Empty file.");
                }

                free(line);
            } else {
                snprintf(ctx->last_error, sizeof(ctx->last_error), "Memory allocation failed.");
            }

            fclose(file);
        } else {
            snprintf(ctx->last_error, sizeof(ctx->last_error), "Can't open file.");
        }
    }

    return success;
}

bool calculate_metrics(AppContext* ctx, const char* region, int column_index) {
    bool success = false;

    if (ctx) {
        if (column_index >= MIN_COLUMN_INDEX && column_index <= MAX_COLUMN_INDEX) {
            success = calculate_statistics(&ctx->data, region, column_index, &ctx->min, &ctx->max, &ctx->median);
            if (!success) {
                snprintf(ctx->last_error, sizeof(ctx->last_error), "Not enough valid data for statistics.");
            }
        } else {
            snprintf(ctx->last_error, sizeof(ctx->last_error), "Invalid column index.");
        }
    }

    return success;
}
