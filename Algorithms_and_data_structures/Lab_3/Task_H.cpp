#include <iostream>
#include <vector>

long long dp[31][1 << 9];
int n_val, m_val;

// Рекурсивная функция для построения следующей маски
void solve(int col, int row, int profile, int next_profile) {
    // Базовый случай: все строки обработаны
    if (row >= n_val) {
        dp[col + 1][next_profile] += dp[col][profile];
        return;
    }

    // Если клетка уже занята домино из предыдущего столбца
    if (profile & (1 << row)) {
        solve(col, row + 1, profile, next_profile);
        return;
    }

    // Два варианта:
    // 1. Поставить вертикальное домино 3x1
    // Проверяем, что в текущем столбце и двух следующих строках достаточно места
    if (row + 2 < n_val && !(profile & (1 << (row + 1))) && !(profile & (1 << (row + 2)))) {
        solve(col, row + 3, profile, next_profile);
    }

    // 2. Поставить горизонтальное домино 1x3
    // Проверяем, что в текущем столбце и двух следующих столбцах есть место
    if (col + 2 < m_val) {
        solve(col, row + 1, profile, next_profile | (1 << row));
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