//Name: Abdulmalek Aldhafer
//GitHub username : akaldhafer
//Email : Ak_aldhafer@hotmail.com
//System title : Training Course Package Management System 


#include <stdio.h> // Header file for simple functions such as input and output
#include <stdlib.h> // Header file to use files
#include <windows.h> // Header file to use windows functions like cls and pause
#pragma warning (disable: 4996) // To disable warning for using scanf and scanf_s


/**************************************************************************************************/
void logIn();
void SystemMenu();
void EmployeeMenu();  /* Declare all the function*/
void AddCourse();     /*Thus, the function can be called inside other function*/
void ShowCourse();
void ShowbCourse();
void BookCourse();
void UpdatePbook();
void CancelBook();
void ShowPbook();
void InvoiceCheck();
int SearchPID(char Pid[10]);
/****************************************************************************************************/
/*Course details*/
struct CourseDetails {
	char Ccode[10]; /*course code such as TM-3-2*/
	char CcategoryType[30]; /*course category type */
	char Cname[40]; /*course name */
	char CstartDate[10];/*course start date */
	int Cterm; /*course term */
	int Cprice;/*course price per day */
	int CVPrice;/* vegetarian meal price*/
	int CNonVPrice;/*Non vegetarian meal price */
	int CadminPayment;/*Admin charge */
}c;
/*participant details*/
struct participant 
{
	char PID[10];             // participant ID //
	char PName[20];           //participant Name//
	char PNO[20];             // participant phone number //
	char PGender[10];         // participant gender //
	int PTotalPayment;      // participant total payment //
	int PPaidPayment;       // participant paied amount //
	int PDuePayment;        // participant due payement//
	char PCourseCode[10];     // Course code//
	char PCourseN[40];        // course name//
	char PCategoryN[30];      //Category name //
	int PCoursePayment;     //course payment per day //
	int PAdminfee;          //admin fee //
	int PMealV;             //food payment for vegetarian meal //
	int PMealNonV;          //food payment for non-vegetarian  meal //
	int PCourseTerm;          // course term //
	char PStartDate[10];      //start date of the course //
}p;
char checkPID[10];

