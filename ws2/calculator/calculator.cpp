#include "calculator.h"

int calculate (int first, int second, char operation) {
    int result{0};
    switch (operation) {
        case '+' : result = first + second;
        break;
        case '-' : result = first - second;
        break;
        case '*' : result = first * second;
        break;
        case '/' : {
            if (second != 0)
                result = first / second;
        }
        break;
    }
    return result;

}
