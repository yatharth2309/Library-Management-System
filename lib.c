//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//global variables
int totalNumOfBooks = 35;
char title[35][50];
char author[35][50];
int issueNum[35];
int numOfCopies[35];
char username[35][50];
char password[35][50];
int alert = 0;

//to print current system date and time
void printCurrentDateAndTime() {
    //built-in functions from time.h that provide current date and time
    char cur_time[128];
    time_t      t;
    struct tm*  ptm;
    t = time(NULL);
    ptm = localtime(&t);
    strftime(cur_time, 128, "%d-%b-%Y", ptm);
    //printing current system date
    printf("\n\t\t\t\t\t\t\tISSUE DATE : %s\n", cur_time);
    t+=1296000;
    ptm = localtime(&t);
    //printing date after 15 days
    strftime(cur_time, 128, "%d-%b-%Y", ptm);
    printf("\n\t\t\t\t\t\t\tRETURN DATE : %s\n", cur_time);
}

//to open and read an already existing text file
void readTextFile() {
    FILE *fp = fopen("books.txt", "r");      //opening file using file pointer
    int i=0;

    //to read until the pointer reaches the end of file
    while(!feof(fp)) {
        fscanf(fp, "%[^,]%*c",title[i]);     //to read text until a comma(,) is found
        fscanf(fp, "%[^,]%*c",author[i]);
        fscanf(fp, "%d",&issueNum[i]);
        fscanf(fp, "%d",&numOfCopies[i]);
        fgetc(fp);
        i++;
    }
    fclose(fp);                              //closing file
}

//prototype of a function that asks the user to return to the main menu
void returnToMainMenu();

//to change all letters of a string to upper case
void toUppercase(char *str) {
    int i;
    for(i=0;i<=strlen(str);i++) {
        if(str[i]>=97&&str[i]<=122) {
            str[i]=str[i]-32;
        }
   }
}

//to print a header message
void welcomeMessage() {
    printf("\t\t\t\t\t\t\t-----------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t------------                                               ------------");
    printf("\n\t\t\t\t\t\t\t------------           LIBRARY MANAGEMENT SYSTEM           ------------");
    printf("\n\t\t\t\t\t\t\t------------                 B.I.T.S Pilani                ------------");
    printf("\n\t\t\t\t\t\t\t------------                                               ------------");
    printf("\n\t\t\t\t\t\t\t-----------------------------------------------------------------------\n\n\n");
}

void fixedOnScreen() {
    system("clear");                        //C function to clear screen
    welcomeMessage();
}

//to delay the execution of a command
void delay() {
    int j, k;
    for(j=0 ; j<25000 ; j++) {
        for(k=0 ; k<25000 ; k++) {}         //use of empty for loops
    }
}

//to show books that were recently added to the library
void newlyAddedBooks() {
    printf("\n\n\t\t\t\t\t\t\t\t\t\t   NEWLY ADDED BOOKS...\n");
    delay();
    printf("\n\t\t\t\t\t\t\t       BOOK                        AUTHOR                 ISSUE NO.\n");
    delay();
    printf("\n\t\t\t\t\t\t\tThink and Grow Rich             Napoleon Hill               1026");
    delay();
    printf("\n\t\t\t\t\t\t\tThe Warren Buffett Way          Robert G. Hagstrom          1027  ");
    delay();
    printf("\n\t\t\t\t\t\t\tZero to One                     Peter Thiel                 1028 ");
    delay();
    printf("\n\t\t\t\t\t\t\tThe Power of Habit              Charles Duhigg              1029");
    delay();
    printf("\n\t\t\t\t\t\t\tThe Millionaire Fastlane        MJ Demarco                  1030");
    delay();
    printf("\n\t\t\t\t\t\t\tThe 4-hour Work week            Timothy Ferriss             1031");
    delay();
    printf("\n\t\t\t\t\t\t\tMoney master the game           Tony Robbins                1032");
    delay();
    printf("\n\t\t\t\t\t\t\tThe Intelligent Investor        Benjamin Graham             1033");
    delay();
    printf("\n\t\t\t\t\t\t\tRich Dad Poor Dad               Robert T.Kiyosaki           1034\n");
    delay();
}

