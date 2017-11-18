//
//  pam.h
//  PortableAnyMap
//
//  Created by Mieszko Wawrzyniak on 18/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef pam_h
#define pam_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loger.h"
#include "errors.h"

/**
 Portable Any Map object
 */
typedef struct {
  unsigned int heigth;
  unsigned int width;
  unsigned int pixels_ammount;
} Headers;

typedef struct {
  Headers h;
  unsigned char grayscale;
  unsigned char *pixels;
} Pgm;

void read_pgm(Pgm *img, FILE *file);
void print_pgm(Pgm *img, FILE *file);

#endif /* pam_h */
