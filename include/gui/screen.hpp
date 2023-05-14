#pragma once
#include "lvgl.h"
#include "page.hpp"
#include <memory>
#include <vector>

namespace GUI {
class Screen : public Page {
public:
  Screen(lv_obj_t *iparent);

  void render();
  void loop();

  lv_obj_t *newPage(const std::string &iname);

  template <class T> std::shared_ptr<T> makePage(const std::string &iname) {
    static_assert(std::is_base_of<Page, T>::value, "T is not a Page");
    auto ptr = std::make_shared<T>(newPage(iname));
    ptr->initialize();
    pages.emplace_back(ptr);
    return ptr;
  }

private:
  lv_obj_t *tabview;
  std::vector<std::shared_ptr<Page>> pages{};
};

} // namespace GUI
