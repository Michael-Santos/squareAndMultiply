/*
 * @Author: Michael dos Santos
*/

#include<stdio.h>
#include<stdlib.h>

#define NUMBER_NUM_BITS 64

typedef unsigned long long int NUMBER;

/*
 * Get the value of a specific bit
 * 
 * @params value - Number to find the bit
 * @params index - Index of the bit (bit zero is the leftmost bit)
 * @returns Value of the bit
*/
int get_bit_by_index(NUMBER value, int index) {
    NUMBER left_shift = value << index;
    return left_shift >> NUMBER_NUM_BITS - 1;
}

/*
 * Find the leftmost bit with value
 * 
 * @params value - Number to find a the leftmost bit one
 * @returns Index of the bit
*/
int find_leftmost_one_bit(NUMBER value) {
    int bit = 0;
    
    for(int i = 0; i < NUMBER_NUM_BITS; i++) {
        bit = get_bit_by_index(value, i);
        if (bit == 1) return i;
    }   
    return(-1);
}


/*
 * Efficient alway to calculate exponentions using square and multiply operations
 * 
 * @params base - Base of operation
 * @params power - Power of operation
*/
NUMBER sqr_n_multiply(NUMBER base, NUMBER power) {
    int index, bit;
    NUMBER result = base;
    
    index = find_leftmost_one_bit(power);
    
    for(int i = ++index; i < NUMBER_NUM_BITS; i++) {
        bit = get_bit_by_index(power, i);
        result *= result;

        if(bit == 1) result *= base;
    }
    return result;
}

int main()
{
    NUMBER base, power;
    
    // Read entries
    scanf("%llu", &base);
    scanf("%llu", &power);

    printf("%llu\n", sqr_n_multiply(base, power));

    return 0;
}
