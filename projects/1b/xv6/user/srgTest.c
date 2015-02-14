#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{
  printf(1,"SRGTEST!\n");
  printf(1,"The getpid()=%d\n",getpid());
  printf(1,"The getprocs()=%d\n",getprocs());
  exit();
}
