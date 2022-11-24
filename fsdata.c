#include "lwip/apps/fs.h"
#include "lwip/def.h"


#define file_NULL (struct fsdata_file *) NULL


#ifndef FS_FILE_FLAGS_HEADER_INCLUDED
#define FS_FILE_FLAGS_HEADER_INCLUDED 1
#endif
#ifndef FS_FILE_FLAGS_HEADER_PERSISTENT
#define FS_FILE_FLAGS_HEADER_PERSISTENT 0
#endif
/* FSDATA_FILE_ALIGNMENT: 0=off, 1=by variable, 2=by include */
#ifndef FSDATA_FILE_ALIGNMENT
#define FSDATA_FILE_ALIGNMENT 0
#endif
#ifndef FSDATA_ALIGN_PRE
#define FSDATA_ALIGN_PRE
#endif
#ifndef FSDATA_ALIGN_POST
#define FSDATA_ALIGN_POST
#endif
#if FSDATA_FILE_ALIGNMENT==2
#include "fsdata_alignment.h"
#endif
#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__index_shtml = 0;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__index_shtml[] FSDATA_ALIGN_POST = {
/* /index.shtml (13 chars) */
0x2f,0x69,0x6e,0x64,0x65,0x78,0x2e,0x73,0x68,0x74,0x6d,0x6c,0x00,0x00,0x00,0x00,

/* HTTP header */
/* "HTTP/1.0 200 OK
" (17 bytes) */
0x48,0x54,0x54,0x50,0x2f,0x31,0x2e,0x30,0x20,0x32,0x30,0x30,0x20,0x4f,0x4b,0x0d,
0x0a,
/* "Server: lwIP/2.2.0d (http://savannah.nongnu.org/projects/lwip)
" (64 bytes) */
0x53,0x65,0x72,0x76,0x65,0x72,0x3a,0x20,0x6c,0x77,0x49,0x50,0x2f,0x32,0x2e,0x32,
0x2e,0x30,0x64,0x20,0x28,0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x73,0x61,0x76,0x61,
0x6e,0x6e,0x61,0x68,0x2e,0x6e,0x6f,0x6e,0x67,0x6e,0x75,0x2e,0x6f,0x72,0x67,0x2f,
0x70,0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x6c,0x77,0x69,0x70,0x29,0x0d,0x0a,

