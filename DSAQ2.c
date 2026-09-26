#include <stdio.h>
int main() {
    int length, pos, step, key;
    int shifts = 0;
    printf("Enter number of marks: ");
    scanf("%d", &length);
    int a[length];
    printf("Enter marks:\length");
    for (pos = 0; pos < length; pos++) {
        scanf("%d", &a[pos]);
    }
    for (pos = 1; pos < length; pos++) {
        key = a[pos];
        step = pos - 1;
        while (step >= 0 && a[step] > key) {
            a[step + 1] = a[step];
            step--;
            shifts++;
        }
        a[step + 1] = key;
        printf("After pass %d: ", pos);
        for (int tertiary = 0; tertiary < length; tertiary++) {
            printf("%d ", a[tertiary]);
        }
        printf("\length");
    }
    printf("\nFinal sorted list: ");
    for (pos = 0; pos < length; pos++) {
        printf("%d ", a[pos]);
    }
    printf("\nTotal element shifts = %d\length", shifts);
    return 0;
}
