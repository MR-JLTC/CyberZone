/* * *
  CODED BY    	   : 丂ʜᴀᴅᴏᴡ尺ᴇᴀᴘᴇ尺
  FROM             : 𝐂𝐓 𝐈𝐍𝐂𝐎𝐑𝐏𝐎𝐑𝐀𝐓𝐄𝐃
  PATCH DATE       : 6/13/２３
  System Name      : CYBERZONE CONSOLE
  System Version   : v1.2-beta
  System Type      : POS
  System Info      : A point of sale system for tech products with admin feature
  Programming Type : Procedural / Centralized Control
* * */
#include<stdio.h>//stands for standard input/output
#include<conio.h>//stands for console input/ouput
#include<windows.h>//used for coloring the text
#include<stdlib.h>//stands for standard library
#include<unistd.h>//stands for UNIX Standard Header, used for usleep function.
#include<stdbool.h>//stands for standard bool, used for boolean declarations

#define MAX_STRING_LENGTH 50
#define MAX_USERNAME_LEN 10
#define MAX_PASSWORD_LEN 10
#define MAX_MESSAGE_LENGTH 100
//used for new products
#define MAX_PRODUCTS 13
#define MAX_NAME_LENGTH 50
//USED FOR ARRAY OF COMMANDS
#define NUM_OF_ROWS 6
#define NUM_OF_COLS 17
#define MAX_LENGTH 30

/***|-[UTILITY FUNCTIONS]-|***/
void simulate_typing(const char *message);
int gender_input_vldtn(const char gender[MAX_STRING_LENGTH]);

/***|-[ENTRY POINT]-|***/
void front_page(void);
void logo(void);
void main_page();

/***|-[ADMIN PAGE]-|***/
void login(void);
void admin_header(void);
void admin_chatbot();
//admin command subfunction's\\
void AddProducts(void);
void signup(void);
void addPriceDiscountPromotion(void);

/***|-[CUSTOMER PAGE]-|***/
void cstmr_header(void);
void cstmr_chatbot(const char cstmr_gender[MAX_STRING_LENGTH]);
void cstmr_menu();
//subfuntions to get the chosen products from predefine list of products
void displaymenu(void);
void acceptChosenProducts(struct Product chosenProducts[], int *numProducts);
void displayChosenProducts(struct Product chosenProducts[], int numProducts);
//add products subfunctions to display the products added by the admin\\
void acceptChosenNewProducts(struct Product chosenProducts[], int *numProducts);
void display_newprod(void);
void getNewProducts(void);
//subfuntions to calculate and get the payment from both new products and predefine list of products
float calculateTotalPayment(struct Product chosenProducts[], int numProducts);
void payment_page(struct Product chosenProducts[],int numprod);
// ---[END OF FUNCTION DECLARATION]

//GLOBAL VARIABLE DECLARATIONS
char username[MAX_USERNAME_LEN + 1];
char password[MAX_PASSWORD_LEN + 1];
char entered_username[MAX_USERNAME_LEN + 1];
char entered_password[MAX_PASSWORD_LEN + 1];
const char deflt_usrnm[] = "admin";
const char deflt_pswrd[] = "admin123";
char admin_type[MAX_STRING_LENGTH];
char admin_gender[MAX_STRING_LENGTH];
char productNames[MAX_PRODUCTS][MAX_NAME_LENGTH];//USED TO STORE THE NEWLY ADDED PRODUCTS
char opt[MAX_STRING_LENGTH];
float productPrices[MAX_PRODUCTS];
float dscnt_prcntg = 0;
int numProducts =0;
int maxNameLength = 0;
int maxPriceLength = 0;
int Numprod;
int is_signed_up = 0;
char message[MAX_MESSAGE_LENGTH + 1];
int gndr_vldty;
char input[MAX_STRING_LENGTH];
int loop_anlyzr=0;
int loop_anlyzr2=0;
int loop_anlyzr3=0;
int loop_found=0;
char cstmr_prdct_rspn[MAX_STRING_LENGTH];
char brand[MAX_STRING_LENGTH];

//GLOBAL BOOLEAN VARIABLE DECLARATION
bool addng_promotion_done = false;
bool cmd_view_found = false;
bool onlyone_prod_found = false;
bool multiple_ch_found = false;
//FOR NEW ACCOUNT
bool signup_successful = false;
//FOR NEW PRODUCT/S
bool getNewProducts_found = false;
bool new_products_found = false;
bool adding_done = false;
bool new_admin_accnt_found = false;

//USED TO STORE THE CHOSEN PRODUCTS
struct Product {
	char name[MAX_STRING_LENGTH];
	float price;
	bool buy;
};

/***   (UTILITY FUNCTIONS)   ***/
/**                    >>>   TYPING DELAY ANIMATION [Description]   <<<
    putchar() - used to print each character of the message string to the standard output stream
                and this function takes a single character as input and prints it to the console.
    usleep()  - a function that causes the program to pause execution for a specified number of microseconds,
*/
void simulate_typing(const char *message) {
	for (int i = 0; i < strlen(message); i++) {
		putchar(message[i]);
		usleep(4100);
	}
	putchar('\n');
}
int gender_input_vldtn(const char gender[MAX_STRING_LENGTH]) {
	if((strcmp(gender,"Male")==0||strcmp(gender,"MALE")==0||strcmp(gender,"male")==0||strcmp(gender,"M")==0||strcmp(gender,"m")==0)) {
		return 1;
	} else if((strcmp(gender,"Female")==0||strcmp(gender,"FEMALE")==0||strcmp(gender,"female")==0||strcmp(gender,"F")==0||strcmp(gender,"f")==0)) {
		return 1;
	} else {
		return 0;
	}
}/**>>>   END OF UTILITY FUNCTIONS SIDE   <<<**/

/**----|   START OF MAIN FUNCTION/ENTRY POINT   |----**/
void front_page(void) {
	char respnd[MAX_STRING_LENGTH];
	loop_again:
	system("cls");
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	// Set the console color to green
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("\n\n\n\n\n");
	printf(" _|         _|  _|_|_|_|  _|          _|_|_|    _|_|    _|      _|  _|_|_|_|  _|_|_|_|_|    _|_|    \n");
	printf(" _|         _|  _|        _|        _|        _|    _|  _|_|  _|_|  _|            _|      _|    _|  \n");
	printf(" _|    _|   _|  _|_|_|    _|        _|        _|    _|  _|  _|  _|  _|_|_|        _|      _|    _|  \n");
	printf("  _|  _|  _|    _|        _|        _|        _|    _|  _|      _|  _|            _|      _|    _|  \n");
	printf("    _|  _|      _|_|_|_|  _|_|_|_|    _|_|_|    _|_|    _|      _|  _|_|_|_|      _|        _|_|    \n\n");
	// Set the console color to red
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf("                            _/_/_/_/_/_/     _/_/_/_/_/_/_/         _/_/_/_/_/_/                            \n");
	printf("                          _/                            _/        _/                                        \n");
	printf("                         _/                          _/          _/                                         \n");
	printf("                        _/                        _/            _/                                          \n");
	printf("                        /                      _/              _/                                           \n");
	printf("                      _/                    _/                _/                                            \n");
	printf("                      _/_/_/_/_/_/        _/_/_/_/_/_/_/      _/_/_/_/_/_/_/                                \n");
	SetConsoleTextAttribute(hConsole, originalColor);
	printf("                      ______________________________________________________\n");
	printf("                                       [ CYBERZONE CONSOLE ]\n");
	printf("                      ______________________________________________________\n");
	printf("                                        Proceed?[y/n]: ");
	fgets(respnd,MAX_STRING_LENGTH,stdin);
	respnd[strcspn(respnd, "\n")] = '\0';//stands for String Complement Span, it is used to find the length of the initial segment
	if(strcmp(respnd,"y")==0||strcmp(respnd,"Y")==0) {
		printf("                                     press any key to continue...");
	} else if(strcmp(respnd,"n")==0||strcmp(respnd,"N")==0) {
		printf("                                     press any key to exit...");
		getch();
		exit(0);
	} else {
		if(strlen(respnd)==0) {
			printf("                                        Enter a respond please!");
		} else {
			printf("                                        Invalid input!");
		}
		getch();
		goto loop_again;
	}
	getch();
}
void logo(void) {
	system("cls");
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	// Set the console color to red
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf("  _____     _           _____                _____                 _      \n");
	printf(" |     |_ _| |_ ___ ___|__   |___ ___ ___   |     |___ ___ ___ ___| |___  \n");
	printf(" |   --| | | . | -_|  _|   __| . |   | -_|  |   --| . |   |_ -| . | | -_| \n");
	printf(" |_____|_  |___|___|_| |_____|___|_|_|___|  |_____|___|_|_|___|___|_|___| \n");
	printf("       |___|                                                              \n");
	printf("   <<<=============================================================>>>    \n");
	printf("       \\\\ +++++++++++++++++++++++++++++++++++++++++++++++++++++ //      \n");
	printf("                        \\____[POS]SYSTEM(v1.0)____/ 		                  \n\n");
	SetConsoleTextAttribute(hConsole, originalColor);
}
void main_page() {
	logo();
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	// Set the console color to green
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("       /~___________~\\       /~___________~\\       /~___________~\\      \n");
	printf("       .-------------.       .-------------.       .-------------.      \n");
	printf("      (|    ADMIN    |)     (|   CUSTOMER  |)	  (|     EXIT    |)     \n");
	printf("       '-------------'       '-------------'       '-------------'      \n");
	printf("       \\_~~~~~~~~~~~_/       \\_~~~~~~~~~~~_/	   \\_~~~~~~~~~~~_/  	\n");
	SetConsoleTextAttribute(hConsole, originalColor);

	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	// Set the console color again to red
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf("       \\\\ +++++++++++++++++++++++++++++++++++++++++++++++++++++ //      \n\n");
	printf("   <<<=============================================================>>>   \n");
	// Set the console color back to the original
	SetConsoleTextAttribute(hConsole, originalColor);
}
int main() {
	char gender[MAX_STRING_LENGTH];
	char choice[MAX_STRING_LENGTH];
	int exitFlag = 0; //FALSE
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;
	system("cls");
	front_page();
	do {
		main_page();
		//TO RESET THE BOOLEAN VALUE
		signup_successful = false;
		new_products_found = false;
		cmd_view_found = false;
		printf("\t        OPTION : ");
		fgets(choice,MAX_STRING_LENGTH,stdin);
		choice[strcspn(choice, "\n")] = '\0';

		if(strcmp(choice,"Admin")==0||strcmp(choice,"admin")==0||strcmp(choice,"ADMIN")==0||strcmp(choice,"1")==0) {
			login();
			getch();

		} else if(strcmp(choice,"Customer")==0||strcmp(choice,"customer")==0||strcmp(choice,"CUSTOMER")==0||strcmp(choice,"2")==0) {
			enter_identity:
			system("cls");
			printf(" ===============================================\n");
			printf("||           GENDER * IDENTITY * FORM          ||\n");
			printf(" ===============================================\n");
			printf(" Customer Gender: ");
			fgets(gender,MAX_STRING_LENGTH,stdin);
			gender[strcspn(gender, "\n")] = '\0';
			gndr_vldty=gender_input_vldtn(gender);//TRUE(1) / FALSE (0)
			//CONDITION IF THE GENDER INPUT IS VALID
			if(gndr_vldty==1) {
				cstmr_chatbot(gender);
				continue;
			} else {
				if(strlen(gender)==0) {
					printf(" _______________________________________________\n");
					printf(" Enter some words for gender please...");
					getch();
					goto enter_identity;
				} else {
					printf(" _______________________________________________\n");
					printf(" Invalid Gender!");
					getch();
					goto enter_identity;
				}
			}

		} else if(strcmp(choice,"Exit")==0||strcmp(choice,"exit")==0||strcmp(choice,"EXIT")==0||strcmp(choice,"3")==0) {
			// Set the console color to green
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			printf("\n");
			printf("\t         ++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t        |     THANK YOU FOR CHOOSING CYBERZONE     |\n");
			printf("\t        |           USE OUR SYSTEM AGAIN :)        |\n");
			printf("\t        |              ANYTIME & ANYWHERE          | \n");
			printf("\t         ++++++++++++++++++++++++++++++++++++++++++\n");
			printf("\t               press any key to continue...\n");
			// Set the console color back to the original
			SetConsoleTextAttribute(hConsole, originalColor);
			getch();
			exitFlag = 1;//true
		} else {
			if(strlen(choice)==0) {
				printf("\t        Enter some words please...");
				getch();
			} else {
				printf("\t\tInvalid Input!");
				getch();
			}
		}
	} while(!exitFlag);//end of the loop
	return 0;
}/**>>>   END OF MAIN/ENTRY SIDE   <<<**/


