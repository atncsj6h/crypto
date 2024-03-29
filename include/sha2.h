/*      $OpenBSD: sha2.h,v 1.5 2014/11/16 17:39:09 tedu Exp $   */

/*
 * FILE:        sha2.h
 * AUTHOR:      Aaron D. Gifford <me@aarongifford.com>
 *
 * Copyright (c) 2000-2001, Aaron D. Gifford
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTOR(S) BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $From: sha2.h,v 1.1 2001/11/08 00:02:01 adg Exp adg $
 */

#ifndef _SHA2_H
#define _SHA2_H


/*** SHA-256/384/512 Various Length Definitions ***********************/
#define SHA256_BLOCK_LENGTH             64
#define SHA256_DIGEST_LENGTH            32
#define SHA256_DIGEST_STRING_LENGTH     (SHA256_DIGEST_LENGTH * 2 + 1)
#define SHA384_BLOCK_LENGTH             128
#define SHA384_DIGEST_LENGTH            48
#define SHA384_DIGEST_STRING_LENGTH     (SHA384_DIGEST_LENGTH * 2 + 1)
#define SHA512_BLOCK_LENGTH             128
#define SHA512_DIGEST_LENGTH            64
#define SHA512_DIGEST_STRING_LENGTH     (SHA512_DIGEST_LENGTH * 2 + 1)


/*** SHA-256/384/512 Context Structure *******************************/
typedef struct _SHA2_CTX {
        union {
                u_int32_t       st32[8];
                u_int64_t       st64[8];
        } state;
        u_int64_t       bitcount[2];
        u_int8_t        buffer[SHA512_BLOCK_LENGTH];
} SHA2_CTX;

/**********************************************************************
 *
 *                        PROGRAMMING NOTE
 *
 * The below functions are used internally by the library and forms
 * the core of its algorithms.
 *
 * Most programs would normally use the SHAxxxInit(), SHAxxxUpdate(),
 * and SHAxxxFinal() functions instead of calling SHAxxxTransform()
 * or SHAxxxLast() directly.
 *
 * They are only exposed here in case you have a legitimate need to
 * call them directly.
 *
 *********************************************************************/

void SHA256Transform(u_int32_t *, const u_int8_t *);
void SHA512Transform(u_int64_t *, const u_int8_t *);
void SHA512Last(SHA2_CTX *);

void SHA256Init(SHA2_CTX *);
void SHA256Update(SHA2_CTX *, const void *, size_t);
void SHA256Final(u_int8_t[SHA256_DIGEST_LENGTH], SHA2_CTX *);

void SHA384Init(SHA2_CTX *);
void SHA384Update(SHA2_CTX *, const void *, size_t);
void SHA384Final(u_int8_t[SHA384_DIGEST_LENGTH], SHA2_CTX *);

void SHA512Init(SHA2_CTX *);
void SHA512Update(SHA2_CTX *, const void *, size_t);
void SHA512Final(u_int8_t[SHA512_DIGEST_LENGTH], SHA2_CTX *);

#endif /* _SHA2_H */
