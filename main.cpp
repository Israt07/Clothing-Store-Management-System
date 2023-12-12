#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<regex>
#include<string>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include <dos.h>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <ctype.h>
#include <stdlib.h>


using namespace std;

void Login();
void CustomerMenu();
void Register();

void CustomerMainMenu(string m1);
void CustomerLogin();
void AddOrder(string m1);
void viewlist(string m1);
void customersearch(string m1);
void Receipt(string m1);
void Payment(string m1);
void Exit();

void ClothMenuPage();
void AddItem();
void UpdateItem();
void SearchItem();
void ViewMenu();
void DeleteItem();
void ShowAdminReport();


void deleteFromCart(string m1);
char c_option;
char frontChar;

bool check_number(string str);

int customerID;
static string condition="";
int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
MYSQL* connectdatabase() {
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "csms", 3306, NULL, 0);
	if (conn) {
		cout << "Successfully connected to database " << endl;
		return conn;
	}
	else {
		cout << "Failed to connect to database" << endl;
		return conn;
	}
}

COORD c;            //global veriable
    void gotoxy(int x, int y)
    {
        c.X=x;
        c.Y=y;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    }

int main()

{

	system("CLS");

	MYSQL* conn = connectdatabase();

	system("CLS");
	cout << ("\n\n\t\t\t\t     =============================================== ") << endl;
	cout << "\t\t\t\t     |                                             |" << endl;
	cout << "\t\t\t\t     |         WELCOME To ISRAT'S STORE        |" << endl;
	cout << "\t\t\t\t     |                                             |" << endl;
	cout << ("\t\t\t\t     =============================================== \n") << endl;
	gotoxy(45,6); cout<<"------------------------------"<<endl;
	gotoxy(45,7); cout<<"| CLOTHING STORE MANAGEMENT SYSTEM |"<<endl;
	gotoxy(45,8); cout<<"------------------------------"<<endl;
	gotoxy(0,9); cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

    gotoxy(45,10);cout << "Front Menu Options::" << endl << endl;

	gotoxy(45,11);cout << "1.Admin" << endl;
	gotoxy(45,12);cout << "2.Customer" << endl;
	gotoxy(45,13);cout << "3.Exit" << endl << endl;;

	cout << "Enter your choice here: ";
	string choice;
	cin >> choice;


	if (choice == "1")
	{
		Login();
	}
	else if (choice == "2")
	{
            CustomerMenu();
	}
	else if (choice == "3")
	{
	    cout<<"Thanks for using our system.";
		Exit();

	}
	else
	{
		cout << "Wrong keyword!!!!!!!" << endl;
		cout << "Press any key to go to	Main Login Page again" << endl;
		_getch();
		main();
	}


	return 0;
}

void CustomerMenu(){

	system("CLS");
	gotoxy(45,3);cout << "*******************             Welcome To         ********************* " << endl;
	gotoxy(45,4);cout << "*******************      Customer Section Page   **********************" << endl << endl;


	cout << "Options::" << endl << endl;

	gotoxy(45,11);cout << "1.Customer Registration" << endl;
	gotoxy(45,12);cout << "2.Customer Login" << endl;
	gotoxy(45,13);cout << "3.Go Back to Main Menu" << endl;
    gotoxy(45,14);cout << "4.Exit" << endl<<endl;


	cout << "Enter your choice here: ";
	string choice;
	cin >> choice;

	if (choice == "1")
	{
		Register();
	}
	else if (choice == "2")
	{
		CustomerLogin();
	}

	else if (choice == "3")
	{
		main();


	}

	else if (choice == "4")
	{
	    cout<<"Thanks for using our Clothing Store Management System.";
		Exit();

	}

	else{

       cout<<"\n\nThanks for using our Clothing Store Management System.\nPlease Key in the correct Input type.\nKey-in Enter to start over\n";
       system("pause");
       CustomerMenu();
	}

}
void Login()
{

    string m="";
	system("CLS");
	MYSQL* conn = connectdatabase();
	int qstate = 0;
	stringstream ss;

	string username = "israt";
	string password = "333555";
	string username1, password1;
    cout<<"\n\nPlease key in your Login Credentials or(m) to back."<<endl<<endl;
	gotoxy(45,11);cout << "Enter Username :";


	cin >> username1;

	if (username1=="m"){
        main();
	}

for (int i=0; i<100;i++){
	if(isdigit(username1[i]) ){
            if (i==0){
  cout<<"\n\nUsername invalid:The username must not start with an integer.\nPlease hit enter start over"<<endl;
  system("pause");
  Login();

            }
    }
}

	gotoxy(45,14);cout << "Password :";
	cin >> password1;

    if (password1=="m"){
    main();

}
if(password1.length()<=3){
  cout<<"\n\nPassword invalid:The password must be a minimum of 4 charachters.\nPlease click enter start over"<<endl;
    system("pause");
    Login();
}

int epsilion=0;
int count=0;

while(isalnum(password1[epsilion])){
    epsilion++;

     if(isdigit(password1[epsilion]))
       count++;

       if(count==1){

        break;
       }
       else{
        cout<<"The password is not alphanumeric character.\n\nClick Enter to try again.";
        system("pause");
        Login();

       }

}


	if (username1 == username && password1 == password)
	{
		system("CLS");
		cout << "Login Successfully" << endl;

		ClothMenuPage();


	}


	else {
		cout << "Wrong Credentials...Press any key to go to Login Page Again" << endl;
		_getch();
		Login();
	}
}

