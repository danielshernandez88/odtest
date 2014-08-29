/* main.c - main function file
 * Copyright (C) 2014 Adrian Alonso <aalonso00@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with self library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>

#define SIZE_ROW	0xF

int
main(int argc, char **argv)
{


    FILE *fd;
    char *file = NULL;
    char buff[16];
    char car;
    char n; 
    int row=0;
    char cad[10];
    int i=0;

    if(argc != 2)
    {
        printf ("Usage: %s <file>\n", argv[0]);
        exit (1);
    }

    file = argv[1];

    fd = fopen(file, "r");

    if(fd < 0)
    {
        printf ("Error");
        exit(1);
    }
    else {
		printf("%.6x ",row);
		do{
			fread(&car, sizeof(char), 1, fd);
			printf("%.2x ",car);
			if(car == '\n'){
				if(!feof(fd))
				buff[i] = '.';
			}
			else
				buff[i] = car;
			if(i<SIZE_ROW){
				i++;
			}
			else{
				i=0;
				printf(">%s<\n",&buff[0]);
				row += 0x10;
				printf("%.6x ",row);
			}
		}
		while(!feof(fd));
		for(n=i; n<=SIZE_ROW;n++){
			printf("   ");
			buff[n-1] = 0;
		}
		printf(">%s<\n",&buff[0]);
		printf("\n");
    }

    /* Print complete file content following od hex format */
    /* od -A x -t x1z -v file.dat */

    close (fd);
}
