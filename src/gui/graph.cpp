#include "gui/graph.hpp"
#include "lvgl.h"
#include <iostream>
#include <src/extra/widgets/chart/lv_chart.h>

namespace GUI {

void Graph::initialize() { graph = lv_chart_create(container); }
void Graph::render() { printf("hello from the graph\n"); }

} // namespace GUI
