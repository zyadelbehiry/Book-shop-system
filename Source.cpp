#include <iostream>
#include<string>
#include <ctime>
using namespace std;


struct Book {
	string  title, category, List_of_Authors, Publication_Year;
	float price = 0.0;
	int Quantity_in_Stock = 0, ID = 0;
};
struct	customer {
	string UserName, email, Address;
	int id = 0;
	string customer_pass;
	string phone;
};
struct dat {
	int day = 0, month = 0, year = 0;
};
struct order {

	int List_of_Book_IDs[26] = { 0 };
	double Total_price = 0;
	int customer_id;
	dat d1;
};

//global variables
Book Books[10];
customer  customers[5];
int customer_num = 3, order_num = 0, t = 2,next_id=0;
order Order[10];

//The Definitions of the functions 
void edit_info(int);
void Books_Informations();
void book1(int);
void new_order(int);
void choose(int);
void login(int);
void sign_up(customer, string);
void choose3(int);
void Show_order_Receipt();
void choose_action(int);
void previous_order(int);


void login(int) {
	
	customers[0].UserName = "zyad"; customers[0].customer_pass = "12345"; customers[0].email = "zyad@yahoo.com"; customers[0].phone = "01234567777"; customers[0].Address = "Shoubra Elkheyma";  customers[0].id = 2;
	customers[1].UserName = "eslam"; customers[1].customer_pass = "1234"; customers[1].email = "eslam@yahoo.com"; customers[1].phone = "01150311104"; customers[1].Address = "elsalam city"; customers[1].id = 1;
	customers[2].id = 3; customers[3].id = 4; customers[4].id = 5;
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Log in ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";
	cout << "Please Enter The user name \n";
	cin >> customers[customer_num].UserName;
	cout << "Please Enter The password\n";
	cin >> customers[customer_num].customer_pass;
	int j = 0,counter = 0 , wrong = 0;
	for (; j < customer_num; j++) {
		if (customers[customer_num].UserName == customers[j].UserName && customers[customer_num].customer_pass == customers[j].customer_pass) {
			customer_num = j;
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Welcome to the program ~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			choose(customer_num);
		}
	}

	for ( ; counter < customer_num; counter++) {
		if (customers[customer_num].UserName != customers[counter].UserName || customers[customer_num].customer_pass != customers[counter].customer_pass) {
			wrong += 1;
		}
		if (wrong == customer_num) {
			cout << "\nWrong Username or password\n";
			int mn = 0;
			login(mn);
		}
	}
}

void sign_up(customer, string) {
	string confirm_passowrd;
	int us = 3;
	do {
		t = 2;
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Sign Up ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";
		cout << "\nEnter your Username :\n"; cin >> customers[t].UserName;
		cout << "Enter your Email :\n"; cin >> customers[t].email;
		cout << "Enter your Phone number :\n"; cin >> customers[t].phone;
		cout << "Enter your Address :\n"; cin >> customers[t].Address;
		cout << "Enter your Password :\n"; cin >> customers[t].customer_pass;
		cout << "Enter your Password again :\n"; cin >> confirm_passowrd;
		if (confirm_passowrd != customers[t].customer_pass)
			cout << "\nYou Entered a wrong confirmed password please sign up again ! \n";

	} while (confirm_passowrd != customers[t].customer_pass);
	login(us);
}

