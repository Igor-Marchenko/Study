/************************************************************************
*file: Scanner.h
*purpose: declarations for functions, types
*author: MarIO
*written: 10/10/2017
*last modified: 15/11/2017
*************************************************************************/


#ifndef __SCANNER_H__
#define __SCANNER_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int id;//унікальний ідентифікатор
	char manufacturer[128];// виготовлювач
	int year;	 // рік виготовлення
	char model[128];// найменування моделі
	float price;// ціна
	int x_size;// горизонтальний розмір області сканування
	int y_size;// вертикальний розмір області сканування
} SCAN_INFO;


typedef struct {
	int rec_nmb;//number of records
	SCAN_INFO *recs;//records 
}RECORD_SET;


unsigned create_db(const char *csv, const char *db);
int make_index(const char *db, const char *field_name);
RECORD_SET * get_recs_by_index(const char *dba, char *indx_field);
void reindex(const char *db);
void del_scanner(const char *db, int id);
void add_scanner(const char *db, const char* scanner_str);
void print_db(const char *db);
RECORD_SET* select(const char *db, const char *field, const char *value);
void print_rec_set(RECORD_SET *rs);

#endif /* __SCANNER_H__ */