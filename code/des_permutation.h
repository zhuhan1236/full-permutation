#ifndef DES_PERMUTATION_H
#define DES_PERMUTATION_H

namespace des{
    template <class T> bool next_permutation(T first, T last){
        if(first == last){
            return false;
        }
        return true;
    }
}

#endif
