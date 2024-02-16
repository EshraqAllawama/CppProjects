
#include<iostream>
#include<conio.h>
using namespace std;

string userNmae_Nurse0 = "Ahmad";
string userPass_Nurse0 = "18@aa";
string ch = "Yes"; //Variable if the user wants to re-test
string M[3] = { "A1C","FBSLT","OGTT" };
string test;//The test that was chosen
int p = 0;
class Info;


class A1C // The first form from test forms
{

private:

	int co;
	double avgre; //average
	double Readings[10];

public:

	void test() // Function To take the values

	{
		avgre = 0;
		co = 1; // counter
		cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
		cout << "--plz Enter 10 readings for diabetes " << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << co++ << "- ";
			cin >> Readings[i];
			if (i == 9)
				cout << endl << "**End of entering readings**\n\n";
			else
				cout << " \t\t reminder : " << 9 - i << endl;
			avgre += Readings[i];

		}
		avgre /= 10;
	}

	void Result(Info& U); // Extract the test result


};


class FBSLT // The Second form from test forms
{
private:
	int co;
	double avgre;//average
	double Readings[1];
public:
	void test() // Function To take the values
	{ 
		avgre = 0;
		co = 1;// counter
		cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
		cout << "--plz Enter one reading for diabetes" << endl;
		for (int i = 0; i < 1; i++)
		{
			cout << co++ << "- ";
			cin >> Readings[i];
			cout << endl << "**End of entering readings**\n\n";
			avgre = Readings[i];

		}
		avgre /= 1;

	}
	void Result(Info& U); // Extract the test result



};


class OGTT // The Third form from test forms
{
private:
	int co;
	double avgre; //average
	double Readings[6];
public:
	void test()// Function To take the values
	{
		avgre = 0;
		co = 1;// counter
		cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
		cout << "plz Enter 6 readings for diabetes" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << co++ << "- ";
			cin >> Readings[i];
			if (i == 5)
				cout << endl << "**End of entering readings**\n\n";
			else
				cout << " \t\t reminder : " << 5 - i << endl;
			avgre += Readings[i];

			
		}
		
		avgre /= 6;
		
	}




	void Result(Info& U); // Extract the test  result

};

class Info // specific all Information for User ( log out , log in , Number attemps for both)
{


private:
	string userNmae_Nurse1;
	string userPass_Nurse1;

public:
	void Tests(int i)
	{
		FBSLT FB;
		A1C A1;
		OGTT OG;
		Info U;
		switch (i) //  Whiche test Will be Chosen ?
		{

		case 0: {
			A1.test();
			A1.Result(U);
			break;
		}
		case 1: {
			FB.test();
			FB.Result(U);
			break;

		}
		case 2: {
			OG.test();
			OG.Result(U);
			break;
		}

		}

	}

	void user() // The part log in and log out details for both 
	{
		cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
		int x = 1, w = 0;
		while (x <= 3 && ch == "Yes")
		{

			if (p == 0)
			{
				cout << "User Name :";
				cin >> userNmae_Nurse1;
				cout << "User Password :";
				cin >> userPass_Nurse1;
			}

			system("Cls"); // Cleaning up befor
			cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
			cout << endl;

			if (userNmae_Nurse0 == userNmae_Nurse1 && userPass_Nurse0 == userPass_Nurse1)
			{
				cout << "Available diabetes tests :"; cout << endl;
				cout << "1-A1C" << endl;
				cout << "2-FBSLT" << endl;
				cout << "3-OGTT" << endl << endl;
				cout << "--Testing required : ";
				cin >> test;
				system("Cls");
				for (int i = 0; i < 3; i++)
				{


					if (test == M[i])
					{
						Tests(i);
						w++;
						x = 1;
						break;
					}


				}

				if (w == 0)
				{
					x = 1;
					p++;
				}


			}


			x++;



		}

		if (x == 4) // log out after 3 attemps
		{
			cout << "Your trial period has expired. Please close the program and try again :(" << endl;
		}

	}

};

//  All The Function using output from 3 test 
void A1C::Result(Info& U)
{
	cout << "*Result*\n";
	if (5.7 > avgre)
		cout << " uninfected (Normal)\n\n";
	else if (5.7 <= avgre && 6.4 >= avgre)
		cout << " prediabetes\n\n";
	else
		cout << " injured \n\n";

	cout << "WARNING !!!!!!! \nYou have two chances to write the test correctly.. Otherwise, you will exit the program :)" << endl;
	cout << "*Do you want to get a diabetes test again?" << endl;
	cout << "Yes or No ?" << endl;
	cin >> ch;
	if (ch == "Yes")
	{
		system("Cls");
		p++;
		U.user();


	}
	else
	{
		system("Cls");
		cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
		cout << "Finished The program " << endl;
	}

}

void FBSLT::Result(Info& U)
{
	cout << "*Result*\n";
	if (avgre < 100)
		cout << "uninfected (Normal)" << endl;
	else if (100 <= avgre && avgre <= 125)
		cout << "prediabetes " << endl;
	else
		cout << "injured" << endl;

	cout << "WARNING !!!!!!! \nYou have two chances to write the test correctly.. Otherwise, you will exit the program :)" << endl;
	cout << "*Do you want to get a diabetes test again?" << endl;
	cout << "Yes or No ?" << endl;
	cin >> ch;
	if (ch == "Yes")
	{
		system("Cls");
		p++;
		U.user();


	}
	else
	{
		system("Cls");
		cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
		cout << "Finished The program " << endl;
	}


}

void OGTT::Result(Info& U)
{
	cout << "*Result*\n";
	if (avgre < 140)
		cout << "uninfected (Normal)" << endl;
	else if (140 <= avgre && avgre <= 199)
		cout << "prediabetes " << endl;
	else
		cout << "injured" << endl;

	cout << "WARNING !!!!!!! \nYou have two chances to write the test correctly.. Otherwise, you will exit the program :)" << endl;
	cout << "*Do you want to get a diabetes test again?" << endl;
	cout << "Yes or No ?" << endl;
	cin >> ch;
	if (ch == "Yes")
	{
		system("Cls");
		p++;
		U.user();


	}
	else
	{
		system("Cls");
		cout << " \t\t\t\t\t\Diabetes Screening System" << endl;
		cout << "Finished The program " << endl;
	}

}
int main()
{
	Info U;
	U.user();
	return 0;
}
