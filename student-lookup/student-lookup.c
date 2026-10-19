#include <stdio.h>
#include <string.h>


typedef struct
{
    int id;
    char name[50];
    char major[50];
} Student;

int main(void)
{
    Student students[] = {
        {101, "Amina", "Computer Science"},
        {102, "Farid", "Mathematics"},
        {103, "Madina", "Economics"},
        {104, "Rustam", "Design"},
        {105, "Zebo", "Computer Science"}
    };

    // Calculate the number of students.
    int length = sizeof(students) / sizeof(students[0]);
    int atindex = -1;

    // Read the ID to search for.
    printf("Student ID: ");
    int id;
    scanf("%d", &id);

    // Search for a matching student.
    for (int i = 0; i < length; i++)
    {
        if (id == students[i].id)
        {
            atindex = i;
            break;
        }
    }
    // Print the result.
    if (atindex != -1)
    {
        printf("Name: %s\n", students[atindex].name);
        printf("Major: %s\n", students[atindex].major);
    } else {
        printf("Student not found.\n");
    }
    return 0;
}