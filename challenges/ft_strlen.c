int	ft_strlen(char *str)
{
	int	count;

	while(*str != '\0')
	{
		count++;
		*str++;
	}
	return (count);
}