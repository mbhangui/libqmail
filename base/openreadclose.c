/* 
 * $Log: openreadclose.c,v $
 * Revision 1.1  2020-11-24 09:35:24+05:30  Cprogrammer
 * Initial revision
 *
 *
 * Public domain, from djbdns-1.05.
 */

#include "error.h"
#include "open.h"
#include "readclose.h"
#include "openreadclose.h"

int openreadclose(const char *fn,stralloc *sa,unsigned int bufsize)
{
  int fd;
  fd = open_read(fn);
  if (fd == -1) {
    if (errno == error_noent) return 0;
    return -1;
  }
  if (readclose(fd,sa,bufsize) == -1) return -1;
  return 1;
}

void
getversion_openreadclose_c()
{
	static char    *x = "$Id: openreadclose.c,v 1.1 2020-11-24 09:35:24+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
