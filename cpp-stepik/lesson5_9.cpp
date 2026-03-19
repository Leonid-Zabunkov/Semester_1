#include <cstddef>
#include <stdio.h>
#include <string.h>
#include <string>

// int main(void){
//     char str_1[100] = "hello world!";
//     char str_1_copy[15];
//     char str_2[15] = "Hello ";

//     size_t lenth_1 = strlen(str_1);
//     size_t lenth_2 = strlen(str_2);

//     strncpy(str_1_copy, str_1, lenth_1 - 1);

//     strcat(str_1, str_2);

//     size_t max_add_2 = sizeof(str_2) - strlen(str_2) - 1;

//     strncat(str_2, str_1, max_add_2);

//     return 0;
// }

// int main(void){

//     char cities[6][50];

//     char index_of_max_len = 0;
//     char index_of_max_len_2 = 1;

//     for(int i = 0; i<6; i++){
//         scanf("%50s", cities[i]);

//         if(strlen(cities[index_of_max_len]) < strlen(cities[i])){
//             index_of_max_len_2 = index_of_max_len;
//             index_of_max_len = i;
//         } else if (strlen(cities[index_of_max_len_2]) < strlen(cities[i]) &&
//         i!=0) {
//             index_of_max_len_2 = i;
//         }
//     }

//     if(index_of_max_len < index_of_max_len_2){
//         printf("%s %s", cities[index_of_max_len],
//         cities[index_of_max_len_2]);
//     } else {
//         printf("%s %s", cities[index_of_max_len_2],
//         cities[index_of_max_len]);
//     }

//     return 0;
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

// int main(void)
// {
//     char str[100], res_str[100] = "I love language C ";
//     fgets(str, sizeof(str), stdin);
//     strip_string(str, sizeof(str));

//     size_t len_res_str = strlen(res_str);
//     size_t max_add = sizeof(res_str) - len_res_str - 1;

//     strncat(res_str, str, max_add);
//     res_str[sizeof(res_str) - 1] = '\0';

//     printf("%s", res_str);
//     return 0;
// }

// int main(void) {

//   char ps[7][50];

//   for (int i = 0; i < 7; i++) {
//     scanf("%50s", ps[i]);
//   }

//   char ps_sort[357] = "";

//   for (int i = 0; i < 7; i++) {
//     size_t lenth_ps = strlen(ps[i]);
//     if (lenth_ps % 2 == 0) {
//       if (i > 0 && strlen(ps_sort)) {
//         strcat(ps_sort, " ");
//       }

//       strncat(ps_sort, ps[i], lenth_ps);
//     }
//   }

//   printf("%s", ps_sort);
//   return 0;
// }

int main(void) {

  char ps[7][50];
  char indexes[7] = {0, 1, 2, 3, 4, 5, 6};

  for (int i = 0; i < 7; i++) {
    scanf("%50s", ps[i]);
  }

  int x;
  char ind_min_len = 0;
  size_t lenth_ps;
  for (int i = 0; i < 6; i++) {
    
    ind_min_len = i;

    for (int j = i + 1; j < 7; j++) {
      if (strlen(ps[indexes[ind_min_len]]) > strlen(ps[indexes[j]])) {
        ind_min_len = j;
      }
    }

    x = indexes[i];
    indexes[i] = indexes[ind_min_len];
    indexes[ind_min_len] = x;
  }

  char ps_sort[357] = "";
  int index;

  for (int i = 0; i < 7; i++) {
    index = indexes[i];
    lenth_ps = strlen(ps[index]);

    if (i > 0 && strlen(ps_sort)) {
      strcat(ps_sort, " ");
    }

    strncat(ps_sort, ps[index], lenth_ps);
  }
  printf("%s", ps_sort);
  return 0;
}