#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include<Windows.h>
#include <MMsystem.h>
using namespace std;

struct  person
{
	string name;
	int pin;
	int balance;
};
person new_client()
{
	string clinet_name; int clinet_balance; int clinet_pin;

	bool l = true;
	bool k = 0;
	while (k == 0)
	{

		cout << "Please enter your personal data" << endl;
		cout << "please enter your first name: ";
		clinet_name;
		cin >> clinet_name;
		cout << "Your balance: ";
		clinet_balance;
		cin >> clinet_balance;
		cout << "and the pin you wish to have: ";
		int check_1, check_2;
		bool l = 1;
		cin >> check_1;
		while (l)//if the user entered invaild pin
		{
			/*number_of_d = check_1 / 10000;*/
			if (check_1 > 10000 || check_1 < 999)
			{
				cout << "you have entered an invalid pin [please remember that your pin should exactly be 4-digits not more not less]" << endl;
				cout << "try a diffrent pin: ";
				cin >> check_1;



			}
			else
			{
				l = 0;
			}

			cout << "now,enter your pin again: ";
			cin >> check_2;
			bool l2 = 0;
			while (l2 == 0)// if the check isn't correct
			{
				if (check_1 != check_2)
				{
					cout << "this pin doesn't match the first" << endl;
					cout << "enter the pin: ";
					cin >> check_1;
					cout << "renter the pin: ";
					cin >> check_2;
				}
				else
				{
					l2 = 1;

				}
			}

			clinet_pin = check_1;
			cout << "!!congratulations!!" << endl << "your have just finished setting up your accont";
			cout << "now you can log into your account, and this is your personal information:" << endl;
			cout << "your name: " << clinet_name << endl << "your balance: " << clinet_balance << endl << "your pin: " << clinet_pin << endl;
			k = 1;
		}
	}
	person client1;
	client1.name = clinet_name;
	client1.balance = clinet_balance;
	client1.pin = clinet_pin;
	return client1;

}
int login_pins()
{
	int p1, p2, m=0;
	cout << "To log in please enter your pin : ";
	cin >> p1;
	bool digit_limit = 0;
	while (digit_limit == 0)
	{
		if (p1 > 10000 || p1 < 999)
		{


			cout << "you have entered an invalid pin [please remember that your pin should exactly be 4-digits not more not less]" << endl;
			//PlaySound("sad.wav", NULL, SND_SYNC | SND_FILENAME | SND_LOOP);
			cout << "try a diffrent pin: ";
			cin >> p1;
			digit_limit = 0;
		}
		else { digit_limit = 1; }
	}
	cout << "kindly renter your pin : ";
	cin >> p2;
	bool pins = 0;
	
	while (pins == 0 && m < 3)
	{
		if (p1 == p2)
		{
			/*cout << "you have access to your account \n";*/


			pins = 1;

		}
		
		else if (m == 2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);//RED

			cout << "you have entered a wrong pin for three time " << endl << "you can not access your accont please call the bank for more information" << endl;
			m = 6;
		}
		else
		{
			bool wh_cont = 1;
			int cont = 1;
			
			
				cout << "the pins dont match please renter them  \n";
				//PlaySound("error.wav", NULL, SND_SYNC | SND_FILENAME | SND_LOOP);
				cout << "enter the pin : ";
				cin >> p1;
				cout << "renter the pin : ";
				cin >> p2;
				if(p1==p2)
				pins = 0;
				m++;
			
		}

	}
	
	

	return p2;
}
void checking(int b)
{

	cout << "your blance is " << b << endl;


}
void withdrawl(int& withdraw)
{
	int money;
	bool m = 0;



	cout << "please enter the amount of money you want to withdraw : ";
	cin >> money;
	while (m == 0)
	{
		if (money >= 50 && money <= 2000 && money % 50 == 0 && money < withdraw)
		{
			cout << "you have chosen to withdraw " << money << " please wait for the money to come out of the machine \n";
			m = 1;
		}
		else
		{
			cout << "\a";
			cout << "the amount of money you chose to withdraw is invalid please enter a valid amount : ";
			cin >> money;

		}
	}
	withdraw = withdraw - money;
	cout << "your balance now is " << withdraw << endl;

}
void transfer(string s1, int& T1, int& T2)
{
	cout << "enter the amount of money you wish to transfer [the limit of transfering is 10,000]: ";
	int t;
	cin >> t;
	bool mw = 1;
	while (mw == 1)
		if (t < 10000 && t < T1 && t>0)
		{
			T1 = T1 - t;
			T2 = T2 + t;
			cout << "Transfer complete" << endl << "Your balance is now " << T1 << endl;
			cout << s1 << "'s balance is now " << T2 << endl;
			mw = 0;
		}
		else
		{
			cout << "you have entered an invaild value" << endl << "please re enter how much money you want to transfer: ";
			cin >> t;

		}

}

