import graph_utils
import topological_sort
import time
import random


numNodes = 7
#precedences = [(0,1),(0,3),(2,4),(0,2),(3,4),(4,5),(0,6)]

# cycle example:
precedences = [(6,1),(6,3),(2,4),(4,2),(6,2),(3,4),(4,5),(6,0)]

precedences = [(6,5),(5,4),(4,3),(3,2),(2,1),(1,0)]


numNodes = 1000
precedences = []
#for i in xrange(numNodes - 1, -1, -1):
for i in xrange(0, numNodes, 1):
	for j in xrange(0, i, 1):
		precedences.append((i,j))

random.shuffle(precedences)


#resultSucc = graph_utils.fromPrecToSucc(numNodes, precedences)
#resultPrec = graph_utils.fromPrecToPrec(numNodes, precedences)

startTime = time.time()
print topological_sort.topologicalSort(numNodes, precedences)
endTime = time.time()

print endTime - startTime

#print graph_utils.fromPrecToMatrix(numNodes, precedences)
