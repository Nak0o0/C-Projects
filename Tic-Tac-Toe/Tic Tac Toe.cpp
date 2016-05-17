/*
Tic Tac Toe Assignment for Department of Automation Engineering - February 2016
AI programmed using MiniMax and Exhaustive Tree Search algorithms.
Made by: Eleni K.
Contact: auto44718@stef.teipir.gr
*/

#include <stdio.h> // needed for getchar()
#include <iostream> //primarly needed for cout / cin

using namespace std;
// FUNCTIONS ARE PLACED HERE *****
void main_menu() //function to display main menu.
{
	cout <<"\t\t\t\t ________________" << endl;
	cout <<"\t\t\t\t|    MAIN MENU   |" << endl;
	cout <<"\t\t\t\t| 1 - Start Game |" << endl;
	cout <<"\t\t\t\t| 2 - About      |" << endl;
	cout <<"\t\t\t\t| 3 - Exit       |" << endl;
	cout <<"\t\t\t\t ----------------" << endl;
	cout <<"\t Please choose menu item: ";
} //end of main_menu() function

char place_mark(int i) // These are Marks which are placed on the board.
{
	switch (i)
	{
        case -1:           //in case of -1 the field on the board is marked with X
            return 'X';
        case 0:           //in case of 0 the place field on the board appears empty until a mark is placed on that field.
            return ' ';
        case 1:           //in case of 1 the field on the board is marked with O
            return 'O';
	}
} // end of place_mark();

void draw(int b[9]) //Function to draw the board. b[0-8] array holds the current mark ( X or O or ' ' ).
{
	cout <<"\t\t\t\t        |     |     "<< endl; // \t is used to add TAB space and center the board position.
	cout << "\t\t\t\t     " << place_mark(b[0]) << "  |  " << place_mark(b[1]) << "  |  " <<place_mark(b[2]) << endl;
	cout <<"\t\t\t\t   -----+-----+-----" << endl;
	cout <<"\t\t\t\t        |     |     "<< endl;
	cout << "\t\t\t\t     " << place_mark(b[3]) << "  |  " << place_mark(b[4]) << "  |  " <<place_mark(b[5]) << endl;
	cout <<"\t\t\t\t   -----+-----+-----" << endl;
	cout <<"\t\t\t\t        |     |    "<< endl;
	cout << "\t\t\t\t     " << place_mark(b[6]) << "  |  " << place_mark(b[7]) << "  |  " <<place_mark(b[8]) << endl;
} //end of draw() function

int win(const int game_board[9]) //function to determine if a player has won.
{
	unsigned wins[8][3] = // An array holding all possible combinations of win states. Horizontally, Vertically and Diagonally. Numbers indicate field positions on the board.
	{   //Horizontal "--"
        { 0,1,2 },
        { 3,4,5 },
        { 6,7,8 },
        //Vertical   "|"
        { 0,3,6 },
        { 1,4,7 },
        { 2,5,8 },
        //Diagonal   "\"
        { 0,4,8 },
        { 2,4,6 }
    };

	for (int i = 0; i < 8; ++i)
    {  // for loop used to loop through wins[][] to determine end game state.
		if (game_board[wins[i][0]] != 0 &&
			game_board[wins[i][0]] == game_board[wins[i][1]] &&
			game_board[wins[i][0]] == game_board[wins[i][2]])
        {
            return game_board[wins[i][2]];
        }
	}
	return 0;
} //end of win() function

int minimax(int game_board[9], int player)  // MiniMax algorithm (AI's logic).
{
	//How is the position like for player (their turn) on board?
	int winner = win(game_board);
	if (winner != 0) return winner*player;
	int move = -1;
	int score = -2; //Losing moves have lowest score and if possible are skipped.
	for (int i = 0; i < 9; ++i) { //Loop for all the moves,
		if (game_board[i] == 0) //If legal,
        {
            game_board[i] = player; //Try the move
            int thisScore = -minimax(game_board, player*-1);
            if (thisScore > score)
            {
                score = thisScore;
                move = i;
            } //Pick the one that's worst for the opponent
            game_board[i] = 0;//Reset board after try
		}
	}
	if (move == -1) return 0;
	return score;
} // end of minimax() function

void computer_move(int game_board[9]) // function to make AI make a move.
{
	int move = -1;
	int score = -2;
	for (int i = 0; i < 9; ++i)
	{
		if (game_board[i] == 0) // if the field on the board is empty
        {
			game_board[i] = 1; // make your move
			int tempScore = -minimax(game_board, -1);  // Assign minimax based calculation to temporary score variable
			game_board[i] = 0;  // Reset the field
			if (tempScore > score)  // Check if the temporary score is bigger than initial score.
            {
				score = tempScore;  // True, assign the value of temporary score to initial score.
				move = i; // Assign the value of the board position to the move variable.
			}
		}
	}
	//returns a score based on minimax tree at a given node.
	game_board[move] = 1; // Places the computer's mark upon the board.
} //end of computer_move() function

void player_move(int game_board[9]) //function allowing player to make a move.
{
	int move = 0;
	do {
	start: // beginning
		cout << "\n Choose your move using digits ([0..8]): "; // Ask player for input
		cin >> move; // Take the input from player
		if (game_board[move] != 0) { // If the field you try to move into is different than 0 ( means it's occupied),
			cout << "You can't move here, its Already Occupied !"; // Inform player about spot being occupied,
			goto start; // Jump back to the beginning. Note ** Taken from the teacher's lessons, the goto is considered a bad practice. However goto used for this particular problem is quite efficient.
		}
		cout << "\n";
	}  while ((move >= 9 || move < 0 )&& (game_board[move] == 0));
	game_board[move] = -1;
}// end of player_move() function

