
/*
 * Copyright (C) 2006 Movilgate SRL.
 * File  : tcp.c
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

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#include "esme.h"

int do_tcp_connect( xmlNodePtr p, int *server_socket ) {
    struct addrinfo hints, *servers_addr, *server_addr;
    int yes = 1; //solaris would prefer a char
    int res;
    
    char h[256];
    char port[256];
    GET_PROP_STR(h, p, "host");
    GET_PROP_STR(port, p, "port");
    
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;    //to use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;    // Only stream
    hints.ai_flags = AI_PASSIVE;        // Accept on any address or port
    hints.ai_protocol = IPPROTO_TCP;    //only TCP

    if ((res = getaddrinfo(NULL, port, &hints, &servers_addr)) != 0) {
        fprintf(stderr, "MPP server: getaddrinfo: %s\n", gai_strerror(res));
        return -1;
    }

    // loop through all the results and bind to the first we can
    for(server_addr = servers_addr; server_addr != NULL; server_addr = server_addr->ai_next) {
        if ((*server_socket = socket(server_addr->ai_family, server_addr->ai_socktype, server_addr->ai_protocol)) == -1)
        {
            perror("SMPP server: socket");
            continue;
        }

#ifndef WIN32
        if (setsockopt(*server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1)
        {
            perror("SMPP server: setsockopt");
            return -1;
        }
#endif
        if (connect(*server_socket, server_addr->ai_addr, server_addr->ai_addrlen) < 0)
        {
            close(*server_socket);
            perror("SMPP server: bind");
            continue;
        }
        break;
    }

    if (server_addr == NULL)  {
        fprintf(stderr, "SMPP server: failed to bind\n");
        return -1;
    }

    freeaddrinfo(servers_addr);
    return 0;
}

int do_tcp_close( int sock_tcp )
{

    close( sock_tcp );
    return( 0 );
};
