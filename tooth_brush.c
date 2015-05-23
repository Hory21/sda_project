#include "tooth_brush.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

t_tooth_brush	*tooth_brush_construct(char *name, int length, int year)
{
	t_tooth_brush	*tbrush;

	tbrush = (t_tooth_brush*)malloc(sizeof(t_tooth_brush));
	tbrush->name = strdup(name);
	tbrush->length = length;
	tbrush->year = year;
	return (tbrush);
}

void			tooth_brush_destruct(t_tooth_brush* t)
{
	free(t->name);
	free(t);
}

void			tooth_brush_print(t_tooth_brush* t)
{
	printf("%s %d %d\n", t->name, t->length, t->year);
}
