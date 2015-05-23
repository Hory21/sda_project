#include "vector.h"
#include "vector_iterator.h"
#include <stdio.h>
#include <stdlib.h>

void	vector_print(t_vector *v)
{
	t_vector_iterator	*it;

	it = vector_iterator_construct(v);
	while (vector_iterator_valid(it))
	{
		printf("%s %d %d\n",
				vector_iterator_element(it)->name,
				vector_iterator_element(it)->length,
				vector_iterator_element(it)->year);
		vector_iterator_next(it);
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
