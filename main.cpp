#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    long int res[argc-1];
    int iter = 0;
    short sign;
    char* hex;

    for (int i = 0; i < argc - 1; i++){
        hex = argv[i+1];
        res[i] = 0;
        if (hex[iter] == '-'){
            sign = -1;
            iter += 3;
        }
        else if (hex[iter] == '+'){
            sign = 1;
            iter += 3;
        }
        else{
            sign = 1;
            iter += 2;
        }
        while (hex[iter] != '\0'){
            if (hex[iter] < 58) {
                res[i] = res[i] * 16 + (hex[iter] - 48);
            }
            if (hex[iter] > 64 and hex[iter] < 71){
                res[i] = res[i] * 16 + (hex[iter] - 55);
                }
            if (hex[iter] > 96 and hex[iter] < 103){
                res[i] = res[i] * 16 + (hex[iter] - 87);
            }
            ++iter;
        }
        res[i] *= sign;
        iter = 0;
    }

    for (int i = argc - 2; i >= 0; i--){
        cout << res[i] + 100 << endl;
    }

    return 0;
}