/* "Content-Type: text/html
Expires: Fri, 10 Apr 2008 14:00:00 GMT
Pragma: no-cache

" (85 bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,0x3a,0x20,0x74,0x65,
0x78,0x74,0x2f,0x68,0x74,0x6d,0x6c,0x0d,0x0a,0x45,0x78,0x70,0x69,0x72,0x65,0x73,
0x3a,0x20,0x46,0x72,0x69,0x2c,0x20,0x31,0x30,0x20,0x41,0x70,0x72,0x20,0x32,0x30,
0x30,0x38,0x20,0x31,0x34,0x3a,0x30,0x30,0x3a,0x30,0x30,0x20,0x47,0x4d,0x54,0x0d,
0x0a,0x50,0x72,0x61,0x67,0x6d,0x61,0x3a,0x20,0x6e,0x6f,0x2d,0x63,0x61,0x63,0x68,
0x65,0x0d,0x0a,0x0d,0x0a,
/* raw file data (549 bytes) */
0x0a,0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x68,0x74,0x6d,0x6c,0x3e,
0x0a,0x3c,0x68,0x74,0x6d,0x6c,0x3e,0x0a,0x3c,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,
0x74,0x69,0x74,0x6c,0x65,0x3e,0x50,0x69,0x63,0x6f,0x57,0x65,0x62,0x53,0x65,0x6e,
0x73,0x6f,0x72,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x3c,0x2f,0x68,0x65,
0x61,0x64,0x3e,0x0a,0x0a,0x3c,0x73,0x74,0x79,0x6c,0x65,0x3e,0x0a,0x20,0x20,0x74,
0x61,0x62,0x6c,0x65,0x2c,0x20,0x74,0x68,0x2c,0x20,0x74,0x64,0x20,0x7b,0x0a,0x20,
0x20,0x20,0x20,0x62,0x6f,0x72,0x64,0x65,0x72,0x3a,0x31,0x70,0x78,0x20,0x73,0x6f,
0x6c,0x69,0x64,0x20,0x62,0x6c,0x61,0x63,0x6b,0x3b,0x0a,0x20,0x20,0x7d,0x0a,0x3c,
0x2f,0x73,0x74,0x79,0x6c,0x65,0x3e,0x0a,0x3c,0x62,0x6f,0x64,0x79,0x3e,0x0a,0x0a,
0x3c,0x68,0x32,0x3e,0x54,0x65,0x6d,0x70,0x65,0x72,0x61,0x74,0x75,0x72,0x65,0x20,
0x73,0x65,0x6e,0x73,0x6f,0x72,0x20,0x72,0x65,0x61,0x64,0x6f,0x75,0x74,0x3a,0x20,
0x3c,0x2f,0x68,0x32,0x3e,0x3c,0x68,0x32,0x20,0x69,0x64,0x3d,0x22,0x74,0x65,0x6d,
0x70,0x52,0x65,0x61,0x64,0x6f,0x75,0x74,0x22,0x3e,0x30,0x3c,0x2f,0x68,0x32,0x3e,
0x0a,0x0a,0x3c,0x73,0x63,0x72,0x69,0x70,0x74,0x3e,0x0a,0x20,0x20,0x66,0x75,0x6e,
0x63,0x74,0x69,0x6f,0x6e,0x20,0x72,0x65,0x71,0x4c,0x69,0x73,0x74,0x65,0x6e,0x65,
0x72,0x28,0x29,0x20,0x7b,0x0a,0x20,0x20,0x20,0x20,0x64,0x6f,0x63,0x75,0x6d,0x65,
0x6e,0x74,0x2e,0x67,0x65,0x74,0x45,0x6c,0x65,0x6d,0x65,0x6e,0x74,0x42,0x79,0x49,
0x64,0x28,0x22,0x74,0x65,0x6d,0x70,0x52,0x65,0x61,0x64,0x6f,0x75,0x74,0x22,0x29,
0x2e,0x74,0x65,0x78,0x74,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x20,0x3d,0x20,0x74,
0x68,0x69,0x73,0x2e,0x72,0x65,0x73,0x70,0x6f,0x6e,0x73,0x65,0x54,0x65,0x78,0x74,
0x3b,0x0a,0x20,0x20,0x7d,0x0a,0x0a,0x20,0x20,0x77,0x69,0x6e,0x64,0x6f,0x77,0x2e,
0x73,0x65,0x74,0x49,0x6e,0x74,0x65,0x72,0x76,0x61,0x6c,0x28,0x66,0x75,0x6e,0x63,
0x74,0x69,0x6f,0x6e,0x28,0x29,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6c,0x65,0x74,0x20,
0x72,0x65,0x71,0x20,0x3d,0x20,0x6e,0x65,0x77,0x20,0x58,0x4d,0x4c,0x48,0x74,0x74,
0x70,0x52,0x65,0x71,0x75,0x65,0x73,0x74,0x28,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,
0x72,0x65,0x71,0x2e,0x61,0x64,0x64,0x45,0x76,0x65,0x6e,0x74,0x4c,0x69,0x73,0x74,
0x65,0x6e,0x65,0x72,0x28,0x22,0x6c,0x6f,0x61,0x64,0x22,0x2c,0x20,0x72,0x65,0x71,
0x4c,0x69,0x73,0x74,0x65,0x6e,0x65,0x72,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,
0x65,0x71,0x2e,0x6f,0x70,0x65,0x6e,0x28,0x22,0x47,0x45,0x54,0x22,0x2c,0x20,0x22,
0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x31,0x39,0x32,0x2e,0x31,0x36,0x38,0x2e,0x37,
0x2e,0x31,0x2f,0x74,0x65,0x6d,0x70,0x22,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,
0x65,0x71,0x2e,0x73,0x65,0x6e,0x64,0x28,0x29,0x3b,0x0a,0x0a,0x20,0x20,0x7d,0x2c,
0x20,0x31,0x30,0x30,0x30,0x29,0x3b,0x0a,0x20,0x20,0x0a,0x3c,0x2f,0x73,0x63,0x72,
0x69,0x70,0x74,0x3e,0x0a,0x0a,0x3c,0x2f,0x62,0x6f,0x64,0x79,0x3e,0x0a,0x3c,0x2f,
0x68,0x74,0x6d,0x6c,0x3e,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__temp_shtml = 1;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__temp_shtml[] FSDATA_ALIGN_POST = {
/* /temp.shtml (12 chars) */
0x2f,0x74,0x65,0x6d,0x70,0x2e,0x73,0x68,0x74,0x6d,0x6c,0x00,

/* HTTP header */
/* "HTTP/1.0 200 OK
" (17 bytes) */
0x48,0x54,0x54,0x50,0x2f,0x31,0x2e,0x30,0x20,0x32,0x30,0x30,0x20,0x4f,0x4b,0x0d,
0x0a,
/* "Server: lwIP/2.2.0d (http://savannah.nongnu.org/projects/lwip)
" (64 bytes) */
0x53,0x65,0x72,0x76,0x65,0x72,0x3a,0x20,0x6c,0x77,0x49,0x50,0x2f,0x32,0x2e,0x32,
0x2e,0x30,0x64,0x20,0x28,0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x73,0x61,0x76,0x61,
0x6e,0x6e,0x61,0x68,0x2e,0x6e,0x6f,0x6e,0x67,0x6e,0x75,0x2e,0x6f,0x72,0x67,0x2f,
0x70,0x72,0x6f,0x6a,0x65,0x63,0x74,0x73,0x2f,0x6c,0x77,0x69,0x70,0x29,0x0d,0x0a,

/* "Content-Type: text/html
Expires: Fri, 10 Apr 2008 14:00:00 GMT
Pragma: no-cache

" (85 bytes) */
0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,0x3a,0x20,0x74,0x65,
0x78,0x74,0x2f,0x68,0x74,0x6d,0x6c,0x0d,0x0a,0x45,0x78,0x70,0x69,0x72,0x65,0x73,
0x3a,0x20,0x46,0x72,0x69,0x2c,0x20,0x31,0x30,0x20,0x41,0x70,0x72,0x20,0x32,0x30,
0x30,0x38,0x20,0x31,0x34,0x3a,0x30,0x30,0x3a,0x30,0x30,0x20,0x47,0x4d,0x54,0x0d,
0x0a,0x50,0x72,0x61,0x67,0x6d,0x61,0x3a,0x20,0x6e,0x6f,0x2d,0x63,0x61,0x63,0x68,
0x65,0x0d,0x0a,0x0d,0x0a,
/* raw file data (12 bytes) */
0x3c,0x21,0x2d,0x2d,0x23,0x61,0x64,0x63,0x20,0x2d,0x2d,0x3e,};



const struct fsdata_file file__index_shtml[] = { {
file_NULL,
data__index_shtml,
data__index_shtml + 16,
sizeof(data__index_shtml) - 16,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_SSI,
}};

const struct fsdata_file file__temp_shtml[] = { {
file__index_shtml,
data__temp_shtml,
data__temp_shtml + 12,
sizeof(data__temp_shtml) - 12,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_SSI,
}};

#define FS_ROOT file__temp_shtml
#define FS_NUMFILES 2

