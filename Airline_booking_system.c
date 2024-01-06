#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book
{
    char code[30];
    char name[30];
    char date[30];
    char desti[30];
} b;

int seat = 60;
void tic_book();
void viewall();
void Booked_tic();
void old_rec();

void main()
{
    int ch;
    do
    {
        printf("\n==================================");
        printf("\n");
        printf("  Airline Ticket booking ");
        printf("\n");
        printf("\n==================================");

        printf("\n 1 Ticket Booking");
        printf("\n 2 View All Ticket");
        printf("\n 3 Booked Ticket");
        printf("\n 4 View All Record");
        printf("\n 0 Exit \n");
        printf("\nEnter your Choice:  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            tic_book();
            break;

        case 2:
            viewall();
            break;

        case 3:
            Booked_tic();
            break;

        case 4:
            old_rec();
            break;

        case 0:
            exit(0);
            break;

        default:
            printf("Wrong choice !");
            break;
        }
    } while (ch != 0);
}

void tic_book()
{
    FILE *fp;
    struct book b;
    printf("Enter ticket code :  ");
    scanf("%s", b.code);
    printf("Enter  passenger name :  ");
    scanf("%s", b.name);
    printf("Enter  Date:  ");
    scanf("%s", b.date);
    printf("Enter your destination :  ");
    scanf("%s", b.desti);

    fp = fopen("data.txt", "a");

    if (fp == NULL)
    {
        printf("FIle not Found");
    }
    else
    {
        fprintf(fp, "%s %s %s  %s\n", b.code, b.name, b.date, b.desti);
        printf("\nCongratulations, Booking successfull\n\n");
        printf("\nYour ticket is:\n\n");
        printf("Name: %s\n", b.name);
        printf("Date: %s\n", b.date);
        printf("destination: %s\n", b.desti);
        printf("Flight Name: Air India\n");
        printf("Seat No.: %s\n", b.code);
    }
    printf("\n");
    fclose(fp);
}

void viewall()
{
    char ch;
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Not found !");
        exit(1);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }
    fclose(fp);
}

void Booked_tic()
{
    struct book b;
    FILE *fp;
    FILE *ufp;
    int total_seat;
    char name[20], phone[20];
    char ch;
    char ticket_code[20];
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("Not found !");
        exit(1);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }
    fclose(fp);
    printf("\n Enter ticket code :");
    scanf("%s", ticket_code);
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("File not found !");
        exit(1);
    }
    else
    {
        while (getc(fp) != EOF)
        {
            fscanf(fp, "%s %s %s ", b.code, b.name, b.date);
            if (strcmp(b.code, ticket_code) == 0)
            {
                printf("\n Record Found\n");
                printf("\n\t\tCode :%s", b.code);
                printf("\n\t\tPassenger name :%s", b.name);
            }
        }
    }
    printf("\n===========================");
    printf("\n");
    printf("\t Passenger Details ");
    printf("\n");
    printf("\n===========================");
    printf("\n Passenger name :");
    scanf("%s", name);
    printf("\n Phone number :");
    scanf("%s", phone);
    printf("\n Total seat :");
    scanf("%d", &total_seat);
    printf("\n===========================");
    printf("\n");
    printf("\t Happy Journey ");
    printf("\n");
    printf("\n===========================");
    printf("\n\t\tname : %s", name);
    printf("\n\t\tphone Number : %s", phone);
    printf("\n\t\tTotal seats : %d", total_seat);
    ufp = fopen("record.txt", "a");
    if (ufp == NULL)
    {
        printf("FIle not Found");
    }
    else
    {
        fprintf(ufp, "%s %d %s \n", phone, total_seat, b.name);
        printf("\n Re-enter in record");
    }
    printf("\n");
    fclose(ufp);
    fclose(fp);
}

void old_rec()
{
    char ch;
    FILE *fp;
    fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        printf("Not found !");
        exit(1);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }
    fclose(fp);
}