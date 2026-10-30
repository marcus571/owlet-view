/*
 * battery.c
 * 2026-11-06 修改记录：
 *   1. 电量数字改为左对齐，X坐标设为 20，紧贴 "BAT"。
 *   2. 充电图标 X 坐标设为 55。
 */
#include <zephyr/kernel.h>
#include "battery.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bolt);

static void draw_level(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_right_dsc;
    init_label_dsc(&label_right_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);

    char text[10] = {};

    sprintf(text, "%i%%", state->battery);
    lv_canvas_draw_text(canvas, 20, 0, 42, &label_right_dsc, text);
}

static void draw_charging_level(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    lv_draw_label_dsc_t label_right_dsc;
    init_label_dsc(&label_right_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);

    char text[10] = {};

    sprintf(text, "%i%%", state->battery);
    lv_canvas_draw_text(canvas, 20, 0, 35, &label_right_dsc, text);
    lv_canvas_draw_img(canvas, 55, 1, &bolt, &img_dsc);
}

void draw_battery_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_left_dsc;
    init_label_dsc(&label_left_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);
    lv_canvas_draw_text(canvas, 0, 0, 20, &label_left_dsc, "BAT");

    if (state->charging) {
        draw_charging_level(canvas, state);
    } else {
        draw_level(canvas, state);
    }
}
