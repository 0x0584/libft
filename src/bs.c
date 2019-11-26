/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:41:14 by archid-           #+#    #+#             */
/*   Updated: 2019/11/26 18:02:27 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int binary_search(int val, int *arr, int low, int high)
{
	int mid;

	if (low > high)
		return (-1);
	mid = (low + high) / 2;
	if (arr[mid] == val)
		return (mid);
	else if (val > arr[mid])
		return (binary_search(val, arr, mid + 1, high));
    return (binary_search(val, arr, low, mid - 1));
}

int binary_search_min(int *arr, int low, int high)
{
	int mid;

	mid = (low + high) / 2;
	if (low > high)
		return (-1);
	if (arr[low] < arr[high] || low == high)
		return (low);
	else if (arr[mid] < arr[mid + 1] && arr[mid] < arr[mid - 1])
		return (mid);
	else if (arr[high] < arr[mid])
		return (binary_search_min(arr, mid + 1, high));
	else
		return (binary_search_min(arr, low, mid - 1));
}

int binary_search_range_sorted(int val, int *arr, int low, int high)
{
	int n_rots;

	n_rots = 0;
	if (val < arr[low] || val > arr[high])
		return (0);
	while (n_rots++ < (int)high / 2)
	{
		if (val < arr[n_rots] && val > arr[n_rots - 1])
			return (n_rots);
		else if (val < arr[high - n_rots + 1] && val > arr[high - n_rots])
			return (n_rots * (-1));
	}
	return (0);
}

int binary_search_range_roted(int val, int *arr, int low, int high)
{
	int old_min;
	int old_max;
	int n_rots;

	old_min = binary_search_min(arr, low, high);
	old_max = (old_min == 0 ? high : old_min - 1);
	n_rots = 0;
	if (val < arr[low] && val > arr[high])
		return (0);
	if (val < arr[old_min] || val > arr[old_max])
	{
		n_rots = high - old_min - 1;
		return (n_rots < 0 && ABS(n_rots) < (int)old_max + 1)
					? n_rots : (old_max + 1);
	}
	while (n_rots++ < (int)high / 2)
	{
		if (val < arr[n_rots] && val > arr[n_rots - 1])
			return n_rots;
		if (val < arr[high - n_rots + 1] && val > arr[high - n_rots])
			return (n_rots * (-1));
	}
	return (n_rots);
}

int binary_search_range(int val, int *arr, int low, int high)
{
	if (arr[low] < arr[high])
		return (binary_search_range_sorted(val, arr, low, high));
	return (binary_search_range_roted(val, arr, low, high));
}
