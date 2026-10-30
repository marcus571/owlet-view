/*
 * layer.c
 * 2026-11-06 修改记录：
 *   将 Y 坐标从 48 改为安全的 36，避免被画布底部裁切。
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

    // Y 坐标设为 36（原版是 34），确保能画在 68x68 的画布内
    lv_canvas_draw_text(canvas, 0, 36, 68, &label_dsc, text);
}