// END OF FUNCTIONS *****
int main()
{
	cout << "--------------------------------------------------------------------------------";
	cout << "\t\t\t TIC TAC TOE by ELENI K. " << endl;                                          // This message is displayed at the top of the program at the launch.
	cout << "\t\t\t Tmima Automatismou 2015-2016 " << endl;
	cout << "\t\t\t Programatismos I Workshop " << endl;
	cout << "--------------------------------------------------------------------------------\n" << endl;
	int game_board[9] = { 0,0,0,0,0,0,0,0,0 }; // Initialize the board array and fill it with zeros. Computer squares are stored as 1, player squares as -1. Used to store marks on specific board positions.
	int choice; // Choice variable used to store choice of menu item. Used as case in switch menu.
	int game_loop = true; // Variable used in while loop. It is initialized as true to allow the main game loop to run.
	int player = 0; // Player variable. Is 0, because at this moment of code "who goes first" is not yet determined.
	main_menu(); // Calling main_menu function to display the main menu
    	cin >> choice; // Take input from user (menu options choice)
	while (game_loop != false) // Main game loop. Repeat until game_loop is not false, (is false when you choose option 3).
	{
		switch (choice) //switch / case depending on user choice in menu.
		{
            case 1: // Do that if user chose option 1
                cout << "\n" << endl;
                cout << "\t\t\t Computer: O, You: X " << endl;
                cout << "\t\t\t Who should have first move ? " << endl;
                cout << "\t\t\t 1 - Player \n" "\t\t\t 2 - Computer " << endl;
                cout << "\t\t Choose: ";
                cin >> player; // Take input from the user to determine who goes first
                cout << "\n";

                unsigned turn; // turn variable, used to store number of turns passed.
                for (turn = 0; turn < 9 && win(game_board) == 0; ++turn) //for loop to switch turns starting at 0 and incrementing up to 8. 8 is max possible amount of turns before all game fields are taken. Thus ending the game.
                {
                    if ((turn + player) % 2 == 0) // if turn added to player can be divided by 2 without a remainder, then it is computer's turn. % is called Modulus Operator.
                    {
                    computer_move(game_board); // computer player makes it's move.
                    }
                    else // if the above condition is false,
                    {
                        draw(game_board);// draw the board,
                        player_move(game_board); // player makes it's move.
                    }
                } //end of for loop
                switch (win(game_board)) { // switch / case to display end - game state message.
                case 0:
                    draw(game_board); // draw board is called here in order to update the game board last time before endgame state message is displayed. This prevents empty fields at the end of the game.
                    cout << "\n\t\t\t\t =================" << endl;
                    cout << "\t\t\t\t |  !!! DRAW !!! | " << endl;
                    cout << "\t\t\t\t =================\n" << endl;
                    game_loop = false; // Sets the main game loop to false. Therefore the condition in the while loop ( while =!false) evaluates to true and the game is terminated.
                    break;
                case 1:
                    draw(game_board);
                    cout << "\n\t\t\t\t =================" << endl;
                    cout << "\t\t\t\t |!!!  DEFEAT !!!| " << endl;
                    cout << "\t\t\t\t =================\n" << endl;
                    game_loop = false;
                    break;
                case -1:
                    draw(game_board);
                    cout << "\n\t\t\t\t =================" << endl;
                    cout << "\t\t\t\t |!!! VICTORY !!!| " << endl;      // Never during the testing was I able to win with computer. I'm fairly confident player will never see this message.
                    cout << "\t\t\t\t |!!! ~Impossible~ !!!| " << endl;
                    cout << "\n\t\t\t\t =================" << endl;
                    game_loop = false;
                    break;
                }
                break; // End of menu 1 case
            case 2: // Do that if user chose option 2
                cout << "\n" << endl;
                cout << "--------------------------------------------------------------------------------";
                cout << "\t\t\t\t      Rules:" << endl;
                cout << "The object of Tic Tac Toe is to get three in a row." << endl;
                cout << "You play on a three by three game board." << endl;
                cout << "The first player is known as X and the second is O." << endl;
                cout << "Players take turns placing Xs and Os on the game board until either opponent has three in a row or all nine squares are filled." << endl;
                cout << "In the event that no one has three in a row, the game ends in draw." << endl;
                cout << "\n \t\t\t\t    Instructions:\n" << endl;
                cout << "The game board is represented in an array. The fields are marked from 0 to 8." << endl;
                cout << "Below is a visual representation of the board and corresponding fields." << endl;
                cout << "\t\t\t\t        |     |     " << endl;
                cout << "\t\t\t\t     0  |  1  |  2  " << endl;
                cout << "\t\t\t\t   -----+-----+-----" << endl;
                cout << "\t\t\t\t        |     |     " << endl;
                cout << "\t\t\t\t     3  |  4  |  5  " << endl;
                cout << "\t\t\t\t   -----+-----+-----" << endl;
                cout << "\t\t\t\t        |     |    " << endl;
                cout << "\t\t\t\t     6  |  7  |  8  " << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                cout << "\t Please choose menu item: ";
                cin >> choice;
                break; // End of menu 2 case
            case 3: // Do that if user chose option 3
                cout << "\n" << endl;
                game_loop = false;
                break; // End of menu 3 case
            default: // Default case if user chooses menu item outside of range of 1 - 3
                cout << "\n" << endl;
                cout << "Invalid choice. " << endl;
                cout << "Try again." << endl; // Ask for input again
                cin >> choice; // Take input from user.
		} // end of switch
    } // end of while loop
    cout << "Thank you for using my program . . . Bye bye." << endl; // Goodbye message displayed at the end of the program.
    getchar(); // Used to ask user to press a button before terminating the program. It prevents situation where command window flashes and the program closes instantly.
    return 0;
} // End of the main. End of the program.


