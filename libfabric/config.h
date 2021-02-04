/* adds build_id to version if it was defined */
/* #undef BUILD_ID */

/* defined to 1 if libfabric was configured with --enable-debug, 0 otherwise
   */
/* #undef ENABLE_DEBUG */

/* Define to 1 if compiler/linker support symbol versioning. */
/* #undef HAVE_SYMVER_SUPPORT */

/* Set to 1 to use c11 atomic functions */
#define HAVE_ATOMICS

/* Set to 1 to use c11 atomic `least` types */
#define HAVE_ATOMICS_LEAST_TYPES

/* Set to 1 to use built-in intrincics atomics */
#define HAVE_BUILTIN_ATOMICS

/* Set to 1 to use built-in intrinsics memory model aware atomics */
/* #undef HAVE_BUILTIN_MM_ATOMICS */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H

/* Define to 1 if you have the <elf.h> header file. */
/* #undef HAVE_ELF_H */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H

/* Define to 1 if you have the `dl' library (-ldl). */
#define HAVE_LIBDL

/* Define to 1 if you have the `pthread' library (-lpthread). */
#define HAVE_LIBPTHREAD

/* sstmac provider is built */
#define HAVE_SSTMAC 1

/* sstmac provider is built as DSO */
#undef HAVE_SSTMAC_DL

/* define when building with FABRIC_DIRECT support */
#define FABRIC_DIRECT_ENABLED

/* Define to 1 to enable valgrind annotations */
#undef INCLUDE_VALGRIND

/* Whether we have __builtin_ia32_rdpmc() and linux/perf_event.h file or not
   */
#undef HAVE_LINUX_PERF_RDPMC

/* Define to 1 if the linker supports alias attribute. */
#undef HAVE_ALIAS_ATTRIBUTE

/* Set to 1 to use cpuid */
#undef HAVE_CPUID

/* perf provider is built */
#undef HAVE_PERF

/* perf provider is built as DSO */
#undef HAVE_PERF_DL

/* hook_debug provider is built */
#undef HAVE_HOOK_DEBUG

/* hook_debug provider is built as DSO */
#undef HAVE_HOOK_DEBUG_DL

#define PACKAGE "libfabric"

/* Version number of package */
#define VERSION "1.10.0a1"

#define PACKAGE_VERSION "1.10.0a1"

#define BUILD_ID ""
