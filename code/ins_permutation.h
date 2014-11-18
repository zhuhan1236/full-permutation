#ifndef INS_PERMUTATION_H
#define INS_PERMUTATION_H

namespace ins{

	template <class T> int* getIntermediaryNum(T first, T right,int* index){
    	int *intermediary_number = new int[right - first];
    	int n = right - first;
    	T temp;
    	for (int i = 0;i < n;i++){
    		int bigger = 0;
    		for (temp = first + index[i]+1;temp <= right;temp++){
    			if (*(first + index[i]) > *(temp)){
    				bigger ++;
    			}
    		}
    		intermediary_number[i] = bigger;
    	}
    	return intermediary_number;
	}

	bool plusOne(int *intermediary_number,int num){
		int add = 1;
		int ary,temp;
		int tempNum;
		for (int i = 1;i <= num;i++){
			temp = num - i;
			ary = i + 1;
			tempNum = intermediary_number[temp] + add;
			add = tempNum / ary;
			intermediary_number[temp] = tempNum % ary;
		}
		// for (int i = 0;i < num;i++){
		// 	std::cout<<intermediary_number[i]<<" ";
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

		for (int i = 0;i < iNumLength;i++){
			int k = intermediary_number[i];
			temp = right;
			//need to be improved
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
			(*temp) = *(sortedFirst + i);

		}

		temp = right;
		while (*temp != 0){
			temp--;
		}
		*temp = *(sortedFirst + iNumLength);
		return true;
	}

    template <class T> bool next_permutation(T first, T last,int* intermediary_number,T sortedFirst){
        if(first == last){
            return false;
        }
        T right = last - 1;
        if (right == first){
        	return false;
        }

        getPermutationFromIntermediary(first,right,intermediary_number,sortedFirst);
        //在这里输出比较妥当，不然会少最后一个。

        return plusOne(intermediary_number,right - first);
    }

    
}

#endif
