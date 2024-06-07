#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "list.h"


list* newZveno()
{
	list* V;
	V = (list*)malloc(sizeof(list));
	V->info = 0;
	V->next = NULL;
	return V;
}

list* AddFirst(list* head, int data)
{
	list* v = newZveno();
	v->info = data;
	v->next = head;
	return v;
}

list* addLast(list* head, int data) {
	list* v = newZveno();
	if (head == NULL) {
		v->info = data;
		v->next = NULL;
		head = v;
		return head;
	}
	list* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = v;
	v->info = data;
	v->next = NULL;
	return head;
}
/*
list* specDelete(list* head, int value) {
	list* pZveno = head;
	if (pZveno->id == value) {
		list* tempZveno = pZveno;
		head = pZveno->next;
		free(tempZveno);
		return head;
	}
	while (pZveno->next != NULL && pZveno->next->id != value)
		pZveno = pZveno->next;
	if (pZveno->next != NULL) {
		list* tempZveno = pZveno->next;
		pZveno->next = tempZveno->next;

		free(tempZveno);
	}
	else {
		printf("Элемент со значением %d не найден\n", value);
		return head;
	}

	return head;
}

list* getLast(list* head) {
	list* last = head;
	while (last != NULL && last->next != NULL) {
		last = last->next;
	}
	return last;
}

list* getMaxList(list* archiveProc) {
	list* pProc = archiveProc;
	list* maxList = pProc;
	int maxBurst = pProc->id;
	while (pProc != NULL) {
		if (pProc->id > maxBurst) {
			maxBurst = pProc->id;
			maxList = pProc;
		}
		pProc = pProc->next;
	}
	return maxList;
}
*/

void print(list* head)
{
	while (head)
	{
		printf("%d ", head->info);
		head = head->next;
	}
}

void sortIncr(list* head) {
	list* pProc = head;
	while (pProc != NULL) {
		list* minlist = pProc;
		list* nextlist = pProc->next;
		while (nextlist != NULL) {
			if (nextlist->info < minlist->info)
				minlist = nextlist;
			nextlist = nextlist->next;
		}
		int ttt = pProc->info;
		pProc->info = minlist->info;
		minlist->info = ttt;
		pProc = pProc->next;
	}
}

