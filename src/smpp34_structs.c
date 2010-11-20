/*
 * Copyright (C) 2006 Movilgate SRL.
 * File  : smpp34_structs.c
 * Author: Raul Tremsal <rtremsal@movilgate.com>
 *
 * This file is part of libsmpp34 (c-open-smpp3.4 library).
 *
 * The libsmpp34 library is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU Lesser General Public License as 
 * published by the Free Software Foundation; either version 2.1 of the 
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public 
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License 
 * along with this library; if not, write to the Free Software Foundation, 
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA 
 *
 */
#include "smpp34_core.h"
#include "smpp34_structs.h"
#include "smpp34_params.h"

/* GLOBALS ********************************************************************/
int smpp34_errno;
char smpp34_strerror[2048];
char *ptrerror = NULL;

/* EXTERN *********************************************************************/
/* FUNCTIONS ******************************************************************/
