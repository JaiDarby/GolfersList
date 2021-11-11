#include <iostream>

#ifndef GolfPlayer_H
#define GolfPlayer_H

using namespace std;

class GolfPlayer {
private:
	string name;
	int averageScore;
public:
	GolfPlayer(string nm, int as){name = nm; averageScore = as;};
	
	GolfPlayer(){name = "N/A"; averageScore = 0;};
	
	void setName(string nm);
	
	string getName() const;
	
	void setAverage(int as);
	
	int getAverage() const;
	
	
	
	
};
















#endif
