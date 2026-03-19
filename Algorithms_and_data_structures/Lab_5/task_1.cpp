#include <cstdio>
#include <iostream>
// #include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  int u, v;
  std::vector<std::vector<char>> matr_smegn(n, std::vector<char>(n, 0));
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    matr_smegn[u][v] = 1;
  }
}