//
//  loger.c
//  PortableAnyMap
//
//  Created by Mieszko Wawrzyniak on 18/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#include "loger.h"

void loger(const log_type type, const char *message) {
  if (log_lvl < type) return;

  // Print type of the message
  switch (type) {
    case log_nothing:
      puts("[F] Nothing cannot be given to loger");
      exit(ILLEGAL);
      break;
      
    case log_error:
      printf("[E] ");
      break;
      
    case log_warning:
      printf("[W] ");
      break;
    case log_info:
      printf("[I] ");
      break;
      
    case log_everything:
      puts("[F] Everything cannot be given to loger");
      exit(ILLEGAL);
      break;
  }

  // Print message
  puts(message);
  
  if (exit_on >= type) exit(ERROR_EXIT);
}
