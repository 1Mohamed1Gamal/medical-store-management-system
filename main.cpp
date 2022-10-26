#include <iostream>
#include <string>
#include<fstream>

using namespace std;
//start of struct data type
int disc[15] = { 0 };
int p = 0;
struct dateOfTaken
{
	int day;
	int month;
	int year;
};
struct medical
{
	string name;
	int stock;
	string suppliername[3];
	dateOfTaken expiredate;
	float price;
	int id;

}medicinearr[15];
struct Supplier
{
	string name[3];
	long long phone;
	string nameofproduct[15];
	int id;
}supplierarr[15];
struct customer
{
	string name[3];
	long long phone;
	string nameofprouduct[15];
	dateOfTaken date;
	float lastbill;
	float TotalPrice = 0;
	int id;

}clientarr[15];

void fullMedicine();
void fullsupplier();
void fullclient();
void dataofcustomer();
void dataofsupplier();
void dataofmedical();
void NewData(int a);
void search();
void searchcustomer();
void searchsupplier();
void searchmedicine();
void stockfun(string arr[], int x);
void report();
void updatecustomer();
void updatesupplier();
void fullMedicine1();
void fullsupplier1();
void fullclient1();
float functionforlastbill(float z);
bool funforchecknameofmedicine(string str);
float funforcheckdiscount(float sum);
void displayresultofresearchofcustomer(int q);
void displayresultofresearchofmedicine(int q);
void displayresultofresearchofsupplier(int q);
int main()
{
	int menu;
	int id, phone;
	char name;
	fullMedicine();
	fullsupplier();
	fullclient();
	do//case of 7 he will exite
	{
		cout << "\t\t\t\t\t\t\t\t\t    Pharmacy Management System \n"; //start menu
		cout << "\t\t\t\t\t\t\t # please enter the number which expresses for the process you want #\n";
		cout << "\t\t\t\t\t\t\t\t==================================================\n\n";
		cout << "\t\t\t\t\t\t\t\t**************************************************\n";
		cout << "\t\t\t\t\t\t\t\t$$\t1. Add new details  \t\t\t $$\n";
		cout << "\t\t\t\t\t\t\t\t$$\t2. update details  \t\t\t $$\n";
		cout << "\t\t\t\t\t\t\t\t$$\t3. search for what you want \t\t $$\n";
		cout << "\t\t\t\t\t\t\t\t$$\t4. Report The Details\t\t\t $$\n";
		cout << "\t\t\t\t\t\t\t\t$$\t5. Exit\t\t\t\t\t $$\n";
		cout << "\t\t\t\t\t\t\t\t**************************************************\n";
		cout << "\t\t\t\t\t\t\t\t\t\t Enter Your choice: ";
		cin >> menu; //end of menu and start to choose
		cout << "\n\n\n\n\n\n";
		switch (menu)
		{
		case 1:
		{
			NewData(menu);
			break;
		}
		case 2:
		{
			NewData(menu);
			break;
		}
		case 3:
		{
			search();
			break;
		}
		case 4:
		{
			report();
			break;
		}
		case 5:
		{
			cout << "\t\t\t\t\t\t\t\t\t\twe will exit thank you \n";
			fullMedicine1();
			fullsupplier1();
			fullclient1();
			break;
		}
		default:
		{
			cout << "You enter invalid input\nre-enter the input\n" << endl;
		}
		}
	} while (menu != 5);
}
void fullMedicine()
{
	ifstream in;
	in.open("medicien.txt");
	for (int i = 0; i < 15; i++)
	{
		in >> medicinearr[i].name >> medicinearr[i].stock;
		in >> medicinearr[i].suppliername[0] >> medicinearr[i].suppliername[1] >> medicinearr[i].suppliername[2];
		in >> medicinearr[i].expiredate.day >> medicinearr[i].expiredate.month >> medicinearr[i].expiredate.year;
		in >> medicinearr[i].price >> medicinearr[i].id;
	}
	in.close();
}
void fullsupplier()
{
	ifstream in;
	in.open("information of supplier.txt");
	for (int i = 0; i < 15; i++)
	{
		in >> supplierarr[i].name[0] >> supplierarr[i].name[1] >> supplierarr[i].name[2];
		in >> supplierarr[i].phone;
		for (int j = 0; j < 15; j++)
		{
			in >> supplierarr[i].nameofproduct[j];
		}
		in >> supplierarr[i].id;
	}
	in.close();
}
void fullclient()
{
	ifstream in;
	in.open("client.txt");
	for (int i = 0; i < 15; i++)
	{
		in >> clientarr[i].name[0] >> clientarr[i].name[1] >> clientarr[i].name[2];
		in >> clientarr[i].phone;
		for (int j = 0; j < 15; j++)
		{
			in >> clientarr[i].nameofprouduct[j];
		}
		in >> clientarr[i].date.day >> clientarr[i].date.month >> clientarr[i].date.year;
		in >> clientarr[i].lastbill;
		in >> clientarr[i].TotalPrice;
		in >> clientarr[i].id;
	}
	in.close();
}
void dataofcustomer()
{
	int x = 0, c;
	long long tele;
	float sum;
	bool z = 1, b, b1;
	string choiceforbill;
	for (int i = 0; i < 15; i++)/*to determine the next id */
	{
		if (clientarr[i].id > x)
		{
			x = clientarr[i].id;
		}
	}
	c = x + 1;
	do/*to ensure that the use renter the right id*/
	{
		cout << "\t ================================================================\t" << endl;
		cout << "-\t enter your id : ";
		cout << "U"; cin >> clientarr[x].id;
		if (clientarr[x].id != c)
		{
			cout << "-\t you must enter next id that equal   " << c << endl;
			z = 0;
		}
		else
			z = 1;
	} while (z == 0);
	cout << "\t ================================================================\t" << endl;
	while (true)
	{
		b1 = 1;
		cout << "-\t enter your phone : " << "\t"; cin >> tele;
		for (int g = 0; g < 15; g++)
		{
			if (clientarr[x].phone == tele)
			{
				cout << "\t this telephone number is already exist please enter new one" << endl;
				b1 = 0;
				break;
			}
		}
		if (b1 == 1) {
			clientarr[x].phone = tele;
			break;
		}
	}
	cout << "\t ================================================================\t" << endl;
	cout << "-\t enter your name 3rd : " << "\t"; cin >> clientarr[x].name[0] >> clientarr[x].name[1] >> clientarr[x].name[2];
	cout << "\t ================================================================\t" << endl;
	cout << "-\t enter your date : " << "\t"; cin >> clientarr[x].date.day; cout << " "; cin >> clientarr[x].date.month; cout << " "; cin >> clientarr[x].date.year; cout << endl;;
	cout << "\t ================================================================\t" << endl;
	cout << "-\t   enter your products\n\tif you want to finish enter the word\"end\"\n\n\tNote : After writing every medicine please press enter:-\n";
	cout << "\t ================================================================\t" << endl;
	int cnt = 1;
	for (int a = 0; a < 15; a++)
	{
		b = 1;
		cout << cnt++ << "-"; cin >> clientarr[x].nameofprouduct[a];
		if (clientarr[x].nameofprouduct[a] == "end")
		{
			for (a; a < 15; a++)
				 clientarr[x].nameofprouduct[a] = "ee";
		}
		else
		{
			b = funforchecknameofmedicine(clientarr[x].nameofprouduct[a]);// cheack for medical
			if (b == 0)
			{
				cout << "\tthis medicine isn't found, please enter a correct medicine \n" << endl;
				a--;
			}
		}
	}
	cout << "\t ================================================================\t" << endl;
	cout << "\t- enter the last bill : "; cin >> clientarr[x].lastbill;
	functionforlastbill(clientarr[x].lastbill);
	cout << "\t ================================================================\t" << endl;
	cout << "\t- enter your Total Price per week : ";
	cin >> clientarr[x]. TotalPrice ;
	stockfun(clientarr[x].nameofprouduct, x);
	cout << "\t ================================================================\t" << endl;
}
void  dataofsupplier()
{
	int x = 0, c;
	bool z = 1, b;
	string str1, str2, str3;
	for (int i = 0; i < 15; i++)
	{
		if (supplierarr[i].id > x)
		{
			x = supplierarr[i].id;
		}
	}
	c = x + 1;
	do
	{
		cout << "\t ================================================================\t" << endl;
		cout << "-\t enter your id : "; cout << 'S'; cin >> supplierarr[x].id;
		if (supplierarr[x].id != c)
		{
			cout << "-\t you must enter next id that equal   " << c << endl;	
			z = 0;
		}
		else
			z = 1;
	} while (z == 0);
	cout << "\t ================================================================\t" << endl;
	while (true) 
	{
		cout << "-\t enter your name : "; cin >> str1 >> str2 >> str3;
		for (int g = 0; g < 15; g++)
		{
			b = 0;
			if (supplierarr[g].name[0] == str1 && supplierarr[g].name[1] == str2 && supplierarr[g].name[2] == str3)
			{
				b = 1;
				cout << "-\t you must enter next id that equal   " << c << endl;
			}
			 if (b == 0)
			{
				supplierarr[x].name[0] = str1;
				supplierarr[x].name[1] = str2;
				supplierarr[x].name[2] = str3;
				break;
			}
			
		}
		if (b == 0)
			break;
	}
	cout << "\t ================================================================\t" << endl;
	cout << "-\t enter your phone : "; cin >> supplierarr[x].phone;
	cout << "\t ================================================================\t" << endl;
	cout << "-\t enter your products\n\tif you want to finish enter the word\"end\"\n\n\tNote : After writing every medicine please press enter:-\n";
	cout << "\t ================================================================\t" << endl;
	int cnt = 1;
	for (int a = 0; a < 15; a++)
	{
		cout << cnt++ << "-";
		cin >> supplierarr[x].nameofproduct[a];
		if (supplierarr[x].nameofproduct[a] == "end")
		{
			for (a; a < 15; a++)
				supplierarr[x].nameofproduct[a] = "ee";
		}
	}
}
void  dataofmedical()
{
	int x = 0, c;
	string str;
	bool z = 1, b;
	for (int i = 0; i < 15; i++)
	{
		if (medicinearr[i].id > x)
		{
			x = medicinearr[i].id;
		}
	}
	c = x + 1;
	do
	{
		cout << "\t ================================================================\t" << endl;
		cout << "\t- enter your id : "; cout << "m"; cin >> medicinearr[x].id;
		if (medicinearr[x].id != c)
		{
			cout << "\t- you must enter next id that equal " << c << endl;
			z = 0;
		}
		else
			z = 1;
	} while (z == 0);
	cout << "\t ================================================================\t" << endl;
	while (true) {
		cout << "\t- enter name of medicine : "; cin >> str;
		for (int g = 0; g < 15; g++)
		{
			b = 1;
			if (medicinearr[g].name == str)
			{
				cout << "\t this medicine is existing before please enter new one " << endl;
				b = 0;
				break;
			}
		}
		if (b == 1)
		{
			str = medicinearr[x].name;
			break;
		}
	}
	cout << "\t- enter name of supplier : "; cin >> medicinearr[x].suppliername[0] >> medicinearr[x].suppliername[1] >> medicinearr[x].suppliername[2];
	cout << "\t ================================================================\t" << endl;
	cout << "\t- enter expier date : "; cin >> medicinearr[x].expiredate.day >> medicinearr[x].expiredate.month >> medicinearr[x].expiredate.year;
	cout << "\t ================================================================\t" << endl;
	cout << "\t- enter stock : "; cin >> medicinearr[x].stock;
	cout << "\t ================================================================\t" << endl;
}
void NewData(int a)
{
	bool x = 1;
	char kindOfData;
	do
	{
		cout << "\t\t\t\t\t\t\t\t$$ for customer  Please Choose || ('u') $$\n";
		cout << "\t\t\t\t\t\t\t\t$$ for Suppleier Please Choose || ('s') $$\n";
		if(a!=2)
		cout << "\t\t\t\t\t\t\t\t$$ for medicine Choose         || ('m') $$\n";
		cout << "\t\t\t\t\t\t\t\tYour choice is : "; cin >> kindOfData;
		switch (kindOfData)
		{
		case 'u':
			if (a == 1) {
				dataofcustomer();
				break;
			}
			else if (a == 2) {
				updatecustomer();
				break;
			}
		case 's':
			if (a == 1) {
				dataofsupplier();
				break;
			}
			else if (a == 2) {
				updatesupplier();
				break;
			}
			break;
		case 'm':
				dataofmedical();			
			break;
		default:
			cout << "\t $$ doesn't exist $$ \t\n";
			x = 0;
		}
	} while (x == 0);
}
void search()
{
	char w;
	cout << "If You Want TO Search For Customer Enter ('c') " << endl;
	cout << "If You Want TO Search For Supplier Enter ('s') " << endl;
	cout << "If You Want TO Search For Medicine Enter ('m') " << endl;
	cout << "Enter Your Chiose : ";
	cin >> w;
	if (w == 'c' || w == 'C')
	{
		searchcustomer();
	}
	else if (w == 's' || w == 'S')
	{

		searchsupplier();
	}
	else if (w == 'm' || w == 'M')
	{
		searchmedicine();
	}
}
void searchcustomer()
{
	char x;
	int id, q;
	long long phone;
	bool found = 0;
	cout << "If You Want To Search For Id Enter (i) " << endl << "IF You Want To Search For Phone Enter(p):  "; cin >> x;
	if (x == 'i' || x == 'I')
	{
		cout << "Enter The Id You Want TO Search : ";
		while (true) {
			found = 1;
			cin >> id;
			for (int i = 0; i < 15; i++) {
				if (clientarr[i].id == id)
				{
					found = 1;
					q = i;
					break;
				}
				else
					found = 0;
			}
			if (found == 0)
				cout << "\tthis id dosen't exist ,enter acorrect id " << endl;
			else {
				displayresultofresearchofcustomer(q);
				break;
			}
		}
	}
	else if (x == 'p' || x == 'P')
	{
		int q;
		bool p;
		cout << "Enter The Phone You Want TO Search : ";
		while (true) {
			cin >> phone;
			for (int i = 0; i < 15; i++)
			{
				p = 1;
				if (clientarr[i].phone == phone) {
					q = i;
					break;
				}
				else
					p = 0;
			}
			if (p == 0) {
				cout << "The Phone dosen't Exist , please enter anthoer  " << endl;
			}
			else {
				displayresultofresearchofcustomer(q);
				break;
			}
		}
	}
}
void searchsupplier()
{
	int id, q;
	string name[3];
	char z;
	bool found = false;
	cout << "If You Want To Search For Id Enter (i) \nIF You Want To Search For Name Enter (n) " << endl;
	cout << "Enter Your Choice : "; cin >> z;
	cout << "\t ================================================================\t" << endl;
	if (z == 'i' || z == 'I')
	{
		while (true) {
			cout << "Enter The Id You Want TO Search : "; cin >> id;
			cout << "\t ================================================================\t" << endl;
			for (int i = 0; i < 15; i++)
			{
				if (supplierarr[i].id == id)
				{
					q = i;
					found = 1;
					break;
				}
				else
					found = 0;
			}
			if (found)
			{
				displayresultofresearchofsupplier(q);
				break;
			}
			else
			{
				cout << "The Id Isn't Exist  " << endl;
				cout << "\t ================================================================\t" << endl;
			}
		}
	}
	else if (z == 'n' || z == 'N')
	{
		int q;
		cout << "Enter The Name 3rd You Want TO Search : ";
		while (true) {
			cin >> name[0] >> name[1] >> name[2];
			cout << "\t ================================================================\t" << endl;
			for (int i = 0; i < 15; i++)
			{
				if (name[0] == supplierarr[i].name[0] && name[1] == supplierarr[i].name[1] && name[2] == supplierarr[i].name[2])
				{
					q = i;
					found = 1;
					break;
				}
				else
				{
					found = 0;
				}
			}
			if (found == 1) {
				displayresultofresearchofsupplier(q);
				break;
			}
			else {
				cout << "The Name Isnt Exist " << endl;
				cout << "\t ================================================================\t" << endl;
			}
		}
	}

}
void searchmedicine()
{
	int id;
	string name;
	char choice;
	bool found = false;
	cout << "If You Want To Search For Id Enter (i) \nIF You Want To Search For Name Enter (n) " << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "Enter Your Choice : "; cin >> choice;
	cout << "\t ================================================================\t" << endl;

	if (choice == 'i' || choice == 'I')
	{
		int q;
		cout << "Enter The Id You Want TO Search : ";
		while (true) {
			cin >> id;
			cout << "\t ================================================================\t" << endl;
			for (int i = 0; i < 15; i++)
			{
				found = 1;
				if (medicinearr[i].id == id)
				{
					q = i;
					found = 1;
					break;
				}
				else
					found = 0;
			}
			if (found == 1) {
				displayresultofresearchofmedicine(q);
				break;
			}
			else
			{
				cout << "this id dosen't enter a correct one :  " << endl;
				cout << "\t ================================================================\t" << endl;
			}
		}

	}
	else if (choice == 'n' || choice == 'N')
	{
		int q;
		cout << "Enter The Name You Want TO Search : " << endl;
		cout << "\t ================================================================\t" << endl;
		while (true) {
			cin >> name;
			for (int i = 0; i < 15; i++)
			{
				if (name == medicinearr[i].name)
				{
					found = 1;
					q = i;
					break;
				}
				else
					found = 0;
			}
			if (found == 1) {
				displayresultofresearchofmedicine(q);
				break;
			}
			else
			{
				cout << "\t this medicine dosen't exist " << endl;
				cout << "\t ================================================================\t" << endl;
			}
		}
	}
}
void stockfun(string arr[], int x)
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (clientarr[x].nameofprouduct[i] == medicinearr[j].name)
				medicinearr[j].stock--;
		}
	}
	/*for (int i = 0; i < 15e; i++)
	{
		cout << medicinearr[i].stock << endl;
	}*/
}
void report()
{
	for (int i = 0; i < 15; i++)
	{
		if (medicinearr[i].stock == 0)
			break;
		cout << "\t the name of medicine is : " << medicinearr[i].name << "\t the stock of medicine is : " << medicinearr[i].stock << "\n";
		cout << "******************************************************************" << endl;
		if (medicinearr[i].stock < 5)
		{
			cout << "this medicine must be purchased \t" << medicinearr[i].name << endl;
		}
	}
	for (int z = 0; z < 15; z++)
	{
		if (disc[z] == 0)
			break;
		else
			cout << disc[z] << endl;
	}

}
void updatecustomer()
{
	int x = 0;
	float sum;
	bool b;
	string choiceforbill;
	for (int i = 0; i < 15; i++)
	{
		if (clientarr[i].id > x)
		{
			x = clientarr[i].id;
		}
		else if (clientarr[i].id == 0)
			break;
	}
	int id1, i = 0;
	cout << "\t ================================================================" << endl;
	cout << "\t-please enter your id : U";
	while (true) {
		cin >> id1;
		if (id1 > x) {
			cout << "this id dosenot exist ,please enter right id  " << endl;
			cout << "\t ================================================================\t" << endl;
		}
		else
			break;
	}
	id1--; //to reduce variables and we use this as idex of array 
	cout << "\t- please enter new date : "; cin >> clientarr[id1].date.day >> clientarr[id1].date.month >> clientarr[id1].date.year;
	cout << "\t ================================================================\t" << endl;
	cout << "\t- enter your products\n\tif you want to finish enter the word\"end\"\n\n\tNote : After writing every medicine please press enter:-\n";
	cout << "\t ================================================================\t" << endl;
	int cnt = 1;
	for (int a = 0; a < 15; a++)
	{
		b = 1;
		cout << cnt++ << "-"; cin >> clientarr[id1].nameofprouduct[a];
		if (clientarr[id1].nameofprouduct[a] == "end")
		{
			for (a; a < 15; a++)
				clientarr[id1].nameofprouduct[a] = "ee";
		}
		else
		{
			b = funforchecknameofmedicine(clientarr[id1].nameofprouduct[a]);
			if (b == 0)
			{
				cout << "\tthis medicine isn't found,please enter acorrect medicine " << endl;
				a--;
			}
		}
	}
	cout << "\t ================================================================\t" << endl;
	stockfun(clientarr[id1].nameofprouduct, id1);
	cout << "\t- enter the last bill : "; cin >> clientarr[id1].lastbill;
	functionforlastbill(clientarr[id1].lastbill);
	cout << "\t ================================================================\t" << endl;
	cout << " \t- please enter the new total price : "; cin >> clientarr[id1].TotalPrice;
}
void updatesupplier()
{
	int x = 0;
	for (int i = 0; i < 15; i++)
	{
		if (supplierarr[i].id > x)
		{
			x = supplierarr[i].id;
		}
		else if (supplierarr[i].id == 0)
			break;
	}
	int id1, i = 0;
	cout << "\t- please enter your id : S";
	while (true) {
		cin >> id1;
		if (id1 > x) {
			cout << "this id dosenot exist ,please enter your id  \n";
			cout << "\t ================================================================\t" << endl;
		}
		else
			break;
	}
	cout << "\t- enter supplied medical products : \n";
	int cnt = 1;
	for (int i = 0; i < 15; i++) {
		if (supplierarr[id1].nameofproduct[i] == "ee")
			break;
		else {
			for (i; i < 15; i++)
			{
				cout << cnt++ << "-"; cin >> supplierarr[id1].nameofproduct[i];
				if (supplierarr[id1].nameofproduct[i] == "end")
				{
					for (i; i < 15; i++)
						supplierarr[id1].nameofproduct[i] = "ee";
				}
			}
		}
	}
}
void fullMedicine1()
{
	ofstream out;
	out.open("medicien.txt");
	for (int i = 0; i < 15; i++)
	{
		out << medicinearr[i].name << "\t" << medicinearr[i].stock << "\t";
		out << medicinearr[i].suppliername[0] << "\t" << medicinearr[i].suppliername[1] << "\t" << medicinearr[i].suppliername[2] << "\t";
		out << medicinearr[i].expiredate.day << "\t" << medicinearr[i].expiredate.month << "\t" << medicinearr[i].expiredate.year << "\t";
		out << medicinearr[i].price << "\t" << medicinearr[i].id << endl;
	}
	out.close();
}
void fullsupplier1()
{
	ofstream out;
	out.open("information of supplier.txt");

	for (int i = 0; i < 15; i++)
	{
		cout << endl;
		out << supplierarr[i].name[0] << "\t" << supplierarr[i].name[1] << "\t" << supplierarr[i].name[2] << "\t" << supplierarr[i].phone << "\t";
		for (int j = 0; j < 15; j++)
		{
			out << supplierarr[i].nameofproduct[j] << "\t";
		}
		out << supplierarr[i].id << endl;

	}

	out.close();
}
void fullclient1()
{
	ofstream out;
	out.open("client.txt");

	for (int i = 0; i < 15; i++)
	{
		out << clientarr[i].name[0] << "\t" << clientarr[i].name[1] << "\t" << clientarr[i].name[2] << "\t";
		out << clientarr[i].phone << "\t";
		for (int j = 0; j < 15; j++)
		{
			out << clientarr[i].nameofprouduct[j] << "\t";
		}
		out << clientarr[i].date.day << "\t" << clientarr[i].date.month << "\t" << clientarr[i].date.year << "\t";
		out << clientarr[i].lastbill << "\t";
		out << clientarr[i].TotalPrice << "\t";
		out << clientarr[i].id << endl << endl;
	}
	out.close();
}
float functionforlastbill(float z) {
	if (z >= 500)
	{
		z = z - z * 0.05;
		disc[p] = z;
		p++;
	}
	return z;
}
bool funforchecknameofmedicine(string str) {
	bool b = 0;
	for (int i = 0; i < 15; i++)
	{
		if (str == medicinearr[i].name) {
			b = 1;
			break;
		}
	}
	return b;
}
float funforcheckdiscount(float sum)
{
	string choiceforbill;
	cout << "\t if you want to take a discount please enter yes,if you don't enter no : "; cin >> choiceforbill;
	cout << "\t ================================================================\t" << endl;
	if (choiceforbill == "YES" || choiceforbill == "yes")
		sum = functionforlastbill(sum);
	return sum;
}
void displayresultofresearchofcustomer(int q)
{
	cout << "\t ================================================================\t" << endl;
	cout << "\t the id of customer is "; cout << clientarr[q].id << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t the phone of customer is  :0"; cout << clientarr[q].phone << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t the name of customer is  :"; cout << clientarr[q].name[0] << "  " << clientarr[q].name[1] << "  " << clientarr[q].name[2] << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t the date of last bill of customer is  :"; cout << clientarr[q].date.day << "  " << clientarr[q].date.month << "  " << clientarr[q].date.year << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t the price of the last bill  :"; cout << clientarr[q].lastbill << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t the total price for week :"; cout << clientarr[q].TotalPrice << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t the list of purchased products :" << endl;
	cout << "\t ================================================================\t" << endl;
	int cnt = 1;
	for (int s = 0; s < 15; s++)
	{
		if (clientarr[q].nameofprouduct[s] == "ee")
			break;
		else 
		{
			cout << "\t" << cnt++ << "-" << clientarr[q].nameofprouduct[s] << endl;
		}
	}
	cout << "\t ================================================================\t" << endl;
}
void displayresultofresearchofmedicine(int q)
{
	cout << "\t -this is the id of medicine : " << medicinearr[q].id << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -this is the name of medicine : " << medicinearr[q].name << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -this is the stock of medicine : " << medicinearr[q].stock << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -this is the price of medicine : " << medicinearr[q].price << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -this is the the expire date of medicine : " << medicinearr[q].expiredate.day << "  " << medicinearr[q].expiredate.month << "  " << medicinearr[q].expiredate.year << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -the name of supplier is : " << medicinearr[q].suppliername[0] << "   " << medicinearr[q].suppliername[1] << "   " << medicinearr[q].suppliername[2] << endl;
	cout << "\t ================================================================\t" << endl;
}
void displayresultofresearchofsupplier(int q)
{
	cout << "\t -the supplier's name is: "; cout << supplierarr[q].name[0] << "  " << supplierarr[q].name[1] << "  " << supplierarr[q].name[2] << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -the telephone number is 0: " << supplierarr[q].phone << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -the id number is : " << supplierarr[q].id << endl;
	cout << "\t ================================================================\t" << endl;
	cout << "\t -the list of supplied products :" << endl;
	cout << "\t  ================================================================\t" << endl;
	int cnt = 1;
	for (int s = 0; s < 15; s++)
	{
		if (supplierarr[q].nameofproduct[s] == "ee")
			break;
		else {
			cout << cnt++ <<"-" << supplierarr[q].nameofproduct[s] << endl;
		}
	}
	cout << "\t ================================================================\t" << endl;
}
