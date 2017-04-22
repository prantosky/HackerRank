from functools import reduce

count = 0


def func(num, num_list, sum_list):
    """ *num* is the number for which the sum is to be obtained
    *num_list* is the list that will contain all the individual elements whose sum of nth power sum will add up to x
    *sum_list is the current sum of nth power of elements of list num_list"""
    global count
    for i in range(max(num_list, default=1), num):
        if i in num_list:
            continue
        j = pow(i, n)
        if j > x:
            return
        else:
            if sum_list + j == x:
                num_list.append(i)
                # print(num_list)
                count += 1
                return
            elif sum_list + j > x:
                return
            else:
                new_list = [d for d in num_list]
                new_list.append(i)
                func(num - j, new_list, sum_list + j)


x = int(input())
n = int(input())
func(x, [], 0)
print(count)
