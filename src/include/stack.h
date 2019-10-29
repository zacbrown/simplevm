/*******************************************************************************
 * filename    : stack.h
 * author      : Zac Brown <zac@zacbrown.org>
 * date        : 11.17.2009
 * description : stack implementation header
 ******************************************************************************/

#ifndef __SIMPLEVM_STACK_H__
#define __SIMPLEVM_STACK_H__

#define MAX_STR_LEN 128

/* macros to help */
#define CHECK_NULL(ptr, msg, ln, ret) if (ptr==NULL) { printf(msg,ln); \
        return ret; }

/*******************************************************************************
 * STACK DATA STRUCTURES
 ******************************************************************************/

/* our simple VM supports 4 basic types below */
typedef union
{
    int dat_i;
    float dat_f;
    char dat_c;
    char dat_s[MAX_STR_LEN];
} data_t;
typedef data_t* data_p;

typedef struct
{
    data_t data;
    int type;
} data_elem_t;
typedef data_elem_t* data_elem_p;


/* stack element structure  */
struct _stack_element_t
{
    data_elem_p data;
    /*
     * Data type masks:
     *     empty   : 0x00000 -- this is only for the base element of the stack
     *     integer : 0x00001
     *     float   : 0x00010
     *     char    : 0x00100
     *     string  : 0x01000
     *     array   : 0x10000
     */
    int type;
    int size; /* for use with arrays */
    struct _stack_element_t* next;
    struct _stack_element_t* previous;
};
typedef struct _stack_element_t stack_element_t;
typedef stack_element_t* stack_element_p;

/* stack structure */
struct _simplevm_stack_t
{
    stack_element_p top;
    stack_element_p base;
    long size;
};
typedef struct _simplevm_stack_t simplevm_stack_t;
typedef simplevm_stack_t* simplevm_stack_p;




/*******************************************************************************
 * STACK FUNCTIONS
 ******************************************************************************/

/* Function    : simplevm_stack_init
 * Description : initialize stack with a base element to avoid nasty NULL-ness
 * Arguments   :
 *   stack     : pointer to a stack_t
 *
 * Returns     :
 *   -1        : null stack_p pointer
 *    0        : success
 */
int simplevm_stack_init(simplevm_stack_p);

/* Function    : simplevm_stack_peek
 * Description : get top element of stack without removing it
 * Arguments   :
 *   stack     : pointer to a stack_t
 *
 * Returns     :
 *   elem ptr  : if stack not empty
 *   NULL      : if stack empty or null stack pointer
 */
stack_element_p simplevm_stack_peek(simplevm_stack_p);

/* Function    : simplevm_stack_pop
 * Description : get top element of stack and remove it
 * Arguments   :
 *   stack     : pointer to a stack_t
 *
 * Returns     :
 *   elem ptr  : if stack not empty
 *   NULL      : if stack empty or null stack pointer
 */
stack_element_p simplevm_stack_pop(simplevm_stack_p);

/* Function    : simplevm_stack_push
 * Description : push element on top of stack
 * Arguments   :
 *   stack     : pointer to a stack_t
 *   elem      : pointer to stack element
 *
 * Returns     :
 *   -2        : null stack_element_p pointer
 *   -1        : null stack_p
 *    0        : success
 */
int simplevm_stack_push(simplevm_stack_p, stack_element_p);

/* Function    : simplevm_stack_size
 * Description : get size of stack
 * Arguments   :
 *   stack     : pointer to a stack_t
 *
 * Returns     :
 *   -1        : null stack pointer
 *   long >= 0 : stack size
 */
long simplevm_stack_size(simplevm_stack_p);

#endif
