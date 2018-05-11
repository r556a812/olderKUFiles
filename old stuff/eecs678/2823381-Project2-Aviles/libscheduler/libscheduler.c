/** @file libscheduler.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libscheduler.h"
#include "../libpriqueue/libpriqueue.h"


/**
  Stores information making up a job to be scheduled including any statistics.

  You may need to define some global variables or a struct to store your job queue elements. 
*/
typedef struct _job_t
{
  int job_number;
  int time;
  int running_time;
  int priority;
  int remaining_time;
  int time2;
} job_t;

int preemptFlag;
scheme_t compare;
priqueue_t q;
int size;
job_t** coreArray;
int num_jobs;
int last_job_added;
int turn_time;
int waiting_time;
int response_time;

int fcfsComparer(const void * a, const void * b)
{
  return 1;
}

int sjfComparer(const void * a, const void * b)
{
  const job_t * j1 = a;
  const job_t * j2 = b;
  int a1 = j1->running_time;
  int b1 = j2->running_time;
  return(a1-b1);
}

int psjfComparer(const void * a, const void * b)
{
  const job_t * j1 = a;
  const job_t * j2 = b;
  int a1 = j1->remaining_time;
  int b1 = j2->remaining_time;
  return(a1-b1);

}

int priComparer(const void * a, const void * b)
{
  const job_t * j1 = a;
  const job_t * j2 = b;
  int a1 = j1->priority;
  int b1 = j2->priority;
  if (a1-b1 == 0)
  {
    a1 = j1->time;
    b1 = j2->time;
  }
  return(a1-b1);
}

int ppriComparer(const void * a, const void * b)
{
  const job_t * j1 = a;
  const job_t * j2 = b;
  int a1 = j1->priority;
  int b1 = j2->priority;
  return(a1-b1);

}

int rrComparer(const void * a, const void * b)
{
  return 1;
}



/**
  Initalizes the scheduler.
 
  Assumptions:
    - You may assume this will be the first scheduler function called.
    - You may assume this function will be called once once.
    - You may assume that cores is a positive, non-zero number.
    - You may assume that scheme is a valid scheduling scheme.

  @param cores the number of cores that is available by the scheduler. These cores will be known as core(id=0), core(id=1), ..., core(id=cores-1).
  @param scheme  the scheduling scheme that should be used. This value will be one of the six enum values of scheme_t
*/
void scheduler_start_up(int cores, scheme_t scheme)
{
  coreArray = malloc(cores* sizeof coreArray[0]);
  size = cores;
  compare = scheme;
  last_job_added = 0;
last_job_added = -1;
  num_jobs = 0;
  waiting_time = 0;
  response_time = 0;
  turn_time = 0;

  for (int i = 0; i < size; i++)
  {
    coreArray[i] = NULL;
  }
  
  switch(scheme)
  {
    case FCFS:
      priqueue_init(&q, fcfsComparer);
      break;

    case SJF:
      priqueue_init(&q, sjfComparer);
      break;

    case PSJF:
      priqueue_init(&q, psjfComparer);
      break;

    case PRI:
      priqueue_init(&q, priComparer);
      break;

    case PPRI:
      priqueue_init(&q, ppriComparer);
      break;

    case RR:
      priqueue_init(&q, rrComparer);
      break;
  }
}


/**
  Called when a new job arrives.
 
  If multiple cores are idle, the job should be assigned to the core with the
  lowest id.
  If the job arriving should be scheduled to run during the next
  time cycle, return the zero-based index of the core the job should be
  scheduled on. If another job is already running on the core specified,
  this will preempt the currently running job.
  Assumptions:
    - You may assume that every job wil have a unique arrival time.

  @param job_number a globally unique identification number of the job arriving.
  @param time the current time of the simulator.
  @param running_time the total number of time units this job will run before it will be finished.
  @param priority the priority of the job. (The lower the value, the higher the priority.)
  @return index of core job should be scheduled on
  @return -1 if no scheduling changes should be made. 
 
 */
