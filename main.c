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
	vector_iterator_destruct(it);
}

int		main()
{
	t_tooth_brush	*t;
	t_tooth_brush	*t2;
	t_tooth_brush	*t3, *t4, *t5, *t6, *t7;
	t_vector		*v;

	v = vector_construct(128);
	t = tooth_brush_construct("pulare", 67, 2000);
	t2 = tooth_brush_construct("pulamare", 45, 2013);
	t3 = tooth_brush_construct("ulaare", 102, 1998);
	t4 = tooth_brush_construct("plamar", 39, 1998);
	t5 = tooth_brush_construct("puaare", 22, 1998);
	t6 = tooth_brush_construct("ulamare", 93, 1998);
	t7 = tooth_brush_construct("pulare", 68, 1998);

	vector_push(v, t);
	vector_push(v, t2);
	vector_push(v, t3);
	vector_push(v, t4);
	vector_push(v, t5);
	vector_push(v, t6);
	vector_push(v, t7);
	vector_print(v);
	printf("\n");
	vector_sort(v);
	vector_print(v);

	tooth_brush_destruct(t);
	tooth_brush_destruct(t2);
	tooth_brush_destruct(t3);
	tooth_brush_destruct(t4);
	tooth_brush_destruct(t5);
	tooth_brush_destruct(t6);
	tooth_brush_destruct(t7);
	vector_destruct(v);
	return (0);
}
