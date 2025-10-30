
// Program to calculate the sum of integers
#include <stdio.h>

int main() {
    int n, i, sum = 0, num;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter integer %d: ", i);
        scanf("%d", &num);
        sum += num;
    }

    printf("Sum of the integers: %d\n", sum);

    return 0;
}
