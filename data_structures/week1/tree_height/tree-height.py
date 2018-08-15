# python3

import sys, threading, os
sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

class Node:
	def __init__(self):
		self.children = []
		self.height = 0

class TreeHeight:
	root = 0
	def read(self,data):
	#def read(self):
		#self.n = int(sys.stdin.readline())
		#self.parent = list(map(int, sys.stdin.readline().split()))
		first = data.find('\n')
		self.n = int(data[0:first])
		self.parent = list(map(int, data[first+1:].split()))
		self.nodes = []
		self.height = 0
		for i in range(self.n):
			newnode = Node()
			self.nodes.append(newnode)
			self.nodes[i].parent = self.parent[i]
			

		for i, el in enumerate(self.parent):
			if el == -1:
				self.root = i
			else:
				self.nodes[el].children.append(self.nodes[i])

	def compute_height(self):
		if self.nodes[self.root] == None: return
		cheight = 0
		maxheight = 0
		cue = []
		cue.append(self.nodes[self.root])
		depths = []
		currentheight = 0
		while len(cue) > 0:
			current = cue.pop(0)
			if current.height < currentheight:
				currentheight = current.height
			if len(current.children) > 0:
				for i in current.children:
					i.height = current.height+1
					cue.append(i)
			else:
				if current.height > maxheight:
					maxheight = current.height
		return maxheight+1

			

	'''
	def compute_height(self):
		# Replace this code with a faster implementation
		maxHeight = 0
		for vertex in range(self.n):
			height = 0
			i = vertex
			while i != -1:
				height += 1
				i = self.parent[i]
			maxHeight = max(maxHeight, height);
		return maxHeight;
	'''

def main():
	cdir = os.fsencode(dirloc)
	answers = []
	tests = []
	for ff in os.listdir(cdir):
		fn = os.fsdecode(dirloc.encode('utf-8')+ff)
		if fn.endswith(".a"): 
			#answers.append(f.read().encode('utf-8'))
			#answers.append(f.read())
			answers.append(ff)
		else:
			#tests.append(f.read().encode('utf-8'))
			#tests.append(f.read())
			tests.append(ff)


	oans = []
	otest = []
	for x in answers:
		#handle = x.find('.')
		check = x[0:2]
		for j in tests:
			if check == j:
				oans.append(x)
				otest.append(j)

	#print(oans)
	#print(otest)
	dans = []
	dtest = []
	for i in range(len(oans)):
		g = os.fsdecode(dirloc.encode('utf-8')+oans[i])
		f = open(g,'r')
		dans.append(f.read())
		f.close()
		g = os.fsdecode(dirloc.encode('utf-8')+otest[i])
		f = open(g, 'r')
		dtest.append(f.read())
		f.close()

	#tree = TreeHeight()
	#tree.read()
	#print(tree.compute_height())

	'''
	tree = TreeHeight()
	tree.read(dtest[-1])
	#print(dtest[-1])
	#print(dans[-1])
	ans = tree.compute_height()
	print(ans)
	'''
	for i,el in enumerate(dtest):
		tree = TreeHeight()
		tree.read(el)
		ans = tree.compute_height()
		#print(type(ans))
		#print(type(dans[i]))
		if int(dans[i]) == ans:
			print("OK")
		else:
			print("Incorrect answer: ", ans, " vs. correct ", dans[i])

threading.Thread(target=main).start()
