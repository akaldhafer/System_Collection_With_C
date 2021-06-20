//Name: Abdulmalek Aldhafer
//GitHub username : akaldhafer
//Email : Ak_aldhafer@hotmail.com
//System title : AK COLLEGE HOSTEL MANAGEMENT SYSTEM


#include<stdio.h> /*header file for simple input and output*/
#include <stdlib.h> /* header file for using files*/
#include<string.h> /*header file for using string*/
#include<math.h> /*header file for using math functions*/




struct Student {   // student details //
	int stTP;
	char name[30];
	char phone[20];
	char roomNO[10];
	int weeks;
	int roompr;
	int mealpr;
	int gympr;
	int total;
	int paid;
	int duep;
}std;
/// Declare te fctions
void bookingM();
void bookingF();
void displayingM();
void displayingF();
int avlTPM(int IDno);
int avlTPF(int IDno);
void searchingM();
void searchingF();
void CancelingM();
void CancelingF();
void updatingM();
void updatingF();
////////////////////// FUNCTION TO BOOK ROOM FOR MALE STUDENT /////////////////////////
void bookingM() {

	int option;

	FILE* file;   //code to create file or add to the file if is it already existed
	file = fopen("studentMale", "a+");
	printf("\n             Room Weakly Price            \n");  // room weakly rate//
	printf("\nBlock A2(Male): 2 beds  ** Rent: 200 ** Meal:120 ** Gym:10\n");
	printf("\nBlock A3(Male): 3 beds  ** Rent: 150 ** Meal:120 ** Gym:10\n");
	printf("\nBlock A4(Male): 4 beds  ** Rent: 100 ** Meal:120 ** Gym:10\n");
	printf("\nEnter Student TP    : "); // this code will get the student details
	scanf("%d", &std.stTP);
	printf("Enter the Name      : ");
	scanf("%s", &std.name);
	printf("Enter the phone NO  : ");
	scanf("%s", &std.phone);
	printf("Enter room NO       : ");
	scanf("%s", &std.roomNO);
	printf("Week of renting     : ");
	scanf("%d", &std.weeks);
	printf("Enter room price    : ");
	scanf("%d", &std.roompr);
service:
	std.mealpr = 120;
	std.gympr = 10;
	printf("\nWhat service you would like to add: \n");
	printf("1. Meal cost 120 weekly.\n");
	printf("2. Gym cost 10 weekly.\n");
	printf("3. Both services.\n");
	printf("4. Without service.\n");
	printf("Please select one option: ");
	scanf("%d", &option);
	if (option == 1) {
		std.total = std.roompr + std.mealpr;
		std.total = std.total * std.weeks;
	}
	else if (option == 2) {
		std.total = std.roompr + std.gympr;
		std.total = std.total * std.weeks;
	}
	else if (option == 3) {
		std.total = std.roompr + std.mealpr + std.gympr;
		std.total = std.total * std.weeks;
	}
	else if (option == 4) {
		std.total = std.roompr;
		std.total = std.total * std.weeks;
	}
	else {
		printf("\nYou have entered a wrong selection, Try again\n");
		goto service;
	}
	printf("The total: %d", std.total); //print the total amount
	printf("\nEnter received amount: ");
	scanf("%d", &std.paid);
	std.duep = std.total - std.paid;
	printf("\nDue payment is %d", std.duep);
	fwrite(&std, sizeof(std), 1, file); //write the data into the file to save it
	fclose(file);  //this will close the file after finish writing
}
//////////////////////* FUNCTION TO BOOK ROOM FOR FEMALE STUDENT */////////////////////////
void bookingF() {

	int option;

	FILE* file2;   //code to create file or add to the file if is it already existed
	file2 = fopen("studentFemale", "a+");
	printf("\n             Room Weakly Price            \n");  // room weakly rate//
	printf("\nBlock B1(Female): 1 bed  ** Rent: 400 ** Meal:120 ** Gym:10\n");
	printf("\nEnter Student TP    : "); // this code will get the student details
	scanf("%d", &std.stTP);
	printf("Enter the Name      : ");
	scanf("%s", &std.name);
	printf("Enter the phone NO  : ");
	scanf("%s", &std.phone);
	printf("Enter room NO       : ");
	scanf("%s", &std.roomNO);
	printf("Week of renting     : ");
	scanf("%d", &std.weeks);
	printf("Enter room price    : ");
	scanf("%d", &std.roompr);
service2:
	std.mealpr = 120;
	std.gympr = 10;
	printf("\nWhat service you would like to add: \n");
	printf("1. Meal cost 120 weekly.\n");
	printf("2. Gym cost 10 weekly.\n");
	printf("3. Both services.\n");
	printf("4. Without service.\n");
	printf("Please select one option: ");
	scanf("%d", &option);
	if (option == 1) {
		std.total = std.roompr + std.mealpr;
		std.total = std.total * std.weeks;
	}
	else if (option == 2) {
		std.total = std.roompr + std.gympr;
		std.total = std.total * std.weeks;
	}
	else if (option == 3) {
		std.total = std.roompr + std.mealpr + std.gympr;
		std.total = std.total * std.weeks;
	}
	else if (option == 4) {
		std.total = std.roompr;
		std.total = std.total * std.weeks;
	}
	else {
		printf("\nYou have entered a wrong selection, Try again\n");
		goto service2;
	}
	printf("The total: %d", std.total); //print the total amount
	printf("\nEnter received amount: ");
	scanf("%d", &std.paid);
	std.duep = std.total - std.paid;
	printf("\nDue payment is %d", std.duep);
	fwrite(&std, sizeof(std), 1, file2); //write the data into the file to save it
	fclose(file2);  //this will close the file after finish writing
}
//////////////////////// * DISPLAY ALL RENTING ROOM IN THE MALE STUDENT BLOCK  *///////////
void displayingM()
{
	FILE* dis;
	dis = fopen("studentMale", "r"); //open the file for reading
	printf("\nTP\tName\tPhone\tRoomNO\tWeek\tRoomP\tMealP\tGymP\tTotal\tPaid\tDueP\n");
	while (fread(&std, sizeof(std), 1, dis)) //printing the data inside the file
		printf("%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", std.stTP, std.name, std.phone, std.roomNO, std.weeks, std.roompr, std.mealpr, std.gympr, std.total, std.paid, std.duep);
	fclose(dis); //close the file
}
//////////////////////// * DISPLAY ALL RENTING ROOM IN THE FEMALE STUDENT BLOCK * ///////////
void displayingF()
{
	FILE* dis2;
	dis2 = fopen("studentFemale", "r"); //open the file for reading
	printf("\nTP\tName\tPhone\tRoomNO\tWeek\tRoomP\tMealP\tGymP\tTotal\tPaid\tDueP\n");
	while (fread(&std, sizeof(std), 1, dis2)) //printing the data inside the file
		printf("%d\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", std.stTP, std.name, std.phone, std.roomNO, std.weeks, std.roompr, std.mealpr, std.gympr, std.total, std.paid, std.duep);
	fclose(dis2); //close the file
}
////////////////* FUCTION TO CHECK MALE TP NUMBER IS AVAILABLE INSIDE THE FILE */////////////
int avlTPM(int IDno)
{
	FILE* av;
	int TPno = 0;
	av = fopen("studentMale", "r"); // open file for reading the data
	while (!feof(av))
	{
		fread(&std, sizeof(std), 1, av);

		if (IDno == std.stTP)
		{
			fclose(av);
			return 1;
		}
	}
	fclose(av); //close file
	return 0;
}
////////////////* FUCTION TO CHECK FEMALE TP NUMBER IS AVAILABLE INSIDE THE FILE *///////////
int avlTPF(int IDno)
{
	FILE* av2;
	int TPn = 0;
	av2 = fopen("studentFemale", "r"); // open file for reading the data
	while (!feof(av2))
	{
		fread(&std, sizeof(std), 1, av2);

		if (IDno == std.stTP)
		{
			fclose(av2);
			return 1;
		}
	}
	fclose(av2); //close file
	return 0;
}
//////////////// *FUNCTION TO SEARCH MALE STUDENT DETAILS BY USING STUDENT TP  */////////////
void searchingM()
{
	FILE* ser;
	int searm, sdetail, Savl;

	printf("\nEnter Student TP: "); //get student ID to search
	scanf("%d", &searm);
	Savl = avlTPM(searm);
	if (Savl == 0) {
		printf("\nThis Student TP %d is not available in the file\n", searm);
		system("pause");
		system("cls");
		main();
	}
	else
	{
		ser = fopen("studentMale", "r"); // opening the file for reading the data
		while (fread(&std, sizeof(std), 1, ser))
		{
			sdetail = std.stTP;
			if (sdetail == searm)  //displaying all the data inside the female file
			{
				printf("\nID number    = %d", std.stTP);
				printf("\nName         = %s", std.name);
				printf("\nPhone NO     = %s", std.phone);
				printf("\nRoom NO      = %s", std.roomNO);
				printf("\nWeek         = %d", std.weeks);
				printf("\nRoom Price   = %d", std.roompr);
				printf("\nMeal Price   = %d", std.mealpr);
				printf("\nLaundry Price= %d", std.gympr);
				printf("\nTotal amount = %d", std.total);
				printf("\nReceived amount = %d", std.paid);
				printf("\nDue payment  = %d\n\n", std.duep);
			}
		}
		fclose(ser); //close the file
	}
}
//////////////// *FUNCTION TO SEARCH FEMALE STUDENT DETAILS BY USING STUDENT TP  *///////////
void searchingF()
{
	FILE* ser2;
	int searm2, sdetail2, Savl2;

	printf("\nEnter Student TP: "); //get student ID to search
	scanf("%d", &searm2);
	Savl2 = avlTPF(searm2);
	if (Savl2 == 0) {
		printf("\nThis Student TP %d is not available in the file\n", searm2);
		system("pause");
		system("cls");
		main();
	}
	else
	{
		ser2 = fopen("studentFemale", "r"); // opening the file for reading the data
		while (fread(&std, sizeof(std), 1, ser2))
		{
			sdetail2 = std.stTP;
			if (sdetail2 == searm2)  //displaying all data inside the female file
			{
				printf("\nID number    = %d", std.stTP);
				printf("\nName         = %s", std.name);
				printf("\nPhone NO     = %s", std.phone);
				printf("\nRoom NO      = %s", std.roomNO);
				printf("\nWeek         = %d", std.weeks);
				printf("\nRoom Price   = %d", std.roompr);
				printf("\nMeal Price   = %d", std.mealpr);
				printf("\nLaundry Price= %d", std.gympr);
				printf("\nTotal amount = %d", std.total);
				printf("\nReceived amount = %d", std.paid);
				printf("\nDue payment  = %d\n\n", std.duep);
			}
		}
		fclose(ser2); //close the file
	}
}
/////////////// * FUNCTION TO CANCEL BOOKING FROM THE MALE FILE    * ////////////////////
void CancelingM()
{
	FILE* out;
	FILE* put;
	int cancelTP, can;

	printf("\nEnter the student TP: "); //get student ID 
	scanf("%d", &cancelTP);
	if (avlTPM(cancelTP) == 0) { //this code will check if the ID exist inside the file or not
		printf("\nStudent TP %d is not available in the file\n", cancelTP);
		system("pause");
		system("cls");
		main();
	}
	else
	{
		out = fopen("studentMale", "r"); //open file for reading
		put = fopen("MFile", "w"); //open file for writing
		while (fread(&std, sizeof(std), 1, out))
		{
			can = std.stTP;
			if (can != cancelTP)
				fwrite(&std, sizeof(std), 1, put);
		}
		fclose(out); //close file
		fclose(put);
		out = fopen("studentMale", "w"); //opening the file for writing and deleting old data
		put = fopen("MFile", "r"); //opening file for reading
		while (fread(&std, sizeof(std), 1, put))
			fwrite(&std, sizeof(std), 1, out);
		printf("\n **              Canceling Booking is done successfully            **\n");
		fclose(out); //close file
		fclose(put);
	}

}
///////////////*  FUNCTION TO CANCEL BOOKING FROM THE FEMALE FILE    * ////////////////////
void CancelingF()
{
	FILE* out2;
	FILE* put2;
	int cancelTP2, can2;

	printf("\nEnter the student TP: "); //get student ID 
	scanf("%d", &cancelTP2);
	if (avlTPF(cancelTP2) == 0) { //this code will check if the ID exist inside the file or not
		printf("\nStudent TP %d is not available in the file\n", cancelTP2);
		system("pause");
		system("cls");
		main();
	}
	else
	{
		out2 = fopen("studentFemale", "r"); //open file for reading
		put2 = fopen("FFile", "w"); //open file for writing
		while (fread(&std, sizeof(std), 1, out2))
		{
			can2 = std.stTP;
			if (can2 != cancelTP2)
				fwrite(&std, sizeof(std), 1, put2);
		}
		fclose(out2); //close file
		fclose(put2);
		out2 = fopen("studentFemale", "w"); //opening the file for writing and deleting old data
		put2 = fopen("FFile", "r"); //opening file for reading
		while (fread(&std, sizeof(std), 1, put2))
			fwrite(&std, sizeof(std), 1, out2);
		printf("\n **              Canceling Booking is done successfully            **\n");
		fclose(out2); //close file
		fclose(put2);
	}

}
/////*   FUNCTION TO UPDATE BOOKING DETAILS FOR MALE BY USING STUDENT TP  *////////////////
void updatingM()
{
	int update;
	FILE* put3;
	FILE* out3;
	int uTP, upTP;
	int upoption;

	printf("\nEnter Student TP: "); // student TP
	scanf("%d", &upTP);
	update = avlTPM(upTP);
	if (update == 0) //check if the id is available or not
	{
		printf("\nStudent TP %d is not Available in the file\n", upTP);
		system("pause");
		system("cls");
		main();
	}
	else
	{
		out3 = fopen("studentMale", "r"); //open the file for reading
		put3 = fopen("MFile", "w");//open the file for writing
		while (fread(&std, sizeof(std), 1, out3))
		{
			uTP = std.stTP;
			if (uTP != upTP)
				fwrite(&std, sizeof(std), 1, put3); //writing all data 
			else
			{
				printf("\nPlease fill up all the new details bellow\n");
				printf("\n             Room Weakly Price            \n");  // room weakly rate//
				printf("\nBlock A2(Male): 2 beds  ** Rent: 200 ** Meal:120 ** Gym:10\n");
				printf("\nBlock A3(Male): 3 beds  ** Rent: 150 ** Meal:120 ** Gym:10\n");
				printf("\nBlock A4(Male): 4 beds  ** Rent: 100 ** Meal:120 ** Gym:10\n");
				printf("\nEnter Student TP    : "); // this code will get the student details
				scanf("%d", &std.stTP);
				printf("Enter the Name      : ");
				scanf("%s", &std.name);
				printf("Enter the phone NO  : ");
				scanf("%s", &std.phone);
				printf("Enter room NO       : ");
				scanf("%s", &std.roomNO);
				printf("Week of renting     : ");
				scanf("%d", &std.weeks);
				printf("Enter room price    : ");
				scanf("%d", &std.roompr);
			upservice:
				std.mealpr = 120;
				std.gympr = 10;
				printf("\nWhat service you would like to add: \n");
				printf("1. Meal cost 120 weekly.\n");
				printf("2. Gym cost 10 weekly.\n");
				printf("3. Both services.\n");
				printf("4. Without service.\n");
				printf("Please select one option: ");
				scanf("%d", &upoption);
				if (upoption == 1) {
					std.total = std.roompr + std.mealpr;
					std.total = std.total * std.weeks;
				}
				else if (upoption == 2) {
					std.total = std.roompr + std.gympr;
					std.total = std.total * std.weeks;
				}
				else if (upoption == 3) {
					std.total = std.roompr + std.mealpr + std.gympr;
					std.total = std.total * std.weeks;
				}
				else if (upoption == 4) {
					std.total = std.roompr;
					std.total = std.total * std.weeks;
				}
				else {
					printf("\nYou have entered a wrong selection, Try again\n");
					goto upservice;
				}
				printf("The total: %d", std.total); //print the total amount
				printf("\nEnter received amount: ");
				scanf("%d", &std.paid);
				std.duep = std.total - std.paid;
				printf("\nDue payment is %d", std.duep);
				
				fwrite(&std, sizeof(std), 1, put3); //to write all new data into the file
			}
		}
		fclose(out3); //close file
		fclose(put3);
		out3 = fopen("studentMale", "w"); //open file for writing
		put3 = fopen("MFile", "r"); //open file for reading
		while (fread(&std, sizeof(std), 1, put3))
			fwrite(&std, sizeof(std), 1, out3);
		fclose(out3);// colse file
		fclose(put3);
	}
	
}
/////*   FUNCTION TO UPDATE BOOKING DETAILS FOR FEMALE BY USING STUDENT TP  *////////////////
void updatingF()
{
	int update2;
	FILE* put4;
	FILE* out4;
	int uTP2, upTP2;
	int upoption2;

	printf("\nEnter Student TP: "); // student TP
	scanf("%d", &upTP2);
	update2 = avlTPF(upTP2);
	if (update2 == 0) //check if the id is available or not
	{
		printf("\nStudent TP %d is not Available in the file\n", upTP2);
		system("pause");
		system("cls");
		main();
	}
	else
	{
		out4 = fopen("studentFemale", "r"); //open the file for reading
		put4 = fopen("FFile", "w");//open the file for writing
		while (fread(&std, sizeof(std), 1, out4))
		{
			uTP2 = std.stTP;
			if (uTP2 != upTP2)
				fwrite(&std, sizeof(std), 1, put4); //writing all data 
			else
			{
				printf("\nPlease fill up all the new details bellow\n");
				printf("\n             Room Weakly Price            \n");  // room weakly rate//
				printf("\nBlock B1(Female): 1 bed  ** Rent: 400 ** Meal:120 ** Gym:10\n");
				printf("\nEnter Student TP    : "); // this code will get the student details
				scanf("%d", &std.stTP);
				printf("Enter the Name      : ");
				scanf("%s", &std.name);
				printf("Enter the phone NO  : ");
				scanf("%s", &std.phone);
				printf("Enter room NO       : ");
				scanf("%s", &std.roomNO);
				printf("Week of renting     : ");
				scanf("%d", &std.weeks);
				printf("Enter room price    : ");
				scanf("%d", &std.roompr);
			upservice2:
				std.mealpr = 120;
				std.gympr = 10;
				printf("\nWhat service you would like to add: \n");
				printf("1. Meal cost 120 weekly.\n");
				printf("2. Gym cost 10 weekly.\n");
				printf("3. Both services.\n");
				printf("4. Without service.\n");
				printf("Please select one option: ");
				scanf("%d", &upoption2);
				if (upoption2 == 1) {
					std.total = std.roompr + std.mealpr;
					std.total = std.total * std.weeks;
				}
				else if (upoption2 == 2) {
					std.total = std.roompr + std.gympr;
					std.total = std.total * std.weeks;
				}
				else if (upoption2 == 3) {
					std.total = std.roompr + std.mealpr + std.gympr;
					std.total = std.total * std.weeks;
				}
				else if (upoption2 == 4) {
					std.total = std.roompr;
					std.total = std.total * std.weeks;
				}
				else {
					printf("\nYou have entered a wrong selection, Try again\n");
					goto upservice2;
				}
				printf("The total: %d", std.total); //print the total amount
				printf("\nEnter received amount: ");
				scanf("%d", &std.paid);
				std.duep = std.total - std.paid;
				printf("\nDue payment is %d", std.duep);

				fwrite(&std, sizeof(std), 1, put4); //to write all new data into the file
			}
		}
		fclose(out4); //close file
		fclose(put4);
		out4 = fopen("studentFemale", "w"); //open file for writing
		put4 = fopen("FFile", "r"); //open file for reading
		while (fread(&std, sizeof(std), 1, put4))
			fwrite(&std, sizeof(std), 1, out4);
		fclose(out4);// colse file
		fclose(put4);
	}
	
}
//////////////////////////////////////
/////////////////////////////////////
int main() {
	char menu, bookmenu, displaymenu, searchmenu, cancelmenu, updatemenu;
	FILE* fp1 = fopen("studentFemale", "a");
	FILE* fp2 = fopen("studentMale", "a");
	fclose(fp1);
	fclose(fp2);
    menutop:
	system("cls");
	printf("\n|----------------------------------------------------------------|\n");
	printf("\n|          AK COLLEGE HOSTEL MANAGEMENT SYSTEM                   |\n");
	printf("\n|----------------------------------------------------------------|\n\n");
	printf("\n|----------------------------------------------------------------|\n");
	printf("1. Book Room.\n");      // the main menu of the system
	printf("2. Update student Booking.\n");
	printf("3. Display All Booking Rooms.\n");
	printf("4. Search Student booking.\n");
	printf("5. Cancel Booking.\n");
	printf("6. Exit from The System.\n");
	printf("\n|----------------------------------------------------------------|\n");
	printf("\nSelect one option: "); //get input from the user
	scanf("%s", &menu); // read the input
	switch (menu)
	{
	case '1':
		booktop:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|                   WELCOME TO BOOKING PAGE                      |\n"); //booking menu//
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|   1.  Male.            2. Female       3. Back to the menu     |\n");
		printf("\nSelect your option: ");
		scanf("%s", &bookmenu);
		switch (bookmenu)
		{
		case '1':
			bookingM();
			goto booktop;
			break;
		case '2':
			bookingF();
			goto booktop;
			break;
		case '3':
			goto menutop;
			break;
		default:
			printf("\n|----------------------------------------------------------------|\n");
			printf("\n\n**  You have entered a wrong option..Please try again  **\n\n");
			goto booktop;
			break;
		}
		goto menutop; //will back to the main menu 
		break;
	case '2':
		updatetop:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|                    WELCOME TO UPDATING PAGE                    |\n");
		printf("\n|----------------------------------------------------------------|\n"); //updating menu//
		printf("\n|   1.  Male.            2. Female       3. Back to the menu     |\n");
		printf("\nSelect your option: ");
		scanf("%s", &updatemenu);
		switch (updatemenu)
		{
		case '1':
			updatingM();
			goto updatetop;
			break;
		case '2':
			updatingF();
			goto updatetop;
			break;
		case '3':
			goto menutop;
			break;
		default:
			printf("\n|----------------------------------------------------------------|\n");
			printf("\n\n**  You have entered a wrong option..Please try again  **\n\n");
			goto updatetop;
			break;
		}
		goto menutop; //will back to the main menu
		break;
	case '3':
		displaytop:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|                    WELCOME TO DISPLAYING PAGE                  |\n");
		printf("\n|----------------------------------------------------------------|\n");//displaying menu//
		printf("\n|   1.  Male.            2. Female       3. Back to the menu     |\n");
		printf("\nSelect your option: ");
		scanf("%s", &displaymenu);
		switch (displaymenu)
		{
		case '1':
			displayingM();
			goto displaytop;
			break;
		case '2':
			displayingF();
			goto displaytop;
			break;
		case '3':
			goto menutop;
			break;
		default:
			printf("\n|----------------------------------------------------------------|\n");
			printf("\n\n**  You have entered a wrong option..Please try again  **\n\n");
			goto displaytop;
			break;
		}
		goto menutop; //will back to the main menu 
		break;
	case '4':
		searchtop:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|                    WELCOME TO SEARCHING PAGE                   |\n");
		printf("\n|----------------------------------------------------------------|\n");//searching menu//
		printf("\n|   1.  Male.            2. Female       3. Back to the menu     |\n");
		printf("\nSelect your option: ");
		scanf("%s", &searchmenu);
		switch (searchmenu)
		{
		case '1':
			searchingM();
			goto searchtop;
			break;
		case '2':
			searchingF();
			goto searchtop;
			break;
		case '3':
			goto menutop;
			break;
		default:
			printf("\n|----------------------------------------------------------------|\n");
			printf("\n\n**  You have entered a wrong option..Please try again  **\n\n");
			goto searchtop;
			break;
		}
		goto menutop; //will back to the main menu
		break;
	case '5':
		canceltop:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|                    WELCOME TO CANCELING PAGE                   |\n");
		printf("\n|----------------------------------------------------------------|\n");//canceling menu//
		printf("\n|   1.  Male.            2. Female       3. Back to the menu     |\n");
		printf("\nSelect your option: ");
		scanf("%s", &cancelmenu);
		switch (cancelmenu)
		{
		case '1':
			CancelingM();
			goto canceltop;
			break;
		case '2':
			CancelingF();
			goto canceltop;
			break;
		case '3':
			goto menutop;
			break;
		default:
			printf("\n|----------------------------------------------------------------|\n");
			printf("\n\n**  You have entered a wrong option..Please try again  **\n\n");
			system("pause");
			system("cls");
			goto canceltop;
			break;
		}
		goto menutop; //will back to the main menu 
		break;
	case '6':
		printf("\n|----------------------------------------------------------------|\n");
		system("pause");
		exit(1); //will exit from the system
		break;
	default:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n\n**  You have entered a wrong option..Please try again  **\n\n");
		system("pause");
		goto menutop; //will back to the beginning 
		break;
	}
	return(0);
}
