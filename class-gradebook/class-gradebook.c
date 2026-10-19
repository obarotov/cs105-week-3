#include <stdio.h>

typedef struct
{
    char name[50];
    int score;
} Student;

int main(void)
{
    Student students[10];
    int student_count;

    // Read a valid number of students.
    do
    {
        printf("Number of students: ");
        scanf("%d", &student_count);
    } while (student_count < 3 || student_count > 10);

    // Read every student's name and score.
    for (int i = 0; i < student_count; i++)
    {
        printf("Student %d name: ", i + 1);
        scanf("%49s", students[i].name);

        do
        {
            printf("%s's score: ", students[i].name);
            scanf("%d", &students[i].score);
        } while (students[i].score < 0 || students[i].score > 100);
    }

    // Calculate the average and find the highest-scoring student.
    int sum = 0;
    int top = 0; 

    for (int i = 0; i < student_count; i++)
    {
        sum += students[i].score;
        if (students[i].score > students[top].score)
        {
            top = i;
        }
    }
    float avg = (float)sum / student_count;

    printf("\nAverage: %.2f\n", avg);
    printf("Top student: %s (%d)\n", students[top].name, students[top].score);

    // Sort the Student records by score.
    for (int i = 0; i < student_count - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < student_count; j++)
        {
            if (students[j].score > students[max].score)
            {
                max = j;
            }
        }
        if (max != i)
        {
            Student temp = students[i];
            students[i] = students[max];
            students[max] = temp;
        }
    }

    // Print the results and ranking.
    printf("\nRanking:\n");
    for (int i = 0; i < student_count; i++)
    {
        printf("%d. %s - %d\n", i + 1, students[i].name, students[i].score);
    }
}
