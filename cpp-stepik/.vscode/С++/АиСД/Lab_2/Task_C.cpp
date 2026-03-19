#include <algorithm>
#include <iostream>
#include <vector>

namespace AISD_Lab2 {

struct Track {
  int index;
  int stable;
  int pop;
};

void task_C() {
  int n;
  std::cin >> n;
  std::vector<Track> lst;
  lst.reserve(n);

  for (auto i = 1; i < n + 1; i++) {
    Track t;
    std::cin >> t.pop >> t.stable;
    t.index = i;

    if (lst.empty()) {
      lst.push_back(t);
      continue;
    }

    auto it = std::lower_bound(lst.begin(), lst.end(), t, [](Track a, Track b) {
      if (a.pop < b.pop)
        return true;
      if (a.pop > b.pop)
        return false;
      if (a.stable < b.stable)
        return true;
      if (a.stable > b.stable)
        return false;
      return a.index < b.index;
    });

    lst.insert(it, t);
  }
  for (auto t : lst) {
    std::cout << t.index << " ";
  }
}
} // namespace AISD_Lab2