void edit_info(int u) {

	cout << " your informations is :\n\n " << "*********************************************\n";
	cout << " your username is : " << customers[customer_num].UserName << "\n";
	cout << " your password is : " << customers[customer_num].customer_pass << "\n";
	cout << " your email is : " << customers[customer_num].email << "\n";
	cout << " your address is : " << customers[customer_num].Address << "\n";
	cout << " your phone is : " << customers[customer_num].phone << "\n";
	cout << "\n" << "********************************************";
	cout << " \n Press 1 to Edit your username  \n Press 2 to Edit your password \n Press 3 to Edit your email \n Press 4 to Edit your address \n Press 5 to Edit your phone number\n\n";
	char b;
	cin >> b;
	switch (b) {
	case '1': {
		cout << "Enter your new username \n";

		cin >> customers[customer_num].UserName;
		break; }
	case '2': {
		cout << "Enter your new password \n";

		cin >> customers[customer_num].customer_pass;
		break; }
	case '3': {
		cout << "Enter your new email \n";

		cin >> customers[customer_num].email;
		break; }
	case '4': {
		cout << "Enter your new Address \n";

		cin >> customers[customer_num].Address;
		break; }
	case '5': {
		cout << "Enter your new Phone number \n";

		cin >> customers[customer_num].phone;
		break; }
	
	default: {
		cout << "wrong input\n";
		break; 
	}
	}
	cout << " your new informations is :" << endl << endl << "**********************************************\n";
	cout << " your username is :" << customers[customer_num].UserName << "\n";
	cout << " your password is :" << customers[customer_num].customer_pass << "\n";
	cout << " your email is :" << customers[customer_num].email << "\n";
	cout << " your address is :" << customers[customer_num].Address << "\n";
	cout << " your phone is :" << customers[customer_num].phone << "\n";
	cout << " your id is :" << customers[customer_num].id << "\n\n" << "**********************************************\n";
	choose(customer_num);


}

