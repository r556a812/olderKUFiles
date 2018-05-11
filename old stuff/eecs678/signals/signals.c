#include <stdio.h>     /* standard I/O functions                         */
#include <stdlib.h>    /* exit                                           */
#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <string.h>
#include <signal.h>    /* signal name macros, and the signal() prototype */

/* first, define the Ctrl-C counter, initialize it with zero. */
int ctrl_c_count = 0;
int got_response = 0;
#define CTRL_C_THRESHOLD  5 

/* the Ctrl-C signal handler */
void catch_int(int sig_num)
{
  /* increase count, and check if threshold was reached */
  ctrl_c_count++;
  if (ctrl_c_count >= CTRL_C_THRESHOLD) {
    char answer[30];
    
    
    /* prompt the user to tell us if to really
    * exit or not */
    printf("\nReally exit? [Y/n]: ");
    
    alarm(5);
    
    fflush(stdout);
    fgets(answer, sizeof(answer), stdin);
    if (answer[0] == 'n' || answer[0] == 'N') {
      
      alarm(0);
      
      printf("\nContinuing\n");
      fflush(stdout);
      /* 
      * Reset Ctrl-C counter
      */
      ctrl_c_count = 0;
    }
    else {
      printf("\nExiting...\n");
      fflush(stdout);
      exit(0);
    }
  }
}

/* the Ctrl-Z signal handler */
void catch_tstp(int sig_num)
{
  /* print the current Ctrl-C counter */
  printf("\n\nSo far, '%d' Ctrl-C presses were counted\n\n", ctrl_c_count);
  fflush(stdout);
}

void catch_alarm()
{
  printf("\n\nUser taking too long to respond. Exiting ...\n\n");
  fflush(stdout);
  exit(0);
}

int main(int argc, char* argv[])
{
  struct sigaction sa;
  struct sigaction za;
  struct sigaction aa;
  
  sigset_t mask_set;  /* used to set a signal masking set. */
  sigfillset(&mask_set);
  sigdelset(&mask_set, SIGALRM);
  
  memset(&sa, 0, sizeof(struct sigaction));
  sa.sa_mask = mask_set;
  sa.sa_handler = catch_int;
  sigaction(SIGINT, &sa, NULL);
  
  memset(&za, 0, sizeof(struct sigaction));
  za.sa_mask = mask_set;
  za.sa_handler = catch_tstp;
  sigaction(SIGTSTP, &za, NULL);
  
  memset(&aa, 0, sizeof(struct sigaction));
  aa.sa_mask = mask_set;
  aa.sa_handler = catch_alarm;
  sigaction(SIGALRM, &aa, NULL);
  
  /* setup mask_set */
  
  /* set signal handlers */
  
  
  while (1)
  {
    pause();
  }
  
  return 0;
}

