#include <stdio.h>

void towerOfHanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }

    towerOfHanoi(n - 1, src, aux, dest);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    towerOfHanoi(n - 1, aux, dest, src);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("\nTower of Hanoi Steps:\n");
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