void CustomerMainMenu(string m1) {
	system("CLS");
	gotoxy(45,9);cout << "*********** CUSTOMER MAIN MENU ******** " << endl;


	gotoxy(45,11);cout << "1.Add Order: " << endl;
	gotoxy(45,12);cout << "2.view list: " << endl;
	gotoxy(45,13);cout << "3.customer search: " << endl;
	gotoxy(45,14);cout << "4.Receipt:   " << endl;
	gotoxy(45,15);cout << "5.Payment: "<<endl;
	gotoxy(45,16);cout << "6.Exit:      " << endl << endl;;



	cout << "Enter your choice here: ";
	string choice;
	cin >> choice;


	if (choice == "1")

		AddOrder(m1);

    else if (choice == "2")
	{
		viewlist(m1);
	}

	else if (choice == "3")
	{
		customersearch(m1);
	}

	else if (choice == "4")
	{
		Receipt(m1);
	}

	else if (choice == "5")
	{
		Payment(m1);
	}


	else if (choice == "6")
	{
		main();
	}
	else
	{
		cout << "Wrong keyword!!!!!!!" << endl;
		cout << "Press any key to go to Customer Main MenuPage" << endl;
		_getch();
		CustomerMainMenu(m1);
	}

}


void Payment(string m1){

MYSQL* conn = connectdatabase();

bool paymentStatus=false;

    string status="Added to Cart";
	system("CLS");
	int qstate = 0;
	double Total;
	stringstream ss;
	gotoxy(45,9);cout << "**********MY CART************ " << endl;

string selectQuery="select * from orderlist where CustomerID='"+m1+"' AND Status= '"+status+"'";
const char* qq=selectQuery.c_str();
	qstate = mysql_query(conn,qq);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{
			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << endl  << "Order ID: " << row[0] << endl  << "Item Quantity: " << row[1] << endl << "Item Price: " << row[4] << endl  <<  "Item: " << row[5] << endl  << endl;
			cout << "------------------------------------------------------------------------------------------------" << endl;

		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}


  int num1;
    cout << "1. Remove products from cart."<<endl;
    cout << "2. Confirm Payment" << endl;
    cout<<  "3.Go Back"<<endl;
cin>>num1;

    switch (num1) {
        case 1:
          deleteFromCart(m1);
            break;
        case 2:
paymentStatus=true;


    if(paymentStatus){

int transactionChoice=0;
           cout<<"1.Pay by Card"<<endl;
           cout<<"2.Pay by Cash"<<endl;

cin>>transactionChoice;

if(transactionChoice==1){

string paymentMethod="Card";
  int cardNubmer=0;
    cout<<"Enter Card Number:";
    cin>>cardNubmer;

    int k=cardNubmer%10000;
  stringstream ss1;
  ss1<<k;
  string stringCard;
  ss1>> stringCard;


    stringstream ss;

    ss << " SELECT SUM(Price) as Total From orderlist";



			string query = ss.str();
			const char* qm = query.c_str();
			qstate = mysql_query(conn, qm);
			if (qstate == 0)
			{

				res = mysql_store_result(conn);
				row = mysql_fetch_row(res);
				stringstream geek(row[0]);
				geek >> Total;
				stringstream sq;
				sq << "INSERT INTO receipt(CustomerID,TotalPrice,CardNumber,paymentMethod) VALUES ('" << m1 << "','" << Total << "','"<<stringCard<<"','"<<paymentMethod<<"')";
				query = sq.str();
				const char* qp = query.c_str();
				qstate = mysql_query(conn, qp);


            if(qstate==0){

                        cout << "Payment Successfully Confirmed "<< endl << endl;

}
else {
    cout<<"Problem"<<endl;
}
cout<<"Payment Done"<<endl;
system("pause");
CustomerMainMenu(m1);

			}
			else {
				//cout << "Failed To Insert Into Database" << endl;
				//cout << "Wrong Keyword!! Please Try Again ";


			}


//internal switch break

}

else if (transactionChoice==2){

    string paymentMethod="Cash";
  int cardNubmer=000000000;


    int k=cardNubmer%10000;
  stringstream ss1;
  ss1<<k;
  string stringCard;
  ss1>> stringCard;


    stringstream ss;

    ss << " SELECT SUM(Price) as Total From orderlist";



			string query = ss.str();
			const char* qm = query.c_str();
			qstate = mysql_query(conn, qm);
			if (qstate == 0)
			{

				res = mysql_store_result(conn);
				row = mysql_fetch_row(res);
				stringstream geek(row[0]);
				geek >> Total;
				stringstream sq;
				sq << "INSERT INTO receipt(CustomerID,TotalPrice,CardNumber,paymentMethod) VALUES ('" << m1 << "','" << Total << "','"<<stringCard<<"','"<<paymentMethod<<"')";
				query = sq.str();
				const char* qp = query.c_str();
				qstate = mysql_query(conn, qp);


            if(qstate==0){

                        cout << "Payment Successfully Confirmed "<< endl << endl;

}
else {
    cout<<"Problem"<<endl;
}

cout<<"Payment Done"<<endl;
system("pause");
CustomerMainMenu(m1);

			}
			else {
				//cout << "Failed To Insert Into Database" << endl;
				//cout << "Wrong Keyword!! Please Try Again ";


			}

}


    }


            break;

        case 3:
            CustomerMainMenu(m1);

        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! The operator is not correct";
            break;


}
}

bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

void Register() {


cin.clear();
cin.ignore(1000,'\n');
	MYSQL* conn = connectdatabase();

    string g;
	system("CLS");
	gotoxy(45,9);cout << "*********************  CUSTOMER REGISTRATION   ***************** " << endl;

	int qstate = 0;
	stringstream ss;
	string CustomerName, phoneNumber,password;

    cout << "Enter Customer Name(or press g to go back) :";
	getline(cin, CustomerName);

	if(CustomerName=="g"){
        CustomerMenu();
	}

labelPhone:
	cout << "Enter Phone Number(or press g to go back) :";
	getline(cin, phoneNumber);
if(phoneNumber=="g"){
        CustomerMenu();
	}
	int phoneNumberInt=atoi(phoneNumber.c_str());


 if (check_number(phoneNumber))
{
//Valid Phone
}
   else
      cout<<"Invalid Phone: The input value is NOT a number."<<endl;




if (phoneNumber.size()==10){
    //valid phone
}
else{
     cout<<"Phone number must be 10 digits.Try again"<<endl;
     goto labelPhone;
}

	cout<<"Enter Password(or press g to go back): ";
	cin>>password;

if(password=="g"){
        CustomerMenu();
	}

if(password.length()<=3){
  cout<<"\n\nPassword invalid:The password must be a minimum of 4 characters.\nPlease click enter start over"<<endl;
    system("pause");
    Login();
}

int epsilion=0;
int int_count=0;
int String_count=0;

while(isalnum(password[epsilion]) && epsilion<password.length()){
    epsilion++;


    //cout<<"The password is not alphanumberic charachter.\n\nHit Enter to try again.";


}

	ss << "INSERT INTO customer(CustomerName,PhoneNumber,password) VALUES ('" + CustomerName + "','" + phoneNumber + "','"+password+"')";
	string query = ss.str();
	const char* qx = query.c_str();
	qstate = mysql_query(conn, qx);
	if (qstate == 0)
	{
		cout <<  "Record inserted in the system" << endl;


		stringstream sq;
		sq << "select * from customer where CustomerName = '" + CustomerName + "' and PhoneNumber = '" + phoneNumber + "'";
		string query = sq.str();
		const char* qm = query.c_str();
		qstate = mysql_query(conn, qm);


		if (qstate == 0)
		{
			res = mysql_store_result(conn);
			if ((row = mysql_fetch_row(res)))
			{
				customerID = atoi(row[0]);

			}

			cout<<"Registered Successfully"<<endl;
		}


		cout << "Press any key to go to Customer Login ";
		_getch();
        CustomerLogin();
	}
	else {
		cout << "failed to insert in the system";
		Register();
	}


}

void Exit()
{

exit(0);
}

void CustomerLogin()

