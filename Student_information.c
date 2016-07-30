//header file
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

/*
Name    : Md. Mohaymenul Islam (NOYON)
Id      : 133-35-535
Program : SWE
Batch   : 12
*/

//************* Function Prototype **********//
void password(int);
void welcome();
void mainmenu();
void add_info();
int getdata();
int checkid(char*);
void delete_info();
void search_info();
void view_info();
void edit_info();
void exit_fun();
void src_info_byid();
void src_info_byname();
void noyon();
void help_fun();



//gotoxy function
COORD coord = {0,0};
void gotoxy(int x, int y)
{
    coord.X = x;   coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//*******************
//Variyable
char pass[15] = "noyonsprogram";
int i,count_f_exit=1;
int c=15,n=301;  //For line symble
FILE *fp, *ft;
struct information
{
    char id[13];
    char name[25];
    int batch;
    float cgpa;
    char department[25];
}student;


//*************** Main Function **************//&&
int main()
{
    password(1);       //password function calling
    mainmenu();
    //getch();
    return 0;
}


// ***************** Function **************//
void password(int count)
{
    if(count<=5)
    {
        if(count_f_exit<=10)
        {
            system("color 9f");
            char inputpass[15],ch;
            //*********** Body ************//
            gotoxy(36,1);
            printf("NOYON");
            int gotox=9;
            gotoxy(gotox,3);
            for(i=0;i<20;i++)
                printf("%c",c);
            printf(" Password Protected ");
            char password1[15] = "classroll535";
            strcpy(pass+5, password1+11);
            for(i=0;i<20;i++)
                printf("%c",c);
            gotoxy(gotox,17);
            for(i=0;i<60;i++)
                printf("%c",c);
            strncat(pass, "3556565",2);
            //strrev(pass);
            //****************************//
            //strrev(pass);
            gotoxy(18,7);
            printf("Enter Password : ");
            i = 0;
            while(ch != 13)
            {
                ch = getch();
                if(ch != 13 && ch != 8)
                {
                    putch('*');
                    inputpass[i] = ch;
                    i++;

                }
                inputpass[i] = '\0';
            }
            if(strcmp(inputpass,pass) == 0)
            {
                //system("color 9f");
                welcome();
            }
            else
            {
                count++;
                count_f_exit++;
                gotoxy(18,14);
                printf("\aIncorrect Password!");
                gotoxy(18,15);
                printf("Press any key for giving password again...");
                getch();
                system("cls");
                password(count);
            }
        }
        else
        {
            exit_fun();
            exit(0);
        }

    }
    else
    {
        gotoxy(11,6);
        printf("\a\aYou can call to author for password for open this project!!");
        gotoxy(27,8);
        printf("NOYON  -  01681246187");
        gotoxy(18,15);
        printf("Press any key for giving password again...");
        getch();
        system("cls");
        password(4);

    }

}

void welcome()
{
    system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");
    int gotox=9;
    gotoxy(gotox,3);
    for(i=0;i<25;i++)
        printf("%c",c);
    printf(" WELCOME ");
    for(i=0;i<25;i++)
        printf("%c",c);
    gotoxy(gotox,20);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//
    gotoxy(gotox,2);
    printf("Help(H)");
    gotoxy(54,2);
    printf("AboutNoyon(SB)");
    gotoxy(28,9);
    printf("Welcome to my project.");
    gotoxy(20,11);
    printf("Press any key to going to mainmenu...");
    switch(getch())
    {
    case 32:
        noyon();
        break;
    case 104:
        help_fun();
        break;
    case 72:
        help_fun();
        break;
    default:
        mainmenu();
        break;
    }
}
//**************************************************//
void mainmenu()
{
    system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");
    int gotox=9;
    gotoxy(gotox,3);
    for(i=0;i<25;i++)
        printf("%c",c);
    printf(" Mainmenu ");
    for(i=0;i<25;i++)
        printf("%c",c);
    gotoxy(gotox,20);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//
    gotoxy(gotox,2);
    printf("Help(H)");
    gotoxy(55,2);
    printf("AboutNoyon(SB)");
    gotoxy(60,21);
    printf("Exit(Esc)");
    int x=23;
    static int y=5;
    gotoxy(x,y);
    printf("What are you want to do? ");
    gotoxy(14,y+1);
    for(i=0;i<50;i++)
        printf("*");
    gotoxy(x,y+3);
    printf("1 - Add student information");
    gotoxy(x,y+5);
    printf("2 - Delete student information");
    gotoxy(x,y+7);
    printf("3 - Search student information");
    gotoxy(x,y+9);
    printf("4 - View all student information");
    gotoxy(x,y+11);
    printf("5 - Edit student information");
    gotoxy(x,y+13);
    printf("6 - Exit");

    again:
    gotoxy(x,y+16);
    printf("Enter your choice: ");
    //scanf("%d",&choice);

    switch(getch())
    {
    case 49:
        add_info();
        break;
    case 50:
        delete_info();
        break;
    case 51:
        search_info();
        break;
    case 52:
        view_info();
        break;
    case 53:
        edit_info();
        break;
    case 54:
        exit_fun();
        exit(0);
        break;
    case 32:
        noyon();
        break;
    case 104:
        help_fun();
        break;
    case 72:
        help_fun();
        break;
    case 8:
        welcome();
        break;
    case 27:
        exit_fun();
        exit(0);
        break;
    default:
        gotoxy(16,y+18);
        printf("\aWrong input! Press any key for input again .....");
        getch();
        goto again;
        break;
    }


}

//*************
void add_info()
{
    system("cls");
    //*********** Body ************//
    int gotox=9;
    gotoxy(36,1);
    printf("NOYON");
    gotoxy(gotox,3);
    for(i=0;i<18;i++)
        printf("%c",c);
    printf(" Add Student Information ");
    for(i=0;i<18;i++)
        printf("%c",c);
    gotoxy(gotox,22);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//

    int x=23;

    fp = fopen("information.dat", "ab+");
    if(getdata() == 1)
    {
        fseek(fp, 0, SEEK_END);
        fwrite(&student, sizeof(student), 1, fp);
        fclose(fp);
        fflush(fp);
        gotoxy(x-6,18);
        printf("The student information is successfully saved.");

        againinput:
            gotoxy(56,2);
            printf("AboutNoyon(BS)");
            gotoxy(x,20);
            printf("Are there any more student?(y/n) ");
            gotoxy(9,23);
            printf("Back(BackSpace)");
            gotoxy(32,23);
            printf("MainMenu(Enter)");
            gotoxy(59,23);
            printf("Exit(Esc)");

            fflush(stdin);

            switch(getch())
            {
            case 'y':
                add_info();
                break;
            case 'n':
                mainmenu();
                break;
            case 8:
                mainmenu();
                break;
            case 13:
                mainmenu();
                break;
            case 32:
                noyon();
                break;
            case 27:
                exit_fun();
                exit(0);
                break;
            default:
                goto againinput;
                break;
            }
    }

}

int getdata()
{
    int x=23;
    char getid[13];
    again:
        gotoxy(x,5);
        printf("Enter the information below : ");
        gotoxy(x,7);
        printf("Id\t   :  ");
        gets(getid);

        if(checkid(getid) == 0)
        {
            gotoxy(x+27,7);
            printf("\a(Wrong Id. give again..");
            goto again;
        }
        strcpy(student.id, getid);
        fflush(stdin);
        gotoxy(x,9);
        printf("Name\t   :  ");
        gets(student.name);
        gotoxy(x,11);
        printf("Batch\t   :  ");
        scanf("%d",&student.batch);
        gotoxy(x,13);
        printf("cgpa \t   :  ");
        scanf("%f",&student.cgpa);
        gotoxy(x,15);
        printf("Department  :  ");
        scanf("%s",student.department);
        gotoxy(x,17);
        printf("Are you want to save it? (y/n) ");

        if(getch() == 'n')
        {
            add_info();
        }
        return 1;
}

int checkid(char* t)
{
    rewind(fp);
    while(fread(&student, sizeof(student), 1, fp) == 1)
    {

        if(strcmp(student.id, t)==0)
        {
            return 0;
        }

    }

    return 1;

}


void delete_info()
{
    system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");

    int gotox=9,find_info=0;
    gotoxy(gotox,3);
    for(i=0;i<16;i++)
        printf("%c",c);
    printf(" Delete Student Information ");
    for(i=0;i<16;i++)
        printf("%c",c);
    gotoxy(gotox,21);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//
    gotox = 21;
    char getid[13];

    gotoxy(gotox-4,5);
    printf("Enter the student Id to delete?: ");
    gets(getid);
    fp = fopen("information.dat", "rb");
    rewind(fp);
    while(fread(&student, sizeof(student), 1, fp) ==1 )
    {
        if(strcmp(student.id, getid)==0)
        {
            gotoxy(gotox,7);
            printf("The student record is available.");
            gotoxy(gotox,9);
            printf("Name\t\t:  %s", student.name);
            gotoxy(gotox,11);
            printf("Batch\t\t:  %d", student.batch);
            gotoxy(gotox,13);
            printf("cgpa\t\t:  %.2f", student.cgpa);
            gotoxy(gotox,15);
            printf("Department \t:  %s", student.department);
            find_info = 1;
        }

    }

    fflush(fp);
    fflush(stdin);
    if(find_info == 1)
    {
        gotoxy(gotox,17);
        printf("Are you want to delete it? (y/n) ");
        if(getch() == 'y')
        {
            ft = fopen("test.dat", "wb");
            rewind(fp);
            while(fread(&student, sizeof(student), 1, fp) ==1 )
            {
                if(strcmp(student.id, getid) != 0)
                {
                    fseek(ft,0,SEEK_CUR);
                    fwrite(&student, sizeof(student), 1, ft);

                }
            }
            fclose(ft);
            fclose(fp);
            fflush(stdin);
            fflush(ft);
            fflush(fp);
            int a = 1;
            a = remove("information.dat");
            rename("test.dat","information.dat");
            if(a == 0)
            {
                gotoxy(gotox,18);
                printf("The recode is successfully delete. ");

            }

        }

        fflush(stdin);

    }
    else
    {
        gotoxy(gotox,10);
        printf("No record is found.");
        fflush(stdin);
    }
    fflush(stdin);
    gotoxy(55,2);
    printf("AboutNoyon(SB)");
    gotoxy(gotox,19);
    printf("Are you want to delete another? (y/n)");
    gotoxy(9,22);
    printf("Back(BackSpace)");
    gotoxy(32,22);
    printf("MainMenu(Enter)");
    gotoxy(59,22);
    printf("Exit(Esc)");
    xy:
        switch(getch())
        {
        case 'y':
            delete_info();
            break;
        case 'n':
            mainmenu();
            break;
        case 8:
            mainmenu();
            break;
        case 13:
            mainmenu();
            break;
        case 27:
            exit_fun();
            exit(0);
            break;
        case 32:
            noyon();
            break;
        default:
            goto xy;
            break;
        }
        fflush(stdin);
}

void search_info()
{
        system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");

    int gotox=9;
    gotoxy(gotox,3);
    for(i=0;i<16;i++)
        printf("%c",c);
    printf(" Search Student Information ");
    for(i=0;i<16;i++)
        printf("%c",c);
    gotoxy(gotox,21);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//
    gotoxy(54,2);
    printf("AboutNoyon(SB)");
    gotoxy(9,22);
    printf("Back(BackSpace)");
    gotoxy(32,22);
    printf("MainMenu(Enter)");
    gotoxy(60,22);
    printf("Exit(Esc)");
    //*****************************//
    gotox =18;
    fflush(stdin);
    gotoxy(gotox,6);
    printf("You can search student information by :- ");
    gotoxy(gotox,8);
    printf("1 - Search by Id     2 - Search by Name ");
    gotoxy(gotox,10);
    printf("Chose anyone: ");
    fflush(stdin);
    up:
        switch(getch())
        {
        case 49:
            src_info_byid();
            break;
        case 50:
            src_info_byname();
            break;
        case 32:
            noyon();
            break;
        case 13:
            mainmenu();
            break;
        case 27:
            exit_fun();
            exit(0);
            break;
        case 8:
            mainmenu();
            break;
        default:
            goto up;
            break;
        }
    fflush(stdin);

}

void src_info_byid()
{
    system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");

    int gotox=9;
    gotoxy(gotox,3);
    for(i=0;i<16;i++)
        printf("%c",c);
    printf(" Search Information By Id ");
    for(i=0;i<17;i++)
        printf("%c",c);
    gotoxy(gotox,21);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//
    gotox = 21;
    char get_id[13];
    int find_info=0;
    gotoxy(gotox-3,5);
    printf("Enter the student Id : ");
    gets(get_id);
    fp = fopen("information.dat", "rb");
    rewind(fp);
    while(fread(&student, sizeof(student), 1, fp) ==1 )
    {
        if(strcmp(student.id, get_id)==0)
        {
            gotoxy(gotox,7);
            printf("The student information is available.");
            gotoxy(gotox,9);
            printf("Id \t:  %s",student.id);
            gotoxy(gotox,11);
            printf("Name\t:  %s", student.name);
            gotoxy(gotox,13);
            printf("Batch\t:  %d", student.batch);
            gotoxy(gotox,15);
            printf("cgpa \t:  %.2f", student.cgpa);
            gotoxy(gotox,17);
            printf("Department\t:  %s", student.department);
            find_info = 1;

        }
        fflush(stdin);
    }
    fflush(stdin);
    if(find_info == 0)
    {
        gotoxy(gotox,10);
        printf("No record found.");
    }
    x:
        gotoxy(54,2);
        printf("AboutNoyon(SB)");
        gotoxy(gotox,20);
        printf("Do you want to another search? (y/n) ");
        gotoxy(9,22);
        printf("Back(BackSpace)");
        gotoxy(32,22);
        printf("MainMenu(Enter)");
        gotoxy(59,22);
        printf("Exit(Esc)");
        switch(getch())
        {
        case 'y':
            src_info_byid();
            break;
        case 'n':
            mainmenu();
            break;
        case 8:
            search_info();
            break;
        case 13:
            mainmenu();
            break;
        case 27:
            exit_fun();
            exit(0);
            break;
        case 32:
            noyon();
            break;
        default:
            goto x;
            break;
        }

}

void src_info_byname()
{
    system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");

    int gotox=9;
    gotoxy(gotox,3);
    for(i=0;i<16;i++)
        printf("%c",c);
    printf(" Search Information By Name ");
    for(i=0;i<16;i++)
        printf("%c",c);
    gotoxy(gotox,21);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//
    gotox = 19;
    char get_name[15];
    int find_n = 0;
    gotoxy(gotox-3,5);
    printf("Enter the student name : ");
    gets(get_name);
    fp = fopen("information.dat", "rb");
    rewind(fp);
    while(fread(&student, sizeof(student), 1, fp) == 1)
    {
        if(strcmp(student.name, get_name) == 0)
        {
            gotoxy(21,7);
            printf("The student information is available.");
            gotoxy(21,9);
            printf("Id \t:  %s",student.id);
            gotoxy(21,11);
            printf("Name\t:  %s",student.name);
            gotoxy(21,13);
            printf("Batch\t:  %d",student.batch);
            gotoxy(21,15);
            printf("cgpa \t:  %.2f",student.cgpa);
            gotoxy(21,17);
            printf("Department\t:  %s",student.department);
            find_n = 1;
        }
        fflush(stdin);
    }
    fflush(fp);
    fflush(stdin);
    if(find_n == 0)
    {
        gotoxy(21,10);
        printf("No record found.");
    }
    x:
        gotoxy(55,2);
        printf("AboutNoyon(SB)");
        gotoxy(21,19);
        printf("Do you want to search another?: (y/n)");
        gotoxy(9,22);
        printf("Back(BackSpace)");
        gotoxy(32,22);
        printf("MainMenu(Enter)");
        gotoxy(59,22);
        printf("Exit(Esc)");

        switch(getch())
        {
        case 'y':
            src_info_byname();
            break;
        case 'n':
            mainmenu();
            break;
        case 8:
            search_info();
            break;
        case 13:
            mainmenu();
            break;
        case 27:
            exit_fun();
            exit(0);
            break;
        case 116:
            noyon();
            break;
        default:
            goto x;
            break;

        }

}

void view_info()
{
    system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");

    int gotox=3;
    gotoxy(gotox,3);
    for(i=0;i<21;i++)
        printf("%c",c);
    printf(" View Student Information List ");
    for(i=0;i<21;i++)
        printf("%c",c);

    //****************************//
    int y=7;
    gotoxy(gotox,y-3);
    for(i=0;i<73;i++)
        printf("-");
    gotoxy(gotox,y-2);
    printf("ID\t\t  Name\t\t \t      Batch \t Cgpa \t Department");
    gotoxy(gotox,y-1);
    for(i=0;i<73;i++)
        printf("-");
    //**************************//
    int total=0;

    fp = fopen("information.dat", "rb");
    while(fread(&student, sizeof(student), 1, fp) == 1)
    {
        gotoxy(gotox,y);
        printf("%s", student.id);
        gotoxy(gotox+15,y);
        printf("%s",student.name);
        gotoxy(gotox+43,y);
        printf("%d",student.batch);
        gotoxy(gotox+54,y);
        printf("%.2f",student.cgpa);
        gotoxy(gotox+62,y);
        printf("%s",student.department);
        y++;
        total++;
    }
    fclose(fp);
    fflush(fp);
    gotoxy(gotox,y+10);
    for(i=0;i<73;i++)
        printf("%c",c);

    fflush(stdin);
    gotoxy(62,2);
    printf("AboutNoyon(SB)");
    gotoxy(3,y+11);
    printf("Back(BackSpace)");
    gotoxy(35,y+11);
    printf("MainMenu(Enter)");
    gotoxy(67,y+11);
    printf("Exit(Esc)");
    gotoxy(gotox,y+4);
    printf("Total Student = %d ",total);
    enteragain:
        switch(getch())
        {
        case 8:
            mainmenu();
            break;
        case 13:
            mainmenu();
            break;
        case 27:
            exit_fun();
            exit(0);
            break;
        case 32:
            noyon();
            break;
        default:
            gotoxy(29,y+9);
            printf("\aWrong input! Enter again ...");
            goto enteragain;
            break;
        }
}


void edit_info()
{
        system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");
    int gotox=5;
    gotoxy(gotox,3);
    for(i=0;i<21;i++)
        printf("*");
    printf(" Edit Student Information ");
    for(i=0;i<21;i++)
        printf("*");
    gotoxy(gotox,21);
    for(i=0;i<68;i++)
        printf("*");
    //****************************//

    int x,c=0,i;
    char t[13];
    gotoxy(18,5);
    printf("Enter the student id for editing: ");
    gets(t);
    fp = fopen("information.dat", "rb+");
    rewind(fp);
    while(fread(&student, sizeof(student), 1, fp)==1)
    {
        if(checkid(t)==0)
        {
            gotoxy(gotox,7);
            printf("The student record is available.");
            gotoxy(gotox,9);
            printf("Name \t: %s",student.name);
            gotoxy(gotox,11);
            printf("Batch \t: %d",student.batch);
            gotoxy(gotox,13);
            printf("Cgpa  \t: %.2f",student.cgpa);
            gotoxy(gotox,15);
            printf("Department : %s",student.department);
            gotoxy(gotox,17);
            printf("Are you want to edit it?(y/n)");
            fflush(stdin);
            int y=7;
            switch(getch())
            {
            case 'y':
                for(i=0;i<11;i++)
                {
                    gotoxy(38,y);
                    printf("|");
                    y++;
                }
                goto next;
                break;
            default:
                mainmenu();
                break;
            }
            next:
                x = 41;
                gotoxy(x,7);
                printf("Your Id   :  %s", student.id);
                gotoxy(x,9);
                printf("New Name  :  ");    gets(student.name);
                gotoxy(x,11);
                printf("New Batch :  ");  scanf("%d", &student.batch);
                gotoxy(x,13);
                printf("New Cgpa  :  ");  scanf("%f", &student.cgpa);
                gotoxy(x,15);
                printf("New Department :  ");  scanf("%s",student.department);
                gotoxy(x,17);
                printf("Are you want to save it?(y/n) ");
                switch(getch())
                {
                case 'n':
                    mainmenu();
                    break;
                default:
                    goto next_stape;
                    break;
                }
                next_stape:
                gotoxy(27,19);
                printf("The record modified.");
                fseek(fp,ftell(fp)-sizeof(student),0);
                fwrite(&student, sizeof(student), 1, fp);
                fclose(fp);
                fflush(fp);
                c++;
                fflush(stdin);
        }
        else
        {
            gotoxy(20,10);
            printf("No record found.");
        }
    }
    fflush(stdin);
    up:
        gotoxy(59,2);
        printf("AboutNoyon(SB)");
        gotoxy(22,20);
        printf("Are you want to another edit?(y/n)");
        gotoxy(5,22);
        printf("Back(BackSpace)");
        gotoxy(32,22);
        printf("MainMenu(Enter)");
        gotoxy(63,22);
        printf("Exit(Esc)");

        switch(getch())
        {
        case 'y':
            edit_info();
            break;
        case 'n':
            mainmenu();
            break;
        case 8:
            mainmenu();
            break;
        case 13:
            mainmenu();
            break;
        case 27:
            exit_fun();
            exit(0);
            break;
        case 32:
            noyon();
            break;
        default:
            goto up;
            break;
        }
}


void exit_fun()
{
    system("cls");
    gotoxy(32,11);
    printf("Thank You!!!");

    getch();
    gotoxy(0,0);
}

void noyon()
{
    system("cls");
    //textcolor(green);

    int x =22;
    gotoxy(x,5);
    printf("Md. Mohaymenul Islam (NOYON)");
    gotoxy(x,7);
    printf("Id \t : 133-35-535");
    gotoxy(x,9);
    printf("Batch \t : 12");
    gotoxy(x,11);
    printf("Department : SWE");
    gotoxy(x,13);
    printf("Mobile \t : 01681-246187");
    gotoxy(x,15);
    printf("HomeTown   : Rajshahi");
    if(getch())
        mainmenu();

}

void help_fun()
{
     system("cls");
    //*********** Body ************//
    gotoxy(36,1);
    printf("NOYON");
    int gotox=9;
    gotoxy(gotox,3);
    for(i=0;i<25;i++)
        printf("%c",c);
    printf(" Help Center ");
    for(i=0;i<25;i++)
        printf("%c",c);
    gotoxy(gotox,20);
    for(i=0;i<60;i++)
        printf("%c",c);
    //****************************//
    gotoxy(34,5);
    printf("About Program");


    getch();
    mainmenu();
}
