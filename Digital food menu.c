/*______Header files______*/

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<tchar.h>


/*____Function declaration____*/
void startingmenu(void);
void mainmenu(void);

void adminmn(void);
void guest(void);
void about();

void login();
void get_password();

void aboutus();
void aboutdev(void);

void addrec(void);
void searchrec(void);
void viewinfo(void);
void deleterec(void);

void vegetarian(void);
void nonvegetarian(void);

int checkid(int);
void endoder(void);
void details(void);

/*____Structural work____*/
struct employ
{
    int id;
    char name[100];
    long unsigned int phone;
    char email[100];
    int YOJ;
    int dd;
    int mm;
    int yyyy;
    float salary;


} emp;

//struct employee e;

FILE *rec, *temp,*vmenu,*nvmenu,*fp,*ft,*dp,*dt;;

int s;
char findrecord;
int again;
int quantity;
int t;
double total=0;

//void startingmenu(void);

/*------- Console Management Function -------*/
void SetColor(int ForgC);
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground();
void window();
void print_heading(const char title[]);
void clearWindow();


/*____Main Function ____*/

int main()
{
    //startingmenu();
    //SetColor(28);
    SetConsoleTitle(_T("DIGITAL FOOD MENU"));
    ClearConsoleToColors(15,15);
    startingmenu();
    return 0;
}

void startingmenu()
{
    SetColor(10);
    printf("\n\n\n\n\n");
    printf("   **************************************************************************************************************\n");
    SetColor(17);
    printf("  ***************************** ");
    print_heading("WELCOME TO THE DIGITAL MENU SYSTEM");
    SetColor(17);
    printf(" ***********************************************\n");
    SetColor(10);
    printf("   **************************************************************************************************************\n\n");
    SetColor(8);
    printf("\t\t\t\t    Press any key to continue");
    if (getch())
        mainmenu();
}

/*____Function Definition____*/
void mainmenu()
{
    SetColor(10);
    int choicemainmenu;
    system("cls");
    printf("\t\t\t **************************************************************************\n");
    printf("\t\t\t\t\t\t ");
    print_heading("WELCOME TO JACKS KITCHEN");
    printf("\n");
    SetColor(10);
    printf("\t\t\t **************************************************************************\n\n\n");
    SetColor(17);
    printf("\t 1. ADMINISTRATION SECTION--> \n\n\t 2. GUEST SECTION--> \n\n\t 3. ABOUT US --> \n\n\t 4. Exit--> \n\n\n\t");
    SetColor(8);
    printf(" Enter Your Choice ---> ");
    scanf("%d",&choicemainmenu);
    switch(choicemainmenu)
    {
    case 1:
        login();
        break;
    case 2:
        guest();
        break;
    case 3:
        about();
        break;
    case 4:
    {
        system("cls");
        printf("\n\n\n");
        printf(" \t\t*******************************THANK YOU**************************************\n");

        printf(" \t\t*************Feeling HUNGRY ? Call or Walk-In JACKS KITCHEN*******************\n\n");
        exit(0);
    };
    break;
    default:
    {
        printf("\n\n \t\t\t\t\t\t   !!!INPUT ERROR!!!\n\t\t\t\t PRESS ANY KEY TO CONTINUE (ENTER FROM THE OPTION ABOVE)");
        if(_getch())
            mainmenu();
    }
    }
}

void login()
{
    system("cls");
    SetColor(10);
    printf("   **************************************************************************************************************\n  ************************************* WELCOME TO THE LOGIN PANEL ***********************************************\n   **************************************************************************************************************\n\n");
    int username;
    printf("\n\n\t\t\t\t   The Admin-section is password protected.");
    printf("\n\t\t\t\t   Enter valid administrator password.");
    SetColor(17);
    printf("\n\n\n\t\t\t\tUSERNAME:- Administrator");

    printf("\n\t\t\t\tPASSWORD:- ");
    get_password();
}

