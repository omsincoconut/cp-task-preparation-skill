#include <algorithm>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "constraints.h"

using namespace std;
using namespace elevator_constraints;

namespace {

int H;

// The statement promises "the scenarios may be ordered differently in each
// process". Without it the call index of a process is a clock shared with the
// rooftop, and a solution can answer from the index alone without pressing a
// single button. The seed is derived from the test file, so a rerun of the same
// test gives the same verdict while a submission cannot predict the order.
std::mt19937 scenario_rng(1);

unsigned compute_scenario_seed(std::vector<std::vector<int>> const &values,
                               int subtask) {
  unsigned long long h =
      1469598103934665603ULL ^ static_cast<unsigned>(subtask);
  for (auto const &row : values)
    for (int v : row) {
      h ^= static_cast<unsigned long long>(v) + 0x9e3779b97f4a7c15ULL;
      h *= 1099511628211ULL;
    }
  return static_cast<unsigned>(h ^ (h >> 32));
}

enum class ErrorCode {
  DUPLICATE_BUTTON,
  BUTTON_OUT_OF_RANGE,
  BUTTON_ALREADY_PRESSED,
  WRONG_ANSWER_LENGTH,
  WRONG_RECOVERED_VALUE,
  MALFORMED_INPUT,
  IO_FAILURE,
  CHANGED_HASH_FAILURE,
};

// EJOI 2026 rules, section 7: the grading system reports one of a fixed set of
// verdicts. The manager must emit exactly one of those strings and nothing more
// -- no detail about which rule was broken, and no test data.
const char *verdict(ErrorCode const code) {
  switch (code) {
  case ErrorCode::DUPLICATE_BUTTON:
  case ErrorCode::WRONG_RECOVERED_VALUE:
  case ErrorCode::BUTTON_OUT_OF_RANGE:
  case ErrorCode::BUTTON_ALREADY_PRESSED:
  case ErrorCode::WRONG_ANSWER_LENGTH:
    return "Output isn't correct";
  case ErrorCode::IO_FAILURE:
  case ErrorCode::MALFORMED_INPUT:
  case ErrorCode::CHANGED_HASH_FAILURE:
    return "Protocol violation";
  }

  return "Unknown error";
}

void write_to_output_txt(string const message) {
  ofstream file("output.txt");
  file << message << endl;
}

[[noreturn]] void result(double const score, const char *const message) {
  printf("%.4f\n", score);
  fprintf(stderr, "%s\n", message);
  exit(0);
}

[[noreturn]] void fail(ErrorCode const code) { result(0, verdict(code)); }

[[noreturn]] void success(double const points) {
  if (1.0 - points < 0.001)
    result(points, "Output is correct");
  result(points, "Output is partially correct");
}

struct proc {
  std::ofstream to_user;
  std::ifstream from_user;
  proc(std::string to, std::string from) : to_user(to), from_user(from) {}
};

std::vector<int> readline(std::istream &in) {
  int input_H = 0;
  if (!(in >> input_H)) {
    write_to_output_txt("IO closed at read h.");
    fail(ErrorCode::IO_FAILURE);
  }

  if (input_H != H) {
    fail(ErrorCode::IO_FAILURE);
  }

  int count;
  if (!(in >> count)) {
    write_to_output_txt("IO closed at read line.");
    fail(ErrorCode::IO_FAILURE);
  }
  if (count < 0 || count > FLOOR_COUNT) {
    write_to_output_txt("IO read an impossible count.");
    fail(ErrorCode::IO_FAILURE);
  }

  std::vector<int> line(count);
  for (int i = 0; i < count; i++) {
    if (!(in >> line[i])) {
      write_to_output_txt("IO closed while reading numbers from the line.");
      fail(ErrorCode::IO_FAILURE);
    }
  }

  return line;
}

void writeline(std::ostream &out, std::vector<int> const &value) {
  out << value.size() << " ";
  for (auto i : value)
    out << i << " ";
  out << std::endl;
}

double compute_points(int const recovered, int const subtask) {
  if (subtask == 0) {
    // The example carries no points, but a run that broke no rule is still
    // a correct run: returning 0 makes every solution, the model included,
    // report "Output isn't correct" on the sample. The checker treats
    // subtask 0 as ok, so match it.
    return 1;
  } else if (subtask == 1) {
    if (recovered < 60) {
      return 0.25 * recovered / POINTS_SUBTASK_1;
    }
    return 1;
  } else if (subtask == 2) {
    if (recovered < 30) {
      return 0.5 * recovered / POINTS_SUBTASK_2;
    } else if (recovered < 40) {
      return (2.0 * recovered - 45) / POINTS_SUBTASK_2;
    }
    return 1;
  } else if (subtask == 3) {
    if (recovered < 30) {
      return 0.5 * recovered / POINTS_SUBTASK_3;
    }
    return 1;
  } else if (subtask == 4) {
    if (recovered < 20) {
      return 0.7 * recovered / POINTS_SUBTASK_4;
    } else if (recovered < 25) {
      return (4.0 * recovered - 66) / POINTS_SUBTASK_4;
    }
    return 1;
  }
  throw std::runtime_error("invalid subtask value");
}

// The elevator opens at floor f only if f is floor 0 or its button has already
// been pressed. A process of a floor the elevator never reaches must not be
// asked anything at all, so the number of calls it gets is sent in the header
// instead of the number of test cases.
void run_floor(proc &pipes, int const subtask, int const N,
               vector<int> const &values, vector<vector<int>> &pressed_so_far,
               int const floor) {
  size_t const T = values.size();

  vector<size_t> opened;
  for (size_t test = 0; test < T; ++test) {
    vector<int> const &pressed = pressed_so_far[test];
    if (floor == 0 || binary_search(pressed.begin(), pressed.end(), floor)) {
      opened.push_back(test);
    }
  }

  shuffle(opened.begin(), opened.end(), scenario_rng);

  pipes.to_user << opened.size() << " " << N << " " << subtask << " " << H
                << endl;

  for (size_t const test : opened) {
    pipes.to_user << values[test] << endl;
    writeline(pipes.to_user, pressed_so_far[test]);

    auto added = readline(pipes.from_user);
    sort(added.begin(), added.end());
    if (adjacent_find(added.begin(), added.end()) != added.end()) {
      write_to_output_txt("Same button incorrectly pressed twice.");
      fail(ErrorCode::DUPLICATE_BUTTON);
    }
    for (int const button : added) {
      if (!(floor < button && button <= N)) {
        write_to_output_txt("Pressed out of range button.");
        fail(ErrorCode::BUTTON_OUT_OF_RANGE);
      }
    }

    // pressed_so_far[test] and added are both sorted, merge them and reject
    // any button that is pressed twice.
    vector<int> const &pressed = pressed_so_far[test];
    vector<int> all_pressed;
    all_pressed.reserve(pressed.size() + added.size());
    size_t a = 0, b = 0;
    while (a < pressed.size() || b < added.size()) {
      if (b == added.size()) {
        all_pressed.push_back(pressed[a++]);
      } else if (a == pressed.size()) {
        all_pressed.push_back(added[b++]);
      } else if (pressed[a] == added[b]) {
        write_to_output_txt("Attempted to press the same button again.");
        fail(ErrorCode::BUTTON_ALREADY_PRESSED);
      } else if (pressed[a] < added[b]) {
        all_pressed.push_back(pressed[a++]);
      } else {
        all_pressed.push_back(added[b++]);
      }
    }
    pressed_so_far[test] = all_pressed;
  }
}

int run_rooftop(proc &pipes, int const subtask, int const N,
                vector<vector<int>> const &values,
                vector<vector<int>> const &pressed_so_far) {
  size_t const T = values.size();

  pipes.to_user << T << " " << N << " " << subtask << " " << H << endl;
  vector<size_t> order(T);
  for (size_t i = 0; i < T; ++i)
    order[i] = i;
  shuffle(order.begin(), order.end(), scenario_rng);

  int minimum_recovered = N + 1;
  for (size_t const test : order) {
    writeline(pipes.to_user, pressed_so_far[test]);

    auto decoded = readline(pipes.from_user);
    if (decoded.size() != static_cast<size_t>(N + 1)) {
      write_to_output_txt("Wrong answer length.");
      fail(ErrorCode::WRONG_ANSWER_LENGTH);
    }
    int recovered = 0;
    for (int floor = 0; floor <= N; ++floor) {
      if (decoded[floor] == -1)
        continue;
      if (decoded[floor] != values[test][floor]) {
        write_to_output_txt("Recovered an incorrect value.");
        fail(ErrorCode::WRONG_RECOVERED_VALUE);
      }
      ++recovered;
    }
    minimum_recovered = min(minimum_recovered, recovered);
  }

  return minimum_recovered;
}

} // namespace

