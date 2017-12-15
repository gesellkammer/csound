/*
    compile_ops.h:

    Copyright (C) 2013 by Victor Lazzarini

    This file is part of Csound.

    The Csound Library is free software; you can redistribute it
    and/or modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    Csound is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with Csound; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
    02111-1307 USA
*/

#include <csoundCore.h>

typedef struct _compile {
  OPDS h;
  MYFLT *res;
  MYFLT *str;
  MYFLT *ktrig;
}COMPILE;

typedef struct _retval {
  OPDS h;
  MYFLT *ret;
} RETVAL;

int compile_orc_i(CSOUND *csound, COMPILE *c);
int compile_str_i(CSOUND *csound, COMPILE *c);
int compile_csd_i(CSOUND *csound, COMPILE *c);
int read_score_i(CSOUND *csound, COMPILE *c);
int eval_str_i(CSOUND *csound, COMPILE *p);
int eval_str_k(CSOUND *csound, COMPILE *p);
int retval_i(CSOUND *csound, RETVAL *p);
int eval_str_k(CSOUND *csound, COMPILE *p);
