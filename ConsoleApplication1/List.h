#pragma once

#ifndef LIST_H
#define LIST_H

#include "Set.h"
#include <stdio.h>
#include <stdlib.h>

#define LIST_FILE_EXTENSION(var) "List." #var

typedef struct node {
	uint32_t yyyymm;
	char career[SIZE_OF_MAX];
	struct node* p_prev_node;
	struct node* p_next_node;
}node_t;

#define NODE node_t

NODE* CreateNode(uint32_t yyyymm, char* carrer);
void ConnectNode(NODE* p_prev_node, NODE* p_next_node);
NODE* AddFirstNode(NODE* p_head, NODE* p_node);
NODE* AddLastNode(NODE* p_tail, NODE* p_node);
void InsertNode(NODE* p_node, NODE* p_inserting_node);
void RemoveNode(NODE* p_node);
void PrintList(NODE* p_head);
NODE* SelectNode(uint32_t index, NODE* p_head);
void PrintNode(NODE* p_node);
void* DestroyList(NODE* p_head);
void PrintMenu(NODE* p_head);
NODE* ExecuteMenu(char menu_guide, NODE* p_head);
NODE* OverwriteNode(NODE* p_node, uint32_t yyyymm, char* carrer);
uint32_t SearchNode(uint32_t yyyymm, NODE* p_head);
void SaveList(NODE* p_head);
NODE* LoadList(NODE* p_head);
NODE* SortList(NODE* p_head);
uint32_t GetListLength(NODE* p_head);

#endif /* LIST_H */