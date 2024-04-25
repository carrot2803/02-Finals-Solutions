/*
a.
i. No the array is not sorted

ii.
lo  hi  mid  value
0   8   4    Monser
0   3   1    Bar
2   1   -    -    Search Terminated as lo > hi

b. 
If the array contains duplicate values, the binary search algorithm would still work
but it may not return the index of the first occurrence of the target value. 
Instead, it could return the index of any occurrence of the target value.

c.

Original array :  6, 32, 29, 8, 17, 64

i.

Pass1: 32, 6, 29, 8, 17, 64
Pass2: 32, 29, 6, 8, 17, 64
Pass3: 32, 29, 8, 6, 17, 64

ii.
Pass1: 32 29 8 17 64 6
Pass2: 32 29 17 64 8 6
Pass3: 32 29 64 17 8 6

iii.
In insertion sort, each element is compared only with the previous elements until the correct position is found, 
so if the array is already sorted, only one comparison will be made per element, resulting in a time complexity of O(n). 
On the other hand, bubble sort always compares all adjacent elements,
even if they are already in the correct order, resulting in a time complexity of O(n^2) for a sorted array.
Thus insertion sort would be more efficient

N.B both have a standard TC of O(n)

*/