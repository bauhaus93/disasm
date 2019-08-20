#ifndef ADDRESSING_METHOD_H 
#define ADDRESSING_METHOD_H

// Intel 64/IA-32 Architecture, Volume 2, Appendix A.2, p. 2535ff
typedef enum {
    AM_NONE,
    AM_DIRECT_ADDR,                  // A
    AM_VEX_REG,                      // B
    AM_MODRM_REG_CONTROL,            // C
    AM_MODRM_REG_DEBUG,              // D
    AM_MODRM_REG_ADDR,               // E
    AM_E_R_FLAGS,                    // F
    AM_MODRM_REG,                    // G
    AM_VEX_XMM_YMM,                  // H
    AM_IMMEDIATE,                    // I
    AM_RELATIVE_OFFSET,              // J
    AM_IMMEDIATE_XMM_YMM,            // L
    AM_MODRM_ONLY_MEM,               // M
    AM_MODRM_RM_MMX,                 // N
    AM_OFFSET,                       // O
    AM_MODRM_REG_MMX,                // P
    AM_MODRM_OPERAND_MMX_ADDR,       // Q
    AM_MODRM_RM_ONLY_GEN_REG,        // R
    AM_MODRM_REG_SEG_REG,            // S
    AM_MODRM_RM_XMM_YMM,             // U
    AM_MODRM_REG_XMM_YMM,            // V
    AM_MODRM_OPERAND_XMM_YMM_ADDR,   // W
    AM_MEM_BY_DS_RSI,                // X
    AM_MEM_BY_ES_RDI,                // Y
    AM_DIRECT_ADDR_IMMEDIATE_XMM_YMM // AL
} AddressingMethod;


#ifdef __cplusplus
extern "C" {
#endif

AddressingMethod get_addressing_method_by_letter(char letter);
AddressingMethod get_addressing_method_by_letters(char letter_a, char letter_b);


#ifdef __cplusplus
}
#endif

#endif // ADDRESSING_METHOD_H
