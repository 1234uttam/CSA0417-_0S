#include <stdio.h>

#define NUM_PARTITIONS 6
#define NUM_PROCESSES 5

int main() {
	int i,j;
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[NUM_PROCESSES] = {115, 500, 358, 200, 375};
    int allocated[NUM_PROCESSES] = {-1, -1, -1, -1, -1};  // -1 means not yet allocated

    // Allocate memory to each process
    for (i = 0; i < NUM_PROCESSES; i++) {
        int best_fit_index = -1;
        for (j = 0; j < NUM_PARTITIONS; j++) {
            if (partitions[j] >= processes[i]) {
                if (best_fit_index == -1 || partitions[j] < partitions[best_fit_index]) {
                    best_fit_index = j;
                }
            }
        }
        if (best_fit_index != -1) {
            allocated[i] = best_fit_index;
            partitions[best_fit_index] -= processes[i];
        }
    }

    // Print the results
    printf("Process\tSize\tPartition\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("%d\t%d KB\t", i, processes[i]);
        if (allocated[i] == -1) {
            printf("Not allocated\n");
        } else {
            printf("%d\n", allocated[i]);
        }
    }

    return 0;
}
