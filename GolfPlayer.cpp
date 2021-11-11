#include <iostream>
#include "GolfPlayer.h"

using namespace std;

void GolfPlayer:: setName(string nm){
	name = nm;
}

string GolfPlayer:: getName() const{
	return name;
}

void GolfPlayer:: setAverage(int as){
	averageScore = as;
}

int GolfPlayer:: getAverage() const{
	return averageScore;
}