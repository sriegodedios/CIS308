/**********************************************
 * Name: Shane Riegodedios
 *
 * Date: 04/27/2017
 *
 * Assignment: Project 6: Sets
 ************************************************
 * Description: This program lets the user enter 
 *              two vectors abd stires them in 
 *              resizeable arrays. The program 
 *              will automatically sort and not 
 *              include duplicates. The user can 
 *              has the option to intersect the vectors
 *              which matches two of the same sets together
 *              or unionize which unions the sets together if 
 *              they have diffect numbers.
 ************************************************/

#include <stdio.h>
#include <iostream>
#include <string>
//#include <stdlib.h>
#include "set.cpp"

using namespace std;

bool checkForDuplicates(char value, char *ar, int numVal);

/************************************************
 * Method Name: main
 *
 * Input: N/A
 *
 * Output: N/A
 *
 * Description: This method excutes the program.
 ************************************************/
int main() {
	char input1[50];
	char input2[50];
	char * d1;
	char * d2;
	bool val;
	Set<char> * s1 = new Set<char>(5);
	Set<char> * s2 = new Set<char>(5);

	//### Input 1 #####
	cout << "Input vector 1 (like num1, num2, ..., numN): ";

	cin >> input1;
	d1 = strtok(input1, " ,()");

	//Needed to check for duplicates
	while (d1 != NULL)
	{
		val = checkForDuplicates(*d1, input1, 50);
		if (val != true)
		{
			s1->insert(*d1);
		}
		s1->insert(*d1);
		d1 = strtok(NULL, " ,()");
	}



	cout << "Input vector 2 (like num1, num2, ..., numN): ";
	cin >> input2;
	//### Input 2 #####
	d2 = strtok(input2, " ,()");
	//Needed to check for duplicates
	while (d2 != NULL)
	{
		val = checkForDuplicates(*d2, input2, 50);
		if (val != true)
		{
			s2->insert(*d2);
		}
		s2->insert(*d2);
		d2 = strtok(NULL, " ,()");
	}

	cout << "The sorted sets are:" << endl;
	cout << endl;
	s1->Print();
	cout << endl;
	s2->Print();
	cout << endl;


	char option;
	cout << "Enter (i)nsert or (u)nion: ";
	cin >> option;

	Set<char> * temp = new Set<char>(5);
	
	switch (option) {
	case 'i':
		
		
		temp = s1->intersection(s2);

		temp->Print();

		break;

	case 'u':

		temp = s1->unionize(s2);

		temp->Print();

		break;
	}





	system("PAUSE");

	return 1;
}
/************************************************
 * Method Name: checkForDuplicates
 *
 * Input: char of the value, a char of a pointer, and an int of the size
 *
 * Output: Returns a bool.
 *
 * Description: The method checks for duplicates and returns a bool based on that.
 ************************************************/
bool checkForDuplicates(char value, char *ar, int numVal) {
	int i;
	for (i = 0; i < numVal; i++) {
		if (ar[i] == value) {
			return true;
		}
		return false;
	}

}


