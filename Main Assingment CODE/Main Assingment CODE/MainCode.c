//Thanh Phan u3175008 Main Assignment
//Semester 1

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//Name
char name1[30];
char name2[30];

//Job
char jobOption[30];

//Meal
char mealOption[30];


//Others
int noOfServing;
int tableNo;
//int jobNo;
int mealNo;

//Invoice
float cost;
float grossCost;
float discount;
float tax;
float totalCost;
float VAT = 0.08;

//Look up Meal
void lookupMeal() {

	if (strcmp(mealOption, "D") == 0) {
		strcpy_s(mealOption, 30, "Date Cake");
	}

	if (strcmp(mealOption, "S") == 0) {
		strcpy_s(mealOption, 30, "Strawberry dessert");
	}

	if (strcmp(mealOption, "B") == 0) {
		strcpy_s(mealOption, 30, "Beef Sandwich");
	}

	if (strcmp(mealOption, "C") == 0) {
		strcpy_s(mealOption, 30, "Cheese Sandwich");
	}
}

//Job's menu
void jobMenu() {
	printf("\nInput your job section from the following selection\n");
	printf("E - Exit\n");
	printf("A - Astronaut\n");
	printf("S - Science\n");
	printf("P - Public Relations\n");

	do {
		printf("Enter Selection: ");
		fseek(stdin, 0, SEEK_END);
		scanf("%s", &jobOption, 30);
		strupr(jobOption);

		if (strcmp(jobOption, "E") == 0) {
			exit(0);
		}

		//If the option is not equal to the option Given from the job section then print Error   
		else if ((strcmp(jobOption, "E") != 0) && (strcmp(jobOption, "A") != 0) && (strcmp(jobOption, "S") != 0) && (strcmp(jobOption, "P") != 0)) {
			printf("\nError - must be one of E.A.S.P\n\n");
		}

	} while ((strcmp(jobOption, "E") != 0) && (strcmp(jobOption, "A") != 0) && (strcmp(jobOption, "S") != 0) && (strcmp(jobOption, "P") != 0));
}

//Meal's menu
void mealMenu() {
	printf("\nInput the meal you want from following menu: \n");
	printf("E - Exit\n");
	printf("D - Date Cake\n");
	printf("S - Strawberry dessert\n");
	printf("B - Beef Sandwich\n");
	printf("C - Cheese Sandwich\n");

	do {
		printf("Enter selection: ");
		fseek(stdin, 0, SEEK_END);
		scanf("%s", &mealOption, 30);
		strupr(mealOption);
		lookupMeal; // LookUP for the name of the Meal have choosen then display on invoice Table

		if (strcmp(mealOption, "E") == 0)
		{
			exit(0);
		}

		if ((strcmp(mealOption, "E") != 0) && (strcmp(mealOption, "D") != 0) && (strcmp(mealOption, "S") != 0) && (strcmp(mealOption, "B") != 0) && (strcmp(mealOption, "C") != 0)) {
			printf("\nError - must be one of E.D.S.B.C\n\n");
		}



	} while ((strcmp(mealOption, "E") != 0) && (strcmp(mealOption, "D") != 0) && (strcmp(mealOption, "S") != 0) && (strcmp(mealOption, "B") != 0) && (strcmp(mealOption, "C") != 0));


	//Jane Tully suffer from fatal allergic reaction
	if ((strcmp(name1, "JANE") == 0) && (strcmp(name2, "TULLY") == 0) && (strcmp(mealOption, "S") == 0)) {
		printf("\nError %s thats not in your diet\n", name1);
		mealMenu();
	}

}

//Number of servings
void numberofOrder() {

	do {

		printf("\nEnter the number of servings (1 to 12): ");
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &noOfServing);

		if (noOfServing <= 0) {
			exit(0);
		}

		if (noOfServing > 12) {
			printf("\nInvalid number! Enter again!\n");
		}

	} while (noOfServing < 1 || noOfServing > 12);

}

//Table number
void tableNumber() {

	do {
		printf("\nWhich table are you at (1 to 32): ");
		fseek(stdin, 0, SEEK_END);
		scanf_s("%d", &tableNo);

		if (tableNo <= 0) {
			exit(0);
		}

		else if (tableNo > 32) {
			printf("\nInvalid number! Enter again!\n");
		}

	} while (tableNo < 1 || tableNo > 32);
}

