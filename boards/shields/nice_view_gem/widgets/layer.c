/*
 * layer.c
 * 2026-11-06 修改记录：
 *   1. 提示词改为 "LAY"，保持三字母对齐。
 *   2. Y 坐标下移到 50，保证整体三行间距分布均匀。
 */
#include <zephyr/kernel.h>
#include <string.h>
#include "layer.h"
#include "../assets/custom_fonts.h"

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);

    char text[10] = {};

    if (state->layer_label == NULL || strlen(state->layer_label) == 0) {
        sprintf(text, "LAY %i", state->layer_index);
    } else {
        strncpy(text, state->layer_label, 9);
        to_uppercase(text);
    }

    lv_canvas_draw_text(canvas, 0, 50, 68, &label_dsc, text);
}
