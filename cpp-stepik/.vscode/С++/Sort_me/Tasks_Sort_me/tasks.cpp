#include <iostream>
#include <string>
#include <vector>

void task_1() {
  std::cout << "Input 2 numbers: ";
  long int a, b;
  std::cin >> a >> b;
  if (a == b) {
    std::cout << a + b;
    return;
  }
  if (a > b) {
    auto t = a;
    a = b;
    b = t;
  }
  std::cout << (a + b) / 2 * (b - a + 1);
}

void task_6() {

  std::string s;
  std::getline(std::cin, s); // Считываем всю строку
  int a = 0;
  for (auto c : s) {
    if (c == '(') {
      a++;
    }
    if (c == ')') {
      a--;
    }
    if (a < 0) {
      break;
    }
  }
  if (a != 0) {
    std::cout << "NO";
  } else {
    std::cout << "YES";
  }
}

void task_37() {
  unsigned int n, m;
  std::cin >> n >> m;

  if (n != m + 1) {
    std::cout << "NO";
    return;
  }

  std::vector<char> lst(n);

  for (auto i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    if (a > n || b > n) {
      std::cout << "NO";
      return;
    }
    if ((lst[a - 1]++ == 2) || (lst[b - 1]++ == 2)) {
      std::cout << "NO";
      return;
    }
  }
  int e = 0;
  for (auto x : lst) {
    if (x == 0) {
      std::cout << "NO";
      return;
    } else if (x == 1) {
      e++;
    }
  }
  if (e != 2) {
    std::cout << "NO";
    return;
  }
  std::cout << "YES";
}