int scheduler_new_job(int job_number, int time, int running_time, int priority)
{
  //Set variables for the new job
  job_t* job = malloc(sizeof(job_t));
  job->job_number = job_number;
  job->time = time;
  job->running_time = running_time;
  job->priority = priority;
  job->remaining_time = running_time;

  if(last_job_added == -1)
  {
    last_job_added = time;
  }
  else
  {
    last_job_added = time - last_job_added;
  }
  
  response_time = -1;
  num_jobs++;
  response_time = response_time + last_job_added;

  

  for(int a = 0; a < size; a++)
  {
    if(coreArray[a] != NULL && coreArray[a]->time2 != time)
    {
      job_t * temp = malloc(sizeof(job_t));
      temp = coreArray[a];
      temp->remaining_time = temp->remaining_time - last_job_added;
    }
  }



  //Insert the new job into the queue
  int spot;
  spot = priqueue_offer(&q, job);

  //printf("%d\n\n", ((job_t *)priqueue_peek(&q))->job_number);
  //printf("%d\n\n", ((job_t *)priqueue_peek(&q))->remaining_time);


  

  //Check for any available cores and which core to assign the new job to.
  int place = -1;
  int avail = 0;
  for(int i = 0; i < size; i++)
  {
    if (coreArray[i] == NULL)
    {
      avail++;
    }
    if (coreArray[i] == NULL && place == -1)
    {
      place = i;
    }
  }   

  //Switch case to determine what to do with the job
   switch(compare)
  {
    case FCFS:
    case SJF:
    case PRI:
    case RR:
      if (place == -1)
      {
        return place;
      }
      else
      {
        if (avail < spot)
        {
          return -1;
        }
        else
        {
          waiting_time += last_job_added;
          coreArray[place] = job;
          job_t checking = *(job_t *)priqueue_poll(&q);
          return place;
        }
      }

    case PSJF:;
      if (place == -1 || avail < spot)
      {
        for (int j = 0; j < size; j++)
        {
          
          if (coreArray[j]->remaining_time > job->remaining_time)
          {
            waiting_time += last_job_added;
            job_t * job1 = malloc(sizeof(job_t));
            job_t * job2 = malloc(sizeof(job_t));
            job2 = priqueue_poll(&q);
            job1 = coreArray[j];
            priqueue_offer(&q, job1);
            coreArray[j] = job;
            return j;
          }
        }
        return -1;
      }
      else
      {
        waiting_time += last_job_added;
        coreArray[place] = job;
        job_t checking = *(job_t *)priqueue_poll(&q);
        return place;
      }


    case PPRI:;
      if(place != -1)
      {
        waiting_time += last_job_added;
        coreArray[place] = job;
        job_t checking = *(job_t *)priqueue_poll(&q);
        return place;
      }
      else if (place == -1 || avail < spot)
      {
        int low = -1;
        for (int k = 0; k < size; k++)
        {
           
          if(coreArray[k] != NULL)
          {
            if(coreArray[k]->priority > low)
            {
              low = k;
            }
          }

        }

        if (coreArray[low]->priority > job->priority)
          {
            waiting_time += last_job_added;
            job_t * job1 = malloc(sizeof(job_t));
            job_t * job2 = malloc(sizeof(job_t));
            job1 = coreArray[low];
            priqueue_offer(&q, job1);
            job2 = (job_t *)priqueue_poll(&q);
            coreArray[low] = job2;
            return low;
          }
          else
          {
            return -1;
          }

          
          
          
          
      }
      else
      {
        waiting_time += last_job_added;
        coreArray[place] = job;
        job_t checking = *(job_t *)priqueue_poll(&q);
        return place;
      }

      default :
        return place;
  }
       

}


/**
  Called when a job has completed execution.
 
  The core_id, job_number and time parameters are provided for convenience. You may be able to calculate the values with your own data structure.
  If any job should be scheduled to run on the core free'd up by the
  finished job, return the job_number of the job that should be scheduled to
  run on core core_id.
 
  @param core_id the zero-based index of the core where the job was located.
  @param job_number a globally unique identification number of the job.
  @param time the current time of the simulator.
  @return job_number of the job that should be scheduled to run on core core_id
  @return -1 if core should remain idle.
 */
