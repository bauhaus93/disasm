#ifndef OPERAND_TYPE_H
#define OPERAND_TYPE_H

typedef enum {
    OT_NONE,
    OT_TWO_WORD_DWORD_MEM,  // a
    OT_BYTE,                // b
    OT_BYTE_WORD,           // c
    OT_DWORD,               // d
    OT_DQWORD,              // dq
    OT_POINTER,             // p
    OT_PACKED_DOUBLE_FLOAT, // pd
    OT_QWORD_MMX_REG,       // pi
    OT_PACKED_SINGLE_FLOAT, // ps
    OT_QWORD,               // q,
    OT_QQWORD,              // qq
    OT_PSEUDO_DESCRIPTOR,   // s
    OT_SCALAR_DOUBLE_FLOAT, // sd
    OT_SCALAR_SINGLE_FLOAT, // ss
    OT_DWORD_INTEGER_REG,   // si
    OT_WORD_DWORD_QWORD,    // v
    OT_WORD,                // w
    OT_QQ_DQ_WORD,          // x
    OT_WORD_DWORD           // z
} OperandType;

#ifdef __cplusplus
extern "C" {
#endif

OperandType get_operand_type_by_letter(char letter);
OperandType get_operand_type_by_letters(char letter_a, char letter_b);

#ifdef __cplusplus
}
#endif

#endif // OPERAND_TYPE_H
