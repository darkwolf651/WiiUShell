cmake_minimum_required(VERSION 3.2)
project(wiiushell C)
include("${WUT_ROOT}/share/wut.cmake" REQUIRED)

add_executable(wiiushell
   src/main.c
   src/video.c
   src/menu.c
   src/draw.c
   src/theme.c
   src/IO.c)

target_link_libraries(wiiushell
   coreinit
   vpad
   whb
   proc_ui
   sysapp)

wut_create_rpx(wiiushell.rpx wiiushell)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/wiiushell.rpx"
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
