#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Core {
  long cost;
  int time = 0;
};

void swap(Core &a, Core &b) {
  auto temp = a;
  a = b;
  b = temp;
}

bool compareCores(Core &a, Core &b) {
  if (a.time < b.time)
    return true;
  if (a.time == b.time)
    return a.cost < b.cost;
  return false;
}

void makeMinHeap(std::vector<Core> &arr, int n, int i) {
  int best = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && compareCores(arr[best], arr[left])) {
    best = left;
  }

  if (right < n && compareCores(arr[best], arr[right])) {
    best = right;
  }

  if (best != i) {
    swap(arr[i], arr[best]);
    makeMinHeap(arr, n, best);
  }
}

void reorderHeap(std::vector<Core> &arr, int n, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && compareCores(arr[left], arr[i])) {
    swap(arr[i], arr[left]);
    reorderHeap(arr, n, left);
  }

  if (right < n && compareCores(arr[right], arr[left])) {
    swap(arr[left], arr[right]);
    reorderHeap(arr, n, right);
  }
}

void makeSort(std::vector<Core> &arr, int n) {

  for (int i = n / 2 - 1; i >= 0; i--) {
    makeMinHeap(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    makeMinHeap(arr, i, 0);
  }
}

bool findFreeCore(std::vector<Core> &cores, int time) {
  int end = cores.size();
  for (auto i = 0; i < cores.size(); i++) {
    auto &core = cores[i];
    if (core.time > time) {
      end = i;
      break;
    }
    core.time = 0;
  }
  if (end == 0)
    return false;
  if (end > 0) {
    makeSort(cores, end);
  }
  return true;
}

int main() {
  int n, m, x;
  std::cin >> n >> m;
  std::vector<Core> cores(n);

  for (auto i = 0; i < n; i++) {
    std::cin >> cores[i].cost;
  }
  // std::sort(cores.begin(), cores.end(), compareCores);

  long sum = 0;
  int t, deltaT, f;

  for (auto i = 0; i < m; i++) {
    std::cin >> t >> f;
    if (!findFreeCore(cores, t)) {
      continue;
    }

    sum += cores[0].cost * f;
    cores[0].time = t + f;
    reorderHeap(cores, n, 0);
  }
  std::cout << sum;
}