#include <stdio.h>

// Fungsi untuk menghitung faktorial
int faktorial(int y) {
    if (y == 0 || y == 1) {
        return 1;
    } else {
        return y * faktorial(y - 1);
    }
}

// Fungsi untuk menghitung nilai Fibonacci
int fibonacci(int x) {
    if (x <= 1) {
        return x;
    } else {
        return fibonacci(x - 1) + fibonacci(x - 2);
    }
}

int main() {
    int y;
    printf("Masukkan nilai untuk menentukan deret Fibonacci: ");
    scanf("%d", &y);
    printf("%d! = ", y);
    for (int i = y; i > 0; i--) {
        printf("%d", i);
        if (i != 1) {
            printf("x");
        }
    }
    printf(" = %d\n", faktorial(y));
    
    return 0;
}
