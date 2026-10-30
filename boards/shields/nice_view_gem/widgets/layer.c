/*
 * layer.c
 * 2026-11-06 修改记录：
 *   调整层数组件 Y 坐标，使其显示在屏幕底部。
 *   去除了旧的 BUFFER_OFFSET_BOTTOM 偏移，直接固定在 Y=50。
 */
#include <zephyr/kernel.h>
#include "layer.h"
#include "../assets/custom_fonts.h"

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_CENTER);

    char text[10] = {};

    if (state->layer_label == NULL) {
        sprintf(text, "Layer %i", state->layer_index);
    } else {
        strncpy(text, state->layer_label, 9);
        to_uppercase(text);
    }

    // Y 坐标改为 50，固定在底部
    lv_canvas_draw_text(canvas, 0, 50, 68, &label_dsc, text);
}
