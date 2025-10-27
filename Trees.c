#include <stdio.h>

int main() {
    int treeNodes[] = {50, 30, 90, 10, 40, 70, 100};

    printf("Mapping of tree as an array:\n");
    for (int i = 0; i < 7; i++) {
        printf("Index %d → %d\n", i, treeNodes[i]);
    }

    return 0;
}
