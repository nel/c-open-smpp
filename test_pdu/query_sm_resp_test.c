
/*
 * Copyright (C) 2006 Movilgate SRL.
 * File  : query_sm_resp_test.c
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

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>

#ifdef __linux__
#include <stdint.h>
#endif

#include "smpp34.h"
#include "smpp34_structs.h"
#include "smpp34_params.h"
#include "core.h"


int
main( int argc, char *argv[] )
{

    query_sm_resp_t a;
    query_sm_resp_t b;

    memset(&a, 0, sizeof(query_sm_resp_t));
    memset(&b, 0, sizeof(query_sm_resp_t));

    /* Init PDU ***********************************************************/
    b.command_length   = 0;
    b.command_id       = QUERY_SM_RESP;
    b.command_status   = ESME_ROK;
    b.sequence_number  = 1;
    snprintf( b.message_id, sizeof(b.message_id), "%s", "88898239379");
    snprintf( b.final_date, sizeof(b.final_date), "%s", "No se");
    b.message_state  = 1;
    b.error_code  = 4;

    doTest(QUERY_SM_RESP, &a, &b);
    return( 0 );
};
