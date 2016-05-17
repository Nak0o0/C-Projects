#include <iostream>
using namespace std;

int play_again(){
    int again;
		cout<< "You want to play again (1 for yes, 2 for no) ?"<<endl;
		cin >> again;

		if (again == 1) {
            return true;
		}
		else {
            cout << "Bye Bye !";
            return false;
		}

}
int main(int argc, char** argv) {
	int answer1;
	int answer2;


	int loop_running=true;


	while(loop_running != false)
	{
	cout<<"Choose one of the three options:"<<endl;
	cout<<"1-Rock\n2-Paper\n3-Scissors "<<endl;
	cout<<"First Player: ";
	cin>>answer1;
	cout<<"Second Player: ";
	cin>>answer2;

		if (answer1 == 1 && answer2 == 1 ||answer1 == 2 && answer2 == 2 ||answer1 == 3 && answer2 == 3)
		{
		cout<<"Its draw"<<endl;
		loop_running = play_again();
		}
		else if(answer1 == 1 && answer2 == 2 ||answer1 == 2 && answer2 == 3||answer1 == 3 && answer2 == 1 )
		{
		cout<<"Player 1 lost! :("<<endl;
		cout<<"Player 2 wins! :D"<<endl;
		loop_running = play_again();
		}
		else if(answer1 == 2 && answer2 == 1 ||answer1 == 3 && answer2 == 2||answer1 == 1 && answer2 == 2)
		{
		cout<<"Player 2 lost! :("<<endl;
		cout<<"Player 1 wins! :D"<<endl;
		loop_running = play_again();
		}



}
	return 0;
}







