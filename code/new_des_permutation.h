#ifndef NEW_DES_PERMUTATION_H
#define NEW_DES_PERMUTATION_H

namespace new_des{
    //sorted list is from big to small
    template <class T> bool next_permutation(T first, T last,int* index,T sortedFirst){
        if(first == last){
            return false;
        }
        T right = last - 1;
        if (right == first)
            return false;
        if (*index == 0){
            int i = 1;
            while (*(first + i) == *(sortedFirst + i)){
                i++;
            }
            if (i == last - first){
                return false;
            }
            //from 0 to i - 1 is equal
            std::reverse(first + i,last);
            std::reverse(first,last);
            
            int j = 1;
            while(*(first+j) != *(sortedFirst + i))
                j++;
            std::iter_swap(first+j,first+j-1);
            
            *index = last - first - 1;
        }else{
            std::iter_swap(first + *index,first + *index - 1);
            *index = *index - 1;
        }
        return true;
    }
}

#endif
