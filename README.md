# Library-Management-System
A lightweight Library Management System built using C.

Instructions for running the code and observing the output :

				   ***** It is recommended to run the program on a LINUX machine from terminal ***** 

                 ***** Please run the program in fullscreen for best experience *****
      
1. The soure code is written in lib.c . It is a menu driven program. At the end of each function, you will be prompted to go back to the main menu.

2. Keep lib.c and books.txt in the same directory for smooth functioning of the program.

3. When you run the program on the terminal, it will prompt you to answer whether you are a new member or not. 
   Enter y/n for yes or no respectively. If you haven't registered before, please enter y.

4. You can login with the registered username and password if you enter n, or you can register by entering y
   and then login using the credentials.
   (You can check the registered accounts in the members.txt file. We request that you do not change any text files 
    for proper functioning of the program. If the file is changed, please start the program after clearing the members.txt file.)

5. Main Menu with new books will be displayed to you. 
   
   Here you will be given 8 choices :  1. SEARCH BOOK

                                       2. BOOK TRANSACTION

                                       3. VENDOR MANAGEMENT

                                       4. INVENTORY MANAGEMENT

                                       5. DELETE REGISTERED USER

                                       6. DELETE BOOK RESERVATION
                           
                                       7. LOG OUT

                                       8. EXIT

   
   At the end of each function, you will be prompted to go back to the main menu.

6. If you enter 1, the search menu will open.
   The program will prompt you to enter the criterion based on which you want to search the book(title, author and issue number).
   The issue numbers vary from 1000-1034.
   On selecting the desired option, you will be asked to search for the book.
   Since the number of books are limited, we request you to see the available books in the books.txt file.
   The books.txt file will show you the title, author, issue number and available count of the books in the respective order.
   You can search for the available books by entering the desired criterion.
   If a title which is not in books.txt is searched, an option to order it from  a vendor or another library will show up.
   After searching for the book, you will be asked if you want to issue the book/books.
   You can type the issue number of the book you want to issue, if the available count of the book is not 0, it will be issued to you. A reminder of 15 days showing the
   issue date and return date will be printed. 
   If the issue count of the book is 0, "Book not available will be printed", and you will be given a choice to give an alert as soon as the book is returned.

7. If you enter 2, the book transaction menu will open.
   You will be given 2 options, to issue a book or to return a book.
   If you want to issue a book, you will be redirected to the search menu to search for the required book.
   If you want to return a book, you will be asked to enter the title of the book that you want to return.
   On returning, the book count will increase and if the alert option was desired, an alert will be printed that the book is back in the library.
  
8. If you enter 3, the vendor management menu will open.
   You will be asked if you want to order a book from a vendor or another library.
   If the book is present in the library(Either it's available or already issued), you will be asked to issue it from the library itself.
   If the book is not in the books.txt file, you will be given a choice of vendors and libraries showing the name of the organization and time they take to deliver
   a book. After you make a choice, a notification showing the no. of days for delivery will appear and the book will be issued.

9. If you enter 4, the inventory management menu will open.
   You will be prompted to enter the name of the book whose count you want to know.
   After entering the title, you will be shown the number of available copies.

10. If you enter 5, the delete user menu will open.
    You will be asked to enter the registered username and password which you want to delete.
    It is requested that you enter the correct username and password of the users who are registered previously.
    
11. If you enter 6, the delete reservation menu will open.
    You can delete the alert you opted for when the required book was out of stock.

12. If you enter 7, you will be logged out of your account and redirected to the welcome page.

13. If you enter 8, you will exit the program.

14. You can check (at any time) the text files to get information about the accounts and books. Please refrain from editing these files for best functioning.