/**----|   START OF ADMIN SIDE   |----**/
void login(void) {
	char gender[MAX_STRING_LENGTH];
	system("cls");
	cmd_view_found = false;
	login_f:
	system("cls") ;
	logo();
	signup_successful = false;
	printf("\n\t\t              [SECURITY KEY]");
	printf("\n\t    ==================================================");
	printf("\n\t\t        USERNAME: ");
	fgets(entered_username,MAX_STRING_LENGTH,stdin);
	entered_username[strcspn(entered_username, "\n")] = '\0'; // Remove newline character from message string
	printf("\t\t        PASSWORD: ");
	fgets(entered_password,MAX_STRING_LENGTH,stdin);
	entered_password[strcspn(entered_password, "\n")] = '\0';
	//ANALYZE IF THE ADMIN USER DID NOT INPUT ANYTHING
	if(strlen(entered_username)==0 && strlen(entered_password)==0) {
		printf("\t    ==================================================");
		printf("\n\t          [FAILURE STATUS]: Please input Username & Password");
		getch();
		goto login_f;
	} else if(strlen(entered_username)==0) {
		printf("\t    ==================================================");
		printf("\n\t          [FAILURE STATUS]: Please input username");
		getch();
		goto login_f;
	} else if(strlen(entered_password)==0) {
		printf("\t    ==================================================");
		printf("\n\t          [FAILURE STATUS]: Please input password");
		getch();
		goto login_f;
	}
	
	//if the admin user successfully created his/her disered account
	if(new_admin_accnt_found){
			//THIS 1ST CONDITION WILL ANALYZE IF THE ADMIN USER ENCODED AN UNREGISTERED ACCOUNT
		if (strcmp(entered_username, username) != 0 && strcmp(entered_password, password) != 0) {
			printf("\t    ==================================================");
			printf("\n\t          [FAILURE STATUS]: Invalid Account!");
			getch();
			goto login_f;
		} else if(strcmp(entered_username,username)!=0) {
			printf("\t    ==================================================");
			printf("\n\t          [FAILURE STATUS]: Invalid Username!");
			getch();
			goto login_f;
		} else if(strcmp(entered_password,password)!=0) {
			printf("\t    ==================================================");
			printf("\n\t          [FAILURE STATUS]: Invalid Password!");
			getch();
			goto login_f;
		} else {
			printf("\t    ==================================================\n");
			printf("\t                    [LOGIN SUCESSFULLY]\n");
			printf("\t               press any key to continue... ");
			getch();
			do {
				system("cls");
				printf(" ===============================================\n");
				printf("||           GENDER * IDENTITY * FORM          ||\n");
				printf(" ===============================================\n");
				printf("Customer Gender: ");
				fgets(input,MAX_STRING_LENGTH,stdin);
				//extracting the first word from the input
				sscanf(input,"%s",gender);
				gndr_vldty=gender_input_vldtn(gender);//GENDER INPUT VALIDATION
				//CONDITION FOR THE GENDER VALIDATION RESULT
				if(gndr_vldty==1) {
					strncpy(admin_type,username,MAX_STRING_LENGTH);
					strncpy(admin_gender,gender,MAX_STRING_LENGTH);
					admin_chatbot();
				} else {
					printf(" ===============================================\n");
					printf("Invalid Gender");
					getch();
				}
			} while(1);
		}
	}else{
			//ANALYZE IF THE ADMIN ENTERED THE DEFAULT ACCOUNT
		if(strcmp(entered_username,deflt_usrnm)==0||strcmp(entered_password,deflt_pswrd)==0) {
			if(strcmp(entered_username,deflt_usrnm)!=0) {
				printf("\t    ==================================================\n");
				printf("\t                      [LOGIN FAILED]\n");
				printf("\t                Invalid Default Username!");
				getch();
				goto login_f;
			} else if(strcmp(entered_password,deflt_pswrd)!=0) {
				printf("\t    ==================================================\n");
				printf("\t                      [LOGIN FAILED]\n");
				printf("\t                 Invalid Default Password!");
				getch();
				goto login_f;
			} else {
				printf("\t    ==================================================\n");
				printf("\t                   [LOGIN SUCESSFULLY]\n");
				simulate_typing("\t\t     press any key to continue...");
				getch();
				int loop;
				do {
					loop++;
					system("cls");
					printf(" ===============================================\n");
					printf("||           GENDER * IDENTITY * FORM          ||\n");
					printf(" ===============================================\n");
					printf(" Customer Gender: ");
					fgets(input,MAX_STRING_LENGTH,stdin);
					//extracting the first word from the input
					sscanf(input,"%s",gender);
					//CONDITION IF THERES NO INPUT
					gndr_vldty=gender_input_vldtn(gender);//GENDER INPUT VALIDATION
					if(gndr_vldty==1) {
						strncpy(admin_type,deflt_usrnm,MAX_STRING_LENGTH);
						strncpy(admin_gender,gender,MAX_STRING_LENGTH);
						admin_chatbot();
					} else {
						printf(" ===============================================\n");
						printf(" [ERROR]: Invalid Gender");
						getch();
					}
				} while(gndr_vldty!=1);
			}
		}//ANALYZE THE REGISTERED ADMIN ACCOUNT
		else {
			//THIS 1ST CONDITION WILL ANALYZE IF THE ADMIN USER ENCODED AN UNREGISTERED ACCOUNT
			if (strcmp(entered_username, username) != 0 && strcmp(entered_password, password) != 0) {
				printf("\t    ==================================================");
				printf("\n\t          [FAILURE STATUS]: Invalid Account!");
				getch();
				goto login_f;
			} else if(strcmp(entered_username,username)!=0) {
				printf("\t    ==================================================");
				printf("\n\t          [FAILURE STATUS]: Invalid Username!");
				getch();
				goto login_f;
			} else if(strcmp(entered_password,password)!=0) {
				printf("\t    ==================================================");
				printf("\n\t          [FAILURE STATUS]: Invalid Password!");
				getch();
				goto login_f;
			} else {
				printf("\t    ==================================================\n");
				printf("\t                    [LOGIN SUCESSFULLY]\n");
				printf("\t               press any key to continue... ");
				getch();
				do {
					system("cls");
					printf(" ===============================================\n");
					printf("||           GENDER * IDENTITY * FORM          ||\n");
					printf(" ===============================================\n");
					printf("Customer Gender: ");
					fgets(input,MAX_STRING_LENGTH,stdin);
					//extracting the first word from the input
					sscanf(input,"%s",gender);
					gndr_vldty=gender_input_vldtn(gender);//GENDER INPUT VALIDATION
					//CONDITION FOR THE GENDER VALIDATION RESULT
					if(gndr_vldty==1) {
						strncpy(admin_type,deflt_usrnm,MAX_STRING_LENGTH);
						strncpy(admin_gender,gender,MAX_STRING_LENGTH);
						admin_chatbot();
					} else {
						printf(" ===============================================\n");
						printf("Invalid Gender");
						getch();
					}
				} while(1);
			}
		}	
	}
}
//=====START OF ADMIN SUBFUNCTIONS ======//
//ADD PRODUCT FEATURE
void AddProducts(void) {
	back:
	system("cls");
	cmd_view_found = false;
	new_products_found = true;
	printf("===============================================\n");
	printf("||            NEW PRODUCT/S ENTRY            ||\n");
	printf("===============================================\n");
	printf("Number of products[1-13]: ");
	fgets(input,MAX_LENGTH,stdin);
	input[strcspn(input, "\n")] = '\0'; 
	//sscanf(input,"%d",&numProducts);
	numProducts = atoi(input);// Convert the input to an integer
	//analyze if input is greater than maximum set number of products to be added & ig input is lesser than or equal to 0
    if (numProducts != 0 || input[0] == '0') {
		if (numProducts <= 0 || numProducts > MAX_PRODUCTS) {
			printf("Number exceed the given maximum number. Please try again.\n");
			getch();
			goto back;  // Exit the program with an error status
		}else{
			printf("\n+---------------------------------------------+\n");
			// Input product names and prices
			for (int i = 0; i < numProducts; i++) {
				printf("Enter the name of product #%d: ", i + 1);
				scanf(" %49[^\n]", productNames[i]);
				printf("Enter the price of product #%d: ", i + 1);
				scanf("%f", &productPrices[i]);
				printf("+---------------------------------------------+\n");
			}
			adding_done = true;
			// Find the maximum length of product names
				for (int i = 0; i < numProducts; i++) {
					int nameLength = strlen(productNames[i]);
					if (nameLength > maxNameLength) {
						maxNameLength = nameLength;
					}	
				}
			// Find the maximum length of price strings
			char priceString[10];
			for (int i = 0; i < numProducts; i++) {
				snprintf(priceString, sizeof(priceString), "%.2f", productPrices[i]);
				int priceLength = strlen(priceString);
				if (priceLength > maxPriceLength) {
					maxPriceLength = priceLength;
				}
			}
			if(adding_done) {
				printf("===============================================\n");
				printf("         Products Successfully Added!          \n");
				printf("         press any key to go back...");
				getch();
				admin_chatbot();
			}
		}
	}else{
		printf("Invalid input. Please enter a valid number.");
        getch();
        goto back;
	}
}
//CREATE ACCOUNT FEATURE
void signup(void) {
	cmd_view_found = false;
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	if (is_signed_up) {
		printf("\n\n==STATUS==\n");
		printf("You have already signed up.");
		getch();
		return;
	}
	//SIGNUP MENU
	reg_f:
	system("cls");
	printf("===============================================");
	printf("\n||       ACCOUNT * REGISTRATION * FORM       ||");
	printf("\n===============================================");

	printf("\nDesired username (up to %d characters):\n>>> ", MAX_USERNAME_LEN);
	// Set the console color to green
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	//scanf("%s", entered_username);
	fgets(input,MAX_STRING_LENGTH,stdin);
	//extracting the first word from the input
	sscanf(input,"%s", entered_username);
	SetConsoleTextAttribute(hConsole, originalColor);

	printf("Desired password (up to %d characters):\n>>> ", MAX_PASSWORD_LEN);
	// Set the console color to green
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	//scanf("%s", entered_password);
	fgets(input,MAX_STRING_LENGTH,stdin);
	//extracting the first word from the input
	sscanf(input,"%s", entered_password);
	SetConsoleTextAttribute(hConsole, originalColor);

	//CONDITION FOR INPUTTED USERNAME & PASSWORD
	if (strlen(entered_username) > MAX_USERNAME_LEN && strlen(entered_password) > MAX_PASSWORD_LEN) {
		printf("\n===============================================");
		printf("\n[ERROR STATUS]: username & password are too long");
		getch();
		goto reg_f;
	} else if (strlen(entered_username) > MAX_USERNAME_LEN) {
		printf("\n===============================================");
		printf("\n[ERROR STATUS]: username too long");
		getch();
		goto reg_f;
	} else if (strlen(entered_password) > MAX_PASSWORD_LEN) {
		printf("\n===============================================");
		printf("\n[ERROR STATUS]: password too long");
		getch();
		goto reg_f;
	} else {
		new_admin_accnt_found = true;
		strcpy(username, entered_username);
		strcpy(password, entered_password);
		is_signed_up = 1;
		printf("\n===============================================\n");
		printf("           [SIGNUP SUCCESSFULLY]\n");
		printf("        press any key to continue...");
		signup_successful = true;
		getch();
		admin_chatbot();
	}
}
//ADD PRICE DISCOUNT FEATURE
void addPriceDiscountPromotion(void) {
	float disc_prmtn_rate;
	ask_gain:
	cmd_view_found = false;
	system("cls");
	printf("===============================================\n");
	printf("||        >>> DISCOUNT PROMOTION <<<         ||\n");
	printf("===============================================\n");
	printf(" Discount promotion rate (in percentage):  ");
	scanf("%f",&disc_prmtn_rate);

	if(disc_prmtn_rate<0) {
		printf("===============================================\n");
		printf(" Invalid Discount Rate");
		getch();
		goto ask_gain;
	} else {
		addng_promotion_done = true;
		printf("===============================================\n");
		printf("                   [SUCCESS]                   \n");
		printf("     Discount rate of %.0f%% has been applied\n",disc_prmtn_rate);
		printf("_______________________________________________\n");
		dscnt_prcntg = disc_prmtn_rate;
		printf("press any key to go back");
		getch();
		admin_chatbot();
	}
}//=====END OF ADMIN SUBFUNCTIONS ======//
//=====START OF ADMIN MAIN FUNCTION ======//
void admin_header(void) {
	//HANDLE  a type alias(new name) defined in the Windows API
	//        it is a type that's used to manipulate and access system resources in the Windows operating system.

	//GetStdHandle(STD_OUTPUT_HANDLE) is a Windows API function that retrieves a handle to the standard output device,
	//                                which is typically the console screen.
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	// Set the console color to green
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf(" *********************************************************************** \n");
	printf("|                      WELCOME TO CYBERZONE CONSOLE                     |\n");
	printf("|                             [ADMIN PAGE]                         v1.0 |\n");
	printf(" *********************************************************************** \n");
	SetConsoleTextAttribute(hConsole, originalColor);
}
/*ADMIN PAGE*/
//SCRIPTED BOT FOR THE ADMIN
void admin_chatbot() {
	int i, j,x,found;
	cmd_view_found = false;
	bool scsfl_cmd_found = false;
	/* ARRAY OF COMMANDS  */
	const char cmds_list[NUM_OF_ROWS][NUM_OF_COLS][MAX_LENGTH] = {
		{
			"ADD PRODUCTS",
			"Add Products",
			"Add products",
			"aDd products",
			"adD products",
			"add Products",
			"add pRoducts",
			"add prOducts",
			"add proDucts",
			"add prodUcts",
			"add produCts",
			"add producTs",
			"add productS",
			"add products"
		},
		{
			"CREATE ACCOUNT",
			"Create Account",
			"Create account",
			"cReate account",
			"crEate account",
			"creAte account",
			"creaTe account",
			"creatE account",
			"create Account",
			"create aCcount",
			"create acCount",
			"create accOunt",
			"create accoUnt",
			"create accouNt",
			"create accounT",
			"create account"
		},
		{
			"ADD PROMOTIONS",
			"Add Promotions",
			"Add promotions",
			"aDd promotions",
			"adD promotions",
			"add Promotions",
			"add pRomotions",
			"add prOmotions",
			"add proMotions",
			"add promOtions",
			"add promoTions",
			"add promotIons",
			"add promotiOns",
			"add promotioNs",
			"add promotionS",
			"add promotions"
		},
		{
			"EXIT",
			"Exit",
			"exit",
			"eXit",
			"exIt",
			"exiT",
			"EXit",
			"ExIt",
			"ExiT",
			"eXIt",
			"eXiT",
			"exIT"
		},
		{
			"CMD",
			"Cmd",
			"cMd",
			"cmD",
			"CMd",
			"CmD",
			"cMD",
			"cmd"
		},
		{
			"CUSTOMER PAGE",
			"Customer Page",
			"Customer page",
			"cUstomer page",
			"cuStomer page",
			"cusTomer page",
			"custOmer page",
			"custoMer page",
			"customEr page",
			"customeR page",
			"customer Page",
			"customer pAge",
			"customer paGe",
			"customer pagE",
			"customer page"
		}
	};
	/*                          INTRODUCTION                  */
	system("cls");
	loop_anlyzr2=0;
	//HANDLE  a type alias(new name) defined in the Windows API
	//        it is a type that's used to manipulate and access system resources in the Windows operating system.

	//GetStdHandle(STD_OUTPUT_HANDLE) is a Windows API function that retrieves a handle to the standard output device,
	//                                which is typically the console screen.
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;
	admin_header();
	//CONDITION FOR GENDER TITLE
	if(strcmp(admin_gender,"Male")==0||strcmp(admin_gender,"MALE")==0||strcmp(admin_gender,"male")==0||strcmp(admin_gender,"M")==0||strcmp(admin_gender,"m")==0) {
		printf("[BOT] : ");
		simulate_typing("Hello Sir :)");
	} else {
		printf("[BOT] : ");
		simulate_typing("Hello Ma'am :)");
	}
	//condition kung naay isa ka command ang nahuman
	if(signup_successful || adding_done || addng_promotion_done){
		if(signup_successful) {
			scsfl_cmd_found = true;
			printf("[BOT] : ");
			simulate_typing("Congratulations for successfully creating your account");
		} else if(adding_done) {
			scsfl_cmd_found = true;
			printf("[BOT] : ");
			simulate_typing("Congratulations for successfully added new products");
		} else if(addng_promotion_done){
			scsfl_cmd_found = true;
			printf("[BOT] : ");
			simulate_typing("Congratulations for successfully added a discount promotion");
		}
		printf("[BOT] : ");
		simulate_typing("Type \"cmd\" to view the list of available commands");
		printf("[BOT] : ");
		simulate_typing("How can we help you today?");
	}//wala pay command nga na execute
	else{
		printf("[BOT] : ");
		simulate_typing("Welcome to the admin page of our console-based system");
		printf("[BOT] : ");
		simulate_typing("I'm your personal chatbot assistant here to help you manage and");
		simulate_typing("\tnavigate through the various features and functionalities");
		simulate_typing("\tavailable to you.");
		printf("[BOT] : ");
		simulate_typing("Type \"cmd\" to view the list of available commands");
		printf("[BOT] : ");
		simulate_typing("How can we help you today?");
	}
	
	while (1) {
		//input:
		found = 0;
		// Set the console color to green
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		printf("[%s] >>>  ",admin_type);
		fgets(message,MAX_LENGTH,stdin);
		message[strcspn(message, "\n")] = '\0'; // Remove newline character from message string
		SetConsoleTextAttribute(hConsole, originalColor);

		if(scsfl_cmd_found) {
			//to make the condition that check if theres no input, behave
		} else {
			if(strlen(message) == 0) {
				printf("[BOT] : ");
				simulate_typing("Enter some words please...");
				continue;
			}
		}

		/*COMMAND's LOOKUP FEATURE*/
		// Search through the array for the COMMAND'S
		for(i=0; i<NUM_OF_ROWS; i++) {
			for(j=0; j<NUM_OF_COLS; j++) {
				if(strcmp(message,cmds_list[i][j])==0) {
					found = 1;
					break;
				}
			}
			if(found) {
				break;
			}
		}
		//IF THE STRING COMMAND FOUND IN THE ARRAY LIST
		//THIS CONDTION WILL COMPARE THE INPUTTED COMMAND BY INDEX LOCATION OF THE LISTED COMMANDS INSIDE THE ARRAY
		if(found) {
			for(x=0; x<NUM_OF_COLS; x++) {
				//ADD PRODUCT COMMAND
				if(strcmp(message,cmds_list[0][x])==0) {
					if(scsfl_cmd_found) {
						continue;
						scsfl_cmd_found = false;
					}
					printf("[BOT] : ");
					simulate_typing("proceeding to add product/s page");
					printf("[BOT] : ");
					simulate_typing("press any key to continue...");
					getch();
					AddProducts();
				}
				//CREATE ACCOUNT COMMAND
				else if(strcmp(message,cmds_list[1][x])==0) {
					//ANALYZE THE REGISTERED ACCOUNT CONDITION
					//CONDITION IS ONE REGISTERED ACCOUNT AT A TIME
					if (is_signed_up) {
						printf("[BOT] : ");
						simulate_typing("Sorry looks like you have already signed up.");
						printf("[BOT] : ");
						simulate_typing("One account registration at a time only");
					} else {
						printf("[BOT] : ");
						simulate_typing("proceeding to account creation page");
						printf("[BOT] : ");
						simulate_typing("press any key to continue...");
						getch();
						signup();
					}
				}
				//ADD PROMOTIONS COMMAND
				else if(strcmp(message,cmds_list[2][x])==0) {
					printf("[BOT] : ");
					simulate_typing("proceeding to account add promotion/s page");
					printf("[BOT] : ");
					simulate_typing("press any key to continue...");
					getch();
					addPriceDiscountPromotion();
				}
				//EXIT COMMAND
				else if(strcmp(message,cmds_list[3][x])==0) {
					if(scsfl_cmd_found) {
						//to make the condition that check if theres no input, behave
						continue;
					}
					printf("[BOT] : ");
					simulate_typing("press any key to exit...");
					getch();
					main();
				}
				//CMD - Command list Command
				else if(strcmp(message,cmds_list[4][x])==0) {
					if(scsfl_cmd_found) {
						//to make the condition that check if theres no input, behave
						continue;
					}

					if(cmd_view_found) {
						printf("[BOT] : ");
						simulate_typing("You are already in the command view list");
						continue;

					} else {
						system("cls");
						admin_header();
						cmd_view_found = true;
							loop_anlyzr2 = 0;
						simulate_typing("-----------------------------------------------");
						printf("\t   <== AVAILABLE COMMAND's ==>\n\n");
						simulate_typing("               [*] Add Products");
						simulate_typing("               [*] Add Promotions");
						simulate_typing("               [*] Create Account");
						simulate_typing("               [*] Customer Page");
						simulate_typing("               [*] CMD");
						simulate_typing("               [*] Exit");
						simulate_typing("-----------------------------------------------");
						printf("\n");
						loop_anlyzr3++;
					}
				}
				//CUSTOMER MENU COMMAND
				else if(strcmp(message,cmds_list[5][x])==0) {
					printf("[BOT] : ");
					simulate_typing("press any key to proceed...");
					getch();
					cstmr_menu();

				}
			}
			scsfl_cmd_found = false;
		} 
		//condition kung ang gihatag nga input/queries wala sa mga commands nga gi store sa string array
		else if(!found) {
			if(scsfl_cmd_found) {
				continue;
			}
			
			if(strcmp(message,"Hi")==0||strcmp(message,"hi")==0){
				printf("[BOT] : ");
				simulate_typing("Hello, what can i do for you?");
			}else if(strcmp(message,"What is your name?")==0||strcmp(message,"what is your name?")==0){
				printf("[BOT] : ");
				simulate_typing("Hello! My name is CyberBot. How can I assist you today?");
			}else if(strcmp(message,"What can you do?")==0||strcmp(message,"what can you do?")==0){
				printf("[BOT] : ");
				simulate_typing("Thank you for your question! As an AI chatbot, I have been programmed to assist");
				simulate_typing("\ttasks. Some of the things I can help you with include [add products, ");
				simulate_typing("\tadd promotions, create account, customer page, and cmd]."); 
				printf("[BOT] : ");
				simulate_typing("Whether you need information, support, or guidance on those topics, feel free to ask.");
				printf("[BOT] : ");
				simulate_typing("If you have any other questions or need assistance, please let me know");
			}else if(strcmp(message,"Add products definition")==0||strcmp(message,"add products definition")==0){
				printf("[BOT] : ");
				simulate_typing("[Add products] command lets you add a new disered products and it will display to the customer page.");
			}else if(strcmp(message,"Add promotions definition")==0||strcmp(message,"add promotions definition")==0){
				printf("[BOT] : ");
				simulate_typing("When you use the '[Add promotions]' command and specify a discounted percentage,");
				simulate_typing("\tthe system will automatically deduct that percentage from the total payment amount.");
				simulate_typing("\tThis ensures that your customers receive the applicable discount without any manual intervention.");
				simulate_typing("\tIt's a convenient and efficient way to provide savings to your customers during their transactions.");
				printf("[BOT] : ");
				simulate_typing("If you have any further questions or need assistance with managing promotions, feel free to ask!");
			}else if(strcmp(message,"Create account definition")==0||strcmp(message,"create account definition")==0){
				printf("[BOT] : ");
				simulate_typing("[Create account] command lets you create your desired admin account");
				simulate_typing("\tif you dont like to use the default admin account");
			}else if(strcmp(message,"Customer page definition")==0||strcmp(message,"customer page definition")==0){
				printf("[BOT] : ");
				simulate_typing("[Customer page] command will let you view the customer page for your customers");
			}else if(strcmp(message,"CMD definition")==0||strcmp(message,"cmd definition")==0){
				printf("[BOT] : ");
				simulate_typing("[cmd] command which stands for (command), lets you view the predefine commands");
			}else if(strcmp(message,"Exit definition")==0||strcmp(message,"exit definition")==0){
				printf("[BOT] : ");
				simulate_typing("[exit] command will let you go back to the front page of our system");
			}else if(strcmp(message,"Who is your developer?")==0||strcmp(message,"who is your developer?")==0){
				printf("[BOT] : ");
				simulate_typing("I was developed by a group of computer science students and there group leader MR.CRUZ");
				simulate_typing("\twhich is the main developer of this system.");
			}else if(strcmp(message,"Thanks")==0||strcmp(message,"thanks")==0||strcmp(message,"Thank You")==0||strcmp(message,"Thank you")==0||strcmp(message,"thank you")==0){
				printf("[BOT] : ");
				simulate_typing("You're welcome! If you have any more questions or need further assistance");
				simulate_typing("\tfeel free to ask. I'm here to help!");
			}else{
				loop_anlyzr2++;
				if(loop_anlyzr2>=3) {
					printf("[BOT] : ");
					simulate_typing("Looks like you're inputting invalid command simultaneously");
					printf("[BOT] : ");
					simulate_typing("Type \"cmd\" to view the list of available commands");
				}else{
					printf("[BOT]: ");
					simulate_typing("Sorry, Invalid Command");
				}
			}
		}
		//behavior flow controller
		if(scsfl_cmd_found) {
			continue;
		}
		scsfl_cmd_found = false;
	}
}/**>>>   END OF ADMIN SIDE   <<<**/

