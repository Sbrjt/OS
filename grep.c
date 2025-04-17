#include <stdio.h>

int main() {
    char filename[10], line[100], term[10];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter search term: ");
    scanf("%s", term);

    FILE *f = fopen(filename, "r");

    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, term)) {
            printf("%s", line);
        }
    }
}
