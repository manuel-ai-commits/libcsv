#define CSV_IMPLEMENTATION
#include "../csv.h"

/*
 * Row and col to experiment with 
*/
#define ROW_TO_MODIFY 10
#define COL_TO_MODIFY 9

int main () {
        
        /*
         * Create buffer and load csv data into it 
        */
        CSV_BUFFER *my_buffer = csv_create_buffer();
        printf("created buffer\n");
        csv_load(my_buffer, "examples/testlist.csv");
        
        /*
         * Print buffer (CSV data loaded)
        */
        printf("PRINT DATA:");
        print_buffer(my_buffer);
        
        /*
         * Play with setting fields
        */
        printf("loaded from file\n");
        csv_set_field(my_buffer, ROW_TO_MODIFY, COL_TO_MODIFY, "test");
        printf("set first field to \"test\"\n");
        /*
         * Save the changed data to ./examples/
        */
        csv_save("examples/testsave.csv", my_buffer);
        printf("saved buffer\n");
        char *my_string = malloc(ROW_TO_MODIFY + 1);
        /*
         * Play with getting fields
        */
        csv_get_field(my_string, ROW_TO_MODIFY, my_buffer, ROW_TO_MODIFY, COL_TO_MODIFY);
        printf("Got string = \"%s\"\n", my_string);
        /*
         * Always remember to free up the space allocated
        */
        csv_destroy_buffer(my_buffer);
        printf("destroyed buffer\n");
        free(my_string);
        printf("Free'd string\n");
        return 0;
}
