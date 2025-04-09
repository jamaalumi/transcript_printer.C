#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "parser.h"

static void trim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
}

void parseFile(FILE *file, CourseList *list) {
    char line[256];
    Course *current = NULL;

    while (fgets(line, sizeof(line), file)) {
        trim(line);
        if (strlen(line) == 0) continue;

        if (line[0] == '[') {
            char *colon = strchr(line, ':');
            char *end = strchr(line, ']');
            if (!colon || !end) continue;

            *colon = 0;
            *end = 0;
            Course *course = &list->courses[list->count++];
            strncpy(course->title, line + 1, MAX_TITLE);
            course->credits = atoi(colon + 1);
            course->studentCount = 0;
            trim(course->title);
            current = course;
        } else {
            if (!current) {
                printf("Ignoring line (no course defined yet): %s\n", line);
                continue;
            }

            char *colon = strchr(line, ':');
            if (!colon) continue;
            *colon = 0;

            Student *student = &current->students[current->studentCount++];
            strncpy(student->name, line, MAX_NAME);
            student->grade = atoi(colon + 1);
            trim(student->name);
        }
    }
}

void printTranscript(CourseList *list, const char *studentName) {
    int total = 0, credits = 0, found = 0;

    for (int i = 0; i < list->count; ++i) {
        Course *course = &list->courses[i];
        for (int j = 0; j < course->studentCount; ++j) {
            if (strcmp(course->students[j].name, studentName) == 0) {
                printf("%s (%d credits): grade %d\n",
                       course->title,
                       course->credits,
                       course->students[j].grade);
                total += course->students[j].grade * course->credits;
                credits += course->credits;
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No records found for %s.\n", studentName);
    } else {
        printf("Average grade: %.2f\n", credits ? (float)total / credits : 0.0);
    }
}

void freeCourses(CourseList *list) {
    // No dynamic allocation, nothing to free
}
//
// Created by jamaa on 9.4.2025.
//

#include "parser.h"
