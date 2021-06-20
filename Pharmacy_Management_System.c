//Developer name: Abdulamlek Taher AlDhafer
//ak_aldhafer@hotmail.com
//Name: Abdulmalek Aldhafer
//GitHub username : akaldhafer
//Email : Ak_aldhafer@hotmail.com
//program title: Pharmacy Management System  

#include<stdio.h>  //the header file stands for standard input/output//
#include <stdlib.h> // header of the general purpose standard library of C programming//
#include<math.h>  //header file in the standard library of the C designed for basic mathematical operations//
#include <time.h> //header file in the standard library of the C designed for produce time//
#pragma warning (disable: 4996)

//                                            Pharmacy Management System                                 //
// The program will allow admin to create account in the system and log in,//
// create new medicine or update or delete or search or list all medicins with their expiry date by months//
//  customer will be able to search medicin or view medicin details or buy medicine and view bill //

//    ADMIN DETAILS  //
struct Admin {   // Admin details //
	int adID;
	char name[30];
	int phone;
}ad;
//   MEDICINE DETAILS //
struct Medicine {   // medicine details //
	int mdID;
	char Mname[20];
	char companyname[30];
	float price;
	int items;
	char Madedate[20];
	char Expirydate[20];
}md;

//////////////////////* FUNCTION TO SIGN UP FOR ADMIN */////////////////////////
void adminlogup() {

	FILE* fadmin;   //code to create file or add to the file if is it already existed
	fadmin = fopen("admin.txt", "a+");
	printf("Please enter all the needed information below\n");
	printf("Enter admin ID: ");
	scanf("%d", &ad.adID);
	printf("Enter name: ");
	scanf("%s", &ad.name);
	printf("Enter phone NO: ");
	scanf("%d", &ad.phone);
	fwrite(&ad, sizeof(ad), 1, fadmin); //write the data into the file to save it
	fclose(fadmin);  //this will close the file after finish writing
}
// FUNCTION TO UPDATE ADMIN ACCOUNT //
void Updateaccount()
{
	int updatID;
	FILE* fup;
	FILE* fup2;
	int updID, newID;

update:
	printf("\nEnter Medicine ID: "); // Medicine ID
	scanf("%d", &newID);
	updatID = avladmID(newID);
	if (updatID == 0) //check if the id is available or not
	{
		printf("\nMedicine ID %d is not Available in the file\n", newID);
		goto update;
	}
	else
	{
		fup2 = fopen("admin.txt", "r"); //open the file for reading
		fup = fopen("aFile.txt", "w");//open the file for writing
		while (fread(&ad, sizeof(ad), 1, fup2))
		{
			updID = ad.adID;
			if (updID != newID)
				fwrite(&ad, sizeof(ad), 1, fup); //writing all data 
			else
			{

				printf("Please fill up the requirements below\n");
				printf("Enter admin ID: ");
				scanf("%d", &ad.adID);
				printf("Enter name: ");
				scanf("%s", &ad.name);
				printf("Enter phone NO: ");
				scanf("%d", &ad.phone);
				fwrite(&ad, sizeof(ad), 1, fup); //to write all new data into the file
			}
		}
		fclose(fup2); //close file
		fclose(fup);
		fup2 = fopen("admin.txt", "w"); //open file for writing
		fup = fopen("aFile.txt", "r"); //open file for reading
		while (fread(&ad, sizeof(ad), 1, fup))
			fwrite(&ad, sizeof(ad), 1, fup2);
		fclose(fup2);// colse file
		fclose(fup);
	}

}

//////////////////////* FUNCTION TO ADD MEDICINE */////////////////////////