void get_password()
{
    char password[16];
    fflush(stdin);
    gets(password);
    char realpassword[16] ="12345";
    int i=0;
    while(1)
    {
        if ( strcmp(password,realpassword)==0 )
        {
            system("cls");
            adminmn();
        }
        else
        {
            system("cls");
            printf("\n\n\n\t\t\tInvalid Password. Try again with valid password.\n");
            if(_getch())
                login();
        }
    }
}

void adminmn()
{
    SetColor(10);
    int choiceadmin;
    system("cls");
    printf("   **************************************************************************************************************\n  *************************************");
    print_heading(" WELCOME TO THE ADMIN PANEL ");
    SetColor(10);
    printf("***********************************************\n   **************************************************************************************************************\n\n");
    printf("\t1. Add New Record\n\n\t2. Search Record\n\n\t3. Delete Record\n\n\t4. View previous orders placed\n\n\t5. Back To Main Menu\n\n");
    SetColor(8);
    printf("\tEnter Your Choice ---> ");
    scanf("%d",&choiceadmin);
    switch(choiceadmin)
    {
    case 1:
        addrec();
        break;
    case 2:
        searchrec();
        break;
    case 3:
        deleterec();
        break;
    case 4:
    {
        SetColor(10);
        system("cls");
        FILE *view;
        char viw;
        view = fopen("order.txt","rt");
        while((viw=fgetc(view))!=EOF)
        {
            printf("%c",viw);
        }
        fclose(view);
        printf("\n\n\n\nPRESS ANY KEY TO CONTINUE...............");
        if(getch())
        {
            adminmn();
        }

        break;
        case 5:
            mainmenu();
            break;
        default:
        {
            printf("\n\n \t\t\t\t\t\t   !!!INPUT ERROR!!!\n\t\t\t\t PRESS ANY KEY TO CONTINUE (ENTER FROM THE OPTION ABOVE)");
            if(getch())
                adminmn();
        }
    }
    }
}
void addrec()
{
    system("cls");
    fseek(rec,0,SEEK_END);
    rec=fopen("record.txt","ab+");
    if(rec == NULL)
    {
        SetColor(12);
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);
    }
    else
    {
        SetColor(10);
        printf("   **************************************************************************************************************\n  *************************************");
        print_heading(" WELCOME TO THE ADDRECORD PANEL ");
        SetColor(10);
        printf("*******************************************\n   **************************************************************************************************************\n\n");
        int t;
        printf("\t\tEmployee ID :\t");
        fflush(stdin);
        scanf("%d",&t);
        if(checkid(t)==1)
        {
            printf("\n\n");
            SetColor(12);
            printf("\a                        !!!The Employee Record Already Exists !!!(Try Again ? (y/n))\a");
            while(getchar() != '\n');
            if(getch()=='y')
                addrec();
            else
                adminmn();
        }
        else
        {
            emp.id=t;
            while(getchar() != '\n');
            printf("\n\n\nENTER THE NAME: ");
            scanf("%s",&emp.name);
            while(getchar() != '\n');
            printf("\nENTER THE PHONE: ");
            scanf("%ld",&emp.phone);
            while(getchar() != '\n');
            printf("\nENTER THE EMAIL: ");
            scanf("%s",&emp.email);
            while(getchar() != '\n');
            printf("\nENTER THE YEAR OF JOINING:");
            scanf("%d",&emp.YOJ);
            while(getchar() != '\n');
            printf("\nENTER THE DATE/MONTH/YEAR:");
            scanf("%d/%d/%d",&emp.dd,&emp.mm,&emp.yyyy);
            while(getchar() != '\n');
            printf("\nENTER THE SALARY: ");
            scanf("%f",&emp.salary);
            while(getchar() != '\n');
            fwrite(&emp,sizeof(emp),1,rec);
            printf("\n\n\t\t\tSUCCWSSFULLY ENTERED (PRESS ANYKEY TO GO BACK)");
            fclose(rec);
            if(getch())
            {
                adminmn();
            }
        }
    }
}

