#include <algorithm>
#include <cstddef>
#include <deque>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int task_1() {
  int n;
  std::cin >> n;

  std::vector<int> lst(n);
  for (auto i = 0; i < n; i++) {
    std::cin >> lst[i];
  }

  for (auto i = 1; i <= n / 2; i++) {
    if ((2 * i <= n) && !(lst[i - 1] <= lst[2 * i - 1])) {
      std::cout << "NO" << std::endl;
      return 0;
    }
    if ((2 * i + 1 <= n) && !(lst[i - 1] <= lst[2 * i])) {
      std::cout << "NO" << std::endl;
      return 0;
    }
  }
  std::cout << "YES" << std::endl;
}

void swap(int &a, int &b) {
  auto temp = a;
  a = b;
  b = temp;
}

void makeMaxHeap(int arr[], int n, int i) {
  int best = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // Если левый потомок меньше корня
  if (left < n && arr[left] > arr[best]) {
    best = left;
  }

  // Если правый потомок меньше, чем наименьший элемент на данный момент
  if (right < n && arr[right] > arr[best]) {
    best = right;
  }

  // Если наименьший элемент не является корнем
  if (best != i) {
    swap(arr[i], arr[best]);
    // Рекурсивно восстанавливаем кучу в затронутом поддереве
    makeMaxHeap(arr, n, best);
  }
}

void heapSort(int arr[], int n) {

  for (int i = n / 2 - 1; i >= 0; i--) {
    makeMaxHeap(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    makeMaxHeap(arr, i, 0);
  }
}

int task_2() {
  int n;
  std::cin >> n;

  int arr[n];
  for (auto i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  heapSort(arr, n);

  for (auto i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}

int getMin(std::vector<int> &queue) {
  auto x = queue[0];
  // begin - создаёт итератор на начало
  queue.erase(queue.begin());
  return x;
}

int getMax(std::vector<int> &queue) {
  auto x = queue[queue.size() - 1];
  queue.pop_back();
  return x;
}

void insert(std::vector<int> &queue, int x) {
  auto it = std::lower_bound(queue.begin(), queue.end(), x);
  queue.insert(it, x);
}

int task_3() {
  int n;
  std::cin >> n;
  std::string s;
  std::vector<int> queue;
  queue.reserve(n);
  for (auto i = 0; i < n; i++) {
    std::cin >> s;
    if (s[0] == 'I') {
      auto x = std::stoi(s.substr(7, s.length() - 8));
      insert(queue, x);
    }
    if (s == "GetMin") {
      std::cout << getMin(queue) << std::endl;
    }
    if (s == "GetMax") {
      std::cout << getMax(queue) << std::endl;
    }
  }
  return 0;
}