//to prompt the user again and again until a valid choice is entered
int enterChoice(int upperBound) {
    int choice;
    printf("\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%d", &choice);
    getchar();
    while(choice<1 || choice>upperBound) {
        printf("\n\t\t\t\t\t\t\tINVALID OPTION CHOSEN...\n");
        printf("\n\t\t\t\t\t\t\tEnter valid choice : ");
        scanf("%d", &choice);
    }
    return choice;
}

//prototype of a function that is responsible for registration of a new user
void userRegistration();

//to login using valid credentials once the user is registered
void userLogin() {
    char usern[36];
    char pass[36];
    FILE *member = fopen("members.txt", "r");
    int i=0;
    while(!feof(member)) {
        fscanf(member, "%[^,]%*c",username[i]);             //reading a text file
        fscanf(member, "%[^.]%*c",password[i]);
        fgetc(member);
        i++;
    }
    fclose(member);
    printf("\n\n\t\t\t\t\t\t\t\t\t\t      USER LOGIN\n");
    printf("\n\t\t\t\t\t\t\tEnter username : ");
    scanf("%[^\n]%*c", usern);
    printf("\n\t\t\t\t\t\t\tEnter password : ");
    scanf("%[^\n]%*c", pass);                               //reading a string until the user pressed ENTER button
    int registered = 0;
    int j;
    for(j=0; j<i ; j++) {
        if(!strcmp(usern,username[j]) && !strcmp(pass,password[j])) {               //function to compare two strings
            printf("\n\t\t\t\t\t\t\tLOGIN SUCCESSFUL!!!\n");
            delay();
            delay();
            fixedOnScreen();
            printf("\n\t\t\t\t\t\t\tHELLO %s\n",username[j]);
            printf("\n\t\t\t\t\t\t\tWELCOME TO B.I.T.S PILANI's LIBRARY MANAGEMENT SYSTEM!!!\n");
            delay();
            delay();
            delay();
            newlyAddedBooks();
            registered = 1;
            break;
        }
        else {
            continue;
        }
    }
    if(registered==0) {
        printf("\n\t\t\t\t\t\t\tINVALID CREDENTIALS!!!\n");
        char ch;
        printf("\n\t\t\t\t\t\t\tHave you registered yourself before logging in? (y/n) : ");
        scanf("%c", &ch);
        getchar();
        if(ch=='y' || ch=='Y') {
            printf("\n\n\t\t\t\t\t\t\tThe above entered USERNAME and PASSWORD do not match to the ones which are in our records.\n");
            printf("\n\t\t\t\t\t\t\tPlease enter valid credentials\n");
            userLogin();
        }
        else {
            printf("\n\n\t\t\t\t\t\t\tPlease REGISTER yourself to avail library services.\n\n");
            userRegistration();
        }
    }
}

//to register a new user and add him/her as a member of the library
void userRegistration() {
    char usern[36];
    char pass[36];
    char confpass[36];
    printf("\n\t\t\t\t\t\t\t\t\t\t    USER REGISTRATION\n");
    printf("\n\t\t\t\t\t\t\tSet username : ");
    scanf("%[^\n]%*c", usern);
    do {
        printf("\n\t\t\t\t\t\t\tSet password : ");                   //setting username and password for a new user
        scanf("%[^\n]%*c", pass);
        printf("\n\t\t\t\t\t\t\tConfirm password : ");
        scanf("%[^\n]%*c", confpass);
        if(!strcmp(pass, confpass)) {
            break;
        }
        else {
            printf("\n\t\t\t\t\t\t\tYour passwords do not match.\n");
        }
    }
    while(strcmp(pass,confpass)!=0);
    FILE *member = fopen("members.txt", "a");                         //opening a file to add the names of registered users
    fprintf(member, "%s,%s.\n", usern, pass);
    fclose(member);
    printf("\n\t\t\t\t\t\t\tREGISTRATION SUCCESSFUL!!\n");
    delay();
    printf("\n\t\t\t\t\t\t\tYou can now proceed to LOGIN...\n");
    delay();
    userLogin();
}

