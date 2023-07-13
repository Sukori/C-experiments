void ft_rev_int_tab(int *tab, int size)
{
	int	*buff;
	
	*buff += size;
	while(size != 0)
	{
		*buff = *tab;
		*buff--;
		*tab++;
		size--;
	}
}