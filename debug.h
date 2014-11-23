/*
 * debug.h
 *
 * Copyright (c) 2014 - Sean R. Lang
 */

#ifndef _DEBUG_H
#define _DEBUG_H

#ifdef DEBUG
	#define PD(...)		fprintf(stderr, __VA_ARGS__)
#else
	#define PD(x)
#endif

#endif /*_DEBUG_H*/
