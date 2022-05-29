#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/* Initialize the game */

//define variables
char test_case;
bool game_over = false;
bool player_game_over = false;
bool split_game_over[3] = { false, false, false };
bool display_split[3] = { false, false, false };
bool split = true;

int split_times = 0;
int split_times_max = 3;
int draw = 1;	//count the times for draw
int draw_max = 4;	//Maximum draw
int splitdraw[3] = { 0, 0, 0 }; //count the times for split draw
int dealer_draw = 1; //count the times for dealer

double player_money = 100;
double bet = 0;

//calculate the points
double dealer_point = 0;
int player_point = 0;
int split_point[3];

//calculate the final points
int final_dealer_point = 0;
int final_player_point = 0;
int final_split_point[3];

int Player_card_rank[5];
int Dealer_card_rank[5];
char Player_card_suit[5];
char Dealer_card_suit[5];

//arrays to store cards for at most 3 possible split players
int Split_card_rank[5][3];
char Split_card_suit[5][3];

//arrays to store existing card information
int total_card_rank[25];
char total_card_suit[25];
int total_card_num = 0;

//store the card num for each rank
int various_card_num[13] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
int known_card_num = 4;
double expectation = 0; //math expectation

int test_case_rank[12] = { 2, 2, 3, 7, 5, 9, 10, 2, 4, 3, 4, 11 };
char test_case_suit[12] = { 'D', 'H', 'C', 'D', 'C', 'D', 'H', 'C', 'D', 'S',
		'H', 'D' };

//function prototype

int generate_card_rank(void);
char generate_card_suit(void);
void gameover(void);
void split_card(int &, char &);
void update_the_screen(void);
bool check_the_card(int, char);
bool check_split_occur(int, int);
void generate_new_card(int &, char &);
void draw_for_split(int);
void draw_for_dealer(void);
int calculate_Ace(int, int);

int main() {

	while (game_over == false) {

		cout << "\nPlayer:$ " << player_money << endl;
		cout << "Pay for this round: ";

		cin >> bet;	//ask the player to pay for the game
		//guarantee the bet must be smaller than the money player has
		while (bet > player_money) {
			cout << "You cannot pay more than you have!" << endl;
			cout << "Pay for this round: ";
			cin >> bet;
		}

		player_money -= bet;
		cout << "Test case? (Y/N): ";
		cin >> test_case;

		//when it is not test case
		if ((test_case != 'Y') && (test_case != 'y')) {
			//initialize random number generator
			srand(time(NULL));
		}

		//generate the first card for player
		generate_new_card(Player_card_rank[0], Player_card_suit[0]);

		while ((draw <= draw_max) && (player_game_over == false)) {
			//After the player draw two cards, generate the first two cards for the dealer

			//initialize the point player gets
			player_point = 0;
			//generate the card player has drawn
			generate_new_card(Player_card_rank[draw], Player_card_suit[draw]);
			//check the card is different from existing card
			while (check_the_card(Player_card_rank[draw],
					Player_card_suit[draw]) == false) {
				//if so,generate a new card
				total_card_num--;
				generate_new_card(Player_card_rank[draw],
						Player_card_suit[draw]);

			}

			if (draw == 1) {
				//generate the first card for dealer
				generate_new_card(Dealer_card_rank[0], Dealer_card_suit[0]);
				//check the card is different from the existing card
				while (check_the_card(Dealer_card_rank[0], Dealer_card_suit[0])
						== false) {
					//if so,generate a new card
					total_card_num--;
					generate_new_card(Dealer_card_rank[0], Dealer_card_suit[0]);
				}

				//generate the second card for dealer
				generate_new_card(Dealer_card_rank[1], Dealer_card_suit[1]);
				//check the card is different from the existing card
				while (check_the_card(Dealer_card_rank[1], Dealer_card_suit[1])
						== false) {
					//if so,generate a new card
					total_card_num--;
					generate_new_card(Dealer_card_rank[1], Dealer_card_suit[1]);
				}

			}

			//update the screen
			update_the_screen();

			//Sum the points together,consider the J,Q,K
			int k = 0;
			for (k = 0; k <= draw; k++) {
				if (Player_card_rank[k] > 10) {
					player_point += 10;
				} else {
					player_point += Player_card_rank[k];
				}
			}

			//Check whether the player is busted

			if (player_point > 21) {
				player_game_over = true;
				//Ask whether the player wishes to draw for split
				int y = 0;
				for (y = 0; y < split_times; y++) {
					draw_for_split(y);
				}

				//generate the card for the dealer
				game_over = true;
				draw_for_dealer();
				gameover();
				break;

			} else {
				//Check whether split occurs
				if (draw == 1) {
					while ((check_split_occur(Player_card_rank[draw],
							Player_card_rank[0]) == true)
							&& (player_money - bet >= 0) && (split == true)) {

						split_card(Player_card_rank[1], Player_card_suit[1]);
					}
					int n = 0;
					for (n = 0; n < split_times; n++) {
						split = true;
						while ((check_split_occur(Split_card_rank[1][n],
								Split_card_rank[0][n]) == true)
								&& (player_money - bet >= 0) && (split == true)) {
							split_card(Split_card_rank[1][n],
									Split_card_suit[1][n]);
						}
					}
				}

				//Ask whether the player wishes to draw
				char reply;
				cout << "\nDraw? (Y/N):";
				cin >> reply;
				if ((reply == 'Y') || (reply == 'y')) {
					draw++;

				} else {
					update_the_screen();

					//Ask whether the player wishes to draw for split
					player_game_over = true;
					int q = 0;
					for (q = 0; q < split_times; q++) {
						draw_for_split(q);
					}
					game_over = true;
					//generate the card for the dealer
					draw_for_dealer();
					gameover();
					break;

				}
			}
		}

	}
	return 0;
}

