/* Name: Jai'Mir Darby 
Date: Nov. 7th, 2021 
Section: (Your section)
Assignment: GolfersLL 
Due Date: Nov. 7th, 2021 
About this project: Creating linked lists
Assumptions: assumes correct user input, there is only one instance of best player in lists
All work below was performed by Jai'Mir Darby */


#include <iostream>
#include "GolfPlayer.h"
#include "listtools.h"
#include "listtools.cpp"

using namespace std;
using namespace LinkedListSavitch;

//Adds value to LL
void addValue(GolfPlayer player, Node<GolfPlayer>*& EndList);
//Displays values of LL
void displayValues (Node<GolfPlayer> * HeadLinkedList);
//Creates lists from original list
Node<GolfPlayer> * BeginnerGolfers (Node<GolfPlayer> * LinkedList);
Node<GolfPlayer> * AvgGolfers (Node<GolfPlayer> * LinkedList);
Node<GolfPlayer> * ExpertGolfers (Node<GolfPlayer> * LinkedList);
//Finds best player in a list
void FindBest(Node<GolfPlayer> * LinkedList);

int main() {
	
	Node<GolfPlayer> * HeadLinkedList1 = new Node<GolfPlayer>(GolfPlayer(),NULL);
	Node<GolfPlayer> * CurrentEndList1 = HeadLinkedList1;
	
	cout << "It's time to add your players" << endl;
	//variable to check if user wants to add another player
	char check = 'y';
	while (check != 'n'|| check != 'n'){
		string name;
		int score;
		//takes in player name
		cout << "What is the name of the player?: " ;
		cin >> name;
		//takes in player score
		cout << "What is the average score of the player?: ";
		cin >> score;
		//Checks if there is another golfer to add
		cout << "Would you like to add another player? [y/n]: ";
		cin >> check;
		//adds the golfer to the list
		GolfPlayer NextPlayer (name, score);
		addValue(NextPlayer, CurrentEndList1);
	}
	
	//Deletes irrelivant first node
	deleteFirstNode(HeadLinkedList1);
	
	//prints lists of all players and scores
	cout << "*****************************"<< endl << "Here is your current list of players: " << endl;
	displayValues(HeadLinkedList1);
	//prints lists of players in categories
	cout << "*****************************"<< endl << "Here is your list of beginner players: " << endl;
	Node<GolfPlayer> *Beginners = BeginnerGolfers (HeadLinkedList1);
	displayValues(Beginners);
	cout << "*****************************"<< endl << "Here is your list of Average players: " << endl;
	Node<GolfPlayer> *Average = AvgGolfers (HeadLinkedList1);
	displayValues(Average);
	cout << "*****************************"<< endl << "Here is your list of Expert players: " << endl;
	Node<GolfPlayer> *Expert = ExpertGolfers (HeadLinkedList1);
	displayValues(Expert);
	//prints best players in each list
	cout << "*****************************"<< endl << "Here is your best beginner player: " << endl;
	FindBest(Beginners);
	cout << "*****************************"<< endl << "Here is your best average player: " << endl;
	FindBest(Average);
	cout << "*****************************"<< endl << "Here is your best expert player: " << endl;
	FindBest(Expert);
}

void addValue(GolfPlayer player, Node<GolfPlayer>*& EndList){
	insert(EndList, player);
	EndList = EndList ->getLink();
	
}

void displayValues(Node<GolfPlayer> * HeadLinkedList){
	//display values
	Node<GolfPlayer> * LinkedList = HeadLinkedList;
	while (LinkedList!=NULL) {
		//display current node data
		cout<<LinkedList->getData().getName()<<endl << "Average Score: "<<LinkedList ->getData().getAverage() << endl;
		//move along to next node
		LinkedList=LinkedList->getLink();
	};
	
}

Node<GolfPlayer> * BeginnerGolfers (Node<GolfPlayer> * LinkedList){
	Node<GolfPlayer> * newLinkedList = NULL;
	//new Node<int>(0,NULL);
	Node<GolfPlayer> * CurrentEndNewList;
	
	while (LinkedList != NULL){
		
		int Avg = LinkedList->getData().getAverage();
		string name = LinkedList->getData().getName();
		if (Avg > 100){
			//first node
			if (newLinkedList == NULL)
				{
					newLinkedList = new Node<GolfPlayer>(GolfPlayer(name, Avg),NULL);
					CurrentEndNewList = newLinkedList;
					LinkedList = LinkedList->getLink();
				} //not first node
			else {
				addValue(LinkedList->getData(), CurrentEndNewList);
				LinkedList = LinkedList->getLink();
			}
		}
		else {LinkedList = LinkedList->getLink();}
	}
	return newLinkedList;
}

Node<GolfPlayer> * AvgGolfers (Node<GolfPlayer> * LinkedList){
	Node<GolfPlayer> * newLinkedList = NULL;
	//new Node<int>(0,NULL);
	Node<GolfPlayer> * CurrentEndNewList;
	
	while (LinkedList != NULL){
		
		int Avg = LinkedList->getData().getAverage();
		string name = LinkedList->getData().getName();
		if ((Avg <= 100)&& (Avg >= 80)){
			//first node
			if (newLinkedList == NULL)
				{
					newLinkedList = new Node<GolfPlayer>(GolfPlayer(name, Avg),NULL);
					CurrentEndNewList = newLinkedList;
					LinkedList = LinkedList->getLink();
				} //not first node
			else {
				addValue(LinkedList->getData(), CurrentEndNewList);
				LinkedList = LinkedList->getLink();
			}
		}
		else {LinkedList = LinkedList->getLink();}
	}
	return newLinkedList;
}

Node<GolfPlayer> * ExpertGolfers (Node<GolfPlayer> * LinkedList){
	Node<GolfPlayer> * newLinkedList = NULL;
	//new Node<int>(0,NULL);
	Node<GolfPlayer> * CurrentEndNewList;
	
	while (LinkedList != NULL){
		
		int Avg = LinkedList->getData().getAverage();
		string name = LinkedList->getData().getName();
		if (Avg < 80){
			//first node
			if (newLinkedList == NULL)
				{
					newLinkedList = new Node<GolfPlayer>(GolfPlayer(name, Avg),NULL);
					CurrentEndNewList = newLinkedList;
					LinkedList = LinkedList->getLink();
				} //not first node
			else {
				addValue(LinkedList->getData(), CurrentEndNewList);
				LinkedList = LinkedList->getLink();
			}
		}
		else {LinkedList = LinkedList->getLink();}
	}
	return newLinkedList;
}

void FindBest(Node<GolfPlayer> * HeadLinkedList){
	
	Node<GolfPlayer> * LinkedList = HeadLinkedList;
	int BestAvg = 1000000000;
	string BestAvgName;

	while (LinkedList!=NULL) {
		if (LinkedList ->getData().getAverage() < BestAvg){
			BestAvg = LinkedList ->getData().getAverage();
			BestAvgName = LinkedList ->getData().getName();
		}
		//move along to next node
		LinkedList=LinkedList->getLink();
	};
	cout<<BestAvgName<<endl << "Average Score: "<<BestAvg << endl;
}