#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void	vector_print(t_vector* v)
{
	int	i;

	for (i = 0; i < v->size; i++)
	{
		tooth_brush_print(vector_element(v, i));
	}
}

int		main()
{
	t_tooth_brush	*t;
	t_tooth_brush	*t2;
	t_tooth_brush	*t3;
	t_vector		*v;

	v = vector_construct(128);
	t = tooth_brush_construct("pulamare", 67, 2000);
	t2 = tooth_brush_construct("pulamare", 45, 2013);
	t3 = tooth_brush_construct("pulamare", 77, 1998);

	vector_push(v, t);
	vector_push(v, t2);
	vector_push(v, t3);
	vector_print(v);
	vector_pop(v);
	printf("\n");
	vector_print(v);

	tooth_brush_destruct(t);
	tooth_brush_destruct(t2);
	tooth_brush_destruct(t3);
	vector_destruct(v);
	return (0);
}