int generate_card_rank(void) {
	int rank = 0;
	if ((test_case != 'Y') && (test_case != 'y')) {

		//generate random rank
		rank = rand() % 13 + 1;
	}

	else {
		rank = test_case_rank[total_card_num];
	}

	//store the information in the total card array
	total_card_rank[total_card_num] = rank;
	return rank;
}

char generate_card_suit(void) {
	char suit = ' ';
	char pattern[4] = { 'H', 'D', 'C', 'S' };

	if ((test_case != 'Y') && (test_case != 'y')) {
		//generate random suits
		suit = pattern[rand() % 4];
	} else {
		suit = test_case_suit[total_card_num];
	}
	//store the information in the total card array
	total_card_suit[total_card_num] = suit;
	return suit;
}

void generate_new_card(int &n, char &a) {
	n = generate_card_rank();
	a = generate_card_suit();
	total_card_num++;
}

bool check_the_card(int n, char a) {
	bool result;
//check if the card has existed before
	result = true;
	int i = 0;
	for (i = 0; i < total_card_num - 1; i++) {
		if ((n == total_card_rank[i]) && (a == total_card_suit[i])) {
			result = false;
		}
	}
	return result;
}

void split_card(int &n, char &a) {

//Ask the player whether to split or not
	char answer;
	cout << "\nSplit ?(Y/N):";
	cin >> answer;
//if the player wishes to split

	if ((answer == 'Y') || (answer == 'y')) {

		if (split_times < split_times_max) {

			//transfer the card from player to split player
			Split_card_rank[0][split_times] = n;
			Split_card_suit[0][split_times] = a;

			//generate a new card for the last player
			generate_new_card(n, a);
			//check the card is different from existing card
			while (check_the_card(n, a) == false) {
				total_card_num--;
				generate_new_card(n, a);
			}

			//generate a new card for the split player
			generate_new_card(Split_card_rank[1][split_times],
					Split_card_suit[1][split_times]);

			//check the card is different from existing card

			while (check_the_card(Split_card_rank[1][split_times],
					Split_card_suit[1][split_times]) == false) {
				total_card_num--;
				generate_new_card(Split_card_rank[1][split_times],
						Split_card_suit[1][split_times]);

			}
			splitdraw[split_times] = 1;
			display_split[split_times] = true;
			split_times++;	//increase the split times
			player_money -= bet; //decrease the money player has
		}

	} else {
		split = false;
	}

	update_the_screen();
}

void update_the_screen(void) {
	if (game_over == false) {
		cout << "\nDealer: *  ";
		cout << Dealer_card_rank[1] << Dealer_card_suit[1] << " ";
	} else {
		cout << "\n\nDealer: ";
		int k = 0;
		for (k = 0; k <= dealer_draw; k++) {
			cout << Dealer_card_rank[k] << Dealer_card_suit[k] << " ";
		}
	}
	cout << "\nPlayer: ";

	int i = 0;
	for (i = 0; i <= draw; i++) {
		cout << Player_card_rank[i] << Player_card_suit[i] << " ";
	}
	int j = 0;
	for (j = 0; j < split_times; j++) {

		if (display_split[j] == true) {
			cout << "\nSplit: ";
			int m;
			m = 0;
			for (m = 0; m <= splitdraw[j]; m++) {
				cout << Split_card_rank[m][j] << Split_card_suit[m][j] << " ";
			}
		}
	}

}

bool check_split_occur(int x, int y) {
	bool result;
	result = false;
//check if split occurs
	if (x == y) {
		result = true;
	}
	return result;
}

