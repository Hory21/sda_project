#include "vector.h"
#include <stdlib.h>

t_vector		*vector_construct(int max_size)
{
	t_vector	*v;

	v = (t_vector*)malloc(sizeof(t_vector));
	v->array = (t_tooth_brush**)malloc(sizeof(t_tooth_brush*) * max_size);
	v->size = 0;
	v->max_size = max_size;
	return (v);
}

void			vector_destruct(t_vector *v)
{
	free(v->array);
	free(v);
}

void			vector_push(t_vector *v, t_tooth_brush *t)
{
	v->array[v->size] = t;
	v->size++;
}

t_tooth_brush	*vector_element(t_vector *v, int i)
{
	return(v->array[i]);
}
