#pragma once

#include "gui/page.hpp"

namespace GUI {
class Graph : public Page {
public:
  using Page::Page;

  void initialize() override;

  void render() override;

private:
  lv_obj_t *graph;
};
} // namespace GUI
