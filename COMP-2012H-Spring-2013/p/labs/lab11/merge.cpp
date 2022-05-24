#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

int main ()
{
    int i;

    int CSSize = 5;
    string CSCourse[] = {"Comp151", "Comp171", "Comp180", "Comp103", "Comp102"};
    Array <string> CS (CSCourse, CSSize);

    cout << "CS course list\n";
    for (i=0; i<CS.Size(); i++)
    {
        cout << CS[i] << " ";
    }
    cout << endl << endl;

    int EESize = 4;
    string EECourse[] = {"Elec102", "Elec151", "Elec211", "Elec214"};    
    Array <string> EE (EECourse, EESize);
    

    cout << "EE course list\n";
    for (i=0; i<EE.Size(); i++)
    {
        cout << EE[i] << " ";
    }
    cout << endl << endl;

    Array <string>  CPEG = CS;
    CPEG += EE;

    cout << "CPEG course list\n";
    for (i=0; i<CPEG.Size(); i++)
    {
        cout << CPEG[i] << " ";
    }
    cout << endl;

    return 0;
}