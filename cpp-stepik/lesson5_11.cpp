#include <cstddef>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(void) {

//   int h, m, s;

//   scanf("%d %d %d", &h, &m, &s);
//   char str[40];

//   char *ptr_str = str;

//   sprintf(ptr_str, h < 24 ? "%02d:" : "--:", h);
//   ptr_str += 3;
//   sprintf(ptr_str, m < 60 ? "%02d:" : "--:", m);
//   ptr_str += 3;
//   sprintf(ptr_str, s < 60 ? "%02d" : "--", s);

//   printf("%s", str);

//   return 0;
// }

// int main(void) {
//   char str[100] = {0};
//   fgets(str, sizeof(str) - 1, stdin);
//   char *ptr_n = strrchr(str, '\n');
//   if (ptr_n != NULL)
//     *ptr_n = '\0';

//   // здесь продолжайте программу

//   char s[20];
//   int h, w, d;
//   sscanf(str, "%*s %d %*s %d %*s %d ", &h, &w, &d);

//       __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и
//       должно
//                        // идти непосредственно перед return 0)
//       return 0;
// }

// int main(void) {
//   char str[200] = {0};
//   fgets(str, sizeof(str) - 1, stdin);
//   char *ptr_n = strrchr(str, '\n');
//   if (ptr_n != NULL)
//     *ptr_n = '\0';

//   double csv[50] = {0.0};
//   char *ptr = strchr(str, ':');
//   ptr++;
//   double x;

//   for (int i = 0; ptr != NULL; i++) {
//     sscanf(ptr, "%lf", &x);
//     csv[i] = x;
//     ptr = strchr(ptr, ';');
//     if (ptr != NULL) {
//       ptr++;
//     }
//   }

//   __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно
//                    // идти непосредственно перед return 0)
//       return 0;
// }

// #define TOTAL 10

// int main(void) {
//   char str[TOTAL][50];
//   int count = 0;
//   while (count < TOTAL && fgets(str[count], sizeof(str[0]) - 1, stdin)) {
//     char *ptr_n = strrchr(str[count], '\n');
//     if (ptr_n != NULL)
//       *ptr_n = '\0';
//     count++;
//   }

//   char s[20];
//   int x;

//   for (int i = 0; i < count; i++) {
//     if (sscanf(str[i], "%[^:]: %*d; %d;", s, &x) == 2) {
//       if (x == 12300) {
//         continue;
//       }

//       printf("%s ", s);
//     }
//   }

//   return 0;
// }

// int main(void) {

//   char str[255];

//   fgets(str, sizeof(str), stdin);

//   char *ptr = strchr(str, ':');
//   ptr++;
//   int x, count = 0;
//   double sr_zn = 0;

//   while (ptr != NULL) {
//     sscanf(ptr, "%d", &x);
//     sr_zn += x;
//     count++;
//     ptr = strchr(ptr, ',');
//     if (ptr != NULL) {
//       ptr++;
//     }
//   }
//   printf("%0.3lf", sr_zn / count);
//   return 0;
// }

int main(void) {

  char str[255];

  fgets(str, sizeof(str), stdin);
    char s[20];
  sscanf(str, "%s", s);
  printf("%s: ", s);

  char *ptr = strchr(str, ' ');
  ptr++;

  int x;

    for (int i = 0; ptr != NULL; i++) {
    sscanf(ptr, "%d", &x);

    i != 0 ? printf(", %d", x) : printf("%d", x);
    ptr = strchr(ptr, ' ');
    if (ptr != NULL) {
      ptr++;
    }
  }

  return 0;
}
