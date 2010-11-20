#ifndef SMPP34_CORE_H
#define SMPP34_CORE_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif //HAVE_CONFIG_H

#include <stdio.h>
#include <string.h>
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif //HAVE_MALLOC_H
#include <sys/types.h>
#include <netinet/in.h>

#ifdef __linux__
#include <stdint.h>
#endif //__linux__

#include "smpp34.h"

#endif //SMPP34_CORE_H