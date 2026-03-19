#include <iostream>
#include <vector>

// int main() {
//   int n;
//   std::cin >> n;
//   std::vector<long long> lst;
//   lst.reserve(n);
//   long long x;
//   for (int i = 0; i < n; i++) {
//     std::cin >> x;

//     auto it = std::lower_bound(lst.begin(), lst.end(), x);

//     if (it == lst.end()) {
//       // Если x больше всех текущих "хвостов", добавляем его в конец
//       lst.push_back(x);
//     } else {
//       // Иначе заменяем первый элемент >= x на текущий x (оптимизация)
//       *it = x;
//     }
//     // for (int j = tail; j >= 0; j--) {
//     //   if (tail == 0) {
//     //     lst.push_back(x);
//     //     break;
//     //   }
//     //   if (x > lst[tail]) {
//     //     // lst[j + 1] = x;
//     //     lst.push_back(x);
//     //     tail++;
//     //     break;
//     //   }
//     //   if (lst[j] > x) {
//     //     continue;
//     //   }
//     //   if (lst[j] < x) {
//     //     lst[j + 1] = x;
//     //     break;
//     //   }
//     // }
//   }

//   std::cout << lst.size();
// }



long long dp[31][1 << 9];
int n_val, m_val;

// Рекурсивная функция для построения следующей маски
void solve(int col, int row, int mask, int next_mask) {
  // Базовый случай: все строки обработаны
  if (row >= n_val) {
    dp[col + 1][next_mask] += dp[col][mask];
    return;
  }

  // Если клетка уже занята домино из предыдущего столбца
  if (mask & (1 << row)) {
    solve(col, row + 1, mask, next_mask);
    return;
  }

  // Два варианта:
  // 1. Поставить вертикальное домино 3x1
  // Проверяем, что в текущем столбце и двух следующих строках достаточно места
  if (row + 2 < n_val && !(mask & (1 << (row + 1))) &&
      !(mask & (1 << (row + 2)))) {
    solve(col, row + 3, mask, next_mask);
  }

  // 2. Поставить горизонтальное домино 1x3
  // Проверяем, что в текущем столбце и двух следующих столбцах есть место
  if (col + 2 < m_val) {
    solve(col, row + 1, mask, next_mask | (1 << row));
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  while (std::cin >> n_val >> m_val && (n_val != 0 || m_val != 0)) {
    // Убедимся, что n - меньшая сторона
    if (n_val > m_val) {
      std::swap(n_val, m_val);
    }

    for (int i = 0; i <= m_val; ++i) {
      for (int j = 0; j < (1 << n_val); ++j) {
        dp[i][j] = 0;
      }
    }

    dp[0][0] = 1;

    for (int j = 0; j < m_val; ++j) {
      for (int mask = 0; mask < (1 << n_val); ++mask) {
        if (dp[j][mask] > 0) {
          solve(j, 0, mask, 0);
        }
      }
    }

    std::cout << dp[m_val][0] << std::endl;
  }

  return 0;
}