/**
 * @file execute.c
 *
 * @brief Implements interface functions between Quash and the environment and
 * functions that interpret an execute commands.
 *
 * @note As you add things to this file you may want to change the method signature 
 */

#include "execute.h"

#include <stdio.h>

#include "quash.h"
#include "command.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
//#include "deque.h"


// Remove this and all expansion calls to it
/**
 * @brief Note calls to any function that requires implementation
 */
#define IMPLEMENT_ME()                                                  \
  printf("IMPLEMENT ME: %s(line %d): %s()\n", __FILE__, __LINE__, __FUNCTION__)

/***************************************************************************
 * Interface Functions
 ***************************************************************************/

/*typedef struct Job_Que 
{
  int job_id;
  char* cmd;
} Job_Que;

IMPLEMENT_DEQUE_STRUCT(Jobs, Job_Que);
IMPLEMENT_DEQUE(Jobs, Job_Que);*/

pid_t pid;

//Jobs jobs;

// Return a string containing the current working directory.
char* get_current_directory(bool* should_free) {
  // TODO: Get the current working directory. This will fix the prompt path.
  // HINT: This should be pretty simple
  char* the_cwd = malloc(1024);
  getcwd(the_cwd, 1024);

  // Change this to true if necessary
  *should_free = true;

  return the_cwd;
}

// Returns the value of an environment variable env_var
const char* lookup_env(const char* env_var) {
  // TODO: Lookup environment variables. This is required for parser to be able
  // to interpret variables from the command line and display the prompt
  // correctly
  // HINT: This should be pretty simple
 const char* buf = getenv(env_var);

  return buf;
}

// Sets the environment variable env_var to the value val
void write_env(const char* env_var, const char* val) {
  // TODO: Write environment variables
  // HINT: This should be pretty simple
  if (setenv(env_var, val, 1) == -1)
  {
    printf(strerror(errno));
    fflush(stdout);
  }
}

// Check the status of background jobs
void check_jobs_bg_status() {
  // TODO: Check on the statuses of all of the background jobs
 // IMPLEMENT_ME();

  // TODO: Once jobs are implemented, uncomment and fill the following line
  // print_job_bg_complete(job_id, pid, cmd);
}

// Prints the job id number, the process id of the first process belonging to
// the Job, and the command string associated with this job
void print_job(int job_id, pid_t pid, const char* cmd) {
  printf("[%d]\t%8d\t%s\n", job_id, pid, cmd);
  fflush(stdout);
}

// Prints a start up message for background processes
void print_job_bg_start(int job_id, pid_t pid, const char* cmd) {
  printf("Background job started: ");
  fflush(stdout);
  print_job(job_id, pid, cmd);
}

// Prints a completion message followed by the print job
void print_job_bg_complete(int job_id, pid_t pid, const char* cmd) {
  printf("Completed: \t");
  fflush(stdout);
  print_job(job_id, pid, cmd);
}

/***************************************************************************
 * Functions to process commands
 ***************************************************************************/
// Run a program reachable by the path environment variable, relative path, or
// absolute path
void run_generic(GenericCommand cmd) {
  // Print an array of strings. The `str` array is a NULL terminated (last
  // character pointer is always NULL) list of strings. The first element in the
  // array is the executable
  char** const str = cmd.args;

  // TODO: Remove warning silencers
  

  // TODO: Implement run generic
  
  pid = fork();
  int status;
  if (pid == 0)
  {
  execvp(str[0], str);
  exit(0);
  }
   if ((waitpid(pid, &status, 0)) == -1) {
    fprintf(stderr, "Process 1 encountered an error. ERROR%d", errno);
    fflush(stdout);
  }

}

// Print strings
void run_echo(EchoCommand cmd) {
  // Print an array of strings. The args array is a NULL terminated (last
  // character pointer is always NULL) list of strings.
  char** str = cmd.args;

  // TODO: Implement echo
  for (int i = 0; str[i] != NULL; ++i)
  {
    printf("%s", str[i]);
    printf(" ");
  }
  printf("\n");
  fflush(stdout);

}

// Sets an environment variable
void run_export(ExportCommand cmd) {
  // Write an environment variable
  const char* env_var = cmd.env_var;
  const char* val = cmd.val;
  write_env(env_var, val);

  // TODO: Implement export.
  // HINT: This should be quite simple.
}

// Changes the current working directory
void run_cd(CDCommand cmd) {
  // TODO: Change directory
  // TODO: Update PWD and optionally update OLD_PWD
  const char* path = cmd.dir;
  if (path == NULL)
  {
    char* home = getenv("HOME");
    chdir(home);
  }
  else
  {
    if (chdir(path) == -1)
    {
      perror("Error");
      fflush(stdout);
    }
  }

  bool should_free = true;
  char* pwd = get_current_directory(&should_free);
  char* env = "PWD";
  
  write_env(env, pwd);

  free(pwd);
}

// Sends a signal to all processes contained in a job
void run_kill(KillCommand cmd) {
  int signal = cmd.sig;
  int job_id = cmd.job;

  // TODO: Kill a background job
  kill(job_id, signal);
}


