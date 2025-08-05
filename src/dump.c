#include "dump.h"

void dump_memory(void* ptr, int size){
    const unsigned char* p = ptr;
    int curr_size = 0; 
    
    printf("Address         Hexadecimal Values                                ASCII           \n");
    while (curr_size != size){
        //prints address 
        printf("%-16p", (void*)(p + curr_size));
        unsigned char buffer[16];
        int curr_bytes = 0;
        //prints hexadecimal values
        for (int i = 0; i < 16; i++){
            if (curr_size == size){
                break;
            }

            printf("%02x ", (unsigned char)p[curr_size]);
            buffer[i] = (unsigned char)p[curr_size];
            curr_size++;
            curr_bytes++;

            if (i == 7){
                printf(" ");
            }
        }
        
        int itrs;
        //short line
        if (curr_bytes != 16){
            int spacing = 49 - (curr_bytes * 3);
            //adds one to account for the added pad after 8 bytes 
            if (curr_bytes < 8){
                spacing++;
            }
            printf("%*s", spacing, "");
            itrs = curr_bytes; 
        } else {
            printf(" "); 
            itrs = 16;
        }

        //prints ascii characters
        for (int i = 0; i < itrs; i++){
            unsigned char c = buffer[i];
            putchar((c >= 32 && c <= 126) ? c : '.');
        }

        if (curr_size != size){
            printf("\n");
        }
    }
    printf("\n");
}

int main(){
    return 0;
}
