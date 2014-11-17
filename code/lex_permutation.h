#ifndef LEX_PERMUTATION_H
#define LEX_PERMUTATION_H
#include <iostream>

#include <algorithm>

namespace lex{
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
        	//
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
}

#endif