void book1(int num) {
	
	cout << "\nPress 1 for search by category\n" << "Press 2 for search by title\n" << "press 3 for search by authors name\n"<< "press 4 to back to the previous list\n";
	char search_num = '0', WrongAns = 0, nom = 0;
	string title;
	cin >> search_num;
	int i = 0;
	switch (search_num)
	{
	case '1': {
		cout << "The exesting categories are  Comedy / Action / Classic \n\n";
		cout << "To see Comedian books press 1 \nTo see Action books press 2 \nTo see Classic books press 3 \n";
		char choosen_num='0';
		cin >> choosen_num;
		switch (choosen_num)
		{
		case '1': {
			cout << "Book 1 : " << "				" << "Book 2 : \n"
				<< "The title is : " << Books[1].title << "		" << "The title is : " << Books[4].title << "\n"
				<< "The category is : " << Books[1].category << "		" << "The category is : " << Books[4].category << "\n"
				<< "The price is : " << Books[1].price << "			" << "The price is :" << Books[4].price << "\n"
				<< "The publication year is :" << Books[1].Publication_Year << "		" << "The publication year is : " << Books[4].Publication_Year << "\n"
				<< "The List_of_Authors is :" << Books[1].List_of_Authors << "		" << "The List_of_Authors is : " << Books[4].List_of_Authors << "\n"
				<< "The Quantity_in_Stock is :" << Books[1].Quantity_in_Stock << "		" << "The Quantity_in_Stock is : " << Books[4].Quantity_in_Stock << "\n"
				<< "The Book ID is :" << Books[1].ID << "			" << "The Book ID is : " << Books[4].ID << "\n";
			int num = 0;
			choose_action(num);


			cout << "\n\n";
			break; }
		case '2': {
			cout << "Book 1 : " << "				" << "Book 2 : \n"
				<< "The title is : " << Books[0].title << "		" << "The title is : " << Books[3].title << "\n"
				<< "The category is : " << Books[0].category << "		" << "The category is : " << Books[3].category << "\n"
				<< "The price is : " << Books[0].price << "			" << "The price is :" << Books[3].price << "\n"
				<< "The publication year is :" << Books[0].Publication_Year << "		" << "The publication year is : " << Books[3].Publication_Year << "\n"
				<< "The List_of_Authors is :" << Books[0].List_of_Authors << "	" << "The List_of_Authors is : " << Books[3].List_of_Authors << "\n"
				<< "The Quantity_in_Stock is :" << Books[0].Quantity_in_Stock << "		" << "The Quantity_in_Stock is : " << Books[3].Quantity_in_Stock << "\n"
				<< "The Book ID is :" << Books[0].ID << "			" << "The Book ID is : " << Books[3].ID << "\n";
			cout << "\n\n";
			int num = 0;
			choose_action(num);

			break;
		}
		case '3': {
			cout << "Book 1 : " << "				" << "Book 2 : \n"
				<< "The title is : " << Books[2].title << "	        " << "The title is : " << Books[5].title << "\n"
				<< "The category is : " << Books[2].category << "		" << "The category is : " << Books[5].category << "\n"
				<< "The price is : " << Books[2].price << "			" << "The price is :" << Books[5].price << "\n"
				<< "The publication year is :" << Books[2].Publication_Year << "		" << "The publication year is : " << Books[5].Publication_Year << "\n"
				<< "The List_of_Authors is :" << Books[2].List_of_Authors << "		" << "The List_of_Authors is : " << Books[5].List_of_Authors << "\n"
				<< "The Quantity_in_Stock is :" << Books[2].Quantity_in_Stock << "		" << "The Quantity_in_Stock is : " << Books[5].Quantity_in_Stock << "\n"
				<< "The Book ID is :" << Books[2].ID << "			" << "The Book ID is : " << Books[5].ID << "\n";
			cout << "\n\n";
			int num = 0;
			choose_action(num);
			break;

		}
			
				default: {
			cout << "Wrong input";
			break;
		}
		}
		break;
	}
	case '2': {
		cout << "Enter The book title \n";
		cin >> title;

		for (int a = 0; a <= 5; a++) {
			if (title == Books[a].title) {
				cout << "\nThe title is : " << Books[a].title << endl;
				cout << "The category is : " << Books[a].category << endl;
				cout << "The price is : " << Books[a].price << endl;
				cout << "The publication year is : " << Books[a].Publication_Year << endl;
				cout << "The List_of_Authors is : " << Books[a].List_of_Authors << endl;
				cout << "The Quantity_in_Stock is : " << Books[a].Quantity_in_Stock << endl
					<< "The Book ID is : " << Books[a].ID << "\n";
			}
		}
		for (int counter2 = 0; counter2 <= 5; counter2++) {
			if (title != Books[counter2].title)
				WrongAns += 1;
		}
		if (WrongAns == 6)

			cout << "Not found book ! " << endl;
		book1(nom);
		
		break; }
	case '3': {
		string author;
		int wrongs = 0;
		cout << "Enter The Authors name \n";
		cin >> author;

		for (int a = 0; a <= 5; a++) {
			if (author == Books[a].List_of_Authors) {
				cout << "\nThe title is : " << Books[a].title << endl;
				cout << "The category is : " << Books[a].category << endl;
				cout << "The price is : " << Books[a].price << endl;
				cout << "The publication year is : " << Books[a].Publication_Year << endl;
				cout << "The List_of_Authors is : " << Books[a].List_of_Authors << endl;
				cout << "The Quantity_in_Stock is : " << Books[a].Quantity_in_Stock << endl;
				cout << "The Book ID is :" << Books[a].ID << endl;
			}
		}
		for (int au = 0; au <= 5; au++) {
			if (author != Books[au].List_of_Authors)
				wrongs += 1;
		}
		if (wrongs == 6)

			cout << "Not found book ! " << endl;
		book1(nom);

		break;
	}
	case '4': {
		choose(num);
		break;
	}
	default: {
		cout << "Wrong Answer\n";
		choose(num);
	}
		break;
	}

}

