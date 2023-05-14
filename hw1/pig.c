#include "names.h"

#include <stdio.h>
#include <stdlib.h>

//Function to assign points to zero for all players
void assign_points(int points[], int size) {
    for (int i = 0; i < size; i++) {
        points[i] = 0;
    }
}

//Function to find the largest number in an array
int find_max(int arr[], int size) {
    int i;
    int max = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > max){
	    max = arr[i];
	}
    }
    return max;
}

//Function to find a random number between one and seven
int find_random(int lower, int upper, int count) {
    int a;
    for (a = 0; a < count; a++) {
        int num = (rand() % (upper - lower + 1)) + lower;
	return num;
    }
    return 0;
}

//Function to move to the next player in the array
int next_element(int pos, int players) {
    return (pos + 1) % players;
}

int main(void) {
    int players = 0;
    int seed = 0;
    int i = 0;
    //int n = 0;
    printf("Number of players: ");
    scanf("%d", &players);
    //Error message loop for number of players
    if (players < 2 || players > 10) {
        fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
        players = 2;
    }
    printf("Random seed: ");
    scanf("%d", &seed);
    srandom(seed);
    //Error message loop for seed
    if (seed <= 0 || seed >= 2147483647) {
        fprintf(stderr, "Invalid random seed. Using 2022 instead.\n");
        seed = 2022;
    }
    int points[players];
    assign_points(points, players);
    //int length = sizeof(points)/sizeof(points[0]);
    //for (int i = 0; i < length; i++) {     
    //   printf("%d \n", points[i]);     
    //}
    //while (find_max(points, length) < 5) {
    printf("%s is currently rolling the pig\n", names[i]);
    //	int random_num = find_random(1, 7, 1);
    //	printf("%d is the num", random_num);
    //  if (random_num == 1 || random_num == 2) {
    //	    printf("%s rolled a side.", names[i]);
    //	    int next = next_element(n, players);
    // 	    points[next_element] = points[next_element] + 1;
    //	}
    //	else if (random_num(1, 7, 1) == 3) {\
    //	    printf("%s rolled a razorback", names[i]);
    //	    points[player] + 10;
    //	} 
    //		
    //    i += 1;
    //}	
    return 0;
}