void searchrec(void)
{
    SetColor(10);
    system("cls");
    int d;
    rec=fopen("record.txt","rb+");
    rewind(rec);
    system("cls");
    printf("   **************************************************************************************************************\n  *************************************");
    print_heading(" WELCOME TO THE SEARCH RECORD PANEL ");
    SetColor(10);
    printf("***************************************\n   **************************************************************************************************************\n\n");
    printf("\t\t\t Enter The Employee ID : ");
    while(getchar() !='\n');
    scanf(" %d",&d);
    printf("\n\n");
    printf("Searching........");
    while(fread(&emp,sizeof(emp),1,rec)==1)
    {
        if(emp.id==d)
        {
            printf("\n\n");
            printf("...........................The Record is available............................\n\n");
            printf("\t\t Name : %s\n",emp.name);
            printf("\n\t\t phone number : %ld\n",emp.phone);
            printf("\n\t\t EMAIL: %s\n",emp.email);
            printf("\n\t\t Year of joining: %d\n",emp.YOJ);
            printf("\n\t\t Date of birth : %d/%d/%d\n",emp.dd,emp.mm,emp.yyyy);
            printf("\n\t\t Salary : %f\n",emp.salary);

            findrecord='t';
        }

    }
    if(findrecord!='t')
    {
        SetColor(12);
        printf("\n\n\n\a\t\t!!!!!No Record Found!!!!!\a");
    }
    SetColor(8);
    printf("\n\n\t\tTry Another Search ? (y/n)");
    if(getch()=='y')
        searchrec();
    else
        adminmn();
    fclose(rec);
}

void deleterec()
{
    SetColor(10);
    system("cls");
    printf("   **************************************************************************************************************\n  ************************************* WELCOME TO THE DELETE RECORD PANEL ***************************************\n   **************************************************************************************************************\n\n");
    int d,c;
    rec=fopen("record.txt","rb+");
    printf("Enter ID to Delete Information: ");
    while(getchar() != '\n');
    scanf("%d",&d);
    c=d;
    if(checkid(d)==1)
    {
        printf("\n\n");
        printf("                               .....................The Employee Record Is Available....................\n\n");
        printf("               Employee Name Is %s\n\n",emp.name);
        printf("               Employee's Date  OF Birth Is %d/%d/%d\n\n",emp.dd,emp.mm,emp.yyyy);
        findrecord='t';
    }
    if(findrecord=='t' )
    {
        printf("Do You Want To Delete THe Record ? (Y/N) ");
        if(getch()=='y')
        {
            ft=fopen("test1.txt","w");  //temporary file for delete
            rewind(fp);
            while(fread(&emp,sizeof(emp),1,fp)==1)
            {
                if(emp.id!=d)
                {
                    fseek(ft,0,SEEK_CUR);
                    fwrite(&emp,sizeof(emp),1,ft); //write all in tempory file except that
                }                              //we want to delete
            }
            fclose(ft);
            fclose(fp);
            remove("record.txt");
            rename("test1.txt","record.txt"); //copy all item from temporary file to fp except that
            fp=fopen("record.txt","r");
            if(findrecord=='t')
            {
                printf("\n\n        THE RECORD IS SUCCESSFULLY DELETED.\n\n");
            }
            fclose(fp);
        }
    }

    else
    {
        printf("\n\n\n");
        printf("\a\t\t!!!!!NO record found!!!!!\t\t\a");
    }

    printf("\n\n\t\tTry Another Search ? (y/n)");
    if(getch()=='y')
        deleterec();
    else
        adminmn();
}

void guest(void)
{
    int choicegst;
    system("cls");
    printf("\t\t************************************************\n\t\t\t\t    WELCOME\n\t\t************************************************\n\n\n");
    printf("\t   YOU ARE--->\n\n\t\t1. Vegetarian\n\n\t\t\tOR\n\n\t\t2. Non Vegetarian\n\n\t\t\t\n\n\t\t3. Back To Main Menu\n\n\n   Enter Your Choice  --> ");
    scanf("%d",&choicegst);
    switch(choicegst)
    {
    case 1:
        vegetarian();
        break;
    case 2:
        nonvegetarian();
        ;
        break;
    case 3:
        mainmenu();
        break;
    default:
    {
        printf("\n\n \t\t\t\t\t\t   !!!INPUT ERROR!!!\n\t\t\t\t PRESS ANY KEY TO CONTINUE (ENTER FROM THE OPTION ABOVE)");
        if(getch());
        guest();
    }
    }

}

