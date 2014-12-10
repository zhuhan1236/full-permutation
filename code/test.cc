#include <algorithm>
#include <iostream>
#include <sys/time.h>

using std::cout;
using std::cin;
using std::endl;

namespace divide{
    /*function to get next combination*/
    bool next_combination(bool *used_or_not, int length, int ones){
        int start_pos = length - 1;
        for(int i = 1;i <= ones;++i){
            for(int j = start_pos;j >= 0;--j){
                if(used_or_not[j]){
                    if(j == start_pos){
                        start_pos--;
                        break;
                    }
                    else{
                        used_or_not[j] = false;
                        for(int k = 1;k <= i;++k){
                            used_or_not[j+k] = true;
                        }
                        for(int k = j+i+1;k < length;++k){
                            used_or_not[k] = false;
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    }

    template <class T> bool next_permutation(T first, T last){
        if(first == last){
            return false;
        }
        T right = last - 1;
        if (right == first){
            return false;
        }
        while (right > first){
            if (*right > *(right - 1))
                break;
            else
                right--;
        }
        if (right == first){
            std::reverse(first, last);
            return false;
        }else{
            for (T temp = last - 1;temp >= right;temp--){
                if (*(temp) > *(right - 1)){
                    std::iter_swap(temp, right - 1);
                    std::reverse(right, last);
                    return true;
                }
            }
        }
        return false;
    }

    /*function to get full permutation
     * @param cache, 2-dimensional array to cache some permutations
     * @param cache_size, number of permutations to be cached
     * @param cache_len, number of charactors in a cache
     */
    template <class T> long long get_full_permutation(T copy, T first, T last, T *cache, long long cache_size, int cache_len, T result){
        long long permutation_num = 0;
        int array_length = last - first;
        int array_mid = array_length - cache_len;

        bool *used_or_not = new bool[array_length];
        memset(used_or_not, false, sizeof(bool) * array_length);
        for(int i = 0;i < array_mid;++i){
            used_or_not[i] = true;
        }
        
        int combination_num = 0;
        
        do{
            combination_num++;
            /*get new combination*/
            int j = 0;
            int k = 0;
            for(int i = 0;i < array_length;++i){
                if(used_or_not[i]){
                    first[j++] = copy[i];
                }
                else{
                    first[array_mid + k++] = copy[i];
                }
            }
            
            /*cache the second part*/
            int p = 0;
            do{
                memcpy(cache[p], first + array_mid, sizeof(*first)*cache_len);
                p++;
            }while(next_permutation(first + array_mid, last));
            /*end cache*/

            do{
                memcpy(result, first, sizeof(*first) * array_mid);
                for(p = 0;p < cache_size;++p){
                    /*output
                     * the first part: first to first+array_mid 
                     * the second part: cache[p]
                     */
                    memcpy(result+array_mid, cache[p], sizeof(*first) * cache_len);

                    /* output */
                    for(int i = 0;i < array_length-1;++i){
                        cout << result[i] << " ";
                    }
                    cout << result[array_length - 1] << endl;
                    /* end output*/

                    permutation_num++;
                }
            }while(next_permutation(first, first + array_mid));
        }while(next_combination(used_or_not, array_length, array_mid));

        delete [] used_or_not;
        return permutation_num;
    }
}

template <class T> void get_full_permutation_with_divide(T origin, T first, T last, T *cache, long long cache_size, int cache_length, T result);
long getSystemTime();

int main(int argc, char *argv[]){
    int size = 0;
    cin >> size;
    int *test = new int[size];
    int *temp = new int[size];
    for (int i = 0;i < size;++i){
        cin >> test[i];
        temp[i] = test[i];
    }

    long long cache_size = 1;
    int cache_length = size / 2;
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

    return 0;
}

template <class T> void get_full_permutation_with_divide(T origin, T first, T last, T *cache, long long cache_size, int cache_length, T result){
    long start_time = getSystemTime();
    long long permutation_num = divide::get_full_permutation(origin, first, last, cache, cache_size, cache_length, result);
    long end_time = getSystemTime();

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
