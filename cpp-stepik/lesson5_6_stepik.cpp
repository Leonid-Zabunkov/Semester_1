#include <cstddef>
#include <stdio.h>

// int main(void) {
//   int game_pole[5][3];

//   size_t bytes = sizeof(game_pole);
//   size_t row_bytes = sizeof(game_pole[0]);
//   size_t rows = sizeof(game_pole) / sizeof(game_pole[0]);
//   size_t cols = sizeof(game_pole[0]) / sizeof(game_pole[0][0]);

//   // указатель как на одномерный массив
//   int *p_row = game_pole[1];

//   // указатель на двумерный массив
//   int (*p_ar)[3] = game_pole;

//   int x_1 = p_ar[0][1];
//   int x_2 = p_ar[1][2];

//   // это массив из указателей:
//   int *ptr[3];

//   printf("%d \n%d", (int)rows, (int)cols);

//   return 0;
// }

// int main(void) {
//   int x;
//   int ar_2D[4][3] = {0};
//   for (int i = 0; i < sizeof(ar_2D) / sizeof(ar_2D[0]); i++) {
//     for (int j = 0; j < sizeof(ar_2D[0]) / sizeof(ar_2D[0][0]); j++) {
//       scanf("%d ", &x);
//       ar_2D[i][j] = x;
//     }
//   }
//   for (int i = 0; i < 3; i++) {
//     for (int j = 0; j < 4; j++) {
//       j < 3 ? printf("%d ", ar_2D[j][i]) : printf("%d\n", ar_2D[j][i]);
//     }
//   }
//   return 0;
// }

// #define ROWS    3
// #define COLS    5

// int main(void)
// {
//     short vls[ROWS][COLS] = {0};
//     short *ptr_vls = &vls[0][0];

//     short x;
//     for(int i = 0;i < ROWS * COLS && scanf("%hd", &x) == 1; ++i)
//         *ptr_vls++ = x;

//     double mean[3] = {};
//     for(int i = 0; i < 3; i++){
//       for(int j = 0; j<5; j++){
//         mean[i] += vls[i][j];
//       }
//       mean[i] /= 5;
//       printf("%.2f ", mean[i]);
//     }

//     __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и
//     должно идти непосредственно перед return 0) return 0;
// }

#define ROWS 3
#define COLS 4

int main(void) {
  int a[ROWS][COLS] = {0};
  int b[ROWS][COLS] = {0};
  int *ptr_a = &a[0][0];
  int *ptr_b = &b[0][0];

  int x;
  for (int i = 0; i < ROWS * COLS && scanf("%d", &x) == 1; ++i)
    *ptr_a++ = x;
  for (int i = 0; i < ROWS * COLS && scanf("%d", &x) == 1; ++i)
    *ptr_b++ = x;

  int res[ROWS][COLS] = {0};
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j<COLS; j++){
      res[i][j] = a[i][j] + b[i][j];
      printf("%d", res[i][j]);
      j<COLS-1 ? printf(" ") : printf("\n");
    }
  }  
  return 0;
}