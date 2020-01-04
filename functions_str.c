/**
 * _itoa - function convert the integer to string
 * @number: input the number integer
 *
 *Return: the string of the number integer.
 */


char *_itoa(int number)
{
	unsigned int tmp;
	int div = 1, i = 0;
	char *str;

	str = malloc(sizeof(char) * 11);
	if (str == NULL)
		return (NULL);
	if (number < 0)
	{
		str[i++] = '-';
		tmp = number * -1;
	}
	else
		tmp = number;

	while (tmp / div > 9)
		div *= 10;
	while (div != 0)
	{
		str[i] = (tmp / div) + '0';
		tmp %= div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