{

   system("CLS");
	MYSQL* conn = connectdatabase();
      string cust_username="";
      string cust_password="";

     int currentchoice;
            int choose = 0;
            char c = '*';
            system("cls");
            gotoxy(45,9);cout << "*********************  CUSTOMER LOGIN   ***************** " << endl;
            cout<<"\n\n"<<endl;

            cout<<"Enter Username: ";
            cin>>cust_username;

         cout << "Password: ";
            cin>>cust_password;

            if(cust_password.length()<=3){
  cout<<"\n\nPassword invalid:The password must be a minimum of 4 characters.\nPlease click enter start over"<<endl;
    system("pause");
    Login();
}

int epsilion=0;
int count=0;

while(isalnum(cust_password[epsilion])){
    epsilion++;

     if(isdigit(cust_password[epsilion]))
       count++;

       if(count==1){

        break;
       }
       else{
        cout<<"The password is not alphanumeric character.\n\nClick Enter to try again.";
        system("pause");
        Login();

       }

}

            string login_query = "select * from customer where CustomerName  = '"+cust_username+"' and password = '"+cust_password+"' ";
            const char* qn = login_query.c_str();
            qstate = mysql_query(conn, qn);
            if (!qstate) //if success
            {
                res = mysql_store_result(conn);
                if ((row = mysql_fetch_row(res)))
                {
                // if user login

                        cout<<"User successfully logged in "<<endl;
                          int derive_custId = atoi(row[0]);

                            stringstream cusIdString;
                            cusIdString <<derive_custId;
                            string custIdString =   cusIdString.str();

                        Sleep(1);

                     CustomerMainMenu(custIdString);
                        system("cls");

                }
                else{
                cout << "Wrong keyword...Press any key to go to Login Page Again" << endl;
                _getch();
		        Login();

                        }
                }
            }


void ClothMenuPage()
{

	system("CLS");

	gotoxy(45,9);cout << "************** ADMIN MENU PAGE  ************ " << endl;
	gotoxy(45,11);cout << "1.Add item      " << endl;
	gotoxy(45,12);cout << "2.Update item   " << endl;
	gotoxy(45,13);cout << "3.Search item   " << endl;

	gotoxy(45,14);cout << "4.View Menu     " << endl;
	gotoxy(45,15);cout << "5.Delete item   " << endl;
    gotoxy(45,16);cout << "6.Show Report   " << endl;
	gotoxy(45,17);cout << "7.Exit          " << endl;


	gotoxy(45,18);cout << "Enter your choice here: ";
	string choice;
	cin >> choice;

	if (choice == "1")
	{
		AddItem();
	}
	else if (choice == "2")
	{
		UpdateItem();
	}
	else if (choice == "3")
	{
		SearchItem();
	}

	else if (choice == "4")
	{
		ViewMenu();
	}
	else if (choice == "5")
	{
		DeleteItem();
	}

	else if (choice == "6")
	{
	ShowAdminReport();
	}
	else if (choice == "7")
	{
          main();
	}
	else
	{
		cout << "Wrong Input!!!!!!"<<endl;
		cout << "Press any key to go to product menu page" << endl;
		_getch();
		ClothMenuPage();
	}

}

void AddItem()
{



	system("CLS");
	gotoxy(45,0);cout << "***** ADD ITEM ****** " << endl;

	MYSQL* conn = connectdatabase();

	int qstate = 0;
	stringstream ss;
	string ID, Name, Price, Quantity;
	string fabric="";

	getline(cin, Name);

	cout << "1.Add Item Name    :";
	getline(cin, Name);

labelPrice:
   cout << "2.Add Item Price: ";
	getline(cin, Price);

	int PriceInt=atoi(Price.c_str());

if (PriceInt>0 && PriceInt<=10000)
{
//cout<<Intgeger
}
    else{

    cout<<"Input is not a integer.Please key in an appropriate value for the price"<<endl;

    goto labelPrice;

    }

labelFabric:
    cout << "3.Add Item Fabric: ";
	getline(cin, fabric);

	if (fabric=="Cotton" || fabric=="Silk" || fabric=="Velvet" || fabric=="Chiffon"){
        //true
	}
	else{
    cout<<"Please key in the correct fabric.Please key in an appropriate value for the price"<<endl;

    goto labelFabric;
	}


	ss << "INSERT INTO clothmenu(ClothName,Price,fabric) VALUES ('" + Name + "','" + Price + "','"+fabric+"')";
	string query = ss.str();
	const char* qf = query.c_str();
	qstate = mysql_query(conn, qf);
	if (qstate == 0)
	{
		cout <<  "This item has been successfully inserted" <<  endl;;

		cout <<  "Press any key to go to Cloth Menu Page" <<  endl;
		_getch();
		ClothMenuPage();
	}
	else {
		cout <<  "failed to insert the item" <<  endl;
	}
}