/*****************************************************************************************************/
/*login function*/
void logIn() {
	char password[5];
	char username[6];
	int loginAttempt = 0;
	system("cls");
	printf("\n##--------------------------------------------------------------##\n");
	printf("\n                      Employee Sign in Page                       \n");
	printf("\n##--------------------------------------------------------------##\n");
	while (loginAttempt < 5)
	{
		printf("\nThe Username is (admin) and The Password is (pass) By Default\n\n");
		printf("\tEnter The Username: ");
		scanf("%s", &username);
		printf("\n\tEnter The Password: ");
		scanf("%s", &password);

		if (strcmp(username, "admin") == 0 && strcmp(password,"pass") == 0) //strcmp is string compare
		{
			printf("\n##           You Have Logged in Successfuly... !        ##\n\n");
			system("pause");
			system("cls");
			EmployeeMenu();
			break;
		}
		else
		{
			printf("\n##         Wrong username or password. Please try again..!!      ##\n\n");
			system("pause");
			system("cls");
			loginAttempt++;
		}
	}
	if (loginAttempt == 5)
	{
		printf("\nToo Many Login Attempts! The Program Will Now Terminate..!!!\n");
		printf("\n\n##==>>       Thanks For Using Our Program       <<==##\n\n");
		system("pause");
		exit(1);
	}
}
/*System menu*/
void SystemMenu() {
	system("cls");
	printf("\n##--------------------------------------------------------------##\n");
	printf("\n            Training Course Package Management System           \n");
	printf("\n##--------------------------------------------------------------##\n\n");
	printf("##1. Sign in.\t2. Exit from the system.        ##\n");      
	printf("\n=>Select One Option: ");
	switch (getche())
	{
	case '1':
		system("cls"); /*clear the screen*/
		logIn(); /*Call login function*/
		break;
	case '2':
		system("cls"); /*clear the screen*/
		printf("\n\n##==>>       Thanks For Using Our Program       <<==##\n\n");
		system("pause"); /*wait the user to press any key*/
		exit(1); // will close the system 
		break;
	default:
		printf("\n## Wrong selection!!, please select new option ##\n\n");
		system("pause"); /*wait the user to press any key*/
		system("cls"); /*clear the screen*/
		SystemMenu(); /*call system menu function*/
		break;
	}
}
/* Employee menu*/
void EmployeeMenu() {
	system("cls");
	printf("\n##------------------------------------------------------------------------##\n");
	printf("\n            Training Course Package Management System           \n");
	printf("\n##------------------------------------------------------------------------##\n\n");
	printf("##1. Add A New Course.           2.Show All Courses.                      ##\n");
	printf("##3. Book Course.                4.Show All Booked Courses.               ##\n");
	printf("##5. Cancel Participant Booking. 6.Show Booked Course of The Participant. ##\n");
	printf("##7. Update Participant Payment. 8.Invoice check         9.Log out.       ##\n");
	printf("\n##=>Select One Option: ");
	switch (getche())
	{
	case '1':
		system("cls"); /*clear the screen*/
		AddCourse(); /*Call add course function*/
		break;
	case '2':
		system("cls"); /*clear the screen*/
		ShowCourse(); /*call show courses function*/
		break;
	case '3':
		system("cls"); /*clear the screen*/
		BookCourse(); /*call book course function*/
		break;
	case '4':
		system("cls"); /*clear the screen*/
		ShowbCourse(); /*call show all booked course function*/
		break;
	case '5':
		system("cls"); /*clear the screen*/
		CancelBook();  /*call cancel booking function*/
		break;
	case '6':
		system("cls"); /*clear the screen*/
		ShowPbook();   /*call show participant booking function*/
		break;
	case '7':
		system("cls"); /*clear the screen*/
		UpdatePbook(); /*call update booking function*/
		break;
	case '8':
		system("cls"); /*clear the screen*/
		InvoiceCheck();
		break;
	case '9':
		system("cls"); /*clear the screen*/
		printf("\n\n##==>>       Thanks For Using Our Program       <<==##\n\n");
		system("pause"); /*wait the user to press any key*/
		system("cls"); /*clear the screen*/
		SystemMenu(); /*call system menu function*/
		break;
	default:
		printf("\n## Wrong selection!!, please select new option ##\n\n");
		system("pause"); /*wait the user to press any key*/
		system("cls"); /*clear the screen*/
		EmployeeMenu(); /*call system menu function*/
		break;
	}
}
/* Function for adding a new course*/
void AddCourse() {
	char choice;
	FILE* ACourse = fopen("Course.txt", "a"); // open the file for adding new course 
	system("cls"); /*clear the screen*/
	do
	{
		printf("\n##------------------------------------------------------------------##\n");
		printf("\n                         Adding a new course          \n");
		printf("\n##------------------------------------------------------------------##\n\n");
		printf("##1. Soft Skills Courses.    2. Computing Skills Courses.           ##\n");
		printf("##3. Back to main menu.                                             ##\n");
		printf("\n##=>Select One Option: ");
		scanf("%s", &choice); // get the user input and read it then store it inide menu variable
		if (choice == '1')
		{
			system("cls");
			do
			{
				printf("\n##------------------------------------------------------------------##\n");
				printf("\n                      Soft Skills Courses           \n");
				printf(__TIME__"---------------------------------------------------"__DATE__);
				printf("\n\n##1. Team Building.            2. Communications.                   ##\n");
				printf("##3. Corporate Career Growth.  4. Conflict Management.              ##\n");
				printf("##5. Back to main menu.                                             ##\n");
				printf("\n##=>Select One Option: ");
				scanf("%s", &choice); // get the user input and read it then store it inide menu variable
				if (choice == '1')
				{
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Soft Skills"); //strcpy: copy the string to new variable 
					strcpy(c.Cname, "Team Building");
					c.Cterm = 3;   // assignning the variables to the course variables
					c.CVPrice = 75;
					c.CNonVPrice = 50;
					c.CadminPayment = 50;;
					c.Cprice = 800;
					fwrite(&c, sizeof(c), 1, ACourse); // write the course details to the file 
					fclose(ACourse); // close file and save the recode
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();	// call add course functoin to restart the function			
				}
				else if (choice == '2')
				{
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Soft Skills");
					strcpy(c.Cname, "Communications");
					c.Cterm = 3;
					c.CVPrice = 50;
					c.CNonVPrice = 25;
					c.CadminPayment = 50;;
					c.Cprice = 650;
					fwrite(&c, sizeof(c), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();
				}
				else if (choice == '3') {
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Soft Skills");
					strcpy(c.Cname, "Corporate Career Growth");
					c.Cterm = 3;
					c.CVPrice = 50;
					c.CNonVPrice = 25;
					c.CadminPayment = 50;;
					c.Cprice = 750;
					fwrite(&c, sizeof(c), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();
				}
				else if (choice == '4') {
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Soft Skills");
					strcpy(c.Cname, "Conflict Management");
					c.Cterm = 3;
					c.CVPrice = 50;
					c.CNonVPrice = 25;
					c.CadminPayment = 50;;
					c.Cprice = 600;
					fwrite(&c, sizeof(c), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();
				}
				else if (choice == '5')
				{
					system("cls");
					AddCourse();
				}
				else
				{
					printf("\n## Wrong selection!!, please select new option ##\n\n");
				}
				system("pause");
				system("cls");
			} while (1);
		}
		else if (choice == '2')
		{	
		    system("cls");
			do
			{
				printf("\n##------------------------------------------------------------------##\n");
				printf("\n                      Computing Skills Courses.         \n");
				printf(__TIME__"---------------------------------------------------"__DATE__);
				printf("\n\n##1.Software Design    2.Web Development                            ##\n");
				printf("##3.Cloud Computing    4.Mobile Content Design and Development      ##\n");
				printf("##5. Back to main menu.                                             ##\n");
				printf("\n##=>Select One Option: ");
				scanf("%s", &choice); // get the user input and read it then store it inide menu variable
				if (choice == '1')
				{
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Computing Skills");
					strcpy(c.Cname, "Software Design");
					c.Cterm = 5;
					c.CVPrice = 50;
					c.CNonVPrice = 25;
					c.CadminPayment = 50;;
					c.Cprice = 1000;
					fwrite(&c, sizeof(c), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();
				}
				else if (choice == '2')
				{
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Computing Skills");
					strcpy(c.Cname, "Web Development");
					c.Cterm = 5;
					c.CVPrice = 75;
					c.CNonVPrice = 50;
					c.CadminPayment = 50;;
					c.Cprice = 1100;
					fwrite(&c, sizeof(c), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();
				}
				else if (choice == '3') {
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Computing Skills");
					strcpy(c.Cname, "Cloud Computing");
					c.Cterm = 3;
					c.CVPrice = 50;
					c.CNonVPrice = 25;
					c.CadminPayment = 50;;
					c.Cprice = 1300;
					fwrite(&c, sizeof(c), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();
				}
				else if (choice == '4') {
					system("cls");
					printf("\nEnter Course Code: ");
					scanf("%s", &c.Ccode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &c.CstartDate);
					strcpy(c.CcategoryType, "Computing Skills");
					strcpy(c.Cname, "Mobile Content Design and Development");
					c.Cterm = 5;
					c.CVPrice = 75;
					c.CNonVPrice = 50;
					c.CadminPayment = 50;;
					c.Cprice = 1200;
					fwrite(&c, sizeof(c), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##         Done adding the new course successfully      ##\n");
					system("pause");
					system("cls");
					AddCourse();
				}
				else if (choice == '5')
				{
					system("cls");
					AddCourse();
				}
				else
				{
					printf("\n## Wrong selection!!, please select new option ##\n\n");
				}
				system("pause");
				system("cls");
			} while (1);
		}
		else if (choice == '3')
		{		
			system("cls");
			EmployeeMenu();
		}
		else
		{
			printf("\n## Wrong selection!!, please select new option ##\n\n");
		}
		system("pause");
		system("cls");
	} while (1);
}
/*Function for showing the created courses*/
void ShowCourse() {
	system("cls"); /*clear the screen*/
	FILE* ShowC = fopen("Course.txt", "r"); /*open the course file for reading*/
	printf("\n###                    These are all the created courses                  ###\n\n");
	while (fread(&c, sizeof(c), 1, ShowC)) { /*while the file is reading, display the course details*/
		printf("\nCourse Code                 : %s", c.Ccode);
		printf("\nCourse Category             : %s", c.CcategoryType);
		printf("\nCourse Name                 : %s", c.Cname);
		printf("\nCourse Start                : %s", c.CstartDate);
		printf("\nCourse Term                 : %d", c.Cterm);
		printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
		printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
		printf("\nCourse Payment per day      : %d", c.Cprice);
		printf("\nCourse Admin fee            : %d", c.CadminPayment);
		printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
	}
	fclose(ShowC);  /*close the file*/
	system("pause"); /*wait the user to press any key*/
	system("cls"); /*clear the screen*/
	EmployeeMenu(); /*call system menu function*/
}
/* This function for displaying all Team Building courses */
void Show1()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##                     The Available Team Building Courses                 ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Team Building") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
			
		}
	}
	fclose(fshow);
}
/* This function for displaying all Communications courses */
void Show2()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##                      The Available Communications Courses               ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Communications") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");	
		}
	}
	fclose(fshow);
}
/* This function for displaying all Corporate Career Growth courses */
void Show3()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##             The Available Corporate Career Growth  Courses              ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Corporate Career Growth") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
			
		}
	}fclose(fshow);
}
/* This function for displaying all Team Building courses */
void Show4()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##                 The Available Conflict Management Courses               ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Conflict Management") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
			
		}
	}
	fclose(fshow);
	
}
/* This function for displaying all Software Design courses */
void Show5()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##                   The Available Software Design Courses                 ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Software Design") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
			
		}
	}
	fclose(fshow);
}
/* This function for displaying all Web Development courses */
void Show6()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##                     The Available Web Development Courses               ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Web Development") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");			
		}	
	}
	fclose(fshow);	
}
/* This function for displaying all Cloud Computing courses */
void Show7()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##                   The Available Cloud Computing Courses                 ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Cloud Computing") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");			
		}	
	}
	fclose(fshow);
}
/* This function for displaying all Mobile Content Design and Development courses */
void Show8()
{
	FILE* fshow = fopen("Course.txt", "r");
	printf("\n##       The Available Mobile Content Design and Development Courses       ##\n\n");
	while (fread(&c, sizeof(c), 1, fshow)) {
		if (strcmp(c.Cname, "Mobile Content Design and Development") == 0) {
			printf("\nCourse Code                 : %s", c.Ccode);
			printf("\nCourse Category             : %s", c.CcategoryType);
			printf("\nCourse Name                 : %s", c.Cname);
			printf("\nCourse Start                : %s", c.CstartDate);
			printf("\nCourse Term                 : %d", c.Cterm);
			printf("\nCourse Meal (vegetarian)    : %d", c.CVPrice);
			printf("\nCourse Meal (Non-vegetarian): %d", c.CNonVPrice);
			printf("\nCourse Payment per day      : %d", c.Cprice);
			printf("\nCourse Admin fee            : %d", c.CadminPayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
			fclose(fshow);
		}		
	}
	fclose(fshow);
}
/*Function for booking a course*/
void BookCourse() {
	char choice;
	FILE* ACourse = fopen("Participant.txt", "a");
	system("cls"); /*clear the screen*/
	do
	{
		printf("\n##------------------------------------------------------------------##\n");
		printf("\n                         Book a course menu          \n");
		printf("\n##------------------------------------------------------------------##\n\n");
		printf("##1. Soft Skills Courses.    2. Computing Skills Courses.           ##\n");
		printf("##3. Back to main menu.                                             ##\n");
		printf("\n##=>Select One Option: ");
		scanf("%s", &choice); // get the user input and read it then store it inide menu variable
		if (choice == '1')
		{
			system("cls");
			do
			{
				printf("\n##------------------------------------------------------------------##\n");
				printf("\n                      Soft Skills Courses           \n");
				printf("\n##------------------------------------------------------------------##\n\n");
				printf("##1. Team Building.            2. Communications.                   ##\n");
				printf("##3. Corporate Career Growth.  4. Conflict Management.              ##\n");
				printf("##5. Back to main menu.                                             ##\n");
				printf("\n##=>Select One Option: ");
				scanf("%s", &choice); // get the user input and read it then store it inide menu variable
				if (choice == '1')
				{
					system("cls");
					Show1();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Soft Skills");
					strcpy(p.PCourseN, "Team Building");
					p.PCourseTerm = 3;
					p.PAdminfee = 50;;
					p.PCoursePayment = 800;
					while (1) {
						printf("\n1. Vegetarian Meal (75RM).\n2. Non-vegetarian Meal (50RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 75;
							p.PTotalPayment = ((p.PCoursePayment+p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 50;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();
				}
				else if (choice == '2')
				{
					system("cls");
					Show2();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Soft Skills");
					strcpy(p.PCourseN, "Communications");
					p.PCourseTerm = 3;
					p.PAdminfee = 50;;
					p.PCoursePayment = 650;
					while (1) {
						printf("\n1. Vegetarian Meal (50RM).\n2.Non-vegetarian Meal (25RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 50;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 25;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();
				}
				else if (choice == '3') {
				    
					system("cls");
					Show3();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Soft Skills");
					strcpy(p.PCourseN, "Corporate Career Growth");
					p.PCourseTerm = 3;
					p.PAdminfee = 50;;
					p.PCoursePayment = 750;
					while (1) {
						printf("\n1. Vegetarian Meal (50RM).\n2.Non-vegetarian Meal (25RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 50;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 25;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();
                }
				else if (choice == '4') {
					system("cls");
					Show4();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Soft Skills");
					strcpy(p.PCourseN, "Conflict Management");
					p.PCourseTerm = 3;
					p.PAdminfee = 50;;
					p.PCoursePayment = 600;
					while (1) {
						printf("\n1. Vegetarian Meal (50RM).\n2.Non-vegetarian Meal (25RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 50;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 25;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();
				}
				else if (choice == '5')
				{
					system("cls");
					AddCourse();
				}
				else
				{
					printf("\n## Wrong selection!!, please select new option ##\n\n");
				}
				system("pause");
				system("cls");
			} while (1);
		}
		else if (choice == '2')
		{
			system("cls");
			do
			{
				printf("\n##------------------------------------------------------------------##\n");
				printf("\n                      Computing Skills Courses.         \n");
				printf("\n##------------------------------------------------------------------##\n\n");
				printf("##1.Software Design    2.Web Development                            ##\n");
				printf("##3.Cloud Computing    4.Mobile Content Design and Development      ##\n");
				printf("##5. Back to main menu.                                             ##\n");
				printf("\n##=>Select One Option: ");
				scanf("%s", &choice); // get the user input and read it then store it inide menu variable
				if (choice == '1')
				{
					system("cls");
					Show5();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Computing Skills");
					strcpy(p.PCourseN, "Software Design");
					p.PCourseTerm = 5;
					p.PAdminfee = 50;;
					p.PCoursePayment = 1000;
					while (1) {
						printf("\n1. Vegetarian Meal (50RM).\n2.Non-vegetarian Meal (25RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 50;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 25;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();					
				}
				else if (choice == '2')
				{
					system("cls");
					Show6();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Computing Skills");
					strcpy(p.PCourseN, "Web Development");
					p.PCourseTerm = 5;
					p.PAdminfee = 50;;
					p.PCoursePayment = 1100;
					while (1) {
						printf("\n1. Vegetarian Meal (75RM).\n2.Non-vegetarian Meal (50RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 75;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 50;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();
				}
				else if (choice == '3') {				    
					system("cls");
					Show7();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Computing Skills");
					strcpy(p.PCourseN, "Cloud Computing");
					p.PCourseTerm = 5;
					p.PAdminfee = 50;;
					p.PCoursePayment = 1300;
					while (1) {
						printf("\n1. Vegetarian Meal (50RM).\n2.Non-vegetarian Meal (25RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 50;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 25;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();
				}
				else if (choice == '4') {
					system("cls");
					Show8();
					printf("\nEnter Course Code: ");
					scanf("%s", &p.PCourseCode);
					printf("\nEnter Start Date(dd/mn/yyyy): ");
					scanf("%s", &p.PStartDate);
					printf("\nEnter Participant ID: "); //get the customer details
					scanf("%s", &p.PID);
					printf("\nEnter Participant Name: ");
					scanf("%s", &p.PName);
					printf("\nEnter Participant Gender: ");
					scanf("%s", &p.PGender);
					printf("\nEnter Participant Phone NO: ");
					scanf("%s", &p.PNO);
					strcpy(p.PCategoryN, "Computing Skills");
					strcpy(p.PCourseN, "Mobile Content Design and Development");
					p.PCourseTerm = 5;
					p.PAdminfee = 50;;
					p.PCoursePayment = 1200;
					while (1) {
						printf("\n1. Vegetarian Meal (75RM).\n2.Non-vegetarian Meal (50RM)\n\n##Enter Your Meal: ");
						scanf("%s", &choice);
						if (choice == '1') {
							p.PMealNonV = 0;
							p.PMealV = 75;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else if (choice == '2') {
							p.PMealNonV = 50;
							p.PMealV = 0;
							p.PTotalPayment = ((p.PCoursePayment + p.PMealV) * p.PCourseTerm) + p.PAdminfee;
							break;
						}
						else {
							printf("\n\n##         Wrong option, please select again       ##\n");
							system("pause");
							system("cls");
						}
					}
					printf("\nThe Total Payment: %d", p.PTotalPayment);
					printf("\nEnter Your Payment: ");
					scanf("%d", &p.PPaidPayment);
					p.PDuePayment = p.PPaidPayment - p.PTotalPayment;
					printf("\nThe Due Payment: %d", p.PDuePayment);
					fwrite(&p, sizeof(p), 1, ACourse);
					fclose(ACourse);
					printf("\n\n##           Done booking a course successfully        ##\n");
					system("pause");
					system("cls");
					BookCourse();
				}
				else if (choice == '5')
				{
					system("cls");
					BookCourse();
				}
				else
				{
					printf("\n## Wrong selection!!, please select new option ##\n\n");
				}
				system("pause");
				system("cls");
			} while (1);
		}
		else if (choice == '3')
		{
			system("cls");
			EmployeeMenu();
		}
		else
		{
			printf("\n## Wrong selection!!, please select new option ##\n\n");
		}
		system("pause");
		system("cls");
	} while (1);
}
/* Function to show all the booked courses and bill details*/
void ShowbCourse() {
	system("cls"); /*clear the screen*/
	FILE* ShowC = fopen("Participant.txt", "r"); /*open the course file for reading*/
	printf("\n###            These are all the Booked courses and bill details          ###\n\n");
	while (fread(&p, sizeof(p), 1, ShowC)) { /*while the file is reading, display the course details*/
		printf("\nParticipant ID              : %s", p.PID);
		printf("\nParticipant Name            : %s", p.PName);
		printf("\nParticipant Gender          : %s", p.PGender);
		printf("\nParticipant Phone No        : %s", p.PNO);
		printf("\nParticipant Total Payment   : %d", p.PTotalPayment);
		printf("\nParticipant Paid Payment    : %d", p.PPaidPayment);
		printf("\nParticipant Due Payment     : %d", p.PDuePayment);
		printf("\nCourse Code                 : %s", p.PCourseCode);
		printf("\nCourse Category             : %s", p.PCategoryN);
		printf("\nCourse Name                 : %s", p.PCourseN);
		printf("\nCourse Start                : %s", p.PStartDate);
		printf("\nCourse Term                 : %d", p.PCourseTerm);
		printf("\nCourse Vegetarian Meal      : %d", p.PMealV);
		printf("\nCourse Non-vegetarian Meal  : %d", p.PMealNonV);
		printf("\nCourse Payment per day      : %d", p.PCoursePayment);
		printf("\nCourse Admin fee            : %d", p.PAdminfee);
		printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
	}
	fclose(ShowC);  /*close the file*/
	system("pause"); /*wait the user to press any key*/
	system("cls"); /*clear the screen*/
	EmployeeMenu(); /*call system menu function*/
}
/* Function to show the participant details*/
void ShowPbook() {
	system("cls"); /*clear the screen*/
	char pcheckID[10];
	FILE* ShowC = fopen("Participant.txt", "r"); /*open the course file for reading*/
	printf("\n##--------------------------------------------------------------##\n");
	printf("\n                      Employee Sign in Page                       \n");
	printf("\n##--------------------------------------------------------------##\n");
	printf("\nEnter Participant ID: ");
	scanf("%s", &pcheckID);
	while (fread(&p, sizeof(p), 1, ShowC)) { /*while the file is reading, display the course details*/
		if (strcmp(p.PID, pcheckID) == 0) {
			printf("\n\n##        The Participant ID has been found successfully       ##\n");
			printf("\nParticipant ID              : %s", p.PID);
			printf("\nParticipant Name            : %s", p.PName);
			printf("\nParticipant Gender          : %s", p.PGender);
			printf("\nParticipant Phone No        : %s", p.PNO);
			printf("\nParticipant Total Payment   : %d", p.PTotalPayment);
			printf("\nParticipant Paid Payment    : %d", p.PPaidPayment);
			printf("\nParticipant Due Payment     : %d", p.PDuePayment);
			printf("\nCourse Code                 : %s", p.PCourseCode);
			printf("\nCourse Category             : %s", p.PCategoryN);
			printf("\nCourse Name                 : %s", p.PCourseN);
			printf("\nCourse Start                : %s", p.PStartDate);
			printf("\nCourse Term                 : %d", p.PCourseTerm);
			printf("\nCourse Vegetarian Meal      : %d", p.PMealV);
			printf("\nCourse Non-vegetarian Meal  : %d", p.PMealNonV);
			printf("\nCourse Payment per day      : %d", p.PCoursePayment);
			printf("\nCourse Admin fee            : %d", p.PAdminfee);
			printf("\n##--->----->----->------>------>------->----->----->------>----->\n\n");

		}

	}
	fclose(ShowC);  /*close the file*/
	system("pause"); /*wait the user to press any key*/
	system("cls"); /*clear the screen*/
	EmployeeMenu(); /*call system menu function*/
}
/* Function for update the participant payment*/
void UpdatePbook() {
	
	FILE* forginal;
	FILE* fnew;
	int PPaid;
	system("cls"); /*clear the screen*/
	char cPID[10];
	int searchID;
	printf("\n##------------------------------------------------------------------##\n");
	printf("\n                   Update participant Payment Page                      \n");
	printf("\n##------------------------------------------------------------------##\n\n");
	printf("Enter participant ID: ");
	scanf("%s", cPID);
	searchID = SearchPID(cPID);
	if (searchID == 0)
	{
		printf("**   No participant recode found for the given ID, please retry again!!!   **\n");
		system("pause");
		system("cls");
		EmployeeMenu();
	}
	else
	{
		forginal = fopen("Participant.txt", "r");
		fnew = fopen("ParticipantUpdate.txt", "w");
		while (fread(&p, sizeof(p), 1, forginal))
		{
			if (strcmp(p.PID, cPID) != 0)
				fwrite(&p, sizeof(p), 1, fnew);
			else
			{			
				printf("\nThe Total Payment: %s", p.PName);
				printf("\nThe Total Payment: %d", p.PTotalPayment);
				printf("\nThe Total Paid   : %d", p.PPaidPayment);
				printf("\nThe Due Payment  : %d", p.PDuePayment);
				printf("\nEnter the updated information below: \n\n");
				printf("\nEnter Your Payment: ");
				scanf("%d", &PPaid);
				p.PDuePayment = PPaid + p.PDuePayment;
				p.PPaidPayment = p.PPaidPayment + PPaid;
				printf("\nThe Total Payment: %d", p.PTotalPayment);
				printf("\nThe Total Paid   : %d", p.PPaidPayment);
				printf("\nThe Due Payment  : %d", p.PDuePayment);
				fwrite(&p, sizeof(p), 1, fnew);
			}
		}
		fclose(forginal);
		fclose(fnew);
		forginal = fopen("Participant.txt", "w");
		fnew = fopen("ParticipantUpdate.txt", "r");
		while (fread(&p, sizeof(p), 1, fnew))
			fwrite(&p, sizeof(p), 1, forginal);
		fclose(forginal);
		fclose(fnew);
	}
	printf("\n**==     Participant Payment record modified successfully     ==**\n");
	system("pause");
	system("cls");
	EmployeeMenu();
}
/*Function to cancel participant booking*/
void CancelBook() {
	FILE* forginal;
	FILE* fnew;
	system("cls"); /*clear the screen*/
	char cPID[10];
	int searchID;
	printf("\n##------------------------------------------------------------------##\n");
	printf("\n                   Cancel Participant Payment Page                     \n");
	printf("\n##------------------------------------------------------------------##\n\n");
	printf("Enter Participant ID: ");
	scanf("%s", &cPID);
	searchID = SearchPID(cPID);
	if (searchID == 0)
	{
		printf("\n##  The entered ID is not available inside the file !!   ##\n");
		system("pause");
		system("cls");
		EmployeeMenu();
	}
	else
	{
		forginal = fopen("Participant.txt", "r");
		fnew = fopen("ParticipantUpdate.txt", "w");
		while (fread(&p, sizeof(p), 1, forginal)) // fread my orginal file 
			if (strcmp(p.PID, cPID) != 0) // if the given id is not equal the id in the file 
				fwrite(&p, sizeof(p), 1, fnew); //  write the participant details to the new file
		fclose(forginal); // close both files
		fclose(fnew);
		/*--------------------------------*/
		forginal = fopen("Participant.txt", "w");
		fnew = fopen("ParticipantUpdate.txt", "r");
		while (fread(&p, sizeof(p), 1, fnew))
			fwrite(&p, sizeof(p), 1, forginal);
		fclose(fnew);
		fclose(forginal);
		printf("\n##  The booked Course record canceled successfully !!  ##\n");
		system("pause");
		system("cls");
		EmployeeMenu();
	}
}
/* This function for the Checking the course code inside the staff file*/
int SearchPID(char Pid[10])
{
	FILE* fRead = fopen("Participant.txt", "r"); // open the file in the reading mode
	while (!feof(fRead)) // while the pointer does not reach the end of the file
	{
		fread(&p, sizeof(p), 1, fRead); //check if the given id is in the file or not
		if (strcmp(Pid, p.PID) == 0)
		{
			fclose(fRead); // close the file
			return 1;  // return true
		}
	}
	fclose(fRead);
	return 0;  //return false
}
/*function for displaying the invoice recode*/
void InvoiceCheck() {
	system("cls");
	printf("\n##------------------------------------------------------------------##\n");
	printf("\n                         Invoice Check Menu                    \n");
	printf("\n##------------------------------------------------------------------##\n\n");
	printf("##1. Print the amount receivable from each participant\n");
	printf("##2. Print the total amount receivable and total payment received\n");
	printf("\n##Enter your choice: ");
	switch (getche()) 
	{
	case '1':
		system("cls");	
		FILE* Show = fopen("Participant.txt", "r"); /*open the course file for reading*/
		printf("\n###            These are all the Booked courses and bill details          ###\n\n");
		while (fread(&p, sizeof(p), 1, Show)) { /*while the file is reading, display the course details*/
			printf("\nParticipant ID              : %s", p.PID);
			printf("\nParticipant Name            : %s", p.PName);
			printf("\nParticipant Due Payment     : %d", p.PDuePayment);
			printf("\n##--->----->----->------>------>------->----->----->------>----->---->------>\n\n");
		}
		fclose(Show);  /*close the file*/
		break;
	case '2':
		system("cls");
		int TotalReceivable = 0, TotalReceived = 0;
		FILE* fshow = fopen("Participant.txt", "r"); /*open the file for reading*/
		while (fread(&p, sizeof(p), 1, fshow)) {
			TotalReceivable += p.PDuePayment; /* while the file is reading calculate*/
			TotalReceived += p.PPaidPayment;
		}
		fclose(fshow); /*close file*/
		printf("\n\n##    The total receivable and received amount for all participants   ##\n");
		printf("\nTotal Receivable: %d RM", TotalReceivable); /*display the final result*/
		printf("\nTOTAL RECEIVED: %d RM\n\n", TotalReceived);
		break;
	default:
		printf("\n## Wrong selection!!, please select new option ##\n\n");
		system("pause"); /*wait the user to press any key*/
		system("cls"); /*clear the screen*/
		InvoiceCheck();
		break;
	}
	system("pause"); /*wait the user to press any key*/
	system("cls"); /*clear the screen*/
	EmployeeMenu(); /*call employee menu*/
}
/*The main function of the system where the system will start*/
int main() {
	/*Create the files*/
	FILE* NewFile1 = fopen("Participant.txt", "a"); /*participant File*/
	FILE* NewFile2 = fopen("Course.txt", "a");/*Course File*/
	fclose(NewFile1); /*Close the File*/
	fclose(NewFile2); /*Close the File*/
	system("color 3"); // function to change the color
	printf("\n      Please wait while system is analyzing the data\n\n");
	for (int i = 0; i < 10; i++)
	{
		Beep(900, 400); /* function to make sound while the system is analyzing the data*/
		printf("||");
	}
	printf("\n\n                         << Done >>\n\n");
	system("pause");
	SystemMenu(); //call the system emnu function
	return 0; /* Return fales and close the program*/
}
