#include <iostream>
//#include <iomanip>
//using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
class Player{
	//Player Attributes
    char name[30];
    int jrnum;
    int match;
    int runs;
    int wickets;
    
	static int count;
    
    public:
    	Player();
    	Player(int,const char*,int,int,int);
    	
    	void setJrNum(int);
    	void setName(const char*);
    	void setMatches(int);
    	void setRuns(int);
    	void setWickets(int);
    	
    	static void setCount(int);
    	static int getCount();
    	
    	int getJrNum();
    	const char* getName();
    	int getMatches();
    	int getRuns();
    	int getWickets();
    	
    	void printTableHeader();
    	void Display();
};
#endif
