#include <unistd.h>
#include "sepuku.h"
void sepuku(char*);
void sepuku(char *argv0)
{
    unlink(argv0);
}
