#include <elf.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#define DEBUG 0

int kill_header(void);
int kill_header()
{
    Elf64_Ehdr e_hdr;
    #if DEBUG > 0
    printf("ELF64 header size = %lu\n", sizeof(e_hdr));
    #endif
    FILE *f = NULL;
    f = fopen("/proc/self/maps","r");
    if(f == NULL) 
    {
        //break;
        exit(-1);
    }

    long long unsigned start = 0, end = 0;
    int retn = fscanf(f, "%llx-%llx", &start, &end);
    if(retn == -1)
    {
        printf("something went wrong when reading header");
        exit(-1);
    }
    fclose(f);

    #if DEBUG > 0
    printf("start addr\t= %llx\n (%llu)d\n", start, start);
    printf("end addr\t=%llx (%llu)d\n", end, end);
    #endif

    #if DEBUG > 0
    char *byte = (char*) start;
    printf("[*] Bytes: %02x %02x %02x %02x\n", *(char*)(byte),*(char*)(byte+1),*(char*)(byte+2),*(char*)(byte+3));
    #endif

    mprotect((void*)start, (size_t)(end - start), PROT_READ|PROT_WRITE|PROT_EXEC);
    memset((void*)start, 0, sizeof(e_hdr));
    mprotect((void*)start, (size_t)(end - start), PROT_READ|PROT_EXEC);

    #if DEBUG > 0
    printf("zeroed elf header\n");
    printf("[*] Bytes: %02x %02x %02x %02x\n", *(char*)(byte),*(char*)(byte+1),*(char*)(byte+2),*(char*)(byte+3));
    #endif
    return 0;
}
