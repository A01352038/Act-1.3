// =========================================================
// File: main.cpp
// Sergio Augusto Macías Corona - A01352038
// Date: 12/09/2022
// =========================================================
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include "selection.h"

int main(int argc, char *argv[])
{
  ifstream inputFile;
  ofstream outputFile;
  if (argc !=3){
		cout<<argv[0]<<"Input.txt Output.txt";
		return -1;
	}
	inputFile.open(argv[1]);
	if (inputFile.fail()){
		cout<<"Error";
		return -1;
	}
	outputFile.open(argv[2]);
	if(outputFile.fail()){
		cout<<"Error";
		return -1;
	}
  int n;
  string idSearch, date, h, p, id;

  // Ship struct
  struct shipStruct
  {
    int year,month,day;
    string date,h,p,id;
  };
  // Ships vector
  vector<shipStruct> ships;

  // Read file
  inputFile >> n;
  inputFile >> idS;

  for (int i = 0; i < n; i++)
  {
    // Read file
    inputFile >> date >> h >> p >> id;

    // Parse date
    string day = date.substr(0, date.find(""));
    string month = date.substr(3, date.find(""));
    string year = date.substr(6);

    // Find ships with idSearch in id
    std::size_t found = id.rfind(idSearch);
    if (found != string::npos)
    {
      // Add ship to ships vector
      ships.push_back({stoi(year), stoi(month), stoi(day), date, hour, port, id});
    }
  }

  // Sort ships vector by day and then my month with insertion sort algorithm
  insertionSortDay(ships);
  insertionSortMonth(ships);

  // Write output file
  for (int i = 0; i < ships.size(); i++)
  {
    outputFile << ships[i].dateString << "" << ships[i].hour << "" << ships[i].port << "" << ships[i].id << "\n";
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
