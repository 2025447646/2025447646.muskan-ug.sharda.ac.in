#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    long mobile_no;
    float cgpa;
    char dob[15];
    char course[20];
    int year;
};

void read(struct Student *s);
void display(struct Student s);
int findTopper(struct Student s[], int n);

int main() {
    struct Student s[10];
    int i, topper;

    for(i = 0; i < 10; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        read(&s[i]);
    }

    topper = findTopper(s, 10);

    printf("\n--- Topper of the Class ---\n");
    display(s[topper]);

    return 0;
}

void read(struct Student *s) {
    printf("Name: ");
    scanf(" %[^\n]", s->name);

    printf("Roll No: ");
    scanf("%d", &s->roll_no);

    printf("Mobile No: ");
    scanf("%ld", &s->mobile_no);

    printf("CGPA: ");
    scanf("%f", &s->cgpa);

    printf("Date of Birth: ");
    scanf("%s", s->dob);

    printf("Course: ");
    scanf("%s", s->course);

    printf("Year: ");
    scanf("%d", &s->year);
}

void display(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll_no);
    printf("Mobile No: %ld\n", s.mobile_no);
    printf("CGPA: %.2f\n", s.cgpa);
    printf("DOB: %s\n", s.dob);
    printf("Course: %s\n", s.course);
    printf("Year: %d\n", s.year);
}

int findTopper(struct Student s[], int n) {
    int i, top = 0;
    for(i = 1; i < n; i++) {
        if(s[i].cgpa > s[top].cgpa) {
            top = i;
        }
    }
    return top;
}