//prototype of a function that displays the main menu
void mainMenu();

//to ask the user for his/her credentials before login
void getCredentials() {
    char ch;
    printf("\n\t\t\t\t\t\t\tAre you a new user? (y/n) : ");
    scanf("%c", &ch);
    getchar();
    if(ch=='y' || ch=='Y') {
        printf("\n\n\t\t\t\t\t\t\tPlease REGISTER yourself to avail library services.\n\n");            //a new user must register before login
        userRegistration();                                                                             //a registered user can directly login
    }
    else {
        userLogin();
    }
    printf("\n\n\t\t\t\t\t\t\tPress ENTER to continue to the main menu : ");
    getchar();
    mainMenu();
}










//prototype of a function to issue book
void issueBook();

//to ask the user if he/she wants to issue a book or not
void askToIssue() {
    char ch;
    printf("\n\n\t\t\t\t\t\t\tWould you like to issue the book?(y/n) : ");
    scanf("%c",&ch);
    getchar();
    if(ch=='Y' || ch=='y') {
        issueBook();
    }
    returnToMainMenu();
}

//prototype of a function that orders books that are not available in our library
void vendorManagement();

//to search books from the library using 3 different ways
void bookSearch() {
    printf("\t\t\t\t\t\t\t\t\t\t      SEARCH BOOK\n");
    readTextFile();
    printf("\n\t\t\t\t\t\t\t\t\t\t1. Search book by title.\n");               //search using book title
    printf("\n\t\t\t\t\t\t\t\t\t\t2. Search book by author.\n");              //search using book author
    printf("\n\t\t\t\t\t\t\t\t\t\t3. Search book by issue number.\n\n");      //search using issue number of the book
    int choice = enterChoice(3);
    char bookname[50] ;
    char authorname[50] ;
    int issuenum;
    int available = 0;
    switch(choice) {
        //searching book using title
        case 1 :
            printf("\n\t\t\t\t\t\t\tEnter Book title : ");
            scanf("%[^\n]%*c",bookname);
            int k;
            for(k=0 ; k<totalNumOfBooks ; k++) {
                if(!strcasecmp(bookname,title[k])) {
                    printf("\n\n\t\t\t\t\t\t\tBOOK NAME                \tAUTHOR                   \tISSUE NO.\n");
                    printf("\n\t\t\t\t\t\t\t%-25s\t%-25s\t%d\n", title[k], author[k], issueNum[k]);
                    available = 1;
                    break;
                }
                else {
                    continue;
                }
            }
            if(available==0) {
                toUppercase(bookname);
                printf("\n\t\t\t\t\t\t\t%s is not available in our library",bookname);
                char ch;
                printf("\n\n\t\t\t\t\t\t\tWould you like to get the book from any other vendor or library?(y/n) : ");
                scanf("%c",&ch);
                getchar();
                if(ch=='Y' || ch=='y') {
                    fixedOnScreen();
                    vendorManagement();
                }
                returnToMainMenu();
            }
            else {
                askToIssue();
            }
            break;

        //searching book using author name
        case 2 :
            printf("\n\t\t\t\t\t\t\tEnter Author name : ");
            scanf("%[^\n]%*c",authorname);
            printf("\n\n\t\t\t\t\t\t\tBOOK NAME                \tAUTHOR                   \tISSUE NO.\n");
            int l;
            for(l=0 ; l<totalNumOfBooks ; l++) {
                if(!strcasecmp(authorname,author[l])) {
                    printf("\n\t\t\t\t\t\t\t%-25s\t%-25s\t%d\n", title[l], author[l], issueNum[l]);
                    available++;
                }
                else {
                    continue;
                }
            }
            if(available==0) {
                char none[5] = "NONE";
                printf("\n\t\t\t\t\t\t\t%-25s\t%-25s\t%s\n\n", none, none, none);
                toUppercase(authorname);
                printf("\n\t\t\t\t\t\t\tThere is no book written by %s in our library",authorname);
                char ch;
                printf("\n\n\t\t\t\t\t\t\tWould you like to search other books from our library?(y/n) : ");
                scanf("%c",&ch);
                getchar();
                if(ch=='Y' || ch=='y') {
                    fixedOnScreen();
                    bookSearch();
                }
                else {
                    returnToMainMenu();
                }

            }
            else {
                askToIssue();
            }
            break;

        //searching book using issue number
        case 3 :
            printf("\n\t\t\t\t\t\t\tEnter issue number : ");
            scanf("%d",&issuenum);
            while(issuenum<1000 || issuenum>totalNumOfBooks+999) {
                printf("\n\t\t\t\t\t\t\tINVALID ISSUE NUMBER...\n");
                printf("\n\t\t\t\t\t\t\tEnter valid issue number : ");
                scanf("%d", &issuenum);
            }
            getchar();
            printf("\n\n\t\t\t\t\t\t\tBOOK NAME                \tAUTHOR                   \tISSUE NO.\n");
            int e;
            for(e=0 ; e<totalNumOfBooks ; e++) {
                if(issuenum==issueNum[e]) {
                    printf("\n\t\t\t\t\t\t\t%-25s\t%-25s\t%d\n", title[e], author[e], issueNum[e]);
                    break;
                }
                else {
                    continue;
                }
            }
            askToIssue();
            break;
    }
}

