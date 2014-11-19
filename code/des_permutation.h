#ifndef DES_PERMUTATION_H
#define DES_PERMUTATION_H

namespace des{

    bool plusOne(int *intermediary_number,int num){
        int add = 1;
        int ary;
        int tempNum;
        for (int i = num - 1;i >= 0;i--){
            ary = i + 2;
            tempNum = intermediary_number[i] + add;
            add = tempNum / ary;
            intermediary_number[i] = tempNum % ary;
        }
        // for (int i = 0;i < num;i++){
        //  std::cout<<intermediary_number[i]<<" ";
        // }
        // std::cout<<std::endl;
        if (add == 1){
            //get the last one
            return false;
        }else{
            return true;
        }
    }

    template <class T> bool getPermutationFromIntermediary(T first, T right,int* intermediary_number,T sortedFirst){
        int arrayLength = right - first + 1;
        int iNumLength = right - first;
        T temp = right;
        for (int i = 0;i < arrayLength;i++){
            *(first + i) = 0; 
        }

        for (int i = iNumLength - 1;i >= 0;i--){
            int k = intermediary_number[i];
            temp = right;
             while (k != 0){
                if (*temp == 0){
                    k--;
                }
                temp--;
            }

            while ((*temp) != 0 && temp >= first){
                temp--;
            }
            if (temp < first){
                return false;
            }
            // now sorted array is from small to big
            (*temp) = *(sortedFirst + i+1);
        }
        temp = right;
        while (*temp != 0){
            temp--;
        }
        *temp = *(sortedFirst);
        return true;
    }

    template <class T> bool next_permutation(T first, T last,int* intermediary_number,T sortedFirst){
        if(first == last){
            return false;
        }
        T right = last - 1;
        if (right == first)
            return false;
        getPermutationFromIntermediary(first,right,intermediary_number,sortedFirst);
        //在这里输出比较妥当，不然会少最后一个。
        T temp = first;
        while (temp < last){
            std::cout<<*temp<<" ";
            temp++;
        }
        std::cout<<std::endl;

        return plusOne(intermediary_number,right - first);
    }
}

#endif
