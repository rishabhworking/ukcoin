// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2020 The Ukcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef UKC_UKCCONSENSUS_H
#define UKC_UKCCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_UKC_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/ukcoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBUKCCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define UKCCONSENSUS_API_VER 1

typedef enum ukcoinconsensus_error_t
{
    ukcoinconsensus_ERR_OK = 0,
    ukcoinconsensus_ERR_TX_INDEX,
    ukcoinconsensus_ERR_TX_SIZE_MISMATCH,
    ukcoinconsensus_ERR_TX_DESERIALIZE,
    ukcoinconsensus_ERR_AMOUNT_REQUIRED,
    ukcoinconsensus_ERR_INVALID_FLAGS,
} ukcoinconsensus_error;

/** Script verification flags */
enum
{
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    ukcoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = ukcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | ukcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               ukcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | ukcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               ukcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | ukcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int ukcoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, ukcoinconsensus_error* err);

EXPORT_SYMBOL int ukcoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, ukcoinconsensus_error* err);

EXPORT_SYMBOL unsigned int ukcoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // UKC_UKCCONSENSUS_H
