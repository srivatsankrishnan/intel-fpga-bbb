//
// Copyright (c) 2017, Intel Corporation
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// Neither the name of the Intel Corporation nor the names of its contributors
// may be used to endorse or promote products derived from this software
// without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

/**
 * \file shim_pwrite.c
 * \brief MPF PWRITE (partial write) shim
 */

#include <string.h>

#include <opae/mpf/mpf.h>
#include "mpf_internal.h"


fpga_result __MPF_API__ mpfPwriteGetStats(
    mpf_handle_t mpf_handle,
    mpf_pwrite_stats* stats
)
{
    // Is the PWRITE feature present?
    if (! mpfShimPresent(mpf_handle, CCI_MPF_SHIM_PWRITE))
    {
        memset(stats, -1, sizeof(mpf_pwrite_stats));
        return FPGA_NOT_SUPPORTED;
    }

    stats->numPartialWrites = mpfReadCsr(mpf_handle, CCI_MPF_SHIM_PWRITE, CCI_MPF_PWRITE_CSR_STAT_NUM_PWRITES, NULL);

    return FPGA_OK;
}