void vegetarian(void)
{
    system("cls");
    int choice;
    int again;
    int quantity;

    double price=0;

    printf("                    ****************************************\n                                  VEGETARIAN MENU\n                    ****************************************\n\n");
    char v;
    FILE *vmenu;

    vmenu=fopen("vegmenu.txt","rt");
    while((v=getc(vmenu))!=EOF)
    {
        printf("%c",v);
    }
    fclose(vmenu);
    printf("\n\nEnter What You Want : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Quantity :  ");
        scanf("%d",&quantity);
        total=total + 40*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        printf("\n");
        if(again==1)
        {
            printf("\n\n");
            vegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==2)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 60*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
            vegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==3)
    {
        printf("Quantity :  ");
        scanf("%d",&quantity);
        total=total + 45*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
            vegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==4)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 35*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
            vegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }
    }
    else if(choice==5)
    {
        printf("Quantity :");
        scanf("%d",&quantity);
        total=total + 150*(quantity);
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf("%d",&again);
        if(again==1)
        {
            printf("\n\n");
            vegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);

            details();
        }

    }
    else if(choice==6)
    {

    }
    else
    {
        printf("\n\n \t\t\t\t\t\t   !!!INPUT ERROR!!!\n\t\t\t\t PRESS ANY KEY TO CONTINUE (ENTER FROM THE OPTION ABOVE)");
        if(getch())
            vegetarian();
    }
}
void nonvegetarian(void)
{
    system("cls");
    int choice;
    int again;
    int quantity;
    double price=0;
    SetColor(12);
    printf("                                    **********************************************\n");
    printf("                                                    ");
    print_heading("NON-VEG-MENU");
    printf("\n");
    SetColor(12);
    printf("                                    **********************************************\n");
    char n;
    FILE *nmenu;
    nmenu = fopen("nonveg.txt","rt");
    while((n=getc(nmenu))!=EOF)
    {
        printf("%c",n);
    }
    printf("\n\t5. Back to menu          \n");
    printf("\n\nEnter What You Want : ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Quantity : ");
        scanf(" %d",&quantity);
        total=total + 100*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            nonvegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is :%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==2)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 120*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            nonvegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is :%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==3)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 85*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            nonvegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is :%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==4)
    {
        printf("Quantity :");
        scanf(" %d",&quantity);
        total=total + 35*(quantity);
        printf("\n");
        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
        scanf(" %d",&again);
        if(again==1)
        {
            printf("\n\n");
            nonvegetarian();
        }
        else if(again==2)
        {
            printf("Your Total Amount Is :%.2lf\n\n",total);
            int totl = total;
            FILE *ttl;
            ttl = fopen("order.txt","a");
            fprintf(ttl,"\nGrand Total : %d\n",totl);
            fclose(ttl);
            details();
        }
    }
    else if(choice==5)
    {
        system("cls");
        guest();
    }
    else
    {
        printf("\n\n \t\t\t\t\t\t   !!!INPUT ERROR!!!\n\t\t\t\t PRESS ANY KEY TO CONTINUE (ENTER FROM THE OPTION ABOVE)");
        nonvegetarian();
    }
}
void details(void)
{
    system("cls");
    char name1[20];
    char name2[20];
    long long int phone;
    printf("Please Give Your Contact Details \n");
    printf(" First Name : ");
    scanf("%s",name1);
    printf("Last Name : ");
    scanf("%s",name2);
    printf("Phone : ");
    scanf("%lld",&phone);
    printf("\n\n");
    printf("Your Entered Details Are --->\n");
    FILE *cust;
    cust = fopen("order.txt","a");
    fprintf(cust,"Order Placed By : %s %s\nPhone number : %lld\n",name1,name2,phone);
    fclose(cust);
    printf("    -->First Name :  %s\n    -->Last Name   :  %s\n    -->Phone     :%lld  \n",name1,name2,phone);
    printf("\n\n\n");
    printf("                       *********************************************************************************************\n");
    printf("                                             Your Order Will Be At Your Table In NO TIME .\n");
    printf("                                                       .....HAPPY ORDERING.....\n");
    printf("                       *********************************************************************************************\n");

    printf("Press Any To The MainMenu.");
    if(getch());
    mainmenu();
}