int main(int argc, char **argv) {
  if ((FLOOR_COUNT + 1) * 2 + 1 != argc) {
    std::cout << (FLOOR_COUNT + 1) * 2 + 1 << std::endl;
    std::cout << argc << std::endl;
    throw std::runtime_error("unexpected number of parameters to manager");
  }
  // A process that closes its stdin must not take the manager down with it.
  signal(SIGPIPE, SIG_IGN);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0,
                                             std::numeric_limits<int>::max());
  H = distrib(gen);

  int input_t = 0;
  int input_n = 0;
  string trailing;
  int subtask;
  // The test file's first line is "T N S" -- the same format the generator
  // writes, the validator checks and the sample grader reads. Reading only
  // two numbers here made N land in subtask, so every run was rejected.
  if (!(cin >> input_t >> input_n >> subtask) || input_t < 1 ||
      input_t > MAX_T || input_n != N ||
      maximum_value_for_subtask(subtask) < 0) {
    write_to_output_txt("Provided T, N or subtask are out of bounds");
    fail(ErrorCode::MALFORMED_INPUT);
  }

  int const maximum_value = maximum_value_for_subtask(subtask);
  vector<vector<int>> values(input_t, vector<int>(input_n + 1));
  for (int test = 0; test < input_t; ++test) {
    for (int floor = 0; floor <= input_n; ++floor) {
      if (!(cin >> values[test][floor]) || values[test][floor] < 0 ||
          values[test][floor] > maximum_value) {
        write_to_output_txt("Failure reading floor values V_f");
        fail(ErrorCode::MALFORMED_INPUT);
      }
    }
  }
  if (cin >> trailing) {
    write_to_output_txt("Trailing characters at the end of test");
    fail(ErrorCode::MALFORMED_INPUT);
  }

  unsigned seed = compute_scenario_seed(values, subtask);
  scenario_rng.seed(seed);

  vector<vector<int>> pressed_so_far(input_t, vector<int>());

  vector<proc> all_pipes;
  for (int i = 0; i < input_n + 2; i++) {
    all_pipes.emplace_back(argv[i * 2 + 2], argv[i * 2 + 1]);
  }

  for (int floor = 0; floor <= input_n; floor++) {
    auto &pipes = all_pipes.at(floor);
    vector<int> vs;
    vs.reserve(input_t);
    for (int test = 0; test < input_t; test++) {
      vs.push_back(values[test][floor]);
    }

    run_floor(pipes, subtask, input_n, vs, pressed_so_far, floor);
  }

  auto &pipes = all_pipes.at(input_n + 1);
  int const recovered =
      run_rooftop(pipes, subtask, input_n, values, pressed_so_far);

  const double points = compute_points(recovered, subtask);
  if (seed != compute_scenario_seed(values, subtask)) {
    write_to_output_txt("Hash changed");
    fail(ErrorCode::CHANGED_HASH_FAILURE);
  }

  std::stringstream ss;
  ss << "Scored " << setprecision(4) << fixed << points * 100
     << "% of subtask points.";
  write_to_output_txt(ss.str());
  success(points);
}
