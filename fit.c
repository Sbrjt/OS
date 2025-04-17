int main() {
    int n, m;

    printf("Enter no. of blocks: ");
    scanf("%d", &n);

    int block[n];
    for (int i = 0; i < n; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("\nEnter no. of processes: ");
    scanf("%d", &m);

    int process[m];
    for (int i = 0; i < m; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    int result[m];
    for (int i = 0; i < n; i++)
        result[i] = -1;

    firstFit(block, process, n, m, result);
    print_allocations(result, m);
}

void firstFit(int block[], int process[], int n, int m, int arr[]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (process[i] <= block[j]) {
                arr[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }
}

void bestFit(int block[], int process[], int n, int m, int arr[]) {
    for (int i = 0; i < m; i++) {
        int idx = -1;
        int d = 1e9;
        for (int j = 0; j < n; j++) {
            if (process[i] <= block[j] && (block[j] - process[i] < d)) {
                d = block[j] - process[i];
                idx = j;
            }
        }

        if (idx != -1) {
            arr[i] = idx;
            block[idx] -= process[i];
        }
    }
}

void worstFit(int block[], int process[], int n, int m, int arr[]) {
    for (int i = 0; i < m; i++) {
        int idx = -1;
        int d = -1;
        for (int j = 0; j < n; j++) {
            if (process[i] <= block[j] && (block[j] - process[i] > d)) {
                d = block[j] - process[i];
                idx = j;
            }
        }

        if (idx != -1) {
            arr[i] = idx;
            block[idx] -= process[i];
        }
    }
}

void print_allocations(int result[], int m) {
    printf("Process \t Block \n");
    for (int i = 0; i < m; i++) {
        if (result[i] != -1)
            printf("%d \t\t %d \n", i + 1, result[i] + 1);
        else
            printf("%d \t\t Unallocated \n", i + 1);
    }
}