# contiene metodi per conversione formato grafo

def fromPrecToSucc(numNodes, precedences):
	result = {}

	for n in xrange(0, numNodes):
		result[n] = []

	for p in precedences:
		result[p[0]].append(p[1])

	return result


def fromPrecToPrec(numNodes, precedences):
	pass


def fromPrecToMatrix(numNodes, precedences):
	pass