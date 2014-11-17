#include "lex_permutation.h"
#include "ins_permutation.h"
#include "des_permutation.h"
#include "exc_permutation.h"

#include <iostream>

using std::cout;
using std::endl;

template <class T> void get_full_permutation(bool (*next_permutation)(T, T), T first, T last);

int main(int argc, char *argv[]){
    int test[] = {1, 2, 3};
    switch(argv[1][0]){
        case 'l':
            get_full_permutation(lex::next_permutation, &test, &test + 3);
            break;
        case 'i':
            break;
        case 'd':
            break;
        case 'e':
            break;
        default:
            cout << "first param error" << endl;
    }
    return 0;
}

template <class T> void get_full_permutation(bool (*next_permutation)(T, T), T first, T last){
    cout << next_permutation(first, last) << endl;
}
