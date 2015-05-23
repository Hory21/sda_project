#include "vector_iterator.h"
#include <stdlib.h>

t_vector_iterator   *vector_iterator_construct(t_vector *v)
{
	t_vector_iterator	*it;

	it = (t_vector_iterator*)malloc(sizeof(t_vector_iterator));
	it->v = v;
	it->i = 0;
	return (it);
}

int                 vector_iterator_valid(t_vector_iterator *it)
{
	if ((it->i >= it->v->size) || (it->i < 0))
	{
		return (0);
	}
	return (1);
}

t_tooth_brush       *vector_iterator_element(t_vector_iterator *it)
{
	return(vector_element(it->v, it->i));
}

void                vector_iterator_next(t_vector_iterator *it)
{
	it->i++;
}

void                vector_iterator_destruct(t_vector_iterator *it)
{
	free(it);
}
