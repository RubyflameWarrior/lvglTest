#include "gui/page.hpp"
#include "lvgl.h"

namespace GUI {
Page::Page(lv_obj_t *iparent) : container(lv_obj_create(iparent)) {
  lv_obj_set_size(container, lv_obj_get_width(iparent),
                  lv_obj_get_height(iparent));
  //lv_obj_align(container, LV_ALIGN_BOTTOM_MID, 0, 0);
}

Page::~Page() {
  if (container != nullptr) {
    lv_obj_del(container);
  }
}

} // namespace GUI
