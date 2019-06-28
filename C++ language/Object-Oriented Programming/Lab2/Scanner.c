/************************************************************************
*file: Scanner.c
*synopsis: The functions use pointers to be able to work with the files
*(open them, close, get information from the file and to write inside it),
*malloc/realloc to create temporary dynamical objects, made to store the
*informatoin? which was read or going to be written from/inside the file.
*Functions make database, index files, add to database new information and
*delete nessecary from it, make a set of data fields.
*These functions are declared in the include file "Scanner.h".
*related files: "Scanner.h"
*author: MarIO
*written: 10/10/2017
*last modified: 15/11/2017
************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Scanner.h"

unsigned create_db(const char *csv, const char *db) {
	FILE *fcsv = NULL, *fdb = NULL;
	SCAN_INFO *elem1, *elem2;
	int elem_counter = 0, i = 0;
	char *line = NULL, *symb_place = NULL, *ptr=NULL;
	if ((csv == NULL) || (db == NULL))
		return 1;
	if ((NULL == (fcsv = fopen(csv, "rt"))) || ((NULL == (fdb = fopen(db, "wb+"))))) 
		exit(1);
	if (NULL == (line = (char*)malloc(512*sizeof(char)))){
		fclose(fcsv);
		fclose(fdb);
		return 3;
	}
	if ((NULL == (elem1 = (SCAN_INFO*)calloc(1,sizeof(SCAN_INFO)))) || (NULL == (elem2 = (SCAN_INFO*)calloc(1,sizeof(SCAN_INFO))))) {
		free(line);
		fclose(fcsv);
		fclose(fdb);
		return 4;
	}
	fwrite(&elem_counter, sizeof(int), 1, fdb);
	while (EOF != fscanf(fcsv, "%s", line)) {
		ptr = line;
		while (symb_place = strrchr(ptr, ';'))
			*symb_place = '\0';
		strcpy(elem1->manufacturer, ptr);
		ptr += strlen(ptr) + 1;
		strcpy(elem1->model, ptr);
		ptr += strlen(ptr) + 1;
		elem1->year = atoi(ptr);
		ptr += strlen(ptr) + 1;
		elem1->price = atof(ptr);
		ptr += strlen(ptr) + 1;
		elem1->x_size = atoi(ptr);
		ptr += strlen(ptr) + 1;
		elem1->y_size = atoi(ptr);
		i = 0;
		fseek(fdb, 4, SEEK_SET);
		while (fread(elem2, sizeof(SCAN_INFO), 1, fdb) == 1) {
			if ((strcmp(elem1->model, elem2->model)) == 0) {
				if (elem1->year == elem2->year) {
					if (elem1->price == elem2->price) {
						if (elem1->x_size == elem2->x_size) {
							if (elem1->y_size == elem2->y_size) {
								i = -1;
								break;
							}
						}
					}
				}
			}
			i++;
		}
		if (i >= 0) {
			elem1->id = i;
			fwrite(elem1, sizeof(SCAN_INFO), 1, fdb);
			elem_counter++;
		}	
	}
	rewind(fdb);
	fwrite(&elem_counter, sizeof(int), 1, fdb);
	free(line);
	free(elem1);
	free(elem2);
	fclose(fdb);
	fclose(fcsv);
	return 0;
}

int manufacturer_comp(const void *l1, const void *l2) {

		return strcmp((*(SCAN_INFO**)l1)->manufacturer, (*(SCAN_INFO**)l2)->manufacturer);
}

int model_comp(const void *l1, const void *l2) {

	return strcmp((*(SCAN_INFO**)l1)->model, (*(SCAN_INFO**)l2)->model);
}

int year_comp(const void *n1, const void *n2) {
	return ((*(SCAN_INFO**)n1)->year - (*(SCAN_INFO**)n2)->year);
}

int price_comp(const void *n1, const void *n2) {
	return ((*(SCAN_INFO**)n1)->price - (*(SCAN_INFO**)n2)->price);
}

int x_size_comp(const void *n1, const void *n2) {
	return ((*(SCAN_INFO**)n1)->x_size - (*(SCAN_INFO**)n2)->x_size); 
}

int y_size_comp(const void *n1, const void *n2) {
	return ((*(SCAN_INFO**)n1)->y_size - (*(SCAN_INFO**)n2)->y_size);
}

int make_index(const char *db, const char *field_name) {
	FILE *fidx = NULL, *fdb = NULL;
	SCAN_INFO **mas_sc = NULL,*buff=NULL;
	char file_name[32];
	int  ammount = 0, i = 0, j=0, k=0;
	if ((db == NULL) || (field_name == NULL))
		return 0;
	if (NULL == (fdb = fopen(db, "rb")))
		exit(2);
	fread(&ammount, sizeof(int), 1, fdb);
	if (ammount > 0) {
		if ((NULL == (mas_sc = (SCAN_INFO**)calloc(ammount,sizeof(SCAN_INFO*)))) || (NULL == (buff = (SCAN_INFO*)calloc(1, sizeof(SCAN_INFO))))) {
			fclose(fdb);
			return 0;
		}
		for (i = 0; i < ammount; i++) {
			if (NULL == (mas_sc[i] = (SCAN_INFO*)calloc(1,sizeof(SCAN_INFO)))) {
				for (j = 0; j < i; j++)
					free(mas_sc[j]);
				free(mas_sc);
				free(buff);
				fclose(fdb);
			}
		}
		strcpy(file_name, field_name);
		strcat(file_name, ".idx");
		i = 0;
		while (fread((*(mas_sc + i)), sizeof(SCAN_INFO), 1, fdb) == 1)
			i++;
		if ( 0 == strcmp(field_name, "manufacturer"))
			qsort(mas_sc, ammount, sizeof(SCAN_INFO*), manufacturer_comp);
		if (0 == strcmp(field_name, "model"))
			qsort(mas_sc, ammount, sizeof(SCAN_INFO*), model_comp);
		if (0 == strcmp(field_name, "year"))
			qsort(mas_sc, ammount, sizeof(SCAN_INFO*), year_comp);
		if (0 == strcmp(field_name, "price"))
			qsort(mas_sc, ammount, sizeof(SCAN_INFO*), price_comp);
		if (0 == strcmp(field_name, "x_size"))
			qsort(mas_sc, ammount, sizeof(SCAN_INFO*), x_size_comp);
		if (0 == strcmp(field_name, "y_size"))
			qsort(mas_sc, ammount, sizeof(SCAN_INFO*), y_size_comp);
		if (NULL == (fidx = fopen(file_name, "wt"))) {
			for (i = 0; i < ammount; i++)
				free(*(mas_sc + i));
			free(mas_sc);
			free(buff);
			fclose(fdb);
			exit(-1);
		}
		fseek(fdb, 4, SEEK_SET);
		for (i = 0; i < ammount; i++) {
			k = -1;
			while (fread(buff, sizeof(SCAN_INFO), 1, fdb) == 1) {
				k++;
				if (buff->id == (*(mas_sc + i))->id)
					break;
			}
			fprintf(fidx, "%d ", k);
			free(*(mas_sc + i));
			fseek(fdb, 4, SEEK_SET);
		}
		free(mas_sc);
		fclose(fidx);
		free(buff);
		fclose(fdb);
	}
	return 1;
}

RECORD_SET * get_recs_by_index(const char *dba, char *indx_field) {
	RECORD_SET *ptr = NULL;
	char file_name[32];
	int i = 0, j=0;
	FILE *fdb=NULL, *fidx=NULL;
	strcpy(file_name, indx_field);
	strcat(file_name, ".idx");
	if ((NULL == dba) || (NULL == indx_field))
		return NULL;
	if ((NULL == (fdb = fopen(dba, "rb"))) || (NULL == (fidx = fopen(file_name, "rt")))) 
		exit(3);
	if (NULL == (ptr = (RECORD_SET*)malloc(sizeof(RECORD_SET)))) {
		fclose(fdb);
		fclose(fidx);
		return NULL;
	}
	fread(&(ptr->rec_nmb), 4, 1, fdb);
	if((ptr->rec_nmb) > 0){
		if (NULL == (ptr->recs = (SCAN_INFO*)calloc(ptr->rec_nmb,sizeof(SCAN_INFO)))) {
			fclose(fdb);
			fclose(fidx);
			return NULL;
		}
		j = 0;
		while (j < ptr->rec_nmb) {
			fscanf(fidx, "%d", &i);
			fseek(fdb, 4+i*sizeof(SCAN_INFO), SEEK_SET);
			fread(ptr->recs + j, sizeof(SCAN_INFO), 1, fdb);
			rewind(fdb);
			j++;
		}
	}
	else {
		ptr->recs = NULL;
	}
	fclose(fdb);
	fclose(fidx);
	return ptr;
}

void reindex(const char *db) {
	if (db == NULL)
		return;
	make_index(db, "manufacturer");
	make_index(db, "model");
	make_index(db, "year");
	make_index(db, "price");
	make_index(db, "x_size");
	make_index(db, "y_size");
	make_index(db, "id");
}

void del_scanner(const char *db, int id) {
	SCAN_INFO *ptr = NULL;
	FILE *fdb = NULL;
	int ammount = 0, i = 0;
	if ((db == NULL) || (id < 0))
		return;
	if (NULL == (fdb = fopen(db, "rb")))
		exit(4);
	fread(&ammount, sizeof(ammount), 1, fdb);
	if (NULL == (ptr = (SCAN_INFO*)malloc(ammount * sizeof(SCAN_INFO))))
		return;
	for (i = 0; i < ammount; i++)
		fread(ptr + i, sizeof(SCAN_INFO), 1, fdb);
	fclose(fdb);
	ammount--;
	if (NULL == (fdb = fopen(db, "wb"))) {
		free(ptr);
		return;
	}
	fwrite(&ammount, sizeof(ammount), 1, fdb);
	for (i = 0; i < ammount + 1; i++) {
		if(i != id)
		fwrite(ptr + i, sizeof(SCAN_INFO), 1, fdb);
	}
	fclose(fdb);
	free(ptr);
	reindex(db);
}

void add_scanner(const char *db, const char* scanner_str) {
	FILE *fdb = NULL;
	SCAN_INFO *ptr = NULL;
	char *wptr = NULL, *place = NULL, *line=NULL;
	int size = 0;
	if ((db == NULL) || (scanner_str == NULL))
		return;
	if (NULL == (ptr = (SCAN_INFO*)malloc(sizeof(SCAN_INFO))))
		return;
	if (NULL == (line = (char*)calloc((strlen(scanner_str) + 1), sizeof(char)))) {
		free(ptr);
		return;
	}
	if (NULL == (fdb = fopen(db, "rb+"))) {
		free(ptr);
		free(line);
		exit(5);
	}
	strcpy(line, scanner_str);
	wptr = line;
	while (NULL != (place = strrchr(wptr, ';')))
		*place = '\0';
	strcpy(ptr->manufacturer, wptr);
	wptr += strlen(wptr) + 1;
	strcpy(ptr->model, wptr);
	wptr += strlen(wptr) + 1;
	ptr->year = atoi(wptr);
	wptr += strlen(wptr) + 1;
	ptr->price = atof(wptr);
	wptr += strlen(wptr) + 1;
	ptr->x_size = atoi(wptr);
	wptr += strlen(wptr) + 1;
	ptr->y_size = atoi(wptr);
	free(line);
	fread(&size, sizeof(size), 1, fdb);
	size++;
	rewind(fdb);
	fwrite(&size, sizeof(size), 1, fdb);
	if (NULL == freopen(db, "ab", fdb)) 
		free(ptr);
	ptr->id = size - 1;
	fwrite(ptr, sizeof(SCAN_INFO), 1, fdb);
	fclose(fdb);
	free(ptr);
	reindex(db);
}

void print_db(const char *db) {
	FILE *fdb = NULL, *ftxt = NULL;
	SCAN_INFO *buff=NULL;
	int size=0;
	if (NULL == db)
		return;
	if (NULL == (fdb = fopen(db, "rb")))
		exit(6);
	if (NULL == (ftxt = fopen("print_db.txt", "wt"))) {
		fclose(fdb);
		exit(7);
	}
	if (NULL == (buff = (SCAN_INFO*)malloc(sizeof(SCAN_INFO)))) {
		fclose(fdb);
		fclose(ftxt);
		return;
	}
	fread(&size, sizeof(size), 1, fdb);
	fprintf(ftxt, "Scanners_Ammount:\n%d\n\n", size);
	while (fread(buff, sizeof(SCAN_INFO), 1, fdb) == 1) {
		fprintf(ftxt, "Manufacturer:\n%s\n", buff->manufacturer);
		fprintf(ftxt, "Model:\n%s\n", buff->model);
		fprintf(ftxt, "Price:\n%f\n", buff->price);
		fprintf(ftxt, "Year:\n%d\n", buff->year);
		fprintf(ftxt, "Length:\n%d\n", buff->x_size);
		fprintf(ftxt, "Width:\n%d\n", buff->y_size);
		fprintf(ftxt, "Id:\n%d\n\n", buff->id);
	}
	free(buff);
	fclose(fdb);
	fclose(ftxt);
	return;
}

RECORD_SET* select(const char *db, const char *field, const char *value) {
	RECORD_SET *ptr = NULL;
	SCAN_INFO *buff = NULL, *elem=NULL;
	FILE *fdb = NULL;
	int i = 0, size = 0;
	double j = 0;
	if ((db == NULL) || (field == NULL))
		return NULL;
	if (NULL == (fdb = fopen(db, "rb"))) 
		exit(8);
	if (NULL == (elem = (SCAN_INFO*)calloc(1,sizeof(SCAN_INFO)))) {
		fclose(fdb);
		return NULL;
	}
	if (NULL == (ptr = (RECORD_SET*)malloc(sizeof(RECORD_SET)))) {
		free(elem);
		fclose(fdb);
		return NULL;
	}
	fread(&size, sizeof(size), 1, fdb);
	if (NULL == (buff = (SCAN_INFO*)calloc(size,sizeof(SCAN_INFO)))) {
		fclose(fdb);
		free(elem);
		return NULL;
	}
	size = 0;
	while (1 == fread(elem, sizeof(SCAN_INFO), 1, fdb)) {
		if (0 == strcmp(field, "manufacturer")) {
			if (0 == strcmp(elem->manufacturer, value))
				i = 1;
		}
		else {
			if (0 == strcmp(field, "model")) {
				if (0 == strcmp(elem->model, value))
					i = 1;
			}
			else {
				if (0 == strcmp(field, "year")) {
					i = atoi(value);
					if (elem->year == i)
						i = 1;
				}
				else {
					if (0 == strcmp(field, "price")) {
						j = atof(value);
						if (elem->price == j)
							i = 1;
					}
					else {
						if (0 == strcmp(field, "id")) {
							i = atoi(value);
							if (elem->id == i)
								i = 1;
						}
						else {
							if (0 == strcmp(field, "x_size")) {
								i = atoi(value);
								if (elem->x_size == i)
									i = 1;
							}
							else {
								if (0 == strcmp(field, "y_size")) {
									i = atoi(value);
									if (elem->y_size == i)
										i = 1;
								}
							}
						}
					}
				}
			}
		}
		if (i == 1) {
			strcpy((buff + size)->manufacturer, elem->manufacturer);
			strcpy((buff + size)->model, elem->model);
			(buff + size)->price = elem->price;
			(buff + size)->year = elem->year;
			(buff + size)->x_size = elem->x_size;
			(buff + size)->y_size = elem->y_size;
			(buff + size)->id = elem->id;
			size++;
			i = 0;
		}
	}
	free(elem);
	if (NULL == (ptr=(RECORD_SET*)malloc(sizeof(RECORD_SET)))) {
		free(buff);
		fclose(fdb);
		return NULL;
	}
	ptr->rec_nmb = size;
	if (NULL == (ptr->recs = (SCAN_INFO*)malloc(ptr->rec_nmb * sizeof(SCAN_INFO)))) {
		free(buff);
		fclose(fdb);
		return NULL;
	}
	for (i = 0; i < size; i++) {
		strcpy((ptr->recs + i)->manufacturer, (buff + i)->manufacturer);
		strcpy((ptr->recs + i)->model, (buff + i)->model);
		(ptr->recs + i)->year = (buff + i)->year;
		(ptr->recs + i)->price = (buff + i)->price;
		(ptr->recs + i)->x_size = (buff + i)->x_size;
		(ptr->recs + i)->y_size = (buff + i)->y_size;
		(ptr->recs + i)->id = (buff + i)->id;
	}
	fclose(fdb);
	free(buff);
	return ptr;
}

void print_rec_set(RECORD_SET *rs) {
	int i=0;
	if (rs == NULL) {
		printf("There is NO set of elements, which are pointed by \"*rs\"");
		return;
	}
	printf("\n");
	while (i < rs->rec_nmb) {
		printf("Manufacturer:\n%s\n", (rs->recs + i)->manufacturer);
		printf("Model:\n%s\n", (rs->recs + i)->model);
		printf("Year:\n%d\n", (rs->recs + i)->year);
		printf("Price:\n%f\n", (rs->recs + i)->price);
		printf("Length:\n%d\n", (rs->recs + i)->x_size);
		printf("Width:\n%d\n", (rs->recs + i)->y_size);
		printf("Id:\n%d\n", (rs->recs + i)->id);
		printf("\n");
		i++;
	}
}