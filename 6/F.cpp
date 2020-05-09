void my_slightly_less_dumb_reallocation(int** source, unsigned int n_old, unsigned int n_new){
        if (*source != NULL and n_new != 0){
            int* NEW = new int[n_new];
            if (n_old > n_new){
                for (int i = 0; i < n_new; i++){
                    NEW[i] = *(*(source) + i);
                }
            } else {
                for (int i = 0; i < n_old; i++){
                    NEW[i] = *(*(source) + i);
                }
            }
            delete[] *source;
            *source = NEW;
        } else if (*source == NULL and n_new != 0){
            *source = new int[n_new];
        } else if (n_new == 0){
            delete[] *source;
            *source == NULL; 
    }
}
