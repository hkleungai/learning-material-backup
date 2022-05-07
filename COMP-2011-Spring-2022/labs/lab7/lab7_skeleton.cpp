/* Lab 7: Voting -- An election system
 * Struct and separate compilation
 * File: lab7_skeleton.cpp
 */

/* Task 4: After finishing the coding task 1 to task 3
 * separate the single lab7.cpp to 3 files
 *  - lab7.h 
 *  - main.cpp with definition of main()
 *  - lab7functions.cpp with definitions of all other functions
 *  - (optional) Makefile
 * You will need to demo your lab 7 with separate compilation 
 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 10;
const int MAX_STRING_LENGTH = 20;

enum Role
{
   CANDIDATE,
   VOTER
};

//names listed in no particular order :)
char names[MAX_SIZE][MAX_STRING_LENGTH] = {"JoeBiden", "QueenElizabethII", "Putin", "Trudeau", "XiJinping", "Macron", "KimJongun", "CarrieLam", "Zelenskyy", "Trump"};

// struct definition of Participant
struct Participant
{
   int id;
   char name[MAX_STRING_LENGTH];
   Role role;     // CANDIDATE or VOTER
   bool hasVoted; // true if voter has voted, false otherwise
   int voteCount; // number of votes received if the participant is a candidate of election, initilized as 0
};

// struct definition of Election
struct Election
{
   Participant participants[MAX_SIZE];
   int numCandidates; //note candidates can also vote
   int numVoters;
   // the candidates will occupy the first numCandidates elements in the participants array,
   // while the other voters will occupy the next numVoters elements in the participants array
};

/* Helper function
 * Print participants
 * Parameter:
 *    - election: the Election struct object
 */
void printParticipants(const Election &election)
{

   for (int i = 0; i < election.numCandidates + election.numVoters; i++)
   {
      cout << "ID: " << election.participants[i].id << "\tName:" << election.participants[i].name << "\t";
      if (election.participants[i].role == CANDIDATE)
         cout << "Role: Candidate" << endl;
      else
         cout << "Role: Voter" << endl;
   }
}

/* Task 1: 
 * Setup the election
 * - initialize all the member variables of the Election object
 * Parameters:
 *    - election: a Election struct object
 * Note:
 *    - id for voter/candidate are assigned as 1, 2, 3, ...in sequence
 *    - name for voter/candidate are copied from names[][] in sequence
 *    - role: CANDIDATE or VOTER (note candidate can also vote)
 *    - hasVoted = false, voteCount = 0
 */
void setup(Election &election, int numCandidates, int numVoters)
{
   
}



/* Task 2:
 * Casting votes to some candidates by a specific voter given the voter id
 * Parameters:
 *    - election: the Election struct object
 *    - voterId: the voter's id
 * Note:
 *    validates the following 
 *    - voter id has to be valid, note candidate can also vote
 *    - candidate id has to be valid
 *    - voter can only vote once
 */
void voting(Election &election, int voterID)
{
   
}

/* Task 3:
 * Output the number of votes for each candidate
 * and announce the winner by finding who has the maximum number of votes
 * Parameters:
 *    - election: the Election struct object
 * Note: if there is more than 1 candidate has the same number of maximum votes,
 * announce it as a tie election.
 */
void resultTallying(const Election &election)
{
   
}

// Main function for the election system
int main()
{
   // Create an election
   Election election;
   int numCandidates, numVoters;

   cout << "===============================" << endl;
   cout << " Welcome to the voting system! " << endl;
   cout << "===============================" << endl;
   cout << "Preparing ... " << endl;
   do
   {
      cout << "Enter how many candidates will run for the election: \n";
      cin >> numCandidates;
      cout << "Enter how many more voters: \n";
      cin >> numVoters;
   } while (((numCandidates + numVoters) > MAX_SIZE) || (numCandidates <= 0));
   cout << "\n";

   // the setup phase
   setup(election, numCandidates, numVoters);

   // print candidates and voters
   printParticipants(election);

   int currentId;
   int voteCount = 0;

   // voting
   cout << "Voting starts ..." << endl;
   char cmd;
   do
   {
      cout << "Enter the voter id to start voting:\n"; //candidates can also vote
      cin >> currentId;

      voting(election, currentId);

      cout << "Continue with the next voter? (y/n) ";
      cin >> cmd;
   } while ((cmd == 'y') || (cmd == 'Y'));

   cout << "Tallying votes ..." << endl;
   //the result-tallying phase
   resultTallying(election);

   cout << "End of the election!" << endl;
   return 0;
}
