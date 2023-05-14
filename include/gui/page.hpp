#pragma once
#include "lvgl.h"

namespace GUI {
class Page {
public:
  explicit Page(lv_obj_t *iparent);
  virtual ~Page();

  virtual void initialize() {}

  virtual void render() {}

protected:
  lv_obj_t *container;
  lv_style_t cStyle{};
  lv_color_t themeColor{};
};

} // namespace GUI
