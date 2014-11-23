/*
 * return_code.h
 *
 * Copyright (c) 2014 - Sean R. Lang
 */

#ifndef _RETURN_CODE_H
#define _RETURN_CODE_H

typedef int ReturnCode;
typedef ReturnCode ErrorCode;

#define SLASH_SUCCESS	0
#define SLASH_ERROR		1
#define SLASH_FATAL		(-1)

#endif /*_RETURN_CODE_H*/
