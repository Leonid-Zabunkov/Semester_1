#include <stdio.h>
#include <string.h>

// strchr      - поиск 1 символа -> [char] strrchr     - поиск 1 символа <-
// [right char] strstr      - поиск строкового литерала(подстроки) -> [string]
// strbprk     - поиск хотя бы 1 символа из стр. литерала (подстроки) ->
// [pointer break] strcmp      - сравнение строк на равенство [comparison]
// strncmp     - сравнение первых n элементов на равенство -> [comparison]
// strlen      - длина строки [length] strcpy      - копирование 2-ой строки в
// первую                                 [copy] strncpy     - копирование 2-ой
// строки в первую с указанием лимита копирования  [copy] strcat      -
// добавление  2-ой строки к первой [concatenate] strncat     - добавление  2-ой
// строки к первой с указанием лимита добавления   [concatenate]

// int main(void) {
//   char str[100] = {0};
//   fgets(str, sizeof(str) - 1, stdin);
//   char *ptr_n = strrchr(str, '\n');
//   if (ptr_n != NULL)
//     *ptr_n = '\0';

//   int count = 0;
//   char *str_1 = str;
//   while (true) {
//     auto ptr = strstr(str_1, "is");
//     if (!ptr) {
//       break;
//     }
//     count++;
//     str_1 = ptr + 1;
//     continue;
//   }
//   printf("%d", count);
//   return 0;
// }

// int main(void) {
//   char str[100] = {0};
//   fgets(str, sizeof(str) - 1, stdin);
//   char *ptr_n = strrchr(str, '\n');
//   if (ptr_n != NULL)
//     *ptr_n = '\0';

//   // здесь продолжайте программу

//   char str_new[100] = "";

//   char *ptr_str = str;
//   int i = 0;
//   char *ptr;
//   for (ptr = strchr(ptr_str, '-'); ptr; ptr = strchr(ptr_str, '-')) {
//     strncat(str_new, ptr_str, ptr - ptr_str);
//     strcat(str_new, "-+-");
//     ptr_str = ptr + 1;
//   }
//   strcat(str_new, ptr_str);
//   printf("%s", str_new);
//   return 0;
// }

// int main(void)
// {
//     char str[100] = {0};
//     fgets(str, sizeof(str)-1, stdin);
//     char* ptr_n = strrchr(str, '\n');
//     if(ptr_n != NULL)
//         *ptr_n = '\0';

//     // здесь продолжайте программу

//     for(int i = 1; str[i] != '\0'; i++){
//         if(str[i] == '-' && str[i-1] == '-'){
//             for(int j = i; j<100; j++){
//                 str[j-1] = str[j];
//             }
//             i--;
//         }
//     }
//     printf("%s", str);

//     return 0;
// }

// int main(void) {

//   char cities[10][50];

//   char city[50] = "";
//   int count = 0;
//   while (scanf("%s", city) && count < 10) {
//     if (city[0] == '\0') {
//       continue;
//     }
//     for (int i = 0; i < count; i++) {
//       if (strcmp(cities[i], city) == 0) {
//         goto my_continue;
//       }
//     }
//   my_continue:
//     continue;
//     strcpy(cities[count++], city);
//   }

//   for (int i = 0; i < count; i++) {

//     printf("%s ", cities[i]);
//   }

//   return 0;
// }

// int main(void) {
//   int s, m, h;
//   scanf("%d:%d:%d", &s, &m, &h);
//   printf("%02d:%02d:%02d", h, m, s);
// }

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте программу

    char digit;
    int count = 0;
    for(int i = 0; str[i]; i++){
        digit = str[i];
        if(i == 0 && digit == '@'){
            printf("%d", 1);
            return 0;
        }
        
    }

    return 0;
}