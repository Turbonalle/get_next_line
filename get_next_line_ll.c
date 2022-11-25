typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}					t_node;

typedef struct s_list
{
	int				*content;
	struct s_node	*node;
	struct s_list	*next;
}					t_list;

void	read_file(t_list **list, int fd)
{
	t_list *tmp;

	if (list && tmp)
	{
		tmp = *list;
		while (tmp->next)
		{
			if (tmp->content != fd)
				tmp = tmp->next;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;


	return (line);
}