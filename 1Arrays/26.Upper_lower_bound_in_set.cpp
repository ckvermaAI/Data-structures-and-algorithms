// https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-for-ordered-set-in-c/

// C++ program to implement the
// lower_bound() and upper_bound()
// using Ordered Set

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Ordered Set Tree
typedef tree<int, null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update>
	ordered_set;

ordered_set set1;

// Function that returns the lower bound
// of the element
int lower_bound(int x)
{
	// Finding the position of the element
	int pos = set1.order_of_key(x);

	// If the element is not present in the set
	if (pos == set1.size())
	{
		return -1;
	}

	// Finding the element at the position
	else
	{
		int element = *(set1.find_by_order(pos));

		return element;
	}
}

// Function that returns the upper bound
// of the element
int upper_bound(int x)
{
	// Finding the position of the element
	int pos = set1.order_of_key(x + 1);

	// If the element is not present
	if (pos == set1.size())
	{
		return -1;
	}

	// Finding the element at the position
	else
	{
		int element = *(set1.find_by_order(pos));

		return element;
	}
}

// Function to print Upper
// and Lower bound of K
// in Ordered Set
void printBound(int K)
{

	cout << "Lower Bound of " << K << ": " << lower_bound(K)
		<< endl;
	cout << "Upper Bound of " << K << ": " << upper_bound(K)
		<< endl;
}

// Driver's Code
int main()
{
	set1.insert(10);
	set1.insert(20);
	set1.insert(30);
	set1.insert(40);
	set1.insert(50);

	int K = 30;
	printBound(K);

	K = 60;
	printBound(K);

	return 0;
}