void draw_for_split(int n) {
	cout << "\nDraw for split? (Y/N): ";
	char answer;
	cin >> answer;
	while (((answer == 'Y') || (answer == 'y')) && (splitdraw[n] < draw_max)) {
		//draw a new card for the split
		splitdraw[n]++;
		generate_new_card(Split_card_rank[splitdraw[n]][n],
				Split_card_suit[splitdraw[n]][n]);

		//check the card is different from existing card
		while (check_the_card(Split_card_rank[splitdraw[n]][n],
				Split_card_suit[splitdraw[n]][n]) == false) {
			total_card_num--;
			//generate a new card
			generate_new_card(Split_card_rank[splitdraw[n]][n],
					Split_card_suit[splitdraw[n]][n]);

		}

		//check whether the player is busted
		split_point[n] = 0;
		int p = 0;
		for (p = 0; p <= splitdraw[n]; p++) {
			if (Split_card_rank[p][n] > 10) {
				split_point[n] += 10;
			} else {
				split_point[n] += Split_card_rank[p][n];
			}
		}
		if (split_point[n] > 21) {
			split_game_over[n] = true;
			update_the_screen();
			break;
		}
		update_the_screen();
		cout << "\nDraw for split? (Y/N): ";
		cin >> answer;
	}
	if ((answer != 'Y') || (answer != 'y')) {
		update_the_screen();
	}
	split_game_over[n] = true;

}

void draw_for_dealer(void) {
	int x = 0;
	for (x = 0; x < 2; x++) {
		if (Dealer_card_rank[x] > 10) {
			dealer_point += 10;
		} else {
			dealer_point += Dealer_card_rank[x];
		}

	}
	//update the card number remaining for each rank

	//the first two cards for the dealer
	various_card_num[Dealer_card_rank[0] - 1]--;
	various_card_num[Dealer_card_rank[1] - 1]--;

	//the first two cards for the player
	various_card_num[Player_card_rank[0] - 1]--;
	various_card_num[Player_card_rank[1] - 1]--;

	//the first two cards for the split player
	int i = 0;
	for (i = 0; i < split_times; i++) {
		various_card_num[Split_card_rank[0][i] - 1]--;
		known_card_num++;
		various_card_num[Split_card_rank[1][i] - 1]--;
		known_card_num++;
	}
	//Calculate the math expectation
	expectation = 0;
	int j = 0;
	for (j = 0; j < 13; j++) {
		if (j < 10) {
			expectation += (j + 1)
					* (double(various_card_num[j]) / (52 - known_card_num));
		} else {
			expectation += 10
					* (double(various_card_num[j]) / (52 - known_card_num));
		}
	}

	while (((dealer_point + expectation) <= 21) && (dealer_draw < draw_max)) {
		dealer_draw++;
		generate_new_card(Dealer_card_rank[dealer_draw],
				Dealer_card_suit[dealer_draw]);

		//check if the card has existed before
		while (check_the_card(Dealer_card_rank[dealer_draw],
				Dealer_card_suit[dealer_draw]) == false) {
			total_card_num--;
			generate_new_card(Dealer_card_rank[dealer_draw],
					Dealer_card_suit[dealer_draw]);
		}

		various_card_num[Dealer_card_rank[dealer_draw] - 1]--;
		known_card_num++;

		//check the sum
		if (Dealer_card_rank[dealer_draw] > 10) {
			dealer_point += 10;
		} else {
			dealer_point += Dealer_card_rank[dealer_draw];
		}
		//calculate the math expectation again
		expectation = 0;
		int j = 0;
		for (j = 0; j < 13; j++) {
			if (j < 10) {
				expectation += (j + 1)
						* (double(various_card_num[j]) / (52 - known_card_num));
			} else {
				expectation += 10
						* (double(various_card_num[j]) / (52 - known_card_num));
			}
		}
	}
	update_the_screen();
}

