// #include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <experimental/filesystem>

int main() {
  int c, i, nwhite, nother;
  int ndigit[10];

  auto& x = std::cout;

  x << "sxds\n" << std::ends << "ddd";

  std::ifstream file("./test.txt");

  nwhite = nother = 0;

  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;

    printf("Цифры =");
    for (i = 0; i < 10; ++i)
      printf("%d", ndigit[i]);
    printf(", символы-разделители = %d, прочие = %d\n", nwhite, nother);
  }
}

// сущуствует функция pow(n, m)
// c и с++ не перетирает аргументы функций, т. к. берёт копии !!!!!

// int power1(int base, int n);
// {
//   int i, p;
//   p = 1 for (i = 1; i <= n; ++i) p = p * base;

//   return p;
// }

// int power2(int base, int n) {
//   int p;

//   for (p = 1; n > 0; --n)
//     p = p * base;
//   return p;
// }

// main()
// {
//   int i;
//   for (i = 0; i < 10; ++i)
//     printf("%d %d %d\n", i, power(2, i), power(-3, i));
//   return 0;
// }

// #include <stdio. h>
// #define MAXLINE 1000 /* максимальный размер вводимой строки */
// int getline(char line[], int MAXLINE);
// void copy(char to[], char from[]); /* печать самой длинной строки */
// main() {

//   int len;               /* длина текущей строки */
//   int max;               /* длина максимальной из просмотренных строк */
//   char line[MAXLINE];    /* текущая строка */
//   char longest[MAXLINE]; /* самая длинная строка */

//   max = 0;
//   while ((len = getline(line, MAXLINE)) > 0)
//     if (len > max) {
//       max = len;
//       copy(longest, line);
//     }

//   if (max > 0) /* была ли хоть одна строка? */
//     printf("%s", longest);
//   return 0;
// }

// /* getline: читает строку в s, возвращает длину */
// int getline(char s[], int lim) {
//   int c, i;
//   for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n;'; ++i)
//     s[i] = c;
//   if (c == 'n') {
//     s[i] = c;
//     ++i;
//   }
//   s[i] = '\0';
//   return i;
// }

// /* copy: копирует т 'from' в 'to'; to достаточно большой */
// void copy(char to[], char from[]) {
//   int i;

//   i = 0;
//   while ((to[i] = from[i]) != '\0')
//     ++i;
// }


#include <stdio.h>

int main()
{
    int a, b;
    a = getchar();
    getchar();
    b = getchar();
    printf("%d", a+b);
}