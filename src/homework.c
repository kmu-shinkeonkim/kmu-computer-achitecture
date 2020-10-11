#include <stdio.h>

int main() {
    int a[5] = {30, 50, -10, 45, 100};
    int sum = 0;

    for(int i = 0; i < 5; i++) {
        sum += a[i];
    }
}