/*
 * moduleUtil.h
 *
 *  Created on: 29 giu 2021
 *      Author: paoloc
 */

#ifndef MODULEUTIL_H_
#define MODULEUTIL_H_

#include "stdint.h"

typedef struct {
	void (*Run)(void);
	void (*Update)(void);
}ModuleTypDef;

#endif /* MODULEUTIL_H_ */
