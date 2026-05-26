#ifndef MAGIC_H
#define MAGIC_H

/// PRIVATE INCLUDES
/// Dont include ffmpeg directly, use the magic macros instead
#if defined ( __FFMPEG_INCLUDE )

#include <ffmpeg/avcodec.h>
#include <ffmpeg/avformat.h>
#include <ffmpeg/swscale.h>

#endif // __FFMPEG_INCLUDE

/// MAGIC MACROS
/// Use these macros to include ffmpeg headers and define recording strings

#if defined ( __FFMPEG_WEBCAM_RECORD )
#define __FFMPEG_INCLUDE
#define FFMPEG_WEBCAM_STRING "ffmpeg -f v4l2 -i /dev/video0 out.mp4"
#endif // __FFMPEG_WEBCAM_RECORD

#if defined ( __FFMPEG_DESKTOP_RECORD )
#define __FFMPEG_INCLUDE
#define FFMPEG_DESKTOP_STRING "ffmpeg -f x11grab -i :0.0 out.mp4"
#endif // __FFMPEG_DESKTOP_RECORD

#endif // MAGIC_H
