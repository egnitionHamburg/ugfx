/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#ifndef _GOS_ECOS_H
#define _GOS_ECOS_H

#if GFX_USE_OS_ECOS

#include <cyg/hal/hal_arch.h>
#include <cyg/kernel/kapi.h>
#include <stdlib.h>

/*===========================================================================*/
/* Type definitions                                                          */
/*===========================================================================*/

#define gDelayNone			0
#define gDelayForever		0xFFFFFFFF

typedef cyg_ucount32		gDelay;
typedef cyg_tick_count_t	gTicks;
typedef cyg_count32 		gSemcount;
typedef void				gThreadreturn;
typedef cyg_addrword_t		gThreadpriority;
typedef cyg_handle_t		gfxThreadHandle;

#define MAX_SEMAPHORE_COUNT			0x7FFFFFFF
#define gThreadpriorityLow				(CYGNUM_KERNEL_SCHED_PRIORITIES-2)
#define gThreadpriorityNormal				(CYGNUM_KERNEL_SCHED_PRIORITIES/2)
#define gThreadpriorityHigh				0

#define DECLARE_THREAD_STACK(name, sz)			struct { cyg_thread t; unsigned char stk[(sz) & ~3]; } name[1]
#define DECLARE_THREAD_FUNCTION(fnName, param)	gThreadreturn fnName(cyg_addrword_t param)
#define THREAD_RETURN(retval)

typedef struct {
	cyg_sem_t	sem;
	gSemcount	limit;
	} gfxSem;

typedef cyg_mutex_t		gfxMutex;


/*===========================================================================*/
/* Function declarations.                                                    */
/*===========================================================================*/

#define gfxSystemTicks()			cyg_current_time()
#define gfxExit()					exit(0)
#define gfxHalt(msg)				exit(-1)
#define gfxYield()					cyg_thread_yield()

#define gfxMillisecondsToTicks(ms)	(((ms)*(CYGNUM_HAL_RTC_DENOMINATOR*1000))/(CYGNUM_HAL_RTC_NUMERATOR/1000))
void gfxSleepMilliseconds(gDelay ms);
void gfxSleepMicroseconds(gDelay ms);

#define gfxAlloc(sz)					malloc(sz)
#define gfxFree(ptr)					free(ptr)
#define gfxRealloc(ptr, oldsz, newsz)	realloc(ptr, newsz)

#define gfxSystemLock()					cyg_scheduler_lock()
#define gfxSystemUnlock()				cyg_scheduler_unlock()

#define gfxMutexInit(pmutex)			cyg_mutex_init(pmutex)
#define gfxMutexExit(pmutex)			cyg_mutex_unlock(pmutex)
#define gfxMutexDestroy(pmutex)			cyg_mutex_destroy(pmutex)
#define gfxMutexEnter(pmutex)			cyg_mutex_lock(pmutex)

void gfxSemInit(gfxSem *psem, gSemcount val, gSemcount limit);
void gfxSemDestroy(gfxSem *psem);
gBool gfxSemWait(gfxSem *psem, gDelay ms);
gBool gfxSemWaitI(gfxSem *psem);
void gfxSemSignal(gfxSem *psem);
void gfxSemSignalI(gfxSem *psem);

gfxThreadHandle gfxThreadCreate(void *stackarea, size_t stacksz, gThreadpriority prio, DECLARE_THREAD_FUNCTION((*fn),p), void *param);
#define gfxThreadWait(thread)		NOTIMPLEMENTED_YET
#define gfxThreadMe()				cyg_thread_self()
#define gfxThreadClose(thread)		(void)thread

#endif /* GFX_USE_OS_ECOS */
#endif /* _GOS_ECOS_H */
