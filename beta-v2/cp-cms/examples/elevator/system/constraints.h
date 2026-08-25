#ifndef ELEVATOR_CONSTRAINTS_H
#define ELEVATOR_CONSTRAINTS_H

#include <cstddef>
namespace elevator_constraints {

constexpr int N = 60;
constexpr int FLOOR_COUNT = N + 1;
constexpr int MAX_T = 10000;

constexpr int SUBTASK_MIN = 0;
constexpr int SUBTASK_MAX = 4;

constexpr int K_SUBTASK_0 = 0;
constexpr int K_SUBTASK_1 = 60;
constexpr int K_SUBTASK_2 = 40;
constexpr int K_SUBTASK_3 = 30;
constexpr int K_SUBTASK_4 = 25;

constexpr int POINTS_SUBTASK_0 = 0;
constexpr int POINTS_SUBTASK_1 = 15;
constexpr int POINTS_SUBTASK_2 = 35;
constexpr int POINTS_SUBTASK_3 = 15;
constexpr int POINTS_SUBTASK_4 = 35;

inline int maximum_value_for_subtask(int subtask) {
    if (subtask == 0) return 3;
    if (subtask == 1) return 1;
    if (subtask == 2) return 1;
    if (subtask == 3) return 2;
    if (subtask == 4) return 3;
    return -1;
}

inline int target_k_for_subtask(int subtask) {
    if (subtask == 0) return K_SUBTASK_0;
    if (subtask == 1) return K_SUBTASK_1;
    if (subtask == 2) return K_SUBTASK_2;
    if (subtask == 3) return K_SUBTASK_3;
    if (subtask == 4) return K_SUBTASK_4;
    return -1;
}

inline int points_for_subtask(int subtask) {
    if (subtask == 0) return POINTS_SUBTASK_0;
    if (subtask == 1) return POINTS_SUBTASK_1;
    if (subtask == 2) return POINTS_SUBTASK_2;
    if (subtask == 3) return POINTS_SUBTASK_3;
    if (subtask == 4) return POINTS_SUBTASK_4;
    return -1;
}

}  // namespace elevator_constraints

#endif
