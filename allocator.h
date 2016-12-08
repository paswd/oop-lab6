#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

class AllocatorCluster {
private:
	bool Alloced;
	bool Empty;
	void *Pointer;
	size_t Size;

public:
	AllocatorCluster(void);
	~AllocatorCluster(void);

	void *Alloc(size_t size);
	void Free(void);

	bool IsEmpty(void);
	bool IsCurrentPointer(void *pointer);
};

class Node {
public:
	std::vector <AllocatorCluster> Clusters;
	Node *Parent;
	Node *Child;
	size_t Level;
};

class Allocator {
private:
	Node *Root;
	size_t NConst;
	//size_t ClusterSize;

public:
	//Methods
	Allocator(void);
	~Allocator(void);

	void *Alloc(size_t size);
	void Free(void *pointer);
};

#endif /* FIGURE_H */
