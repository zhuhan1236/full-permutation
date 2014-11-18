#include "lex_permutation.h"
#include "ins_permutation.h"
#include "des_permutation.h"
#include "exc_permutation.h"

#include <iostream>
#include <sys/time.h>

using std::cout;
using std::endl;

template <class T> void get_full_permutation(bool (*next_permutation)(T, T), T first, T last);
template <class T> void get_full_permutation(bool (*next_permutation)(T, T, int *, T), T first, T last, T sortedFirst);
long getSystemTime();

int main(int argc, char *argv[]){
    char test[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char temp[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    switch(argv[1][0]){
        case 'l':
            get_full_permutation(lex::next_permutation, test, test + 10);
            break;
        case 'i':
            std::reverse(temp, temp + 10);
            get_full_permutation(ins::next_permutation, test, test + 10, temp);
            break;
        case 'd':
            get_full_permutation(des::next_permutation, test, test + 10, temp);
            break;
        case 'e':
            break;
        default:
            get_full_permutation(std::next_permutation, test, test + 10);
    }
    return 0;
}

template <class T> void get_full_permutation(bool (*next_permutation)(T, T), T first, T last){
    long start_time = getSystemTime();
    while(next_permutation(first, last));
    long end_time = getSystemTime();
    
    cout << end_time - start_time << endl;
}

template <class T> void get_full_permutation(bool (*next_permutation)(T, T, int *, T), T first, T last, T sortedFirst){
    int *i_number = new int[last - first - 1];
    memset(i_number, 0, sizeof(int) * (last - first - 1));
    long start_time = getSystemTime();
    while(next_permutation(first, last, i_number, sortedFirst));
    long end_time = getSystemTime();
    
    delete [] i_number;
    cout << end_time - start_time << endl;
}

long getSystemTime(){  
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long t = tv.tv_sec;
    t *= 1000;
    t += tv.tv_usec/1000;
    return t;
}  