//Calculation and Invoice Table
void invoice() {
	//Job
	if (strcmp(jobOption, "A") == 0) {

		strcpy_s(jobOption, 30, "Astronaut");

		if (strcmp(mealOption, "D") == 0) { cost = 1.0; }
		else if (strcmp(mealOption, "S") == 0) { cost = 1.0; }
		else if (strcmp(mealOption, "B") == 0) { cost = 0.0; }
		else if (strcmp(mealOption, "C") == 0) { cost = 0.0; }

		//Calculation
		grossCost = cost*noOfServing;
		tax = 0;
		if (noOfServing >= 3) {
			discount = grossCost*0.05;
			totalCost = grossCost - discount;
		}
		else {
			discount = 0;
			totalCost = grossCost;
		}
	}

	if (strcmp(jobOption, "S") == 0) {
		strcpy_s(jobOption, 30, "Science");

		if (strcmp(mealOption, "D") == 0) { cost = 5.0; }
		else if (strcmp(mealOption, "S") == 0) { cost = 7.41; }
		else if (strcmp(mealOption, "B") == 0) { cost = 5.50; }
		else if (strcmp(mealOption, "C") == 0) { cost = 4.90; }

		//Calculation
		grossCost = cost*noOfServing;
		tax = 0;

		if (noOfServing >= 3) {
			discount = grossCost*0.05;
			totalCost = grossCost - discount;
		}
		else {
			discount = 0;
			totalCost = grossCost;
		}
	}

	if (strcmp(jobOption, "P") == 0) {
		strcpy_s(jobOption, 30, "Public Relations");

		if (strcmp(mealOption, "D") == 0) { cost = 6.0; }
		else if (strcmp(mealOption, "S") == 0) { cost = 7.50; }
		else if (strcmp(mealOption, "B") == 0) { cost = 6.5; }
		else if (strcmp(mealOption, "C") == 0) { cost = 7.0; }


		//Calculation
		grossCost = cost*noOfServing;
		if (noOfServing >= 3) {
			discount = grossCost*0.05;
			tax = (grossCost - discount)*VAT;
			totalCost = grossCost - discount + tax;
		}

		else {
			discount = 0;
			tax = grossCost*VAT;
			totalCost = grossCost + tax;
		}
	}
}


//Add up all the sperate void to run The correct order of the requiment 
void main() {
	//Add all void together 
	printf("\n****Welcome to the Bake-off food system***\n");
	printf("\nPlease Input your name or Enter (Portal Song to get the Lyrics): ");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%s %s", name1, 30, name2, 30);
	strupr(name1);
	strupr(name2);

	if ((strcmp(name1, "PORTAL") == 0) && (strcmp(name2, "SONG") == 0)) {
		printf("\n This was a triumph");
		printf("\n Im making a note here; Huge success");
		printf("\n My satisfaction");
		printf("\n Aperture Science :");
		printf("\n We do what we must");
		printf("\n Because we can");
		printf("\n For the good of all of us");
		printf("\n Except the ones who are dead");
		printf("\n But there is no sense crying");
		printf("\n Over every mistake");
		printf("\n You just keep on trying");
		printf("\n Till you run out of cake");
		printf("\n And the science gets done");
		printf("\n And you make a neat gun");
		printf("\n For the people who are");
		printf("\n Still alive");
		printf("\n Im not even angry");
		printf("\n Im being so sincere right now");
		printf("\n Even though you broke my heart,");
		printf("\n And killed me");
		printf("\n And tore me to pieces");
		printf("\n And threw every piece into a fire");
		printf("\n As they burned it hurt because");
		printf("\n I was so happy for you");
		printf("\n Now, these points of data");
		printf("\n Make a beautiful line");
		printf("\n And we are out of beta");
		printf("\n We are releasing on time");
		printf("\n So Im GLaD I got burned");
		printf("\n Think of all the things we learned -");
		printf("\n For the people who are");
		printf("\n Still alive");
		printf("\n Go…\n\n");
		main();
	}

	jobMenu(); // Recall to display Job on invoice Table
	mealMenu(); // Recall to Use Menu options
	numberofOrder(); // Recall to display number of servinngs on invoice Table
	tableNumber();// Recall to display number of the table have choosen on invoice Table
	invoice();// Look up for the calculation


			  //Free Date cake for service department staff member Rubens May//
	if ((strcmp(jobOption, "Science") == 0) && (strcmp(name1, "RUBENS") == 0) && (strcmp(name2, "MAY") == 0) && (strcmp(mealOption, "D") == 0)) {
		discount = 0;
		tax = 0;
		totalCost = 0;
	}

	lookupMeal(); // LookUP for the name of the Meal have choosen then display on invoice Table
				  //Invoice Table 
	printf("----------------------------------------------------------------\n");
	printf("Name          : %s %s\n", name1, name2);
	printf("Job Section   : %s\n", jobOption);
	printf("Meal          : %s\n", mealOption);
	printf("Servings      : %d\n", noOfServing);
	printf("Table number  : %d\n\n", tableNo);
	printf("Product Cost  : $%10.2f\n", cost);
	printf("Gross Cost    : $%10.2f\n", grossCost);
	printf("Discount      : $%10.2f\n", discount);
	printf("Tax Cost      : $%10.2f\n", tax);
	printf("Nett Cost     : $%10.2f\n", totalCost);
	printf("----------------------------------------------------------------\n");

	//Say Freaking thanks to astronaut
	if (strcmp(jobOption, "Astronaut") == 0) {
		printf("%s %s Enjoy the good tucker\n", name1, name2);
		printf("----------------------------------------------------------------\n\n");
	}

	//Repeat the Program again
	main();

	_getch();
}




