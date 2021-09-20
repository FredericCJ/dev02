int *find_min_addr(int *array){
    if(*array == -__INT_MAX__)
        return (int *)__INT_MAX__;
    
    int min_val = __INT_MAX__;
    int *min_ptr = array;
    int i =0;

    while(array[i] != -__INT_MAX__){
        if(array[i] <= min_val){
            min_val = array[i];
            min_ptr = &array[i];
        }
        i++;
    }

    return min_ptr;
} //return address of the minimum of an array

int *find_max_addr(int *array){
    if(*array == -__INT_MAX__)
        return (int *)(-__INT_MAX__);
    
    int max_val = -__INT_MAX__;
    int *max_ptr = array;
    int i = 0;
    //for(int i=0 ; i<size ; i++)
    while(array[i] != -__INT_MAX__){
        if(array[i] >= max_val){
            max_val = array[i];
            max_ptr = &array[i];
        }
        i++;
    }

    return max_ptr;
} //return address of the maximum of an array
