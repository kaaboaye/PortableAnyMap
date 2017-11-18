//
//  pam.c
//  PortableAnyMap
//
//  Created by Mieszko Wawrzyniak on 18/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "pam.h"

void read_pgm(Pgm *img, FILE *file) {
  // Read magcick number
  char type[3];
  
  if (!fscanf(file, "%2s", type)) {
    loger(log_error, "Unable to read magick number from file.");
  }
  
  // Check if image has magick number "P2"
  if (strcmp("P2", type)) {
    loger(log_error, "Bad file format.");
  }
  
  // Read width header
  if (!fscanf(file, "%du", &img->h.width)) {
    loger(log_error, "Unable to read width header from file.");
  }
  
  // Read heigth header
  if (!fscanf(file, "%du", &img->h.heigth)) {
    loger(log_error, "Unable to read heigth header from file.");
  }
  
  // Read grayscale
  if (!fscanf(file, "%hhu", &img->grayscale)) {
    loger(log_error, "Unable to read grayscale from file.");
  }
  
  // Set pixels ammount
  img->h.pixels_ammount = img->h.width * img->h.heigth;
  
  // Read pixels
  unsigned char pixel;
  
  // Assign memory to the array of pixels
  img->pixels = malloc(img->h.pixels_ammount + 1);
  
  for (unsigned int i = 0; i < img->h.pixels_ammount; ++i) {
    // Read pixel
    if (!fscanf(file, "%hhu", &pixel)) {
      loger(log_error, "Unable to read grayscale from file.");
    }
    
    img->pixels[i] = pixel;
  }
  
  // Close the file
  fclose(file);
}

void print_pgm(Pgm *img, FILE *file) {
  // Print magick number
  if (!fprintf(file, "P2\n")) {
    loger(log_error, "Unable to save file.");
  }
  
  // Print width, height and grayscale
  fprintf(file, "%d %d\n%d\n", img->h.width, img->h.heigth, img->grayscale);
  
  // Print pixels
  unsigned char pixel;
  for (int i = 0; i < img->h.pixels_ammount; ++i) {
    // Add new lines at the end of rows
    if (i % img->h.width == 0) fprintf(file, "\n");
    
    pixel = img->pixels[i];
    fprintf(file, "%d\t", pixel);
  }
  
  // End file with new line character
  fprintf(file, "\n");
  
  // Close the file
  fclose(file);
}
