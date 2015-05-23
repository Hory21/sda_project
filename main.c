#include "tooth_brush.h"

int	main()
{
	t_tooth_brush	*t;

	t = tooth_brush_construct("pulamare", 45, 1998);
	tooth_brush_print(t);
	tooth_brush_destruct(t);
	return (0);
}
