#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

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
	int	i;
	int	n;

	n = vector_size(v);
	for (i = 0; i < n; i++)
	{
		tooth_brush_destruct(v->array[i]);
	}
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

t_tooth_brush	*vector_pop(t_vector *v)
{
	t_tooth_brush	*t;

	if (0 == v->size)
	{
		printf("error: poped from an empty vector!\n");
		return (0);
	}
	t = v->array[v->size - 1];
	v->array[v->size - 1] = 0;
	v->size--;
	return (t);
}

int				vector_size(t_vector *v)
{
	return (v->size);
}

void			vector_modify(t_vector *v, int i, t_tooth_brush *t)
{
	t_tooth_brush	*to_destruct;

	to_destruct = vector_element(v, i);
	v->array[i] = t;
	tooth_brush_destruct(to_destruct);
}

void			vector_add(t_vector *v, int i, t_tooth_brush *t)
{
	int	j;

	for (j = v->size; j > i; j--)
	{
		v->array[j] = v->array[j - 1];
	}
	v->array[i] = t;
	v->size++;
}

void			vector_delete(t_vector *v, int i)
{
	t_tooth_brush	*to_destruct;
	int				j;

	to_destruct = v->array[i];
	for (j = i; j <= v->size - 2; j++)
	{
		v->array[j] = v->array[j + 1];
	}
	tooth_brush_destruct(to_destruct);
	v->size--;
}

void			vector_sort(t_vector *v)
{
	t_heap	*h;

	h = heap_construct(128);
	while (v->size > 0)
	{
		heap_push(h, vector_pop(v));
	}
	while (h->size > 0)
	{
		vector_push(v, heap_pop(h));
	}
	heap_destruct(h);
}
