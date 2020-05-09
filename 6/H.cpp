Cat* get_home_for_a_cats_pride(unsigned int n){
    if (n != 0){
    Cat* cats = new Cat[n];
    char* names = new char[10 * n]; 
    for (int i = 0; i < n; i++){
        cats[i].name = &names[10 * i]; 
    }
    return cats;
    } else {
        return NULL;
    }
}

void clear_home_of_a_cats_pride(Cat *cats, unsigned int n){
    if (n != 0){
    delete[] cats[0].name;
    delete[] cats;}
}