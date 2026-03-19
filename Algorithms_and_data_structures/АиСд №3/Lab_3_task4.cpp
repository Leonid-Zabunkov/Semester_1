#include <iostream>
#include <queue>
#include <vector>


struct Core {
  long cost;

  bool operator>(const Core &other) const { return cost > other.cost; }
};

struct BusyCore {
  long release_time;
  long cost;

  bool operator>(const BusyCore &other) const {
    return release_time > other.release_time;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  long t, f, cost, sum = 0;

  std::priority_queue<Core, std::vector<Core>, std::greater<Core>> cores;
  for (int i = 0; i < n; ++i) {
    std::cin >> cost;
    cores.push({cost});
  }

  std::priority_queue<BusyCore, std::vector<BusyCore>, std::greater<BusyCore>> busy_cores;

  for (int i = 0; i < m; ++i) {
    std::cin >> t >> f;

    while (!busy_cores.empty() && busy_cores.top().release_time <= t) {
      Core core = {busy_cores.top().cost};
      busy_cores.pop();
      cores.push(core);
    }

    if (!cores.empty()) {
      auto core = cores.top();
      cores.pop();

      sum += core.cost * f;

      busy_cores.push({t + f, core.cost});
    }
  }

  std::cout << sum << std::endl;

  return 0;
}