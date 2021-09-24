//Header Files
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//Global Variables

//Stores the name of file.
char FileName[16];
//Stores the size of FileName.
int size = 0;

//Stores the date, month and year of the day on which user plays the game.
char date[10];
char month[10];
char year[10];

//Stores the question number on which the user is presently on.
int ques_slab;

//Stores the question number out of 40 from the database which is displayed on the screen.
int ques_no;

//Stores the answer of the question.
char answer;

//Stores the name of the user.
char name[100];

//Stores the age of the user.
int age;

//Stores the phone number of the user.
long long phno;

//Stores the step question number which the user has just cleared.
int step_ques;

//Stores the lower limit and higher limit between which the question is picked from the database.
int low_limit;
int high_limit;

//Keeps the check of the lifelines available for the player to use.
int flip;
int fifty;

//Function Signature
void InputDate();
void Name();
void Age();
void PhoneNumber();
void GeneralInstructions();
void SetQuestionNumber(int);
void FileManagement();
char PickQuestionNumber();
char* Money(int);
char* Rupees(int);
void PrintCheque(int);
void SetStepQuestion(int);
int GetStepQuestion();
void CorrectAnswer(int);
int LifeLines(int);
void SetAnswer(char);
char GetAnswer();
void Fifty_Fifty();
char FlipTheQuestion();
void WrongAnswer(int);
void AnswerInstructions();
char CheckingAnswer(char, int);
char QuitStatement(char, int);
char LifelineChecker(char, int);
int AnswerEncoding();
char* Step(int);
void StepQuestion(int);

//Getters
int GetStepQuestion()
{
	return step_ques;
}

int GetFlip()
{
	return flip;
}

int GetFifty()
{
	return fifty;
}

char GetAnswer()
{
	return answer;
}

//Encodes each option to a specific number.
int AnswerEncoding()
{
	if (answer == 'A')
		return 0;
	else if (answer == 'B')
		return 1;
	else if (answer == 'C')
		return 2;
	else if (answer == 'D')
		return 3;
	else 
		return 4;
}

//Defines the step of the game as per the question number.
char* Step(int ques)
{
	if (ques == 4)
		return "first";
	if (ques == 9)
		return "second";
	return "none";
}

//Setters
void SetQuestionNumber (int ques)
{
	ques_slab = ques;
}

void SetStepQuestion(int ques)
{
	step_ques = ques;
}

void SetFlip(int fq)
{
	flip = fq;
}

void SetFifty(int ff)
{
	fifty = ff;
}

void SetAnswer(char ans)
{
	answer = ans;
}

//Function is used to input the date
void InputDate()
{
	int dd, mm, yy;
	printf("Enter the date in the format of DD MM YYYY.\n");
	printf("Date (only day of the month):- ");
	scanf("%d", &dd);
	//For converting days less than or equal to 9 into two digit days.
	if (dd <= 9)
	{  
		itoa(dd, date, 10); 
		// Here 10 means conversion into decimal number system.
		char c = date[0];
		date[0] = '0';
		date[1] = c;
	}
	//For conversion of reast of the days.
	else if (dd>9 && dd<=31)
	{
		itoa(dd, date, 10);
	}
	else
	{
		printf("please enter a valid date\n ");
		InputDate();
	}

	printf("Month:- ");
	scanf("%d", &mm);
	//For converting months less than October (10th month) into two digit months.
	if (mm <= 9) 
	{
		itoa(mm, month, 10);
		char c = month[0];
		month[0] = '0';
		month[1] = c;
		                        
	}
	//For rest of the months
	else if(mm>9 && mm<=12)
	{
		itoa(mm, month, 10);
	}
	else
	{
		printf("please enter a valid date \n");
		InputDate();
	}

	//Input of year is taken here.
	printf("Year:- ");
	scanf("%d", &yy);
	itoa(yy, year, 10);
}

//To take the name of the user as an input.
void Name()
{
	int i = 0;
	printf("Name:- ");
	scanf(" %c", &name[0]);
	while (name[i] != '\n')
	{
		i++;
		name[i] = getchar();
	}
	name[i] = '\0';
}

//To take the age of the user as an input
void Age()
{
	printf("Age:- ");
	scanf("%d", &age);
}

