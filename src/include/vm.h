/*******************************************************************************
 * filename    : vm.h
 * author      : Zac Brown <zac@zacbrown.org>
 * date        : 11.17.2009
 * description : vm relavent code
 ******************************************************************************/

#ifndef __VM_H__
#define __VM_H__

#include "stack.h"

#define MAX_OP_LEN 256

enum instr_enum
{
    /* arithmetic related */
    IADD,
    FADD,
    ISUB,
    FSUB,
    IMUL,
    FMUL,
    IDIV,
    FDIV,
    MOD, /* int modulo */
    IPOW, /* int power */
    FPOW, /* float power */
    /* bitwise operators */
    BOR, /* logical or */
    BAND, /* logical and */
    LSHIFT, /* left shift */
    RSHIFT, /* right shift */
    I2F, /* int to float */
    F2I, /* float to int */
    INEG, /* negate int */
    FNEG, /* negate float */
    /* control related */
    ICMP,
    FCMP,
    CCMP,
    SCMP,
    JMP,
    JMPZ,
    LAND,
    LOR,
    /* data oriented */
    IPUSH,
    FPUSH,
    CPUSH,
    SPUSH,
    DROP,
    DUP,
    DUP2,
    SWAP,
    ILOAD, /* int load */
    FLOAD, /* float load */
    CLOAD, /* char load */
    SLOAD, /* string load */
    ISTOR, /* int store */
    FSTOR, /* float store */
    CSTOR, /* char store */
    SSTOR, /* string store */
    TYPE,
    /* arrays */
    ARRAY,
    ARRLEN,
    ARRIND,
    /* debug/sys oriented */
    HALT,
    PRINT,
    DUMP,
    LAST_NOOP_INSTR
};

static const char *instr_strings[] = {
    "IADD",
    "FADD",
    "ISUB",
    "FSUB",
    "IMUL",
    "FMUL",
    "IDIV",
    "FDIV",
    "MOD",
    "IPOW",
    "FPOW",
    "BOR",
    "BAND",
    "LSHIFT",
    "RSHIFT",
    "I2F",
    "F2I",
    "INEG",
    "FNEG",
    "ICMP",
    "FCMP",
    "CCMP",
    "SCMP",
    "JMP",
    "JMPZ",
    "LAND",
    "LOR",
    "IPUSH",
    "FPUSH",
    "CPUSH",
    "SPUSH",
    "DROP",
    "DUP",
    "DUP2",
    "SWAP",
    "ILOAD",
    "FLOAD",
    "CLOAD",
    "SLOAD",
    "ISTOR",
    "FSTOR",
    "CSTOR",
    "SSTOR",
    "TYPE",
    "ARRAY",
    "ARRLEN",
    "ARRIND",
    "HALT",
    "PRINT",
    "DUMP"
};

typedef void* instruction_t;

typedef struct
{
    instruction_t instr;
    char instr_str[6];
    data_elem_p data;
} operation_t;
typedef operation_t* operation_p;

typedef struct
{
    char* label;
    int line;
} label_t;
typedef label_t* label_p;

/* Function    : parse_file
 * Description : parse a source file
 * Arguments   :
 *   filename  : character string for filename path off source file
 *
 * Returns     :
 *   -1        : file not found
 *   0         : success
 */
int parse_file(char*);

/* Function    : usage
 * Description : prints usage information
 * Arguments   :
 *
 * Returns     :
 */
void usage(void);

/* Function    : get_label_loc
 * Description : gets line number for a label
 * Arguments   :
 *   label     : character string referencing a label
 *
 * Returns     :
 *   -1        : non-existent label
 *   int >= 0  : line number for <label>
 */
int get_label_loc(char*);

/* Function    : execute_goto
 * Description : executes virtual machine with goto style opcode dispatch
 * Arguments   :
 *
 * Returns     :
 */
void execute_goto(void);

#endif
