int		strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	strncpy(char *s1, const char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		s1[i] = s2[i];
}
