
plugin_LTLIBRARIES = libgstschro.la

noinst_HEADERS = \
	gstschroutils.h

libgstschro_la_SOURCES = \
	gstschro.c \
	gstschrodec.c \
	gstschroenc.c \
	gstschroutils.c
libgstschro_la_CFLAGS = \
	$(GST_PLUGINS_BAD_CFLAGS) \
	$(GST_PLUGINS_BASE_CFLAGS) \
        $(GST_BASE_CFLAGS) \
	$(GST_CFLAGS) \
	-DGST_USE_UNSTABLE_API \
	$(SCHRO_CFLAGS)
libgstschro_la_LIBADD = \
	$(top_builddir)/gst-libs/gst/video/libgstbasevideo-@GST_MAJORMINOR@.la \
	$(GST_PLUGINS_BASE_LIBS) -lgstvideo-@GST_MAJORMINOR@ \
        $(GST_BASE_LIBS) $(GST_LIBS) \
	$(SCHRO_LIBS)
libgstschro_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstschro_la_LIBTOOLFLAGS = --tag=disable-static


