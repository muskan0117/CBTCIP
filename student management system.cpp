#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5

const char *subjectTitles[MAX_SUBJECTS] = {"Maths", "English", "Hindi", "Science", "Sanskrit"};

struct Student {
    char fullName[MAX_NAME_LENGTH];
    float grades[MAX_SUBJECTS];
    float averageGrade;
    float highestGrade;
    float lowestGrade;
};

void enterStudentDetails(struct Student *student);
void computeStatistics(struct Student *student);
void showStudentDetails(struct Student *student);

int main() {
    struct Student students[MAX_STUDENTS];
    int i;

    printf("** Student Performance Management System **\n\n");

    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter details for student %d:\n", i + 1);
        enterStudentDetails(&students[i]);
        computeStatistics(&students[i]);
    }

    printf("\n*** Student Information ***\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("\nDetails for student %d:\n", i + 1);
        showStudentDetails(&students[i]);
    }

    return 0;
}

void enterStudentDetails(struct Student *student) {
    int i;

    printf("Enter student name: ");
    getchar(); // Clear input buffer
    fgets(student->fullName, sizeof(student->fullName), stdin);
    student->fullName[strcspn(student->fullName, "\n")] = '\0';

    for (i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter grade for %s: ", subjectTitles[i]);
        scanf("%f", &student->grades[i]);
    }
}

void computeStatistics(struct Student *student) {
    int i;

    student->averageGrade = 0.0;
    student->highestGrade = student->grades[0];
    student->lowestGrade = student->grades[0];

    for (i = 0; i < MAX_SUBJECTS; i++) {
        student->averageGrade += student->grades[i];

        if (student->grades[i] > student->highestGrade) {
            student->highestGrade = student->grades[i];
        }

        if (student->grades[i] < student->lowestGrade) {
            student->lowestGrade = student->grades[i];
        }
    }

    student->averageGrade /= MAX_SUBJECTS;
}

void showStudentDetails(struct Student *student) {
    printf("Name: %s\n", student->fullName);
    printf("Average Grade: %.2f\n", student->averageGrade);
    printf("Highest Grade: %.2f\n", student->highestGrade);
    printf("Lowest Grade: %.2f\n", student->lowestGrade);
}

