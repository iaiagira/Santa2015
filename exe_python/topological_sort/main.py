import graph_utils
#from topological_sort import * #importa tutte le funzioni classi variabili ecc.. senza necessita' di ripetere il nome della libreria (topological_sort)
#import topological_sort as ts # importa la libreria, ma qui la chiamerai come il suo alias (ts)
import topological_sort
import time
import random
import sys

sys.argv

if len(sys.argv) != 3:
	print 'Usage: python main.py INPUT_FILE OUTPUT_FILE'

else:

	inputFilename = sys.argv[1]
	outputFilename = sys.argv[2]

	inputFile = open(inputFilename, 'r')

	#data = inputFile.read()
	#lines = data.split("\n")

	precedences = []
	count=0
	for i in inputFile: #i itera sulle linee del file
		if count == 0:
			numNodes = int(i)
		else:
			j = i.split(",")
			#j = map(int, j)
			precedences.append((int(j[0]), int(j[1])))
		count = count+1

	inputFile.close()

	"""
	numNodes = elements.pop(0)[0]

	elements = sum(elements, [])
	print elements


	for k in xrange(0,len(elements),2):	
		precedences.append((elements[k],elements[k+1]))
	print precedences
	"""

	#precedences = [(0,1),(0,3),(2,4),(0,2),(3,4),(4,5),(5,6)]

	# cycle example:
	#precedences = [(6,1),(6,3),(2,4),(4,2),(6,2),(3,4),(4,5),(6,0)]
	#precedences = [(6,5),(5,4),(4,3),(3,2),(2,1),(1,0)]

	#precedences = graph_utils.generateRandomDAG(numNodes)

	#resultSucc = graph_utils.fromPrecToSucc(numNodes, precedences)
	#resultPrec = graph_utils.fromPrecToPrec(numNodes, precedences)

	startTime = time.time()
	#ordtop = topological_sort.topologicalSort(numNodes, precedences)

	try:
		#1 / 0 # questo crea un eccezione inatesa :)
		ordtop = topological_sort.fastSort(numNodes, precedences)

		endTime = time.time()
		delta = endTime - startTime

		with open(outputFilename, 'w') as outputFile: #automatica chiusura del file aperto alla fine del with, e' utile con le eccezioni che altrimenti non chiuderebbero il file
			outputFile.write("Ordine Topologico del grafo:"+str(ordtop)+"\nTempo di esecuzione:"+str(delta)+"\n")

		print ordtop
		print delta

	except topological_sort.NotADAGException:

		endTime = time.time()
		delta = endTime - startTime
		with open(outputFilename, 'w') as outputFile: #automatica chiusura del file aperto alla fine del with, e' utile con le eccezioni che altrimenti non chiuderebbero il file
			outputFile.write("Il grafo non e' un DAG!\nTempo di esecuzione:"+str(delta)+"\n")
		
		print 'Il grafo non e\' un DAG' 
		print delta

	except Exception as e:
		print 'e\' successo qualcosa di inatteso: ' + str(e)





	#print graph_utils.fromPrecToMatrix(numNodes, precedences)
