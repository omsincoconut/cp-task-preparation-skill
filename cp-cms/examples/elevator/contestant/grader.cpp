#define DETAILED false
#define AUTO_GENERATE false

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>

#include "constraints.h"
#include "elevator.h"

using namespace std;

namespace {

void log(const string &details) {
  if (DETAILED && !details.empty()) {
    cout << "Error: " << details << endl;
  }
}

void invalidInput(const string &details = "") {
  log(details);
  cout << "Invalid input!" << endl;
  exit(0);
}

// An invalid operation costs every point of the subtask. It is reported as a
// recovered count of -1 for the offending test case, followed by 0 points.
void invalidOperation(const string &details = "") {
  log(details);
  cout << -1 << endl;
  cout << setprecision(2) << fixed << 0.0 << endl;
  exit(0);
}

int run_all(const int subtask, const int N, const vector<vector<int>> &values) {
  const int T = static_cast<int>(values.size());
  vector<vector<int>> final_buttons(T);

  for (int test = 0; test < T; ++test) {
    if (DETAILED) {
      cout << "Running test " << test << " with V: [";
      for (int f = 0; f <= N; ++f) {
        cout << (f == 0 ? "" : ", ") << values[test][f];
      }
      cout << "]" << endl;
    }

    set<int> pressed;
    for (int floor = 0; floor <= N; ++floor) {
      if (floor != 0 && !pressed.count(floor)) {
        continue;
      }

      const vector<int> added =
          press_buttons(subtask, N, floor, values[test][floor],
                        vector<int>{pressed.begin(), pressed.end()});
      for (const int button : added) {
        if (!(floor < button && button <= N)) {
          invalidOperation("Invalid button pressed.");
        }

        if (pressed.count(button)) {
          invalidOperation("Pressed same button twice.");
        }

        pressed.insert(button);
      }
    }
    final_buttons[test] = vector<int>{pressed.begin(), pressed.end()};
  }

  int minimum_recovered = N + 1;
  for (int test = 0; test < T; ++test) {
    vector<int> decoded = answer(subtask, N, final_buttons[test]);
    if (decoded.size() != static_cast<size_t>(N + 1)) {
      invalidOperation("Answer does not contain N + 1 elements.");
    }
    int recovered = 0;
    for (int floor = 0; floor <= N; ++floor) {
      if (decoded[floor] == -1)
        continue;
      if (decoded[floor] != values[test][floor]) {
        invalidOperation("Wrong answer.");
      }
      ++recovered;
    }
    cout << recovered << endl;
    minimum_recovered = min(minimum_recovered, recovered);
  }

  return minimum_recovered;
}

bool is_value_ok(const int subtask, const int N, const int V_max,
                 const int V_prev, const int V, const int f) {
  if (V < 0 || V > V_max) {
    return false;
  }

  if (subtask == 1) {
    if (f == 0 || f == N) {
      return V == 1;
    }
    return V_prev == 1 || V == 1;
  }

  return true;
}

void ensure_end_of_input() {
  if (AUTO_GENERATE) {
    return; // the values in the file were deliberately not read
  }
  string trailing;
  if (cin >> trailing) {
    invalidInput("Expected end of input, but read additional data");
  }
}

double calc_score(const int subtask, const int k) {
  switch (subtask) {
  case 0:
    return 0;
  case 1:
    if (k < 60)
      return 0.25 * k;
    else
      return 15;
  case 2:
    if (k < 30)
      return 0.5 * k;
    else if (k < 40)
      return 2 * k - 45;
    else
      return 35;
  case 3:
    if (k < 30)
      return 0.5 * k;
    else
      return 15;
  case 4:
    if (k < 20)
      return 0.7 * k;
    else if (k < 25)
      return 4 * k - 66;
    else
      return 35;
  default:
    return -1;
  }
}

} // namespace

int main() {
  int subtask = 0;
  int input_t = 0;
  int input_n = 0;
  if (!(cin >> input_t >> input_n >> subtask) || input_t < 1 || input_n < 1) {
    invalidInput();
  }
  if (elevator_constraints::maximum_value_for_subtask(subtask) < 0) {
    invalidInput("Invalid subtask number");
  }

  const int maximum_value =
      elevator_constraints::maximum_value_for_subtask(subtask);
  mt19937 gen(AUTO_GENERATE ? random_device{}() : 0u);
  uniform_int_distribution<int> V_gen(0, maximum_value);

  vector<vector<int>> values(input_t, vector<int>(input_n + 1));
  for (int test = 0; test < input_t; ++test) {
    for (int f = 0; f <= input_n; ++f) {
      const int V_prev = f == 0 ? -1 : values[test][f - 1];

      if (!AUTO_GENERATE) {
        if (!(cin >> values[test][f])) {
          invalidInput("Not able to read V");
        }
      } else {
        while (true) {
          values[test][f] = V_gen(gen);
          if (is_value_ok(subtask, input_n, maximum_value, V_prev,
                          values[test][f], f)) {
            break;
          }
        }
      }

      if (!is_value_ok(subtask, input_n, maximum_value, V_prev, values[test][f],
                       f)) {
        invalidInput();
      }
    }
  }

  ensure_end_of_input();

  const int recovered = run_all(subtask, input_n, values);
  cout << setprecision(2) << fixed << calc_score(subtask, recovered) << endl;
  return 0;
}
