#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int main() {
    CourseList courseList = { .count = 0 };
    FILE *file = fopen("grades.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    parseFile(file, &courseList);
    fclose(file);

    char input[100];
    while (1) {
        printf("Enter student name (or 'stop' to quit): ");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;  // Remove newline

        if (strcmp(input, "stop") == 0) break;

        printTranscript(&courseList, input);
    }

    freeCourses(&courseList);
    return 0;
}
//
// Created by jamaa on 9.4.2025.
//
