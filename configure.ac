#
# $Log: configure.ac,v $
# Revision 1.25  2021-06-16 13:24:59+05:30  Cprogrammer
# added AC_CHECK_LIB(ssl, SSL_CTX_new, ...)
#
# Revision 1.24  2021-05-28 22:33:11+05:30  Cprogrammer
# define SYSCONFDIR for leapsecs.dat
#
# Revision 1.23  2021-05-04 14:17:42+05:30  Cprogrammer
# removed -lssl from link
#
# Revision 1.22  2021-04-02 20:14:00+05:30  Cprogrammer
# updated configure.ac
#
# Revision 1.21  2021-03-26 18:28:01+05:30  Cprogrammer
# use conf-email for email address
#
# Revision 1.20  2021-03-12 13:11:25+05:30  Cprogrammer
# add LDFLAGS to existing LDFLAGS
#
# Revision 1.19  2021-03-11 20:45:10+05:30  Cprogrammer
# updated CPPFLAGS, LDFLAGS for brew
#
# Revision 1.18  2021-03-11 18:33:21+05:30  Cprogrammer
# added -Dlint for macos
#
# Revision 1.17  2021-01-11 23:25:45+05:30  Cprogrammer
# removed -Wcast-align
#
# Revision 1.16  2020-10-22 22:37:10+05:30  Cprogrammer
# removed STRIP_OPT
#
# Revision 1.15  2020-10-06 14:49:45+05:30  Cprogrammer
# remove use of GCC variable as it is set by almost non-gcc compilers too
#
# Revision 1.14  2020-10-04 12:00:33+05:30  Cprogrammer
# fix for broken crypt() function on Darwin Mac OS X
#
# Revision 1.13  2020-09-30 20:48:27+05:30  Cprogrammer
# Darwin Port
#
# Revision 1.12  2020-09-16 21:53:54+05:30  Cprogrammer
# FreeBSD fix
#
# Revision 1.11  2020-09-13 01:35:26+05:30  Cprogrammer
# fixed PACKAGE_BUGREPORT email address
#
# Revision 1.10  2020-07-23 11:27:07+05:30  Cprogrammer
# used comprehensive CFLAGS
#
# Revision 1.9  2020-07-01 16:23:05+05:30  Cprogrammer
# added stddef.h, stdint.h
#
# Revision 1.8  2020-07-01 15:59:46+05:30  Cprogrammer
# added subdir-objects
#
# Revision 1.6  2020-06-21 21:27:07+05:30  Cprogrammer
# added AC_PROG_CC_C99 to configure.ac
#
# Revision 1.5  2020-06-16 16:09:30+05:30  Cprogrammer
# added pwd.h, grp.h
#
# Revision 1.4  2020-06-15 00:56:06+05:30  Cprogrammer
# updated email address
# added AC_CHECK_LIB(crypto, ..)
#
# Revision 1.3  2020-05-21 10:52:32+05:30  Cprogrammer
# version 0.3
#
# Revision 1.2  2020-05-21 09:00:12+05:30  Cprogrammer
# version 0.2
#
# Revision 1.1  2020-05-11 12:32:48+05:30  Cprogrammer
# Initial revision
#
# Revision 1.1  2014-09-02 22:13:49+05:30  Cprogrammer
# Initial revision
#
# $Id: configure.ac,v 1.25 2021-06-16 13:24:59+05:30 Cprogrammer Exp mbhangui $
#
AC_PREREQ([2.64])
AC_INIT([libqmail],m4_normalize(m4_include([conf-version])),m4_normalize(m4_include([conf-email])),indimail, [https://github.com/mbhangui/libqmail])
AC_CANONICAL_TARGET
PACKAGE=$PACKAGE_NAME
VERSION=$PACKAGE_VERSION
LT_INIT
AM_INIT_AUTOMAKE([subdir-objects silent-rules])
AM_CONFIG_HEADER(config.h)

dnl Checks for programs.
LT_INIT
AC_PROG_LN_S
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_INSTALL
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

dnl Checks for header files.
AC_CHECK_HEADERS(ctype.h errno.h stdarg.h time.h unistd.h limits.h pwd.h grp.h fcntl.h signal.h stdint.h stddef.h endian.h netdb.h)
AC_CHECK_HEADERS(sys/types.h sys/wait.h sys/file.h sys/endian.h)

case "$host" in
*-*-sunos4.1.1*)
	CPPFLAGS="$CPPFLAGS -DSUNOS4"
	;;
*-*-solaris*)
	CPPFLAGS="$CPPFLAGS -DSOLARIS"
	;;
