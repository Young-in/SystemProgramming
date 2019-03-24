#include <stdlib.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>
#include <stdio.h>

int get_callinfo(char *fname, size_t fnlen, unsigned long long *ofs)
{
  unw_cursor_t cursor;
  unw_context_t context;
  unw_word_t ip, sp;

  unw_getcontext(&context);
  unw_init_local(&cursor, &context);

  unw_step(&cursor);
  unw_step(&cursor);
  unw_step(&cursor);

  int ret = unw_get_proc_name(&cursor, fname, fnlen, (unw_word_t *)ofs);
  (*ofs) -= 5;
  return ret;
//  return -1;
}
