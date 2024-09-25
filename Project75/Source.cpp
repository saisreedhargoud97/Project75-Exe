#include <stdlib.h>
#include <string>
#include <tcinit/tcinit.h>
#include <tccore/item.h>
#include <tc/tc_macros.h>
#include <iostream>
#include<tccore/aom_prop.h>
using namespace std;

int ITK_user_main(int argc, char* argv[])
{

	ITK_init_module("infodba", "infodba", "dba");
	char *cValue = NULL;
	int iFail = 0;
	tag_t item, rev_tag;
	ITEM_find_item("000043", &item);

	iFail = ITEM_find_revision(item, "A", &rev_tag);
	if (iFail == ITK_ok) {

		AOM_ask_value_string(rev_tag, "object_name", &cValue);
		cout << "found" << cValue << endl;
	}
	else {
		cout << "not found" << endl;
	}
	return 0;
}