//definition of a function that is used to issue books from the library
void issueBook() {
    printf("\n\n\t\t\t\t\t\t\t\t\t\t       ISSUE BOOK\n");
    int iss;
    printf("\n\t\t\t\t\t\t\tType the issue number of the book you want to checkout : ");
    scanf("%d",&iss);
    while(iss<1000 || iss>totalNumOfBooks+999) {
        printf("\n\t\t\t\t\t\t\tINVALID ISSUE NUMBER...\n");
        printf("\n\t\t\t\t\t\t\tEnter valid issue number : ");
        scanf("%d", &iss);
    }
    getchar();
    int i;
    for(i=0 ; i<totalNumOfBooks ; i++) {
        if(iss==issueNum[i] && numOfCopies[i]>0) {
            printf("\n\t\t\t\t\t\t\t%s has successfully been issued for you.\n", title[i]);
            printf("\n\t\t\t\t\t\t\tPlease return the book after 15 days.\n");                               //notification to return book after 15 days
            printCurrentDateAndTime();                                                                       //issue date and return date is printed
            numOfCopies[i]--;                                                                                //reducing book count in stock once a book is issued
        }
        else if(iss==issueNum[i] && numOfCopies[i]==0) {
            printf("\n\t\t\t\t\t\t\tBOOK NOT AVAILABLE as it has been issued to another user.\n");
            char ch;
            printf("\n\t\t\t\t\t\t\tWould you like to get notified when the book is available?(y/n) : ");    //option to get an alert once a book is returned
            scanf("%c",&ch);
            getchar();
            if(ch=='Y' || ch=='y') {
                printf("\n\t\t\t\t\t\t\tWe will notify when the book is returned.");
                alert=1;
            }
        }
        else {
            continue;
        }
    }
    FILE *fp = fopen("books.txt", "w");
    for(i=0 ; i<totalNumOfBooks ; i++) {
        fprintf(fp, "%s,%s,%d %d\n",title[i],author[i],issueNum[i],numOfCopies[i]);
    }
    fclose(fp);
    returnToMainMenu();
}

