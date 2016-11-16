#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#define FileLocationUpdate "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\"
#define FileLocationPLUSlogo "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\logo.txt"
#define FileLocationPLUSUserChoices "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\user_choices.txt"
#define FileLocationPLUSMoneyOptions "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\money_options.txt"
#define FileLocationPLUSmoneyOUTCHOICES "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\moneyout_choices.txt"
#define FileLocationGoodbye "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\goodbye.txt"
#define FileBeginStart "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\BeggingStart.txt"
#define EnterName "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\EnterYourName.txt"
#define EnterSurName "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\EnterYourSurname.txt"
#define EnterPin "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\EnterYourPin.txt"
#define EnterPinAgain "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\EnterYourPinAgain.txt"
#define PinsDontMatch "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\PinsDontMatch.txt"
#define PinsStillDontMatch "C:\\Users\\Wilder Ruiz\\OneDrive\\iPROGRAM\\BANK SIMULATOR by Wilder Ruiz\\BankSimulator_CommonFiles\\Files\\PinsStillDontMatch.txt"


struct bank
{
	char name[100];
	char surname[100];
	int funds;
	int money;
	int totalMoney;
	int tempMoney;
	int money_out;
	int pin;
	char tempPin[100];
	int pin2;
};

int ExtractNumbersFrom(char number[]);
void printFileOnScreen(char location[]);
void makeFileAndStoreNewPIN(char fileAddress[], int newPIN, char name[]);
void addMoneyToAccount(int totalMoney, int newMoneyToAdd);
//int comparePinsAndChangeIt(char your_name[100], char FileLocation[500], int pin1);

