/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: calin
 *
 * Created on March 22, 2018, 4:18 PM
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;
/*
https://en.wikipedia.org/wiki/Data_Encryption_Standard

Implement DES-CTR algorithm on i5 gen2 processor. Use 1M bytes of data to clock the algo.

Required speed: 
5/10 for 1 MB/s
6/10 for 2 MB/s
7/10 for 5 MB/s
8/10 for 10 MB/s
9/10 for 20 MB/s
9/10 for 40 MB/s
9/10 for 60 MB/s
10/10 for 80 MB/s
*/

#include "des.h"

#define NUM_DATABLOCKS (1)

unsigned char data_block[BYTES_PER_DATABLOCK * NUM_DATABLOCKS];
unsigned char processed_block[BYTES_PER_DATABLOCK * NUM_DATABLOCKS];
key_set key_sets[17];
unsigned char des_key[BYTES_PER_DATABLOCK * NUM_DATABLOCKS];

int main(int argc, char** argv) {
    
    double time_taken;    
    clock_t start, finish;

    generate_key(des_key);
    generate_blocks(data_block, NUM_DATABLOCKS);

    start = clock();
    for (unsigned i = 0; i < NUM_DATABLOCKS; i++) {
        generate_sub_keys(des_key, key_sets);
        process_message(data_block + BYTES_PER_DATABLOCK * i, processed_block + BYTES_PER_DATABLOCK * i, key_sets, ENCRYPTION_MODE);
    }
    
    finish = clock();
    time_taken = (double)(finish - start)/(double)CLOCKS_PER_SEC;

    printf("Time for X blocks %f\n", time_taken);
    printf("Datarate %f KB/s\n", (BYTES_PER_DATABLOCK * NUM_DATABLOCKS) / time_taken / 1000);
    
    return 0;
}