void addmedicine() {

	FILE* fmedicine;   //code to create file or add to the file if is it already existed
	fmedicine = fopen("medicine.txt", "a+");
	printf("\n|----------------------------------------------------------------|\n");
	printf("\n|                      Adding new medicine                       |\n");
	printf("\n|----------------------------------------------------------------|\n");
	printf("Please fill up the requirements below\n");
	printf("Enter medicine ID: ");
	scanf("%d", &md.mdID);
	printf("Enter medicine name: ");
	scanf("%s", &md.Mname);
	printf("Enter company name: ");
	scanf("%s", &md.companyname);
	printf("Enter price: ");
	scanf("%f", &md.price);
	printf("Enter items: ");
	scanf("%d", &md.items);
	printf("\n** dd/mn/yr **\n");
	printf("Enter Date of Manufacture: ");
	scanf("%s", &md.Madedate);
	printf("Enter Date of Expiry: ");
	scanf("%s", &md.Expirydate);
	fwrite(&md, sizeof(md), 1, fmedicine); //write the data into the file to save it
	fclose(fmedicine);  //this will close the file after finish writing
}
//   Fuction to check admin ID in the file //
int avladmID(int IDno)
{
	FILE* favl;
	int ID = 0;
	favl = fopen("admin.txt", "r"); // open file for reading the data
	while (!feof(favl)) //read from the file line by line till finding the right ID or the end of the file//
	{
		fread(&ad, sizeof(ad), 1, favl);

		if (IDno == ad.adID) //if the new ID equal to the saved one in the file//
		{
			fclose(favl);
			return 1;
		}
	}
	fclose(favl); //close file
	return 0;
}
//   Fuction to check medicine ID in the file //
int avlmedID(int IDno)
{
	FILE* favlm;
	int mID = 0;
	favlm = fopen("medicine.txt", "r"); // open file for reading the data
	while (!feof(favlm)) //read from the file line by line till finding the right ID or the end of the file//
	{
		fread(&md, sizeof(md), 1, favlm);

		if (IDno == md.mdID) //if the new ID equal to the saved one in the file//
		{
			fclose(favlm);
			return 1;
		}
	}
	fclose(favlm); //close file
	return 0;
}
/////*        FUNCTION TO UPDATE MEDICINE DETAILS   *////////////////
void ModifyM()
{
	int modifyID;
	FILE* fput3;
	FILE* fout3;
	int modID, upID;

updateID:
	printf("\nEnter Medicine ID: "); // Medicine ID
	scanf("%d", &upID);
	modifyID = avlmedID(upID);
	if (modifyID == 0) //check if the id is available or not
	{
		printf("\nMedicine ID %d is not Available in the file\n", upID);
		goto updateID;
	}
	else
	{
		fout3 = fopen("medicine.txt", "r"); //open the file for reading
		fput3 = fopen("MFile.txt", "w");//open the file for writing
		while (fread(&md, sizeof(md), 1, fout3))
		{
			modID = md.mdID;
			if (modID != upID)
				fwrite(&md, sizeof(md), 1, fput3); //writing all data 
			else
			{

				printf("Please fill up the requirements below\n");
				printf("Enter medicine ID: ");
				scanf("%d", &md.mdID);
				printf("Enter medicine name: ");
				scanf("%s", &md.Mname);
				printf("Enter company name: ");
				scanf("%s", &md.companyname);
				printf("Enter price: ");
				scanf("%f", &md.price);
				printf("Enter items: ");
				scanf("%d", &md.items);
				printf("\n** dd/mn/yr **\n");
				printf("Enter Date of Manufacture: ");
				scanf("%s", &md.Madedate);
				printf("Enter Date of Expiry: ");
				scanf("%s", &md.Expirydate);
				fwrite(&md, sizeof(md), 1, fput3); //to write all new data into the file
			}
		}
		fclose(fout3); //close file
		fclose(fput3);
		fout3 = fopen("medicine.txt", "w"); //open file for writing
		fput3 = fopen("MFile.txt", "r"); //open file for reading
		while (fread(&md, sizeof(md), 1, fput3))
			fwrite(&md, sizeof(md), 1, fout3);
		fclose(fout3);// colse file
		fclose(fput3);
	}

}

//                      FUNCTION TO DELETE MEDICINE                    //
void deletemedicine()
{
	FILE* fout;
	FILE* fput;
	int deleteID, checkid;
deletetop:
	printf("\nEnter the Medicine ID: "); //get Medicine ID
	scanf("%d", &deleteID);
	if (avlmedID(deleteID) == 0) { //this code will check if the ID exist inside the file or not
		printf("\nMedicine ID %d is not available in the file\n", deleteID);
		goto deletetop;

	}
	else
	{
		fout = fopen("medicine.txt", "r"); //open file for reading
		fput = fopen("MFile.txt", "w"); //open file for writing
		while (fread(&md, sizeof(md), 1, fout))
		{
			checkid = md.mdID;
			if (checkid != deleteID)
				fwrite(&md, sizeof(md), 1, fput);
		}
		fclose(fout); //close file
		fclose(fput);
		fout = fopen("medicine.txt", "w"); //opening the file for writing and deleting old data
		fput = fopen("MFile.txt", "r"); //opening file for reading
		while (fread(&md, sizeof(md), 1, fput))
			fwrite(&md, sizeof(md), 1, fout);
		printf("\n **              Deleting the medicine is done successfully            **\n");
		fclose(fout); //close file
		fclose(fput);
	}

}

