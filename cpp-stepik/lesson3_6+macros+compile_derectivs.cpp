#include <stdio.h>


// #define SQ_PR(A, B) ((A) * (B))
// #define TEXT(A, B)  "Square of rectangle (" #A ") x (" #B ")\n"


// #if
// #else
// #endif
// #ifndef
// #elif
// #elifdef
// #elifndef

// #define LANG_CPP 1

// #ifdef LANG_CPP
// #   include <iostream>

// #else
// #   include <stdio.h>

// #endif

// int main()
// {
//     int x = 5;

// #ifdef LANG_CPP
//     std::cout << x << std::endl;
// #else
//     printf("%d\n", x);
// #endif

//     return 0;
// }

#include <math.h>
#define X_N(N)      x ## N


int main(void)
{
    int a, b;
    if (scanf("%d, %d", &a, &b) != 2) {
        return 1;
    }

    // здесь продолжайте программу

    double tg = (double)a / b;
    double result = atan(tg);
    printf("%.2lf %.2lf\n", tg, result);


    int x1 = 1, x2 = 2, x4 = 10;
    printf("%d\n", X_N(4)); // x4: оно равно 10
    return 0;
}