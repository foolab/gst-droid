/*
 * gst-droid
 *
 * Copyright (C) 2014 Mohammed Sameer <msameer@foolab.org>
 * Copyright (C) 2015 Jolla LTD.
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
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_DROID_V_DEC_H__
#define __GST_DROID_V_DEC_H__

#include <gst/gst.h>
#include <gst/video/gstvideodecoder.h>
#include "gstdroidcodec.h"
#include "droidmediaconvert.h"

G_BEGIN_DECLS

#define GST_TYPE_DROIDVDEC \
  (gst_droidvdec_get_type())
#define GST_DROIDVDEC(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_DROIDVDEC, GstDroidVDec))
#define GST_DROIDVDEC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_DROIDVDEC, GstDroidVDecClass))
#define GST_IS_DROIDVDEC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_DROIDVDEC))
#define GST_IS_DROIDVDEC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_DROIDVDEC))

typedef struct _GstDroidVDec GstDroidVDec;
typedef struct _GstDroidVDecClass GstDroidVDecClass;

struct _GstDroidVDec
{
  GstVideoDecoder parent;
  DroidMediaCodec *codec;
  DroidMediaBufferQueue *queue;
  GstAllocator *allocator;
  GstDroidCodec *codec_type;

  /* eos handling */
  gboolean eos;
  GMutex eos_lock;
  GCond eos_cond;

  GstBufferPool *pool;

  /* protected by decoder stream lock */
  GstFlowReturn downstream_flow_ret;
  GstBuffer *codec_data;
  gboolean dirty;
  DroidMediaRect crop_rect;
  GstVideoInfo info;

  GstVideoCodecState *in_state;
  GstVideoCodecState *out_state;
  DroidMediaConvert *convert;
};

struct _GstDroidVDecClass
{
  GstVideoDecoderClass parent_class;
};

GType gst_droidvdec_get_type (void);

G_END_DECLS

#endif /* __GST_DROID_V_DEC_H__ */
