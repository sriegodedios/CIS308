/**********************************************
 * Name: Shane Riegodedios
 *
 * Date: 04/27/2017
 *
 * Assignment: Project 6: Sets
 *
 * set.cpp
 ***********************************************/


#include <iostream>

using namespace std;

template<class T>
class Set {
private:
	T *nums;
	T pos;
	int max;


public:
	Set(int num);
	~Set();
	void insert(T elem);
	void Print(void);
	Set<T> * intersection(Set<T> * s);
	Set<T> * unionize(Set<T> * s);
};

/************************************************
 * Method Name: Set
 *
 * Input: an int of the max size.
 *
 * Output: N/A
 *
 * Description: This method is the constructor for the 
 *              resisizable array. We need a number to initialize 
 *              the size of the array.
 ************************************************/
template <class T>
Set<T>::Set(int max) {
	nums = new T[max];
	pos = 0;
	this->max = max;
}

/************************************************
 * Method Name: ~Set
 *
 * Input: N/A
 *
 * Output: N/A
 *
 * Description: This method deconstructs the class.
 ************************************************/
template <class T>
Set<T>::~Set()
{
	delete[] nums;
}



/************************************************
 * Method Name: insert
 *
 * Input: a T of an element (any type)
 *
 * Output: N/A
 *
 * Description: This method inserts the type of T 
 *              into the array. It also checks for duplicates 
 *              and sorts the array from least to greatest.
 ************************************************/
template <class T>
void Set<T>::insert(T elem) {

	int i ;
	int j;
	int temp = 0;
    
    //Checks for duplicates
	for (int t = 0; t < pos; t++) {

		if (elem == this->nums[t]) {
            //Does not add the element to the array.
			return;
		}
	}

    //Inserts the actual value

	if (pos >= max)
	{
		int *temp = new int[max];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = nums[i];
		}
		max *= 2;
		nums = new T[max];
		for (int i = 0; i < pos; i++)
		{
			nums[i] = temp[i];
		}
	}
	for (i = 0; i < pos; i++) {
		if (nums[i] == elem) return;
	}
	nums[pos++] = elem;


	// The sorting algorithm (bubble sort)


	if (pos > 1)
	{
		for (int i = 0; i < pos; i++) {
			for (int j = 1; j < pos - i; j++) {
				if (this->nums[j - 1] > this->nums[j]) {
					temp = this->nums[j - 1];
					this->nums[j - 1] = nums[j];
					this->nums[j] = temp;
				}
			}
		}


	}
}

template <class T>
void Set<T>::Print() {
	for (int i = 0; i < this->pos; i++) {
		cout << this->nums[i] << " ";
	}
	cout << endl;
}


/************************************************
 * Method Name: intersect
 *
 * Input: A pointer of a set.
 *
 * Output: A pointer of a set.
 *
 * Description: This method checks the values of two sets
 *              if any of them are the same. It adds the sa
 ************************************************/
template <class T>
Set<T> * Set<T>::intersection(Set<T> * s) {
	Set<T> * s1 = new Set<T>(5);

	for (int i = 0; i < this->pos; i++) {
		for(int j = 0; j < s->pos; j++) {
			
			if (s->nums[j] == this->nums[i]) {
				s1->insert(s->nums[j]);
			}

		}
	}

	return s1;

}


/************************************************
 * Method Name: unionize
 *
 * Input: A pointer of a set.
 *
 * Output: A pointer of a set.
 *
 * Description: This method unionizes two sets.
 *              It will combine the two sets of 
 *              different values.
 ************************************************/
template <class T>
Set<T> * Set<T>:: unionize(Set<T> * s) {
	Set<T> * s1 = this;
	
	for (int i = 0; i < this->pos; i++) {
		s1->insert(this->nums[i]);
	}
	
	for (int y = 0; y < s->pos; y++) {
		s1->insert(s->nums[y]);
	}


	return s1;

}
