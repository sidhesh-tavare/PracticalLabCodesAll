#include <stdio.h>

void towersOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", fromRod, toRod);
        return;
    }
    towersOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from %c to %c\n", n, fromRod, toRod);
    towersOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);

    printf("The sequence of moves to solve the Towers of Hanoi is:\n");
    towersOfHanoi(numDisks, 'A', 'C', 'B'); // A, B, C are names of rods
    return 0;
}
