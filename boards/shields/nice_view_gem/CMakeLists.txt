# ============================================================
# nice_view_gem CMakeLists.txt
# 路径：boards/shields/nice_view_gem/CMakeLists.txt
#
# 2026-11-06 修复白屏问题：
#   加入 custom_status_screen.c，这是 ZMK 显示子系统的入口文件。
# ============================================================

if(CONFIG_ZMK_DISPLAY)
  target_sources(app PRIVATE
    custom_status_screen.c       # 核心入口：告诉 ZMK 怎么加载我们的屏幕
    widgets/screen.c
    widgets/battery.c
    widgets/output.c
    widgets/layer.c
    widgets/util.c
    assets/images.c
    assets/pixel_operator_mono.c # 真实的字体文件
  )
endif()
