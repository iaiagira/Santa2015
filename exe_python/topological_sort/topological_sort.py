# contiene il metodo per fare l'ordinamento topologico
import graph_utils

def topologicalSort(numNodes, precedences):

	ordtop = []
	resultSucc = graph_utils.fromPrecToSucc(numNodes, precedences)
	resultPrec = graph_utils.fromPrecToPrec(numNodes, precedences)
	count = 0
	#raise Exception('The graph is not a DAG!')

	while len(ordtop) < numNodes:
		for p in resultPrec:
			count = count + 1
			print count
			if count == numNodes*2:
				raise Exception('The graph is not a DAG!')
				break
			else: 
				if len(resultPrec[p]) == 0 and p not in ordtop:
					ordtop.append(p)

					print ordtop
					for n in resultSucc[p]:
						print n,p
						resultPrec[n].remove(p)

	return ordtop


	
