#include "SDL.h"
#include <SDL2/SDL.h>
#include "lv_drivers/display/monitor.h"

#include "lvgl.h"
#include <iostream>

static int tick_thread(void *data);

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics
 * library
 */
static void hal_init(void) {
  /* Add a display
   * Use the 'monitor' driver which creates window on PC's monitor to simulate a
   * display*/
  // monitor_init();
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  // disp_drv.disp_flush = monitor_flush;
  // disp_drv.disp_fill = monitor_fill;
  // disp_drv.disp_map = monitor_map;
  lv_disp_drv_register(&disp_drv);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  // mouse_init();
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv); /*Basic initialization*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  // indev_drv.read = mouse_read;
  lv_indev_drv_register(&indev_drv);

  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);
  // SDL_CreateThread(lvgl_thread, "lvgl", NULL);
}

static int tick_thread(void *data) {
  (void)data;

  while (1) {
    SDL_Delay(5);
    lv_tick_inc(5); /*Tell LittelvGL that 5 milliseconds were elapsed*/
  }

  return 0;
}

int main(int argc, char *argv[]) {

  printf("hello world\n");

  hal_init();
  lv_init();
  return 0;
}
