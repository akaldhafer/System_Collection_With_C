//Name: Abdulmalek Aldhafer
//GitHub username : akaldhafer
//Email : Ak_aldhafer@hotmail.com
//System title : ALDhafer Car Service Management System


#include <stdio.h> /*header files*/
#include <string.h>/*string function*/
#include <stdlib.h>/*for improtant function such as strcmp*/
#include <windows.h>/*system function such as pause and cls*/
#include <stdbool.h>/*for boolean function*/
#pragma warning (disable: 4996)/*disable scanf and scanf_s error*/

/*declare the customer structer*/
struct Customer {
	char ID[5];/*customer ID*/
	char name[20]; /*customer name*/
	char phone[20];
	char ServiceTaken[50];/*one of the avaiable 8 service*/
	char ServiceType[10]; /*(Normal/Urgent) */
	char ServiceDate[20];
	char CarRegistrationNO[10];
	char InvoiceNo[10];
	int ServiceFee;
	char newline[2];
}c;


/*declare the local variables*/
char option, choice, stype, choice2;
/*declare the services types*/
char ST1[50] = "Repair Punctured Car tyre/piece";
char ST2[50] = "Car Tyre Change/piece";
char ST3[50] = "Mineral Oil Change";
char ST4[50] = "Synthetic Oil Change";
char ST5[50] = "Battery Change";
char ST6[50] = "Head light Bulb change/piece";
char ST7[50] = "Tail light bulb change/piece";
char ST8[50] = "Car Wash";
char Nextline[2] = "\n";
/*declare the program functions*/
int main();
void StaffMenu();
bool CheckCID(char crId[5]);
void Register();
void SearchCustomerRecord();
void ViewCustomerRecords();
void updatePersonalInfo();
void DeleteCustomerRecord();
void DisplayTotalOwnedMoney();
void ViewInvoicesRecords();
/*program main menu*/
int main(){
	char PIN[4];
	FILE* fcustomer = fopen("Customer.txt", "a");//Declare the customer file//
	fclose(fcustomer);
	system("color 2");
	do{
		system("CLS");
		printf("\n<*<>*><*<>*> AL Dhafer Car Service Management System <*<>*><*<>*>\n\n");
		printf("1. Login as Staff              2. Exit\n");
		printf("\n<*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*>\n");
		printf("\nSelect one option: "); scanf("%s", &choice2);
		switch (choice2)
		{
		case '1':
			printf("\nPIN By Default (1234)");
			printf("\nEnter The PIN: ");
			scanf("%s", &PIN);
			if (strcmp(PIN, "1234") == 0) /*strcmp   string compare*/
				StaffMenu();
			else
			{
				printf("\n<*<>*><*<>*> Wrong PIN ! <*<>*><*<>*>\n");
			}
			break;
		case '2':
			printf("\n<*<>*><*<>*> Thanks For Your Time <*<>*><*<>*>\n");
			system("PAUSE");
			system("CLS");
			exit(1);
			break;
		default:
			printf("\n<*<>*><*<>*> Invalid Entry ! <*<>*><*<>*>\n\n");
			break;
		}
		system("PAUSE");
		system("CLS");
	} while (choice2 != '2');
	return 0;
}
/*Staff Menu*/
void StaffMenu() {
	system("color 3");
	do{
		system("CLS");
		printf("\n<*<>*><*<>*>                Staff Menu           <*<>*><*<>*>\n\n");
		printf("1. Register New Customer         2. View All Customers Records\n");
		printf("3. Delete Customer Record        4. Search Customer Record\n");
		printf("5. Update Customer Record        6. View All Invoices Records\n");
		printf("7. Display Total owned Payments  8. Sign Out\n");
		printf("\n<*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*><*<>*>\n");
		printf("\nSelect an option: "); scanf("%s", &choice);
		switch (choice){
		case '1':	
			Register();
			break;
		case '2':
			ViewCustomerRecords();
			break;
		case '3':
			DeleteCustomerRecord();
			break;
		case '4':
			SearchCustomerRecord();
			break;
		case '5':
			updatePersonalInfo();
			break;
		case '6':
			ViewInvoicesRecords();
			break;
		case '7':
			DisplayTotalOwnedMoney();
			break;
		case '8':
			printf("\n<*<>*><*<>*> You have Signed Out Successfuly <*<>*><*<>*>\n");
			system("PAUSE");
			system("CLS");
			main();
			break;
		default:
			printf("\n<*<>*><*<>*> Invalid Entry ! <*<>*><*<>*>\n\n");
			break;
		}
		system("PAUSE");
		system("CLS");
	} while (choice != '8');
	
}
/*check customer ID*/
bool CheckCID(char crId[5])
{
	FILE* fc = fopen("Customer.txt", "r");
	while (fread(&c, sizeof(c), 1, fc))/*scan the file till the end of the file*/
	{   /*scanf the file*/	
		if (strcmp(crId, c.ID) == 0){
			fclose(fc);
			return true;
			break;
		}
	}
	fclose(fc);
	return false;
}
/*register customer function*/
void Register() {
	FILE* fcustomer = fopen("Customer.txt", "a");
	system("CLS");
	printf("\n<*<>*><*<>*>    Customer Register     <*<>*><*<>*>\n");
	printf("\n|NO|                                 |Time(Min)|Normal|Urgent|\n");
	printf("\n|1. Repair punctured car tyre/piece  |10       |RM5   |RM6   |\n");
	printf("\n|2. Car tyre change/piece            |15       |RM150 |RM160 |\n");
	printf("\n|3. Mineral Oil Change               |20       |RM80  |RM90  |\n");
	printf("\n|4. Synthetic Oil Change             |20       |RM130 |RM140 |\n");
	printf("\n|5. Battery Change                   |5        |RM200 |RM210 |\n");
	printf("\n|6. Head light bulb change/piece     |5        |RM6   |RM8   |\n");
	printf("\n|7. Taillight bulb change/piece      |5        |RM6   |RM8   |\n");
	printf("\n|8. Car Wash                         |10       |RM10  |RM12  |\n");
	printf("\nChoose one service: "); scanf("%s", &option);
	switch (option)
	{
	case '1':
		strcpy(c.ServiceTaken, ST1);/*string copy function*/
		break;
	case '2':
		strcpy(c.ServiceTaken, ST2);
		break;
	case '3':
		strcpy(c.ServiceTaken, ST3);
		break;
	case '4':
		strcpy(c.ServiceTaken, ST4);
		break;
	case '5':
		strcpy(c.ServiceTaken, ST5);
		break;
	case '6':
		strcpy(c.ServiceTaken, ST6);
		break;
	case '7':
		strcpy(c.ServiceTaken, ST7);
		break;
	case '8':
		strcpy(c.ServiceTaken, ST8);
		break;
	default:
		printf("\n<*<>*><*<>*> Invalid Entry ! <*<>*><*<>*>\n\n");
		system("PAUSE");
		system("CLS");
		Register();
		break;
	}
	printf("\nEnter Service Type(1. Normal  2. Urgent): ");
	scanf("%s", &stype);
	if (stype == '1') {
		strcpy(c.ServiceType, "Normal");
	}
	else {
		strcpy(c.ServiceType, "Urgent");
	}
	printf("\nEnter the Service fee: "); scanf("%d", &c.ServiceFee);
	printf("\nEnter customer ID: ");scanf("%s", &c.ID);
	printf("\nEnter Your Name: "); scanf("%s", &c.name);
	printf("\nEnter Your Phone Number: "); scanf("%s", &c.phone);
	printf("\nEnter Car Registration NO: "); scanf("%s", &c.CarRegistrationNO);
	printf("\nEnter The Date(Y/M/D): "); scanf("%s", &c.ServiceDate);
	printf("\nEnter Invoice Number: "); scanf("%s", &c.InvoiceNo);
	strcpy(c.newline, Nextline);
	//write all the data//
	fwrite(&c, sizeof(c), 1, fcustomer);
	printf("\n\n<*<>*><*<>*> Customer Registered Successfully  <*<>*><*<>*>\n\n");
	fclose(fcustomer);
	/*generate Invoice*/
	printf("\n\n<*<>*><*<>*>   Invoice Details   <*<>*><*<>*>\n\n");
	printf("\nInvoice Number      : %s", c.InvoiceNo);
	printf("\nCustomer ID         : %s", c.ID);
	printf("\nCustomer Name       : %s", c.name);
	printf("\nCustomer Phone No   : %s", c.phone);
	printf("\nCar Registration NO : %s", c.CarRegistrationNO);
	printf("\nService Date        : %s", c.ServiceDate);
	printf("\nService taken       : %s", c.ServiceTaken);
	printf("\nService Type        : %s", c.ServiceType);
	printf("\nService Fee         : %d\n", c.ServiceFee);
	return;
}
/*view all customers function*/
void ViewCustomerRecords() {
	FILE* fcustomer = fopen("Customer.txt", "r");//open the file//
	printf("\n\n<*<>*><*<>*>   Customer Records Details   <*<>*><*<>*>\n\n");
	while (fread(&c, sizeof(c), 1, fcustomer)) {
		printf("\nCustomer ID         : %s", &c.ID);
		printf("\nCustomer Name       : %s", &c.name);
		printf("\nCustomer Phone No   : %s", &c.phone);
		printf("\nCar Registration NO : %s", &c.CarRegistrationNO);
		printf("\n____________________________________________________\n");
	}
	fclose(fcustomer);
}
/*search for a customer function*/
void SearchCustomerRecord() {
	FILE* fcustomer = fopen("Customer.txt", "r");//open the file//
	char cid[5];
	printf("\n\n<*<>*><*<>*>   Search Customer Record   <*<>*><*<>*>\n\n");
	printf("\n Enter Customer ID to Search: "); scanf("%s", &cid);
	while (fread(&c, sizeof(c), 1, fcustomer)) {/*read the file*/
		if (strcmpi(c.ID, cid)==0) {/*check customer id*/
			printf("\nInvoice Number      : %s", &c.InvoiceNo);
			printf("\nCustomer ID         : %s", &c.ID);
			printf("\nCustomer Name       : %s", &c.name);
			printf("\nCustomer Phone No   : %s", &c.phone);
			printf("\nCar Registration NO : %s", &c.CarRegistrationNO);
			printf("\nService Date        : %s", &c.ServiceDate);
			printf("\nService taken       : %s", &c.ServiceTaken);
			printf("\nService Type        : %s", &c.ServiceType);
			printf("\nService Fee         : %d", c.ServiceFee);
			printf("\n____________________________________________________\n");
		}
	}
	fclose(fcustomer);
}
/*update customer record*/
void updatePersonalInfo()
{
	FILE* fcustomer;
	FILE* FtempFile;
	char checkid[5];
	printf("\n\n<*<>*><*<>*>  Update Customer Profile  <*<>*><*<>*>\n\n");
	printf("\nEnter customer ID: ");
	scanf("%s", &checkid);
	if (CheckCID(checkid) == false) {
		printf("\n\n<*<>*><*<>*> Wrong ID, Please retry again <*<>*><*<>*>\n\n");}
	else{
		fcustomer = fopen("Customer.txt", "r");
		FtempFile = fopen("TempFile.txt", "w");
		while (fread(&c, sizeof(c), 1, fcustomer))
		{/*read the customer file*/
			if (strcmp(c.ID, checkid) != 0)/*copying the data into the tempfile*/
				fwrite(&c, sizeof(c), 1, FtempFile);
			else {
				printf("\nNOTE: Only the personal information allowed to be updated\n");
				printf("\nEnter Your Name: "); scanf("%s", &c.name);
				printf("\nEnter Your Phone Number: "); scanf("%s", &c.phone);
				printf("\nEnter Car Registration NO: "); scanf("%s", &c.CarRegistrationNO);
				fwrite(&c, sizeof(c), 1, FtempFile);				
				//update the new data//
			}
		}
		fclose(FtempFile);/*close both files and save changes made*/
		fclose(fcustomer);
		fcustomer = fopen("Customer.txt", "w");
		FtempFile = fopen("TempFile.txt", "r");
		while (fread(&c, sizeof(c), 1, FtempFile)) {
			fwrite(&c, sizeof(c), 1, fcustomer);
			//copying the data from the temporary file into the Customer file//
		}
		printf("\n\n<*<>*><*<>*> Customer Profile Updated Successfully  <*<>*><*<>*>\n\n");
		fclose(FtempFile);/*close both files and save the changes*/
		fclose(fcustomer);
	}
}
/*delete customer record*/
void DeleteCustomerRecord()
{
	FILE* fcustomer;
	FILE* FtempFile;
	char checkid2[5];
	printf("\n\n<*<>*><*<>*>  Delete Customer Record  <*<>*><*<>*>\n\n");
	printf("\nEnter customer ID: ");
	scanf("%s", &checkid2);
	if (CheckCID(checkid2) == false) {
		printf("\n\n<*<>*><*<>*> Wrong ID, Please retry again <*<>*><*<>*>\n\n");}
	else{
		fcustomer = fopen("Customer.txt", "r");
		FtempFile = fopen("TempFile.txt", "w");
		while (fread(&c, sizeof(c), 1, fcustomer))
		{/*read the customer file*/
			if (strcmp(c.ID, checkid2) != 0) /*copying the data into the tempfile*/
				fwrite(&c, sizeof(c), 1, FtempFile);/*except the wanted record tobe deleted*/
		}
		fclose(FtempFile);/*close both files and save changes made*/
		fclose(fcustomer);
		fcustomer = fopen("Customer.txt", "w");
		FtempFile = fopen("TempFile.txt", "r");
		while (fread(&c, sizeof(c), 1, FtempFile)) 
			fwrite(&c, sizeof(c), 1, fcustomer);
			//copying the data from the temporary file into the Customer file//
		printf("\n\n<*<>*><*<>*> Customer Profile Deleted Successfully  <*<>*><*<>*>\n\n");
		fclose(FtempFile);/*close both files and save the changes*/
		fclose(fcustomer);
	}
}
/*display total owned money*/
void DisplayTotalOwnedMoney() {
	FILE* fcustomer = fopen("Customer.txt", "r");//open the file//
	int TotalOwned = 0;
	printf("\n\n<*<>*><*<>*>   Display Total Owned Money  <*<>*><*<>*>\n\n");
	while (fread(&c, sizeof(c), 1, fcustomer)) {
		TotalOwned += c.ServiceFee;
	}
	fclose(fcustomer);
	printf("\nThe Total Collected Money: %d\n\n", TotalOwned);
}
/*View All Invoices Records*/
void ViewInvoicesRecords() {
	FILE* fcustomer = fopen("Customer.txt", "r");//open the file//
	printf("\n\n<*<>*><*<>*>   Invoices Records Details   <*<>*><*<>*>\n\n");
	while (fread(&c, sizeof(c), 1, fcustomer)) {

		printf("\nInvoice Number      : %s", c.InvoiceNo);
		printf("\nCustomer ID         : %s", c.ID);
		printf("\nCustomer Name       : %s", c.name);
		printf("\nCustomer Phone No   : %s", c.phone);
		printf("\nCar Registration NO : %s", c.CarRegistrationNO);
		printf("\nService Date        : %s", c.ServiceDate);
		printf("\nService taken       : %s", c.ServiceTaken);
		printf("\nService Type        : %s", c.ServiceType);
		printf("\nService Fee         : %d", c.ServiceFee);
		printf("\n____________________________________________________\n");
	}
	fclose(fcustomer);
}