// Дальше не менял я ничего, все вункции с операционных систем...
 /*
 
void reversePrintList(process* head) {
	process* pZveno = head;
	char stack[N] = { NULL };
	int top = -1;
	while (pZveno != NULL) {
		push(stack, &top, pZveno->burstTime);
		pZveno = pZveno->next;
	}
	while (!is_empty(top))
		printf("%d ", pop(stack, &top));
	printf("\n");
}

int numElements(process* head) {
	process* pZveno = head;
	int cntZveno = 0;
	while (pZveno != NULL) {
		cntZveno++;
		pZveno = pZveno->next;
	}
	return cntZveno;
}

int addNext(process* head, int value, int data) {
	process* p = head;
	while (p->burstTime != value && p->next != 0)
		p = p->next;
	if (p->next == NULL)
		return 0;
	process* v = newZveno();
	v->burstTime = data;
	v->next = p->next;
	p->next = v;
	return 1;
}
 process* evenDelete(process* head) {
	process* pProc = head;

	while (pProc != NULL && pProc->burstTime % 2 == 0) {
		process* tempZveno = pProc;
		head = pProc->next;
		pProc = pProc->next;

		free(tempZveno);
	}

	while (pProc->next != NULL) {
		if (pProc->next->burstTime % 2 == 0) {
			process* tempZveno = pProc->next;
			pProc->next = tempZveno->next;

			free(tempZveno);
		}
		else
			pProc = pProc->next;
	}
	return head;
}

process* filterDelete(process* head, int value) {
	process* pProc = head;

	while (pProc != NULL && pProc->burstTime > value) {
		process* tempProc = pProc;
		head = pProc->next;
		pProc = pProc->next;

		free(tempProc);
	}

	while (pProc->next != NULL) {
		if (pProc->next->burstTime > value) {
			process* tempZveno = pProc->next;
			pProc->next = tempZveno->next;

			free(tempZveno);
		}
		else
			pProc = pProc->next;
	}
	return head;
}

process* getProc(process* queueProc, int index) {
	process* pProc = queueProc;
	int cnt = 0;
	while (pProc != NULL && cnt != index) {
		pProc = pProc->next;
		cnt++;
	}
	if ((cnt == index) && (pProc != NULL))
		return pProc;
	else
		return NULL;
}
 process* copyQueue(process* queueProc) {
	process* pProc = queueProc;
	process* newQueue = newZveno();
	process* newProc = NULL;
	process* lastNewProc = newQueue;

	newQueue->id = pProc->id;
	newQueue->burstTime = pProc->burstTime;
	newQueue->startTime = pProc->startTime;
	newQueue->endTime = pProc->endTime;
	newQueue->waitTime = pProc->waitTime;
	newQueue->cntStatus = pProc->cntStatus;
	newQueue->tagPrev = pProc->tagPrev;
	newQueue->arriveTime = pProc->arriveTime;
	newQueue->kollllllll = pProc->kollllllll;
	copyCond(pProc, newQueue);
	newQueue->next = NULL;

	pProc = pProc->next;
	while (pProc != NULL) {
		newProc = newZveno();
		newProc->id = pProc->id;
		newProc->burstTime = pProc->burstTime;
		newProc->startTime = pProc->startTime;
		newProc->endTime = pProc->endTime;
		newProc->waitTime = pProc->waitTime;
		newProc->cntStatus = pProc->cntStatus;
		newProc->tagPrev = pProc->tagPrev;
		newProc->arriveTime = pProc->arriveTime;
		newProc->kollllllll = pProc->kollllllll;
		copyCond(pProc, newProc);
		newProc->next = NULL;
		lastNewProc->next = newProc;
		lastNewProc = lastNewProc->next;
		pProc = pProc->next;
	}
	return newQueue;
}

 statusProc* newZvenoCond() {
	statusProc* V;
	V = (statusProc*)malloc(sizeof(statusProc));
	V->next = NULL;
	return V;
}

statusProc* addLastCond(statusProc* head, char cond) {
	statusProc* v = newZvenoCond();
	if (head == NULL) {
		v->next = NULL;
		v->condition = cond;
		head = v;
		return head;
	}
	statusProc* p = head;
	while (p->next != NULL)
		p = p->next;
	p->next = v;
	v->condition = cond;
	v->next = NULL;

	return head;
}

void copyCond(process* queueProc, process* archiveProc) {
	process* pProc = queueProc;
	while (pProc != NULL) {
		process* pArchive = archiveProc;
		while ((pArchive != NULL) && (pProc->id != pArchive->id)) {
			pArchive = pArchive->next;
		}
		if ((pProc != NULL) && (pArchive != NULL)) {
			statusProc* pCondProc = pProc->conditionProc;
			statusProc** ppCondArchive = &(pArchive->conditionProc);
			while (pCondProc != NULL) {
				if (pCondProc->condition != NULL) {
					statusProc* newCond = new statusProc;
					*newCond = *pCondProc;
					*ppCondArchive = newCond;
					ppCondArchive = &(newCond->next);
				}
				pCondProc = pCondProc->next;
			}
		}
		pProc = pProc->next;
	}
}

 void clearCondStatus(process* archiveProc) { //?
	process* pProc = archiveProc;
	while (pProc != NULL) {
		free(pProc->conditionProc);
		pProc->conditionProc = NULL;
		pProc->cntStatus = 0;
		pProc = pProc->next;
	}
}

 int lenQueue(process* queueProc) {
	int cnt = 0;
	process* pProc = queueProc;
	while (pProc != NULL) {
		cnt++;
		pProc = pProc->next;
	}
	return cnt;
}

process* missArrive(process* queueProc) {
	process* pProc = queueProc;
	while (pProc != NULL) {
		pProc->arriveTime = 0;
		pProc = pProc->next;
	}
	return queueProc;
}

void dockQueue(process** archiveProc, process** queueProc, int timer, int* exePenalty) {
	process* pProc = *archiveProc;
	int deleteValue = 0;
	while (pProc != NULL) {
		if (pProc->arriveTime <= timer) {
			*queueProc = addLast(*queueProc, pProc->burstTime, pProc->id);
			getLast(*queueProc)->tagPrev = pProc->tagPrev;
			getLast(*queueProc)->arriveTime = 0;

			for (int i = 0; i < timer; i++) {
				pProc->conditionProc = addLastCond(pProc->conditionProc, ' ');
			}
			pProc->kollllllll += timer;
			exePenalty[pProc->id - 1] += timer;
			pProc->cntStatus += timer;
			getLast(*queueProc)->cntStatus += pProc->cntStatus;
			copyCond(pProc, *queueProc);

			deleteValue = pProc->burstTime;
			pProc = pProc->next;
			*archiveProc = specDelete(*archiveProc, deleteValue);

		}
		else
			pProc = pProc->next;
	}
}
*/
