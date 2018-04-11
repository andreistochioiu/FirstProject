/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   des.h
 * Author: calin
 *
 * Created on March 22, 2018, 4:19 PM
 */

#ifndef DES_H
#define DES_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _DES_H_
#define _DES_H_

    #define BYTES_PER_DATABLOCK 8

    #define ENCRYPTION_MODE 1
    #define DECRYPTION_MODE 0

    typedef struct {
            unsigned char k[8];
            unsigned char c[4];
            unsigned char d[4];
    } key_set;

    void generate_key(unsigned char* key);
    void generate_blocks(unsigned char *startdatablock, unsigned numblocks);
    
    void generate_sub_keys(unsigned char* main_key, key_set* key_sets);
    void process_message(unsigned char* message_piece, unsigned char* processed_piece, key_set* key_sets, int mode);

    #endif

#ifdef __cplusplus
}
#endif

#endif /* DES_H */

