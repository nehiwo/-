#include "List.h"

NODE* CreateNode(uint32_t yyyymm, char* career) 
{
	NODE* p_new_node = (NODE*)malloc(sizeof(NODE));
	if (p_new_node != NULL) {
		p_new_node->yyyymm = yyyymm;
		strcpy(p_new_node->career, career);
		p_new_node->p_prev_node = NULL;
		p_new_node->p_next_node = NULL;
	}
	else {
		printf("there is not memories.\n");
		/*exit(0);*/
	}
	return p_new_node;
}

void ConnectNode(NODE* p_node1, NODE* p_node2) 
{
	if (p_node1 == NULL) {
		printf("node1 does not exist.\n");
		/*exit(0);*/
	}
	else if (p_node2 == NULL) {
		printf("node2 does not exist.\n");
		/*exit(0);*/
	}
	else {
		p_node1->p_next_node = p_node2;
		p_node2->p_prev_node = p_node1;
	}
}

NODE* AddFirstNode(NODE* p_head, NODE* p_node)
{
	if (p_head == NULL) {
		printf("List is not found.\n");
		/*exit(0);*/
	}
	else {
		if (p_node == NULL) {
			printf("node is not found.\n");
			/*exit(0)*/;
		}
		else {
			p_node->p_next_node = p_head;
			p_head->p_prev_node = p_node;
		}
	}
	return p_node;
}

NODE* AddLastNode(NODE* p_tail, NODE* p_node)
{
	if (p_tail == NULL) {
		printf("List is not found.\n");
		/*exit(0)*/;
	}
	else {
		if (p_node == NULL) {
			printf("node is not found.\n");
			/*exit(0)*/;
		}
		else {
			p_node->p_prev_node = p_tail;
			p_tail->p_next_node = p_node;
		}
	}
	return p_node;
}

void InsertNode(NODE* p_node, NODE* p_inserting_node)
{
	if (p_node == NULL) {
		printf("node is not in this List.\n");
		/*exit(0)*/;
	}
	else {
		if (p_inserting_node == NULL) {
			printf("inserting node is not found.\n");
			/*exit(0)*/;
		}
		else {
			ConnectNode(p_inserting_node, p_node->p_next_node);
			ConnectNode(p_node, p_inserting_node);
		}
	}
}

void RemoveNode(NODE* p_node) 
{
	if (p_node == NULL) {
		printf("there is not data in this node yet.\n");
		/*exit(0)*/;
	}
	else {
		if (p_node->p_prev_node != NULL && p_node->p_next_node != NULL) {
			ConnectNode(p_node->p_prev_node, p_node->p_next_node);
		}
		else if (p_node->p_prev_node == NULL && p_node->p_next_node != NULL){
			p_node->p_next_node->p_prev_node = NULL;
		}
		else if (p_node->p_prev_node != NULL && p_node->p_next_node == NULL) {
			p_node->p_prev_node->p_next_node = NULL;
		}
		else if (p_node->p_prev_node == NULL && p_node->p_next_node == NULL){
			/* nothing to do */
		}
		else {
			/* nothing to do */
		}

		p_node->p_prev_node = NULL;
		p_node->p_next_node = NULL;
		p_node->yyyymm = NULL;
		strcpy(p_node->career, "");
		free(p_node);
	}
}

void PrintList(NODE* p_head)
{
	if (p_head == NULL) {
		printf("List is not found.\n");
		/*exit(0)*/;
	}
	else {
		NODE* p_now = p_head;
		while (p_now->p_next_node != NULL) {
			PrintNode(p_now);
			p_now = p_now->p_next_node;
		}
		PrintNode(p_now);
	}
}

NODE* SelectNode(uint32_t index, NODE* p_head) 
{
	NODE* p_now = p_head;
	for (uint32_t i = 1; i < index; i++) {
		if (p_now->p_next_node == NULL) {
			printf("overflow. return tail node.\n");
			break;
		}
		p_now = p_now->p_next_node;
	}
	return p_now;
}