*-*-linux*)
	CPPFLAGS="$CPPFLAGS -Dlint -DLINUX -Wall"
	CFLAGS="$CFLAGS -O4 -Wall -Wimplicit -fPIC -fno-strict-aliasing"
	CFLAGS="$CFLAGS -Wunused -Wcomment -Wchar-subscripts -Wuninitialized"
	CFLAGS="$CFLAGS -Wshadow -Wcast-align -Wwrite-strings -Wno-discarded-qualifiers"
	;;
*-*-freebsd*)
	CPPFLAGS="$CPPFLAGS -Dlint -DFREEBSD -Wall"
	CFLAGS="$CFLAGS -O3 -Wall -Wimplicit -fPIC -fno-strict-aliasing -Wunused"
	CFLAGS="$CFLAGS -Wcomment -Wchar-subscripts"
	CFLAGS="$CFLAGS -Wuninitialized -Wshadow -Wwrite-strings -Wno-ignored-qualifiers"
	CFLAGS="$CFLAGS -Wno-incompatible-pointer-types-discards-qualifiers -Wno-cast-align"
	;;
*-*-darwin*)
	CPPFLAGS="$CPPFLAGS -Dlint -I/opt/local/include -DDARWIN -I/usr/local/include"
	LDFLAGS="$LDFLAGS -L/opt/local/lib -L/usr/local/lib"
	;;
esac

AC_CHECK_FUNC(flock)
if test "$ac_cv_func_flock" = yes ; then
	AC_DEFINE([HAVE_FLOCK], [1], [flock function])
fi

AC_CHECK_LIB(ssl, SSL_CTX_new, [AC_SUBST([LIB_SSL], ["-lssl"]) AC_DEFINE([HAVE_SSL], [1],[OpenSSL Library])],,-lssl)
AC_CHECK_LIB(crypto, CRYPTO_new_ex_data, [AC_SUBST([LIB_CRYPTO], ["-lcrypto"]) AC_DEFINE([HAVE_CRYPTO], [1],[Crypto Library])],,-lcrypto)
AC_CHECK_LIB(crypt, crypt, [AC_SUBST([LIB_CRYPT], ["-lcrypt"]) AC_DEFINE([HAVE_CRYPT], [1],[crypt Library])],,)

dnl Does not work on RHEL 5, CentOS 5 64 bit systems
RPATH_LIB="$acl_libdirstem"
defaultprefix="/usr"
AC_SUBST([LIBTOOL_DEPS])
AC_SUBST(RPATH_LIB)
AC_SUBST(defaultprefix)
AC_SUBST(libdir)
LIBVER=1
AC_SUBST(LIBVER)
AC_CONFIG_FILES([libqmail.pc:libqmail.pc.in],[], [])

if test x$prefix = xNONE
then
	prefix="$defaultprefix"
	ac_configure_args="$ac_configure_args -prefix=$prefix"
fi

if test " $pkgconfigdir" = " "
then
	if test -d $prefix/lib/pkgconfig
	then
		pkgconfigdir=$prefix/lib/pkgconfig
	elif test -d $prefix/libdata/pkgconfig
	then
		pkgconfigdir=$prefix/libdata/pkgconfig
	else
		AC_MSG_ERROR(Could not find pkgconfigdir)
	fi
fi

