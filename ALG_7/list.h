typedef struct list
{
	int info;
	struct list* next;
}list;

list* newZveno();
list* AddFirst(list* head, int data);
list* addLast(list* head, int data);
void print(list* head);
void sortIncr(list* archiveProc);
