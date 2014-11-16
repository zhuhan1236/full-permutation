#ifndef EXC_PERMUTATION_H
#define EXC_PERMUTATION_H

namespace exc{
    template <class T> bool next_permutation(T first, T last){
        if(first == last){
            return false;
        }
        return true;
    }
}

#endif
