#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int card_deck[52][2], //store the card deck (both numbers and suits)
	pointer; //point to the next card to be drawn
char suit[4]; //'S', 'H', 'C', 'D'
int player_hand[4][15][2], //cards in the player's hands
	dealer_hand[15][2], //cards in the dealer's hand
	hand_number[4], //number of cards in each hand of the player
	dealer_number; //number of cards that dealer has in hand
int cards_remain[14], //record how many cards remain for each rank
	split, //how many splits the player has
	indicator, //indicate the hand which can split
	player_sum[4], dealer_sum; //sum of their hand cards
double money_total, expected_value, this_round, init;

void exchange_value(int & a, int & b){
	int t;
	t=a;a=b;b=t;
}
//set the card deck for the test case
void test_shuffle(){
	card_deck[0][0]=2; card_deck[0][1]=3;
	card_deck[1][0]=2; card_deck[1][1]=1;
	card_deck[2][0]=3; card_deck[2][1]=2;
	card_deck[3][0]=7; card_deck[3][1]=3;
	card_deck[4][0]=5; card_deck[4][1]=2;//5 and 2   //!!!!!!!!!!!!!
	card_deck[5][0]=9; card_deck[5][1]=3;
	card_deck[6][0]=10; card_deck[6][1]=1;
	card_deck[7][0]=2; card_deck[7][1]=2;
	card_deck[8][0]=4; card_deck[8][1]=3;
	card_deck[9][0]=3; card_deck[9][1]=0;
	card_deck[10][0]=4; card_deck[10][1]=1;
	card_deck[11][0]=11; card_deck[11][1]=3;

	card_deck[40][0]=1; card_deck[40][1]=0;
	card_deck[14][0]=5; card_deck[14][1]=0;
	card_deck[28][0]=10; card_deck[28][1]=0;
	card_deck[45][0]=4; card_deck[45][1]=0;
	//card_deck[4][0]=2; card_deck[4][1]=0;//5 and 2   //!!!!!!!!!!!!!
	card_deck[30][0]=2; card_deck[30][1]=0;
	card_deck[47][0]=6; card_deck[47][1]=0;
	card_deck[22][0]=7; card_deck[22][1]=0;
	card_deck[27][0]=8; card_deck[27][1]=0;
	card_deck[42][0]=9; card_deck[42][1]=0;
	//card_deck[9][0]=3; card_deck[9][1]=0;
	card_deck[16][0]=11; card_deck[16][1]=0;
	card_deck[49][0]=12; card_deck[49][1]=0;
	int randnum;
	srand(time(0));
	for (int i=12; i<52; i++){
		randnum=(double)rand()/RAND_MAX*(52-12)+12;
		//exchange the rank
		exchange_value(card_deck[i][0],card_deck[randnum][0]);
		//exchange the suit
		exchange_value(card_deck[i][1],card_deck[randnum][1]);
		}
}

//set the card deck for the random case
void random_shuffle(){
	int randnum;
	srand(time(0));
	for (int i=0; i<52; i++){
		randnum=(double)rand()/RAND_MAX*52;
		//exchange the rank
		exchange_value(card_deck[i][0],card_deck[randnum][0]);
		//exchange the suit
		exchange_value(card_deck[i][1],card_deck[randnum][1]);
	}
}

//check if the hand card can be split
bool check_split(){
	for (int i=0; i<=split; i++)
		if (player_hand[i][0][0]==player_hand[i][1][0]){
			indicator=i;
			return true;
		}
	return false;
}

//check if any ace exist in the player's hand
bool player_ace_exist(int p){
	for (int i=0; i<hand_number[p]; i++)
		if (player_hand[p][i][0]==1) return true;
	return false;
}

//check if any ace exist in the dealer's hand
bool dealer_ace_exist(){
	for (int i=0; i<dealer_number; i++)
		if (dealer_hand[i][0]==1) return true;
	return false;
}

//check if the player have busted for all hands
bool all_exceed_21(){
	for (int i=0; i<=split; i++)
		if (player_sum[i]<=21) return false;
	return true;
}

