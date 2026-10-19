#include <stdio.h>

typedef struct
{
    int id;
    char name[50];
    char major[50];
} Student;

int main(void)
{
    Student students[] = {
        {108, "Kamol", "Physics"},
        {103, "Madina", "Economics"},
        {105, "Zebo", "Computer Science"},
        {101, "Amina", "Computer Science"},
        {107, "Nilufar", "Biology"},
        {102, "Farid", "Mathematics"},
        {106, "Rustam", "Design"},
        {104, "Daler", "Engineering"}
    };

    int student_count = sizeof students / sizeof students[0];

    // Sort the complete records by ID using selection sort.
    int i = 0;
    while (i < student_count - 1)
    {
        int min = i;
        int j = i + 1;
        while (j < student_count)
        {
            if (students[j].id < students[min].id)
            {
                min = j;
            }
            j++;
        }
        if (min != i)
        {
            Student temp = students[i];
            students[i] = students[min];
            students[min] = temp;
        }
        i++;
    }

    // Print the sorted directory.
    printf("Sorted directory:\n");
    i = 0;
    while (i < student_count)
    {
        printf("%d - %s\n", students[i].id, students[i].name);
        i++;
    }
    printf("\n");

    // Read the target ID.
    int target_id;
    printf("Student ID: ");
    scanf("%d", &target_id);

    // Search for the ID using binary search.
    int low = 0;
    int high = student_count - 1;
    int count = 0;
    int found_index = -1;

    while (low <= high)
    {
        count++;
        int mid = low + (high - low) / 2;

        if (students[mid].id == target_id)
        {
            found_index = mid;
            break;
        }
        else if (students[mid].id < target_id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Print the result and number of comparisons.
    if (found_index != -1)
    {
        printf("Name: %s\n", students[found_index].name);
        printf("Major: %s\n", students[found_index].major);
    }
    else
    {
        printf("Student not found.\n");
    }
    printf("Comparisons: %d\n", count);
}
