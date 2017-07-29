class Node:
	def __init__(self,data):
		self.data = data
		self.next = None

	def set_data(self, data):
		self.data = data

	def get_data(self):
		return self.data

	def set_next(self, next):
		self.next = next

	def get_next(self):
		return self.next

class LinkedList:
	def __init__(self):
		self.head = None
		self.length = 0

	def addNode(self,node):
		if self.length == 0:
			self.addBeg(node)
		else:
			self.addLast(node)

	def addBeg(self, node):
		newnode = node
		newnode.next = self.head
		self.head = newnode
		self.length += 1

	def addLast(self,node):
		current = self.head
		while current.next != None:
			current = current.next

		newnode = node
		newnode.next = None
		current.next = newnode
		self.length += 1

	def addAtPos(self, pos, node):
		count = 0
		current = self.head
		previous = self.head

		if pos > self.length or pos < 0:
			print("Invalid position")

		else:
			while current.next != None or count < pos :
				count += 1
				if count == pos:
					previous.next = node
					node.next = current
					self.length += 1
					return
				else:
					previous = current
					current = current.next

	def addAfterValue(self, data, node):
		newNode = node
		currentnode = self.head
		 
		while currentnode.next != None or currentnode.data != data:
			if currentnode.data == data:
				newNode.next = currentnode.next
				currentnode.next = newNode
				self.length = self.length + 1
				return
			else:
				currentnode = currentnode.next
				 
		print ("The data provided is not present")

	def delBeg(self):
		if self.length == 0:
			print ("List is Empty")
		else:
			self.head = self.head.next
			self.length -= 1

	def delLast(self):
		if self.length == 0:
			print ("The list is empty")
		else:
			currentnode = self.head
			previousnode = self.head
			 
			while currentnode.next != None:
				previousnode = currentnode
				currentnode = currentnode.next
				 
			previousnode.next = None
			 
			self.length -= 1

	def delVal(self,val):
		current = self.head
		prev = self.head
		while current != None or current.data != val:
			if current.data == val :
				prev.next = current.next
				self.length -= 1
				return
			else:
				prev = current
				current = current.next

		print("data aint present")

	def deleteAtPos(self, pos):
		count = 0
		currentnode = self.head
		previousnode = self.head
 
		if pos > self.length or pos < 0:
			print ("The position does not exist. Please enter a valid position")
		elif pos == 1:
			self.delBeg()
			#self.length -= 1
		else:        
			while currentnode.next != None or count < pos:
				count = count + 1
				if count == pos:
					previousnode.next = currentnode.next
					self.length -= 1
					return
				else:
					previousnode = currentnode
					currentnode = currentnode.next

	def print_list(self):
		nodeList = []
		currentnode = self.head
		while currentnode != None:
			nodeList.append(currentnode.data)
			currentnode = currentnode.next 
			 
		print (nodeList) 


node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node5 = Node(5)
ll = LinkedList()
ll.addNode(node1)
ll.addNode(node2)
ll.addNode(node3)
ll.addNode(node4)
ll.addNode(node5)
ll.print_list()
ll.delVal(5)
ll.print_list()
ll.deleteAtPos(3)
ll.print_list()