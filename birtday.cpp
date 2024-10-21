#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <set>

using namespace std;

string generateBirthday(){

  int month = rand() % 12 + 1;
  int day;
  if(month == 2) {
    day = rand() % 28 + 1;
  }
  else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
    day = rand() % 31 + 1;
  }
  else {
    day = rand() % 30 + 1;
  }
  string birthday = to_string(day) + '/' + to_string(month);
  return birthday;
}

bool simulation(int babyCount) {
  set<string> simulationBirthdaySet;
  for (int i = 0; i < babyCount ; i++) {
    auto check = simulationBirthdaySet.insert(generateBirthday());
    if(!check.second)
      return true; //true = matching birthday
  }
  return false;
}

double possibilityCheck(int babyCount, int simulationCount){
  int trueCount = 0;
  for(int i = 0; i < simulationCount; i++) {
    if(simulation(babyCount))
      trueCount++;
  }
  cout << trueCount << endl;
  return (double)trueCount / (double)simulationCount;
}

int main(){
  srand(time(0));

  int simulationCount = 0;
  int babyCount = 0;

  cout << "Simulation count: ";
  cin >> simulationCount;
  cout << "Baby Count: ";
  cin >> babyCount;

  cout << possibilityCheck(babyCount, simulationCount) << endl;

  return EXIT_SUCCESS;
}