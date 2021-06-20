//Name: Abdulmalek Aldhafer
//GitHub username : akaldhafer
//Email : Ak_aldhafer@hotmail.com
//System title : Course Package Management System 


#include <stdio.h>   /*header files */
#include <stdlib.h>  
#include <windows.h> 
#pragma warning (disable: 4996) /*disable scanf error*/


/*declare the functions*/
char choice;
void CreateVisit();
void DisplayVisit();
void SearchVisit();
void DisplayPayment();
void UpdateService();
void UpdatePayment();
void smenu();
void LogUp();
void LogIn();
int main();

/*staff variables*/
struct Staff
{
	char sname[20];
	char susername[20];
	char spassword[20];
}s;

/*customer recodes variables*/
struct Customer {

	char VisitID[20];
	char VisitDate[20]; 
	char cname[20];
	char cphone[20];
	char ServiceType[50];
	float ServiceCost; 
	float PaidAmount; 
	float UnpaidAmount;
}c;
/*The service types*/
char s1[50] = "Remove virus, malware or spyware";/*service type*/
char s2[50] = "Troubleshoot and fix a computer running slow";
char s3[50] = "Laptop screen replacement";
char s4[50] = "Laptop keyboard replacement";
char s5[50] = "Laptop battery replacement";
char s6[50] = "Operating System Format and Installation";
char s7[50] = "Data backup and recovery";
char s8[50] = "Internet connectivity issues";
/**/
void CreateVisit() {
	FILE* fpr = fopen("Customer.txt", "a");
	char option;
	while (1)
	{
		printf("\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
			"\n                            Create New Visit Record Menu       \n"
			"\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
			"\n|No|     Service Type                           |Needed days|Normal Fee|Urgent Fee|"
			"\n|1.| Remove virus, malware or spyware           |2 days     |    30RM  |  50RM    |"
			"\n|2.| Troubleshot and fix computer running slow  |2 days     |    40RM  |  70RM    |"
			"\n|3.| Laptop screen replacement                  |3 days     |   380RM  | 430RM    |"
			"\n|4.| Laptop keyboard replacement                |2 days     |   160RM  | 200RM    |"
			"\n|5.| Laptop battery replacement                 |1 day      |   180RM  | 210RM    |"
			"\n|6.| Operating System Format and Installation   |2 days     |    50RM  |  80RM    |"
			"\n|7.| Data backup and recovery                   |2 days     |   100RM  | 150RM    |"
			"\n|8.| Internet connectivity issues               |1 day      |    50RM  |  75RM    |"
			"\n|9.| Return"
			"\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n");
		printf("\nChoose One Option: "); scanf("%s", &choice);
		if (choice == '1') {
			strcpy(c.ServiceType, s1); /*String copy function*/
			printf("\n1. Normal (30Rm)      2. Urgent (50 Rm)");
			printf("\nChoose Service Fee: ");scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 30;}
			else {
				c.ServiceCost = 50;}
		}
		else if (choice == '2') {
			strcpy(c.ServiceType, s2); /*String copy function*/
			printf("\n1. Normal (40Rm)      2. Urgent (70 Rm)");
			printf("\nChoose Service Fee: "); scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 40;}
			else {
				c.ServiceCost = 70;}
		}
		else if (choice == '3') {
			strcpy(c.ServiceType, s3); /*String copy function*/
			printf("\n1. Normal (380Rm)      2. Urgent (430 Rm)");
			printf("\nChoose Service Fee: "); scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 380;}
			else {
				c.ServiceCost = 430;}
		}
		else if (choice == '4') {
			strcpy(c.ServiceType, s4); /*String copy function*/
			printf("\n1. Normal (160Rm)      2. Urgent (200 Rm)");
			printf("\nChoose Service Fee: "); scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 160;}
			else {
				c.ServiceCost = 200;}
		}
		else if (choice == '5') {
			strcpy(c.ServiceType, s5); /*String copy function*/
			printf("\n1. Normal (180Rm)      2. Urgent (210 Rm)");
			printf("\nChoose Service Fee: "); scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 180;}
			else {
				c.ServiceCost = 210;}
		}
		else if (choice == '6') {
			strcpy(c.ServiceType, s6); /*String copy function*/
			printf("\n1. Normal (50Rm)      2. Urgent (80 Rm)");
			printf("\nChoose Service Fee: "); scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 50;}
			else {
				c.ServiceCost = 80;}
		}
		else if (choice == '7') {
			strcpy(c.ServiceType, s7); /*String copy function*/
			printf("\n1. Normal (100Rm)      2. Urgent (150 Rm)");
			printf("\nChoose Service Fee: "); scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 100;}
			else {
				c.ServiceCost = 150;}
		}
		else if (choice == '8') {
			strcpy(c.ServiceType, s8); /*String copy function*/
			printf("\n1. Normal (50Rm)      2. Urgent (75 Rm)");
			printf("\nChoose Service Fee: "); scanf("%s", &option);
			if (option == '1') {
				c.ServiceCost = 50;}
			else {
				c.ServiceCost = 75;}
		}
		else if (choice == '9') {
			system("CLS");
			smenu();}
		else {
			printf("\n     Incorrect choice, Please retry again!!!\n");}
		printf("Enter visit ID             : "); scanf("%s", &c.VisitID);
		printf("Enter visit Date           : "); scanf("%s", &c.VisitDate);
		printf("Enter customer name        : "); scanf("%s", &c.cname);
		printf("Enter customer phone number: "); scanf("%s", &c.cphone);
		printf("\nThe Total Payment          : %.2f", c.ServiceCost);
		printf("\nEnter the payment          : "); scanf("%f", &c.PaidAmount);
		c.UnpaidAmount = c.ServiceCost - c.PaidAmount;
		printf("\nThe Unpaid Amount          : %.2f", c.UnpaidAmount);
		printf("\n\n         <**>          The Record Saved Successfully :)        <**>\n");
		fwrite(&c, sizeof(c), 1, fpr); /*function to write the record into the file*/
		fclose(fpr); /*close the file*/
		system("pause");
		system("CLS");
	}
}
/* Display  Visit function*/
void DisplayVisit() {
	FILE* Visit = fopen("Customer.txt", "r"); 
	if (Visit == NULL) {
		printf("\n There is no record yet...\n");
	}
	else {
		printf("\n                  The created records\n");
		while (fread(&c, sizeof(c), 1, Visit)) { /*while the fread is reading the visit file*/
			printf("\nVisit ID         : %s", c.VisitID);  /*all visit recodes will be printed*/
			printf("\nVisit Date       : %s", c.VisitDate);
			printf("\nCustomer Name    : %s", c.cname);
			printf("\nCustomer Phone No: %s", c.cphone);
			printf("\nService Type     : %s", c.ServiceType);
			printf("\nService Fees     : %.2f RM", c.ServiceCost);
			printf("\nPaid Amount      : %.2f RM", c.PaidAmount);
			printf("\nUnpaid Amount    : %.2f RM\n", c.UnpaidAmount);
		}
		fclose(Visit);
	}
	return;
}
/*Search Visit function*/
void SearchVisit() {
	char Sname[20];
	FILE* fVisit = fopen("Customer.txt", "r");
	printf("\nEnter customer First name: "); scanf("%s", &Sname);
	if (fVisit == NULL) {
		printf("\n There is no record yet...\n");
	}
	else {
		while (fread(&c, sizeof(c), 1, fVisit)) { /*Display the customer details*/
			if (strcmpi(c.cname, Sname) == 0) {//strcmpi function for compare two string
				printf("\nThe Customer Details: \n");
				printf("\nVisit ID         : %s", c.VisitID);  
				printf("\nVisit Date       : %s", c.VisitDate);
				printf("\nCustomer Name    : %s", c.cname);
				printf("\nCustomer Phone No: %s", c.cphone);
				printf("\nService Type     : %s", c.ServiceType);
				printf("\nService Fees     : %.2f RM", c.ServiceCost);
				printf("\nPaid Amount      : %.2f RM", c.PaidAmount);
				printf("\nUnpaid Amount    : %.2f RM\n", c.UnpaidAmount);
			}
		}
		fclose(fVisit);
	}
	return;
}
/*Display Payment paid and unpaid from all records*/
void DisplayPayment() {
	float TotalUnpaid = 0;
	float TotalPaid = 0;
	FILE* Visit = fopen("Customer.txt", "r");
	printf("\n               Display Payment Page\n");
	if (Visit == NULL) {
		printf("\n There is no record yet...\n");
	}
	else {
		while (fread(&c, sizeof(c), 1, Visit)) {
			TotalPaid += c.PaidAmount;//calculate the paid amount from each record
			TotalUnpaid += c.UnpaidAmount; //calculate the unpaid amount from each record
		}
		printf("\nTotal payment made and total unpaid balance for all visits: \n\n");
		printf("\nTotal Paid Amount: %.2f RM", TotalPaid);
		printf("\nTotal Unpaid Amount: %.2f RM\n\n\n", TotalUnpaid);
	}
	fclose(Visit);
	return; 
}
/*Update service type function*/ 
void UpdateService() {
	system("cls");
	char name[20], option;
	FILE* Visit = fopen("Customer.txt", "r"); /*opening the file on reading mode*/
	FILE* fpr;
	FILE* ftemp;
	printf("\n              Update Service Type Page\n\n");
	if (Visit == NULL) {
		printf("\n There is no record yet...\n");
	}
	else {
		printf("\nEnter customer first name: "); scanf("%s", &name);
		while (fread(&c, sizeof(c), 1, Visit)) {
			if (strcmpi(c.cname, name) == 0) {//searching the needed record
				fpr = fopen("Customer.txt", "r");
				ftemp = fopen("FileTemp.txt", "w");
				while (fread(&c, sizeof(c), 1, fpr)) {
					if (strcmpi(c.cname, name) != 0) {
						fwrite(&c, sizeof(c), 1, ftemp); //copy the records from the old one to the temp file
					}
					else {
						printf("\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
							"\n                              UPDATE SERVICE TYPE      \n"
							"\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
							"\n|No|     Service Type                           |Needed days|Normal Fee|Urgent Fee|"
							"\n|1.| Remove virus, malware or spyware           |2 days     |    30RM  |  50RM    |"
							"\n|2.| Troubleshot and fix computer running slow  |2 days     |    40RM  |  70RM    |"
							"\n|3.| Laptop screen replacement                  |3 days     |   380RM  | 430RM    |"
							"\n|4.| Laptop keyboard replacement                |2 days     |   160RM  | 200RM    |"
							"\n|5.| Laptop battery replacement                 |1 day      |   180RM  | 210RM    |"
							"\n|6.| Operating System Format and Installation   |2 days     |    50RM  |  80RM    |"
							"\n|7.| Data backup and recovery                   |2 days     |   100RM  | 150RM    |"
							"\n|8.| Internet connectivity issues               |1 day      |    50RM  |  75RM    |"
							"\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n");
						printf("\nChoose One Option: "); scanf("%s", &choice);
						if (choice == '1') {
							strcpy(c.ServiceType, s1); /*String copy function*/
							printf("\n1. Normal (30Rm)      2. Urgent (50 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 30;
							}
							else {
								c.ServiceCost = 50;
							}
						}
						else if (choice == '2') {
							strcpy(c.ServiceType, s2); /*String copy function*/
							printf("\n1. Normal (40Rm)      2. Urgent (70 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 40;
							}
							else {
								c.ServiceCost = 70;
							}
						}
						else if (choice == '3') {
							strcpy(c.ServiceType, s3); /*String copy function*/
							printf("\n1. Normal (380Rm)      2. Urgent (430 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 380;
							}
							else {
								c.ServiceCost = 430;
							}
						}
						else if (choice == '4') {
							strcpy(c.ServiceType, s4); /*String copy function*/
							printf("\n1. Normal (160Rm)      2. Urgent (200 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 160;
							}
							else {
								c.ServiceCost = 200;
							}
						}
						else if (choice == '5') {
							strcpy(c.ServiceType, s5); /*String copy function*/
							printf("\n1. Normal (180Rm)      2. Urgent (210 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 180;
							}
							else {
								c.ServiceCost = 210;
							}
						}
						else if (choice == '6') {
							strcpy(c.ServiceType, s6); /*String copy function*/
							printf("\n1. Normal (50Rm)      2. Urgent (80 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 50;
							}
							else {
								c.ServiceCost = 80;
							}
						}
						else if (choice == '7') {
							strcpy(c.ServiceType, s7); /*String copy function*/
							printf("\n1. Normal (100Rm)      2. Urgent (150 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 100;
							}
							else {
								c.ServiceCost = 150;
							}
						}
						else if (choice == '8') {
							strcpy(c.ServiceType, s8); /*String copy function*/
							printf("\n1. Normal (50Rm)      2. Urgent (75 Rm)");
							printf("\nChoose Service Fee: "); scanf("%s", &option);
							if (option == '1') {
								c.ServiceCost = 50;
							}
							else {
								c.ServiceCost = 75;
							}
						}
						else {
							printf("\n     Incorrect choice, Please retry again!!!\n");
							UpdateService();
						}
						printf("\nThe Total Payment          : %.2f", c.ServiceCost);
						printf("\nEnter the payment          : "); scanf("%f", &c.PaidAmount);
						c.UnpaidAmount = c.ServiceCost - c.PaidAmount;
						printf("\nThe Unpaid Amount          : %.2f", c.UnpaidAmount);
						printf("\n\n         <**>          The Record Updated Successfully :)        <**>\n");
						fwrite(&c, sizeof(c), 1, ftemp); //copy the records from the old one to the temp file
					}
				}
				fclose(fpr); // close both files
				fclose(ftemp);
				fpr = fopen("Customer.txt", "w");
				ftemp = fopen("FileTemp.txt", "r");
				while (fread(&c, sizeof(c), 1, ftemp))
					fwrite(&c, sizeof(c), 1, fpr);//copy the records from the temp file to the old one
				fclose(ftemp); /*close both files*/
				fclose(fpr);
			}
		}
	}
	fclose(Visit);
	system("pause");
	system("cls");
	smenu();
	return;
}
/*Update payment function*/
void UpdatePayment() {
	system("cls");
	char name[20];
	float NewPayment;
	FILE* Visit = fopen("Customer.txt", "r"); /*opening the file on reading mode*/
	FILE* fpr;
	FILE* ftemp;
	printf("\n              Update Payment Page\n\n");
	if (Visit ==NULL) {
		printf("\n There is no record yet...\n");
	}
	else {
		printf("\nEnter customer first name: "); scanf("%s", &name);
		while (fread(&c, sizeof(c), 1, Visit)) {
			if (strcmpi(c.cname, name) == 0) {//searching the needed record
				fpr = fopen("Customer.txt", "r");
				ftemp = fopen("FileTemp.txt", "w");
				while (fread(&c, sizeof(c), 1, fpr)) {
					if (strcmpi(c.cname, name) != 0) {
						fwrite(&c, sizeof(c), 1, ftemp); //copy the records from the old one to the temp file
					}
					else {
						printf("\nThe service fees : %.2f RM", c.ServiceCost);
						printf("\nThe total paid   : %.2f RM", c.PaidAmount);
						printf("\nThe due payment  : %.2f RM", c.UnpaidAmount);
						printf("\nEnter the payment: ");
						scanf("%f", &NewPayment);
						c.UnpaidAmount = c.UnpaidAmount - NewPayment;
						c.PaidAmount = c.PaidAmount + NewPayment;
						printf("\n\n    <**>          The Record Updated Successfully :)        <**>\n");
						fwrite(&c, sizeof(c), 1, ftemp); //copy the records from the old one to the temp file
					}
				}
				fclose(fpr); // close both files
				fclose(ftemp);
				fpr = fopen("Customer.txt", "w");
				ftemp = fopen("FileTemp.txt", "r");
				while (fread(&c, sizeof(c), 1, ftemp))
					fwrite(&c, sizeof(c), 1, fpr);//copy the records from the temp file to the old one
				fclose(ftemp); /*close both files*/
				fclose(fpr);
			}
		}
	}
	fclose(Visit);
	return;
}
/*Delete visit record function*/
void DeleteVisit() {
	char name[20];
	FILE* Visit = fopen("Customer.txt", "r"); /*opening the file on reading mode*/
	FILE* fpr;
	FILE* ftemp;
	printf("\n              Delete Visit Record Page\n\n");
	if (Visit == NULL) {
		printf("\n There is no record yet...\n");}
	else {
		printf("\nEnter customer first name: "); scanf("%s", &name);
		while (fread(&c, sizeof(c), 1, Visit)) {
			if (strcmpi(c.cname, name) == 0) {//searching the needed record
				fpr = fopen("Customer.txt", "r");
				ftemp = fopen("FileTemp.txt", "w");
				while (fread(&c, sizeof(c), 1, fpr))
					if (strcmpi(c.cname, name) != 0)
						fwrite(&c, sizeof(c), 1, ftemp); //copy the records from the old one to the temp file
				fclose(fpr); // close both files
				fclose(ftemp);
				fpr = fopen("Customer.txt", "w");
				ftemp = fopen("FileTemp.txt", "r");
				while (fread(&c, sizeof(c), 1, ftemp))
					fwrite(&c, sizeof(c), 1, fpr);//copy the records from the temp file to the old one
				fclose(ftemp); /*close both files*/
				fclose(fpr);
				printf("\n              The Record Deleted       \n");

			}
		}
	}
	fclose(Visit);
	return;
}
/*Staff menu*/
void smenu() {
	do
	{
		printf("\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
			"\n<*>                        The Available Services                   <*>\n"
			"\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
		    "\n<*>a). Create new visit              b). Update visit record        <*>\n"
		    "\n<*>c). Search visit                  d). Display all visits records <*>\n"
		    "\n<*>e). Delete visit record           f). Log out                    <*>\n"
		    "\n<*>g). Display total paid and unpaid amount from all visits         <*>\n");
		printf("\n<*> Select one option: "); scanf("%s", &choice);
		switch (choice)
		{
		case 'a':
		case 'A':
			system("CLS");
			CreateVisit();
			break;
		case 'b':
		case 'B':
			printf("\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
				"\n<*>                        Update Visit Record                      <*>\n"
				"\n<*><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><*>\n"
				"\n<*>1). Update service type                2). Update payment        <*>\n"
				"\n<*>3). Return                                                       <*>\n");
			printf("\n<*> Select one option: "); scanf("%s", &choice);
			if (choice =='1') {
				UpdateService();
			}
			else if(choice =='2') {
				UpdatePayment();
			}
			else{
				printf("\n<><><><><><><><<><><><><><><><><><><><><><><><><><><><><><><><>><><\n");
			}
			break;
		case 'c':
		case 'C':
			system("CLS");
			SearchVisit();
			break;
		case 'd':
		case 'D':
			system("CLS");
			DisplayVisit();
			break;
		case 'e':
		case 'E':
			system("CLS");
			DeleteVisit();
			break;
		case 'f':
		case 'F':
			system("CLS");
			main();
			break;
		case 'g':
		case 'G':
			system("CLS");
			DisplayPayment();
			break;
		default:
			printf("\n     Incorrect choice, Please retry again!!!\n");
			break;
		}
		system("pause");
		system("CLS");

	} while (1);
}
/*log up function*/
void LogUp()
{
	FILE* fstaff = fopen("Staff.txt", "a");/*open staff File to append*/
	printf("\n<><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><>\n"
	       "\n<>                          Sign up page                           <>\n"
	       "\n<><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><>\n");
	printf("\nEnter staff first name: ");scanf("%s", &s.sname);/*read staff name*/
	printf("\nCreate username: ");scanf("%s", &s.susername);/*read staff username*/
	printf("\nCreate password: "); scanf("%s", &s.spassword);/*read staff password*/
	fwrite(&s, sizeof(s), 1, fstaff); /*wirting the record into the staff file*/
	fclose(fstaff); /*Close the File*/
	printf("\n          You registered successfully!!!...\n");
}
/*log in function*/
void LogIn() {
	FILE* fstaff = fopen("Staff.txt","r");
	char username[20], password[20];
	printf("\n<><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><>\n"
		"\n<>                          Sign in page                           <>\n"
		"\n<><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><>\n");
	if (fstaff == NULL) {
		printf("\n        Sign Up First !!!\n");}
	else {
		printf("\n   Enter the username: "); scanf("%s", &username);/*read username*/
		printf("\n   Enter the password: "); scanf("%s", &password);/*read password*/
		while (fread(&s, sizeof(s), 1, fstaff)) {/*reading the record from the staff file*/
			if ((strcmp(s.susername, username) == 0) && (strcmp(s.spassword, password) == 0)) {
				system("CLS");
				printf("\n            <*><*>><     Welcome Back %s    ><<*><*>\n", s.sname);
				fclose(fstaff);
				smenu();}/*call staff menu*/
		}
		printf("\n     Incorrect username or password !!!\n");
		system("pause");
		system("CLS");
		LogIn();
	}
	return;
}

/*the main function*/
int main() {
	FILE* file1 = fopen("Customer.txt","a");
	FILE* file2 = fopen("Staff.txt", "a");
	fclose(file1);
	fclose(file2);
	system("color 2");
	char option;
	do{
		printf("\n<><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><>\n");
		printf("\n                  Course Package Management System     \n");
		printf("\n<><<<<<><<><><><><><><><><><><><><><><><><><><><><><><><><><<>>>>>><>\n");
		printf("1. Login\t2. Log up\t3. Quit");
		printf("\nEnter one option: ");
		scanf("%s", &option);
		if (option == '1') {
			LogIn();
		}
		else if (option =='2') {
			LogUp();
		}
		else if (option =='3') {
			printf("\n\n        Thank You For Using Our Systsem !!\n\n");
			system("pause");
			exit(1);
			break;
		}
		else {
			printf("\n /*/ You entered a wrong option ..!! /*/\n");
		}
		system("pause");
		system("CLS");
	} while (1);

	return 0;
}