int scheduler_job_finished(int core_id, int job_number, int time)
{
  waiting_time += time - coreArray[core_id]->time - coreArray[core_id]->running_time;
  turn_time += time - coreArray[core_id]->time;
  coreArray[core_id] = NULL;
    
  /* int is_same = 0;

  for (int i = 0; i < size; i++)
    {
      if (coreArray[i] != NULL && temp->job_number == coreArray[i]->job_number)
      {
        is_same = 1;
      }
    }*/




  
  //Return -1 if queue is empty, otherwise return the next job number
	if (priqueue_size(&q) == 0)
  {
    last_job_added = -1;

    return -1;
  }
  /*else if(is_same == 1)
  {
    if (priqueue_size(&q) == 1)
    {
      return -1;
    }
    else
    {
      waiting_time += time - last_job_added;
      temp = (job_t *)priqueue_poll(&q);
      coreArray[core_id] = temp;
      return(temp->job_number);
    }
  }*/
  else
  {
    job_t *temp = malloc(sizeof(job_t));
    temp = (job_t *)priqueue_poll(&q);
    coreArray[core_id] = temp;
    temp->time2 = time;
   
    return (temp->job_number);
  }
}


/**
  When the scheme is set to RR, called when the quantum timer has expired
  on a core.
 
  If any job should be scheduled to run on the core free'd up by
  the quantum expiration, return the job_number of the job that should be
  scheduled to run on core core_id.

  @param core_id the zero-based index of the core where the quantum has expired.
  @param time the current time of the simulator. 
  @return job_number of the job that should be scheduled on core cord_id
  @return -1 if core should remain idle
 */
int scheduler_quantum_expired(int core_id, int time)
{
  job_t* job1 = malloc(sizeof(job_t));
  job1 = coreArray[core_id];
  priqueue_offer(&q, job1);
  coreArray[core_id] = NULL;
  
  if (priqueue_size(&q) == 0)
  {
    return (-1);
  }
  else
  {
    job_t* job2 = malloc(sizeof(job_t));
    job2 = (job_t *)priqueue_poll(&q);
    coreArray[core_id] = job2;
    
    return (job2->job_number);
  }
}


/**
  Returns the average waiting time of all jobs scheduled by your scheduler.

  Assumptions:
    - This function will only be called after all scheduling is complete (all jobs that have arrived will have finished and no new jobs will arrive).
  @return the average waiting time of all jobs scheduled.
 */
float scheduler_average_waiting_time()
{
  float w_time = waiting_time/num_jobs;
	return w_time;
}


/**
  Returns the average turnaround time of all jobs scheduled by your scheduler.

  Assumptions:
    - This function will only be called after all scheduling is complete (all jobs that have arrived will have finished and no new jobs will arrive).
  @return the average turnaround time of all jobs scheduled.
 */
float scheduler_average_turnaround_time()
{
  float t_time = turn_time/num_jobs;
	return t_time;
}


/**
  Returns the average response time of all jobs scheduled by your scheduler.

  Assumptions:
    - This function will only be called after all scheduling is complete (all jobs that have arrived will have finished and no new jobs will arrive).
  @return the average response time of all jobs scheduled.
 */
float scheduler_average_response_time()
{
  float r_time = response_time/num_jobs;
	return r_time;
}


/**
  Free any memory associated with your scheduler.
 
  Assumptions:
    - This function will be the last function called in your library.
*/
void scheduler_clean_up()
{
  
}


/**
  This function may print out any debugging information you choose. This
  function will be called by the simulator after every call the simulator
  makes to your scheduler.
  In our provided output, we have implemented this function to list the jobs in the order they are to be scheduled. Furthermore, we have also listed the current state of the job (either running on a given core or idle). For example, if we have a non-preemptive algorithm and job(id=4) has began running, job(id=2) arrives with a higher priority, and job(id=1) arrives with a lower priority, the output in our sample output will be:

    2(-1) 4(0) 1(-1)  
  
  This function is not required and will not be graded. You may leave it
  blank if you do not find it useful.
 */
void scheduler_show_queue()
{
 if(priqueue_size(&q) != 0)
  {
    job_t * temp = malloc(sizeof(job_t));

    for (int i = 0; i < priqueue_size(&q); i++)
    {
      temp = (job_t *)priqueue_at(&q, i);
      printf("%d  ", temp->job_number);
    }
  }
}
