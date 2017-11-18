//
//  loger.h
//  PortableAnyMap
//
//  Created by Mieszko Wawrzyniak on 18/11/2017.
//  Copyright © 2017 Mieszko Wawrzyniak. All rights reserved.
//

#ifndef loger_h
#define loger_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "errors.h"

typedef enum {
  log_nothing,
  log_error,
  log_warning,
  log_info,
  log_everything
} log_type;

extern log_type exit_on;
extern log_type log_lvl;

void loger(log_type type, const char *message);

#endif /* loger_h */