void main()
{


	int color = 10;
	person client[10];
	person bill;
	bill.pin = 1234;
	bill.name = "bill";
	bill.balance = 3500;
	client[0] = bill;

	person Ali;
	Ali.pin = 5678;
	Ali.name = "Ali";
	Ali.balance = 3100;
	client[1] = Ali;
	person Mohamed;
	Mohamed.pin = 1334;
	Mohamed.name = "Mohamed";
	Mohamed.balance = 3200;
	client[2] = Mohamed;

	person Taha;
	Taha.pin = 1834;
	Taha.name = "Taha";
	Taha.balance = 3300;
	client[3] = Taha;

	person Mustafa;
	Mustafa.pin = 1634;
	Mustafa.name = "Mustafa";
	Mustafa.balance = 3400;
	client[4] = Mustafa;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	int x = 1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);//Green
	string s = "Welcome to Money Saver Bank";
	int c_w = 120;
	int len = s.length();
	if (len % 2 == 0)
		s += " ";
	cout << setw((c_w / 2) + len / 2) << right << s << endl << endl << endl << endl;
	cout << "if you are a new client Enter 0[otherwise Enter 1]: ";
	cin >> x;
	int c = 0;
	bool login = 0;
	while (login == 0)
	{
		if (x == 0)//new client
		{
			c = 5;
			client[c] = new_client();//function of the client


			cout << "**************************************************************************************************\n";
			login_pins();

			login = 1;


		}
		else if (x == 1)//old client
		{
			bool c_check = 1;
			while (c_check)
			{
				int pin;
				pin = login_pins();
				bool c = 1;
				int q = 1;
				while (c)
				{
					for (q; q <= 3; q++)
					{


						if (pin == client[c].pin)
						{
							cout << "welcome " << client[c].name << endl;
							q = 0;
							c_check = 0;
						}

						else if (c == 9)
						{
							for (int z = 1; z <= 3; z++)
							{
								cout << "your have entered a wrong pin" << endl;
								pin = login_pins();
								if (z == 3) 
								{
									cout << "done";
								}
								else
								{


									c = 0;
								}
							}



						}
						else
						{
							c++;

						}
						login = 1;
					}
				}
			}
		}
		else//invalid 
		{


			cout << "you have entered an invalid number please choose a valid one : ";
			cin >> x;
			login = 0;
		}
	}
	int menu_choice;
	cout << "please choose the operation you want by pressing it's number \n";
	bool another_option = 0;
	while (another_option == 0)
	{

		cout << "1-Balance checking \n" << "2-Money withdrawl \n" << "3-Money transfer \n";
		cin >> menu_choice;
		if (menu_choice == 1)
		{
			cout << "you have chosen balance checking \n";
			checking(client[c].balance);

		}
		else if (menu_choice == 2)
		{
			cout << "you have chosen money withdrawl \n";
			withdrawl(client[c].balance);
		}
		else if (menu_choice == 3)
		{
			cout << "you have chosen money transfer " << endl << "enter the name of the accont you want to transfer money to: ";
			string N2;
			cin >> N2;
			bool Q = 1;
			int Transfer = 0;
			while (Q == 1)
			{


				if (N2 == client[Transfer].name)
				{

					transfer(N2, client[c].balance, client[Transfer].balance);
					Q = 0;
				}

				else
				{
					Transfer++;
				}



			}
		}
		int another_op;
		cout << "If you want to choose an anohter operation press 1 : ";
		cin >> another_op;
		if (another_op == 1)
		{
			another_option = 0;

		}
		else
		{
			cout << "Thank you for using our service \n";
			another_option = 1;
		}
	}
	system("pause");

}











