#ifndef PARSER_H
#define PARSER_H

#define MAX_COURSES 100
#define MAX_STUDENTS 100
#define MAX_NAME 100
#define MAX_TITLE 100

typedef struct {
    char name[MAX_NAME];
    int grade;
} Student;

typedef struct {
    char title[MAX_TITLE];
    int credits;
    Student students[MAX_STUDENTS];
    int studentCount;
} Course;

typedef struct {
    Course courses[MAX_COURSES];
    int count;
} CourseList;

void parseFile(FILE *file, CourseList *list);
void printTranscript(CourseList *list, const char *studentName);
void freeCourses(CourseList *list);

#endif
//
// Created by jamaa on 9.4.2025.
//

#ifndef PARSER_H
#define PARSER_H

#endif //PARSER_H
