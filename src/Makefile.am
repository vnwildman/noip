sbin_PROGRAMS = noip
noip_SOURCES = noip2.c
AM_CPPFLAGS = -I$(srcdir) -I$(top_srcdir) -DSYSCONFDIR="\"$(sysconfdir)\""
noip_LDADD = -lc -lcurl
dist_man1_MANS = noip.1

sbin_SCRIPTS = mininoip
dist_doc_DATA = mininoip.conf

