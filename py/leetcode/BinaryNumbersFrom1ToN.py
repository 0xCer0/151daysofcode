# Given a number n, generate all binary numbers with decimal values from 1 to N and return the array of binary number.

from queue import Queue

def solve(n):
	q = Queue()
	q.put("1")
	while(n > 0):
		n -= 1
		s1 = q.get()
		print (s1)
		s2 = s1 
		q.put(s1+"0")
		q.put(s2+"1")


n = 10
solve(n)

