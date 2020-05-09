unsigned int count_total_mice_amount(Cat* cats, unsigned int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        count += cats[i].mice_caught;
    }
    return count;
}