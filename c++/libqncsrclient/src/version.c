#include "Revision.h"
#define RELEASE  "2222"
#define VERSION  "3333"

static const char __libc_release[] = RELEASE;
static const char __libc_version[] = VERSION;

const char interp[] __attribute__((section(".interp"))) = "/lib/ld-linux.so.2";

static const char banner[] =
"VGADAPTER Library release verion:"GIT_REVISION_NUM", by "BUILD_BY" at "BUILD_AT" on "BUILD_TIME"\n\
Copyright (C) 2008 Channel Soft, Inc.\n";

#include <unistd.h>

extern void __libc_print_version (void);
void
__libc_print_version (void)
{
	write (STDOUT_FILENO, banner, sizeof banner - 1);
}


/* This function is the entry point for the shared object.
   Running the library as a program will get here.  */

extern void __libc_main (void) __attribute__ ((noreturn));
void
__libc_main (void)
{
  //__libc_print_version ();
  print_version();
  _exit (0);
}
