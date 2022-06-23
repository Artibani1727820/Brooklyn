#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
  int NumCh = 16;
  int TotEvents = 60000;
  double event[NumCh][TotEvents] = {0};

  int ch, partID, Nevent = 0;
  double E = 0.;
  ifstream infile;
  infile.open("run1Gev.txt");
  while (!infile.eof()) {
    infile >> ch >> E >> partID >> Nevent;
    event[ch][Nevent]+=E;
  }
  event[ch][Nevent]-=E;
  infile.close();

  ofstream outfile;
  outfile.open("runcleaned1Gev.dat");
  for (int i=0; i<TotEvents; i++) {
    for (int j=0; j<NumCh; j++) {
      outfile << event[j][i] << " ";
    }
   outfile << endl;
  }
  outfile.close();
  return 0;
}
  
  
