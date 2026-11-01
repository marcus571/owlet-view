# ============================================================
# nice_view_gem CMakeLists.txt
# 路径：boards/shields/nice_view_gem/CMakeLists.txt
#
# 2026-11-06 修正版：
#   1. 移除了不存在的 assets/custom_fonts.c。
#   2. 显式只编译我们当前 UI 需要的 .c 文件。
#   3. 原版的 wpm.c、profile.c 等文件即使还在目录中，
#      也不会参与编译，不影响最终固件。
# ============================================================

zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY
    widgets/screen.c
    widgets/battery.c
    widgets/output.c
    widgets/layer.c
    widgets/util.c
    assets/images.c
)