// Prints the current working directory to stdout
void run_pwd() {
  // TODO: Print the current working directory
  bool should_free = true;
  char* pwd = get_current_directory(&should_free);
  
  printf("%s", pwd);
  printf("\n");
  
  free(pwd);
  
  // Flush the buffer before returning
  fflush(stdout);
}

// Prints all background jobs currently in the job list to stdout
void run_jobs() {
  // TODO: Print background jobs
  /*if(length_Jobs(&jobs) != 0)
  {
    
    int si = length_Jobs(&jobs);
    Job_Que* arr = as_array_Jobs(&jobs, NULL);
    for(int i = 0; i < si; i++)
    {
      int jobid = i;
      char* cmdline = arr[i].cmd;
    //int jobid = peek_front_Jobs(&jobs).job_id;
    //char* cmdline = peek_front_Jobs(&jobs).cmd;
    printf("[%d]\t%8d\t%s\n", jobid, pid, cmdline);
    printf("\n");
    fflush(stdout);
    }
  }*/
}

/***************************************************************************
 * Functions for command resolution and process setup
 ***************************************************************************/

/**
 * @brief An example of how to resolve a Command type from a @a Command union.
 *
 * You will need some variant(s) of this switch structure to direct the command
 * statements to their correct caller. Probably you won't want all commands
 * accessible from a single function like this.
 *
 * @param cmd The Command to try to run
 *
 * @sa Command
 */

void example_run_command(Command cmd) {
  CommandType type = get_command_type(cmd);

  switch (type) {
  case GENERIC:
    run_generic(cmd.generic);
    break;

  case ECHO:
    run_echo(cmd.echo);
    break;

  case EXPORT:
    run_export(cmd.export);
    break;

  case CD:
    run_cd(cmd.cd);
    break;

  case KILL:
    run_kill(cmd.kill);
    break;

  case PWD:
    run_pwd();
    break;

  case JOBS:
    run_jobs();
    break;

  case EXIT:
  case EOC:
    break;

  default:
    fprintf(stderr, "Unknown command type: %d\n", type);
  }
}

/**
 * @brief Create a process centered around the @a Command in the @a
 * CommandHolder setting up redirects and pipes where needed
 *
 * @note Not all commands should be run in the child process. A few need to
 * change the quash process in some way
 *
 * @param holder The CommandHolder to try to run
 *
 * @sa Command CommandHolder
 */
void create_process(CommandHolder holder) {
  // Read the flags field from the parser
  bool p_in  = holder.flags & PIPE_IN;
  bool p_out = holder.flags & PIPE_OUT;
  bool r_in  = holder.flags & REDIRECT_IN;
  bool r_out = holder.flags & REDIRECT_OUT;
  bool r_app = holder.flags & REDIRECT_APPEND;

  // TODO: Remove warning silencers
  (void) p_in;  // Silence unused variable warning
  (void) p_out; // Silence unused variable warning
  (void) r_in;  // Silence unused variable warning
  (void) r_out; // Silence unused variable warning
  (void) r_app; // Silence unused variable warning

  // TODO: Setup pipes and redirects
 // IMPLEMENT_ME();
 
 
 CommandType type = get_command_type(holder.cmd);
  switch (type) {
  case GENERIC:
    run_generic(holder.cmd.generic);
    break;

  case ECHO:
    run_echo(holder.cmd.echo);
    break;

  case EXPORT:
    run_export(holder.cmd.export);
    break;

  case CD:
    run_cd(holder.cmd.cd);
    break;

  case KILL:
    run_kill(holder.cmd.kill);
    break;

  case PWD:
    run_pwd();
    break;

  case JOBS:
    run_jobs();
    break;

  case EXIT:
  case EOC:
    break;

  default:
    fprintf(stderr, "Unknown command type: %d\n", type);
  }


 

 

}

// Run a list of commands 
void run_script(CommandHolder* holders) {
  if (holders == NULL)
    return;

  check_jobs_bg_status();

  if (get_command_holder_type(holders[0]) == EXIT &&
      get_command_holder_type(holders[1]) == EOC) {
    end_main_loop();
    return;
  }
  
  CommandType type;
 /* static bool init_job = false;
  if(init_job == false)
  {
    jobs = new_Jobs(10);
    init_job = true;
  }*/

  // Run all commands in the `holder` array
  for (int i = 0; (type = get_command_holder_type(holders[i])) != EOC; ++i)
    create_process(holders[i]);

  if (!(holders[0].flags & BACKGROUND)) {
    // Not a background Job
    // TODO: Wait for all processes under the job to complete
   // IMPLEMENT_ME();
  }
  else {
    // A background job.
    // TODO: Push the new job to the job queue
   /* Job_Que nwjob;
    nwjob.cmd = get_command_string(&holders[0]);
    nwjob.job_id = length_Jobs(&jobs) + 1;
    push_front_Jobs(&jobs, nwjob);

    // TODO: Once jobs are implemented, uncomment and fill the following line
    print_job_bg_start(nwjob.job_id, pid, nwjob.cmd);*/
  }
}