AC_ARG_ENABLE(ENABLE_MD5_CRYPT,    [  --enable-md5-crypt            if your system crypt does not support md5],
	[with_md5crypt=$enableval],
	[with_md5crypt=no])
test "$with_md5crypt" = "no" && AC_DEFINE(ENABLE_MD5_CRYPT,1,Define if you want md5 crypt support compiled in)
AM_CONDITIONAL(ENABLE_MD5_CRYPT, test "$with_md5crypt" = yes)

AC_ARG_ENABLE(ENABLE_SHA256_CRYPT, [  --enable-sha256-crypt         if your system does not support sha256],
	[with_sha256crypt=$enableval],
	[with_sha256crypt=no])
test "$with_sha256crypt" = "no" && AC_DEFINE(ENABLE_SHA256_CRYPT,1,Define if you want sha256 crypt support compiled in)
AM_CONDITIONAL(ENABLE_SHA256_CRYPT, test "$with_sha256crypt" = yes)

AC_ARG_ENABLE(ENABLE_SHA512_CRYPT, [  --enable-sha512-crypt         if your system does not support sha512],
	[with_sha512crypt=$enableval],
	[with_sha512crypt=no])
test "$with_sha512crypt" = "no" && AC_DEFINE(ENABLE_SHA512_CRYPT,1,Define if you want sha512 crypt support compiled in)
AM_CONDITIONAL(ENABLE_SHA512_CRYPT, test "$with_sha512crypt" = yes)

pwdhash=system
AC_ARG_ENABLE(passwd-hash,
	[--enable-passwd-hash=des|md5|sha256|sha512|system Passwd Hash (des - DES, md5 - MD5, sha256 - SHA256, sha512 - SHA512, system)],
	pwdhash=$enableval,
	[
	 pwdhash=system
	])
case $pwdhash in
	des)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,0,Enable DES Encryption)
	;;
	md5)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,1,Enable MD5 Encryption)
	;;
	sha256)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,2,Enable SHA256 Encryption)
	;;
	sha512)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,3,Enable SHA512 Encryption)
	;;
	system)
	AC_DEFINE_UNQUOTED(PASSWORD_HASH,-1,Use System Crypt Encryption)
	;;
esac
AC_DEFINE_UNQUOTED(DES_HASH,0,Enable DES Encryption)
AC_DEFINE_UNQUOTED(MD5_HASH,1,Enable MD5 Encryption)
AC_DEFINE_UNQUOTED(SHA256_HASH,2,Enable SHA256 Encryption)
AC_DEFINE_UNQUOTED(SHA512_HASH,3,Enable SHA512 Encryption)
AC_DEFINE_UNQUOTED(SYSCONFDIR,"$sysconfdir", Directory for leapsecs.dat)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

case $pwdhash in
	des)
echo "     Password Hash = DES --enable-password-hash=des"
	;;
	md5)
echo "     Password Hash = MD5 --enable-password-hash=md5"
	;;
	sha256)
echo "     Password Hash = SHA256 --enable-password-hash=sha256"
	;;
	sha512)
echo "     Password Hash = SHA512 --enable-password-hash=sha512"
	;;
	system)
echo "     Password Hash = system --enable-password-hash=system"
	;;
esac

case $with_md5crypt in
1*|y*|Y*)
echo "         MD5 Crypt = ON  --enable-md5-crypt=y"
;;
*)
echo "         MD5 Crypt = OFF --enable-md5-crypt=n default"
;;
esac

case $with_sha256crypt in
1*|y*|Y*)
echo "      SHA256 Crypt = ON  --enable-sha256-crypt=y"
;;
*)
echo "      SHA256 Crypt = OFF --enable-sha256-crypt=n default"
;;
esac

case $with_sha512crypt in
1*|y*|Y*)
echo "      SHA512 Crypt = ON  --enable-sha512-crypt=y"
;;
*)
echo "      SHA512 Crypt = OFF --enable-sha512-crypt=n default"
;;
esac