void new_order(int) {
	
	int k = 0;
	for (; k <= 5; k += 2)
	{

		cout << "*********************************************************************\n"
			<< "The title is : " << Books[k].title << "		" << "The title is : " << Books[k + 1].title << "\n"
			<< "The category is : " << Books[k].category << "		" << "The category is : " << Books[k + 1].category << "\n"
			<< "The price is : " << Books[k].price << "			" << "The price is :" << Books[k + 1].price << "\n"
			<< "The publication year is :" << Books[k].Publication_Year << "		" << "The publication year is : " << Books[k + 1].Publication_Year << "\n"
			<< "The List_of_Authors is :" << Books[k].List_of_Authors << "		" << "The List_of_Authors is : " << Books[k + 1].List_of_Authors << "\n"
			<< "The Quantity_in_Stock is :" << Books[k].Quantity_in_Stock << "		" << "The Quantity_in_Stock is : " << Books[k + 1].Quantity_in_Stock << "\n"
			<< "The Book ID is :" << Books[k].ID << "		      " << "The Book ID is : " << Books[k + 1].ID << "\n";
	}


	cout << "*********************************************************************\n";
	cout << "\nTo make an order please enter your book id and press 0 to stop adding books  \n ";
	int idd;
	for (int counterr = 0; counterr < 26; counterr++) {
		cin >> idd;
		if (idd >= 1001 && idd <= 1006) {
			Order[order_num].List_of_Book_IDs[counterr] = idd;
			for (int tp = 0; tp < 6; tp++) {
				if (Books[tp].ID == idd && Books[tp].Quantity_in_Stock != 0) {
					Order[order_num].Total_price += Books[tp].price;
					Books[tp].Quantity_in_Stock -= 1;
				}
				else if(Books[tp].ID == idd && Books[tp].Quantity_in_Stock == 0){
					cout << "Sold out book\n";
				
				}
					
				
			}

		}
		else if (idd == 0) {

			Show_order_Receipt();

		}
		else
			cout << "Not found book\n";
		
	}

}

void Show_order_Receipt() {
	
	int counter = next_id, num1 = 0;
	cout << "\n********************************* The order receipt **********************************\n";
	cout << "The list of book ids is : " << endl;
	for (; counter < 26; counter++) {
		if (Order[order_num].List_of_Book_IDs[counter] != 0 ) {
			cout << Order[order_num].List_of_Book_IDs[counter] << endl;
		} 
	} 
	next_id == counter;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Order[order_num].d1.day = ltm->tm_mday;	Order[order_num].d1.month = 1 + ltm->tm_mon; Order[order_num].d1.year = 1900 + ltm->tm_year;
	cout << "The Customer ID is : " << customers[customer_num].id << endl;
	cout << "The total price of books is : " << Order[order_num].Total_price << endl;
	cout << "The order date is : " << endl << Order[order_num].d1.day << "/" << Order[order_num].d1.month << "/" << Order[order_num].d1.year << endl;
	cout << "The ship date is : " << endl << Order[order_num].d1.day + 3 << "/" << Order[order_num].d1.month << "/" << Order[order_num].d1.year << endl;
	cout << "\n**************************************************************************************\n";
	order_num += 1;
	choose(num1);
	
}

void previous_order(int) {
	order previous[10];
	
	int zz=0;
	cout << "\n********************************* The Previous Orders  **********************************\n";
	for (int pl = 0; pl < order_num; pl++) {
		cout << "The list of book ids is : " << endl;
		for (int sh = 0; sh < 26; sh++) {
			if (Order[pl].List_of_Book_IDs[sh] != 0) {
				previous[pl].List_of_Book_IDs[sh] = Order[pl].List_of_Book_IDs[sh];
				cout << previous[pl].List_of_Book_IDs[sh] << endl;
			}
		}
		time_t now = time(0);
		tm* ltm = localtime(&now);
		previous[pl].d1.day = ltm->tm_mday;	previous[pl].d1.month = 1 + ltm->tm_mon; previous[pl].d1.year = 1900 + ltm->tm_year;
		previous[pl].Total_price = Order[pl].Total_price;
		cout << "The Customer ID is : " << customers[customer_num].id << endl;
		cout << "The total price of the books is : " << previous[pl].Total_price << endl;
		cout << "The order date is : " << endl<< previous[pl].d1.day << "/" << previous[pl].d1.month << "/" << previous[pl].d1.year << endl;
		cout << "The ship date is : " << endl<< previous[pl].d1.day+3 << "/" << previous[pl].d1.month << "/" << previous[pl].d1.year << endl;

		cout << "\n**************************************************************************************\n";

	}
	choose(zz);
}