/**----|   START OF CUSTOMER SIDE   |----**/
void cstmr_header(void) {
	/*CHANGING THE TEXT COLOR OF OUR HEADER*/
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	// Set the console color to RED
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	printf(" ***********************************************************************\n");
	printf("|                     Welcome to CYBERZONE CONSOLE                      |\n");
	printf("|                           [CUSTOMER PAGE]                        v1.0 |\n");
	printf(" ***********************************************************************\n");
	SetConsoleTextAttribute(hConsole, originalColor);
}
//SCRIPTED BOT FOR CUSTOMER's
void cstmr_chatbot(const char cstmr_gender[MAX_STRING_LENGTH]) {
	cmd_view_found = false;
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	if(loop_anlyzr>=1) {
		system("cls");
		cstmr_header();
		goto direct_chat;
	}
	system("cls");
	cstmr_header();
	printf("[ADMIN] : ");
	simulate_typing("Before we proceed, I would like to make an introduction");
	//CONDITION FOR GENDER TITLE
	if(strcmp(cstmr_gender,"Male")==0||strcmp(cstmr_gender,"MALE")==0||strcmp(cstmr_gender,"male")==0||strcmp(cstmr_gender,"M")==0||strcmp(cstmr_gender,"m")==0) {
		printf("[ADMIN] : ");
		simulate_typing("Hello Sir and Welcome to CyberZone!");
	} else {
		printf("[ADMIN] : ");
		simulate_typing("Hello Ma'am and Welcome to CyberZone!");
	}
	printf("[ADMIN] : ");
	simulate_typing("We sell the latest tech gadgets and devices to keep you");
	simulate_typing("\t  connected, productive, and entertained.");
	printf("[ADMIN] : ");
	simulate_typing("Our goal is to make technology accessible and affordable");
	simulate_typing("\t  for everyone");

	direct_chat:
	loop_anlyzr=0;
	SetConsoleTextAttribute(hConsole, originalColor);
	printf("[ADMIN] : ");
	simulate_typing("How can we help you today?");
	printf("[ADMIN] : ");
	simulate_typing("Type \"cmd\" to view the list of available commands");
	while (1) {
		/*CHANGING THE TEXT COLOR OF OUR CUSTOMER RESPONDS*/
		// Set the console color to red
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		if(loop_anlyzr>=1) {
			printf("[YOU] >>>  ");
		} else {
			printf("[YOU] >>>  ");
		}
		fgets(message,MAX_MESSAGE_LENGTH,stdin);
		// Remove newline character from message string
		message[strcspn(message, "\n")] = '\0';
		SetConsoleTextAttribute(hConsole, originalColor);
		//CONDITION IF THE USER's WILL JUST ENTER DIRECTLY WITHOUT INPUTTING SOMETHING
		if(strlen(message)==0) {
			printf("[ADMIN] : ");
			simulate_typing("Enter some words please...");
			continue;
		}

		//CONDITION FOR CUSTOMERS RESPONDS
		if (strcmp(message, "menu") == 0 || strcmp(message, "Menu") == 0 || strcmp(message, "MENU") == 0 ) {
			printf("[ADMIN] : ");
			simulate_typing("Here's our menu...");
			printf("[ADMIN] : ");
			simulate_typing("press enter key to continue...");
			getch();
			system("cls");
			cstmr_menu();
			continue;
		} else if(strcmp(message, "go back") == 0 || strcmp(message, "Go Back") == 0||strcmp(message, "go Back") == 0||strcmp(message, "GO BACK") == 0||strcmp(message, "Go back") == 0) {
			printf("[ADMIN] : ");
			simulate_typing("press any key to continue");
			getch();
			main();
		} else if(strcmp(message, "help") == 0 || strcmp(message, "HELP") == 0||strcmp(message, "cmd") == 0||strcmp(message, "CMD") == 0||strcmp(message, "Cmd") == 0) {
			if(cmd_view_found) {
				printf("[ADMIN]: ");
				simulate_typing("You are already in the command view list");
				continue;
			}
			system("cls");
			cstmr_header();
			cmd_view_found = true;
			loop_anlyzr=0;
			simulate_typing("-------------------------------------------------");
			printf("\t   <== AVAILABLE COMMAND ==>\n\n");
			simulate_typing("[menu]     - display the menu page for customers");
			simulate_typing("[go back]  - it will go back to the main page");
			simulate_typing("[exit]     - terminate the program");
			simulate_typing("[help/cmd] - view the list of commands");
			simulate_typing("[admin page] - it will go back to the admin page");
			simulate_typing("-------------------------------------------------");
			printf("\n");
		} else if(strcmp(message, "EXIT") == 0 || strcmp(message, "exit") == 0) {
			printf("[ADMIN] : ");
			simulate_typing("Thanks for choosing CyberZone");
			printf("[ADMIN] : ");
			simulate_typing("Hope you buy one of our products next time :)");
			printf("[ADMIN] : ");
			simulate_typing("press any key to continue...");
			getch();
			exit(0);
		} else if(strcmp(message, "admin page") == 0 || strcmp(message, "admin page") == 0) {
			printf("[ADMIN] : ");
			simulate_typing("press any key to proceed...");
			getch();
			login();
		} else {
			if(loop_anlyzr >=3) {
				printf("[ADMIN] : ");
				simulate_typing("You're inputting invalid command simultaneously");
				printf("[ADMIN] : ");
				simulate_typing("Type \"help\" to see the list of valid commands");
			} else {
				printf("[ADMIN] : ");
				simulate_typing("Sorry, invalid command");
				loop_anlyzr++;
			}
		}
	}
}
/***   FOR NEWLY ADDED PRODUCTS   ***/
void display_newprod(void) {
	// Display the header
	printf("====================================================\n");
	printf("||           >>> NEW ADDED PRODUCTS <<<           ||\n");
	printf("*==================================================*\n");
	printf("| NUMBER       NAME                  PRICE         |\n");
	printf("+--------------------------------------------------+\n");

	// Display the entered product names and prices
	for (int i = 0; i < numProducts; i++) {
		printf("| %-4d         %- *s %*.*f   |\n", i + 1, maxNameLength, productNames[i], maxPriceLength + 3, 2, productPrices[i]);
	}
	printf("| [g]o back                                        |\n");
	printf("+--------------------------------------------------+\n");
}
void acceptChosenNewProducts(struct Product chosenProducts[], int *numProducts) {
	char choice;
	bool chooseMore = true;
	int productId;
	cmd_view_found = false;
	while (chooseMore && (*numProducts < MAX_PRODUCTS)) {
		printf("Product Number for chosen product [%d]: ",*numProducts + 1);
		fgets(input,MAX_STRING_LENGTH,stdin);
		input[strcspn(input, "\n")] = '\0';
		sscanf(input, "%d", &productId);
		if(strcmp(input,"g")==0||strcmp(input,"G")==0) {
			cstmr_menu();
		}

		switch (productId) {
			case 1:
				strcpy(chosenProducts[*numProducts].name,productNames[0]);
				chosenProducts[*numProducts].price = productPrices[0];
				(*numProducts)++;
				break;
			case 2:
				strcpy(chosenProducts[*numProducts].name,productNames[1]);
				chosenProducts[*numProducts].price = productPrices[1];
				(*numProducts)++;
				break;
			case 3:
				strcpy(chosenProducts[*numProducts].name,productNames[2]);
				chosenProducts[*numProducts].price = productPrices[2];
				(*numProducts)++;
				break;
			case 4:
				strcpy(chosenProducts[*numProducts].name,productNames[3]);
				chosenProducts[*numProducts].price = productPrices[3];
				(*numProducts)++;
				break;
			case 5:
				strcpy(chosenProducts[*numProducts].name,productNames[4]);
				chosenProducts[*numProducts].price = productPrices[4];
				(*numProducts)++;
				break;
			case 6:
				strcpy(chosenProducts[*numProducts].name,productNames[5]);
				chosenProducts[*numProducts].price = productPrices[5];
				(*numProducts)++;
				break;
			case 7:
				strcpy(chosenProducts[*numProducts].name,productNames[6]);
				chosenProducts[*numProducts].price = productPrices[6];
				(*numProducts)++;
				break;
			case 8:
				strcpy(chosenProducts[*numProducts].name,productNames[7]);
				chosenProducts[*numProducts].price = productPrices[7];
				(*numProducts)++;
				break;
			case 9:
				strcpy(chosenProducts[*numProducts].name,productNames[8]);
				chosenProducts[*numProducts].price = productPrices[8];
				(*numProducts)++;
				break;
			case 10:
				strcpy(chosenProducts[*numProducts].name,productNames[9]);
				chosenProducts[*numProducts].price = productPrices[9];
				(*numProducts)++;
				break;
			case 11:
				strcpy(chosenProducts[*numProducts].name,productNames[10]);
				chosenProducts[*numProducts].price = productPrices[10];
				(*numProducts)++;
				break;
			case 12:
				strcpy(chosenProducts[*numProducts].name,productNames[11]);
				chosenProducts[*numProducts].price = productPrices[11];
				(*numProducts)++;
				break;
			case 13:
				strcpy(chosenProducts[*numProducts].name,productNames[12]);
				chosenProducts[*numProducts].price = productPrices[12];
				(*numProducts)++;
				break;
			default:
				printf("Invalid product ID. Skipping...\n");
				break;
		}
		ask_again:
		printf("Do you want to choose another product? (y/n): ");
		fgets(input,MAX_STRING_LENGTH,stdin);
		sscanf(input, "%c", &choice);
		if (choice == '\n') {
			simulate_typing("No input provided. Product not added to the purchase.");
			chosenProducts[*numProducts].buy = false;
			goto ask_again;
		}else if(choice == 'Y' || choice == 'y'){
			continue;
		}else if (choice == 'N' || choice == 'n') {
			chooseMore = false;
		}else{
			simulate_typing("Invalid input, please enter the required respond.");
			chosenProducts[*numProducts].buy = false;
			goto ask_again;
		}
	}
}
/****   CUSTOMER MENU PAGE    ****/
void cstmr_menu(void) {
	cmd_view_found = false;
	struct Product chosenProducts[MAX_PRODUCTS];
	int numProducts = 0;
	loop_anlyzr++;
	//condition if there are newly added products
	if(new_products_found) {
		logo();
		// Get the console output handle
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		// Save the original console color settings
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
		WORD originalColor = consoleInfo.wAttributes;

		// Set the console color to green
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		if(addng_promotion_done){
			printf("\t\t\t     <<<== MENU ==>>>\n");	
			printf("\t\t\t      [%.0f%% Promo!]\n",dscnt_prcntg);
		}else{
			printf("\t\t\t     <<<== MENU ==>>>\n");
		}
		printf("\t\t      ==============================\n");
		printf("\t\t    || [n] (New Products Added!)    ||\n");
		printf("\t\t    || [1] Desktop PC Packages      ||\n");
		printf("\t\t    || [2] Laptops                  ||\n");
		printf("\t\t    || [3] SmartPhone               ||\n");
		printf("\t\t    || [4] Tablets                  ||\n");
		printf("\t\t    || [5] Keyboard                 ||\n");
		printf("\t\t    || [6] Mice                     ||\n");
		printf("\t\t    || [7] Monitor                  ||\n");
		printf("\t\t    || [8] Back to Main Page        ||\n");
		printf("\t\t    || [9] Back to Chatbot          ||\n");
		printf("\t\t    || [10] EXIT                    ||\n");
		printf("\t\t      ==============================\n");
		SetConsoleTextAttribute(hConsole, originalColor);
		// Set the console color to RED
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		printf("       \\\\ +++++++++++++++++++++++++++++++++++++++++++++++++++++ //      \n");
		printf("\t\t  Category: ");
		fgets(opt,MAX_STRING_LENGTH,stdin);
		opt[strcspn(opt, "\n")] = '\0';
		SetConsoleTextAttribute(hConsole, originalColor);

		if(strcmp(opt,"n")==0||strcmp(opt,"N")==0) {
			SetConsoleTextAttribute(hConsole, originalColor);
			getNewProducts_found = true;
			simulate_typing("\t\t  press any key to view new products");
			getch();
			system("cls");
			display_newprod();
			acceptChosenNewProducts(chosenProducts, &numProducts);

			if (numProducts > 0) {
				payment_page(chosenProducts,numProducts);
			} else {
				printf("No products chosen.\n");
			}
		} else {
			simulate_typing("\t\t  press any key to view");
			getch();
			acceptChosenProducts(chosenProducts, &numProducts);
			if (numProducts > 0) {
				payment_page(chosenProducts, numProducts);
			} else {
				printf("No products chosen.\n");
			}
		}
	}
	//condition if there are no added products 
	else {
		acceptChosenProducts(chosenProducts, &numProducts);
			//condition if the process above is done
		if (numProducts > 0) {
			payment_page(chosenProducts, numProducts);
		} else {
			printf("No products chosen.\n");
		}
	}
}
/***    FOR PREDEFINE LIST OF PRODUCTS    ***/
void acceptChosenProducts(struct Product chosenProducts[], int *numProducts) {
	int choice;
	bool chooseMore = true;
	bool loop_again = false;
	char input[MAX_STRING_LENGTH];
	cmd_view_found = false;
	// Get the console output handle
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Save the original console color settings
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD originalColor = consoleInfo.wAttributes;

	// Set the console color to green
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

	while (chooseMore && (*numProducts < MAX_PRODUCTS)) {
		system("cls");
		logo();
		// Get the console output handle
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		// Save the original console color settings
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
		WORD originalColor = consoleInfo.wAttributes;
		if(new_products_found) {
			if(loop_again) {
				// Set the console color to green
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				if(addng_promotion_done){
					printf("\t\t\t     <<<== MENU ==>>>\n");
					printf("\t\t\t      [%.0f%% Promo!]\n",dscnt_prcntg);
				}else{
					printf("\t\t\t     <<<== MENU ==>>>\n");
				}
				printf("\t\t      ==============================\n");
				printf("\t\t    || [n] (New Products Added!)    ||\n");
				printf("\t\t    || [1] Desktop PC Packages      ||\n");
				printf("\t\t    || [2] Laptops                  ||\n");
				printf("\t\t    || [3] SmartPhone               ||\n");
				printf("\t\t    || [4] Tablets                  ||\n");
				printf("\t\t    || [5] Keyboard                 ||\n");
				printf("\t\t    || [6] Mice                     ||\n");
				printf("\t\t    || [7] Monitor                  ||\n");
				printf("\t\t    || [8] Back to Main Page        ||\n");
				printf("\t\t    || [9] Back to Chatbot          ||\n");
				printf("\t\t    || [10] EXIT                    ||\n");
				printf("\t\t      ==============================\n");
				SetConsoleTextAttribute(hConsole, originalColor);
				// Set the console color to RED
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				printf("       \\\\ +++++++++++++++++++++++++++++++++++++++++++++++++++++ //      \n");
				printf("\t\t  Category: ");
				fgets(opt,MAX_STRING_LENGTH,stdin);
				opt[strcspn(opt, "\n")] = '\0';
				SetConsoleTextAttribute(hConsole, originalColor);
				sscanf(opt, "%d", &choice);
				goto opt_case;
			} else {
				SetConsoleTextAttribute(hConsole, originalColor);
				sscanf(opt, "%d", &choice);
				goto opt_case;
			}
		} else {
			// Set the console color to green
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			if(addng_promotion_done){
				printf("\t\t\t     <<<== MENU ==>>>\n");
				printf("\t\t\t      [%.0f%% Promo!]\n",dscnt_prcntg);
			}else{
				printf("\t\t\t     <<<== MENU ==>>>\n");
			}
			printf("\t\t      ==============================\n");
			printf("\t\t    || [1] Desktop PC Packages      ||\n");
			printf("\t\t    || [2] Laptops                  ||\n");
			printf("\t\t    || [3] SmartPhone               ||\n");
			printf("\t\t    || [4] Tablets                  ||\n");
			printf("\t\t    || [5] Keyboard                 ||\n");
			printf("\t\t    || [6] Mice                     ||\n");
			printf("\t\t    || [7] Monitor                  ||\n");
			printf("\t\t    || [8] Back to Main Page        ||\n");
			printf("\t\t    || [9] Back to Chatbot          ||\n");
			printf("\t\t    || [10] EXIT                    ||\n");
			printf("\t\t      ==============================\n");
		}
		SetConsoleTextAttribute(hConsole, originalColor);
		// Set the console color to RED
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		printf("       \\\\ +++++++++++++++++++++++++++++++++++++++++++++++++++++ //      \n");
		printf("\t\t  Category: ");
		fgets(input, MAX_STRING_LENGTH, stdin);
		SetConsoleTextAttribute(hConsole, originalColor);
		// Check if the input is empty (only contains a newline character)
		if (input[0] == '\n') {
			printf("\t\t  No input provided. Skipping...\n");
			getch();
			continue;
		}
		sscanf(input, "%d", &choice);
		opt_case:
		loop_again = true;
		switch (choice) {
			case 1: // Smarthphone
				system("cls");
				printf("======================================================================================\n");
				printf("||                                 ASUS SYSTEM UNITS                                ||\n");
				printf("*====================================================================================*\n");
				printf("|                                       UNIT[1]                                      |\n");
				printf("| MODEL NAME    : CZ GFX WYVERN RED (PRO)                                            |\n");
				printf("| PRICE         : PHp 68,995.00                                                      |\n");
				printf("|                                                                                    |\n");
				printf("|                           ||=====>>> SPECIFICATION <<<=====||                      |\n");
				printf("| Processor     : AMD Ryzen 5 5600X (3.7GHZ)                                         |\n");
				printf("| Graphics      : ASUS GeForce GTX 3050 TUF Gaming OC 8GB GDDR6 128Bit               |\n");
				printf("| Motherboard   : ASUS TUF B550M-Plus Gaming Wifi II                                 |\n");
				printf("| Memory        : XPG Spectrix 16GB DDR4 3600MHZ D50 RGB                             |\n");
				printf("| Storage       : XPG 1TB SX8200 Pro NVME PCIE M.2 SSD                               |\n");
				printf("| Chassis       : ASUS TUF Gaming GT301 ARGB Tempered Glass Chassis                  |\n");
				printf("| Power supply  : Silverstone SST-ST60F-ES230 600W 80+                               |\n");
				printf("| []PERIPHERALS & ACCESSORIES[]                                                      |\n");
				printf("| Keyboard      :ASUS TUF Gaming K1 RGB                                              |\n");
				printf("| Mouse         : ASUS TUF Gaming M3 RGB                                             |\n");
				printf("| Monitor       : ASUS 23.8 VP249QGR Gaming LED (Black)                              |\n");
				printf("| AVR           : 500W AVR                                                           |\n");
				printf("*====================================================================================*\n");
				printf("|[g]o back                                                                           |\n");
				printf("--------------------------------------------------------------------------------------\n\n");
				strcpy(chosenProducts[*numProducts].name, "CZ GFX WYVERN RED (PRO)");
				chosenProducts[*numProducts].price = 68995;
				break;
			case 2: // Desktop PC Package
				system("cls");
				printf("===================================================================\n");
				printf("||                        MSI LAPTOP UNITS                       ||\n");
				printf("*=================================================================*\n");
				printf("|                             UNIT[1]                             |\n");
				printf("| MODEL NAME    : MSI GF63 THIN IOUC-443PH Intel Core i7(BLACK)   |\n");
				printf("| PRICE         : PHp59,995.00                                    |\n");
				printf("|                                                                 |\n");
				printf("|        ||=====>>> SPECIFICATION <<<=====||                      |\n");
				printf("| Processor     : AMD Ryzen 9 5900X (3.7GHZ) Unlocked             |\n");
				printf("| Graphics      : NVIDIA GeForce RTX 3050 Laptop GPU, 4GB GDDR6   |\n");
				printf("|                 Up to 1222.5MHz Boost Clock, 40W Maximum        |\n");
				printf("|                 Graphics Power with Dynamic Boost               |\n");
				printf("| Memory        : 8GB DDR4 2933MHZ 2 Slots Number of SO-DIMM      |\n");
				printf("|                 Slot Max 64GB Max Capacity                      |\n");
				printf("| Storage       : Kingston 1TB NV2 PCIE NVME M.2                  |\n");
				printf("| []PERIPHERALS & ACCESSORIES[]                                   |\n");
				printf("| Monitor       : 23.8 FHD (1920X1080)                            |\n");
				printf("| +Specs        : USB Keyboard & Mouse                            |\n");
				printf("|               : LAN + WIFI + Bluetooth                          |\n");
				printf("|               : Camera | Built-In-Speakers                      |\n");
				printf("|               : HDMI OUT (2X)                                   |\n");
				printf("| OS            : Windows 10 Home                                 |\n");
				printf("| Free Software : MS Office Home & Student 2021                   |\n");
				printf("*=================================================================*\n");
				printf("|[g]o back                                                        |\n");
				printf("-------------------------------------------------------------------\n\n");
				strcpy(chosenProducts[*numProducts].name, "MSI GF63 THIN IOUC-443PH Intel Core i7(BLACK)");
				chosenProducts[*numProducts].price = 59995;
				break;
			case 3: // Monitors
				system("cls");
				printf("======================================================================================================\n");
				printf("||                                            ASUS SMARTHPHONE                                      ||\n");
				printf("*====================================================================================================*\n");
				printf("|                                                   UNIT[1]                                          |\n");
				printf("| MODEL NAME    : ASUS ROG PHONE 6                                                                   |\n");
				printf("| PRICE         : PHp 50,995.00                                                                      |\n");
				printf("|                                                                                                    |\n");
				printf("|                                     ||=====>>> SPECIFICATION <<<=====||                            |\n");
				printf("| Technology    : GSM / CDMA / HSPA / LTE / 5G                                                       |\n");
				printf("| Status        : Available Released 2022, July 13                                                   |\n");
				printf("| Announced     : 2022, July 05                                                                      |\n");
				printf("| Dimensions    : 173 x 77 x 10.3 mm (6.81 x 3.03 x 0.41 in)                                         |\n");
				printf("| Weight        : 239 g (8.43 oz)                                                                    |\n");
				printf("| Build         : Glass front (Gorilla Glass Victus), glass back (Gorilla Glass 3), aluminum frame   |\n");
				printf("| SIM           : Dual SIM (Nano-SIM, dual stand-by) IPX4 water resistant Illuminated                |\n");
				printf("|               : Illuminated RGB logo (on the back) Pressure sensitive zones (Gaming triggers)      |\n");
				printf("| Type          : AMOLED, 1B colors, 165Hz, HDR10+, 800 nits (typ), 1200 nits (peak)                 |\n");
				printf("| Size          : 6.78 inches, 109.5 cm2 (82.2% screen-to-body ratio)                                |\n");
				printf("| Resolution    : 1080 x 2448 pixels (395 ppi density)                                               |\n");
				printf("| Protection    : Corning Gorilla Glass Victus                                                       |\n");
				printf("| OS            : Android 12                                                                         |\n");
				printf("| Chipset       : Qualcomm SM8475 Snapdragon 8+ Gen 1 (4 nm)                                         |\n");
				printf("| CPU           : Octa-core (1x3.19 GHz Cortex-X2 3x2.75 GHz                                         |\n");
				printf("|                 Cortex-A710  4x1.80 GHz Cortex-A510)                                               |\n");
				printf("| GPU           : Adreno 730                                                                         |\n");
				printf("| Card slot     : No                                                                                 |\n");
				printf("| Internal      : 512GB 16GB RAM UFS 3.1 NTFS support for external storage                           |\n");
				printf("| Triple        : 50 MP, f/1.9, (wide), 1/1.56, 1.0m, PDAF 13 MP, f/2.2, (ultrawide) 5 MP, (macro)   |\n");
				printf("| Features      : LED flash, HDR, panorama                                                           |\n");
				printf("| Video         : 8K24fps, 4K 30/60/120fps, 1080p 30/60/120/240fps, 720p 480fps gyro-EIS             |\n");
				printf("| Single        : 12 MP, 28mm (wide)                                                                 |\n");
				printf("| Features      : Panorama, HDR                                                                      |\n");
				printf("| Video         : 1080p 30fps                                                                        |\n");
				printf("| Loudspeaker   : Yes, with stereo speakers (2 amplifiers)                                           |\n");
				printf("| 3.5mm jack    : Yes 32-bit/384kHz audio                                                            |\n");
				printf("| WLAN          : Wi-Fi 802.11 a/b/g/n/ac/6e, tri-band, Wi-Fi Direct, hotspot                        |\n");
				printf("| Bluetooth     : 5.2, A2DP, LE, aptX HD, aptX Adaptive                                              |\n");
				printf("| GPS           : Yes, with A-GPS. Up to dual-band: GLONASS (1), BDS (2),                            |\n");
				printf("|                  GALILEO (2), QZSS (2), NavIC                                                      |\n");
				printf("| NFC           : Yes                                                                                |\n");
				printf("| Radio         : No                                                                                 |\n");
				printf("| USB           : USB Type-C 3.1 (side), USB Type-C 2.0 (bottom), accessory connector,USB On-The-Go  |\n");
				printf("| Sensors       : Fingerprint (under display, optical), accelerometer, gyro, proximity,compass       |\n");
				printf("| Type          : Li-Po 6000 mAh, non-removable                                                      |\n");
				printf("| Charging      : Fast charging 65W, 100percent in 42 min (advertised)                               |\n");
				printf("|                 Reverse charging 10W Power Delivery 3.0 Quick Charge 5                             |\n");
				printf("*====================================================================================================*\n");
				printf("|[g]o back                                                                                           |\n");
				printf("------------------------------------------------------------------------------------------------------\n\n");
				strcpy(chosenProducts[*numProducts].name, "ASUS ROG PHONE 6");
				chosenProducts[*numProducts].price = 50995;
				break;
			case 4:
				system("cls");
				printf("=====================================================================================================================\n");
				printf("||                                                 LENOVO TABLET UNITS                                             ||\n");
				printf("*===================================================================================================================*\n");
				printf("|                                                         UNIT[1]                                                   |\n");
				printf("| MODEL NAME               : LENOVO TAB MH10 HD                                                                     |\n");
				printf("| PRICE                    : PHp 9,999.00                                                                           |\n");
				printf("|                                                                                                                   |\n");
				printf("|                                           ||=====>>> SPECIFICATION <<<=====||                                     |\n");
				printf("| PROCESSOR                : MediaTek Helio P22T (8C, 4x A53 2.3GHz + 4x A53 1.8GHz)                                |\n");
				printf("| GRAPHICS                 : Integrated IMG PowerVR GE8320 GPU                                                      |\n");
				printf("| CHIPSET                  : MediaTek SoC Platform                                                                  |\n");
				printf("| MEMORY                   : 4GB Soldered LPDDR4X                                                                   |\n");
				printf("| STORAGE                  : 64GB (eMCP4x, eMMC)                                                                    |\n");
				printf("| OPERATING SYSTEM         : Android 10                                                                             |\n");
				printf("| EXPANDABLE MEMORY        : MicroSD Card (Up to 256GB, FAT32; 1TB, exFAT)                                          |\n");
				printf("| CARD READER              : Single Nano-SIM & MicroSD Card Slot                                                    |\n");
				printf("| STORAGE SUPPORT          : 64GB eMCP4x on systemboard MicroSD card,                                               |\n");
				printf("|                            supports FAT32 file up to 256GB, exFAT file up to 1TB                                  |\n");
				printf("| FRONT CAMERA             : 5.0MP                                                                                  |\n");
				printf("| REAR CAMERA              : 8.0MP                                                                                  |\n");
				printf("| MICROPHONE               : 2x, Array                                                                              |\n");
				printf("| SPEAKERS                 : 2 side speakers, optimized with Dolby Atmos                                            |\n");
				printf("| SENSORS                  : Accelerometer (G) sensor Hall sensor Ambient light sensor (ALS) Proximity (P) sensor   |\n");
				printf("| VIBRATION MOTOR          : Eccentric Rotating Mass (ERM)                                                          |\n");
				printf("| BATTERY                  : Integrated 5000mAh                                                                     |\n");
				printf("| STANDBY TIME             : 700hr                                                                                  |\n");
				printf("| ONLINE VIDEO PLAY TIME   : 8hr                                                                                    |\n");
				printf("| BROWSING TIME            : 10hr                                                                                   |\n");
				printf("| CHARGING TIME            : Over 4.5 hr to fully charged                                                           |\n");
				printf("| POWER ADAPTER            : 5V / 2.0A                                                                              |\n");
				printf("|                                              ||=====>>> DESIGN <<<=====||                                         |\n");
				printf("| DISPLAY 10.1 HD          : (1280x800) TDDI 400nits, Touch                                                         |\n");
				printf("| TOUCHSCREEN              : 10-point Multi-touch                                                                   |\n");
				printf("| CASE MATERIAL            : Pure Metal (PC + ABS + Metal)                                                          |\n");
				printf("| PEN                      : No support                                                                             |\n");
				printf("| DIMENSIONS               : (WxDxH) 241.54 x 149.38 x 8.25 mm (9.50 x 5.88 x 0.32 inches)                          |\n");
				printf("| WEIGHT                   : 420 g (0.92lbs)                                                                        |\n");
				printf("| CASE COLOR               : Iron Grey                                                                              |\n");
				printf("|                                           ||=====>>> CONNECTIVITY <<<=====||                                      |\n");
				printf("| WLAN + BLUETOOTH         : 11a/b/g/n/ac, 1x1 + BT5.0                                                              |\n");
				printf("| VOICECALL                : LTE Call                                                                               |\n");
				printf("| STANDARD PORTS           : 1x Pogo pin connector (2-point) 1x Headphone / microphone combo jack (3.5mm)           |\n");
				printf("|                                      ||=====>>> PRE-INSTALLED SOFTWARE <<<=====||                                 |\n");
				printf("| Google Photos                                                                                                     |\n");
				printf("| Google Calendar                                                                                                   |\n");
				printf("| Dolby Atmos                                                                                                       |\n");
				printf("| Phone by Google (cellular device only)                                                                            |\n");
				printf("| Lenovo Launcher                                                                                                   |\n");
				printf("| YouTube Music                                                                                                     |\n");
				printf("| Video +                                                                                                           |\n");
				printf("| Messages (cellular device only)                                                                                   |\n");
				printf("| Google Chrome                                                                                                     |\n");
				printf("| Google                                                                                                            |\n");
				printf("| Gmail                                                                                                             |\n");
				printf("| Kids Space                                                                                                        |\n");
				printf("| Bing Wallpaper                                                                                                    |\n");
				printf("*===================================================================================================================*\n");
				printf("|[g]o back                                                                                                          |\n");
				printf("---------------------------------------------------------------------------------------------------------------------\n\n");
				strcpy(chosenProducts[*numProducts].name, "LENOVO TAB MH10 HD");
				chosenProducts[*numProducts].price = 9999;
				break;
			case 5:
				system("cls");
				printf("=====================================================================================================\n");
				printf("||                                          WIRED KEYBOARDS UNITS                                  ||\n");
				printf("*===================================================================================================*\n");
				printf("|                                                  UNIT[1]                                          |\n");
				printf("| MODEL NAME    : RAZER  BLACKWIDOW V3 TKL                                                          |\n");
				printf("| PRICE         : PHp 3,995.00                                                                      |\n");
				printf("|                                                                                                   |\n");
				printf("|                                   ||=====>>> SPECIFICATION <<<=====||                             |\n");
				printf("| SWITCH TYPE        : Razer Yellow Mechanical Switch                                               |\n");
				printf("| KEY FEEL           : Linear and Silent                                                            |\n");
				printf("| APPROXIMATE SIZES  : Tenkeyless                                                                   |\n");
				printf("| LIGHTING           : Razer Chroma RGB customizable backlighting with 16.8 million color options   |\n");
				printf("| WRIST REST         : None                                                                         |\n");
				printf("| ONBOARD MEMORY     : None                                                                         |\n");
				printf("| MEDIA KEYS         : None                                                                         |\n");
				printf("| PASSTHROUGH        : None                                                                         |\n");
				printf("| CONNECTIVITY       : Wired Attached                                                               |\n");
				printf("| KEYCAPS            : Regular ABS                                                                  |\n");
				printf("| OTHERS             : Razer  Mechanical Switches designed for gaming                               |\n");
				printf("|                      Tenkeyless form factor                                                       |\n");
				printf("|                      Razer Synapse 3 enabled                                                      |\n");
				printf("|                      Cable routing options                                                        |\n");
				printf("|                      N-key roll-over with built-in anti-ghosting                                  |\n");
				printf("|                      Fully programmable keys with on-the-fly macro recording                      |\n");
				printf("|                      Gaming mode option                                                           |\n");
				printf("|                      1000 Hz Ultrapolling                                                         |\n");
				printf("|                      Aluminum matte top plat                                                      |\n");
				printf("*===================================================================================================*\n");
				printf("|[g]o back                                                                                          |\n");
				printf("-----------------------------------------------------------------------------------------------------\n\n");
				strcpy(chosenProducts[*numProducts].name, "RAZER  BLACKWIDOW V3 TKL");
				chosenProducts[*numProducts].price = 3995;
				break;
			case 6:
				system("cls");
				printf("==================================================================================================\n");
				printf("||                                       WIRED MICE UNITS                                       ||\n");
				printf("*================================================================================================*\n");
				printf("|                                            UNIT[1]                                             |\n");
				printf("| MODEL NAME    : RAZER BASILISK V3 RGB                                                          |\n");
				printf("| PRICE         : PHp 2,750.00                                                                   |\n");
				printf("|                                                                                                |\n");
				printf("|                              ||=====>>> SPECIFICATION <<<=====||                               |\n");
				printf("| FORM FACTOR                   : Right-Handed                                                   |\n");
				printf("| CONNECTIVITY                  : Wired Razer Speedflex Cable                                    |\n");
				printf("| BATTERY LIFE                  : None                                                           |\n");
				printf("| RGB LIGHTING                  : Razer Chroma RGB                                               |\n");
				printf("| SENSOR                        : Optical                                                        |\n");
				printf("| MAX SENSITIVITY (DPI)         : 26000                                                          |\n");
				printf("| MAX SPEED (IPS)               : 650                                                            |\n");
				printf("| MAX ACCELERATION (G)          : 50                                                             |\n");
				printf("| PROGRAMMABLE BUTTONS          : 11                                                             |\n");
				printf("| SWITCH TYPE                   : 2nd-gen Razer Optical Mouse Switch                             |\n");
				printf("| SWITCH LIFECYCLE              : 70 Million Clicks                                              |\n");
				printf("| ON-BOARD MEMORY PROFILES      : 5                                                              |\n");
				printf("| MOUSE FEET                    : 100 PTFE Mouse Feet                                            |\n");
				printf("| CABLE                         : Razer Speedflex Cable                                          |\n");
				printf("| TILT SCROLL WHEEL             : 4-way Razer HyperScroll tilt wheel                             |\n");
				printf("|                               : Electronically actuated notched and free-spinning modes        |\n");
				printf("| APPROXIMATE SIZES             : Length: 130.0 mm / 5.11 in                                     |\n");
				printf("|                               : Width: 75.0 mm / 2.95 in                                       |\n");
				printf("|                               : Height: 42.5 mm / 1.65 in                                      |\n");
				printf("| APPROXIMATE WEIGHT            : 101 g / 3.56 oz (Excluding cable)                              |\n");
				printf("| DOCK COMPATIBILITY            : None                                                           |\n");
				printf("*================================================================================================*\n");
				printf("|[g]o back                                                                                       |\n");
				printf("--------------------------------------------------------------------------------------------------\n\n");
				strcpy(chosenProducts[*numProducts].name, "RAZER BASILISK V3 RGB");
				chosenProducts[*numProducts].price = 2750;
				break;
			case 7:
				system("cls");
				printf("=================================================================================\n");
				printf("||                               DELL MONITOR UNITS                            ||\n");
				printf("*===============================================================================*\n");
				printf("|                                     UNIT[1]                                   |\n");
				printf("| MODEL NAME    : DELL 27 G2722HS  165HZ IPS                                    |\n");
				printf("| PRICE         : PHp15,600.00                                                  |\n");
				printf("|                                                                               |\n");
				printf("|                       ||=====>>> SPECIFICATION <<<=====||                     |\n");
				printf("|          General                                                              |\n");
				printf("|          Display Type                      : LED-backlit LCD monitor          |\n");
				printf("|                                               TFT active matrix               |\n");
				printf("|          Panel Type                       :   IPS                             |\n");
				printf("|          Pixel Pitch                      :   0.3108 mm                       |\n");
				printf("|          Contrast Ratio                   :   1000:1                          |\n");
				printf("|                                               1000:1 dynamic                  |\n");
				printf("|          Response Time                    :   1 ms gray to gray               |\n");
				printf("|          Vertical Viewing Angle           :   178                             |\n");
				printf("|          Features                         :   LED edgelight system,           |\n");
				printf("|                                               3-sided bezeless                |\n");
				printf("|          Diagonal Size                    :   27                              |\n");
				printf("|          Aspect Ratio                     :   16:9                            |\n");
				printf("|          Pixel Per Inch                   :   81.59                           |\n");
				printf("|          Color Support                    :   16.7 million colors             |\n");
				printf("|          Gaming                           :   Yes                             |\n");
				printf("|          Screen Coating                   :   Anti-glare 3H hardness          |\n");
				printf("|          Dimensions                       :   WxDxH 24.1inx14.3inx15.5in      |\n");
				printf("|                                               with stand lowest position      |\n");
				printf("|          Adaptive Sync Technology         :   NVIDIA G-SYNC                   |\n");
				printf("|                                               Compatible Certified            |\n");
				printf("|                                               AMD FreeSync Premium            |\n");
				printf("|                                               Technology                      |\n");
				printf("|          Native Resolution                :   Full HD 1080p1920x1080at165Hz   |\n");
				printf("|          Brightness                       :   350 cd                          |\n");
				printf("|          Color Gamut                      :   99  sRGB                        |\n");
				printf("|          Horizontal Viewing Angle         :   178                             |\n");
				printf("|          Backlight Technology             :   LED backlight                   |\n");
				printf("|          Connectivity:                                                        |\n");
				printf("|          Interfaces                       :   2 x HDMI                        |\n");
				printf("|                                               DisplayPort 1.2                 |\n");
				printf("|                                               Headphones mini-jack            |\n");
				printf("|          [FOR MORE INFO READ THE PRODUCT SPECIFICATION AT THE BOX]            |\n");
				printf("*===============================================================================*\n");
				printf("|[g]o back                                                                      |\n");
				printf("---------------------------------------------------------------------------------\n\n");
				strcpy(chosenProducts[*numProducts].name, "DELL 27 G2722HS  165HZ IPS");
				chosenProducts[*numProducts].price = 15600;
				break;
			case 8:
				main();
			case 9:
				cstmr_chatbot(NULL);
				break;
			case 10:
				system("cls");
				logo();
				// Set the console color to RED
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				printf("                  ========================================  \n");
				printf("                 |     THANK YOU FOR CHOOSING CYBERZONE   | \n");
				printf("                 |           USE OUR SYSTEM AGAIN         | \n");
				printf("                 |            ANYTIME & ANYWHERE          | \n");
				printf("                  ======================================== \n");
				printf("       \\\\ +++++++++++++++++++++++++++++++++++++++++++++++++++++ //      \n");
				SetConsoleTextAttribute(hConsole, originalColor);
				simulate_typing("      press any key to continue...\n");
				getch();
				exit(0);
			default:
				SetConsoleTextAttribute(hConsole, originalColor);
				simulate_typing("\t\t  Sorry, your request is not in the option.");
				getch();
				continue;
		}
		first_qstn:
		printf("Do you want to buy this product? (y/n): ");
		fgets(input, MAX_STRING_LENGTH, stdin);
		sscanf(input, "%c", &choice);
		if (input[0] == '\n') {
			simulate_typing("No input provided. Product not added to the purchase.\n");
			chosenProducts[*numProducts].buy = false;
			getch();
			continue;
		} else if (choice == 'g' || choice == 'G') {
			chosenProducts[*numProducts].buy = false;
			cstmr_menu();
		} else if (choice == 'y' || choice == 'Y') {
			chosenProducts[*numProducts].buy = true;
			(*numProducts)++;
		} else if (choice == 'n' || choice == 'N') {
			chosenProducts[*numProducts].buy = false;
			printf("Product not added to the purchase.\n");
			continue;
		} else {
			simulate_typing("Invalid Input. Product not added to the purchase.");
			chosenProducts[*numProducts].buy = false;
			goto first_qstn;
		}
		ask_again:
		printf("Do you want to choose another product? (y/n): ");
		fgets(input, MAX_STRING_LENGTH, stdin);
		sscanf(input, "%c", &choice);
		if (choice == '\n') {
			simulate_typing("No input provided. Product not added to the purchase.");
			chosenProducts[*numProducts].buy = false;
			goto ask_again;
		}else if(choice == 'Y' || choice == 'y'){
			continue;
		}else if (choice == 'N' || choice == 'n') {
			chooseMore = false;
		}else{
			simulate_typing("Invalid input, please enter the required respond.");
			chosenProducts[*numProducts].buy = false;
			goto ask_again;
		}
	}
}
//FOR CHOSEN PRODUCTS FROM BOT NEWLY ADDED & PREDEFIED
void displayChosenProducts(struct Product chosenProducts[], int numProducts) {
	printf("_________________________________________________________________________________\n");
	printf("[Chosen Product List]\n");
	printf("+-------------------------------------------------------------------------------+\n");

	int i;
	bool hasChosenProduct = false;
	for (i = 0; i < numProducts; i++) {
		if (chosenProducts[i].buy) {
			printf(" Product %d: %s", i + 1, chosenProducts[i].name);
			hasChosenProduct = true;
			int numSpaces;
			// Adjust the number of spaces as needed
			if(strlen(chosenProducts[i].name)==45) {
				numSpaces = 3;
			} else if(strlen(chosenProducts[i].name)==26) {
				numSpaces = 22;
			} else if(strlen(chosenProducts[i].name)==24) {
				numSpaces = 24;
			} else if(strlen(chosenProducts[i].name)==23) {
				numSpaces = 25;
			} else if(strlen(chosenProducts[i].name)==21) {
				numSpaces = 27;
			} else if(strlen(chosenProducts[i].name)==18) {
				numSpaces = 30;
			} else if(strlen(chosenProducts[i].name)==16) {
				numSpaces = 32;
			}
			printf("%*s Price: Php %.2f\n", numSpaces, "", chosenProducts[i].price);
		} else if(new_products_found) {
			hasChosenProduct = true;
			printf(" Product %d: %s      Price: %.2f\n", i + 1, chosenProducts[i].name, chosenProducts[i].price);
		}
	}
	if (!hasChosenProduct) {
		simulate_typing("No products chosen.\n");
	}
}
float calculateTotalPayment(struct Product chosenProducts[], int numProducts) {
	float total = 0.0;
	int i;
	for (i = 0; i < numProducts; i++) {
		total += chosenProducts[i].price;
	}
	return total;
}
void payment_page(struct Product chosenProducts[],int numprod) {
	float totalPayment = 0;
	float cstmr_mny;
	float cstmr_chng;
	float disc_price;
	float disc;
	ask_again:
	system("cls");
	printf("=================================================================================\n");
	printf("||                          >>> PAYMENT INFORMATION <<<                        ||\n");
	printf("*===============================================================================*\n");
	displayChosenProducts(chosenProducts, numprod);
	totalPayment = calculateTotalPayment(chosenProducts, numprod);
	printf("+-------------------------------------------------------------------------------+\n");
	//for newly added promotion which is the discounted total price
	if(addng_promotion_done){
		disc = dscnt_prcntg / 100;
		disc_price = totalPayment*disc;		
		printf(" Original Payment: %.2f\n", totalPayment);
		printf(" Discounted Payment: %.2f\n",disc_price);
		printf("_________________________________________________________________________________\n");
		printf(" Cash Amount: ");
		fgets(input,MAX_LENGTH,stdin);
		input[strcspn(input, "\n")] = '\0';
		cstmr_mny = atoi(input);// Convert the input to an integer
		// Check if the conversion was successful
    	if (cstmr_mny != 0 || input[0] == '0') {
        	//scanf("%f",&cstmr_mny);
			if(cstmr_mny<disc_price) {
				simulate_typing(" Insufficient payment. Please provide correct amount...");
				getch();
				goto ask_again;
			} else {
				cstmr_chng = cstmr_mny - disc_price;
				printf(" Cash remaining after payment: %.2f\n",cstmr_chng);
				printf("*===============================================================================*\n");
				simulate_typing(" press any key to go back to main page...");
				getch();
				main();
			}
    	}else {
        	printf("Invalid input. Please enter a valid number.");
        	getch();
        	goto ask_again;
    	}
		
	}
	//for non discounted total price
	else{
		printf(" Total Payment: %.2f\n", totalPayment);
		printf("_________________________________________________________________________________\n");
		printf(" Cash Amount: ");
		//scanf("%f",&cstmr_mny);
		fgets(input,MAX_LENGTH,stdin);
		input[strcspn(input, "\n")] = '\0';
		cstmr_mny = atoi(input);// Convert the input to an integer
		// Check if the conversion was successful
    	if (cstmr_mny != 0 || input[0] == '0') {
        	//scanf("%f",&cstmr_mny);
			if(cstmr_mny<totalPayment) {
				simulate_typing(" Insufficient payment. Please provide correct amount...");
				getch();
				goto ask_again;
			} else {
				cstmr_chng = cstmr_mny - totalPayment;
				printf(" Cash remaining after payment: %.2f\n",cstmr_chng);
				printf("*===============================================================================*\n");
				simulate_typing(" press any key to go back to main page...");
				getch();
				main();
			}
    	}else { 
        	printf("Invalid input. Please enter a valid number.");
        	getch();
        	goto ask_again;
    	}	
	}
}
