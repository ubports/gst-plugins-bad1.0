/* GStreamer
 * Copyright (C) 2011 David A. Schleef <ds@schleef.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef _GST_INTER_VIDEO_SRC_H_
#define _GST_INTER_VIDEO_SRC_H_

#include <gst/base/gstbasesrc.h>
#include <gst/video/video.h>
#include "gstintersurface.h"

G_BEGIN_DECLS

#define GST_TYPE_INTER_VIDEO_SRC   (gst_inter_video_src_get_type())
#define GST_INTER_VIDEO_SRC(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_INTER_VIDEO_SRC,GstInterVideoSrc))
#define GST_INTER_VIDEO_SRC_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_INTER_VIDEO_SRC,GstInterVideoSrcClass))
#define GST_IS_INTER_VIDEO_SRC(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_INTER_VIDEO_SRC))
#define GST_IS_INTER_VIDEO_SRC_CLASS(obj)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_INTER_VIDEO_SRC))

typedef struct _GstInterVideoSrc GstInterVideoSrc;
typedef struct _GstInterVideoSrcClass GstInterVideoSrcClass;

struct _GstInterVideoSrc
{
  GstBaseSrc base_intervideosrc;

  GstInterSurface *surface;

  char *channel;

  GstVideoFormat format;
  int fps_n;
  int fps_d;
  int n_frames;
  int width;
  int height;
};

struct _GstInterVideoSrcClass
{
  GstBaseSrcClass base_intervideosrc_class;
};

GType gst_inter_video_src_get_type (void);

G_END_DECLS

#endif
