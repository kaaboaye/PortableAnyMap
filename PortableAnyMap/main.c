//
//  main.c
//  PortableAnyMap
//
//  Created by Mieszko Wawrzyniak on 18/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

#include "pam.h"
#include "manipulators.h"
#include "loger.h"

// logger configuration
log_type exit_on = log_error;
log_type log_lvl = log_everything;

int main(int argc, const char * argv[]) {
  Pgm img;
  FILE *input;
  FILE *output;
  
  switch (argc) {
    case 1:
      input = stdin;
      output = stdout;
      break;
      
    case 2:
      if ((input = fopen(argv[1], "r")) == NULL) {
        loger(log_error, "Unable to open input file.");
      }
      
      output = stdout;
      break;
      
    case 3:
      if ((input = fopen(argv[1], "r")) == NULL) {
        loger(log_error, "Unable to open input file.");
      }
      if ((output = fopen(argv[2], "w")) == NULL) {
        loger(log_error, "Unable to open input file.");
      }
      break;
      
    default:
      loger(log_error, "To many arguments");
      exit(ERROR_EXIT);
      break;
  }
  
  read_pgm(&img, input);
  
  Pgm_negative(&img);
  
  print_pgm(&img, output);
  
  return 0;
}
