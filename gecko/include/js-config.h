/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 * vim: set ts=8 sw=4 et tw=78:
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef js_config_h
#define js_config_h

/* Definitions set at build time that affect SpiderMonkey's public API.
   This header file is generated by the SpiderMonkey configure script,
   and installed along with jsapi.h.  */

/* Define to 1 if SpiderMonkey is in debug mode. */
#define JS_DEBUG 1

/*
 * NB: We have a special case for rust-bindgen, which wants to be able to
 * generate both debug and release bindings on a single objdir.
 */
#ifdef JS_DEBUG
#if !defined(DEBUG) && !defined(RUST_BINDGEN)
#  error "SpiderMonkey was configured with --enable-debug, so DEBUG must be defined when including this header"
# endif
#else
# if defined(DEBUG) && !defined(RUST_BINDGEN)
#  error "SpiderMonkey was configured with --disable-debug, so DEBUG must be not defined when including this header"
# endif
#endif

/* Define to 1 if SpiderMonkey should not use struct types in debug builds. */
/* #undef JS_NO_JSVAL_JSID_STRUCT_TYPES */

/* Define to 1 if SpiderMonkey should support multi-threaded clients.  */
/* #undef JS_THREADSAFE */

/* Define to 1 if SpiderMonkey should include ctypes support.  */
#define JS_HAS_CTYPES 1

/* Define to 1 if SpiderMonkey should support the ability to perform
   entirely too much GC.  */
#define JS_GC_ZEAL 1

/* Define to 1 if SpiderMonkey should use small chunks. */
/* #undef JS_GC_SMALL_CHUNK_SIZE */

/* Define to 1 to perform extra assertions and heap poisoning. */
/* #undef JS_CRASH_DIAGNOSTICS */

/* Define to 1 if SpiderMonkey is in NUNBOX32 mode. */
/* #undef JS_NUNBOX32 */

/* Define to 1 if SpiderMonkey is in PUNBOX64 mode. */
#define JS_PUNBOX64 1

/* MOZILLA JSAPI version number components */
#define MOZJS_MAJOR_VERSION 57
#define MOZJS_MINOR_VERSION 0

#endif /* js_config_h */
