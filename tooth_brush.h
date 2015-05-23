#ifndef __TOOTH_BRUSH_H__
# define __TOOTH_BRUSH_H__

typedef struct	s_tooth_brush
{
	char		*name;
	int			length;
	int			year;
}				t_tooth_brush;

t_tooth_brush	*tooth_brush_construct(char *name, int length, int year);
void			tooth_brush_destruct(t_tooth_brush* t);
void			tooth_brush_print(t_tooth_brush* t);

#endif
