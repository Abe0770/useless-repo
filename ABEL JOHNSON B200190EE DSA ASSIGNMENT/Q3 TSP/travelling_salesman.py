'''

REFERRED FROM OUTSIDE SOURCES

'''

from sys import maxsize
from itertools import permutations
V = 5
def tsp(graph, s):
	vertex = []
	for i in range(V):
		if i != s:
			vertex.append(i)
	min_cost = maxsize
	next_permutation=permutations(vertex)
	for i in next_permutation:
		current_cost = 0
		k = s
		for j in i:
			current_cost += graph[k][j]
			k = j
		current_cost += graph[k][s]
		min_cost = min(min_cost, current_cost)
		return min_cost
graph = [[0, 5, 0, 9, 0], [5, 0, 2, 0, 0], [0, 2, 0, 3, 0], [9, 0, 3, 0, 2], [0, 0, 0, 2, 0]]
s = 0
print(tsp(graph, s))
