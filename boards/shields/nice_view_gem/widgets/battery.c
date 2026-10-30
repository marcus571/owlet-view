/*
 * battery.c
 * 2026-11-06 终极计算版：
 *   Y=6，绝对防换行，数字与图标距离拉开。
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
    lv_canvas_draw_text(canvas, 28, 6, 24, &label_right_dsc, text);
}

static void draw_charging_level(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);
    lv_draw_label_dsc_t label_right_dsc;
    init_label_dsc(&label_right_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);

    char text[10] = {};

    sprintf(text, "%i%%", state->battery);
    lv_canvas_draw_text(canvas, 28, 6, 22, &label_right_dsc, text);
    // 闪电图标对齐文字中心
    lv_canvas_draw_img(canvas, 54, 7, &bolt, &img_dsc);
}

void draw_battery_status(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_left_dsc;
    init_label_dsc(&label_left_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);
    // 宽度给 28，绝对防换行
    lv_canvas_draw_text(canvas, 0, 6, 28, &label_left_dsc, "BAT");

    if (state->charging) {
        draw_charging_level(canvas, state);
    } else {
        draw_level(canvas, state);
    }
}