//calculate the sum of hand p of the player
int calculate_player_sum(int p){
	int s, sum;
	sum=0;
	for (int i=0; i<hand_number[p]; i++){
		if (player_hand[p][i][0]==11 || player_hand[p][i][0]==12 || player_hand[p][i][0]==13) s=10;
		else s=player_hand[p][i][0];
		sum+=s;
	}
	return sum;
}

//calculate the sum of the cards of the dealer
int calculate_dealer_sum(){
	int s, sum;
	sum=0;
	for (int i=0; i<dealer_number; i++){
		if (dealer_hand[i][0]==11 || dealer_hand[i][0]==12 || dealer_hand[i][0]==13) s=10;
		else s=dealer_hand[i][0];
		sum+=s;
	}
	return sum;
}

//the game starts
void game_flow(){
	char if_split, conti;
	int h;
	pointer=0; dealer_number=0; split=0; dealer_sum=0;
	for (int i=0; i<4; i++) player_sum[i]=0;
	for (int i=0; i<4; i++) hand_number[i]=0;
	for (int i=0; i<=13; i++) cards_remain[i]=4;
	//deal out the starting cards
	player_hand[0][0][0]=card_deck[0][0]; player_hand[0][0][1]=card_deck[0][1]; cards_remain[card_deck[0][0]]--;
	hand_number[0]++; pointer++;
	player_hand[0][1][0]=card_deck[1][0]; player_hand[0][1][1]=card_deck[1][1]; cards_remain[card_deck[1][0]]--;
	hand_number[0]++; pointer++;
	dealer_hand[0][0]=card_deck[2][0]; dealer_hand[0][1]=card_deck[2][1]; cards_remain[card_deck[2][0]]--;
	dealer_number++; pointer++;
	dealer_hand[1][0]=card_deck[3][0]; dealer_hand[1][1]=card_deck[3][1]; cards_remain[card_deck[3][0]]--;
	dealer_number++; pointer++;
	//deal with the split situation
	while (check_split()){
		cout<<">Dealer: * ";
		for (int i=1; i<dealer_number; i++) cout<<dealer_hand[i][0]<<suit[dealer_hand[i][1]]<<' ';
		cout<<endl;
		cout<<">Player: ";
		for (int i=0; i<hand_number[0]; i++) cout<<player_hand[0][i][0]<<suit[player_hand[0][i][1]]<<' ';
		cout<<endl;
		for (int i=1; i<=split; i++){
			cout<<">split: ";
			for (int j=0; j<hand_number[i]; j++) cout<<player_hand[i][j][0]<<suit[player_hand[i][j][1]]<<' ';
			cout<<endl;
		}
		if (this_round+init>money_total){
			cout<<"You don't have enough money to split again!"<<endl;
			break;
		}
		cout<<"Split?(split the first if more than one hand can be split)(Y/N): ";
		cin>>if_split;
		if (if_split=='y' || if_split=='Y'){
			this_round+=init;
			split++;
			player_hand[split][0][0]=player_hand[indicator][1][0]; player_hand[split][0][1]=player_hand[indicator][1][1];
			hand_number[split]++;
			player_hand[indicator][1][0]=card_deck[pointer][0]; player_hand[indicator][1][1]=card_deck[pointer][1];
			cards_remain[card_deck[pointer][0]]--; pointer++;
			player_hand[split][1][0]=card_deck[pointer][0]; player_hand[split][1][1]=card_deck[pointer][1];
			cards_remain[card_deck[pointer][0]]--; hand_number[split]++; pointer++;
		} else break;
	}
	//draw the cards
	for (int i=0; i<=split; i++){
		do {
			player_sum[i]=calculate_player_sum(i);
			cout<<">Dealer: * "<<dealer_hand[1][0]<<suit[dealer_hand[1][1]]<<endl;
			for (int k=0; k<=split; k++){
				cout<<">Player hand "<<k+1<<": ";
				for (int j=0; j<hand_number[k]; j++) cout<<player_hand[k][j][0]<<suit[player_hand[k][j][1]]<<' ';
				cout<<endl;
			}
			cout<<"Draw for hand "<<i+1<<"?(Y/N): ";
			cin>>conti;
			if (conti=='Y' || conti=='y'){
				player_hand[i][hand_number[i]][0]=card_deck[pointer][0]; player_hand[i][hand_number[i]][1]=card_deck[pointer][1];
				hand_number[i]++; pointer++;
				player_sum[i]=calculate_player_sum(i);   //no need to consider A 1 or 11 here
			}
		} while((conti=='Y' || conti=='y') && hand_number[i]<5 && player_sum[i]<=21);
	}
	dealer_sum=calculate_dealer_sum();
	if (all_exceed_21()) return;
	//the dealer's round
	do {
		dealer_sum=calculate_dealer_sum();
		expected_value=0;
		for (int i=1; i<=13; i++){
			if (i==11 || i==12 || i==13) h=10; else h=i;
			expected_value+=h*(double(cards_remain[i])/(52-2*(split+1)-dealer_number));
		}
		if (dealer_ace_exist()){
			if (dealer_sum+10<=21) dealer_sum+=10;
		}
		if (dealer_sum+expected_value <= 21){
			dealer_hand[dealer_number][0]=card_deck[pointer][0]; dealer_hand[dealer_number][1]=card_deck[pointer][1];
			cards_remain[card_deck[pointer][0]]--; dealer_number++; pointer++;
		}
		else break;
	} while (dealer_number<5 && dealer_sum<=21);

}

