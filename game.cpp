#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;
class player
{
	float score;
	char name[400];
	void getData();
	void leaderboard();
	public:
		player()
		{
			score = 0;
		}
		void addData();
		void showData();
		void getscore();
}P_game;
class answers
{
	public:
		char a1[100];
		char a2[100];
		char a3[100];
		char a4[100];
		char a5[100];
		char a6[100];
		char a7[100];
		char a8[100];
		char a9[100];
		char a10[100];
		char m_a[100];
		answers();
}ans;
answers::answers()
{
	strcpy(m_a, "NULL");
	strcpy(a1, "Mark Zuckerberg");
	strcpy(a2, "Tim Cook");
	strcpy(a3, "Ajay Bhatt");
	strcpy(a4, "Simon");
	strcpy(a5,"Longhorn");
	strcpy(a6, "Octocat");
	strcpy(a7, "Jeff Bezos");
	strcpy(a8, "Transmission control protocol");
	strcpy(a9, "Ubisoft");
	strcpy(a10, "Blockchain");
}
void player::getData()
{
	cout<<"\nYour score: "<<score<<'\n';
	cout<<"Enter your name: ";
	cin.getline(name, 400);
}
void player::leaderboard()
{
	cout<<'\n'<<name<<setw(7)<<score;
}
void player::addData()
{
	ofstream F_add;
	F_add.open("QLeaderboard.dat", ios::binary | ios::app);
	P_game.getData();
	F_add.write((char*)&P_game, sizeof(P_game));
	F_add.close();
}
void player::showData()
{
	ifstream F_show;
	F_show.open("QLeaderboard.dat", ios::binary);
	cout<<"Name:"<<"\t\tScore:\n";
	while(F_show)
	{
		F_show.read((char*)&P_game, sizeof(P_game));
		if(F_show.eof())
		{
			break;
		}
		P_game.leaderboard();
	}
	F_show.close();
}
void player::getscore()
{
	score += 10;
}
void mainGame();
void startGame();
void questions();
int main()
{
	int x;
	system("cls");
	cout<<"******************************WELCOME******************************\n";
	cout<<"\t\t\t!!IT Quiz!!\t\t\n\n";
	cout<<"1. New Game\n";
	cout<<"2. Leaderboard\n";
	cout<<"3. Exit";
	cout<<"\n\nEnter Choice: ";
	ERROR:
	cin>>x;
	cin.ignore();
	switch(x)
	{
		case 1:
			startGame();
			break;
		case 2:
			system("cls");
			P_game.showData();
			break;
		case 3:
			exit(0);
		default:
			cout<<"Wrong input, please enter correct choice: ";
			goto ERROR;
	}
	return 0;
}
void startGame()
{
	char cont;
	system("cls");
	cout<<"RULES:\n";
	cout<<"1. There will be 10 questions.\n";
	cout<<"2. +10 on correct answer, +0 otherwise.\n";
	cout<<"BEST OF LUCK!";
	cout<<"\n\nDo you wish to begin?(y/n): ";
	cin>>cont;
	cin.ignore();
	if (toupper(cont)=='Y')
	{
		mainGame();
	}
	else
	{
		exit(0);
	}
}
void mainGame()
{
	char lead;
	system("cls");
	questions();
	cout<<"\n\nGAME OVER!";
	P_game.addData();
	cout<<"\nDo you wish to view the leaderboard(y/n): ";
	cin>>lead;
	cin.ignore();
	if (toupper(lead)=='Y')
	{
		system("cls");
		P_game.showData();
	}
	else
	{
		exit(0);
	}
}
void questions()
{
	cout<<"Q1: Who is the founder of Facebook?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if (!(strcmpi(ans.m_a,ans.a1)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a1<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q2: Who is the CEO of Apple?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a2)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a2<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q3: Who invented USB?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a3)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a3<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q4: What was the first smartphone called?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a4)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a4<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q5: What was the codename for Windows Vista ?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a5)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a5<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q6: What is the GitHub mascot called?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a6)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a6<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q7:Who founded Blue Origin?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a7)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a7<<"\n\n";
		system("pause");
	}	
	system("cls");
	cout<<"Q8: What does TCP stand for?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a8)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a8<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q9: Which studio developed Asassin's Creed?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a9)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a9<<"\n\n";
		system("pause");
	}
	system("cls");
	cout<<"Q10: what technology is used to record cryptocurrency transactions?\n";
	cout<<"Answer: ";
	cin.getline(ans.m_a, 100);
	if(!(strcmpi(ans.m_a,ans.a10)))
	{
		cout<<"Correct!\n\n";
		P_game.getscore();
		system("pause");
	}
	else
	{
		cout<<"Incorrect!\n";
		cout<<"Correct answer: "<<ans.a10<<"\n\n";
		system("pause");
	}
}

