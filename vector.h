#ifndef __VECTOR_H__
# define __VECTOR_H__

#include "tooth_brush.h"

typedef struct		s_vector
{
	t_tooth_brush	**array;
	int				size;
	int				max_size;
}					t_vector;

t_vector			*vector_construct(int max_size);
void				vector_destruct(t_vector *v);
void				vector_push(t_vector *v, t_tooth_brush *t);
t_tooth_brush		*vector_element(t_vector *v, int i);
t_tooth_brush		*vector_pop(t_vector *v);
int					vector_size(t_vector *v);
void				vector_modify(t_vector *v, int i, t_tooth_brush *t);
void				vector_add(t_vector *v, int i, t_tooth_brush *t);
void				vector_delete(t_vector *v, int i);

#endif
