#include "qpc.h"
#include "filter.h"

int main(void)
{
	static QEvt const *l_filterQSto[10];
	filter_ctor();
	QACTIVE_START(AO_filter, 1U, l_filterQSto, Q_DIM(l_filterQSto), (void *)0, 0U, (QEvt *)0);
	return QF_run();
}
