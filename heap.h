#ifndef __HEAP_H__
# define __HEAP_H__

#include "tooth_brush.h"

typedef struct		s_heap
{
	t_tooth_brush	**array;
	int				size;
	int				max_size;
}					t_heap;

t_heap				*heap_construct(int max_size);
void				heap_push(t_heap *h, t_tooth_brush *t);
t_tooth_brush		*heap_pop(t_heap *h);
void				heap_destruct(t_heap *h);

#endif