void UpdateItem() {
	MYSQL* conn = connectdatabase();


	system("CLS");

	int qstate = 0;
	stringstream ss;
	string ID, Name, Price,fabric;

	string updateID, choice;

	bool HaveException = false;
	bool NotInDatabase = false;
	int indexForID = 0;

	string ClothID = "";
	string ItemName = "";
	string ItemPrice = "";

	while (1) {
		system("CLS");

		try
		{
			gotoxy(45,0);cout << "********* UPDATE ITEM ********** " << endl;
			cout << endl;
			cout << "Enter Item ID: ";
			cin >> ID;

		}
		catch (exception e)
		{
			cout << "Please Enter a valid ID." << endl;
			HaveException = true;
			system("CLS");
		}

		if (HaveException == false)
		{
			stringstream streamid;
			string strid;
			streamid << ID;
			streamid >> strid;


			if (NotInDatabase == false)
			{
				string findbyid_query = "select * from clothmenu where ClothID = '" + ID + "'";
				const char* qi = findbyid_query.c_str();
				qstate = mysql_query(conn, qi);

				if (!qstate)
				{
					int found = 0;
					res = mysql_store_result(conn);
					cout << endl;
					while ((row = mysql_fetch_row(res)))
					{

						found = 1;
						cout << endl << "Item ID: " << row[0] << endl << "Cloth Name: " << row[1] << endl << "Item Price: " << row[2] << endl;
						ClothID = row[0];
						ItemName = row[1];
						ItemPrice = row[2];

					}
					if (found == 0) {
						cout << "Not found" << endl;

						cout <<  "Press any key to enter Item ID again " << endl;
						_getch();
						continue;
					}
				}
				else
				{
					cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
				}


				getline(cin, Name);


				cout << "Enter Item Name(N to not change): ";
				getline(cin, Name);
				if (Name == "N")
				{
					Name = ItemName;
				}

                labelPriceItem:
				cout << "Enter Item Price : ";
				getline(cin, Price);

				int PriceInt=atoi(Price.c_str());

				if (PriceInt>0 && PriceInt<=10000)
{
//cout<<Intgeger Price Valid
}
    else{

    cout<<"Input is not a integer.Please key in an appropriate value for the price"<<endl;

    goto labelPriceItem;

    }
				if (Price == "N")
				{
					Price = ItemPrice;
				}

labelFabric:
				cout << "Enter Item Fabric: ";
				getline(cin, fabric);

					if (fabric=="Cotton" || fabric=="Silk" || fabric=="Velvet" || fabric=="Chiffon"){
        //true
	}
	else{
    cout<<"Please key in the correct fabric.Please key in an appropriate value for the price"<<endl;

    goto labelFabric;
	}

				if (fabric == "N")
				{
					fabric= ItemPrice;
				}

				stringstream ss;
				ss << "update clothmenu set  ClothName='" + Name + "', Price ='" + Price + "',fabric='"+fabric+"'   where ClothID='" + ID + "'";


				string query = ss.str();
				const char* ql = query.c_str();
				qstate = mysql_query(conn, ql);


				if (!qstate)
				{


					cout << "This item has been successfully updated in the system" << endl;
					_getch();
				}
				else
				{

					cout <<  "Failed To Update!" << mysql_errno(conn) << endl;
				}

				int flag = 0;
				while (1) {

					cout << "Do you wanna update any other Cloth item?\n[1]Yes\n[2]No\n\nYour choice : ";
					cin >> choice;

					if (choice == "2") {
						flag = 1;
						ClothMenuPage();
					}
					else if (choice != "1") {
						cout << "Wrong Input!!" << endl;
						_getch();
						UpdateItem();
					}
					else if (choice == "1") {
						UpdateItem();
					}
				}
				if (flag == 1) {
					ClothMenuPage();

				}

			}


		}


	}

};
void ShowAdminReport() {

    MYSQL* conn = connectdatabase();

  system("cls");
    // Variables
    char choose;
    string input;
    // Variables End
            gotoxy(45,9);cout << " *******************       SALES REPORT       ****************** "<<endl;

            cout<<"\n\n"<<endl;

    qstate = mysql_query(conn, "select * from orderlist");
    if (!qstate)
    {
        res = mysql_store_result(conn);
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", "OrderID", "Quantity", "CustomerID", "ClothID", "Price", "Item Name");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(res)))
        {
            printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-15s |\n", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    ExitMenu:
    cout << "Press 'a' to Menu any other key to Exit: ";
    cin >> choose;
    if (choose == 'a' || choose == 'A')
    {
        main();
    }
    else
    {
        exit(0);
    }
}

void SearchItem()
{
	MYSQL* conn = connectdatabase();


	system("CLS");
	int qstate = 0;
	stringstream ss;
	string ID, Name, Price;



	int choice;
	bool print = false;
	while (1) {
		system("CLS");
		int found = 0;
		gotoxy(45,0);cout << "**********  SEARCH ITEM  ********* " << endl;
		cout << "Search Cloth Item\n";

		gotoxy(45,11);cout << "Enter Item Name : ";
		cin >> Name;

		string findbyid_query = "select * from clothmenu where ClothName LIKE '%" + Name + "%'";
		const char* qi = findbyid_query.c_str();
		qstate = mysql_query(conn, qi);

		if (!qstate)
		{
			res = mysql_store_result(conn);
			while ((row = mysql_fetch_row(res)))
			{
				found = 1;
				cout << endl << "Item ID: " << row[0] << endl << "Item Name: " << row[1] << endl << "Item Price: " << row[2] << endl;

			}
			if (found == 0) {
				cout << "Not Found" << endl;

				cout << "\nDo you wanna continue searching?\n[1]Yes\n[2]No\n\nYour choice : ";
				cin >> choice;

				if (choice == 2) {
					ClothMenuPage();
				}

				else if(choice==1){
                         SearchItem();
				}
				else
					{
					    char option;
					    cout<<"Invalid Input.Please try again."<<endl;
					    cout<<"Tap on s to search again OR tap on (m) to navigate to main menu"<<endl;
					    cin>>option;

					    if(option=='m'){
                            ClothMenuPage();
					    }

					    if(option=='n'){
                            SearchItem();
					    }

					    }
					}

					}
		else
		{
			cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
		}

 char g;


    cout<<"Press any key to search again Or press (g) to back to main menu "<<endl;
    getch();
    cin>>g;

if(g=='g'){
    ClothMenuPage();
}
else{

    SearchItem();


}

	}


};

void  ViewMenu()

{
	MYSQL* conn = connectdatabase();


	system("CLS");
	int qstate = 0;
	stringstream ss;
	string ID, Name, Price, Quantity, Rating, FabricID, FabricType;
	gotoxy(45,9);cout << "*********    VIEW PRODUCT MENU   *********** " << endl;


	qstate = mysql_query(conn, "select * from clothmenu ");



	if (!qstate)
	{
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{

			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << endl << "Item ID: " << row[0] << endl <<  "Item Name: " << row[1] << endl  << "Item Price: " << row[2] << endl << endl;
			cout << "------------------------------------------------------------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}


	cout << "Press any key to continue....";

	_getch();
	ClothMenuPage();

}


void deleteFromCart(string m1){

MYSQL* conn = connectdatabase();


	int qstate = 0;
	stringstream ss;
	string ID;

	{

		bool HaveException = false, NotInDatabase = false;


		try
		{
			cout << endl;
			cout << setw(0) << "Enter Item ID: ";
			cin >> ID;
			cout << endl;
		}
		catch (exception e)
		{
			cout << setw(100) << "Please Enter a valid ITEM ID." << endl;
			HaveException = true;
			system("CLS");
		}

		if (HaveException == false)
		{
			stringstream streamid;
			string strid;
			streamid << ID;
			streamid >> strid;

			if (NotInDatabase == false)
			{
				string delete_query = "delete from orderlist where orderID = '" + ID + "'";
				const char* qd = delete_query.c_str();
				qstate = mysql_query(conn, qd);

				if (!qstate)
				{
					cout  << "Successfully Deleted From Database." << endl;
				Payment(m1);
				}
				else
				{
					cout  << "Failed To Delete!" << mysql_errno(conn) << endl;
				}

			}
			else
			{
				cout  << "Cloth Item Not Found in database." << endl;
			}
		}


		cout <<  "Press any key to go to Main Menu....";
		_getch();
		ClothMenuPage();
		system("CLS");
	};




}

void DeleteItem()

{
	MYSQL* conn = connectdatabase();


	system("CLS");
	int qstate = 0;
	stringstream ss;
	string ID;

	{

		gotoxy(45,9);cout << "******* DELETE ITEM ******* " << endl;

	int qstate = 0;
	stringstream ss;
	string ID, Name, Price, Quantity, Rating, FabricID, FabricType;
	cout << "*********    LIST OF PRODUCT ITEMS   *********** " << endl;


	qstate = mysql_query(conn, "select * from clothmenu ");



	if (!qstate)
	{
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{

			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << endl << "Item ID: " << row[0] << endl <<  "Item Name: " << row[1] << endl  << "Item Price: " << row[2] << endl << endl;
			cout << "------------------------------------------------------------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}



		bool HaveException = false, NotInDatabase = false;


		try
		{

		    labelItem:
			cout << endl;
			cout << setw(0) << "Enter Item ID to delete or Press (g) to go back to the main menu: ";


			cin >> ID;


        if(ID=="g"){
                ClothMenuPage();
			}


			int ItemIdInt=atoi(ID.c_str());

			if (ItemIdInt>0 && ItemIdInt<=10000)
{
//cout<<Intgeger
}

    else{

    cout<<"Input is not a integer.Please key in an appropriate value for the Item ID"<<endl;

    goto labelItem;

    }
			cout << endl;
		}
		catch (exception e)
		{
			cout << setw(100) << "Please Enter a valid ITEM NAME." << endl;
			HaveException = true;
			system("CLS");
		}

		if (HaveException == false)
		{
			stringstream streamid;
			string strid;
			streamid << ID;
			streamid >> strid;

			if (NotInDatabase == false)
			{
				string delete_query = "delete from clothmenu where ClothID = '" + ID + "'";
				const char* qd = delete_query.c_str();
				qstate = mysql_query(conn, qd);

				if (!qstate)
				{
					cout  << "This item has been successfully deleted" << endl;
					cout<<"\n\nPlease hit enter to view the updated table."<<endl;
					system("pause");

					DeleteItem();
				}
				else
				{
					cout  << "Failed To Delete!" << mysql_errno(conn) << endl;
				}

			}
			else
			{
				cout  << "Cloth Item Not Found in database." << endl;
			}
		}


		cout <<  "Press any key to go to Main Menu....";
		_getch();
		ClothMenuPage();
		system("CLS");
	};
}

void AddOrder(string m1)
{
    MYSQL* conn1 = connectdatabase();
	MYSQL* conn = connectdatabase();

	int current_state=0;
	string paymentStatus="Added to Cart";
	int qstate = 0;
	system("cls");

	qstate = mysql_query(conn, "select * from clothmenu ");
		res = mysql_store_result(conn);
	if (qstate == 0)
	{

		cout << "******   VIEW PRODUCT MENU   ***** " << endl;
		while ((row = mysql_fetch_row(res)))
		{
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << endl <<  "Item ID: " << row[0] << endl << "Item Name: " << row[1] << endl <<  "Item Price: " << row[2] <<endl<< "Item Fabric: "<<row[3]<< endl << endl;
			cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
		system("cls");

	}

	string ID;
	int Quantity;
	int choice;
	bool print = false;
	while (1) {

		int found = 0;

		cout <<  "Enter Item ID: ";
		cin >> ID;

		stringstream ss;

		string findbyid_query = "select * from clothmenu where ClothID = '" + ID + "'";
		const char* qd = findbyid_query.c_str();
		qstate = mysql_query(conn, qd);

		if (!qstate)
		{
			res = mysql_store_result(conn);
			while ((row = mysql_fetch_row(res)))
			{

				found = 1;

				cout << "Item ID: " << row[0] << endl  << "Item Name: " << row[1] << endl <<  "Item Price: " << row[2] <<endl << endl;

             string fabric=row[3];
				double price;
				price = atoi(row[2]);
				string name;
				name = row[1];
				int id;
				id = atoi(row[0]);

       if(fabric=="Cotton")
        cout << "Enter Item Quantity: ";
	    if(fabric=="Silk")
        cout << "Enter Item Quantity: ";
        if(fabric=="Velvet")
        cout << "Enter Item Quantity: ";
        if (fabric=="Chiffon")
        cout << "Enter Item Quantity(In number of Pieces): ";

        cin>>Quantity;
				double PRICE;
				PRICE = price * Quantity;


ss << "INSERT INTO orderlist(Quantity,CustomerID,ClothID,Price,Name,Status) VALUES ('" << Quantity<< "', '" <<m1<< "', '" << id << "','" << PRICE<< "', '" <<name << "','"<<paymentStatus<<"')";
			string query = ss.str();
				const char* ql = query.c_str();
				qstate = mysql_query(conn, ql);
				if (qstate == 0)
				{
					cout <<  "This item has been Successfully Added in the cart " << endl;


					cout <<  "Do you want to add more Cloths to the Cart(Y/N) " << endl;
					cin>>c_option;

					if (c_option=='Y')
					{
					AddOrder(m1);
					}

					else if (c_option=='N'){
                        CustomerMainMenu(m1);
					}

					else{

                cout<<"Invalid Input.Please try again"<<endl;
             	AddOrder(m1);
					}
					}


				}
				}
				else {
					cout <<  "Failed To Insert Into Database" << endl;
					cout <<  "Wrong Keyword!! Please Try Again " << endl;
					_getch();

				}


				if (found == 0) {
				cout << "Not Found" << endl;

				cout << endl << endl << "Do you want to adding Cloths?" << endl << "[1]Yes" << endl << "[2]No" << endl << endl << "Your choice : ";
				cin >> choice;}

				if (choice == 2) {

				}
				else
					continue;


			}

		}



void Receipt(string m1) {

	MYSQL* conn = connectdatabase();


	system("CLS");
	int qstate = 0;
	double Total;
	stringstream ss;
	gotoxy(45,9);cout << "**********ORDERED PRODUCT************ " << endl;


	qstate = mysql_query(conn, "select * from orderlist");
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{
			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << endl  << "Order ID: " << row[0] << endl  << "Item Quantity: " << row[1] << endl << "Item Price: " << row[4] << endl  <<  "Name: " << row[5] << endl  << endl;
			cout << "------------------------------------------------------------------------------------------------" << endl;

		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}

			ss << " SELECT SUM(Price) as Total From orderlist";



			string query = ss.str();
			const char* qm = query.c_str();
			qstate = mysql_query(conn, qm);
			if (qstate == 0)
			{  string a="7";
			string b="8";
				res = mysql_store_result(conn);
				row = mysql_fetch_row(res);
				stringstream geek(row[0]);
				geek >> Total;
				stringstream sq;
				sq << "  INSERT INTO receipt(CustomerID,TotalPrice) VALUES ('" << m1 << "','" << Total << "')";
				query = sq.str();
				const char* qp = query.c_str();
				qstate = mysql_query(conn, qp);
				if (qstate == 0) {


						cout << "Press any key to go to the Main Menu. " << endl << endl;

						_getch();
						CustomerMainMenu(m1);

				}
				else {
					cout << "Problem" << endl;
				}
			}
			else {
				cout << "Failed To Insert Into Database" << endl;
				cout << "Wrong Keyword!! Please Try Again ";
				_getch();

			}


}

void viewlist(string m1){

MYSQL* conn = connectdatabase();


	system("CLS");
	int qstate = 0;
	stringstream ss;
	string ID, Name, Price, Quantity, Rating, FabricID, FabricType;
	gotoxy(45,9);cout << "*********    VIEW PRODUCT MENU   *********** " << endl;


	qstate = mysql_query(conn, "select * from clothmenu ");



	if (!qstate)
	{
		res = mysql_store_result(conn);
		while ((row = mysql_fetch_row(res)))
		{

			cout << "------------------------------------------------------------------------------------------------" << endl;
			cout << endl << "Item ID: " << row[0] << endl <<  "Item Name: " << row[1] << endl  << "Item Price: " << row[2] << endl << endl;
			cout << "------------------------------------------------------------------------------------------------" << endl;
		}
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
	}


	cout << "Press any key to continue....";

	_getch();
	CustomerMainMenu(m1);



}

void customersearch(string m1){
MYSQL* conn = connectdatabase();


	system("CLS");
	int qstate = 0;
	stringstream ss;
	string ID, Name, Price;



	int choice;
	bool print = false;
	while (1) {
		system("CLS");
		int found = 0;
		gotoxy(0,9);cout << "**********  SEARCH ITEM  ********* " << endl;
		cout << "Search Cloth Item\n";

		gotoxy(45,11);cout << "Enter Item Name : ";
		cin >> Name;

		string findbyid_query = "select * from clothmenu where ClothName LIKE '%" + Name + "%'";
		const char* qi = findbyid_query.c_str();
		qstate = mysql_query(conn, qi);

		if (!qstate)
		{
			res = mysql_store_result(conn);
			while ((row = mysql_fetch_row(res)))
			{
				found = 1;
				cout << endl << "Item ID: " << row[0] << endl << "Item Name: " << row[1] << endl << "Item Price: " << row[2] << endl;

			}
			if (found == 0) {
				cout << "Not Found" << endl;

				cout << "\nDo you wanna continue searching?\n[1]Yes\n[2]No\n\nYour choice : ";
				cin >> choice;

				if (choice == 2) {
					ClothMenuPage();
				}

				else if(choice==1){
                         SearchItem();
				}
				else
					{
					    char option;
					    cout<<"Invalid Input.Please try again."<<endl;
					    cout<<"Tap on s to search again OR tap on (m) to navigate to main menu"<<endl;
					    cin>>option;

					    if(option=='m'){
                            ClothMenuPage();
					    }

					    if(option=='n'){
                            SearchItem();
					    }

					    }
					}

					}
		else
		{
			cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
		}

 char g;


    cout<<"Press any key to search again Or press (g) to back to main menu "<<endl;
    getch();
    cin>>g;

if(g=='g'){
    CustomerMainMenu(m1);
}
else{

    SearchItem();


}

	}


}

