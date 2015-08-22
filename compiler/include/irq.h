#ifndef _LIBC_SPEC_IRQ
#define _LIBC_SPEC_IRQ

void attach_irq_handler(void (*func)(void), int n);

#endif
