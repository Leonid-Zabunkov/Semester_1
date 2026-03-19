// int main() {
//     return 0;
// }

#include <stdio.h>

// main()
// {
//     int fahr, celsius;
//     int lower, upper, step;

//     lower = 0;
//     upper = 300;
//     step = 20;

//     fahr = lower;
//     while (fuhr <= upper) {
//         celsius = 5 * (fahr-32) / 9;
//         printf("%d\t%d\n", fahr, celsius);
//         fahr = fahr + step;

//     }
// }

// main()
// {
//     int fahr;
//     #define LOWER 0
//     #define UPPER 300
//     #define STEP 20

//     for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
//     printf("%3d %6.1\n", fahr, (5.0 / 9.0) * (fahr - 32));
// }

// c = getchar()
// putchar(c)

// main()
// {
//     int c;
//     c = getchar();
//     while (c != EOF) {
//         putchar(c);
//         c = getchar();

//     }
// }

// main() {
//   long nc;
//   nc = 0

//     while (getchar() != EOF)
//         ++nc
//     printf("%ld\n", nc)

// }

// main()
// {
//     double nc;
//     for (nc = 0; getchar() != EOF; ++nc);
//     printf("$.0f\n", nc);

// }

int main() {
  auto n1 = 0;

  //   while ((c = getchar()) != EOF) {
  //     if (c == '\n') {
  //       ++n1;
  //       hasNewLine = false;
  //     } else {
  //       hasNewLine = true;
  //     }
  //   }
  //   if (hasNewLine) {
  //     n1++;
  //   }

  printf("%d\n", ++n1 + n1++);
}