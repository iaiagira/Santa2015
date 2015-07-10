# contiene metodi per conversione formato grafo

def fromPrecToSucc(numNodes, precedences):
	result = {}

	for n in xrange(0, numNodes):
		result[n] = []

	for p in precedences:
		result[p[0]].append(p[1])

	return result


def fromPrecToPrec(numNodes, precedences):
	result = {}

	for n in xrange(0, numNodes):
		result[n] = []
	for p in precedences:
		result[p[1]].append(p[0])
	return result


def fromPrecToMatrix(numNodes, precedences):
	result = []

	for r in xrange(0, numNodes):
		result.append([])
		for c in xrange(0, numNodes):
			result[r].append(0)

	for p in precedences:
		result[p[0]][p[1]]=1
	return result


def generateRandomDAG(numNodes):
	pass




