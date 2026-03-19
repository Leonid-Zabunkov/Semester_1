#include <iostream>
#include <ostream>

// void o_to_0(char* str)

// int main(int argc, char* argv[]){
//     std::cout << "argc " << argc << atd::endl;
//     for(int i = 0; i < argc; i++){
//         std::cout << "argv " << i << "]: " << (argv + i) << std::endl;
//         o_to_0(argv[i]);
//         std::cout << "argv[" << i << "] ahter o_to_0: " << argv[i] << std::endl;

//     }
//     return 0;
// }

// void o_to_0(char* str){
//     while(*str != '\n'){
//         if (*str == 'o'){
//             *str = '0'
//         }
//         str++;
//     }
// }

bool check_number(char* str);
bool check_operator(char* str);
int check_calculatable(int left, int right, char* op);
int to_int(char* str);
int calculate(int left, int right, char* op);

int main(int argc, char* argv[]){
    if(argc != 4){
        std::cout << "invalid argument" << std::endl;
        return 2;
    }

    bool no_err;
    char* left = argv[1];
    char* right = argv[3];
    char* op = argv[2];

    no_err = check_number(left) && check_operator(op) && check_number(right);
    
    if (!no_err){
        std::cout << "invalid argument" <<std::endl;
        return 2;
    }
    int l, r;
    l = to_int(left);
    r = to_int(right);

    no_err = check_calculatable(l, r, op);
    if (! no_err){
        std::cout << "invalid argument" <<std::endl;
        return 3;
    }
    int result = calculate(l, r, op);
    std::cout << result <<std::endl;
    return 0;
}


int to_int(char* str){
    bool positive;
    int result = 0;
    if (str[0] == '-'){
        positive = false;
        str++;
    }else if(str[0] == '+'){
        positive = true;
        str++;
    }else{
        positive = true;
    }
    while (*str != '\0') {
        result *= 10;
        result += *str - '0';
        str++;
    }
    if(! positive){
        result *= -1;
    }
    return result;
}

// как упражнение - дописать функции