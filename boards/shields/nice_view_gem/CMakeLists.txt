# ============================================================
# nice_view_gem CMakeLists.txt
# 路径：boards/shields/nice_view_gem/CMakeLists.txt
#
# 2026-11-06 修正版：
#   使用 target_sources(app PRIVATE ...) 以正确继承 ZMK 的 include 路径。
#   只编译当前 UI 需要的 .c 文件，原版废弃的 wpm.c、profile.c 等不参与编译。
# ============================================================

if(CONFIG_ZMK_DISPLAY)
  target_sources(app PRIVATE
    widgets/screen.c
    widgets/battery.c
    widgets/output.c
    widgets/layer.c
    widgets/util.c
    assets/images.c
  )
endif()
