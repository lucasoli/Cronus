//====================================================================\\
//                   _____                                            ||
//                  /  __ \                                           ||
//                  | /  \/_ __ ___  _ __  _   _ ___                  ||
//                  | |   | '__/ _ \| '_ \| | | / __|                 ||
//                  | \__/\ | | (_) | | | | |_| \__ \                 ||
//                   \____/_|  \___/|_| |_|\__,_|___/                 ||
//                        Source - 2016                               ||
//====================================================================||
// = Arquivo:                                                         ||
// - timer.h                                                          ||
//====================================================================||
// = C�digo Base:                                                     ||
// - eAthena/Hercules/Cronus                                          ||
//====================================================================||
// = Sobre:                                                           ||
// Este software � livre: voc� pode redistribu�-lo e/ou modific�-lo   ||
// sob os termos da GNU General Public License conforme publicada     ||
// pela Free Software Foundation, tanto a vers�o 3 da licen�a, ou     ||
// (a seu crit�rio) qualquer vers�o posterior.                        ||
//                                                                    ||
// Este programa � distribu�do na esperan�a de que possa ser �til,    ||
//�mas SEM QUALQUER GARANTIA; mesmo sem a garantia impl�cita de       ||
//�COMERCIALIZA��O ou ADEQUA��O A UM DETERMINADO FIM. Veja a          ||
//�GNU General Public License para mais detalhes.                     ||
//                                                                    ||
// Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU      ||
// juntamente com este programa. Se n�o, veja:                        ||
// <http://www.gnu.org/licenses/>.                                    ||
//====================================================================//

#ifndef COMMON_TIMER_H
#define COMMON_TIMER_H

#include "config/cronus.h"

#define DIFF_TICK(a,b) ((a)-(b))
#define DIFF_TICK32(a,b) ((int32)((a)-(b)))

#define INVALID_TIMER (-1)

// timer flags
enum {
	TIMER_ONCE_AUTODEL = 0x01,
	TIMER_INTERVAL = 0x02,
	TIMER_REMOVE_HEAP = 0x10,
};

// Struct declaration

typedef int (*TimerFunc)(int tid, int64 tick, int id, intptr_t data);

struct TimerData {
	int64 tick;
	TimerFunc func;
	unsigned char type;
	int interval;

	// general-purpose storage
	int id;
	intptr_t data;
};


/*=====================================
* Interface : timer.h
* Generated by HerculesInterfaceMaker
* created by Susu
*-------------------------------------*/
struct timer_interface {

	/* funcs */
	int64 (*gettick) (void);
	int64 (*gettick_nocache) (void);

	int (*add) (int64 tick, TimerFunc func, int id, intptr_t data);
	int (*add_interval) (int64 tick, TimerFunc func, int id, intptr_t data, int interval);
	const struct TimerData *(*get) (int tid);
	int (*delete) (int tid, TimerFunc func);

	int64 (*addtick) (int tid, int64 tick);
	int64 (*settick) (int tid, int64 tick);

	int (*add_func_list) (TimerFunc func, char* name);

	unsigned long (*get_uptime) (void);

	int (*perform) (int64 tick);
	void (*init) (void);
	void (*final) (void);
};

#ifdef CRONUS_CORE
void timer_defaults(void);
#endif // CRONUS_CORE

HPShared struct timer_interface *timer;

#endif /* COMMON_TIMER_H */
