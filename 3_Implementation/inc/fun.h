/**
 * @file fun.h
 * @author Raghavendra A M
 * @brief 
 * @version 0.1
 * @date 2021-08-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#ifndef __FUN_H__
#define __FUN_H__

/**
 * @brief Print all the contact details
 * 
 * @return error_t return if it has any error or not
 */
void list_all_contact();

void add_new_cont();

void search_cont();
 
void edit_cont();

void del_cont();

void block_contact();

void contact_to_block();

void list_allblocked_contact();

void fav_contact();

void search_to_add_fav();

void list_all_favourites();

void transaction();

void report();

void emerg_cont();

#endif