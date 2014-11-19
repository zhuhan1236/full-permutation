#ifndef EXC_PERMUTATION_H
#define EXC_PERMUTATION_H

namespace exc{

    //need initial flags first
    //sorted from big to small

    template <class T> bool myMove(T first, T last, bool* flags, T sortedFirst){
    	T max = first;
    	T lastMax;
    	bool moved = false;
    	int n = last - first;
    	int i;
    	
    	for (i = 0;i < n;i++){
    		if (moved)
    			if (*(first + i) < *max){
    				continue;
    			}
    		 if ((flags[i] && i < n-1 && *(first + i) > *(first + i + 1)) || //指向右侧 
            (!flags[i] && i > 0 && *(first + i) > *(first + i-1))){
            	max = first + i;
            	moved = true;
        	}
    	}
    	if (!moved){
    		return false;
    	}
    	if (flags[max - first]){
    		std::iter_swap(max,max + 1);
    		//std::cout<<"change: "<<*max<<" "<<*(max + 1)<<std::endl;
    		lastMax = max + 1;
    		std::swap(flags[max - first],flags[max - first + 1]);
    	}else{
    		std::iter_swap(max,max - 1);
    		//std::cout<<"change: "<<*max<<" "<<*(max - 1)<<std::endl;
    		lastMax = max - 1;
    		std::swap(flags[max - first],flags[max - first - 1]);
    	}
    	 for (int i=0; i<n; i++){
        	if (*(first+i) > *lastMax)
            	flags[i] = !flags[i];
    	}
    	return true;
	}

   	template <class T> void excPermutation(T first,T right,bool* flags,T sortedFirst){
    	int n = right - first + 1;
    	//print the first and then
    	

    	do
    	{
    		// for (T t = first;t <= right;t++){
    		// 	std::cout<<*t<<" ";
    		// }
    		// std::cout<<std::endl;
    		if (*right == *sortedFirst){
    			for (int i = 0;i < n - 1;i ++){
    				std::iter_swap(right - i,right - i - 1);
    				std::swap(flags[n-1-i],flags[n-1-i-1]);
    				// for (T t = first;t <= right;t++){
    				// 	std::cout<<*t<<" ";
    				// }
    				// std::cout<<std::endl;
    			}
    		}else{
    			for (int i=1; i<n; i++){
    		 		std::iter_swap(first+i,first+i-1);
    		 		std::swap(flags[i],flags[i-1]);
    		 	// 	for (T t = first;t <= right;t++){
    				// 	std::cout<<*t<<" ";
    				// }
    				// std::cout<<std::endl;
            	}
    		}
    	} while (myMove(first,right + 1,flags,sortedFirst));
	}
}

#endif