void endoder(void)
{
    printf("\n");
    printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
    scanf(" %d",&again);
    if(again==1)
    {
        printf("\n\n");
        vegetarian();
    }
    else if(again==2)
    {
        printf("Your Total Amount Is :%.2lf\n\n",total);
        int totl = total;
        FILE *ttl;
        ttl = fopen("order.txt","a+");
        fprintf(ttl,"\nGrand Total : %d\n",totl);
        fclose(ttl);
    }
}

void about()
{
    system("cls");
    printf("   **************************************************************************************************************\n  ***********************************************  ABOUT US  *****************************************************\n   **************************************************************************************************************\n\n");
    printf("\n\n\n\t1.ABOUT THE PLACE\n\n");
    printf("\t2.ABOUT THE DEVOLOPERS \n\n");
    printf("\t3.GET BACK TO MAINMENU\n\n\n");
    printf("\t ENTER YOUR CHOICE --> ");
    int choiceabt;
    printf("");
    scanf("%d",&choiceabt);
    switch(choiceabt)
    {
    case 1:
        aboutus();
        break;
    case 2:
        aboutdev();
        break;
    case 3:
        mainmenu();
    default:
    {
        printf("\n\n \t\t\t\t\t\t   !!!INPUT ERROR!!!\n\t\t\t\t PRESS ANY KEY TO CONTINUE (ENTER FROM THE OPTION ABOVE)");
        if(_getch())
            about();
    };
    };
}

void aboutdev()
{

    system("cls");
    printf("                       **************************ABOUT DEVELOPER**************************\n\n");
    printf("   \t\t\t\t\t  -->  MD.MAHFUJUR RAHMAN  <-- \n\n   \t\t\t\t\t     -->  ID:192311014  <-- \n\n\t\t\t\t\t     -->  3rd SEMESTER  <-- \n\n\t\t\t\t      --> Dept. CSE Varendra University <-- \n\n");
    printf("                       *****************************THANK YOU*****************************");
    printf("\n\n");
    printf("    Press Any Key To Go Back.");
    if(_getch())
        about();
}

void aboutus()
{

    system("cls");
    printf(" \t\t********************************** JACKS KITCHEN ********************************\n\n");
    printf(" \t\t\t\t\tPHONE-->017*********\n\n\t\t\t\t\tEMAIL-->arnobr99@gmail.com\n\n\t\t\t\t\tADRESS-->RAJSHAHI,BANGLAADESH\n\n");
    printf("                       *****************************THANK YOU*****************************");
    printf("\n\n");
    printf("    Press Any Key To Go Back .");
    if(_getch())
        about();


}

int checkid(int c)
{
    rewind(rec);
    while(fread(&emp,sizeof(emp),1,rec)==1)
    {
        if(emp.id==c)
        {
            return 1;
        }
    }
    return 0;

}

/*------- Clear Console Color Function (Source: Google) -------*/
void SetColor(int ForgC)
{
    WORD wColor;
    ///We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    ///We use csbi for the wAttributes word.
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        ///Mask out all but the background attribute, and add in the foreground color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    ///Get the handle to the current output buffer...
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ///This is used to reset the carat/cursor to the top left.
    COORD coord = {0, 0};
    ///A return value... indicating how many chars were written
    ///   not used but we need to capture this since it will be
    ///   written anyway (passing NULL causes an access violation).
    DWORD count;
    ///This is a structure containing all of the console info
    /// it is used here to find the size of the console.
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    ///Here we will set the current color
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        ///This fills the buffer with a given character (in this case 32=space).
        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        ///This will set our cursor position for the next print statement.
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void print_heading(const char title[])
{
    SetColor(10);
    SetColorAndBackground(31,28);
    printf("%s",title);
    SetColorAndBackground(17,15);
}
