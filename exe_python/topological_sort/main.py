import graph_utils
import topological_sort


numNodes = 7
#precedences = [(0,1),(0,3),(2,4),(0,2),(3,4),(4,5),(0,6)]

# cycle example:
precedences = [(6,1),(6,3),(2,4),(4,2),(6,2),(3,4),(4,5),(6,0)]

#resultSucc = graph_utils.fromPrecToSucc(numNodes, precedences)
#resultPrec = graph_utils.fromPrecToPrec(numNodes, precedences)

print topological_sort.topologicalSort(numNodes, precedences)
#print graph_utils.fromPrecToMatrix(numNodes, precedences)