//to provide choice of issuing or returning a book
void bookTransaction() {
    printf("\t\t\t\t\t\t\t\t\t\t    BOOK TRANSACTION\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t    1. ISSUE BOOK\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t    2. RETURN BOOK\n\n");
    int choice = enterChoice(2);
    printf("\n\n");
    switch(choice) {
        //to issue a book
        case 1 :
            fixedOnScreen();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t       ISSUE BOOK\n");
            printf("\n\t\t\t\t\t\t\tTo issue a book, you should first search it using the search menu!!\n");        //to issue a book, one has to search it first
            delay();
            printf("\n\t\t\t\t\t\t\tREDIRECTING TO SEARCH MENU");
            int m;
            for(m=0;m<4;m++) {
                delay();
                delay();
                printf(" .");
            }
            printf("\n\n");
            bookSearch();
            break;

        //to return a book
        case 2 :
            fixedOnScreen();
            printf("\n\n\t\t\t\t\t\t\t\t\t\t       RETURN BOOK\n");
            readTextFile();
            char bookName[50];
            printf("\n\t\t\t\t\t\t\tEnter the book title that you want to return : ");
            scanf("%[^\n]%*c", bookName);
            int k;
            for(k=0 ; k<35 ; k++) {
                if(!strcasecmp(bookName,title[k])) {
                    printf("\n\n\t\t\t\t\t\t\tTHANK YOU for returning %s\n",title[k]);
                    printf("\n\t\t\t\t\t\t\tWe hope you had a good time reading it!!!\n");
                    numOfCopies[k]++;                                                               //increasing book count once the issued book is returned
                    if(numOfCopies[k]==1 && alert==1) {
                        delay();
                        delay();
                        printf("\n\n\t\t\t\t\t\t\tALERT!!!!\n");
                        delay();
                        printf("\n\t\t\t\t\t\t\t%s, which was previously issued to a user, is now back in the library.\n\n",title[k]);         //printing an alert
                        alert = 0;
                        delay();
                    }
                    break;
                }
                else {
                    continue;
                }
            }
            FILE *fp = fopen("books.txt", "w");
            for(k=0 ; k<totalNumOfBooks ; k++) {
                fprintf(fp, "%s,%s,%d %d\n",title[k],author[k],issueNum[k],numOfCopies[k]);
            }
            fclose(fp);
            returnToMainMenu();
            break;
    }
}

