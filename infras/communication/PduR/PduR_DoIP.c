/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2022 Parai Wang <parai@foxmail.com>
 *
 * ref: Specification of PDU Router AUTOSAR CP Release 4.4.0
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "PduR.h"
#include "PduR_DoIP.h"
#include "PduR_Priv.h"
#include "PduR_Cfg.h"
/* ================================ [ MACROS    ] ============================================== */
#ifndef PDUR_DOIP_TX_BASE_ID
#warning PDUR_DOIP_TX_BASE_ID not defined, default set it to 0
#define PDUR_DOIP_TX_BASE_ID 0
#endif

#ifndef PDUR_DOIP_RX_BASE_ID
#warning PDUR_DOIP_RX_BASE_ID not defined, default set it to 0
#define PDUR_DOIP_RX_BASE_ID 0
#endif
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#ifdef PDUR_USE_TP_GATEWAY
BufReq_ReturnType PduR_DoIPGwCopyTxData(PduIdType id, const PduInfoType *info,
                                        const RetryInfoType *retry,
                                        PduLengthType *availableDataPtr) {
  return PduR_GwCopyTxData(id, info, retry, availableDataPtr);
}

void PduR_DoIPGwTxConfirmation(PduIdType id, Std_ReturnType result) {
  PduR_GwTxConfirmation(id, result);
}

BufReq_ReturnType PduR_DoIPGwStartOfReception(PduIdType id, const PduInfoType *info,
                                              PduLengthType TpSduLength,
                                              PduLengthType *bufferSizePtr) {
  return PduR_GwStartOfReception(id, info, TpSduLength, bufferSizePtr);
}

BufReq_ReturnType PduR_DoIPGwCopyRxData(PduIdType id, const PduInfoType *info,
                                        PduLengthType *bufferSizePtr) {
  return PduR_GwCopyRxData(id , info, bufferSizePtr);
}

void PduR_DoIPGwRxIndication(PduIdType id, Std_ReturnType result) {
  PduR_GwRxIndication(id, result);
}
#endif

BufReq_ReturnType PduR_DoIPCopyTxData(PduIdType id, const PduInfoType *info,
                                      const RetryInfoType *retry, PduLengthType *availableDataPtr) {
  return PduR_CopyTxData(id + PDUR_DOIP_TX_BASE_ID, info, retry, availableDataPtr);
}

void PduR_DoIPRxIndication(PduIdType id, Std_ReturnType result) {
  PduR_TpRxIndication(id + PDUR_DOIP_RX_BASE_ID, result);
}

void PduR_DoIPTxConfirmation(PduIdType id, Std_ReturnType result) {
  PduR_TxConfirmation(id + PDUR_DOIP_TX_BASE_ID, result);
}

BufReq_ReturnType PduR_DoIPStartOfReception(PduIdType id, const PduInfoType *info,
                                            PduLengthType TpSduLength,
                                            PduLengthType *bufferSizePtr) {
  return PduR_StartOfReception(id + PDUR_DOIP_RX_BASE_ID, info, TpSduLength, bufferSizePtr);
}

BufReq_ReturnType PduR_DoIPCopyRxData(PduIdType id, const PduInfoType *info,
                                      PduLengthType *bufferSizePtr) {
  return PduR_CopyRxData(id + PDUR_DOIP_RX_BASE_ID, info, bufferSizePtr);
}
