#ifndef LEX_PERMUTATION_H
#define LEX_PERMUTATION_H

namespace lex{
    template <class T> bool next_permutation(T first, T last){
        if(first == last){
            return false;
        }
        return true;
    }
}

#endif
