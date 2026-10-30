#include <stdlib.h>
#include <zephyr/kernel.h>
#include "animation.h"

// 声明只保留第一张图片
LV_IMG_DECLARE(crystal_01);

void draw_animation(lv_obj_t *canvas) {
    lv_obj_t *art = lv_img_create(canvas);
    lv_img_set_src(art, &crystal_01);
    
    // 让 Logo 在画布正中显示
    lv_obj_align(art, LV_ALIGN_CENTER, 0, 0);
}
