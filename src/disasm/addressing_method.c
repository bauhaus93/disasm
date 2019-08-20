#include "addressing_method.h"

AddressingMethod get_addressing_method_by_letter(char letter) {
    switch (letter) {
    case 'A':
        return AM_DIRECT_ADDR;
    case 'B':
        return AM_VEX_REG;
    case 'C':
        return AM_MODRM_REG_CONTROL;
    case 'D':
        return AM_MODRM_REG_DEBUG;
    case 'E':
        return AM_MODRM_REG_ADDR;
    case 'F':
        return AM_E_R_FLAGS;
    case 'G':
        return AM_MODRM_REG;
    case 'H':
        return AM_VEX_XMM_YMM;
    case 'I':
        return AM_IMMEDIATE;
    case 'J':
        return AM_RELATIVE_OFFSET;
    case 'L':
        return AM_IMMEDIATE_XMM_YMM;
    case 'M':
        return AM_MODRM_ONLY_MEM;
    case 'N':
        return AM_MODRM_RM_MMX;
    case 'O':
        return AM_OFFSET;
    case 'P':
        return AM_MODRM_REG_MMX;
    case 'Q':
        return AM_MODRM_OPERAND_MMX_ADDR;
    case 'R':
        return AM_MODRM_RM_ONLY_GEN_REG;
    case 'S':
        return AM_MODRM_REG_SEG_REG;
    case 'U':
        return AM_MODRM_RM_XMM_YMM;
    case 'V':
        return AM_MODRM_REG_XMM_YMM;
    case 'W':
        return AM_MODRM_OPERAND_XMM_YMM_ADDR;
    case 'X':
        return AM_MEM_BY_DS_RSI;
    case 'Y':
        return AM_MEM_BY_ES_RDI;
    default:
        return AM_NONE;
    }
}

AddressingMethod get_addressing_method_by_letters(char letter_a, char letter_b) {
    if (letter_a == 'A' && letter_b == 'L') {
        return AM_DIRECT_ADDR_IMMEDIATE_XMM_YMM;
    } else {
        return AM_NONE;
    }
}
