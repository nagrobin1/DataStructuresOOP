
// This program is the test file for the sequence class


#include <iostream>    /* cout, cin */
#include <fstream>	   /* ifstream */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "sequence.h"

using namespace std;

int main()
{
	sequence s;
	ifstream input;	
	int nextInt;

	input.open("inputs.txt");

	cout << "Trying to insert the first 50 elements ..." << endl;

	for (int i = 0; i < 50; i++)
	{
		input >> nextInt;
		s.insert(nextInt);
	}
	
	cout << "16'th element in the sequence is: " << s.get(15) << endl;

	cout << "Trying to insert the next 25 element in arbitrary locations ... " << endl;
	for (int i = 0; i < 25; i++)
	{
		input >> nextInt;
		s.insertAt(rand() % s.size(), nextInt);
	}
	
	cout << "Trying to erase the first occurence of number 9 ... " << endl;

	s.eraseFirstOccurence(s.get(9));

	cout << "Trying to erase the third occurence of number 8 ... " << endl;

	s.eraseOccurence(3, 8);

	cout << "Trying to erase 8'th element ... " << endl;

	s.eraseElementAt(7);

	cout << "Trying to remove multiple elements ... ";

	for (int i = 0; i < 5; i++)
	{
		s.eraseElementAt(i);
		s.eraseElementAt(2 * i);
		s.eraseElementAt(5 * i);
		s.eraseElementAt(10 * i);
	}

	cout << "Trying to insert more elements ... " << endl;

	for (int i = 0; i < 10; i++)
	{
		input >> nextInt;
		s.insert(nextInt);
		input >> nextInt;
		s.insertAt(i * 5, nextInt);
	}
	
	cout << "Trying to find number 5 gives me a " << s.find(5) << " result" << endl;

	cout << "Trying to print the sequence ... " << endl;

	// Example output: 7, 8, 4, 5, 6, 1, 8, 7, 5, 6, 7, 2, 9, 0, 1, 6
	cout << s;

	return 0;
}