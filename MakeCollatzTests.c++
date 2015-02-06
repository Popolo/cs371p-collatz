// --------
// includes
// --------

#include <iostream> // cin, cout
#include <fstream>

#include "Collatz.h"

/** Number of new tests to make.
*
*/
const int tests_to_make = 100;

/** Creates new tests, according to tests_to_make.
*
*/
int main () {
    using namespace std;
    std::ifstream in("Collatz.in.txt");
    std::ofstream out("Collatz.out.txt");
    std::ofstream inout("Collatz.in.txt");
    for(int i = 0; i < tests_to_make; i++){
    	long v1 = rand() % 1000000 + 1;
    	long v2 = rand() % 1000000 + 1;
    	inout << v1 << " " << v2 << endl;
    }
    collatz_solve(in, out);
    return 0;}