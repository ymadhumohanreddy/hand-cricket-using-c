
#include<iostream>
#include<stdlib.h>
using namespace std;

class welcome{
public:
	void welpage();
};

class teams:public welcome{
    protected:
    char team1;
	char team2;
	public:
		
		void slctteam();
		void showteam();
};

class tdetails:public teams{
    protected:
    int maxplayers;
	int balls;	
	public:
	void getdet();
	void putdet();
};

class game:public tdetails{	 
    protected:
    int wick1 = 0;
	int wick2 = 0;
	int finnscore;
	int sinnscore;
public:
	int tos;
	int *target;
	game(){
		finnscore = 0;
		sinnscore = 0;		
	}
	void result();
	void toss();
	void firstinn1();
	void firstinn2();
	void innplay1();
	void sinnplay1();
	int gur();
	void innplay2();
	void sinnplay2();
	int gub();
	
};

void teams::slctteam()
{
	cout << endl << endl;
	cout << "Select your team name (A or B), computer team's name would be the other one :- " ;
	cin >> team1;
	if(team1 == 'A')
		team2 = 'B';
	else
		team2 = 'A';
}

void teams::showteam()
{
	cout << endl;
	cout << "   YOUR TEAM DETAILS" << endl;
	cout << "   TEAM-" << team1 << endl;
	cout << "   COMPUTER TEAM DETAILS" << endl;
	cout << "   TEAM-" << team2 << endl;
}

void tdetails::getdet()
{
	cout << endl << "Enter Number of players per team :- ";
	cin >> maxplayers;
	cout << endl << "Enter number of balls you want per innings :- ";
	cin >> balls;
}

void tdetails::putdet()
{	
	cout << endl;
	cout << "NUMBER OF PLAYERS PER TEAM :- " << maxplayers << endl;
	cout << "MAXIMUM BALLS PER INNINGS :- " << balls << endl;
}

void welcome::welpage()
{
    cout << endl << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "|=================== Instructions ===================|" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "|                                                    |" << endl;
    cout << "| 1. Select your team (A or B)                       |" << endl;
    cout << "|    Computer team will be the other one.            |" << endl;
    cout << "| 2. Decide the number of balls per innings(MAX 30). |" << endl;
    cout << "| 3. Lead the toss and decide the choice of play.    |" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl << endl;
    cout << "Press Enter To Continue";
    getchar();
}

void game::toss()
{
	cout << endl << "=================== T O S S ===================" << endl;
	int toss,ct,cc;
	srand (time(NULL));
	toss = rand() % 2; 
	cout << endl << "CALL YOUR TOSS(0 or 1) :- ";
	cin >> ct;
	if(ct == toss){
		cout << endl << " YOU HAVE WON THE TOSS." << endl;
		cout << endl << " CHOOSE:-\n1)BAT FIRST\n2)BOWL FIRST\n";
		cin >> cc;
		if(cc == 1){
			cout << endl << "YOU CHOOSE TO BAT FIRST.\n";
			tos = 1;
		}
		else{
			cout << endl << "YOU CHOOSE TO BOWL FIRST.\n";
			tos = 2;
		}
	}
	else{
		cout << "COMPUTER HAVE WON THE TOSS." << endl;
		cout << "COMPUTER CHOOSE TO BOWL FIRST." << endl;
		tos = 1;
	}
	cout << endl << endl;
}

int game::gur()
{
	
	int run;
	cout << endl << " ENTER RUNS YOU WANT TO SCORE IN THIS BALL :- " << endl;
	cin >> run;
	if(run < 0 || run > 6)
	{
		cout << " ENTER RUNS BETWEEN 0 & 6 " << endl;
		run=0;
		return run;
 		
	}
	else
	{
	return run;
	}
}

