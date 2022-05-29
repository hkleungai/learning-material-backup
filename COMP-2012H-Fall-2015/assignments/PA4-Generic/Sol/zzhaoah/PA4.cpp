//============================================================================
// Name        : PA4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "bigint.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <chrono>
#include <thread>

using namespace std;

char str1[65535];
char str2[65535];
char str3[65535];
char str4[65535];
char temp[65535*4];


int main() {
	ifstream fin("1.txt");
	ofstream output("result.txt");
	if ( !fin ) {
			cerr << "error: unable to open input file " << "1.txt" << "\n";
			exit (-1);
		}
   // string temp;
    int intNum;
	    fin >> intNum;
	    fin.getline( temp, 65535*4);

		for(int i=0; i<intNum; i++)
		{
			if (i%100==0){
				cout<<i<<" completed."<<endl;
			}
			int templength;
	        fin.getline( temp, 65535*4);
	        for (int j = 0; j < 65535 * 4; j++){
	        	if (temp[j]=='}'){
	        		temp[j+1] = '\0';
	        		templength = j+1;
	        		break;
	        	}
	        }
	        int num1start = 1; int num1end;
	        int num2start; int num2end;
	        int num3start; int num3end = templength - 2;
	        int commacount = 0;
	        for (int j = 0; j < templength; j++){
	        	if (temp[j]==','){
	        		switch (commacount){
	        		case 0:
	        			num1end = j-1;
	        			num2start = j+2;
	        			++commacount;
	        			break;
	        		case 1:
	        			num2end = j-1;
	        			num3start = j+2;
	        		}
	        	}
	        }
	        for (int j = num1start; j <= num1end; j++){
	        	str1[j-num1start] = temp[j];
	        }
	        str1[num1end+1-num1start] = '\0';
	        for (int j = num2start; j <= num2end; j++){
	        	str2[j-num2start] = temp[j];
	        }
	        str2[num2end+1-num2start] = '\0';
	        for (int j = num3start; j <= num3end; j++){
	        	str3[j-num3start] = temp[j];
	        }
	        str3[num3end+1-num3start] = '\0';
	        BigInt bi1(str1);
	        BigInt bi2(str2);
	        BigInt bi3(str3);
	        BigInt result = bi1 * bi2;
	        if (result != bi3){
	        	cout <<str1<<" * "<<str2<<" should be "<<str3<<", wrong result: "<<result<<endl;
	        	output<<"error"<<endl;
	        	continue;
	        }
	        auto t1 = std::chrono::high_resolution_clock::now();
	        for (int j = 0; j < 100; j++){
	        	result = bi1 * bi2;
	        }
	        auto t2 = std::chrono::high_resolution_clock::now();
	        output<< chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() <<endl;
		}
	return 0;
}
