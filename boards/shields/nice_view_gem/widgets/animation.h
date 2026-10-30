#pragma once

#include <lvgl.h>
#include "util.h"
// 删除了 #include "screen_peripheral.h"，避免结构体重复定义冲突

void draw_animation(lv_obj_t *canvas);
