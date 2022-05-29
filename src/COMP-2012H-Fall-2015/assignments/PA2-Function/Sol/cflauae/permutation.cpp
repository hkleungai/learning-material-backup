/*
 * permutation.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: CHIFUNGJACKY
 */

#include<iostream> //for cout cin
#include<cstring> //for memset()

using namespace std;

void permutation(char [10],int,int); /*undergo permutation process
                                      parameter: char array which are the characters to be arranged in order
                                                 the function will do permutatoin within the position the first int and second int */
void swap(char&, char&); //swap the two characters within the char array

//mainly for user input interface
int main(){
	int counter;
	char inputList[10]={0}; //char array used to store the characters to undergo permutation
    int arraySize; //the size of of the char array, i.e. number of characters to be permuted
    bool errorInput; //store the value whether the user input is correct or not
    string permutateAgain; //store user input determining whether to run the program again or not

    do{
	   do{
		  //input the array size
	      cout<<"Please input array size (1-10): ";
	      cin>>arraySize;

	      //check whether it is a number and if yes, whether it is between the range of 1 and 10
	      errorInput=false;
	      if(arraySize<1 || arraySize>10 || cin.fail()==true){
		     cout<<"Invalid input! The array size should be in between 1 and 10!"<<endl;
	         cin.clear();
             cin.ignore(1000,'\n');
	         errorInput=true;
	      }
	    }while(errorInput); //redo if there is error in the input process

        do{
           //input the characters to be permuted
	       cout<<"Please input array elements: ";
	       for(counter=0;counter<=arraySize-1;counter++){
		       cin>>inputList[counter]; //put the input into the array
		       //if the next character read will be \n, it will break the loop
		       if(cin.peek()=='\n')
			      break;
	       }
           cin.ignore(10000,'\n'); //clear excess characters input by users which will not be stored in the char array

           /*show the characters which are going to be permuted while check whether no. of characters entered is equivalent to what the user has declared
             e.g. if user inputs array size of 4 but he/she enters a b c , error messgage will be shown
                  if user inputs array size of 4 but he/she enters a b c d e f, no error message will be shown and the program will show
                  "The program is going to permute a b c d" (i.e. it all depends on the arraysize you input previously)
            */
           errorInput=false;
           cout<<"The program is going to permute: ";
	       for (counter=0;counter<=arraySize-1;counter++){
		        if (inputList[counter]==0){
			        cout<<endl;
			        cout<<"The number of input you entered is smaller than the array size!\n";
			        cout<<"Please input again! \n";
			        errorInput=true;
			        memset(inputList,'\0',10);
			        break;
		        }
		        else
		            cout<<inputList[counter]<<" ";
	       }
        }while(errorInput);

        cout<<'\n';

        permutation(inputList,0,arraySize-1); //call the permutation function
        memset(inputList,'\0',10); //clear the value stored in array when the permutation is finished
        cout<<"Continue to use this program? (C/c to continue): "; //asking for running the program again or not
        cin>>permutateAgain;
    }while(permutateAgain=="C"||permutateAgain=="c") ; //run the program again if user input "C" or "c"


    return 0; //exit sucessfully
}

// i: the array index of starting character in the array to be permuted
// j: the array index of last character in the array to be permuted
void permutation(char list[10],int i,int j){
    int counter; //counter for the loop
    int checkCount; //counter for checking duplication, if there is duplication the index of duplicating character in the array will be stored in checkCount
    bool duplicate=false; //if there is duplication in permutation, the value will turn true and the program will avoid printing the duplicate result

    //Terminal case: when the recursion reaches the last character, print the result out
    if(i==j){
       for(counter=0;counter<=j;counter++){
    	   cout<<list[counter];
       }
       cout<<endl;
    }
	else{
		for(counter=i;counter<=j;counter++){
		    for(checkCount=0;checkCount<counter;checkCount++){
		       //the if-statement which will determine there will be duplication occuring
		       if((list[checkCount]==list[counter] && i<=checkCount)){
		    	   duplicate=true;
		           break; //once the valid duplication is found, program will directly quit the checking loop
		       }
		       else
		    	   duplicate=false;
		    }

		    //if there is duplication, skip this loop and continue
		    if(duplicate==true)
		    	continue;
		    else{
			swap(list[counter],list[i]); //swap the two characters
		    permutation(list,i+1,j); //call the recursion to permute (i+1)th character to jth character
		    swap(list[counter],list[i]); //swap back the two characters to the initial position
		    }
		}
	}
}


void swap(char&a,char&b){
	char temp=a; //temperorarily store character a
	a=b; //assign character stored in b to a
	b=temp; //assign character stored in temp (a) to b
}

