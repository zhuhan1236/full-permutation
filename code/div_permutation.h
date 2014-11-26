#ifndef DIV_PERMUTATION_H
#define DIV_PERMUTATION_H
#include <iostream>

#include <algorithm>

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
                    permutation_num++;
                }
            }while(next_permutation(first, first + array_mid));
        }while(next_combination(used_or_not, array_length, array_mid));

        delete [] used_or_not;
        return permutation_num;
    }
}

#endif
