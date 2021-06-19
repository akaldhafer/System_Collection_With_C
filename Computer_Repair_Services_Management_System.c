//Name: Abdulmalek Aldhafer
//GitHub username : akaldhafer
//Email : Ak_aldhafer@hotmail.com
//System title : Computer/Laptop Repair Services Management System 


#include <stdio.h>   /*/ Header file for simple functions such as input and output   /*/
#include <stdlib.h>  /*/ header defines four variable types, several macros, and; various functions for performing general functions/*/
#include <windows.h> /*/ Header file to use windows functions like cls and pause   /*/
#pragma warning (disable: 4996) /*/ To disable warning for using scanf and scanf_s/*/


/***********************************************************************************/
char v1[50] = "Remove virus, malware or spyware";
char v2[50] = "Troubleshoot and fix a computer running slow"; /*The database for the service type*/
char v3[50] = "Laptop screen replacement";
char v4[50] = "Laptop keyboard replacement";
char v5[50] = "Laptop battery replacement";
char v6[50] = "Operating System Format and Installation";
char v7[50] = "Data backup and recovery";
char v8[50] = "Internet connectivity issues";
/***********************************************************************************/
char choice;
char Cname[20];
void logIn();
void SignUp();
void MenuPage();                       /*Declare the functoins*/
void adminMenu();
void service1();
void service2();
void service3();
void service4();
void service5();
void service6();
void service7();
void service8();
void visitdetail();
void NewVisit();
void viewVisit();
void searchVisit();
void All_payment();
void cancelVisit();
void updateVisit();
void updatePayment();
void updateService();
int main();
/***********************************************************************************/
struct Admin { // declare admin variables 
	char Username[20];
	char Password[20];
}a;
/***********************************************************************************/
struct Visit
{ /*Declare visit variables*/
	char VID[20];/*visit ID*/               
	char Vdate[20]; /*visit date*/ 
	char CNAME[20];/*customer name*/ 
	char CPHONE[20];/*customer phone no*/ 
	char service_needed[50];/*the service needed*/ 
	float service_fee; /*service fees*/ 
	float payment_made; /*payment made*/ 
	float unpaid;/*unpaid balance*/ 
}v;
/***********************************************************************************/
void service1() {
	FILE* Visit = fopen("visit.txt", "a"); /*open the file in adding mode*/
	strcpy(v.service_needed, v1); /*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (30Rm)      2. Urgent (50 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {		
		v.service_fee = 30;
	}
	else if (choice == '2') {
		v.service_fee = 50;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service1();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit); /*function to write the data to the file*/
	fclose(Visit); /*close the file*/
	return; 
}
/***********************************************************************************/
void service2() {
	FILE* Visit = fopen("visit.txt", "a");/*open the file in adding mode*/
	strcpy(v.service_needed, v2);/*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (40Rm)      2. Urgent (70 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {
		v.service_fee = 40;
	}
	else if (choice == '2') {
		v.service_fee = 70;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service2();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit);/*function to write the data to the file*/
	fclose(Visit);
	return;
}
/***********************************************************************************/
void service3() {
	FILE* Visit = fopen("visit.txt", "a");/*open the file in adding mode*/
	strcpy(v.service_needed, v3);/*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (380Rm)      2. Urgent (430 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {
		v.service_fee = 380;
	}
	else if (choice == '2') {
		v.service_fee = 430;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service3();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit);/*function to write the data to the file*/
	fclose(Visit);
	return;
}
/***********************************************************************************/
void service4() {
	FILE* Visit = fopen("visit.txt", "a");/*open the file in adding mode*/
	strcpy(v.service_needed, v4);/*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (160Rm)      2. Urgent (200 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {
		v.service_fee = 160;
	}
	else if (choice == '2') {
		v.service_fee = 200;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service4();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit);/*function to write the data to the file*/
	fclose(Visit);
	return;
}
/***********************************************************************************/
void service5() {
	FILE* Visit = fopen("visit.txt", "a");/*open the file in adding mode*/
	strcpy(v.service_needed, v5);/*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (180Rm)      2. Urgent (210 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {
		v.service_fee = 180;
	}
	else if (choice == '2') {
		v.service_fee = 210;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service5();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit);/*function to write the data to the file*/
	fclose(Visit);
	return;
}
/***********************************************************************************/
void service6() {
	FILE* Visit = fopen("visit.txt", "a");/*open the file in adding mode*/
	strcpy(v.service_needed, v6);/*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (50Rm)      2. Urgent (80 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {
		v.service_fee = 50;
	}
	else if (choice == '2') {
		v.service_fee = 80;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service6();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit);/*function to write the data to the file*/
	fclose(Visit);
	return;
}
/***********************************************************************************/
void service7() {
	FILE* Visit = fopen("visit.txt", "a");/*open the file in adding mode*/
	strcpy(v.service_needed, v7);/*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (100Rm)      2. Urgent (150 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {
		v.service_fee = 100;
	}
	else if (choice == '2') {
		v.service_fee = 150;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service7();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit);/*function to write the data to the file*/
	fclose(Visit);
	return;
}
/***********************************************************************************/
void service8() {
	FILE* Visit = fopen("visit.txt", "a");/*open the file in adding mode*/
	strcpy(v.service_needed, v8);/*function to copy the string*/
	printf("\nChoose Service fee: \n");
	printf("1. Normal (50Rm)      2. Urgent (75 Rm)    3. Back to service menu");
	printf("\nEnter your choice: ");
	scanf("%s", &choice);
	if (choice == '1') {
		v.service_fee = 50;
	}
	else if (choice == '2') {
		v.service_fee = 75;
	}
	else if (choice == '3') {
		system("pause");
		system("CLS");
		NewVisit();
	}
	else {
		system("pause");
		system("CLS");
		service8();
	}
	visitdetail();
	printf("The total payment: %.2f", v.service_fee);
	printf("\nEnter the payment: ");
	scanf("%f", &v.payment_made);
	v.unpaid = v.service_fee - v.payment_made;
	printf("Due payment: %.2f", v.unpaid);
	printf("\n------          saving the new recode.....          -----\n");
	fwrite(&v, sizeof(v), 1, Visit);/*function to write the data to the file*/
	fclose(Visit);
	return;
}
/***********************************************************************************/
void viewVisit() {
	FILE* Visit = fopen("visit.txt", "r"); /*opening the file on reading mode*/
	printf("\n     These are all the visit recodes inside the database\n");
	while (fread(&v, sizeof(v), 1, Visit)) { /*while the fread is reading the visit file*/
		printf("\nVisit ID         : %s", v.VID);  /*all visit recodes will be printed*/
		printf("\nVisit Date       : %s", v.Vdate);
		printf("\nCustomer Name    : %s", v.CNAME);
		printf("\nCustomer Phone No: %s", v.CPHONE);
		printf("\nService type     : %s", v.service_needed);
		printf("\nService fees     : %.2f RM", v.service_fee);
		printf("\nDue payment      : %.2f RM", v.unpaid);
		printf("\nPayment made     : %.2f RM\n", v.payment_made);
	}
	if (Visit == NULL) {
		printf("\n !!The file still empty...\n");
	}
	fclose(Visit);
	return;

}
/***********************************************************************************/
void searchVisit() {
	char name[20];
	FILE* Visit = fopen("visit.txt", "r"); /*opening the file on reading mode*/
	getchar();
	printf("\nEnter customer name: ");
	gets(name); /*get the customer name*/
	while (fread(&v, sizeof(v), 1, Visit)) { /*Display the visit recode*/
		if (strcmpi(v.CNAME, name) == 0) {/*if the given name is equal to any name inside the file*/
			printf("\nThese are all the availalbe details: \n");
			printf("\nVisit ID         : %s", v.VID);  /*all details of that name will be displayed*/
			printf("\nVisit Date       : %s", v.Vdate);
			printf("\nCustomer Name    : %s", v.CNAME);
			printf("\nCustomer Phone No: %s", v.CPHONE);
			printf("\nService type     : %s", v.service_needed);
			printf("\nService fees     : %.2f RM", v.service_fee);
			printf("\nDue payment      : %.2f RM", v.unpaid);
			printf("\nPayment made     : %.2f RM\n", v.payment_made);
		}
	}
	if (Visit == NULL) {
		printf("\n !!The file still empty...\n");
	}
	fclose(Visit);
	return;
}
/***********************************************************************************/
void All_payment() {
	float total_unpaid = 0;
	float total_paid = 0;
	FILE* Visit = fopen("visit.txt", "r"); /*opening the file on reading mode*/
	if (Visit == NULL) {
		printf("\n !!The file still empty...\n");
	}
	while (fread(&v, sizeof(v), 1, Visit)) { /*Display the visit recode*/
		total_unpaid += v.unpaid; /* add the unpaid payment of each visit to the total_unpaid variable*/
		total_paid += v.payment_made;/* add the payment_made of each visit to the total_paid variable*/
	}
	printf("\nTotal payment made and total unpaid balance for all visits: \n\n");
	printf("\nTotal payment made: %.2f RM", total_paid);
	printf("\nTotal payment unpaid: %.2f RM\n\n\n", total_unpaid);
	fclose(Visit);
	return; /*returning to the admin menu*/
}
/***********************************************************************************/
void visitdetail() {
	printf("Enter visit ID: ");
	scanf("%s", &v.VID);
	printf("Enter visit Date: ");
	scanf("%s", &v.Vdate);
	getchar();
	printf("Enter customer name: ");
	gets(v.CNAME);
	printf("Enter customer phone No: ");
	scanf("%s", &v.CPHONE);
	return;
}
/***********************************************************************************/
void NewVisit() {
	while (1) {
		printf("\n##--------------------------------------------------------------##\n");
		printf("\n                         Service Menu       \n");
		printf("\n##--------------------------------------------------------------##\n");
		printf("\nNo|     Service Type                                      |Needed days");
		printf("\n1.| Remove virus, malware or spyware                      |2 days");
		printf("\n2.| Troubleshot and fix computer running slow             |2 days");
		printf("\n3.| Laptop screen replacement                             |3 days");
		printf("\n4.| Laptop keyboard replacement                           |2 days");
		printf("\n5.| Laptop battery replacement                            |1 day ");
		printf("\n6.| Operating System Format and Installation              |2 days");
		printf("\n7.| Data backup and recovery                              |2 days");
		printf("\n8.| Internet connectivity issues                          |1 days");
		printf("\n9.| Back to the admin menu");
		printf("\nEnter one choice: ");
		scanf("%s", &choice);
		switch (choice)
		{
		case'1':
			service1();
			break;
		case'2':
			service2();
			break;
		case'3':
			service3();
			break;
		case'4':
			service4();
			break;
		case'5':
			service5();
			break;
		case'6':
			service6();
			break;
		case'7':
			service7();
			break;
		case'8':
			service8();
			break;
		case'9':
			system("CLS");
			adminMenu();
			break;
		default:
			printf(" /*/ You entered a wrong option ..!! /*/");
			break;
		}
		system("pause");
		system("CLS");
	}
	return;
}
/***********************************************************************************/
void updateService() {
	FILE* Visit = fopen("visit.txt", "r"); /*opening the file on reading mode*/
	FILE* forginal;
	FILE* fnew;
	getchar();
	printf("\nEnter customer name: ");
	gets(Cname);
	while (fread(&v, sizeof(v), 1, Visit)) { /*Display the visit recode*/
		if (strcmpi(v.CNAME, Cname) == 0) {
			forginal = fopen("visit.txt", "r");
			fnew = fopen("visitUpdate.txt", "w");
			while (fread(&v, sizeof(v), 1, forginal)) {// fread my orginal file 
				if (strcmpi(v.CNAME, Cname) != 0) // if the given name is not equal the name in the file 
					fwrite(&v, sizeof(v), 1, fnew); //  write the visit details to the new file
				else {
					printf("\nNo|     Service Type                                      |Needed days");
					printf("\n1.| Remove virus, malware or spyware                      |2 days");
					printf("\n2.| Troubleshot and fix computer running slow             |2 days");
					printf("\n3.| Laptop screen replacement                             |3 days");
					printf("\n4.| Laptop keyboard replacement                           |2 days");
					printf("\n5.| Laptop battery replacement                            |1 day ");
					printf("\n6.| Operating System Format and Installation              |2 days");
					printf("\n7.| Data backup and recovery                              |2 days");
					printf("\n8.| Internet connectivity issues                          |1 days");
					printf("\nChoose the needed service: ");
					scanf("%s", &choice);
					if (choice == '1') {
						strcpy(v.service_needed, v1); /*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (30Rm)      2. Urgent (50 Rm)    3. Back to service menu");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 30;
						}
						else if (choice == '2') {
							v.service_fee = 50;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else if (choice == '2') {
						strcpy(v.service_needed, v2);/*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (40Rm)      2. Urgent (70 Rm)    3. Back to service menu");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 40;
						}
						else if (choice == '2') {
							v.service_fee = 70;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else if (choice == '3') {
						strcpy(v.service_needed, v3);/*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (380Rm)      2. Urgent (430 Rm)    3. Back to service menu");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 380;
						}
						else if (choice == '2') {
							v.service_fee = 430;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else if (choice == '4') {
						strcpy(v.service_needed, v4);/*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (160Rm)      2. Urgent (200 Rm)    3. Back to service menu");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 160;
						}
						else if (choice == '2') {
							v.service_fee = 200;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else if (choice == '5') {
						strcpy(v.service_needed, v5);/*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (180Rm)      2. Urgent (210 Rm)    3. Back to service menu");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 180;
						}
						else if (choice == '2') {
							v.service_fee = 210;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else if (choice == '6') {
						strcpy(v.service_needed, v6);/*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (50Rm)      2. Urgent (80 Rm)    3. Back to service menu");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 50;
						}
						else if (choice == '2') {
							v.service_fee = 80;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else if (choice == '7') {
						strcpy(v.service_needed, v7);/*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (100Rm)      2. Urgent (150 Rm)    3. Back to service menu");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 100;
						}
						else if (choice == '2') {
							v.service_fee = 150;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else if (choice == '8') {
						strcpy(v.service_needed, v8);/*function to copy the string*/
						printf("\nChoose Service fee: \n");
						printf("1. Normal (50Rm)      2. Urgent (75 Rm)");
						printf("\nEnter your choice: ");
						scanf("%s", &choice);
						if (choice == '1') {
							v.service_fee = 50;
						}
						else if (choice == '2') {
							v.service_fee = 75;
						}
						else {
							system("pause");
							system("CLS");
							updateService();
						}
						printf("The total payment: %.2f", v.service_fee);
						printf("\nEnter the payment: ");
						scanf("%f", &v.payment_made);
						v.unpaid = v.service_fee - v.payment_made;
						printf("Due payment: %.2f", v.unpaid);
					}
					else {
						printf("\n<<   Wrong option !!!  >>\n");
						system("pause");
						system("cls");
						updateService();
					}
					fwrite(&v, sizeof(v), 1, fnew); //  write the visit details to the new file
				}
			}
			fclose(forginal); // close both files
			fclose(fnew);
			/*--------------------------------*/
			forginal = fopen("visit.txt", "w"); /*rewriting the file with the updated database */
			fnew = fopen("visitUpdate.txt", "r");/*openning the file in the reading mode to copy the data to the orginal file*/
			while (fread(&v, sizeof(v), 1, fnew))
				fwrite(&v, sizeof(v), 1, forginal);
			fclose(fnew);
			fclose(forginal);
			printf("\n#--#  The visit record updated successfully..!!!  #--#\n");
		}
		

	}
	fclose(Visit);
	return;
}
/***********************************************************************************/
void updatePayment() {
	FILE* Visit = fopen("visit.txt", "r"); /*opening the file on reading mode*/
	FILE* forginal;
	FILE* fnew;
	float pay;
	getchar();
	printf("\nEnter customer name: ");
	gets(Cname);
	while (fread(&v, sizeof(v), 1, Visit)) { /*Display the visit recode*/
		if (strcmpi(v.CNAME, Cname) == 0) {
			forginal = fopen("visit.txt", "r");
			fnew = fopen("visitUpdate.txt", "w");
			while (fread(&v, sizeof(v), 1, forginal)) {// fread my orginal file 
				if (strcmpi(v.CNAME, Cname) != 0) // if the given name is not equal the name in the file 
					fwrite(&v, sizeof(v), 1, fnew); //  write the visit details to the new file
				else {
					printf("\nThe service fees: %.2f", v.service_fee);
					printf("\nThe total paid  : %.2f", v.payment_made);
					printf("\nThe due payment : %.2f", v.unpaid);
					printf("\nEnter the payment: ");
					scanf("%f", &pay);
					v.unpaid -= pay;
					v.payment_made += pay;
					fwrite(&v, sizeof(v), 1, fnew); //  write the visit details to the new file
				}
			}
			fclose(forginal); // close both files
			fclose(fnew);
			/*--------------------------------*/
			forginal = fopen("visit.txt", "w"); /*rewriting the file with the updated database */
			fnew = fopen("visitUpdate.txt", "r");/*openning the file in the reading mode to copy the data to the orginal file*/
			while (fread(&v, sizeof(v), 1, fnew))
				fwrite(&v, sizeof(v), 1, forginal);
			fclose(fnew);
			fclose(forginal);
		}
	}
	fclose(Visit);
	printf("\n#--#  The visit record updated successfully..!!!  #--#\n");
	return;
}
/***********************************************************************************/
void updateVisit() {

	while (1) {
		printf("\n##--------------------------------------------------------------##\n");
		printf("                   Update visit recode Menu                        ");
		printf("\n##--------------------------------------------------------------##\n");
		printf("\nNo|     Update options:                                        |");
		printf("\n1.| Update service type                                        |");
		printf("\n2.| Update payment for existing visit recode                   |");
		printf("\n3.| Back to the admin menu                                     |\n");
		printf("\nEnter one choice: ");
		scanf("%s", &choice);
		switch (choice)
		{
		case'1':
			updateService();
			break;
		case'2':
			updatePayment();
			break;
		case'3':
			system("CLS");
			adminMenu();
			break;
		default:
			printf(" /*/ You entered a wrong option ..!! /*/");
			break;
		}
		system("pause");
		system("CLS");
	}
	return;
}
/***********************************************************************************/
void cancelVisit() {	
	FILE* Visit = fopen("visit.txt", "r"); /*opening the file on reading mode*/
	FILE* forginal; 
	FILE* fnew;
	printf("\nDeleting an existing visit recode:\n\n");
	getchar();
	printf("\nEnter customer name: ");
	gets(Cname);/*getting the customer name to delete the recode*/
	while (fread(&v, sizeof(v), 1, Visit)) { 
		if (strcmpi(v.CNAME, Cname) == 0) {/*comparing the names to find the needed visit recode to be deleted*/
			forginal = fopen("visit.txt", "r"); /*open on reading mode to copy the data into the new file*/
			fnew = fopen("visitUpdate.txt", "w"); /*open on writing mode to write the new date*/
			while (fread(&v, sizeof(v), 1, forginal)) // fread my orginal file 
				if (strcmpi(v.CNAME, Cname) != 0) // if the given name is not equal the name in the file 
					fwrite(&v, sizeof(v), 1, fnew); //  write the visit details to the new file
			fclose(forginal); // close both files
			fclose(fnew);
			forginal = fopen("visit.txt", "w"); /*rewriting the file with the updated database */
			fnew = fopen("visitUpdate.txt", "r");/*openning the file in the reading mode to copy the data to the orginal file*/
			while (fread(&v, sizeof(v), 1, fnew))
				fwrite(&v, sizeof(v), 1, forginal);
			fclose(fnew); /*close both files*/
			fclose(forginal);
		}
	}
	fclose(Visit);
	printf("\n#--#  The visit record deleted successfully..!!!  #--#\n");
	return;
}
/***********************************************************************************/
void logIn() {
	char Password[20]; //declare the variables 
	char Username[20];
	int loginAttempt = 0;//the number of the available attempts 
	FILE* fadmin = fopen("admin.txt", "r");/*open admin File for reading mode*/
	system("cls");/*clean the screen from the old function*/
	printf("\n##--------------------------------------------------------------##\n");
	printf("\n                      Sign in Page                       \n");
	printf("\n##--------------------------------------------------------------##\n");
	while (loginAttempt < 5) //while the number of the available attempts is less 
	{  //than five the user still can retry to login
		fread(&a, sizeof(a), 1, fadmin);/*reading the admin details from the file*/
		printf("\nPlease fill up the username and the password to login\n\n");
		printf("\tEnter The Username: ");
		scanf("%s", &Username); /*getting the admin username and the password*/
		printf("\n\tEnter The Password: ");
		scanf("%s", &Password);
		if (strcmp(Username, a.Username) == 0 && strcmp(Password, a.Password) == 0) 
		{   //strcmp is string compare function
			printf("\n#***#           You Have Successfully Accessed... !        #***#\n\n");
			fclose(fadmin);/*close admin file*/
			system("pause");
			system("cls"); /*clean the screen from the old function*/
			adminMenu(); /*call the adminMenu function*/
			break;
		}
		else
		{
			printf("\n##         Wrong username or password. Please retry..!!      ##\n\n");
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
	return;
}
/***********************************************************************************/
void SignUp()
{
	FILE*fadmin = fopen("admin.txt", "a");/*opening admin File for adding mode*/
	printf("\n##--------------------------------------------------------------##\n");
	printf("\n                      Sign up page                                \n");
	printf("\n##--------------------------------------------------------------##\n");
	printf("\nPlease fill up the needed information: ");
	printf("\nEnter your username: ");/*get admin username*/
	scanf("%s", &a.Username);
	printf("\nEnter your password: "); /*get admin password*/
	scanf("%s", &a.Password);
	fwrite(&a, sizeof(a), 1, fadmin); /*wirting the data into the admin file*/
	fclose(fadmin); /*Close the File*/
	printf("\n/*/You have successfully registered...\n");
	system("pause");
	system("cls");
	MenuPage();/*calling MenuPage function*/
}
/***********************************************************************************/
void adminMenu() {

	while (1) {
		printf("\n##--------------------------------------------------------------##\n");
		printf("\n                          Admin Menu                              \n");
		printf(__DATE__);/*date functoin to display the current date of the device*/
		printf("\n##--------------------------------------------------------------##\n");
		printf("\n1. Make new visit       \t2. Search visit");
		printf("\n3. Update visit details \t4. View all visits");
		printf("\n5. Cancel existing visit\t6. Sign out");
		printf("\n7. Print total payment made and total unpaid balance for all visits.");
		printf("\nEnter one choice: ");
		scanf("%s", &choice);
		switch (choice)
		{
		case'1':
			system("CLS");
			NewVisit();
			break;
		case'2':
			system("CLS");
			searchVisit();
			break;
		case'3':
			system("CLS");
			updateVisit();
			break;
		case'4':
			system("CLS");
			viewVisit();
			break;
		case'5':
			system("CLS");
			cancelVisit();
			break;
		case'6':
			system("CLS");
			MenuPage();
			break;
		case'7':
			system("CLS");
			All_payment();
			break;
		default:
			printf("\n /*/ You entered a wrong option ..!! /*/\n");
			break;
		}
		system("pause");
		system("CLS");
	}
	return;
}
/***********************************************************************************/
void MenuPage() {
	char option;
	while (1) {
		system("CLS");
		printf("\n##--------------------------------------------------------------##\n");
		printf("\n         Computer/Laptop Repair Services Management System        \n");
		printf("\n##--------------------------------------------------------------##\n");
		printf("1. Login\t2.Sign up\t3.Exit");
		printf("\nEnter one option: ");
		scanf("%s", &option);
		switch (option){
		case '1':
			system("CLS");
			logIn();
			break;
		case '2':
			system("CLS");
			SignUp();
			break;
		case '3':
			exit(1);
			break;
		default:
			printf("\n /*/ You entered a wrong option ..!! /*/\n");
			system("pause");
			system("CLS");
			break;
		}
	}
	return;
}
/***********************************************************************************/
int main() {
	/*declare the files*/
	FILE* visit = fopen("visit.txt", "a"); /*visit File*/
	FILE* admin = fopen("admin.txt", "a");/*admin File*/
	fclose(visit); /*Close the File*/
	fclose(admin); /*Close the File*/
	system("color 3"); // function to change the color
	printf("\n      The system is loading....\n\n");
	system("pause"); /*waiting function to wait the user input*/
	for (int i = 0; i < 10; i++)
	{
		Beep(1000, 1000); /* sound function to make a sound while the system is loading*/
		printf("-->-->");
	}
	printf("\n\n                         << Done >>\n\n");
	system("pause"); /*waiting function to wait the user input*/
	MenuPage(); //call the menu page function
	return 0; /* Return fales and close the program*/
}
