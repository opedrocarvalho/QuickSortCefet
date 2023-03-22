#include <stdio.h>

void Quicksort(int vet[], int l, int r) {
    int pivot = vet[l + (r - l) / 2];
  
    int left = l, right = r;
    
    while (left <= right) {
        while (vet[left] < pivot) left++;
        while (vet[right] > pivot) right--;
        if (left <= right) {
            int temp = vet[left];
            vet[left] = vet[right];
            vet[right] = temp;
            left++;
            right--;
        }
    }
    
    if (l < right) Quicksort(vet, l, right);
    if (left < r) Quicksort(vet, left, r);
}

int main() {
    int v[] = {6, 1, 8, 3, 9, 2, 10, 7};
    int length = sizeof(v) / sizeof(int);
    
    Quicksort(v, 0, length - 1);
    
    for (int i = 0; i < length; i++)
        printf("%d ", v[i]);
    printf("\n");
    
    return 0;
}
