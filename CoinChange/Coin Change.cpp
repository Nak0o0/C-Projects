#include <iostream>
using namespace std;

// Returns the count of ways we can sum S[0...m-1] coins to get sum n
int count( int S[], int m, int n )
{
// If n is 0 then there is 1 solution (do not include any coin)
	if (n == 0)
		return 1;

	// If n is less than 0 then no solution exists
	if (n < 0)
		return 0;
// If there are no coins and n is greater than 0, then no solution exists
	if (m <=0 && n >= 1)
		return 0;

// count is sum of solutions (i) including S[m-1] (ii) excluding //S[m-1]
	return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

/* The program calculates the total number of unique combinations, where place *is not important, that can be done using the numbers in the set *{1,2,5,10,20,50,100,200} so that  the sum of the used numbers amounts to 300
*/

int main()
{
  
	cout << "Lamvanontas ypopsh 1 apeiro arithmo kermatwn twn akolouthwn onomastikwn aksiwn:"<< endl;
	cout << "(1, 2, 5, 10, 20, 50, 100, 200) kai timwn, gia na kanei thn allagh apo = 300." << endl;
	cout << "Me posous diaforetikous syndiasmoys boroume na kanoume thn allagh? \n\n" << endl;
	int n = 300; //Total sum of coins.
	int arr0[] = {1, 2, 5, 10, 20, 50, 100, 200};
	//Calculate the number of elements arr0 has.
	int m0 = sizeof(arr0)/sizeof(arr0[0]);

	//Display on screen total solution for 300 sum using all coins.
	cout << "Total solutions= " << count(arr0, m0, 300) << "\n";

	//Display total solutions for 300 sum with 1s in them.
	cout << "Total solutions with 1s= " << count(arr0, m0, 299)  << "\n";

	//Display total solutions for 300 sum with 2s in them.
	cout << "Total solutions with 2s= " << count(arr0, m0, 298)  << "\n";

	//Display total solutions for 300 sum with 5s in them.
	cout << "Total solutions with 5s= " << count(arr0, m0, 295)  << "\n";

	//Display total solutions for 300 sum with 10s in them.
	cout << "Total solutions with 10s= " << count(arr0, m0, 290)  << "\n";

	//Display total solutions for 300 sum with 20s in them.
	cout << "Total solutions with 20s= " << count(arr0, m0, 280)  << "\n";

	//Display total solutions for 300 sum with 50s in them.
	cout << "Total solutions with 50s= " << count(arr0, m0, 250)  << "\n";

	//Display total solutions for 300 sum with 100s in them.
	cout << "Total solutions with 100s= " << count(arr0, m0, 200)  << "\n";

	//Display total solutions for 300 sum with 200s in them.
	cout << "Total solutions with 200s= " << count(arr0, m0, 100)  << "\n";
	return 0;
}
