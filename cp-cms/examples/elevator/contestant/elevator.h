#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <vector>

std::vector<int> press_buttons(int subtask, int N, int f, int V,
                               std::vector<int> p);
std::vector<int> answer(int subtask, int N, std::vector<int> p);

#endif