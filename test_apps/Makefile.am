# test_pdu/Makefile.am #

TESTAPPS_SOURCE_DIR = $(top_srcdir)/test_apps
esme_SOURCES = \
    $(TESTAPPS_SOURCE_DIR)/tcp.c\
    $(TESTAPPS_SOURCE_DIR)/smpp.c\
    $(TESTAPPS_SOURCE_DIR)/esme.h\
    $(TESTAPPS_SOURCE_DIR)/esme.c

esme_CPPFLAGS = `xml2-config --cflags`
esme_LDFLAGS = `xml2-config --libs`
esme_pkgdatadir = $(prefix)/bin
esme_pkgdata_DATA = \
     $(TESTAPPS_SOURCE_DIR)/esme.xml

