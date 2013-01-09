/* -------------------------------------------------------------------------
* tpool.h - htun thread pool defs
* -------------------------------------------------------------------------
*/

#ifndef _TPOOL_H_
#define _TPOOL_H_

#include  <stdio.h>
#include  <pthread.h>

/*
* a generic thread pool creation routines
*/

typedef struct tpool_work{
  void (*handler_routine)();
  void *arg;
  struct tpool_work *next;                  /*任务链表*/
} tpool_work_t;

typedef struct tpool{
  int num_threads;
  int max_queue_size;

  int do_not_block_when_full;
  pthread_t *threads;
  int cur_queue_size;
  tpool_work_t *queue_head;
  tpool_work_t *queue_tail;
  pthread_mutex_t queue_lock;
  pthread_cond_t queue_not_full;
  pthread_cond_t queue_not_empty;
  pthread_cond_t queue_empty;
  int queue_closed;
  int shutdown;
} tpool_t;

/*
* returns a newly created thread pool   初始化连接池
*/
extern tpool_t *tpool_init(int num_worker_threads,
    int max_queue_size, int do_not_block_when_full);

/*
* returns -1 if work queue is busy
* otherwise places it on queue for processing, returning 0
*
* the routine is a func. ptr to the routine which will handle the
* work, arg is the arguments to that same routine
    routine 为函数指针  用于处理具体业务的函数实现  arg为参数

*/
extern int tpool_add_work(tpool_t *pool, void  (*routine)(), void *arg);

/*
* cleanup and close,
* if finish is set the any working threads will be allowd to finish
*/
extern int tpool_destroy(tpool_t *pool, int finish);

/* private */
/*extern void tpool_thread(tpool_t *pool); */


#endif /* _TPOOL_H_ */

