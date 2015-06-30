import graph_utils


numNodes = 5
precedences = [(0,1),(0,2),(0,3),(2,4),(3,4)]


succList = graph_utils.fromPrecToSucc(numNodes, precedences)

print succList