#include "dump.h"

void dump_memory(void* ptr, int size){
    const unsigned char* p = ptr;
    int curr_size = 0; 
    
    printf("Address         Hexadecimal Values                               ASCII           \n");
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
        }
       
        if (curr_size % 16 != 0){
            int space = (16 - (curr_size % 16)) * 3;
            printf("%*s", space, "");
        } 

        //prints ascii characters
        int itrs = curr_size % 16 == 0 ? 16 : curr_size % 16;
        printf(" ");
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
    char str[] = "Hello World! So good to meet you!\n";
    int integers[] = {1,2,3,4,5,6,7,8,9,10};
    
    dump_memory(&integers, sizeof(integers));
    return 0;
}