//definition of a function that is used to order books not available in our library
void vendorManagement() {
    printf("\t\t\t\t\t\t\t\t\t\t   VENDOR MANAGEMENT\n");
    printf("\n\t\t\t\t\t\t\t(Use this menu to get books that are not available in our library)\n");
    printf("\n\t\t\t\t\t\t\t\t\t1. ORDER BOOK to a VENDOR\n");
    printf("\n\t\t\t\t\t\t\t\t\t2. REQUEST BOOK from another LIBRARY\n\n");
    int choice = enterChoice(2);
    printf("\n\n");
    readTextFile();
    char allBooks[50];
    printf("\t\t\t\t\t\t\tEnter book title that you want : ");                           //books that are available in our library need not be ordered
    scanf("%[^\n]%*c",allBooks);
    int k, present = 0;
    for(k=0 ; k<35 ; k++) {
        if(!strcasecmp(allBooks,title[k])) {
            printf("\n\t\t\t\t\t\t\t%s is available in our library\n",title[k]);
            printf("\t\t\t\t\t\t\tYou can issue it from our library\n");
            present = 1;
        }
        else {
            continue;
        }
    }
    if(present==1) {
        returnToMainMenu();
    }
    switch(choice) {
        //selecting a suitable vendor
        case 1 :
        {
            printf("\n\n\t\t\t\t\t\t      LIST OF VENDORS                  DELIVERY TIME                BOOK QUALITY\n\n");
            printf("\n\t\t\t\t\t\t    1. ADITYA BOOKS PVT. LTD               3 DAYS                       USED       \n\n");
            printf("\n\t\t\t\t\t\t    2. KAMAL BOOK INTERNATIONAL            5 DAYS                       NEW        \n\n");
            printf("\n\t\t\t\t\t\t    3. ALLIED PUBLISHERS LTD.              2 DAYS                       USED       \n\n");
            printf("\n\t\t\t\t\t\t    4. ASIAN BOOKS PVT. LTD                4 DAYS                       USED       \n\n");
            printf("\n\t\t\t\t\t\t    5. OVERSEAS PRESS LTD                  6 DAYS                       NEW        \n\n");
            int ch;
            printf("\n\n\t\t\t\t\t\t\tSelect vendor : ");
            scanf("%d",&ch);
            getchar();
            printf("\n\t\t\t\t\t\t\tPLACING ORDER");
            int m;
            for(m=0;m<4;m++) {
                delay();
                printf(" .");
            }
            printf("\n\n\t\t\t\t\t\t\tORDER PLACED!!");
            delay();
            switch(ch) {
                case 1 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 3 WORKING DAYS by ADITYA BOOKS PVT. LTD\n", allBooks);
                    break;
                case 2 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 5 WORKING DAYS by KAMAL BOOK INTERNATIONAL\n",allBooks);
                    break;
                case 3 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 2 WORKING DAYS by ALLIED PUBLISHERS LTD\n",allBooks);
                    break;
                case 4 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 4 WORKING DAYS by ASIAN BOOKS PVT. LTD\n",allBooks);
                    break;
                case 5 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 6 WORKING DAYS by OVERSEAS PRESS LTD\n",allBooks);
                    break;
            }
        break;
        }

        //selecting a suitable library
        case 2 :
        {

            printf("\n\n\t\t\t\t\t\t\t\t   LIBRARIES NEAR US                 DELIVERY TIME\n\n");
            printf("\n\t\t\t\t\t\t\t\t     1. BITS GOA                        3 DAYS    \n\n");
            printf("\n\t\t\t\t\t\t\t\t     2. BITS HYD                        5 DAYS    \n\n");
            printf("\n\t\t\t\t\t\t\t\t     3. IIT DELHI                       2 DAYS    \n\n");
            printf("\n\t\t\t\t\t\t\t\t     4. IIT BOMBAY                      4 DAYS    \n\n");
            printf("\n\t\t\t\t\t\t\t\t     5. MANIPAL JAIPUR                  6 DAYS    \n\n");
            int ch;
            printf("\n\n\t\t\t\t\t\t\tSelect library : ");
            scanf("%d",&ch);
            getchar();
            printf("\n\t\t\t\t\t\t\tREQUESTING BOOK");
            int m;
            for(m=0;m<4;m++) {
                delay();
                printf(" .");
            }
            printf("\n\n\t\t\t\t\t\t\tREQUEST ACCEPTED!!");
            delay();
            switch(ch) {
                case 1 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 3 WORKING DAYS by BITS GOA LIBRARY\n",allBooks);
                    break;
                case 2 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 5 WORKING DAYS by BITS HYDERABAD LIBRARY\n",allBooks);
                    break;
                case 3 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 2 WORKING DAYS by IIT DELHI LIBRARY\n",allBooks);
                    break;
                case 4 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 4 WORKING DAYS by IIT BOMBAY LIBRARY\n",allBooks);
                    break;
                case 5 :
                    printf("\n\n\t\t\t\t\t\t\t%s will be delivered within 6 WORKING DAYS by MANIPAL JAIPUR LIBRARY\n",allBooks);
                    break;
            }
            break;
        }
    }
    returnToMainMenu();
}

//to count the stock of books in our library
void inventoryManagement() {
    printf("\t\t\t\t\t\t\t\t\t\t  INVENTORY MANAGEMENT\n");
    readTextFile();
    char allBooks[50];
    printf("\n\t\t\t\t\t\t\tEnter book title whose count you want to know : ");
    scanf("%[^\n]%*c",allBooks);
    int available = 0;
    int k;
    for(k=0 ; k<35 ; k++) {
        if(!strcasecmp(allBooks,title[k])) {
            printf("\n\t\t\t\t\t\t\t%d copies available\n",numOfCopies[k]);
            available = 1;
            break;
        }
        else {
            continue;
        }
    }
    if(available==0) {
        printf("\n\t\t\t\t\t\t\tBOOK NOT AVAILABLE IN OUR LIBRARY\n");
    }
    returnToMainMenu();
}

