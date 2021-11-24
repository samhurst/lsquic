/*
 * lsquic_null_cc.c -- LSQUIC NULL congestion control to disable it for testing
 */

#include <stdint.h>
#include <stdlib.h>

/* Because other includes don't include these themselves for some reason */
#include <sys/queue.h>

#include "lsquic.h"
#include "lsquic_int_types.h"
#include "lsquic_types.h"
#include "lsquic_hash.h"
#include "lsquic_util.h"
#include "lsquic_cong_ctl.h"
#include "lsquic_sfcw.h"
#include "lsquic_conn_flow.h"
#include "lsquic_varint.h"
#include "lsquic_hq.h"
#include "lsquic_stream.h"
#include "lsquic_rtt.h"
#include "lsquic_conn_public.h"
#include "lsquic_packet_common.h"
#include "lsquic_null_cc.h"

void lsquic_null_cc_init (void *cong_ctl, const struct lsquic_conn_public *cp,
                           enum quic_ft_bit ft)
{
    return;
}

void lsquic_null_cc_reinit (void *cong_ctl)
{
    return;
}

void lsquic_null_cc_ack (void *cong_ctl, struct lsquic_packet_out *po,
                         unsigned packet_sz, lsquic_time_t now,
                         int app_limited)
{

}

void lsquic_null_cc_loss (void *cong_ctl)
{

}

void lsquic_null_cc_timeout (void *cong_ctl)
{

}

void lsquic_null_cc_was_quiet (void *cong_ctl, lsquic_time_t now,
                               uint64_t in_flight)
{

}

uint64_t lsquic_null_cc_get_cwnd (void *cong_ctl)
{
    return UINT64_MAX;
}

uint64_t lsquic_null_cc_pacing_rate (void *cong_ctl, int in_recovery)
{
    return UINT64_MAX;
}

void lsquic_null_cc_cleanup (void *cong_ctl)
{

}

const struct cong_ctl_if lsquic_cong_null_if =
{
    .cci_init          = lsquic_null_cc_init,
    .cci_reinit        = lsquic_null_cc_reinit,
    .cci_ack           = lsquic_null_cc_ack,
    .cci_loss          = lsquic_null_cc_loss,
    .cci_timeout       = lsquic_null_cc_timeout,
    .cci_was_quiet     = lsquic_null_cc_was_quiet,
    .cci_get_cwnd      = lsquic_null_cc_get_cwnd,
    .cci_pacing_rate   = lsquic_null_cc_pacing_rate,
    .cci_cleanup       = lsquic_null_cc_cleanup
};