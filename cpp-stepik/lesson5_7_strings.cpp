#include <stdio.h>

// Способы инициализации строк в С:

// int main(void) {
//   char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
//   char s[] = "Hello";
//   char buffer[64] = "Hello";
//   char b[] = "He"
//              "ll"
//              "o";

//   char sp[] = "Hel\
// lo";

// в чём разница?

// char* str_1 = "Balakirev";
// char s[] = "Balakirev";
// str[0] = 'A'
// s[0] = 'A'
// поэтому пишут
// const char* str_2 = "Balakirev";

// Для вывода puts();
//   return 0;
// }

// int main(void)
// {
//     char str[100] = "Best string!";
//     int i = 0;
//     while(str[i] != '\0'){

//         if(str[i] == 's' || str[i] == 'S'){
//             for(int j = i; str[j] != '\0'; j++){
//                 str[j] = str[j+1];
//             }
//             continue;
//         }
//         i++;
//     }
//     puts(str);

//     return 0;
// }

// int main(void)
// {
//     char str[50] = "best string!";
//     int x;
//     for(x = 0; str[x] != '\0'; x++);
//     x++;
//     char s[5] = "The ";

//     for(int i = 3; i != -1; i--){
//         for(int j = x; j > 0; j--){
//             str[j] = str[j-1];
//         }
//         str[0] = s[i];
//         x++;
//     }

//     puts(str);
//     return 0;
// }

int main(void) {

  char str[50] = "Best   language  \"C\"";
  char my_str[50] = "";
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (str[i] == str[i + 1] || str[i] == ' ') {
      my_str[j] = '\n';
      j++;
    }
    i++;
  }
  my_str[j+1] = '\0';

  return 0;
}