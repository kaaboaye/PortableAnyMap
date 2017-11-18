//
//  manipulators.c
//  PortableAnyMap
//
//  Created by Mieszko Wawrzyniak on 18/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "manipulators.h"

void Pgm_negative(Pgm *img) {
  for (unsigned int i = 0; i < img->h.pixels_ammount; ++i) {
    img->pixels[i] = img->grayscale - img->pixels[i];
  }
}
