int main() {
    int pid = getpid(), ppid = getppid();

    printf("pid: %d \n", pid);
    printf("ppid: %d \n", ppid);

    // some heavy computation
    int i = 0;
    while (i++ < 1e7);

    system("ps -o pid,ppid,user,command,%mem,%cpu");
}

// To compile:
//      gcc test.c -o test -w && ./test
// To show intermediate files:
//      -save-temps