int main(){
	system("mode 100,50");
	FILE *fp, *fp1;
	int c, userchoice, i, j, WrngPnCntr, control;
	char buffer[500];
	char tempPin[500], tempPin2[500], name[100];
	char FileLocation[500] = { 0 };
	int tempVar;
	char mainMenu[100];
	WrngPnCntr = 0;
	control = 3;
	struct bank newuser;
	newuser.totalMoney = newuser.pin = i = j = userchoice = WrngPnCntr = tempVar = 0;
	printf("\n  ");
	printf(__DATE__);
The_Begginning:
	system("color 4B");
	printFileOnScreen(FileBeginStart);
	gets_s(buffer, sizeof buffer, stdin);
	userchoice = ExtractNumbersFrom(buffer);
	switch (userchoice)
	{
	case 1:
		system("cls");
		printFileOnScreen(EnterName);
		gets_s(newuser.name, sizeof newuser.name, stdin);
		system("cls");
		printFileOnScreen(EnterSurName);
		gets_s(newuser.surname, sizeof newuser.surname, stdin);
	pin_creator:
		system("cls");
		if ((WrngPnCntr > 0)&&(control < 3)){
			if (control == 0)
			{
				goto The_Begginning;
			}
			else{
				printf("\n\n\n\tYou can try %d more times...\n", control);
			};
		};
		
		printFileOnScreen(EnterPin);
		gets_s(tempPin, sizeof(tempPin), stdin);
		newuser.pin = ExtractNumbersFrom(tempPin);
		system("cls");
		printFileOnScreen(EnterPinAgain);
		gets_s(tempPin2, sizeof(tempPin2), stdin);
		newuser.pin2 = ExtractNumbersFrom(tempPin2);
		//FOR PIN VALIDATION REINITIALIZATION NEEDED.
		if (newuser.pin == newuser.pin2){
			system("cls");
			WrngPnCntr = 0;
		};
		if (newuser.pin != newuser.pin2){
			system("cls");
			printFileOnScreen(PinsDontMatch);
			control--;
			WrngPnCntr++;
			goto pin_creator;
		};

		//CREATING A PERSONALIZED FILE NAME FOR EACH USER
		//START
		strcpy_s(FileLocation, sizeof FileLocation, FileLocationUpdate);
		strcat_s(FileLocation, sizeof FileLocation, newuser.name);
		strcat_s(FileLocation, sizeof FileLocation, ".txt");//NOW FILE "FileLocation" has the address of the file including the user name as filename.
		//END

		fopen_s(&fp, FileLocation, "w+");
		fprintf(fp, "Name : %s\nSurname : %s\nPin : %d\n", newuser.name, newuser.surname, newuser.pin);
		fclose(fp);

		tempVar = newuser.pin;
		strcpy_s(name, sizeof name, newuser.name);
		makeFileAndStoreNewPIN(FileLocationUpdate, tempVar, name);
		system("cls");
		break;
	case 2:
	retry_openning_file :

		system("cls");
						memset(&FileLocation[0], 0, sizeof FileLocation);
						printf("\nPlease enter your Name :\n\n-> ");
						gets_s(newuser.name, sizeof newuser.name, stdin);

						strcpy_s(FileLocation, sizeof FileLocation, FileLocationUpdate);
						strcat_s(FileLocation, sizeof FileLocation, newuser.name);
						strcat_s(FileLocation, sizeof FileLocation, ".txt");
						if (!(fp = fopen(FileLocation, "r"))){
							printf("\nNo records found for \"%s\".\n\nPlease check your spelling.\n\nIf you are still having issues contact Support Center to : \n\n-> 0800121212112\n", newuser.name);
							printf("\nPress [1] to retry, or any key to return to the Main Menu...\n\n->");
							gets_s(mainMenu, sizeof mainMenu, stdin);
							switch (mainMenu[0]){
							case 49:
								system("cls");
								goto retry_openning_file;
								break;
							default:
								system("cls");
								printf("\nReturning to main menu...\n");
								goto The_Begginning;
								break;
							};
							goto retry_openning_file;
						};
						fclose(fp);

						printf("\nEnter your pin number :\n\n-> ");
						gets_s(tempPin, sizeof tempPin, stdin);

						newuser.pin = ExtractNumbersFrom(tempPin);
						memset(&FileLocation[0], 0, sizeof FileLocation);
						strcpy_s(FileLocation, sizeof FileLocation, FileLocationUpdate);
						strcat_s(FileLocation, sizeof FileLocation, newuser.name);
						strcat_s(FileLocation, sizeof FileLocation, "PIN");
						strcat_s(FileLocation, sizeof FileLocation, ".txt");

						if (!(fp = fopen(FileLocation, "r"))){
							printf("No records found, please check your spelling, if still having issues contact support center to : \n0800121212112\n");
							goto retry_openning_file;
						};
						c = 0;
						//READING DOCUMENT FOR PIN NUMBER
						while (fscanf(fp, "%d", &tempVar) != EOF) {
							c = (c * 10) + tempVar;
						}
						fclose(fp);
						//VERIFYING PIN NUMBERS
						if (newuser.pin == c){
							system("cls");
							goto jump;
						}
						else{
							for (i = 3; i > 0; i--){
								system("cls");
								printf("\nWrong pin, %i tries remaining...\n\n-> ", i);
								gets_s(buffer, sizeof buffer, stdin);
								tempVar = ExtractNumbersFrom(buffer);
								if (c == tempVar)
								{
									printf("success pin correct\n");
									goto jump;
								}
							}
							if (i == 0){
								system("cls");
								printf("\n\n                  [Pin entered wrong too many times, returning to main menu...]\n\n");
								goto The_Begginning;
							}
						};

						/*CREATING A FILE TO STORE USER'S BALANCE
						memset(&FileLocation[0], 0, sizeof FileLocation);
						strcpy_s(FileLocation, sizeof FileLocation, FileLocationUpdate);
						strcat_s(FileLocation, sizeof FileLocation, newuser.name);
						strcat_s(FileLocation, sizeof FileLocation, "BALANCE");
						strcat_s(FileLocation, sizeof FileLocation, ".txt");
						fopen_s(&fp1, FileLocation, "r");
						while ((fscanf(fp1, "%d", &tempVar)) != EOF) {
						newuser.totalMoney = (newuser.totalMoney * 10) + tempVar;
						}
						fclose(fp1);
						fopen_s(&fp1, FileLocation, "w++");*/

						goto jump;
	default:
		userchoice = 0;
		system("cls");
		printf("\nInvalid entry, please type [1] if you are a new user or [2] if you already have an account with us\n");
		goto The_Begginning;
	}

jump:
	system("color 4E");
	memset(&buffer[0], 0, sizeof buffer);
	printFileOnScreen(FileLocationPLUSlogo);
	printf("\n\n\t\t\t\t  |  Logged in as : %s  |\n\n", newuser.name);
	printFileOnScreen(FileLocationPLUSUserChoices);
	//system("color 4E");
	gets_s(buffer, sizeof buffer, stdin);
	userchoice = ExtractNumbersFrom(buffer);

	//WAITING FOR USER TO ENTER A VALUE
money_options:

	printFileOnScreen(FileLocationPLUSlogo);
	system("cls");
	switch (userchoice)
	{
		//ADD FUNDS
	case 1:
		system("cls");
		printFileOnScreen(FileLocationPLUSlogo);
		printf("\n\n\t\t\t\t  |  Logged in as : %s  |\n\n", newuser.name);
		printFileOnScreen(FileLocationPLUSMoneyOptions);
		gets_s(buffer, sizeof buffer, stdin);
		newuser.funds = ExtractNumbersFrom(buffer);
		//MONEY OPTIONS TO CHOOSE
		switch (newuser.funds)
		{
		case 1:
			system("cls");
			tempVar = newuser.totalMoney;
			newuser.totalMoney = newuser.totalMoney + 10;
			addMoneyToAccount(tempVar, 10);
			//fprintf(fp, "%d", newuser.totalMoney);
			goto jump;
		case 2:
			system("cls");
			tempVar = newuser.totalMoney;
			newuser.totalMoney = newuser.totalMoney + 20;
			addMoneyToAccount(tempVar, 20);
			//fprintf(fp, "%d", newuser.totalMoney);
			goto jump;
		case 3:
			system("cls");
			tempVar = newuser.totalMoney;
			newuser.totalMoney = newuser.totalMoney + 30;
			addMoneyToAccount(tempVar, 30);
			//fprintf(fp, "%d", newuser.totalMoney);
			goto jump;
		case 4:
			system("cls");
			tempVar = newuser.totalMoney;
			newuser.totalMoney = newuser.totalMoney + 40;
			addMoneyToAccount(tempVar, 40);
			//fprintf(fp, "%d", newuser.totalMoney);
			goto jump;
		case 5:
			system("cls");
			tempVar = newuser.totalMoney;
			newuser.totalMoney = newuser.totalMoney + 50;
			addMoneyToAccount(tempVar, 50);
			//fprintf(fp, "%d", newuser.totalMoney);
			goto jump;
		case 6:
			system("cls");
			tempVar = newuser.totalMoney;
			newuser.totalMoney = newuser.totalMoney + 100;
			addMoneyToAccount(tempVar, 100);
			//fprintf(fp, "%d", newuser.totalMoney);
			goto jump;
		case 7:
			system("cls");
			goto jump;
		default:
			system("cls");
			printf("\n\n			 Invalid entry, Enter [1], [2], [3], [4], [5], [6] \n		                   or [7] to return to main menu\n\n");

			goto money_options;
			break;
		};

		//WITHDRAW FUNDS

	case 2:
		system("cls");
		printFileOnScreen(FileLocationPLUSlogo);
		printf("\n\n\t\t\t\t  |  Logged in as : %s  |\n\n", newuser.name);
		printFileOnScreen(FileLocationPLUSmoneyOUTCHOICES);
		gets_s(buffer, sizeof buffer, stdin);
		newuser.funds = ExtractNumbersFrom(buffer);

		//MONEY OPTIONS TO CHOOSE

		switch (newuser.funds)
		{
		case 1:

			newuser.money = 10;
			newuser.totalMoney = newuser.totalMoney - newuser.money;
			printf("\n\n                            [ You have withdrawn ");
			putchar(156);
			printf("%d from your account ]             \n\n", newuser.money);
			printf("\n\n                                  [ Your new balance is ");
			putchar(156);
			printf("%d ]             \n\n\n", newuser.totalMoney);

			goto jump;
		case 2:
			system("cls");
			newuser.money = 20;
			newuser.totalMoney = newuser.totalMoney - newuser.money;
			printf("\n\n                            [ You have withdrawn ");
			putchar(156);
			printf("%d from your account ]             \n\n", newuser.money);
			printf("\n\n                                  [ Your new balance is ");
			putchar(156);
			printf("%d ]             \n\n\n", newuser.totalMoney);

			goto jump;
		case 3:
			system("cls");
			newuser.money = 30;
			newuser.totalMoney = newuser.totalMoney - newuser.money;
			printf("\n\n                            [ You have withdrawn ");
			putchar(156);
			printf("%d from your account ]             \n\n", newuser.money);
			printf("\n\n                                  [ Your new balance is ");
			putchar(156);
			printf("%d ]             \n\n\n", newuser.totalMoney);

			goto jump;
		case 4:
			system("cls");
			newuser.money = 40;
			newuser.totalMoney = newuser.totalMoney - newuser.money;
			printf("\n\n                            [ You have withdrawn ");
			putchar(156);
			printf("%d from your account ]             \n\n", newuser.money);
			printf("\n\n                                  [ Your new balance is ");
			putchar(156);
			printf("%d ]             \n\n\n", newuser.totalMoney);

			goto jump;
		case 5:
			system("cls");
			newuser.money = 50;
			newuser.totalMoney = newuser.totalMoney - newuser.money;
			printf("\n\n                            [ You have withdrawn ");
			putchar(156);
			printf("%d from your account ]             \n\n", newuser.money);
			printf("\n\n                                  [ Your new balance is ");
			putchar(156);
			printf("%d ]             \n\n\n", newuser.totalMoney);

			goto jump;

		case 6:
			system("cls");
			newuser.money = 100;
			newuser.totalMoney = newuser.totalMoney - newuser.money;
			printf("\n\n                            [ You have withdrawn ");
			putchar(156);
			printf("%d from your account ]             \n\n", newuser.money);
			printf("\n\n                                  [ Your new balance is ");
			putchar(156);
			printf("%d ]             \n\n\n", newuser.totalMoney);

			goto jump;
		case 7:
			system("cls");
			goto jump;
		default:
			system("cls");
			printf("\n\n			 Invalid entry, Enter [1], [2], [3], [4], [5], [6] \n		                   or [7] to return to main menu\n\n");

			goto money_options;
			break;

		};
		goto jump;
		//RETURN CARD AND EXIT PROGRAM.

	case 3:
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t[ Thank you for banking with Wilder's Bank Simulator ]\n\n\n");
		printf("\n\n\n\n\t\t\t\t      [ Please take your card. ]\n\n\n\n\n\n\n\n\n\n\n\n\n");
		break;
		system("pause");

		//CHECK BALANCE

	case 4:
		system("cls");
		printf("\n\n\t\t\t\t[ YOUR AVAILABLE BALANCE IS  ");
		putchar(156);
		printf("%d. ]\n\n\n\n", newuser.totalMoney);
		goto jump;

		//CHANGE PIN NUMBER

	case 5:
		system("cls");
		memset(&buffer[0], 0, sizeof buffer);
		memset(&FileLocation[0], 0, sizeof FileLocation);
		printf("\nAre you sure you want to change your PIN? 1 [YES]  2[NO]\n\n-> ");
		gets_s(buffer, sizeof buffer, stdin);
		i = ExtractNumbersFrom(buffer);
		switch (i)
		{
		case 1:
			system("cls");
			i = j = 0;
			printf("\nEnter your new pin number :\n\n");
			scanf_s("%d", &i, 8);
			printf("\nEnter your new pin again :\n\n");
			scanf_s("%d", &j, 8);
			if (i != j){
				printf("\nPins do not match. Returning to main menu... \n\n");
				goto jump;
			}

			//THIS TWO DECLARATIONS MUST GO TOGETHER
			strcpy_s(name, sizeof name, newuser.name);
			makeFileAndStoreNewPIN(FileLocationUpdate, i, name);

			printf("\nPIN has been changed, please re login...\n\n");
			goto jump;
			break;
		case 2:
			system("cls");
			goto jump;
			break;
		default:
			goto jump;
			break;
		};
		break;
	case 6:
		system("cls");
		system("color 0E");
		printFileOnScreen(FileLocationGoodbye);
		system("exit");
		break;
	default:
		goto jump;
	}

	system("pause");
}

void addMoneyToAccount(int totalMoney, int newMoneyToAdd){
	totalMoney = totalMoney + newMoneyToAdd;
	printf("\n\n                            [ You have added ");
	putchar(156);
	printf("%d to your account ]             \n\n", newMoneyToAdd);
	printf("\n\n                                  [ Your new balance is ");
	putchar(156);
	printf("%d ]             \n\n\n", totalMoney);
};

void printFileOnScreen(char location[]){
	FILE *fp;
	int c;
	fopen_s(&fp, location, "r");
	while ((c = fgetc(fp)) != EOF){
		putchar(c);
	}
	fclose(fp);
}

void makeFileAndStoreNewPIN(char fileAddress[], int newPIN, char name[]){
	FILE *fp;
	char FileLocation[500];
	strcpy_s(FileLocation, sizeof FileLocation, fileAddress);
	strcat_s(FileLocation, sizeof FileLocation, name);
	strcat_s(FileLocation, sizeof FileLocation, "PIN");
	strcat_s(FileLocation, sizeof FileLocation, ".txt");
	fopen_s(&fp, FileLocation, "w+");
	fprintf(fp, "%d", newPIN);
	fclose(fp);
}
//New Function "ExtractNumbersFrom()" by Wilder Ruiz :
//This Function can extract the numbers of any user input.

int ExtractNumbersFrom(char number[]){
	int i, new_digit;
	int result = 0;

	for (i = 0; (number[i] != '\0'); i++){
		if ((number[i] > 47) && (number[i] < 58)){
			switch (number[i])
			{
			case 48:
				new_digit = 0;
				break;
			case 49:
				new_digit = 1;
				break;
			case 50:
				new_digit = 2;
				break;
			case 51:
				new_digit = 3;
				break;
			case 52:
				new_digit = 4;
				break;
			case 53:
				new_digit = 5;
				break;
			case 54:
				new_digit = 6;
				break;
			case 55:
				new_digit = 7;
				break;
			case 56:
				new_digit = 8;
				break;
			case 57:
				new_digit = 9;
				break;
			default:
				break;
			}
			result = (result * 10) + new_digit;
		};
	};
	return result;
};




//NEW FUNCTION ComparePinFromFile
//This function will return 1 if pin1 is equal to pin2 or 0 if it isn't, whereas pin2 is located in a file for which a file name is needed
/*int comparePinsAndChangeIt(char your_name[], char FileLocation[], int pin1){
FILE *fp;
char buffer[100];
int tempVar, c, newPIN, newPIN2;
tempVar = c = 0;

//CREATING A FILE PATH TO LOCATE USER FILE.

strcat_s(FileLocation, sizeof FileLocation, your_name);
strcat_s(FileLocation, sizeof FileLocation, "PIN");
strcat_s(FileLocation, sizeof FileLocation, ".txt");

//NOW FILE "FileLocation" has the address of the file including the user name as filename.

if (!(fp = fopen(FileLocation, "r"))){
printf("cannot open file\n");
}

printf("\nEnter your New PIN number\n\n-> ");
gets_s(buffer, sizeof buffer, stdin);
newPIN = ExtractNumbersFrom(buffer);
printf("\nEnter your New PIN again\n\n-> ");
gets_s(buffer, sizeof buffer, stdin);
newPIN2 = ExtractNumbersFrom(buffer);
if (newPIN == newPIN2){
fopen(FileLocation, "w+");
fprintf(fp, "%d", newPIN);
fclose(fp);
printf("Your Pin has been changed\n");
}
else{
system("cls");
printf("Pins don't match\n");

};
}
*/