//                      FUNCTION TO SEARCH FOR MEDICINE                    //
void searchM()
{
	FILE* search;
	int searchm, searchID, Savl;
searchtop:
	printf("\nEnter Medicine ID: "); //get Medicine ID to search
	scanf("%d", &searchm);
	Savl = avlmedID(searchm);
	if (Savl == 0) {
		printf("\nThis Medicine ID %d is not available in the file\n", searchm);
		goto searchtop;
	}
	else
	{
		search = fopen("medicine.txt", "r"); // opening the file for reading the data
		while (fread(&md, sizeof(md), 1, search))
		{
			searchID = md.mdID;
			if (searchID == searchm)  //displaying all the data inside the file
			{
				printf("\nMedicine ID         = %d", md.mdID);
				printf("\nMedicine Name       = %s", md.Mname);
				printf("\nCompany Name        = %s", md.companyname);
				printf("\nMedicine price      = %0.2f", md.price);
				printf("\nAvailable items     = %d", md.items);
				printf("\nDate of Manufacture = %s", md.Madedate);
				printf("\nDate of Expiry      = %s", md.Expirydate);
			}
		}
		fclose(search); //close the file
	}
}

void readReceipts()
{
	char receipt[200];
	FILE* readReceipts;
	readReceipts = fopen("receipt.txt", "r");
	if (readReceipts == 0)
		printf("\nThere is no record of any purchase yet\n");
	else
	{
		while (fread(&receipt, sizeof(receipt), 1, readReceipts))
			printf("%s\n__________________________________________________________________\n\n", receipt);
	}
	system("PAUSE");
	system("CLS");
	main();
}

