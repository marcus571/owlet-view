/*
 * layer.c
 * 2026-11-06 修改记录：
 *   1. Y 坐标退回安全的 32。
 *   2. 增加空字符串校验，防止 layer_label 为空导致不渲染。
 */
#include <zephyr/kernel.h>
#include <string.h>
#include "layer.h"
#include "../assets/custom_fonts.h"

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);

    char text[10] = {};

    if (state->layer_label == NULL || strlen(state->layer_label) == 0) {
        sprintf(text, "Layer %i", state->layer_index);
    } else {
        strncpy(text, state->layer_label, 9);
        to_uppercase(text);
    }

    // Y 坐标退回原版的安全值 32
    lv_canvas_draw_text(canvas, 0, 32, 68, &label_dsc, text);
}
