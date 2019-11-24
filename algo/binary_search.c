/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 23:26:01 by archid-           #+#    #+#             */
/*   Updated: 2019/11/24 22:31:30 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the following binary_search function require a normal or rotated
** sorted unique interger array
*/

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

	if (low > high)				/* !(low <= high) */
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
			/* left is sorted -- more half elements */
			if (cmp(val, arr[low]) >= 0 && cmp(val, arr[mid]) < 0)
				return binary_search_recu(val, arr, low, mid - 1, cmp);
			else
				return binary_search_rot(val, arr, mid + 1, high, cmp);
		}
		else
		{
			/* right is sorted -- less half elements */
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

/* FIXME: shoudl return the index of the lowest number of rots */
int binary_search_range(int val, int *arr, size_t low, size_t high,
						int (*cmp)(int, int))
{
	size_t old_min;
	size_t old_max;
	int		n_rots;

	old_min = binary_search_find_min(arr, low, high, cmp);

	if (old_min == 0)
		old_max = high;
	else
		old_max = old_min - 1;
	n_rots = 0;
	if (old_min == 0)
	{
		if (cmp(val, arr[old_min]) < 0 || cmp(val, arr[old_max]) > 0)
			return (0);
		while (n_rots++ < (int)high / 2)
		{
			if (cmp(val, arr[n_rots]) < 0
					&& cmp(val, arr[n_rots - 1]) > 0)
		 		return n_rots;
			else if (cmp(val, arr[old_max - n_rots + 1]) < 0
					 && cmp(val, arr[old_max - n_rots]) > 0)
				return (n_rots * (-1));
		}
	}
	else
	{
		if (cmp(val, arr[0]) < 0 && cmp(val, arr[high]) > 0)
				return 0;
		if (cmp(val, arr[old_min]) < 0 || cmp(val, arr[old_max]) > 0)
		{
			n_rots = high - old_min - 1;
			if (n_rots < 0 && ABS(n_rots) < old_max + 1)
				return n_rots;
			else
				return (old_max + 1);
		}
		while (n_rots++ < (int)high / 2)
		{
			if (cmp(val, arr[n_rots]) < 0
					&& cmp(val, arr[n_rots - 1]) > 0)
				return n_rots;
			if (cmp(val, arr[high - n_rots + 1]) < 0
					 && cmp(val, arr[high - n_rots]) > 0)
				return (n_rots * (-1));
		}
	}
	return (n_rots);
}
