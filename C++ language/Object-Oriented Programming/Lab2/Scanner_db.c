/************************************************************************
*file: Scanner_db.c
*synopsis: This file is made for different tests with the functions,
* provided from "Scanner.h"(prototypes) and "Scanner.c"(declarations)
*related files: "Scanner.h", "Scanner.c"
*author: MarIO
*written: 10/10/2017
*last modified: 15/11/2017
************************************************************************/

#include "Scanner.h"

int main() {
	int i = 0;
	create_db("Scanners.csv", "Scanners.db");
	print_db("Scanners.db");
	reindex("Scanners.db");
	add_scanner("Scanners.db", "Asus;AS1055;2009;99.99;210;297");
	print_db("Scanners.db");
	del_scanner("Scanners.db", 5);
	print_db("Scanners.db");
	printf("Select function started\n");
	RECORD_SET *rs = select("Scanners.db", "manufacturer", "HP");
	print_rec_set(rs);
	free(rs->recs);
	free(rs);
	printf("Select function finished\n");
	printf("Get_recs_by_index function started\n");
	rs = get_recs_by_index("Scanners.db", "model");
	print_rec_set(rs);
	free(rs->recs);
	free(rs);
	printf("Get_recs_by_index function finished\n");
	system("pause"); 
	return 0;
}
