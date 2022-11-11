//
// Number collection game with dynamic arrays
// David J Tinley
// 11/11/2022
//

#include "collection.hpp"
#include "testCollection_funcs.cpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

	int size = 5;  // setting collection array size
	double* a = new double[size]; // allocating dynamic array

	// initializing array
	a[0] = 0.;
	a[1] = 10.;
	a[2] = 20.;
	a[3] = 30.;
	a[4] = 40.;

	cout << "Here is your initial collection: ";
	output(a, size); // printing out the array
	cout << endl;

	cout << "Here is your initial collection value: " << value(a, size) << endl;

    char user_operation_selection; // 'q', 'a', or 'r'

    do { // game loop
    cout << "Enter a operation to perform" << endl;
    cout << "'q' to quit, 'a' to add a number to the collection, or 'r' to remove a number from the collection" << endl;
    cin >> user_operation_selection;

    switch (user_operation_selection) {
        case 'q': // quit
            break;;

        case 'a': // add a number to the collection
            int added_number;
            cout << "Enter a number to add to the array: ";
            cin >> added_number;
            addNumber(a, added_number, size);
            cout << "Your collection now ";
            output(a, size);
            cout << endl;
            cout << "Your collection value now: ";
            cout << value(a, size) << endl;
            break;

        case 'r': // remove a number from the collection
            int removed_number;
            cout << "Enter a number to remove: ";
            cin >> removed_number;
            removeNumber(a, removed_number, size);
            output(a, size);
            cout << endl;
            cout << "Your collection value now: ";
            cout << value(a, size) << endl;
            break;
    }
    } while (user_operation_selection != 'q');

	delete[] a; // deallocating the array
}