void game::innplay1()
{
	cout << endl << "==================FIRST INNINGS START===================" << endl; 
	cout << endl;
    cout << "Press Enter To Continue";
    getchar();
	int a[balls];
	int i = 1;
	srand (time(NULL));
	while(i <= balls)
	{
		a[i] = rand() % 7;
		i++;
	}
	int j = 1;
	for(j = 1; j <= balls; j++)
	{
		int tr = gur();
		if(tr != a[j])
		{
			cout << " Computer bowled " << a[j] << endl;
			finnscore = finnscore + tr;
		    cout << " YOUR SCORE IS " << finnscore << endl;
		}
		else
		{
			
			cout << " Computer also bowled " << a[j] << endl;
			cout << " OOPS!!! A WICKET DOWN!!! " << endl;
			wick1++;
			cout << " REMAINING PLAYERS :- " << maxplayers-wick1 << endl; 
			if(wick1 == maxplayers)
			{
				cout << " ALL OUT !!!!!" << endl;
				*target = finnscore+1;
				cout << " 1st Innings completed. " << endl;				
				cout << " Target for 2nd Innings :- " << finnscore+1 << endl;
				return;
			}			
		}			
	}
	*target = finnscore+1;
	cout << " 1st Innings completed. " << endl;
	cout << " Target for 2nd Innings :- " << finnscore+1 << endl;
}

void game::sinnplay1()
{
	cout << endl << "==================SECOND INNINGS START===================" << endl; 
	cout << " YOU NEED TO DEFEND " << *target << " RUNS." << endl;
	cout << endl;
    cout << "Press Enter To Continue";
    getchar();
    getchar();
	int b[balls];
	int i = 1;
	srand (time(NULL));
	while (i <= balls)
	{
		b[i] = rand() % 7;
		i++;
	}
	for(int j = 1; j <= balls; j++)
	{
		int bl = gub();
		if(bl != b[j])
		{
			cout << " Computer scored " << b[j] << " runs." << endl;
			sinnscore = sinnscore + b[j];
			cout << " Opponent Team score :- " << sinnscore << endl;
			if(*target - sinnscore > 0){
			cout << *target - sinnscore << " runs to defend from " << balls - j << " balls" << endl;}
			else 
			{
				cout << " Target has been chased successfully. " << endl;
				return;
			}
		}
		else
		{
			cout << " Computer also scored " << b[j] << " runs." << endl;
			cout << " Wohhoo!!! You have dismissed a player." << endl;
			wick1++;
			cout << " Remaining opponent players :- " << maxplayers-wick1 << endl;
			if(wick1 == maxplayers)
			{
				cout << " Oppenent Team ALL-OUT. " << endl;				
				cout << " 2nd Innings completed. " << endl;
				cout << " Runs scored in this innings :- " << sinnscore << endl;
				return;
			}
		}
	}	
	cout << " 2nd Innings completed. " << endl;
	cout << " Runs scored in this innings :- " << sinnscore << endl;
}

int game::gub()
{
	int bl;
	cout << endl << " ENTER RUNS YOU WANT TO CONCEDE IN THIS BALL :- " << endl;
	cin >> bl;
	if(bl<0 || bl>6)
	{
		cout << " ENTER RUNS BETWEEN 0 & 6!!!! " << endl;
		bl=0;
		return bl;
 		
	}

	
}

void game::innplay2()
{
	cout << endl << "==================FIRST INNINGS START===================" << endl; 
	cout << endl;
    cout << "Press Enter To Continue";
    getchar();
	int b[balls];
	int i = 1;
	srand (time(NULL));
	while (i <= balls)
	{
		b[i] = rand() % 7;
		i++;
	}
	for(int j = 1; j <= balls; j++)
	{
		int bl = gub();
		if(bl != b[j])
		{
			cout << " Computer scored " << b[j] << " runs." << endl;
			finnscore = finnscore + b[j];
			cout << " Opponent Team score :- " << finnscore << endl;
		}
		else
		{
			cout << " Computer also scored " << b[j] << " runs." << endl;
			cout << " Wohhoo!!! You have dismissed a player." << endl;
			wick1++;
			cout << " Remaining opponent players :- " << maxplayers-wick1 << endl;
			if(wick1 == maxplayers)
			{
				cout << " Oppenent Team ALL-OUT. " << endl;
				*target = finnscore+1;
				cout << " 1st Innings completed. " << endl;
				cout << " Runs scored in this innings :- " << finnscore << endl;
				return;
			}
		}
	}	
	*target = finnscore+1;
	cout << " 1st Innings completed. " << endl;
	cout << " Runs scored in this innings :- " << finnscore << endl;
}

