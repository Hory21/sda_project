#include "vector.h"
#include "vector_iterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	print_file(char *filename, t_vector *v)
{
	t_vector_iterator	*it;
	FILE				*f;

	f = fopen(filename, "w+");
	it = vector_iterator_construct(v);
	while (vector_iterator_valid(it))
	{
		fprintf(f, "%s %d %d\n",
				vector_iterator_element(it)->name,
				vector_iterator_element(it)->length,
				vector_iterator_element(it)->year);
		vector_iterator_next(it);
	}
	vector_iterator_destruct(it);
	fclose(f);
}

int		read_file(char *filename, t_vector **v)
{
	int				i;
	char			*s;
	int				l;
	int				y;
	int				status;
	FILE			*f;
	int				n;
	t_tooth_brush	*t;

	t = 0;
	status = 0;
	s = (char*)malloc(256);
	f = fopen(filename, "r");
	if (0 == f)
	{
		status = 1;
		goto cleanup;
	}
	fscanf(f, "%d", &n);
	*v = vector_construct(n + 1);
	for (i = 0; i < n; i++)
	{
		fscanf(f, "%s", s);
		fscanf(f, "%d", &l);
		fscanf(f, "%d", &y);
		t = tooth_brush_construct(s, l, y);
		vector_push(*v, t);
		t = 0;
	}

cleanup:
	free(s);
	if (0 != f)
	{
		fclose(f);
	}
	return (status);
}

int		main()
{
	t_vector		*v;

	v = 0;
	if (0 != read_file("data.in", &v))
	{
		printf("Could not read from file!\n");
		return (1);
	}
	vector_sort(v);
	print_file("data.out", v);
	vector_destruct(v);
	return (0);
}
