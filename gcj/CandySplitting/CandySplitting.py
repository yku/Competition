#!/usr/bin/python

def getcandy(value):
    l = len(value)
    value.sort(cmp=lambda x,y: cmp(int(x), int(y)))
    ret = 0
    ans = -1 * int(value[0])
    for i in xrange(0, l):
        v = int(value.pop())
        ret = ret ^ v
        ans = ans + v
    
    if(ret == 0):
        return ans
    else:
        return "NO"

f = open('C-large.in.in')
words = {}
i = 0
for line in f:
    words[i] = line.rsplit()
    i = i + 1

i = 0
case = 1
for i in xrange(1, len(words)):
    if(i % 2 == 0):
        str = getcandy(words[i])
        print 'Case #%s: %s' % (case, str)
        case = case + 1

#a = ['2092', '2060', '4878', '1630', '6500', '8298', '7648', '8160', '11902']
#print getcandy(a)
