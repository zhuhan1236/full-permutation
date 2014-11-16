#ifndef INS_PERMUTATION_H
#define INS_PERMUTATION_H

namespace ins{
    template <class T> bool next_permutation(T first, T last){
        if(first == last){
            return false;
        }
        return true;
    }
}

#endif
