#include "entry.h"
#include <string.h>

void init_context(Context* ctx) {
    memset(ctx, 0, sizeof(Context));
}

int load_data(Context* ctx, const char* filename, const char* region) {
    free_context(ctx);
    ctx->all_data = create_list();
    if (parse_csv(filename, ctx->all_data, &ctx->total_rows, &ctx->error_rows)) {
        strcpy(ctx->error, "Error opening file");
        return -1;
    }

    ctx->valid_rows = 0;
    for (Node* n = ctx->all_data->head; n; n = n->next) ctx->valid_rows++;

    ctx->filtered_data = region && region[0] ? filter_by_region(ctx->all_data, region) : ctx->all_data;
    return 0;
}

void calculate_metrics(Context* ctx, int column, double* min, double* max, double* median) {
    *min = calculate_min(ctx->filtered_data, column);
    *max = calculate_max(ctx->filtered_data, column);
    *median = calculate_median(ctx->filtered_data, column);
}

void free_context(Context* ctx) {
    if (ctx->all_data) free_list(ctx->all_data);
    if (ctx->filtered_data && ctx->filtered_data != ctx->all_data) free_list(ctx->filtered_data);
    init_context(ctx);
}