void PrintNode(NODE* p_node)
{
	if (p_node == NULL) {
		printf("Node is not found.\n");
	}
	else {
		printf("%p %u %s %p %p\n", p_node, p_node->yyyymm, p_node->career, p_node->p_prev_node, p_node->p_next_node);
	}
}

void* DestroyList(NODE* p_head) 
{
	NODE* p_temp = NULL;
	while (p_head != NULL) {
		p_temp = p_head->p_next_node;
		RemoveNode(p_head);
		p_head = p_temp;
	}
	return 0;
}

void PrintMenu(NODE* p_head) 
{
	char menu_guide = 0;
	int32_t menu_ret = 0;
	char dummy = 0;
	while (1) {
		printf("*******MENU*******\n1)表示\n2)挿入\n3)削除\n4)変更\n5)検索\n6)保存\n7)読込\n8)ソート\n9)終了\n>");
		menu_ret = scanf("%1[123456789]", &menu_guide);
		dummy = getchar();	/* 改行読み飛ばし */
		if (menu_ret == 0) {
			printf("You Input Error Data.\n");
			break;
		}
		p_head = (NODE*) ExecuteMenu(menu_guide, p_head);
	}
}

NODE* ExecuteMenu(char menu_guide, NODE* p_head)
{
	switch (menu_guide)
	{
		uint32_t index = 0;
		uint32_t yyyymm = 0;
		char career[SIZE_OF_MAX] = "";
		int16_t ret = 0;
		NODE* p_now = p_head;
	case '1':
		PrintList(p_head);
		break;
	case '2':
		printf("Where do you want to insert?\nPlease input:");
		ret = scanf("%u", &index);
		if (ret == 0) {
			printf("You Input Error Data.\n");
			break;
		}
		printf("What data do you insert?\nPlease input[yyyymm career]:");
		ret = scanf("%d %s", &yyyymm, career);
		if (ret == 0) {
			printf("You Input Error Data.\n");
			break;
		}
		NODE* p_new = CreateNode(yyyymm, career);
		p_now = SelectNode(index, p_head);
		InsertNode(p_now, p_new);
		break;
	case '3':
		printf("Where do you want to delete?\nPlease input:");
		ret = scanf("%u", &index);
		if (ret == 0) {
			printf("You Input Error Data.\n");
			break;
		}
		p_now = SelectNode(index, p_head);
		if (p_now == p_head) {
			p_head = p_now->p_next_node;
		}
		else {
			/* nothing to do */
		}
		RemoveNode(p_now);
		break;
	case '4':
		printf("Where do you want to overwrite?\nPlease input:");
		ret = scanf("%u", &index);
		if (ret == 0) {
			printf("You Input Error Data.\n");
			break;
		}
		printf("What data do you overwrite?\nPlease input[yyyymm career]:");
		ret = scanf("%u %s", &yyyymm, career);
		if (ret == 0) {
			printf("You Input Error Data.\n");
			break;
		}
		p_now = SelectNode(index, p_head);
		OverwriteNode(p_now, yyyymm, career);
		break;
	case '5':
		printf("What data do you search?\nPlease input[career]:");
		ret = scanf("%s", career);
		if (ret == 0) {
			printf("You Input Error Data.\n");
			break;
		}
		index = SearchNode(career, p_head);
		break;
	case '6':
		SaveList(p_head);
		break;
	case '7':
		p_head = LoadList(p_head);
		break;
	case '8':
		p_head = SortList(p_head);
		break;
	case '9':
		p_head = DestroyList(p_head);
		exit(0);
		break;
	default:
		break;
	}
	char dummy = getchar();	/* 改行読み飛ばし */
	return p_head;
}

NODE* OverwriteNode(NODE* p_node, uint32_t yyyymm, char* career)
{
	if (p_node == NULL) {
		printf("node is not found.\n");
		/*exit(0)*/;
	}
	else {
		p_node->yyyymm = yyyymm;
		strcpy(p_node->career, career);
	}
	return p_node;
}

