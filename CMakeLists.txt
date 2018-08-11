cmake_minimum_required(VERSION 3.2)
project(wiiushell C)
include("${WUT_ROOT}/share/wut.cmake" REQUIRED)

add_executable(wiiushell
   main.c
   video.c
   menu.c
   )

target_link_libraries(wiiushell
   coreinit
   vpad
   whb
   proc_ui
   sysapp)

wut_create_rpx(wiiushell.rpx wiiushell)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/wiiushell.rpx"
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