//////////////////////// * List out expiry dates of the medicines based on months  *///////////
void ListM()
{
	FILE* list;
	list = fopen("medicine.txt", "r"); //open the file for reading
	printf("\nMedicineID\tExpiry Date\n");
	while (fread(&md, sizeof(md), 1, list)) {    //printing the data inside the file
		printf("%d\t\t%s\n", md.mdID, md.Expirydate);
	}
	fclose(list); //close the file
}
//////////////////////// * List medicines based on availability  *///////////
void ListMed()
{
	FILE* listmed;
	listmed = fopen("medicine.txt", "r"); //open the file for reading
	printf("\nMedicineID\tMedicine\tAvailable items\n");
	while (fread(&md, sizeof(md), 1, listmed)) {    //printing the data inside the file
		printf("%d\t%s\t%d\n", md.mdID, md.Mname, md.items);
	}
	fclose(listmed); //close the file
}
/////////////    * List all  medicines   *///////////
void ListAll()
{
	FILE* listmall;
	listmall = fopen("medicine.txt", "r"); //open the file for reading
	printf("\nMedicineID\tMedicine\tCompany\tPrice\tItems\tManufacture\tExpiry\n");
	while (fread(&md, sizeof(md), 1, listmall)) {    //printing the data inside the file
		printf("%d\t\t%s\t\t%s\t%0.2f\t%d\t%s\t\t%s\n", md.mdID, md.Mname, md.companyname, md.price, md.items, md.Madedate, md.Expirydate);
	}
	fclose(listmall); //close the file
}
//                        Main fuction                      //
int main() {

	int admID, chechID, upaccount, view;
	float bill;
	time_t timer;
	char buffer[26];
	struct tm* tm_info;

menutop:
	printf("\n|----------------------------------------------------------------|\n");
	printf("\n|                Pharmacy Management System                      |\n");
	printf("\n|----------------------------------------------------------------|\n\n");
	printf("\n|----------------------------------------------------------------|\n");
	printf("1. Log in as Admin.\n");      // the main menu of the system
	printf("2. Customer page.\n");
	printf("3. Exit from The System.\n");
	printf("\n|----------------------------------------------------------------|\n");
	printf("\nSelect one option: "); //get input from the user
	switch (getche())
	{
	case '1':
	menu2top:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|                Pharmacy Management System                      |\n");
		printf("\n|----------------------------------------------------------------|\n\n");
		printf("1. Log in.\n");      // the main menu of the system
		printf("2. Sign up.\n");
		printf("3. Back to the main menu.\n");
		printf("\n|----------------------------------------------------------------|\n");
		printf("\nSelect one option: "); //get input from the user
		switch (getche())
		{
		case '1':

		toplog:
			printf("\n|----------------------------------------------------------------|\n");
			printf("\n|                    Log in for admin page                       |\n");
			printf("\n|----------------------------------------------------------------|\n\n");
			printf("\nEnter admin ID: ");
			scanf("%d", &admID);
			chechID = avladmID(admID);
			if (chechID == 0) {
				printf("\nThis Admin ID %d is not available in the file\n", admID);
				goto toplog;
			}
			else
			{
			adminmenu:
				printf("\n\n                   Admin menu             \n");
				printf("1. Manage account\n");
				printf("2. Add a new medicine\n");
				printf("3. Delete an existing medicine\n");
				printf("4. Modify an existing medicine\n");
				printf("5. Search for an existing medicine\n");
				printf("6. List out expiry dates of the medicines based on months\n");
				printf("7. View receipts\n");
				printf("8. Back to the main menu\n");
				printf("Enter one option: ");

				switch (getche())
				{
				case '1':
					printf("\n1. Update account details\n");
					printf("2. Back to admin menu\n");
					printf("Enter one option: ");
					scanf("%d", &upaccount);
					if (upaccount == 1) {
						Updateaccount();
						goto adminmenu;
					}
					else if (upaccount == 2) {
						goto adminmenu;
					}
					else {
						goto adminmenu;
					}
					break;
				case '2':
					addmedicine();
					goto adminmenu;
					break;
				case '3':
					deletemedicine();
					goto adminmenu;
					break;
				case '4':
					ModifyM();
					goto adminmenu;
					break;
				case '5':
					searchM();
					goto adminmenu;
					break;
				case '6':
					ListM();
					goto adminmenu;
					break;
				case '7':
					readReceipts();
					break;
				case '8':
					goto menutop;
					break;
				default:
					printf("\n\n*** You have entered wrong option, Please try again ***\n\n");
					goto adminmenu;
					break;
				}
			}
			break;
		case '2':
			printf("\n|----------------------------------------------------------------|\n");
			printf("\n|                      Sign up for admin                         |\n");
			printf("\n|----------------------------------------------------------------|\n");
			adminlogup();
			printf("\n\t\tRegistration is done successfully\t\t\n");
			goto menu2top;
			break;
		case '3':
			goto menutop;
			break;
		default:
			printf("\n\n*** You have entered wrong option, Please try again ***\n\n");
			goto menu2top;
			break;
		}

		break;
	case '2':
	menu3top:
		printf("\n|----------------------------------------------------------------|\n");
		printf("\n|                        Customer service page                           |\n");
		printf("\n|----------------------------------------------------------------|\n\n");
		printf("1. Search for a medicine if available or not.\n");      // the main menu of the system
		printf("2. View medicine details.\n");
		printf("3. Buy medicine.\n");
		printf("4. Back to the main menu.\n");
		printf("\n|----------------------------------------------------------------|\n");
		printf("\nSelect one option: "); //get input from the user

		switch (getche())
		{
		case '1':
			ListMed();
			goto menu3top;
			break;
		case '2':
			printf("\n1. View specific medicine\n");
			printf("2. View all medicine\n");
			printf("3. Back to customer service page\n");
			printf("Please enter one option: ");
			scanf("%d", &view);
			if (view == 1) {
				searchM();
				goto menu3top;
			}
			else if (view == 2) {
				ListAll();
				goto menu3top;
			}
			else if (view == 3) {
				goto menu3top;
			}
			else {
				printf("You have entered something wrong");
				goto menu3top;
			}
			break;
		case '3':
			printf("\nThese are all the medicines available\n");
			ListAll();
			printf("\nSelect the medicine that you want to buy\n");
			printf("Enter medicine ID: ");
			scanf("%d", &md.mdID);
			printf("Enter price: ");
			scanf("%f", &md.price);
			printf("Enter item you want to buy: ");
			scanf("%d", &md.items);
			bill = md.price * md.items;
			char receipt[200] = "";
			strcat(receipt, "\n\nProduct\t\tPrice\t\tQuantity\tTotal\n");
			strcat(receipt, md.Mname);
			strcat(receipt, "\t\t");
			gcvt(md.price, 5, buffer);
			strcat(receipt, buffer);
			strcat(receipt, "\t\t");
			itoa(md.items, buffer, 10);
			strcat(receipt, buffer);
			strcat(receipt, "\t\t");
			gcvt(bill, 5, buffer);
			strcat(receipt, buffer);
			strcat(receipt, "\n\n");
			printf("%s", receipt);
			printf("\nThe total payment is %.02f\n", bill);
			time(&timer);
			tm_info = localtime(&timer);
			strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
			puts(buffer);
			strcat(receipt, buffer);
			FILE* receiptSave;
			receiptSave = fopen("receipt.txt", "a+");
			fwrite(receipt, sizeof(receipt), 1, receiptSave);
			fclose(receiptSave);
			printf("\n--------------------- THANK YOU SIR AND SEE YOU AGAIN ----------------------\n");
			goto menu3top;
			break;
		case '4':
			goto menutop;
			break;
		default:
			printf("\n\n*** You have entered wrong option, Please try again ***\n\n");
			goto menu3top;
			break;
		}

		break;
	case '3':
		exit(1);  //will exit from the system
		break;
	default:
		printf("\n\n*** You have entered wrong option, Please try again ***\n\n");
		goto menutop;
		break;
	}

	return(0);
}
