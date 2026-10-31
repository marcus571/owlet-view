/*
 * layer.c
 * 2026-10-31 修改记录：
 *   整体上移 1 像素，Y=52。
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

    lv_canvas_draw_text(canvas, 0, 52, 68, &label_dsc, text);
}
