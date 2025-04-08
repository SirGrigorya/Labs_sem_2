#include "entry.h"
#include <string.h>

#define INITIALIZED_VALUE 0
#define ERROR_OPENING_FILE -1
#define SUCCESS 0

void init_context(Context* ctx) {
    memset(ctx, INITIALIZED_VALUE, sizeof(Context));
}

int load_data(Context* ctx, const char* filename, const char* region) {
    int status = SUCCESS;  // По умолчанию успех

    free_context(ctx);
    ctx->all_data = create_list();

    if (parse_csv(filename, ctx->all_data, &ctx->total_rows, &ctx->error_rows)) {
        strcpy(ctx->error, "Error opening file");
        status = ERROR_OPENING_FILE;
    } else {
        ctx->valid_rows = INITIALIZED_VALUE;
        for (Node* n = ctx->all_data->head; n; n = n->next) {
            ctx->valid_rows++;
        }
        ctx->filtered_data = (region && region[0]) ? filter_by_region(ctx->all_data, region) : ctx->all_data;
    }

    return status;
}

void calculate_metrics(Context* ctx, int column, double* min, double* max, double* median) {
    if (ctx && ctx->filtered_data) {
        *min = calculate_min(ctx->filtered_data, column);
        *max = calculate_max(ctx->filtered_data, column);
        *median = calculate_median(ctx->filtered_data, column);
    }
}

void free_context(Context* ctx) {
    if (ctx) {
        if (ctx->all_data) {
            free_list(ctx->all_data);
        }
        if (ctx->filtered_data && ctx->filtered_data != ctx->all_data) {
            free_list(ctx->filtered_data);
        }
        init_context(ctx);
    }
}
