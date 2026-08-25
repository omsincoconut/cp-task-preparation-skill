#include <csignal>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "elevator.h"

namespace {
std::vector<int> readline(std::istream &in) {
  int N = 0;
  in >> N;
  std::vector<int> line;
  for (int i = 0; i < N; i++) {
    int x;
    in >> x;
    line.push_back(x);
  }

  return line;
}

void writeline(std::ostream &out, const int H, std::vector<int> const &value) {
  out << H << std::endl;
  out << value.size() << " ";
  for (auto i : value)
    out << i << " ";
  out << std::endl;
}

} // namespace

int main(int argc, char **argv) {
  signal(SIGPIPE, SIG_IGN);

  if (argc < 2) {
    throw std::runtime_error("unexpected number of arguments");
  }
  int const current_floor = std::stoi(argv[1]);
  int subtask = 0, T = 0, N = 0, H = 0;
  std::cin >> T >> N >> subtask >> H;

  for (int i = 0; i < T; i++) {
    int floor_value = 0;
    if (current_floor <= N) {
      std::cin >> floor_value;
    }

    std::vector<int> const pressed_buttons = readline(std::cin);

    if (std::cin.fail()) {
      return 0;
    }

    std::vector<int> return_value;

    if (current_floor <= N) {
      return_value = press_buttons(subtask, N, current_floor, floor_value,
                                   pressed_buttons);
    } else {
      return_value = answer(subtask, N, pressed_buttons);
    }

    if (std::cin.fail()) {
      return 0;
    }
    writeline(std::cout, H, return_value);
  }
}
