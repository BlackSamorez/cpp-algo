#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Direction {
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3
};

struct Location_t {
    bool is_medical_center;
    int free_beds;
    int indicator;
    struct Location_t *up;
    struct Location_t *down;
    struct Location_t *right;
    struct Location_t *left;
};

Location_t *find_medical_center(Location_t* start_location){
	if (*start_location.is_medical and *start_location.free_beds > 0){
		return start_location;
	} /*else {
		struct Location_t *path;
		if (start_location.indicator == 0){
			path = *start_location.up
		}
		if (start_location.indicator == 1){
			path = *start_location.down
		}
		if (start_location.indicator == 2){
			path = *start_location.right
		}
		if (start_location.indicator == 3){
			path = *start_location.left
		}
		find_medical_center(path);
	}*/
	
	
}