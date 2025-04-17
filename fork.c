// fork creates a new child

int main() {
    printf("Creating child and parent processes... \n");

    int n = fork();

    if (n == 0)
        printf("For Child:\n PID = %d\n n = %d\n", getpid(), n);
    else
        printf("For Parent:\n PID = %d\n n = %d\n", getpid(), n);

    printf("Done\n");
}