void choose(int) {
	cout << "Enter 1 to Edit Information \nEnter 2 to Search for a book \nEnter 3 to add new order \nEnter 4 to Show all your previous orders \nEnter 5 to end the program\n\n";
	char y;

	cin >> y;

	switch (y) {

	case '1': {

		int v = 0;
		edit_info(v);

		break;
	}

	case '2': {

		int b3 = 0;
		book1(b3);

		break;
	}
	case '3': {
		int z = 0;
		new_order(z);

		break;
	}
	case'4': {
		int koo = 0;
		previous_order(koo);

		break; }
	case '5': {
		cout << "\n			##### Thank you for using our Book shop ####\n\n ";
		int ex=0;
		exit(ex);
		break;
	}
	default: {

		cout << "wrong input\n";

		choose(y);
		break;
	}
	}

}

void choose3(int) {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Codzella Book shop ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\nEnter 1 to Log in or 2 to Sign Up\n ";

	char log = '0', si = 0; cin >> log;

	switch (log) {

	case '1': {

		int num1 = 0;

		login(num1);

		break;
	}
	case '2': {

		customer l;
		string m;
		sign_up(l, m);

		break;
	}

	default: {

		cout << "wrong input \n\n";
		choose3(si);
		break;
	}

	}

}

void choose_action(int) {
	cout << "To add new order press 1 to back to the last list press 2 to end the program press 0\n";
	char ko = '0';
	int ok = 0;
	cin >> ko;
	switch (ko) {
	case '1': {
		new_order(ok);

		break;
	}
	case '2': {
		choose(ok);
	}
	case'0':
	{
		cout << "\nThank you for using our Book shop \n\n ";
		system("pause");
	}
	default: {
		cout << "Wrong Input";
	}
	}
}

void Books_Informations() {
	//Book 1 Informations
	Books[0].title = "Alex_ider"; Books[0].category = "Action";  Books[0].ID = 1001; Books[0].price = 99; Books[0].Publication_Year = "2002"; Books[0].Quantity_in_Stock = 5; Books[0].List_of_Authors = "A_Horowitz";
	//Book 2 Informations
	Books[1].title = "Bossypants"; Books[1].category = "Comedy"; Books[1].ID = 1002; Books[1].price = 49; Books[1].Publication_Year = "2011";  Books[1].Quantity_in_Stock = 4; Books[1].List_of_Authors = "T_Fey";
	//Book 3 Informations
	Books[2].title = "friendely"; Books[2].category = "Classic"; Books[2].ID = 1003; Books[2].price = 299; Books[2].Publication_Year = "1960"; Books[2].Quantity_in_Stock = 7; Books[2].List_of_Authors = "H_Lee";
	//Book 4 Informations
	Books[3].title = "Code_alker"; Books[3].category = "Action"; Books[3].ID = 1004; Books[3].price = 199; Books[3].Publication_Year = "1973"; Books[3].Quantity_in_Stock = 2; Books[3].List_of_Authors = "J_Bruchac";
	//Book 5 Informations
	Books[4].title = "Boy"; Books[4].category = "Comdey"; Books[4].ID = 1005; Books[4].price = 349; Books[4].Publication_Year = "1989"; Books[4].Quantity_in_Stock = 4; Books[4].List_of_Authors = "C_Elliott";
	//Book 6 Informations
	Books[5].title = "simplicity"; Books[5].category = "Classic"; Books[5].ID = 1006; Books[5].price = 499; Books[5].Publication_Year = "1813"; Books[5].Quantity_in_Stock = 1; Books[5].List_of_Authors = "J_Austen";

}



int main() {
	int x = 0;
	Books_Informations();
	choose3(x);

	int ex = 0;
	exit(ex);
	return 0;
}