//to delete members from the library
void userManagement() {
    printf("\t\t\t\t\t\t\t\t\t\t DELETE REGISTERED USER\n");
    int regcnt=0;
    char usern[36];
    char pass[36];
    int deluser = 0;
    int lastuser = 0;
    FILE *fp = fopen("members.txt", "r");

    while(!feof(fp)) {
        fscanf(fp, "%[^,]%*c",username[regcnt]);
        fscanf(fp, "%[^.]%*c",password[regcnt]);
        fgetc(fp);
        regcnt++;
    }
    fclose(fp);
    printf("\n\t\t\t\t\t\t\tType the username of the account you want to delete : ");
    scanf("%[^\n]%*c", usern);
    printf("\n\t\t\t\t\t\t\tPassword : ");
    scanf("%[^\n]%*c", pass);

    int i;
    for(i=0 ; i<=regcnt-1 ; i++) {
        if(!strcmp(usern,username[i]) && !strcmp(pass,password[i])) {
            if(i==regcnt-1) {lastuser=1;}
            printf("\n\n\t\t\t\t\t\t\t%s is no longer a registered user of our library.\n", username[i]);
            strcpy(username[i],"deleted user");
            strcpy(password[i],"deleted password");
            deluser = 1;
            break;
        }
        else {
            continue;
        }
    }
    if(deluser==1) {
        FILE *fptr = fopen("members.txt", "w");
        int k;
        for(k=0 ; k<=regcnt-1 ; k++) {
            if(k==regcnt-1) {
                fprintf(fptr, "%s,%s.\n",username[k],password[k]);
            }
            else {
                fprintf(fptr, "%s,%s.\n",username[k],password[k]);
            }
        }
        fclose(fp);
    }
    else {
        printf("\n\n\t\t\t\t\t\t\tNO SUCH USER FOUND!!!\n");
    }
    if(lastuser==1) {
        regcnt = 0;
        FILE *fp = fopen("members.txt", "r");
        while(!feof(fp)) {
            fscanf(fp, "%[^,]%*c",username[regcnt]);
            fscanf(fp, "%[^.]%*c",password[regcnt]);
            fgetc(fp);
            regcnt++;
        }
        fclose(fp);

        FILE *fptr = fopen("members.txt", "w");
        int k;
        for(k=0 ; k<=regcnt-2 ; k++) {
            if(k==regcnt-2) {
                fprintf(fptr, "%s,%s.\n",username[k],password[k]);
            }
            else {
                fprintf(fptr, "%s,%s.\n",username[k],password[k]);
            }
        }
        fclose(fp);
    }
    returnToMainMenu();
}

//to delete request for book reservation
void deleteBookReservation() {
    printf("\t\t\t\t\t\t\t\t\t\tDELETE BOOK RESERVATION\n");
    printf("\n\t\t\t\t\t\t\t  (If you proceed, you will not be able to reserve any book)\n");
    char ch;
    printf("\n\t\t\t\t\t\t\tWould you like to proceed? (y/n) : ");
    scanf("%c",&ch);
    getchar();
    if(ch=='Y' || ch=='y') {
        printf("\n\t\t\t\t\t\t\tALL RESERVATIONS DELETED!!!\n");
        printf("\n\t\t\t\t\t\t\tNow you can never avail the option of BOOK RESERVATION.\n");
        alert = 0;
    }
    returnToMainMenu();
}

//to display available features of the library
void mainMenu() {
    fixedOnScreen();
    printf("\t\t\t\t\t\t\t\t\t\t      MAIN MENU\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 1. SEARCH BOOK\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 2. BOOK TRANSACTION\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 3. VENDOR MANAGEMENT\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 4. INVENTORY MANAGEMENT\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 5. DELETE REGISTERED USER\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 6. DELETE BOOK RESERVATION\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 7. LOG OUT\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t 8. EXIT\n");
    printf("\n");
    int choice = enterChoice(8);
    fixedOnScreen();

    switch(choice) {
        case 1 :
            bookSearch();
            break;
        case 2 :
            bookTransaction();
            break;
        case 3 :
            vendorManagement();
            break;
        case 4 :
            inventoryManagement();
            break;
        case 5 :
            userManagement();
            break;
        case 6 :
            deleteBookReservation();
            break;
        case 7 :
            getCredentials();
            break;
        case 8 :
            system("clear");
            exit(0);
    }
}

//definition of a function that helps the user to return back to the main menu
void returnToMainMenu() {
    printf("\n\n\t\t\t\t\t\t\tPress ENTER to return to the main menu : ");
    getchar();
    mainMenu();
}

int main() {
    system("clear");
    welcomeMessage();               //calling the user-defined functions
    getCredentials();
    return 0;
}

