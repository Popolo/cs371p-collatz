// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <cmath>

#include "Collatz.h"

using namespace std;

/** Converts the given string into a pair of numbers.
* @param s The string to convert, must be of the form "# #".
*/
pair<long, long> collatz_read (const string& s) {
    istringstream sin(s);
    long i;
    long j;
    sin >> i >> j;
    return make_pair(i, j);}


/** Finds the greatest value of the Collatz algorithm for the range between two given numbers.
* @param i, j The max and min of the range, order insensitive.
*/
int collatz_eval (long i, long j) {
    long maxvalue = 1;
    long max = fmax(i,j);
    long min = fmin(i,j);
    long cache [1000001];
    for (long i = 0; i < 1000001; i++){
        cache[i] = 0;
    }
    for(long c = min; c <= max; c++){
        long value = 1;
        long current = c;
        while(current != 1){
            if ( current > 1000001 || cache[current - 1] == 0){
                if(0 == current%2){
                    current /= 2;
                    value++;
                }else{
                    current = current * 3 + 1;
                    value++;
                }
            }else{
                value = cache[current - 1] + value;
                break;
            }
        }
        if(cache[c - 1] != 0){
            cache[c - 1] = value;
        }       
        if(value > maxvalue)
            maxvalue = value;
    }
    return maxvalue;
}

/** Prints an output formatted for Sphere.
* @param w The desired output location
* @param i, j The two inputs.
* @param v The output for the inputs.
*/

void collatz_print (ostream& w, long i, long j, long v) {
    w << i << " " << j << " " << v << endl;}

/** Inputs, solves, and outputs the solutions for the Collatz problem.
* @param r The input location.
* @param w The output location.
*/
void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<long, long> p = collatz_read(s);
        const long            i = p.first;
        const long            j = p.second;
        const long            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}