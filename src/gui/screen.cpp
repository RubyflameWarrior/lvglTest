#include "gui/screen.hpp"
#include <src/core/lv_obj_tree.h>
#include <src/extra/widgets/tabview/lv_tabview.h>
#include <src/misc/lv_area.h>
#include <string>

using namespace GUI;

Screen::Screen(lv_obj_t *iparent)
    : Page(iparent), tabview(lv_tabview_create(container, LV_DIR_TOP, 20)){

                     };

lv_obj_t *Screen::newPage(const std::string &iname) {
  lv_obj_t *page = lv_tabview_add_tab(tabview, iname.c_str());
  // lv_page_set_sb_mode(page, LV_SB_MODE_OFF);
  lv_obj_align(page, LV_ALIGN_TOP_MID, 0, 0);
  return page;
}

void Screen::render() {
  for (auto &&page : pages) {
    page->render();
  }
}
