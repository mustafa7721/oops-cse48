
// Program to calculate total, average, and percentage of marks in 5 subjects
#include <stdio.h>

int main() {
    int marks[5], i, total = 0;
    float average, percentage;

    printf("Enter marks of 5 subjects:\n");
    for (i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
    }

    average = total / 5.0;
    percentage = (total / 500.0) * 100; // Assuming each subject is out of 100

    printf("\nTotal marks: %d\n", total);
    printf("Average marks: %.2f\n", average);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
