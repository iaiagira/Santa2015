# contiene il metodo per fare l'ordinamento topologico
import graph_utils

def topologicalSort(numNodes, precedences):

	ordtop = []
	resultSucc = graph_utils.fromPrecToSucc(numNodes, precedences)
	resultPrec = graph_utils.fromPrecToPrec(numNodes, precedences)
	#count = 0

	#raise Exception('The graph is not a DAG!')

	while len(ordtop) < numNodes:
		
		found = False

		for p in resultPrec:
			"""count = count + 1
			print count
			if count == numNodes*numNodes:
				raise Exception('The graph is not a DAG!')"""

			#else: 
			if len(resultPrec[p]) == 0 and p not in ordtop:
				found = True
				ordtop.append(p)

				for n in resultSucc[p]:
					resultPrec[n].remove(p)

		if not found:
			raise Exception('The graph is not a DAG!')
		 
	return ordtop


def fastSort(numNodes, precedences):
	L = []
	ordtop = []

	resultSucc = graph_utils.fromPrecToSucc(numNodes, precedences)
	resultPrec = graph_utils.fromPrecToPrec(numNodes, precedences)

	#while len(ordtop) < numNodes:

	for n in resultPrec:
		if len(resultPrec[n]) == 0:
			L.append(n)

	while len(L)>0:
		n = L.pop()
		ordtop.append(n)
		for s in resultSucc[n]:
			resultPrec[s].remove(n)
			if len(resultPrec[s]) == 0:
				L.append(s)

	if len(ordtop) != numNodes:
		raise Exception('The graph is not a DAG!')

	return ordtop


