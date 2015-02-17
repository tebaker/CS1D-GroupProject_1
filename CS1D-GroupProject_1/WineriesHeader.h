#ifndef WineriesHeader_H_
#define WineriesHeader_H_
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <limits>
#include <ios>
#include <windows.h>
using namespace std;

//information holding the vintage (year) and price of bottle
struct bottleInfo{
	//year the wine was bottled
	int   vintage;
	//how much this specific bottle of wine costs
	float price;
};

//holding all the relevant information for the wineries
struct wineryInfo
{
	//THIS wineries name
	string name;
	//THIS wineries number
	int	   ownNumber;
	//Total number of wineries in this list
	int    numOfWineries;
	//winery number is key that corresponds to a distance to other wineries
	map<int, float> otherWineryDistInfo;
	//holding the number of wines that are offered at each winery
	int    numWinesOffered;
	//Name of wine is the key that corresponds to the bottleInfo
	map<string, bottleInfo> offeredWineInfo;
};

class Wineries {
	public:
		//Default constructor
		Wineries();
		//default destructor
		virtual ~Wineries();

//MUTATORS////////////////////////////////////////////////////////////////////

		//eventually we will be able to add wineries

//ACCESSORS///////////////////////////////////////////////////////////////////
		//returns distance between two wineries RETURNS -1.0 IF ERROR
		float distBetween(int winery1, int winery2) const;
		//returns the name of the passed in winery number
		string nameOf(int wineryNumber) const;
		//returns the contents of the passed in winery number (Formatted in
		//a string)
		string print(int wineryNumber) const;
		//returns the total number of wineries
		int totWineries( ) const;
		//return true if there are no wineries in the list
		bool isEmpty( ) const;


	private:
			vector<wineryInfo> listOfWineries;
			vector<wineryInfo>::iterator it;
			int totalWineries;
};
#endif /* Wineries_H_ */
