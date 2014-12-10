#include "lex_permutation.h"
#include "ins_permutation.h"
#include "des_permutation.h"
#include "exc_permutation.h"
#include "div_permutation.h"
#include "new_des_permutation.h"

#include <iostream>
#include <sys/time.h>

using std::cout;
using std::endl;

template <class T> void get_full_permutation(bool (*next_permutation)(T, T), T first, T last);
template <class T> void get_full_permutation(bool (*next_permutation)(T, T, int *, T), T first, T last, T sortedFirst);
template <class T> void get_full_permutation_with_divide(T origin, T first, T last, T *cache, long long cache_size, int cache_length, T result);
template <class T> void get_full_permutation_with_exc(T first, T right, bool *flags, T sortedFirst);
template <class T> void get_full_permutation_with_dec(T first, T last, int *index, T sortedFirst);
long getSystemTime();

int main(int argc, char *argv[]){
    int size = atoi(argv[2]);
    int *test = new int[size];
    int *temp = new int[size];
    for (int i = 0;i < size;++i){
        test[i] = atoi(argv[i+3]);
        temp[i] = test[i];
    }

    switch(argv[1][0]){
        case 'l': // zidianxu
            {
                get_full_permutation(lex::next_permutation, test, test + size);
            }
            break;
        case 'i':// dizeng
            {
                std::reverse(temp, temp + size);
                get_full_permutation(ins::next_permutation, test, test + size, temp);
            }
            break;
        case 'd':// dijian
            {
                get_full_permutation(des::next_permutation, test, test + size, temp);
            }
            break;
        case 'g':// gaijin dejian
            {
                std::reverse(temp, temp + size);
                int *index = new int;
                *index = size - 1;
                get_full_permutation_with_dec(test, test + size, index, temp);
                delete index;
            }
            break;
        case 'e':// linwei
            {
                std::reverse(temp, temp + size);
                bool *temp_bool = new bool[size];
                memset(temp_bool, false, sizeof(bool) * size);
                get_full_permutation_with_exc(test, test + size - 1, temp_bool, temp);
                delete [] temp_bool;
            }
            break;
        case 'o':// our
            {
                long long cache_size = 1;
                int cache_length = atoi(argv[size + 3]);
                for(int i = 2;i <= cache_length;++i){
                    cache_size *= i;
                }
                int **cache = new int*[cache_size];
                for(int i = 0;i < cache_size;++i){
                    cache[i] = new int[cache_length];
                }
                int *result = new int[size];
                get_full_permutation_with_divide(temp, test, test + size, cache, cache_size, cache_length, result);
                for(int i = 0;i < cache_size;++i){
                    delete [] cache[i];
                }
                delete [] cache;   
                delete [] result;
            }
            break;
        default:// std::next_permutation
            {
                get_full_permutation(std::next_permutation, test, test + size);
            }
    }
    return 0;
}

template <class T> void get_full_permutation(bool (*next_permutation)(T, T), T first, T last){
    long start_time = getSystemTime();
    long long permutation_num = 0;
    do{
        permutation_num++;
    }while(next_permutation(first, last));
    long end_time = getSystemTime();
    
    cout << last - first << " " << end_time - start_time << "ms" << endl;
}

template <class T> void get_full_permutation(bool (*next_permutation)(T, T, int *, T), T first, T last, T sortedFirst){
    int *i_number = new int[last - first - 1];
    memset(i_number, 0, sizeof(int) * (last - first - 1));
    long start_time = getSystemTime();
    while(next_permutation(first, last, i_number, sortedFirst));
    long end_time = getSystemTime();
    
    delete [] i_number;
    cout << last - first << " " << end_time - start_time << "ms" << endl;
}

template <class T> void get_full_permutation_with_divide(T origin, T first, T last, T *cache, long long cache_size, int cache_length, T result){
    long start_time = getSystemTime();
    long long permutation_num = divide::get_full_permutation(origin, first, last, cache, cache_size, cache_length, result);
    long end_time = getSystemTime();

    cout << last - first << " " << last - first - cache_length << " " << end_time - start_time << "ms" << endl;
}

template <class T> void get_full_permutation_with_exc(T first, T right, bool *flags, T sortedFirst){
    long start_time = getSystemTime();
    exc::excPermutation(first, right, flags, sortedFirst);
    long end_time = getSystemTime();

    cout << right - first + 1 << " " << end_time - start_time <<  "ms" << endl;
}

template <class T> void get_full_permutation_with_dec(T first, T last, int *index, T sortedFirst){
    long start_time = getSystemTime();
    long long p_num = 0;
    while(new_des::next_permutation(first, last, index, sortedFirst))
        p_num++;
    long end_time = getSystemTime();

    cout << last - first << " " << end_time - start_time <<  "ms" << endl;
}

long getSystemTime(){  
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long t = tv.tv_sec;
    t *= 1000;
    t += tv.tv_usec/1000;
    return t;
}  
