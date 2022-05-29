from collections import defaultdict


class Graph:


	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, u, v):
		self.graph[u].append(v)

	def DFSUtil(self, v, visited):
		visited.add(v)
		print(v, end=' ')
		for neighbour in self.graph[v]:
			if neighbour not in visited:
				self.DFSUtil(neighbour, visited)

	def DFS(self, v):
		visited = set()
		self.DFSUtil(v, visited)


d = Graph()
d.addEdge(1, 4)
d.addEdge(6, 5)
d.addEdge(2, 5)
d.addEdge(7, 6)
d.addEdge(3, 9)
d.addEdge(4, 7)

d.DFS(2)