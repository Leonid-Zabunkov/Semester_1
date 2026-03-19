#include <stdio.h>

// int main(void) {
//   char data[6][30];
//   for (int i = 0; i < 6; i++) {
//     scanf("%30s", data[i]);
//   }
//   for (int i = 0; i < 6; i++) {
//     if (data[i][0] == 'G') {
//       printf("%s ", data[i]);
//     }
//   }
// }

void strip_string(char *str, int max_len) {
  int count = 0;
  while (*str++ != '\0' && count++ < max_len)
    ;

  if (count > 1) {
    str -= 2;
    if (*str == '\n')
      *str = '\0';
  }
}

// int main(void) {
//   char str[100];
//   fgets(str, sizeof(str), stdin);
//   strip_string(str, sizeof(str));

//   int i = 0;
//   while (str[i] != '\0') {
//     if (str[i] == 'e') {
//       for (int j = i; j < sizeof(str); j++) {
//         str[j] = str[j + 1];
//       }
//     }
//     continue;
//   }
//   printf("%s", str);

//   return 0;
// }

int main(void) {
  char str[100];
  fgets(str, sizeof(str), stdin);
  strip_string(str, sizeof(str));

  bool flag = false;
  int count = 0, i = 0;

  while (str[i] != '\0') {

    if (str[i] != ' ') {
      if (flag == 0) {
        flag = 1;
        count++;
        if (count == 2) {
          break;
        }
      }
    } else if (str[i] == ' ' && flag == 1) {
      flag = 0;
    }

    i++;
  }
  if (count < 2) {
    printf("%s", "no");
  } else if (count == 2) {
    while (str[i] != ' ' && str[i] != '\0') {
      printf("%c", str[i]);
      i++;  
    }
  }
  return 0;
}