//To take the phone number of the user as an input.
void PhoneNumber()
{
	printf("Phone Number:- ");
	scanf("%lld", &phno);
}

//Printing the general instructions on the screen.
void GeneralInstructions()
{
	printf("Hello and Welcome to BITS Pilani CSIS Department presents -\n\t\tKAUN BANEGA CROREPATI\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("We, Uday Mittal, Prakhar Gupta and Shail Patel are the hosts of the game, and infront of us %s is sitting on the hot seat.\n", name);
	printf("Let's start the famous game whose name is KAUN BANEGA CROREPATI.\n\n");
	printf("Before starting the game, I will take you to the general rules of the game.\n\n");
	printf("The game consists of 13 questions with two major steps, first one at Question 4 and second one at Question 9 with Question 13 as the JACKPOT QUESTION.\n");
	printf("Each question consists of 4 options A, B, C and D. \n");
	printf("On crossing each step, a cheque will be given to you, which in all circumstances will be availed by you.\n\n");
	printf("Press any key to read the furthur instructions.\n");
	fflush(stdin);
	//fflush(stdin) is used flush any data buffer.
	getchar();
	//getchar() is used just to give a pause so that the user could take their time to read the instructions.

	printf("\n");
	printf("The prize amount for each particular question is as follows:-\n");
	printf("Question 1 \t Rs 5000\n");
	printf("Question 2 \t Rs 10000\n");
	printf("Question 3 \t Rs 20000\n");
	printf("Question 4 \t Rs 40000\n");
	printf("Question 5 \t Rs 80000\n");
	printf("Question 6 \t Rs 160000\n");
	printf("Question 7 \t Rs 320000\n");
	printf("Question 8 \t Rs 640000\n");
	printf("Question 9 \t Rs 1250000\n");
	printf("Question 10\t Rs 2500000\n");
	printf("Question 11\t Rs 5000000\n");
	printf("Question 12\t Rs 50000000\n");
	printf("Question 13\t Rs 70000000\n\n");
	printf("Press any key to read the furthur instructions.\n");
	fflush(stdin);
	getchar();

	printf("\n");
	printf("You will have two lifelines to help you out.\n");
	printf("They are \"50-50\" and \"Flip the Question\".\n\n\n");
	printf("50-50 will eliminate two of the wrong choice out of the four choices.\n");
	printf("FLIP THE QUESTION will completely change the question to another question along with a different set of options.\n\n");
	printf("SO LET'S BEGIN THE GAME.\n\n\n");
	printf("Press any key to begin the game.\n");
	fflush(stdin);
	getchar();
	printf("\n");	
}

//The instructions for answering the question has been displayed here.
void AnswerInstructions()
{
	printf("\nEnter the option which according to you suits as the answer of the question displayed below the best.\n\n");
	printf("If you want to quit the game then press 'Q' or 'q'.\n\n");

	//flip and fifty are the variables for the lifelines of 50-50 and Flip the Question.
	//The condition is included here so that the option of lifeline is provided only when they are available for the user to use.

	if (flip > 0 || fifty > 0)
	{
		printf("You may use your life-lines as well.\n");
		printf("Enter 'L' or 'l' for using lifelines.\n\n");
	}
}

//The function gives the name to the file which will be opened by the compiler during the execution of the program.
void FileManagement ()
{
	char n[3];
	//The array n is used to convert the integer into char, for eg:- In Question1.txt, 1 is converted into '1' with the help of the array n.
	FileName[0] = 'Q';
	FileName[1] = 'u';
	FileName[2] = 'e';
	FileName[3] = 's';
	FileName[4] = 't';
	FileName[5] = 'i';
	FileName[6] = 'o';
	FileName[7] = 'n';

	//If statements are used since there are both one-digit and two-digit question numbers for the user to answer.
	if (ques_slab < 10)
	{
		itoa(ques_slab, n, 10);
		FileName[8] = n[0];
		FileName[9] = '.';
		FileName[10] = 't';
		FileName[11] = 'x';
		FileName[12] = 't';
		FileName[13] = '\0';
		size = 14;
	}

	if (ques_slab >= 10)
	{
		itoa(ques_slab, n, 10);
		FileName[8] = n[0];
		FileName[9] = n[1];
		FileName[10] = '.';
		FileName[11] = 't';
		FileName[12] = 'x';
		FileName[13] = 't';
		FileName[14] = '\0';
		size = 15;
	}
}

//The function runs a random fuction and picks up a question from the pool of 40 questions allocated for each question number.
char PickQuestionNumber()
{
	srand(time(0));
	//srand(time(0)) is used so that rand() gives altogether different output when run.
	ques_no = rand() % 40;
	//Random fuction takes a random number between zero and forty and then allocates it to ques_no.

	char ans[2];
	//Stores the answer of the question displayed.
	char ques_line[1000];
	//Stores the question which is displayed on the screen for the user to answer.

	low_limit = (6 * (ques_no - 1)) + 1;
	high_limit = 6 * ques_no;
	//All files follows a pattern of question and answer. 
	//low_limit and high_limit are the upper and lower boundries to display answer and question systamatically.

	int j = 0;
	FILE *fp = fopen(FileName, "r");
	//Opens the file in reading mode.

	while (fgets(ques_line, sizeof(ques_line), fp))
	{
		j++;
		if (j >= low_limit && j < high_limit)
		{
			printf("%s", ques_line);
			//Printing the question.
		}
		if (j == (high_limit - 1))
		{
			fgets(ans, sizeof(ans), fp);
			//Storing the answer of the question
		}
	}
	fclose(fp);

	answer = ans[0];
	return answer;
	//answer is a global variable in which answer of the question is stored so that it could be accessed anywhere.
}

//Return the Money for each correct question.
char* Money(int ques)
{
	if (ques == 1)
	return "Rs 5000";
	if (ques == 2)
	return "Rs 10000";
	if (ques == 3)
	return "Rs 20000";
	if (ques == 4)
	return "Rs 40000";
	if (ques == 5)
	return "Rs 80000";
	if (ques == 6)
	return "Rs 160000";
	if (ques == 7)
	return "Rs 320000";
	if (ques == 8)
	return "Rs 640000";
	if (ques == 9)
	return "Rs 1250000";
	if (ques == 10)
	return "Rs 2500000";
	if (ques == 11)
	return "Rs 5000000";
	if (ques == 12)
	return "Rs 50000000";
	if (ques == 13)
	return "Rs 70000000";
}

//Returns the money for each correct question in words.
char* Rupees(int ques)
{
	switch (ques)
	{
		case 1:
			return "Five Thousand";
			break;
		case 2:
			return "Ten Thousand";
			break;
		case 3:
			return "Twenty Thousand";
			break;
		case 4:
			return "Forty Thousand";
			break;
		case 5:
			return "Eighty Thousand";
			break;
		case 6:
			return "One Lakh Sixty Thousand";
			break;
		case 7:
			return "Three lakhs Twenty Thosand";
			break;
		case 8:
			return "Six lakhs Forty Thousand";
			break;
		case 9:
			return "Twelve Lakhs Fifty Thousand";
			break;
		case 10:
			return "Twenty Five Lakhs";
			break;
		case 11:
			return "Fifty Lakhs";
			break;
		case 12:
			return "Five Crore";
			break;
		case 13:
			return "Seven Crore";
			break;
	}
}

//Printing the cheque on the screen. 
//Account Number is the same as that of PM Cares fund.
//Cheque Number is a random number taken from a random cheque on the Internet.
//The address of the bank is of Axis Bank located near the Pilani Campus.
//IFSC Code mentioned is of the same bank branch as mentioned above.
//The signatures mentioned are of all the three members of the team. 
//STU/O means "Student of". It has been included out of love and respect for our Instructor-in-Charge Dr. Pratik Narang. 
	
void PrintCheque(int ques)
{
	printf("\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("                AXIS BANK LTD.                                                          Valid for three months from the date of issue                                         \n");
	printf("                Vidya Vihar, Pilani, Jhunjhunu, 333031                         Date :-              | %s | %s | %s | \n", date, month, year);
	printf("                IFS Code:- UTIB001188                                                                 DD   MM   YYYY\n\n");
	printf("       Pay _________%s____________________________________________________BEARER  \n\n", name); 
	printf("       Rupees_________%s__________________________________________   \n", Rupees(ques));
	printf("         ____________________________________________________________________________ONLY              | %s |\n\n", Money(ques));  
	printf("                  | A/C. No. |  920010023235458 |         | Cheque No. | 10167477 |    \n\n");
	printf("                  //////////////////////                    Silver Privilege                            S. A. B. PATEL \n");    
	printf("                  PAYABLE AT PAR AT ALL                                                                 U. A. MITTAL        \n");
	printf("                  OUR BRANCHES IN INDIA                                                                 P. N. D. GUPTA      \n");
	printf("                                                                                   Shail Patel, Uday Mittal and Prakhar Gupta STU/O Pratik Narang \n"); 
	printf("                                                                                                        Please sign above                      \n");
	printf("                                                     || 167477 || 413211002 || 266460 || 29                                                   \n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

//Print statements to congratulate the winning user.
void CorrectAnswer(int ques)
{
	printf("\n");
	printf("********************************************Congratulations!!**************************************************\n");
	printf("Your answer is CORRECT.\n\n");
	printf("-----------------------------------------\n");
	printf("You have won %s amount of money.\n", Money(ques));
	printf("-----------------------------------------\n\n");
	printf("***************************************************************************************************************\n\n\n");
	printf("Press any key to continue. \n");
	fflush(stdin);
	getchar();
}

//The function is used to initiate the process of using the lifelines.
int LifeLines(int ques)
{
	char choice;
	//choice is used to take the entry of the choice of user to choose in between 50-50 or Flip The Question, if available.
	if (flip == 1 && fifty == 1)
	{
		printf("You have both 50-50 and Flip the Question available.\n");
		printf("Enter \'1\' for 50-50 or \'2\' for Flip the Question\n");
		scanf(" %c", &choice);
		if (choice != '1' && choice != '2')
		{
			printf("The choice entered is wrong. Try Again!\n");
			return 1;
		}
	}

	if (flip == 1 && fifty == 0)
	{
		printf("You have got only one lifeline left: Flip the Question .\n\n");
		choice = '2';
	}

	if (flip == 0 && fifty == 1)
	{
		printf("You have got only one lifeline left: 50-50 .\n\n");
		choice = '1';
	}

	if (choice == '1')
	{
		Fifty_Fifty();
		fifty--;
	}

	if (choice == '2')
	{
		char ans = FlipTheQuestion(ques);
		answer = ans;
		//answer is updated as per the new question which is displayed as per the Flip the Question lifeline.
		flip--;
	}

	return 0;
}

//Main fuction to execute 50-50 lifeline.
void Fifty_Fifty()
{
	int a = AnswerEncoding();
	int i = 0, j = 0;
	int e[2];
	//Array e stores the option which are wrong and needs to eliminated.

	while (j < 2)
	{
		srand(time(0));
		i = rand() % 4;
		//rand() helps in eliminating two options randomly.
		if (i != a)
		{
			e[j] = i;
			j++;
		}
	}

	//Checks that both the option to be eliminated are different.
	while (e[0] == e[1])
	{
		srand(time(0));
		i =  rand() % 4;
		if (i != a && i != e[0])
		{
			e[1] = i;
			break;
		}
	}

	//Opens the file.
	FILE *fp = fopen(FileName, "r");
	char ques_line[1000];
	j = 0;
	printf("\n");

	//Prints the question again such that only two options are displayed on the screen.
	while (fgets(ques_line, sizeof(ques_line), fp))
	{
		j++;
		if (j >= low_limit && j < high_limit && j != (low_limit + e[0] + 1) && j != (low_limit + e[1] + 1))
		{
			printf("%s", ques_line);
		}
	}
	fclose(fp);
}

//Main function to execute Flip the Question Lifeline.
char FlipTheQuestion()
{
	int q = 0;
	char ques_line[1000];

	while (true)
	{
		srand(time(0));
		q = rand() % 40;
		//Randomly chooses a different question from the same file.
		if (q != ques_no)
		//keeps a check that the same previous question is not chosen and displayed.
		{
			ques_no = q;
			break;
		}
	}

	low_limit = (6 * (q - 1)) + 1;
	high_limit = 6 * q;
	//New limits for printing the question has been defined.

	int j = 0;
	char ans[2];
	//Opens the file.
	FILE *fp = fopen (FileName, "r");

	while (fgets(ques_line, sizeof(ques_line), fp))
	{
		j++;
		//Prints the new question.
		if (j >= low_limit && j < high_limit)
		{
			printf("%s", ques_line);
		}
		if (j == (high_limit - 1))
		{
			fgets(ans, sizeof(ans), fp);
			//Stores the value of the answer for the new question.
		}
	}
	return ans[0];
}

//Prints the general statements for the case of wrong answer given.
void WrongAnswer(int ques)
{
	printf("\nSo Sorry!!!\nYour answer is wrong.\n\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("The correct answer is %c. \n", GetAnswer());
	printf("-----------------------------------------------------------------------------\n\n");
	int q = GetStepQuestion();
	if (q > 0)
	{
		printf("\nYou have won %s amount of money.\n", Money(q));
		PrintCheque(q);
	}
	printf("It was very nice to play along with you.\n");
	printf("Please return again and play with us. \n");
	printf("\t\t\nThank You!!!\n\n");
}

//Checks the answer entered by the user.
char CheckingAnswer(char choice, int ques)
{
	if (choice == answer)
	{
		CorrectAnswer(ques);
		if (ques == 4 || ques == 9)
		{
			SetStepQuestion(ques);
		}
		//Save the progress of the game at the two steps as mentioned in the question.
		if (ques >= 4)
		{
			PrintCheque(ques);
			printf("\nPress any key to continue\n");
			fflush(stdin);
			getchar();
		}
		//Cheque is printed only after successfully completing the first step or Question 4.
		return 'c';
	}

	else
	{
		WrongAnswer(ques);
		return 'b';
		//Executed in the case of wrong answer given.
	}
}

//Handles the situation when the user wants to quit the game.
char QuitStatement(char choice, int ques)
{
	if (choice == 'Q')
	{
		int q = ques - 1;
		if (q > 0)
		{
			PrintCheque(q);
			//Print the final cheque which the user will recieve.
		}
		return 'b';
	}
	return 'c';
}

//Handles the situation when user wants to use the lifelines.
char LifelineChecker(char choice, int ques)
{
	char c;
	if (choice == 'L')
	{
		int ch = LifeLines(ques);
		while (ch == 1)
		{
			ch = LifeLines(ques);
		}
		//ch ensures that the user selects the right option between 50-50 and Flip The Question.

		AnswerInstructions();
		//Prints the instructions for answering the question.
		char choice2;
		scanf(" %c", &choice2);
		choice2 = toupper(choice2);
		//choice2 deals with the choice which user enters in the way of answering the question.
		//choice2 is converted to upper case so that the user can enjoy the feature of case insensitive game.

		c = QuitStatement(choice2, ques);
		//Handles the situation when the user manually wants to quit the game.
		if (c == 'b')
		{
			return 'b';
		}
		c = '\0';

		c = LifelineChecker(choice2, ques);
		//The function is made recursive so that the user could choose two lifelines at the same time.
		if (c == 'b')
		{
			return 'b';
		}
		c = '\0';

		if (choice2 != 'L')
		{
			c = CheckingAnswer(choice2, ques);
			//Checks the answer entered by the user.
		}
		if (c == 'b')
		{
			return 'b';
		}
	}
	return 'c';
}

//General Instructions for the user before displaying the step questions of the game, i.e., Question 4 and Question 9.
void StepQuestion(int ques)
{
	system("cls");
	printf("\nIt is your %s step in the game.\n\n", Step(ques));
	printf("If you will answer this question correctly, then you will get atleast %s with you back home.\n", Money(ques));
	printf("Take your time and make yourself ready for the question.\n\n\n");
	printf("Enter any key to resume the game again.\n");
	fflush(stdin);
	getchar();
}

//Main function.
void main ()
{
	system("cls");
	//Clears the screen so that the user could easily play the game on a clean screen.

	printf("\n** Welcome to KAUN BANEGA CROREPATI. **\n\n");
	printf("If you want to play the game, then press any key other than 'Q' or 'q'.\n");
	printf("If you don't want to play the game, press 'Q' or 'q'.\n");
	char cond = getchar();
	//Initial option given to the user to either play the game or not.
	char ch;

	if (cond != 'Q' && cond != 'q')
	{
		//A general form is given to the user to fill.
		//It is mandatory for the user to fill.

		printf("\nPlease fill the form before we proceed.\n");
		InputDate();
		Name();
		Age();
		PhoneNumber();
		printf("\n\n\nTHANK YOU FOR FILLING THE FORM. YOU HAVE BEEN SUCCESSFULLY REGISTERED FOR THE GAME!!! \n\n");
               	printf("NOW YOU WILL COME ACROSS THE GENERAL INSTRUCTION FOR THE GAME, GO THROUGH THEM CAREFULLY. \n\n");
  	        printf("Press any key to continue.\n");
		fflush(stdin);
     	        getchar();
		system("cls");

		//General instructions of the game are displayed.
		GeneralInstructions();
		//Sets the lifeline variables, flip and fifty to 1 in a way to give all the players, irrespective of anything, two lifelines.
		SetFlip(1);
		SetFifty(1);
		//Sets the step of the question. Initally set to zero.
		SetStepQuestion(0);
		int ques = 1;

		while (ques <= 13)
		{
			//Print the general instructions while the user goes on attemption the step questions.
			if (ques == 4 || ques == 9)
			{
				StepQuestion(ques);
			}

			//General instructions for the Jackpot Question.
			if (ques == 13)
			{
				printf("You have reached to the end of the game.\n\n");
				printf("**** This is the JACKPOT QUESTION!!! **** \n\n");
				printf("Think twice before answering it because if you lose, you will get only Rs 1250000 but if you quit then you will win Rs 50000000. \n\n");
				printf("Answer the question only if you are sure about your answer.\n");
				printf("--------------------------------------------------\n\n");
				printf("All the Very Best to You!!!!\n");
				printf("May God Bless You with Wisdom and You Win The Game!!!\n");
				printf("Prepare yourself before attempting the question.\n\n\n");
				printf("Press any key to resume the game.\n");
				fflush(stdin);
				getchar();
			}

			system("cls");
			//Start of the game.
			printf("\t\t\t\t\t\tKAUN BANEGA CROREPATI\n\n");
			printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
			//Printing question number on the screen.
			printf("\nQuestion %d is there on the screen -\n\n", ques);
			SetQuestionNumber(ques);
			//Name the file to be opened.
			FileManagement();
			//Choose the question to be displayed and then returns the answer for the question.
			char ans = PickQuestionNumber();
			ans = GetAnswer();

			//Updates the availability of the lifelines.
			int flip = GetFlip();
			int fifty = GetFifty();

			//Print general instructions for answering the question.
			AnswerInstructions();
			//Asks the user to enter their choice.
			char choice;
			scanf(" %c", &choice);
			//Converts the input to upper case to make the game case insensitive.
			choice = toupper(choice);

			//Checks for the quit option if entered by the user.
			if (choice == 'Q')
			{
				ch = QuitStatement(choice, ques);
			}
			//The letter 'b' returned by the functions is considered as break while the letter 'c' is considered as continue.
			if (ch == 'b')
			{
				break;
			}
			ch = '\0';

			//Checks for the lifeline.
			if (choice == 'L' && (flip > 0 || fifty > 0))
			{
				ch = LifelineChecker(choice, ques);
			}
			if (ch == 'b')
			{
				break;
			}
			//Continues the loop if the lifeline function gives a green signal.
			if (ch == 'c')
			{
				ques++;
				continue;
			}
			ch = '\0';

			//Checks for the corectness of the answer.
			ch = CheckingAnswer(choice, ques);
			if (ch == 'b')
			{
				break;
			}
			ques++;

		}//End of loop

		//Congratualate the user for completing the game.
		if (ques == 14)
		{
			printf("\n********************************************Congratulations!!**************************************************\n\n");
			printf("You have won the game.\n");
			printf("You are a Genius!!!\n");
			printf("May God Bless You with all the Endeavours of Your Life!!!\n");
			printf("It was nice playing with you.\n");
		}
	
	}//End of the if statement.

}//End of main function.

//End of the Program.