/*
 * $Log: scan_int.c,v $
 * Revision 1.4  2020-11-22 23:52:05+05:30  Cprogrammer
 * use const keyword
 *
 * Revision 1.3  2019-07-18 10:08:58+05:30  Cprogrammer
 * fixed compiler warning
 *
 * Revision 1.2  2019-07-18 09:55:36+05:30  Cprogrammer
 * added dummy function to fix compiler warning
 *
 * Revision 1.1  2019-06-24 21:42:31+05:30  Cprogrammer
 * Initial revision
 *
 */
#include "scan.h"

unsigned int
scan_int(register const char *s, register int *i)
{
	register unsigned int pos;
	register int result;
	register unsigned char c;
	int             sign;

	pos = 0;
	result = 0;
	sign = 1;
	/*-
	 * determine sign of the number
	 */
	switch (s[0])
	{
		case '\0':
			return 0;
		case '-':
			++pos;
			sign = -1;
			break;
		case '+':
			++pos;
			sign = 1;
			break;
		default:
			break;
	}
	while ((c = (unsigned char)(s[pos] - '0')) < 10)
	{
		result = result * 10 + c;
		++pos;
	}
	*i = result * sign;
	return pos;
}

void
getversion_scan_int_c()
{
	static char    *x = "$Id: scan_int.c,v 1.4 2020-11-22 23:52:05+05:30 Cprogrammer Exp mbhangui $";

	x++;
}
