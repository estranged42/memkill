#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

main( int argc, char *argv[]) {
  if (argc != 3) {
    printf("usage: %s <max memory size in MB> <duration in sec>\n", argv[0]);
    return -1;
  }
  
  unsigned long long maxMem = atoi(argv[1]);
  maxMem *= 1024;
  maxMem *= 1024;
  int duration = atoi(argv[2]);
  int steps = duration / 5;
  int mySize = maxMem / steps;

  char continueString[20];

  printf("memkill will slowly consume all memory on this system!\n");
  printf("Max Memory: %llu (%s), %i steps over %i seconds.\n", maxMem, argv[1], steps, duration);
  puts("Are you sure you want to continue? [y/N] ");
  scanf("%s", &continueString);

  if (strcmp(continueString, "y") == 0 ||
      strcmp(continueString, "Y") == 0)
  {
    // Run the program
    printf("Ok, you asked for it!\n");
    
    unsigned long long totalSize = 0;
    
    int *a;
    while (1) {
    
      if (totalSize < maxMem) {
        a = (int *)malloc(mySize);
        memset(a, 0x0, mySize);
      
        totalSize += mySize;
      
        printf("Total Memory Size: %llu MB\n", totalSize / 1024 / 1024);
    
      } else {
        printf("Max Memory Reached: %llu MB. ctrl-c to exit\n", totalSize / 1024 / 1024);
      }

      struct timespec tim;
      tim.tv_sec = 5;
      tim.tv_nsec = 0;
  
      if(nanosleep(&tim , NULL) < 0 )   
      {
        printf("Nano sleep system call failed \n");
        return -1;
      }

    }
    
  }
  
  return 0;
}