int main(){
	double win;
	char next, if_test;
	money_total=100;
	suit[0]='S';suit[1]='H';suit[2]='C';suit[3]='D';
	//initialize card deck
	for (int i=0; i<52; i++){
		card_deck[i][0]=(i % 13)+1;
		card_deck[i][1]=i/13;
	}

	//main loop
	do {
		win=0;
		cout<<"Player: $"<<money_total<<endl<<"Pay for this round: ";
		cin>>this_round;
		while (this_round>money_total){
			cout<<"You cannot pay more than you have!"<<endl;
			cout<<"Player: $"<<money_total<<endl<<"Pay for this round: ";
			cin>>this_round;
		}
		init=this_round;
		cout<<"Test case?(Y/N): ";
		cin>>if_test;
		if (if_test=='y' || if_test=='Y') test_shuffle();
		else random_shuffle();
		game_flow();
		//output the result
		cout<<">Dealer: ";
		for (int i=0; i<dealer_number; i++) cout<<dealer_hand[i][0]<<suit[dealer_hand[i][1]]<<' ';
		cout<<endl;
		for (int k=0; k<=split; k++){
			cout<<">Player hand "<<k+1<<": ";
			for (int j=0; j<hand_number[k]; j++) cout<<player_hand[k][j][0]<<suit[player_hand[k][j][1]]<<' ';
			cout<<endl;
		}
		cout<<">Dealer "<<dealer_sum<<" points, Player ";
		for (int i=0; i<=split; i++) {
			if (player_ace_exist(i) && player_sum[i]+10<=21) player_sum[i]+=10;
			cout<<player_sum[i]<<" points, ";
			if (player_sum[i]==21 && hand_number[i]==2) win+=1.5*init;
			else if ((player_sum[i]>dealer_sum && player_sum[i]<=21) || ((player_sum[i]<=21) && dealer_sum>21)) win+=2*init;
			else if (player_sum[i]==dealer_sum && dealer_sum<=21) win+=init;
		}
		cout<<"Player win "<<win-this_round<<" dollars."<<endl;
		money_total+=win-this_round;
		if (money_total<=0) {
			cout<<"You have no money!";
			break;
		}
		cout<<"Again?(Y/N): ";
		cin>>next;
	} while (next=='Y' || next=='y');
	if (money_total>0) cout<<"You have "<<money_total<<" dollars left.";
	return 0;
}
