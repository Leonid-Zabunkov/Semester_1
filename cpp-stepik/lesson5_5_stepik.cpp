// #include <stdio.h>

// #define TOTAL     10

// int main(void)
// {
//     int digs[TOTAL] = {0};
//     size_t count = 0;
//     size_t sz_ar = sizeof(digs) / sizeof(*digs);

//     while(count < sz_ar && scanf("%d", &digs[count]) == 1)
//         count++;

//     bool flag = false;
//     for(int i = 0; i < (int) count; i++){
//         printf("%d ", digs[i]);

//         if(digs[i] == 5 && flag == false){
//             printf("%d ", -5);
//             flag = true;

//         }
//     }
//     return 0;
// }

// #include <stdbool.h>
// #include <stdio.h>

// #define TOTAL 10

// int main(void) {
//   int pows[TOTAL] = {0};
//   size_t count = 0;
//   size_t sz_ar = sizeof(pows) / sizeof(*pows);

//   while (count < sz_ar && scanf("%d", &pows[count]) == 1)
//     count++;

//   for (int i = 0; i < count; i++) {
//     if ((pows[i] % 3 == 0)) {
//       for (int j = i; j < count - 1; j++) {
//         pows[j] = pows[j + 1];
//       }
//       count--;
//       i--;
//     }
//   }
//   for (int i = 0; i < count; i++) {
//     printf("%d ", pows[i]);
//   }

//   return 0;
// }

#include <stdbool.h>
#include <stdio.h>

#define TOTAL 20

int main(void) {
  float ws[TOTAL] = {0.0f};
  size_t count = 0;
  size_t sz_ar = sizeof(ws) / sizeof(*ws);

  while (count < sz_ar && scanf("%f", &ws[count]) == 1)
    count++;

  int min_ind = 0;
  float x;
  for (int i = 0; i < count; i++) {
    min_ind = i;
    for (int j = i; j < count; j++) {
        min_ind = ws[j] < min_ind ? j : min_ind;
    }
    if(ws[min_ind] < ws[i]){
        x = ws[i];
        ws[i] = ws[min_ind];
        ws[min_ind] = x;
    }
  }

  for(int i = 0; i < count; i++){
    printf("%.2f ", ws[i]);
  }

  return 0;
}