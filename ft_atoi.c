
#include "push_swap.h"

// 数字かどうか
static int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

// 空白かどうか
static int	is_space(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

long	ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	// 1. 空白スキップ
	while (is_space(str[i]))
		i++;
	
	// 2. 符号チェック
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// 3. 数字変換
	while (is_digit(str[i]))
	{
		// オーバーフローする前に返すという手もあるが、
		// 今回はlongで受け取ってmain側でチェックする方針なのでシンプルに計算
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

