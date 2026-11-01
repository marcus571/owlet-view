# ============================================================
# nice_view_gem CMakeLists.txt
#
# 2026-11-06 瘦身版：
#   移除了 wpm.c, profile.c, animation.c, screen_peripheral.c
# ============================================================

zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY
    widgets/screen.c
    widgets/battery.c
    widgets/output.c
    widgets/layer.c
    widgets/util.c
    assets/images.c
    assets/custom_fonts.c
)
