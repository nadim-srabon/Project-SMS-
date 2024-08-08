#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    int rollno;
    int class;
    char section;
    float due_payment;
};
void viewAllStudentRecord()
{
    printf("You selected 'View all student record'\n");
    struct student s1 = { "", 0, 0.0 };
    FILE *fp1;

    fp1 = fopen("students.txt", "rb");

    while (fread(&s1, sizeof(struct student), 1, fp1))
    {
        printf("Name: %s\nRoll Number: %d\nClass: %d\nSection: %c\nDue Payment: %.2f\n\n", s1.name, s1.rollno,s1.class,s1.section, s1.due_payment);
        s1 = (struct student)
        { "", 0, 0.0
        }; // Reset the struct to avoid printing uninitialized values in the next iteration
    }

    fclose(fp1);
}
void search_student_by_roll()
{
    printf("You selected 'Search for a student by roll number'\n");
    int roll;
    FILE *fp;
    struct student s;

    fp = fopen("students.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(struct student), 1, fp))
    {
        if (s.rollno == roll)
        {
            printf("Name: %s\nRoll Number: %d\nClass: %d\nSection: %c\nDue Payment: %.2f\n\n",
                   s.name, s.rollno, s.class,s.section, s.due_payment);
            fclose(fp);
            return;
        }
    }

    printf("Student with roll number %d not found!!!!!\n", roll);
    fclose(fp);
}
void edit()
{
    FILE *fp;
    int flag = 0, roll;
    struct student s;

    printf("<--:EDIT RECORD:-->\n");
    printf("Enter the Roll Number of the student to edit: ");
    scanf("%d", &roll);

    fp = fopen("students.txt", "rb+");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fread(&s, sizeof(struct student), 1, fp))
    {
        if (s.rollno == roll)
        {
            printf("\nRoll Number: %d\n", s.rollno);
            printf("Name: %s\n", s.name);
            printf("Class: %d\n", s.class);
            printf("Section: %c\n", s.section);
            printf("Due Payment: %.2f\n\n", s.due_payment);


            printf("\nEnter new information:\n\n");
            printf("Enter name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter class: ");
            scanf("%d", &s.class);
            printf("Enter Section: ");
            scanf(" %s", &s.section);
            printf("Enter Due Payment: ");
            scanf("%f", &s.due_payment);

            fseek(fp, -sizeof(struct student), SEEK_CUR);
            fwrite(&s, sizeof(struct student), 1, fp);

            printf("\nRecord updated successfully!\n");
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\nRecord not found!\n");
    }

    fclose(fp);
}

void printClassRoutine()
{
    printf("Class Routine for Class 6\n");
    printf("Time         | Sunday       | Monday        | Tuesday     | Wednesday   | Thursday\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("9:00-9:30    | Math         | English       | Science     | Social      | Art\n");
    printf("9:30-10:00   | Math         | English       | Science     | Social      | Art\n");
    printf("10:00-10:15  | Snack Break  | Snack Break   | Snack Break | Snack Break | Snack Break\n");
    printf("10:15-10:45  | Social       | Math          | English     | Science     | Physical Education\n");
    printf("10:45-11:15  | Science      | Social        | Math        | English     | Physical Education\n");
    printf("11:15-11:30  | Break        | Break         | Break       | Break       | Break\n");
    printf("11:30-12:00  | English      | Science       | Social      | Math        | Gym\n");
    printf("12:00-12:30  | English      | Science       | Social      | Math        | Gym\n");
}

void printClass7Routine() {
    printf("Time       | Sunday               | Monday                  | Tuesday            | Wednesday         | Thursday\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("8:00-8:30  | Mathematics          | English Language        | Science            | Social Studies    | Physical Education\n");
    printf("8:30-9:00  | Mathematics          | English Language        | Science            | Social Studies    | Physical Education\n");
    printf("9:00-9:30  | Social Studies       | Mathematics             | English Language   | Science           | Art & Craft\n");
    printf("9:30-9:45  | Snack Break          | Snack Break             | Snack Break        | Snack Break       | Snack Break\n");
    printf("9:45-10:15 | Science              | Social Studies          | Mathematics        | English Language  | Physical Education\n");
    printf("10:15-10:45| English Language     | Science                 | Social Studies     | Mathematics       | Music & Dance\n");
    printf("10:45-11:00| Break                | Break                   | Break              | Break             | Break\n");
    printf("11:00-11:30| Computer Science     | Islamic Studies / Moral | Computer Science   | Islamic Studies   | Drawing\n");
    printf("11:30-12:00| Computer Science     | Islamic Studies / Moral | Computer Science   | Islamic Studies   | Drawing\n");
}

void printClass8Routine() {
    printf("Time       | Sunday             | Monday                  | Tuesday              | Wednesday            | Thursday\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("8:00-8:30  | Mathematics        | English Language        | Science              | Social Studies       | Physical Education\n");
    printf("8:30-9:00  | Mathematics        | English Language        | Science              | Social Studies       | Physical Education\n");
    printf("9:00-9:30  | Social Studies     | Mathematics             | English Language     | Science              | Art & Craft\n");
    printf("9:30-9:45  | Snack Break        | Snack Break             | Snack Break          | Snack Break          | Snack Break\n");
    printf("9:45-10:15 | Science            | Social Studies          | Mathematics          | English Language     | Physical Education\n");
    printf("10:15-10:45| English Language   | Science                 | Social Studies       | Mathematics          | Music & Dance\n");
    printf("10:45-11:00| Break              | Break                   | Break                | Break                | Break\n");
    printf("11:00-11:30| Computer Science   | Islamic Studies / Moral | Computer Science     | Islamic Studies      | Drawing\n");
    printf("11:30-12:00| Computer Science   | Islamic Studies / Moral | Computer Science     | Islamic Studies      | Drawing\n");
}


void printClass9ScienceRoutine() {
    printf(" Time       |  Sunday     | Monday      | Tuesday    | Wednesday  | Thursday\n");
    printf("------------| ----------- | ------------| ---------- | ---------- | --------\n");
    printf("9:00-9:50   | Bangla      | English     | Math       | Higher Math| Chemistry\n");
    printf("9:50-10:40  | Biology     | Physics     | Religion   | Bangla     | English\n");
    printf("10:40-11:00 | Break       | Break       | Break      | Break      | Break\n");
    printf("11:00-11:50 | Math        | Higher Math | Chemistry  | Biology    | Physics\n");
    printf("11:50-12:40 | English     | Bangla      | Physics    | Religion   | Biology\n");
    printf("12:40-1:20  | Lunch Break | Lunch Break | Lunch Break| Lunch Break| Lunch Break\n");
    printf("1:20-2:10   | Chemistry   | Biology     | English    | Bangla     | Math\n");
    printf("2:10-3:00   | Physics     | Religion    | Math       | Higher Math| Chemistry\n");
}
void printClass10ScienceRoutine() {
    printf(" Time       |  Sunday     | Monday      | Tuesday    | Wednesday  | Thursday\n");
    printf("------------| ----------- | ------------| ---------- | ---------- | --------\n");
    printf("9:00-9:50   | Bangla      | English     | Math       | Higher Math| Chemistry\n");
    printf("9:50-10:40  | Biology     | Physics     | Religion   | Bangla     | English\n");
    printf("10:40-11:00 | Break       | Break       | Break      | Break      | Break\n");
    printf("11:00-11:50 | Math        | Higher Math | Chemistry  | Biology    | Physics\n");
    printf("11:50-12:40 | English     | Bangla      | Physics    | Religion   | Biology\n");
    printf("12:40-1:20  | Lunch Break | Lunch Break | Lunch Break| Lunch Break| Lunch Break\n");
    printf("1:20-2:10   | Chemistry   | Biology     | English    | Bangla     | Math\n");
    printf("2:10-3:00   | Physics     | Religion    | Math       | Higher Math| Chemistry\n");
}

void printClass9CommerceRoutine() {
    printf(" Time      |  Sunday    | Monday    | Tuesday   | Wednesday | Thursday\n");
    printf("-----------| ---------- | -------   | --------- | --------- | --------\n");
    printf("9:00-9:50  | Bangla     | English   | Math      | Accounting| Finance\n");
    printf("9:50-10:40 | Religion   | Management| English   | Bangla    | Math\n");
    printf("10:40-11:00| Break      | Break     | Break     | Break     | Break\n");
    printf("11:00-11:50| Math       | Accounting| Finance   | Religion  | Management\n");
    printf("11:50-12:40| English    | Bangla    | Management| Accounting| Religion\n");
    printf("12:40-1:20 | Lunch Break| L Break   | L Break   | L Break   | Lunch Break\n");
    printf("1:20-2:10  | Accounting | Finance   | English   | Bangla    | Math\n");
    printf("2:10-3:00  | Religion   | Management| Math      | Accounting| Finance\n");
}
void printClass10CommerceRoutine() {
    printf(" Time      |  Sunday    | Monday    | Tuesday   | Wednesday | Thursday\n");
    printf("-----------| ---------- | -------   | --------- | --------- | --------\n");
    printf("9:00-9:50  | Bangla     | English   | Math      | Accounting| Finance\n");
    printf("9:50-10:40 | Religion   | Management| English   | Bangla    | Math\n");
    printf("10:40-11:00| Break      | Break     | Break     | Break     | Break\n");
    printf("11:00-11:50| Math       | Accounting| Finance   | Religion  | Management\n");
    printf("11:50-12:40| English    | Bangla    | Management| Accounting| Religion\n");
    printf("12:40-1:20 | Lunch Break| L Break   | L Break   | L Break   | Lunch Break\n");
    printf("1:20-2:10  | Accounting | Finance   | English   | Bangla    | Math\n");
    printf("2:10-3:00  | Religion   | Management| Math      | Accounting| Finance\n");
}

void printClass9ArtsRoutine() {
    printf("  Time     | Sunday   | Monday   | Tuesday  | Wednesday | Thursday\n");
    printf("---------- |----------|----------|----------|-----------|-----------\n");
    printf("9:00-9:50  | Bangla   | English  | Economics| Logic     | Sociology\n");
    printf("9:50-10:40 | English  | Geograp  | Sociology| Social Wk | Logic    \n");
    printf("10:40-11:00| Break    | Break    | Break    | Break     | Break    \n");
    printf("11:00-11:50| Economi  | Logic    | Sociology| English   | Geography\n");
    printf("11:50-12:40| Sociology| SocialWk | Logic    | Bangla    | Economics\n");
    printf("12:40-1:20 | L Break  | L Break  | L Break  | L Break   | Lunch Break\n");
    printf("1:20-2:10  | Logic    | Bangla   | English  | Economics | Sociology\n");
    printf("2:10-3:00  | Social Wk| Sociology| Geography| English   | Bangla\n");
}
void printClass10ArtsRoutine() {
    printf("  Time     | Sunday   | Monday   | Tuesday  | Wednesday | Thursday\n");
    printf("---------- |----------|----------|----------|-----------|-----------\n");
    printf("9:00-9:50  | Bangla   | English  | Economics| Logic     | Sociology\n");
    printf("9:50-10:40 | English  | Geograp  | Sociology| Social Wk | Logic    \n");
    printf("10:40-11:00| Break    | Break    | Break    | Break     | Break    \n");
    printf("11:00-11:50| Economi  | Logic    | Sociology| English   | Geography\n");
    printf("11:50-12:40| Sociology| SocialWk | Logic    | Bangla    | Economics\n");
    printf("12:40-1:20 | L Break  | L Break  | L Break  | L Break   | Lunch Break\n");
    printf("1:20-2:10  | Logic    | Bangla   | English  | Economics | Sociology\n");
    printf("2:10-3:00  | Social Wk| Sociology| Geography| English   | Bangla\n");
}

int main()
{
    int option,choice,sec,div;
    char title[] = "<=School Management System=>";
    int width = strlen(title) + 4;  // Width of the star pattern

    // Calculate the number of spaces needed for center alignment
    int spaces = (60 - width) / 2;

    // Print top of star pattern
    for (int i = 1; i <= 60; i++)
    {
        printf("*");
    }
    printf("\n");

    // Print middle section of star pattern with centered title
    printf("  *");
    for (int i = 1; i <= spaces - 1; i++)
    {
        printf(" ");
    }
    printf("%s", title);
    for (int i = 1; i <= spaces - 1; i++)
    {
        printf(" ");
    }
    if (width % 2 == 0)
    {
        printf("*");
    }
    else
    {
        printf(" ");
    }
    printf("\n");

    // Print bottom of star pattern
    for (int i = 1; i <= 60; i++)
    {
        printf("*");
    }
    printf("\n");

    printf("\n");
    printf("                Students Module:\n");
    printf("               =================\n\n");
    printf("                 [1] Add a student record\n");
    printf("                 [2] View all student record\n");
    printf("                 [3] Search for a student record\n");
    printf("                 [4] Edit a student record\n");
    printf("                 [5] Delete a student record\n\n");

    printf("                Teachers Module:\n");
    printf("               =================\n\n");
    printf("                 [6] Add a teacher record\n");
    printf("                 [7] View all teacher record\n");
    printf("                 [8] Search for a teacher record\n");
    printf("                 [9] Edit a teacher record\n");
    printf("                 [10] Delete a teacher record\n\n");
    printf("                Academic:\n");
    printf("               ==========\n\n");
    printf("                 [11] Class Routine\n\n");
    printf("                 Press '0' to exit\n");



    do
    {
        printf("\n              #Enter an option (0-11): ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("You selected 'Add a student record'\n");
            struct student s;
            FILE *fp;

            fp = fopen("students.txt", "ab");

            printf("Enter name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter roll number: ");
            scanf("%d", &s.rollno);
            printf("Enter class: ");
            scanf("%d", &s.class);
            printf("Enter section: ");
            scanf("%s", &s.section);
            printf("Enter Due Payment: ");
            scanf("%f", &s.due_payment);

            fwrite(&s, sizeof(struct student), 1, fp);
            fclose(fp);

            break;

        case 2:
            viewAllStudentRecord();
            break;
        case 3:
            printf("You selected 'Search for a student record'\n");
            search_student_by_roll();
            break;
        case 4:
            printf("You selected 'Edit a student record'\n");
            edit();
            break;
        case 5:
            printf("You selected 'Delete a student record'\n");
            struct student s2;
            FILE *fp2, *temp_file;
            int roll_to_delete;
            int found = 0;

            printf("Enter the roll number of the student to delete: ");
            scanf("%d", &roll_to_delete);

            fp2 = fopen("students.txt", "rb");
            temp_file = fopen("temp.txt", "wb");

            while (fread(&s2, sizeof(struct student), 1, fp2))
            {
                if (s2.rollno == roll_to_delete)
                {
                    found = 1;
                    continue;
                }
                fwrite(&s2, sizeof(struct student), 1, temp_file);
            }

            fclose(fp2);
            fclose(temp_file);

            if (found == 0)
            {
                printf("Record not found!\n");
                remove("temp.txt");
            }
            else
            {
                remove("students.txt");
                rename("temp.txt", "students.txt");
                printf("Record deleted successfully!\n");
            }
            break;

        case 6:
            printf("You selected 'Add a teacher record'\n");
            break;
        case 7:
            printf("You selected 'View all teacher record'\n");
            break;
        case 8:
            printf("You selected 'Search for a teacher record'\n");
            break;
        case 9:
            printf("You selected 'Edit a teacher record'\n");
            break;
        case 10:
            printf("You selected 'Delete a teacher record'\n");
            break;
        case 11:
            printf(" Showing results for 'Routine':\n");
            printf("==============================\n\n");
            printf("          Class 6\n");
            printf("          Class 7\n");
            printf("          Class 8\n");
            printf("          Class 9\n");
            printf("          Class 10\n\n");
            printf("     Choose a Class: (6-10)=> ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 6:
                printf("Class 6 selected.\n\n");
                printClassRoutine();
                break;
            case 7:
                printClass7Routine();
                break;
            case 8:
                printClass8Routine();
                break;
            case 9:
                printf("         1.Science\n");
                printf("         2.Commerce\n");
                printf("         3.Arts\n");

                printf("Which section you want to see?\n         =>");
                scanf("%d",&div);

                switch(div)
                {
             case 1:
                printClass9ScienceRoutine();
                break;
             case 2:
                printClass9CommerceRoutine();
                break;
             case 3:
                printClass9ArtsRoutine();
                }
                break;
            case 10:
                printf("          1.Science\n");
                printf("          2.Commerce\n");
                printf("          3.Arts\n");

                printf("Which section you want to see?\n        =>");
                scanf("%d",&sec);

                switch(sec)
                {
            case 1:
                printClass10ScienceRoutine();
                break;
             case 2:
                printClass10CommerceRoutine();
                break;
             case 3:
                printClass10ArtsRoutine();
                }
                break;
            default:
                printf("Invalid option.\n");
                break;
            }
            break;

        case 0:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid option, please try again.\n");
            break;
        }

    }
    while (option != 12);


    return 0;
}
