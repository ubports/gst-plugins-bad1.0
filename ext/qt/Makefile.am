plugin_LTLIBRARIES = libgstqtsink.la

noinst_HEADERS = \
	gstqsgtexture.h \
	gstqtsink.h \
	qtitem.h

moc_generated = \
	moc_qtitem.cc \
	moc_gstqsgtexture.cc

#anything generated by the Qt tools...
BUILT_SOURCES = $(moc_generated)
CLEANFILES = $(moc_generated)

nodist_libgstqtsink_la_SOURCES = $(BUILT_SOURCES)

libgstqtsink_la_SOURCES = \
	gstqsgtexture.cc \
	qtitem.cc \
	gstqtsink.cc \
	gstqtsink.h \
	gstqtgl.h \
	gstplugin.cc

libgstqtsink_la_CXXFLAGS = \
	-I$(top_srcdir)/gst-libs \
	-I$(top_builddir)/gst-libs \
	$(GST_CXXFLAGS) \
	$(GST_BASE_CFLAGS) \
	$(GST_PLUGINS_BASE_CFLAGS) \
	$(QT_CFLAGS) \
	$(GL_CFLAGS)

libgstqtsink_la_LIBADD = \
	$(GST_BASE_LIBS) \
	$(GST_PLUGINS_BASE_LIBS) \
	$(QT_LIBS) \
	$(top_builddir)/gst-libs/gst/gl/libgstgl-$(GST_API_VERSION).la \
	-lgstvideo-$(GST_API_VERSION)

libgstqtsink_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstqtsink_la_LIBTOOLFLAGS = $(GST_PLUGIN_LIBTOOLFLAGS)


$(moc_generated): moc_%.cc: %.h
	@MOC@ -o $@ $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(MOC_CPPFLAGS) $<

ui-%.h: %.ui
	@UIC@ -o $@ $<

qrc-%.cc: %.qrc
	@RCC@ -o $@ $<
