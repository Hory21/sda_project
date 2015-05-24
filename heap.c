#include "heap.h"
#include <stdlib.h>

int				child1(int i)
{
	return (i * 2 + 1);
}

int				child2(int i)
{
	return (i * 2 + 2);
}

int				parent(int i)
{
	return ((i - 1) / 2);
}

void			swap(t_heap *h, int i, int j)
{
	t_tooth_brush	*aux;

	aux = h->array[i];
	h->array[i] = h->array[j];
	h->array[j] = aux;
}

void			heap_balance_up(t_heap *h, int i)
{
	if (0 == i)
	{
		return ;
	}
	if (tooth_brush_cmp(h->array[parent(i)], h->array[i]))
	{
		swap(h, i, parent(i));
		heap_balance_up(h, parent(i));
	}
	return ;
}

void			heap_balance_down(t_heap *h, int i)
{
	if (child1(i) >= h->size)
	{
		return ;
	}
	else if ((child2(i) >= h->size) &&
			(tooth_brush_cmp(h->array[i], h->array[child1(i)])))
	{
		swap(h, i, child1(i));
		heap_balance_down(h, child1(i));
		return ;
	}
	else if (child2(i) < h->size)
	{
		if (tooth_brush_cmp(h->array[i], h->array[child1(i)]) &&
				tooth_brush_cmp(h->array[child2(i)], h->array[child1(i)]))
		{
			swap(h, i, child1(i));
			heap_balance_down(h, child1(i));
			return ;
		}
		if (tooth_brush_cmp(h->array[i], h->array[child2(i)]))
		{
			swap(h, i, child2(i));
			heap_balance_down(h, child2(i));
		}
	}
}

t_heap			*heap_construct(int max_size)
{
	t_heap	*h;

	h = (t_heap*)malloc(sizeof(t_heap));
	h->array = (t_tooth_brush**)malloc(sizeof(t_tooth_brush*) * max_size);
	h->size = 0;
	h->max_size = max_size;
	return (h);
}

void			heap_push(t_heap *h, t_tooth_brush *t)
{
	h->array[h->size] = t;
	h->size++;
	heap_balance_up(h, h->size - 1);
}

t_tooth_brush	*heap_pop(t_heap *h)
{
	swap(h, 0, h->size - 1);
	h->size--;
	heap_balance_down(h, 0);
	return (h->array[h->size]);
}

void			heap_destruct(t_heap *h)
{
	free(h->array);
	free(h);
}
