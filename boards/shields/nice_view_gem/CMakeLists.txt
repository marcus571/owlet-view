# ============================================================
# nice_view_gem CMakeLists.txt
# 路径：boards/shields/nice_view_gem/CMakeLists.txt
#
# 2026-11-06 最终修正版：
#   1. 使用 target_sources(app PRIVATE ...) 继承 ZMK 头文件。
#   2. 加入真实存在的字体文件 pixel_operator_mono.c。
#   3. 丢弃废弃的 wpm/profile 等文件。
# ============================================================

if(CONFIG_ZMK_DISPLAY)
  target_sources(app PRIVATE
    widgets/screen.c
    widgets/battery.c
    widgets/output.c
    widgets/layer.c
    widgets/util.c
    assets/images.c
    assets/pixel_operator_mono.c
  )
endif()
