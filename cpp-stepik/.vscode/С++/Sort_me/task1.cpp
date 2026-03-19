#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> lst(n);

  for (int i = 0; i < n; i++) {
    std::cin >> lst[i];
  }

  std::vector<int> result;
  result.reserve(n);

  result.push_back(lst[0]);

  int count = 0;
  for (int i = 1; i < n; i++) {
    auto x = lst[i];
    bool inserted = false;
    for (auto it = result.begin(); it != result.end(); it++) {
      count++;
      if (*it <= x) {
        result.insert(it, x);
        inserted = true;
        break;
      }
    }
    if (!inserted) {
      result.insert(result.end(), x);
    }
  }

  std::cout << count << std::endl;
}