void gameover(void) {

	/*calculate the point */
	//set variables to store how many "Ace" everyone gets.
	int player_A = 0;
	int dealer_A = 0;
	int split_A[3] = { 0, 0, 0 };

	//set variables to check whether the first two cards of player sum up to 21

	//calculate the point for player
	int i = 0;
	for (i = 0; i <= draw; i++) {
		if (Player_card_rank[i] > 10) {
			final_player_point += 10;
		} else {
			if (Player_card_rank[i] == 1) {
				player_A++;
			}
			final_player_point += Player_card_rank[i];
		}
	}
	//Smart calculate the Ace value
	if (final_player_point < 21) {
		final_player_point = calculate_Ace(player_A, final_player_point);

	}

	//calculate the point for dealer
	int j = 0;
	for (j = 0; j <= dealer_draw; j++) {
		if (Dealer_card_rank[j] > 10) {
			final_dealer_point += 10;
		} else {
			if (Dealer_card_rank[j] == 1) {
				dealer_A++;
			}
			final_dealer_point += Dealer_card_rank[j];
		}
	}
	//Smart calculate the Ace value
	if (final_dealer_point < 21) {
		final_dealer_point = calculate_Ace(dealer_A, final_dealer_point);

	}

	int p = 0;
	for (p = 0; p < split_times; p++) {
		int q = 0;
		for (q = 0; q <= splitdraw[p]; q++) {
			if (Split_card_rank[q][p] > 10) {
				final_split_point[p] += 10;
			} else {
				if (Split_card_rank[q][p] == 1) {
					split_A[p]++;
				}
				final_split_point[p] += Split_card_rank[q][p];
			}

		}
		//Smart calculate the Ace value
		if (final_split_point[p] < 21) {
			final_split_point[p] = calculate_Ace(split_A[p],
					final_split_point[p]);

		}
	}
	//display all the points
	cout << "\nDealer " << final_dealer_point << " points, Player "
			<< final_player_point << " points,";

	int k = 0;
	for (k = 0; k < split_times; k++) {
		cout << "and " << final_split_point[k] << " points ";
	}

	//decide who wins

	if (final_dealer_point > 21) {
		//check whether player is busted
		if (final_player_point > 21) {
			cout << "\nTie!";
			player_money += bet;
		} else {
			cout << "\nPlayer wins!";
			//player get money back
			if ((draw == 1) && (final_player_point == 21)) {
				player_money += 1.5 * bet;
			} else {
				player_money += (bet * 2);
			}
		}
		//check whether split is busted
		int m = 0;
		for (m = 0; m < split_times; m++) {
			if (final_split_point[m] > 21) {
				cout << "\nTie!";
				player_money += bet;
			} else {
				cout << "\nSplit wins!";
				//player get  money back
				if ((splitdraw[m] == 1) && (final_split_point[m] == 21)) {
					player_money += 1.5 * bet;
				} else {
					player_money += (bet * 2);
				}
			}
		}
	} else {
		if ((final_player_point > 21)
				|| (final_player_point < final_dealer_point)) {
			cout << "\nDealer wins!";

		} else if ((final_dealer_point < final_player_point)
				&& (final_player_point <= 21)) {
			if ((draw == 1) && (final_player_point == 21)) {
				player_money += 1.5 * bet;
			} else {
				player_money += (bet * 2);
			}
			cout << "\nPlayer wins!";

		} else if (final_dealer_point == final_player_point) {
			cout << "\nTie!";
			player_money += bet;
		}
		//check the split
		int n = 0;
		for (n = 0; n < split_times; n++) {
			if ((final_split_point[n] > 21)
					|| (final_split_point[n] < final_dealer_point)) {
				cout << "\nDealer wins!";

			} else if ((final_dealer_point < final_split_point[n])
					&& (final_split_point[n] <= 21)) {
				cout << "\nSplit wins!";
				if ((splitdraw[n] == 1) && (final_split_point[n] == 21)) {
					player_money += 1.5 * bet;
				} else {
					player_money += (bet * 2);
				}

			} else if (final_dealer_point == final_split_point[n]) {
				cout << "\nTie!";
				player_money += bet;
			}
		}
	}
	//Ask the player if he wants to play again
	cout << "\nAgain? (Y/N):";
	char response;
	cin >> response;
	if ((response == 'Y') || (response == 'y')) {
		//reset some variables
		game_over = false;
		player_game_over = false;
		split = true;
		bet = 0;

		split_times = 0;
		draw = 1; //count the times for draw
		dealer_draw = 1; //count the times for dealer

		//calculate the points
		dealer_point = 0;
		player_point = 0;

		//calculate the final points
		final_dealer_point = 0;
		final_player_point = 0;
		total_card_num = 0;
		int x = 0;
		for (x = 0; x < 3; x++) {
			split_game_over[x] = false;
			display_split[x] = false;
			splitdraw[x] = 0;
			split_point[x] = 0;
			final_split_point[x] = 0;

		}
		int y = 0;
		for (y = 0; y < 13; y++) {
			various_card_num[y] = 4;

		}
		known_card_num = 4;
		expectation = 0;

	}
}

int calculate_Ace(int a, int b) {
//calculate Ace point and return final point
	int i = 0;
	for (i = 0; i < a; i++) {
		if (b + 10 <= 21) {
			b += 10;
		}
	}
	return b;
}

