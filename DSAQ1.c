#include <stdio.h>

int main() {
    int n, i, key;
    int low, high, mid, comparisons = 0;

    printf("Enter number of employee IDs: ");
    scanf("%d", &n);

    int id[n];

    printf("Enter IDs in ascending order:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &id[i]);
        
    printf("Enter ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;
        comparisons++;

        if(id[mid] == key) {
            printf("ID found at position %d\n", mid + 1);
            printf("Number of comparisons: %d\n", comparisons);
            return 0;
        }
        else if(key < id[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    printf("ID not found\n");
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}