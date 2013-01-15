#!/usr/bin/env python
# http://nixzhu.me/post/maze-by-python
# author: @nixzhu
# date: 2012.02.25
# description: Maze, use recursion. 
#       Door is (7, 7), as follow shows
# license: GPL

maze = [
    [1,1,0,0,0,0,1,0],
    [0,1,0,0,0,1,1,0],
    [0,1,1,1,1,1,0,0],
    [1,1,0,0,0,1,0,0],
    [1,0,0,0,0,1,1,1],
    [1,1,1,1,1,1,0,0],
    [0,0,0,1,0,1,1,1],
    [0,0,0,1,0,1,0,1]
]
maze_ = [
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0]
]

def showMaze(maze):
    print '-----------------S'
    for line in maze:
        for l in line:
            print l,
        print ''
    print '-----------------E'

def findDest(p={'r':0, 'c':0}):
    if out(p):
        #print '>> ++ out\t', p['r'], p['c']
        return False
    #print '>> -- out\t', p['r'], p['c']
    if isWall(p):
        return False
    if wasVisited(p):
        return False

    visit(p)

    if isDest(p):
        print '('+str(p['r'])+', '+str(p['c'])+')'
        maze_[p['r']][p['c']] = '#'
        return True
    else:
        if findDest(p=left(p)):
            print '('+str(p['r'])+', '+str(p['c'])+')'
            maze_[p['r']][p['c']] = '#'
            return True
        if findDest(p=up(p)):
            print '('+str(p['r'])+', '+str(p['c'])+')'
            maze_[p['r']][p['c']] = '#'
            return True
        if findDest(p=right(p)):
            print '('+str(p['r'])+', '+str(p['c'])+')'
            maze_[p['r']][p['c']] = '#'
            return True
        if findDest(p=down(p)):
            print '('+str(p['r'])+', '+str(p['c'])+')'
            maze_[p['r']][p['c']] = '#'
            return True
        return False

def out(p={'r':0, 'c':0}):
    if p['r'] < 0 or p['r'] > 7:
        return True
    if p['c'] < 0 or p['c'] > 7:
        return True
    return False

def isWall(p={'r':0, 'c':0}):
    if maze[p['r']][p['c']] == 0:
        return True
    else:
        return False

def wasVisited(p={'r':0, 'c':0}):
    if maze[p['r']][p['c']] == 2:
        return True
    else:
        return False

def isDest(p={'r':0, 'c':0}):
    if p['r'] == 7 and p['c'] == 7:
        return True
    else:
        return False

def visit(p={'r':0, 'c':0}):
    maze[p['r']][p['c']] = 2

def left(p={'r':0, 'c':0}):
    return {'r':p['r'], 'c':p['c']-1}
def right(p={'r':0, 'c':0}):
    return {'r':p['r'], 'c':p['c']+1}
def up(p={'r':0, 'c':0}):
    return {'r':p['r']-1, 'c':p['c']}
def down(p={'r':0, 'c':0}):
    return {'r':p['r']+1, 'c':p['c']}


if __name__=='__main__':
    showMaze(maze)
    if not findDest(p={'r':0, 'c':0}):  # Enter is (0, 0)
        print "No, can't find destination"
    else:
        print "Yes, find destination"
    showMaze(maze)
    showMaze(maze_)

