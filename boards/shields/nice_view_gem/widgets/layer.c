/*
 * layer.c
 * 2026-11-06 修改记录：
 *   1. 改为左对齐 (LV_TEXT_ALIGN_LEFT)，X=0，解决 L 靠右的问题。
 *   2. Y 坐标下移到 45，拉开与第二行的距离。
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
        sprintf(text, "Layer %i", state->layer_index);
    } else {
        strncpy(text, state->layer_label, 9);
        to_uppercase(text);
    }

    // X=0 左对齐，Y=45
    lv_canvas_draw_text(canvas, 0, 45, 68, &label_dsc, text);
}
