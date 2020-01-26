/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:26:01 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 01:06:45 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ascending_order(int a, int b)
{
	return (a - b);
}

int descending_order(int a, int b)
{
	return (b - a);
}

int binary_search(int val, int *arr, size_t size, int cmp(int, int))
{
	int mid, low, high;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (cmp(arr[mid], val) == 0)
			return (mid);
		else if (cmp(val, arr[mid]) > 0)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

int binary_search_recu(int val, int *arr, size_t low, size_t high,
						int (*cmp)(int, int))
{
	size_t mid;

	if (low > high)
		return (-1);
	mid = (low + high) / 2;
	if (cmp(arr[mid], val) == 0)
		return (mid);
	else if (cmp(val, arr[mid]) > 0)
		return (binary_search_recu(val, arr, mid + 1, high, cmp));
    return (binary_search_recu(val, arr, low, mid - 1, cmp));
}

int binary_search_rot(int val, int *arr ,size_t low, size_t high,
						int (*cmp)(int, int))
{
	size_t mid;

	if (low > high)
		return (-1);
	mid = (low + high) / 2;
	if (cmp(val, arr[mid]) == 0)
		return (mid);
	else if (cmp(val, arr[low]) == 0)
		return (low);
	else if (cmp(val, arr[high]) == 0)
		return (high);
	else if (cmp(arr[low], arr[high]) > 0)
	{
		if (cmp(arr[low], arr[mid]) < 0)
		{
			if (cmp(val, arr[low]) >= 0 && cmp(val, arr[mid]) < 0)
				return binary_search_recu(val, arr, low, mid - 1, cmp);
			else
				return binary_search_rot(val, arr, mid + 1, high, cmp);
		}
		else
		{
			if (cmp(val, arr[mid]) > 0 && cmp(val, arr[high]) <= 0)
				return binary_search_recu(val, arr, mid + 1, high, cmp);
			else
				return binary_search_rot(val, arr, low, mid - 1, cmp);
		}
	}
	return (binary_search_recu(val, arr, low, high, cmp));
}

int binary_search_find_min(int *arr, size_t low, size_t high,
							int (*cmp)(int, int))
{
	size_t mid;

	mid = (low + high) / 2;
	if (low > high)
		return (-1);
	if (cmp(arr[low], arr[high]) < 0 || low == high)
		return (low);
	else if (cmp(arr[mid], arr[mid + 1]) < 0
				&& cmp(arr[mid], arr[mid - 1]) < 0)
		return (mid);
	else if (cmp(arr[high], arr[mid]) < 0)
		return binary_search_find_min(arr, mid + 1, high, cmp);
	else
		return binary_search_find_min(arr, low, mid - 1, cmp);
}
