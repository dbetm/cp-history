// C++ program to find machine epsilon
#include <iostream>
#include <cfloat>
using namespace std;

// Function for Machine Epsilon with an
// initial value provided as EPS.
void machineEpsilon(float EPS) {
	// taking a floating type variable
	float prev_epsilon;

	// run until condition satisfy
	while ((1+EPS) != 1) {
		// copying value of epsilon into previous epsilon
		prev_epsilon = EPS;
		// dividing epsilon by 2
		EPS /=2;
	}

	// print output of the program
	cout << "Machine Epsilon is : " << prev_epsilon << endl;
}

// Driver Code
int main() {
	// calling function which calculate machine epsilon
	// with initial value provided as 0.5
	machineEpsilon(0.5);
    // 1.19209e-07
	return 0;
}
