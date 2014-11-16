#include "lex_permutation.h"
#include "ins_permutation.h"
#include "des_permutation.h"
#include "exc_permutation.h"

#include <iostream>

using std::cout;
using std::endl;

int main(){
    int test[] = {1, 2, 3};
    cout << lex::next_permutation(&test, &test) << endl;
    return 0;
}
