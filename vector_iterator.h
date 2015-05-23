#ifndef __VECTOR_ITERATOR_H__
# define __VECTOR_ITERATOR_H__

#include "vector.h"
#include "tooth_brush.h"

typedef struct		s_vector_iterator
{
	t_vector		*v;
	int				i;
}					t_vector_iterator;

t_vector_iterator	*vector_iterator_construct(t_vector *v);
int					vector_iterator_valid(t_vector_iterator *it);
t_tooth_brush		*vector_iterator_element(t_vector_iterator *it);
void				vector_iterator_next(t_vector_iterator *it);
void				vector_iterator_destruct(t_vector_iterator *it);

#endif
