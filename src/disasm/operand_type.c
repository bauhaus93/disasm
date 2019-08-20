#include "operand_type.h"

OperandType get_operand_type_by_letter(char letter) {
    switch (letter) {
    case 'a':
        return OT_TWO_WORD_DWORD_MEM;
    case 'b':
        return OT_BYTE;
    case 'c':
        return OT_BYTE_WORD;
    case 'd':
        return OT_DWORD;
    case 'p':
        return OT_POINTER;
    case 'q':
        return OT_QWORD;
    case 's':
        return OT_PSEUDO_DESCRIPTOR;
    case 'v':
        return OT_WORD_DWORD_QWORD;
    case 'w':
        return OT_WORD;
    case 'x':
        return OT_QQ_DQ_WORD;
    case 'z':
        return OT_WORD_DWORD;
    default:
        return OT_NONE;
    }
}

OperandType get_operand_type_by_letters(char letter_a, char letter_b) {
    switch (letter_a) {
    case 'd':
        return letter_b == 'q' ? OT_DQWORD : OT_NONE;
    case 'p':
        switch (letter_b) {
        case 'd':
            return OT_PACKED_DOUBLE_FLOAT;
        case 'i':
            return OT_QWORD_MMX_REG;
        case 's':
            return OT_PACKED_SINGLE_FLOAT;
        default:
            return OT_NONE;
        }
    case 'q':
        return letter_b == 'q' ? OT_QQWORD : OT_NONE;
    case 's':
        switch (letter_b) {
        case 'd':
            return OT_SCALAR_DOUBLE_FLOAT;
        case 's':
            return OT_SCALAR_SINGLE_FLOAT;
        case 'i':
            return OT_DWORD_INTEGER_REG;
        default:
            return OT_NONE;
        }
    default:
        return OT_NONE;
    }
}
