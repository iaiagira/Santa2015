import graph_utils
import topological_sort
import time
import random


inputFile = open('example.graph','r')
#for line in inputFile:
#	print 'linea: ' + line
data = inputFile.read()
inputFile.close()

lines = data.split("\n")

print lines




numNodes = 100
#precedences = [(0,1),(0,3),(2,4),(0,2),(3,4),(4,5),(5,6)]

# cycle example:
#precedences = [(6,1),(6,3),(2,4),(4,2),(6,2),(3,4),(4,5),(6,0)]
#precedences = [(6,5),(5,4),(4,3),(3,2),(2,1),(1,0)]

precedences = graph_utils.generateRandomDAG(numNodes)

#resultSucc = graph_utils.fromPrecToSucc(numNodes, precedences)
#resultPrec = graph_utils.fromPrecToPrec(numNodes, precedences)

startTime = time.time()
#ordtop = topological_sort.topologicalSort(numNodes, precedences)
ordtop = topological_sort.fastSort(numNodes, precedences)

endTime = time.time()

print ordtop

print endTime - startTime

#print graph_utils.fromPrecToMatrix(numNodes, precedences)