void game::sinnplay2()
{
	cout << endl << "==================SECOND INNINGS START===================" << endl; 
	cout << " YOU NEED TO SCORE " << *target << " RUNS." << endl;
	cout << endl;
    cout << "Press Enter To Continue";
    getchar();
	int a[balls];
	int i = 1;
	srand (time(NULL));
	while(i <= balls)
	{
		a[i] = rand() % 7;
		i++;
	}
	int j = 1;
	for(j = 1; j <= balls; j++)
	{
		int tr = gur();
		if(tr != a[j])
		{
			cout << " Computer bowled " << a[j] << endl;
			sinnscore = sinnscore + tr;
		    cout << " YOUR SCORE IS " << sinnscore << endl;
		    if(*target - sinnscore > 0){
			cout << *target - sinnscore << " runs to defend from " << balls - j << " balls" << endl;}
			else 
			{
				cout << endl << " Target has been chased successfully. " << endl;
				return;
			}
		}
		else
		{			
			cout << " Computer also bowled " << a[j] << endl;
			cout << " OOPS!!! A WICKET DOWN!!! " << endl;
			wick1++;
			cout << " REMAINING PLAYERS :- " << maxplayers-wick1 << endl; 
			if(wick1 == maxplayers)
			{
				cout << " ALL OUT !!!!!" << endl;				
				cout << endl <<" 2nd Innings completed. " << endl;				
				cout << " Runs Scored in this Innings :- " << sinnscore << endl;
				return;
			}			
		}			
	}	
	cout << endl << " 2nd Innings completed. " << endl;
	cout << " Runs scored in this Innings :- " << sinnscore << endl;
}

void game::firstinn1()
{
	cout << "              TEAM "<<team1<<"  -->  BATTING             " << endl;
	cout << "              TEAM "<<team2<<"  -->  BOWLING             " << endl;
	cout << "             YOU HAVE TO BAT FIRST             " << endl;
    innplay1();
    sinnplay1();
}
void game::firstinn2()
{
	cout << "              TEAM "<<team1<<"  -->  BOWLING             " << endl;
	cout << "              TEAM "<<team2<<"  -->  BATTING             " << endl;
	cout << "             YOU HAVE TO BOWL FIRST            " << endl; 
	innplay2(); 
	sinnplay2();  
}

void game::result()
{
	cout << endl << "================== MATCH RESULT ===================" << endl;  
	cout << endl << "  FIRST INNINGS SCORE :- " << finnscore;
	cout << endl << "  SECOND INNINGS SCORE :- " << sinnscore;

	if( tos ==  1)
	{
		if(finnscore > sinnscore)
		{
			cout << endl << endl << " CONGRATULATIONS!!! YOU HAVE WON THE MATCH " << endl << endl;
			return;
		}
		else if(finnscore == sinnscore)
		{
			cout << endl << endl << " MATCH DRAWN " << endl << endl;
			return;
		}
		else
		{
			cout << endl << endl << " BETTER LUCK NEXT TIME. YOU HAVE LOST THE MATCH " << endl << endl;
			return;
		}
	}
	else
	{
		if(finnscore > sinnscore)
		{
		
			cout << endl << endl <<" BETTER LUCK NEXT TIME. YOU HAVE LOST THE MATCH " << endl << endl;
			return;
		}
		else if(finnscore == sinnscore)
		{
			cout << endl << endl <<" MATCH DRAWN " << endl << endl;
			return;
			
		}
		else
		{
			cout << endl << endl << " CONGRATULATIONS!!! YOU HAVE WON THE MATCH " << endl << endl;
			return;
		}
	}
}


int main()
{
	game g;
	int ch;
	cout << "------------------------------------------------------" << endl;
    cout << "|================ Hand Cricket Game =================|" << endl;
    cout << "|                                                    |" << endl;
    cout << "|            Welcome to Hand Cricket Game            |" << endl;
    cout << "|                                                    |" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl << endl;
    cout << "Press Enter To Continue";
    getchar();
    while(1)
    {
    	cout << endl << "1. START GAME \n2. INSTRUCTIONS \n3. QUIT " << endl;
    	cout << endl << endl << " ENTER YOUR CHOICE :-" ;
    	cin >> ch;
    	switch(ch)
    	{
    		case 1:
    		{
    			g.slctteam();
				g.getdet();
				g.showteam();
				g.putdet();
				g.toss();
				switch(g.tos)
				{
					case 1:
						g.firstinn1();
						break;
					case 2:
						g.firstinn2();
						break;
				}
				g.result();
				break;
			}
			case 2:
			{
				g.welpage();
				break;
			}
			case 3:
			{
				return 0;
				break;
			}
			default: cout << endl << " ENTER VALID CHOICE " << endl;
    	}
    }
	return 0;
}
