// -------
// defines
// -------

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

// --------
// includes
// --------

#include <iostream> // cin, cout
#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <cmath>

using namespace std;

// ------------
// collatz_read
// ------------

pair<long, long> collatz_read (const string& s) {
    istringstream sin(s);
    long i;
    long j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (long i, long j) {
    long maxvalue = 1;
    long max = fmax(i,j);
    long min = fmin(i,j);
    long cache [1000000];
    
    if(i < j){}
    for(int c = min; c <= max; c++){
        long value = 1;
        long current = c;
        while(current != 1){
            if (cache[current] == 0){
                if(0 == current%2){
                    current /= 2;
                    value++;
                }else{
                    current = current * 3 + 1;
                    value++;
                }
            }else{
                value = cache[current] + value;
                break;
            }
        }
        cache[c] = value;       
        if(value > maxvalue)
            maxvalue = value;
    }
    return maxvalue;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, long i, long j, long v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<long, long> p = collatz_read(s);
        const long            i = p.first;
        const long            j = p.second;
        const long            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

// ----
// main
// ----

int main () {
    collatz_solve(cin, cout);
    return 0;}