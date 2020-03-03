#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct song Song
typedef struct artist Artist
typedef struct snode Snode

struct song {
	int index;
	char* title;
	Artist* artist;
	char* path;
};

struct snode {
	Song* song;
	struct snode* prev, * next;
};


struct artist {
	char* name;
	Artist* next;
	Snode* head, * tail;
	]
};

#endif LIBRARY_H
