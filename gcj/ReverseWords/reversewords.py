#!/usr/bin/python

f = open('B-large-practice.in')

words = {}
i = 0
for line in f:
    words[i] = line.rsplit()
    i = i + 1

idx = 0
offset = int(words[0].pop())
for idx in xrange(1, len(words)):
    w = words[idx]
    w.reverse()
    print 'Case #%s:' % (idx),
    for v in w:
        print v,
    print
    if(idx == offset): 
        idx = idx + 1;
        offset = idx

f.close()
