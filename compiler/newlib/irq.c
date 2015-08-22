extern void *catch_interrupt(void (*func)(void), int n);

void attach_irq_handler(void (*func)(void), int n)
{
	(void)catch_interrupt(func, n);
}