uint32_t SearchNode(char* career, NODE* p_head)
{
	NODE* p_now = p_head;
	uint32_t count = 1;
	
	while (strcmp(p_now->career, career) != 0) {
		count++;
		p_now = p_now->p_next_node;
		if (p_now == NULL) {
			count = 0;
			printf("this career is not found in list.\n");
			break;
		}
	}
	if (count > 0) {
		printf("index of this career is %u in %u.\n", count, p_now->yyyymm);
	}
	else {
		//nothing to do
	}
	return count;
}

void SaveList(NODE* p_head)
{
	if (p_head == NULL) {
		printf("List is not found.\n");
		/*exit(0)*/;
	}
	char* file_name = LIST_FILE_EXTENSION(csv);
#ifndef BINARY_FILE
	char* write_mode = "w";
#else
	char* write_mode = "wb";
#endif
	FILE* p_file = fopen(file_name, write_mode);
	size_t size_of_list = GetListLength(p_head);
	NODE* p_now = p_head;
	while (p_now != NULL) {
#ifndef BINARY_FILE
		fprintf(p_file, "%u %s\n",p_now->yyyymm, p_now->career);
#else
		fwrite(&p_now->yyyymm, &p_now->career, sizeof(int32_t), 2, p_file);
#endif
		p_now = p_now->p_next_node;
	}
	fclose(p_file);
}

NODE* LoadList(NODE* p_head)
{
	char* file_name = LIST_FILE_EXTENSION(csv);
	if (p_head == NULL) {
		p_head = CreateNode(0, "なし");
	}
	if (p_head->p_next_node != NULL) {
		p_head = DestroyList(p_head);
		p_head = CreateNode(0, "なし");
	}
	NODE* p_now = p_head;
#ifndef BINARY_FILE
	char* read_mode = "r";
#else
	char* read_mode = "rb";
#endif
	FILE* p_file = fopen(file_name, read_mode);
	while (feof(p_file) == 0) {
		if (ferror(p_file) != 0) {
			perror("***Load Error***\n");
			/*exit(0)*/;
		}
		NODE* p_new = CreateNode(0, "なし");
		ConnectNode(p_now, p_new);
#ifndef BINARY_FILE
		fscanf(p_file, "%u %s",&p_now->yyyymm, p_now->career);
#else
		fread(&p_now->val, &p_now->career, sizeof(int32_t), 2, p_file);
#endif
		p_now = p_now->p_next_node;
	}
	p_now = p_now->p_prev_node;
	RemoveNode(p_now->p_next_node);
	RemoveNode(p_now);
	PrintList(p_head);
	fclose(p_file);
	return p_head;
}

NODE* SortList(NODE* p_head)
{
	if (p_head == NULL) {
		printf("List is not found.\n");
		/*exit(0)*/;
	}
	else {
		NODE* p_now = p_head;
		const uint32_t k_index = GetListLength(p_head);
		uint32_t temp[SIZE_OF_MAX] = { 0 };
		char copy[SIZE_OF_MAX][SIZE_OF_MAX] = { 0 };

		for (uint32_t i = 0; i < k_index; i++) {
			temp[i] = p_now->yyyymm;
			strcpy(copy[i], p_now->career);
			p_now = p_now->p_next_node;
		}

		uint32_t dummy = temp[0];
		char buff[SIZE_OF_MAX] = "";
		for (uint32_t i = 0; i < k_index - 1; i++) {
			for (uint32_t j = i; j < k_index; j++) {
				if (temp[i] > temp[j]) {
					dummy = temp[i];
					temp[i] = temp[j];
					temp[j] = dummy;
					strcpy(buff, copy[i]);
					strcpy(copy[i], copy[j]);
					strcpy(copy[j], buff);
				}
			}
		}

		p_now = p_head;
		for (uint32_t i = 0; i < k_index; i++) {
			p_now->yyyymm = temp[i];
			strcpy(p_now->career, copy[i]);
			p_now = p_now->p_next_node;
		}
	}
	return p_head;
}

uint32_t GetListLength(NODE* p_head)
{
	uint32_t length = 0;
	NODE* p_now = p_head;
	while (p_now != NULL) {
		p_now = p_now->p_next_node;
		length++;
	}
	return length;
}