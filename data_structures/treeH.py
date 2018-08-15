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
	def read(self):
		self.n = int(sys.stdin.readline())
		self.parent = list(map(int, sys.stdin.readline().split()))
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

			


def main():

	tree = TreeHeight()
	tree.read()
	print(tree.compute_height())

threading.Thread(target=main).start()
