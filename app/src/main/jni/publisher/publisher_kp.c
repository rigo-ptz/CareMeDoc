
#include "../hello.h"

// ---Constants---
// Describes connection to the SS.
#define KP_SS_NAME "X"
//#define KP_SS_ADDRESS "194.85.173.9"  // Public PetrSU SIB
#define KP_SS_ADDRESS "78.46.130.194"     // Local SIB
#define KP_SS_PORT 10010


int main(int argc, char** argv)
{
    sslog_init();

    sslog_node_t *node = sslog_new_node("HelloWorldHigh_KP", KP_SS_NAME, KP_SS_ADDRESS, KP_SS_PORT);

    register_ontology(node);

    // In the smart space the name of the KP must be unique, if you try to
    // join without leave, then you received an error.
    if (sslog_node_join(node) != SSLOG_ERROR_NO) {
        printf("Can't join to SS: %s\n", sslog_error_get_last_text());
        return 0;
    }

    printf("KP joins to SS.\n");

    sslog_individual_t *universum = sslog_new_individual(CLASS_UNIVERSUM, "http://testclass.ru#universum1");

    if (universum == NULL) {
        printf("\nError: %s\n", sslog_error_get_last_text());
        return 0;
    }

    if (argc<2 || argv[1] == NULL) {
        sslog_insert_property(universum, PROPERTY_HAS, "Hello world1");
    } else {
        sslog_insert_property(universum, PROPERTY_HAS, argv[1]);
    }

    if (sslog_node_insert_individual(node, universum) != SSLOG_ERROR_NO)
		printf("Individual can not be inserted\n");
	else
		printf("Individual inserted\n");

    sslog_node_leave(node);

    printf("\nKP leaves SS...\n");

    sslog_shutdown();

    return 0;
}
