#include "Player.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
	int Player::count = 0;
	Player::Player(){
		this->jrnum = 0;
    	strcpy(this->name,"Not-Given.");
    	this->match = 0;
    	this->runs = 0;
    	this->wickets = 0;
//    	count++;
	}
	Player::Player(int jr,const char* nm, int m, int r, int w){
		this->jrnum = jr;
    	strcpy(this->name,nm);
    	this->match = m;
    	this->runs = r;
    	this->wickets = w;
    	count++;
	}
    	
	void Player::setJrNum(int jrNum) {
        jrnum = jrNum;
    }
    void Player::setName(const char* pNm) {
        strncpy(this->name, pNm, sizeof(name));
        name[sizeof(this->name) - 1] = '\0';
    }
    void Player::setMatches(int m) {
        this->match = m;
    }
    void Player::setRuns(int r) {
        this->runs = r;
    }
    void Player::setWickets(int w) {
        this->wickets = w;
    }
    
    void Player::setCount(int c){
    	count = c;
	}
	
	int Player::getJrNum() {
        return this->jrnum;
    }
    const char* Player::getName() {
        return this->name;
    }
    int Player::getMatches() {
        return this->match;
    }
    int Player::getRuns() {
        return this->runs;
    }
    int Player::getWickets() {
        return this->wickets;
    }
    
    int Player::getCount(){
    	return count;
	}
	
	void Player::printTableHeader() {
	    cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
	    cout << "|  JERSY NO.   |                  PLAYER NAME              |        Total M        |    Runs    |    Wickets    |\n";
	    cout << "------------------------------------------------------------------------------------------------------------------\n";
	}
    
	void Player::Display() {
        cout << "\n" << "|" << setw(8) << this->getJrNum() << " " << setw(32) << this->getName() << " " << setw(30) << this->getMatches() << " " << setw(23) << this->runs << " " << setw(10) << this->wickets << " " << setw(6) << "|" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------\n";
    }
    
